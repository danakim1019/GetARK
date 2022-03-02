// Copyright Epic Games, Inc. All Rights Reserved.

#include "GetArkGameMode.h"
#include "GetArkPlayerController.h"
#include "GetArkCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGetArkGameMode::AGetArkGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGetArkPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}