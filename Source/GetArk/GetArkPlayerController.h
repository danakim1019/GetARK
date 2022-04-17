// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GetArkPlayerController.generated.h"

UCLASS()
class AGetArkPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGetArkPlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
private:
	void	Input_KeyInput(void);
	void	Activate_SkillQ(void);
	void	Activate_SkillW(void);
	void	Activate_SkillE(void);
	void	Activate_SkillR(void);

	void	Activate_SkillA(void);
	void	Activate_SkillS(void);
	void	Activate_SkillD(void);
	void	Activate_SkillF(void);
};


