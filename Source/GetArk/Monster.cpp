// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GetArkCharacter.h"
#include "Engine/World.h"

// Sets default values for this component's properties
AMonster::AMonster()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;
	UE_LOG(LogTemp, Error, TEXT("Log UMonster"));

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

}


// Called when the game starts
void AMonster::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Error, TEXT("Log BeginPlay"));
}


// Called every frame
void AMonster::Tick(float DeltaSeconds)
{
	//UE_LOG(LogTemp, Error, TEXT("Log TickComponent"));

	//�θ� update��
	Super::Tick(DeltaSeconds);

	FVector StartLocation = FVector(0, 0, 0);
	FVector EndLocation = FVector(30, 0, 0);

	//pawn�� ���� �Լ�
	MoveForward(1.0f);
	
}

void AMonster::MoveToPlayer(float Value) 
{
	// ��� ���� �������� �˾Ƴ���, �÷��̾ �� �������� �̵��ϰ��� �Ѵٰ� ����մϴ�.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	Direction.Z = 0.0f;
	Direction.Normalize();
	AddMovementInput(Direction, Value);
}

//������ �̵�
void AMonster::MoveForward(float Value)
{
	// ��� ���� �������� �˾Ƴ���, �÷��̾ �� �������� �̵��ϰ��� �Ѵٰ� ����մϴ�.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	Direction.Z = 0.0f;
	Direction.Normalize();
	AddMovementInput(Direction, Value);
}

void AMonster::Jump() {
	bPressedJump = true;
	JumpKeyHoldTime = 0.0f;
}

