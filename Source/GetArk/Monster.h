// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Monster.generated.h"

UCLASS()
class AMonster :  public ACharacter
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	AMonster();

	// Called every frame. update¹®
	virtual void Tick(float DeltaSeconds) override;

	void MoveToPlayer(float Value);
	void MoveForward(float Value);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void Jump() override;
};
