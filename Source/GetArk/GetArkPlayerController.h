// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GetArkProjectile.h"

//#include "Engine/Blueprint.h"
//#include "Engine/BlueprintGeneratedClass.h"
#include "UObject/ConstructorHelpers.h"
#include "GetArkPlayerController.generated.h"

/**
* APlayerController�� ���� Ŭ����
* �÷��̾��� �� ����, �׼� ���� �� �÷��̾��� ��ǲ�� ���� ����� ���� 
* @author ��ȿ��
* @version 1.0, �÷��̾� ��Ʈ�ѷ� Fire �Լ� �߰�(20220501) 
* @see None
*/


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
/**
* @ ������Ʈ�� �Է� ������ �׼� ���ο� ����� �Լ���
* @ Input_KeyInput: Ű �Է¹��� �Լ��� Ű���� �Է¹ް� �б⹮�� ���� ��ų �Լ��� ȣ��
* @ Activate_ : Ű�� �Է� �޾��� �� Ȱ��ȭ �� ��ų �Լ���

*/
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
/**
* @ �׼� ���� �Լ�, �Ѿ� �߻� �Լ�
* @ ���� ���콺 ��ư�� �Է� ���������� ȣ�� �Ǵ� �Լ�
*/
	UFUNCTION()
		void Fire();

/**
* @ ProjectileClass : Fire�Լ��� ȣ���� ������ ������ų �Ѿ� Ŭ����
* @ MuzzleOffset : �Ѿ��� �߻� �� �ѱ��� ��ġ
* @ EditAniWhere�� ���� ������ ������ â���� �� ������ �� ����
*/

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = Projectile)
		TSubclassOf<class AGetArkProjectile> ProjectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;
	TArray<AActor*> m_ArrActors;
	//UBluePrintGeneratedClass* LoadedBP;
	class AGetArkCharacter* m_pGetArkCharacter;
	
	
};


