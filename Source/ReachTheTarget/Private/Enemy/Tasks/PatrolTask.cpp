// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/Tasks/PatrolTask.h"
#include "Enemy/BaseEnemy.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UPatrolTask::UPatrolTask()
{
	NodeName = "Patrol Task";
}

EBTNodeResult::Type UPatrolTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Controller || !Blackboard) return EBTNodeResult::Failed;

	const auto EnemyPawn = Cast<ABaseEnemy>(Controller->GetPawn());

	for (auto PatrolPoint : EnemyPawn->PatrolPoints) 
	{
		Blackboard->SetValueAsVector(PatrolKey.SelectedKeyName, PatrolPoint->GetActorLocation());

	}
	return EBTNodeResult::Succeeded;
	
}
