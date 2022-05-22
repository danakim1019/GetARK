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
* APlayerController를 받은 클래스
* 플레이어의 축 매핑, 액션 매핑 등 플레이어의 인풋에 대한 기능을 정의 
* @author 김효연
* @version 1.0, 플레이어 컨트롤러 Fire 함수 추가(20220501) 
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
* @ 프로젝트의 입력 셋팅의 액션 매핑에 등록할 함수들
* @ Input_KeyInput: 키 입력받을 함수들 키들을 입력받고 분기문에 따라서 스킬 함수들 호출
* @ Activate_ : 키를 입력 받았을 때 활성화 할 스킬 함수들

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
* @ 액션 매핑 함수, 총알 발사 함수
* @ 왼쪽 마우스 버튼을 입력 받을때마다 호출 되는 함수
*/
	UFUNCTION()
		void Fire();

/**
* @ ProjectileClass : Fire함수를 호출할 때마다 생성시킬 총알 클래스
* @ MuzzleOffset : 총알이 발사 될 총구의 위치
* @ EditAniWhere를 통해 엔진의 디테일 창에서 값 셋팅할 수 있음
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


