// Copyright Epic Games, Inc. All Rights Reserved.



#include "Kismet/GameplayStatics.h"
#include "GetArkPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GetArkCharacter.h"

#include "GetArkProjectile.h"

#include "Engine/World.h"




AGetArkPlayerController::AGetArkPlayerController()	
	: MuzzleOffset(0.f, 0.f, 0.f)
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	 
	
	static ConstructorHelpers::FClassFinder<AActor> BPClass(TEXT("/Game/Player/Blueprints/Bp_GetArkProjectile"));
	if (BPClass.Succeeded() && BPClass.Class != NULL)
	{
		// 가져온 BPClass.Class를 통한 작업
		UE_LOG(LogTemp, Log, TEXT("true"));

		ProjectileClass = BPClass.Class;
	}

	
}

void AGetArkPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void AGetArkPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AGetArkPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AGetArkPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AGetArkPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AGetArkPlayerController::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AGetArkPlayerController::OnResetVR);
	InputComponent->BindAction("Fire", IE_Pressed, this, &AGetArkPlayerController::Fire);
}

void AGetArkPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AGetArkPlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (AGetArkCharacter* MyPawn = Cast<AGetArkCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			UE_LOG(LogTemp, Log, TEXT("move"));
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void AGetArkPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AGetArkPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AGetArkPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AGetArkPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
/* 키 입력을 모아놓은 함수 */
void AGetArkPlayerController::Input_KeyInput(void)
{
}

/* 키 입력에 따라 활성화 할 스킬 함수들 */
void AGetArkPlayerController::Activate_SkillQ(void)
{
}

void AGetArkPlayerController::Activate_SkillW(void)
{
}

void AGetArkPlayerController::Activate_SkillE(void)
{
}

void AGetArkPlayerController::Activate_SkillR(void)
{
}

void AGetArkPlayerController::Activate_SkillA(void)
{
}

void AGetArkPlayerController::Activate_SkillS(void)
{
}

void AGetArkPlayerController::Activate_SkillD(void)
{
}

void AGetArkPlayerController::Activate_SkillF(void)
{
}

/* 마우스 왼쪽 버튼에 대한 액션 함수 , 총알 발사 함수 */
void AGetArkPlayerController::Fire(void)
{

	AActor* pPlayer;
	// 플레이어 태그를 찾아서 TArray에 보관
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Player", m_ArrActors);
	pPlayer = (AActor*)m_ArrActors.GetData();
	// TArray에 담긴 액터들을 순회하면서 pPlayer에 대입
	auto iter = m_ArrActors.begin();
	for (int i = 0; i < m_ArrActors.Num(); ++i) {
		pPlayer = *iter;
	}
	
	if (ProjectileClass) {
		//플레이어의 위치와 플레이어가 바라보는 방향을 받아옴
		FVector vPos = pPlayer->GetActorLocation();
		FRotator vRot = pPlayer->GetActorRotation();

		// 총구의 위치에 플레이어의 위치 대입
		FVector		MuzzleLocation = vPos + FTransform(vRot).TransformVector(MuzzleOffset);
		// 총구의 방향에 플레이어의 방향 대입
		FRotator	MuzzleRotation = vRot;

		MuzzleRotation.Yaw += 10.0f;
		UWorld* World = GetWorld();
		if (World) {
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();
			AGetArkProjectile* pProjectile = World->SpawnActor<AGetArkProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			
			if (pProjectile) {
				FVector LaunchDirection = MuzzleRotation.Vector();
				pProjectile->FireInDirection(LaunchDirection);
			}
		}
	}
}
