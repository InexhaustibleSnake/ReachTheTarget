// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "PatrolTask.generated.h"


UCLASS()
class REACHTHETARGET_API UPatrolTask : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UPatrolTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector PatrolKey;

};
