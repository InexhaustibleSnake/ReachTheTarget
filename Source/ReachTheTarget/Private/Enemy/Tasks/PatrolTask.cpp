// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/Tasks/PatrolTask.h"
#include "Enemy/BaseEnemy.h"
#include "Enemy/Controller/BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemy/Points/PatrolPoint.h"

UPatrolTask::UPatrolTask()
{
	NodeName = "Patrol Task";
}

EBTNodeResult::Type UPatrolTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Controller || !Blackboard) return EBTNodeResult::Failed;

	ABaseEnemy* Pawn = Cast<ABaseEnemy>(Controller->GetPawn());
	if (!Pawn) return EBTNodeResult::Failed;

	APatrolPoint* NextPatrolPoint = nullptr;

	TArray<AActor*> AvaiblePatrolPoints = Pawn->GetPatrolPoints();

	if (Pawn->CurrentPatrolPoint != Pawn->GetPatrolPoints().Num() - 1)
	{
		NextPatrolPoint = Cast<APatrolPoint>(AvaiblePatrolPoints[++Pawn->CurrentPatrolPoint]);
	}
	else
	{
		NextPatrolPoint = Cast<APatrolPoint>(AvaiblePatrolPoints[0]);
		Pawn->CurrentPatrolPoint = 0;
	}

	Blackboard->SetValueAsVector(PatrolKey.SelectedKeyName, NextPatrolPoint->GetActorLocation());
	return EBTNodeResult::Succeeded;
}