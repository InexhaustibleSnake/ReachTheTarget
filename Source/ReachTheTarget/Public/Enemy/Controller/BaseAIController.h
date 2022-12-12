// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

class UBaseAIPerceptionComponent;
class UBlackboardComponent;
 
UCLASS()
class REACHTHETARGET_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ABaseAIController();


protected:
	virtual void OnPossess(APawn* InPawn) override;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
		UBaseAIPerceptionComponent* AIPerceptionComponent;

};
