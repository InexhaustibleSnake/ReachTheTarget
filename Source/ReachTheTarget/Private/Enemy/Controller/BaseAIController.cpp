// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/Controller/BaseAIController.h"
#include "Enemy/Components/BaseAIPerceptionComponent.h"
#include "Enemy/BaseEnemy.h"

ABaseAIController::ABaseAIController()
{
	AIPerceptionComponent = CreateDefaultSubobject<UBaseAIPerceptionComponent>("AIPerceptionComponent");
	SetPerceptionComponent(*AIPerceptionComponent);
}

void ABaseAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	const auto Enemy = Cast<ABaseEnemy>(InPawn);
	if (Enemy)
	{
		RunBehaviorTree(Enemy->BehaviorTreeAsset);
	}

	
}
