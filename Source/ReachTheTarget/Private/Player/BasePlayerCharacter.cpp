// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/BasePlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ABasePlayerCharacter::ABasePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());

	MainCamera = CreateDefaultSubobject<UCameraComponent>("MainCamera");
	MainCamera->SetupAttachment(SpringArm);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->bOrientRotationToMovement = true;

	SpringArm->bUsePawnControlRotation = true;

	MainCamera->bUsePawnControlRotation = false;
}

void ABasePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasePlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABasePlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABasePlayerCharacter::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABasePlayerCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ABasePlayerCharacter::StopJumping);
}

void ABasePlayerCharacter::MoveForward(float Amount)
{
	if ((Controller != nullptr) && (Amount != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Amount);
	}
}

void ABasePlayerCharacter::MoveRight(float Amount)
{
	if ((Controller != nullptr) && (Amount != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Amount);
	}
}