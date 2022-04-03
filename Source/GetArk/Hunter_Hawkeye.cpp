// Fill out your copyright notice in the Description page of Project Settings.


#include "Hunter_Hawkeye.h"
#include "Engine/Classes/Components/CapsuleComponent.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Engine/Classes/GameFramework/SpringArmComponent.h"
// Sets default values
AHunter_Hawkeye::AHunter_Hawkeye()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.


	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	GetArkCameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("GetArkCameraSpringArm"));
	GetArkCameraSpringArmComponent->SetupAttachment(RootComponent);
	GetArkCameraSpringArmComponent->SetUsingAbsoluteRotation(false);
	GetArkCameraSpringArmComponent->TargetArmLength = 800.0f;
	GetArkCameraSpringArmComponent->SetRelativeRotation(FRotator(-60.f, 45.0f, 0.0));
	GetArkCameraSpringArmComponent->bDoCollisionTest = false;

	GetArkCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	GetArkCameraComponent->SetupAttachment(GetArkCameraSpringArmComponent, USpringArmComponent::SocketName);
	GetArkCameraComponent->bUsePawnControlRotation = false;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

}

// Called when the game starts or when spawned
void AHunter_Hawkeye::BeginPlay()
{
	//bUseCon
	Super::BeginPlay();

}

// Called every frame
void AHunter_Hawkeye::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AHunter_Hawkeye::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

