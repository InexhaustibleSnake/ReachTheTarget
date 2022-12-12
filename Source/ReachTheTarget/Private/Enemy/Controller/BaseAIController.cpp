// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/Controller/BaseAIController.h"
#include "Enemy/Components/BaseAIPerceptionComponent.h"
#include "Enemy/BaseEnemy.h"

ABaseAIController::ABaseAIController()
{
	AIPerceptionComponent = CreateDefaultSubobject<UBaseAIPerceptionComponent>("AIPerceptionComponent");
}

void ABaseAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	ABaseEnemy* EnemyOwner = Cast<ABaseEnemy>(InPawn);
	
	if (EnemyOwner)
	{
		RunBehaviorTree(EnemyOwner->BehaviorTreeAsset);
	}
}