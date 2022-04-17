// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character_Controller.generated.h"


/**
 *
 */
UCLASS()

class GETARK_API ACharacter_Controller : public APlayerController
{
public:
	ACharacter_Controller();
	GENERATED_BODY()
private:
	bool	m_bClickMouseBtn;
public:
	virtual	void	SetupInputComponent(void) override;
	virtual void	PlayerTick(float fDeltaTime) override;
private:
	void	Input_ClickPressed(void);
	void	Input_ClickReleased(void);
	void	Set_NewDestination(const FVector fvDestLocation);
	void	MoveTo_MouseCursor(void);

	// 키 입력을 받을때 현재 스킬 슬랏에 스킬 있는지 체크
	// 스킬을 사용할때 플레이어의 룩방향 받아올 것 
	// 인풋 키 버튼 받을때 플레이어의 룩 방향 받아올 것 

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
