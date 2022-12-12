// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseEnemy.generated.h"

class UBehaviorTree;

UCLASS()
class REACHTHETARGET_API ABaseEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseEnemy();
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE TArray<AActor*> GetPatrolPoints() const { return PatrolPoints; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Movement")
		TArray<AActor*> PatrolPoints;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
		UBehaviorTree* BehaviorTreeAsset;

	int32 CurrentPatrolPoint = 0;

protected:
	virtual void BeginPlay() override;
};
