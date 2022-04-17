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

	// Ű �Է��� ������ ���� ��ų ������ ��ų �ִ��� üũ
	// ��ų�� ����Ҷ� �÷��̾��� ����� �޾ƿ� �� 
	// ��ǲ Ű ��ư ������ �÷��̾��� �� ���� �޾ƿ� �� 

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
