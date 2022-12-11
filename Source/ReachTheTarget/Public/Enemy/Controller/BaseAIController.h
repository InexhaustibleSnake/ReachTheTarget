// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

class UBaseAIPerceptionComponent;
 
UCLASS()
class REACHTHETARGET_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ABaseAIController();

protected:
	virtual void OnPossess(APawn* InPawn) override;
	//virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UBaseAIPerceptionComponent* AIPerceptionComponent;
};
