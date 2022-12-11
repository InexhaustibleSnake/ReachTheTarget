// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasePlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class REACHTHETARGET_API ABasePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABasePlayerCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
		USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
		UCameraComponent* MainCamera;

private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);
};
