// Fill out your copyright notice in the Description page of Project Settings.
#include "Character_Controller.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
ACharacter_Controller::ACharacter_Controller()
{
	bShowMouseCursor = true;
}

void ACharacter_Controller::SetupInputComponent(void)
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Move_InputRBtn", IE_Pressed, this, &ACharacter_Controller::Input_ClickPressed);
	InputComponent->BindAction("Move_InputRBtn", IE_Released, this, &ACharacter_Controller::Input_ClickReleased);
	//InputComponent->BindAction("Skill_Q",IE_Pressed, this, &ACharacter_Controller::InputKey)
}

void ACharacter_Controller::Input_ClickPressed(void)
{
	m_bClickMouseBtn = true;
}

void ACharacter_Controller::Input_ClickReleased(void)
{
	m_bClickMouseBtn = false;
}

void ACharacter_Controller::Set_NewDestination(const FVector fvDestLocation)
{
	APawn* const	MyPawm = GetPawn();
	if (MyPawm) {
		float	const	fDistance = FVector::Dist(fvDestLocation, MyPawm->GetActorLocation());

		if (fDistance > 120.f) {
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, fvDestLocation);
		}
	}
}

void ACharacter_Controller::MoveTo_MouseCursor(void)
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit) {
		Set_NewDestination(Hit.ImpactPoint);
	}
}

void ACharacter_Controller::Input_KeyInput(void)
{
	InputComponent->

}

void ACharacter_Controller::Activate_SkillQ(void)
{

}

void ACharacter_Controller::Activate_SkillW(void)
{
}

void ACharacter_Controller::Activate_SkillE(void)
{
}

void ACharacter_Controller::Activate_SkillR(void)
{
}

void ACharacter_Controller::Activate_SkillA(void)
{
}

void ACharacter_Controller::Activate_SkillS(void)
{
}

void ACharacter_Controller::Activate_SkillD(void)
{
}

void ACharacter_Controller::Activate_SkillF(void)
{
}


void ACharacter_Controller::PlayerTick(float fDeltaTime)
{
	Super::PlayerTick(fDeltaTime);

	if (m_bClickMouseBtn) {
		MoveTo_MouseCursor();
	}
}

