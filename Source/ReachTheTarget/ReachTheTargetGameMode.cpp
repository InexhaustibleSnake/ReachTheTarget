// Copyright Epic Games, Inc. All Rights Reserved.

#include "ReachTheTargetGameMode.h"
#include "ReachTheTargetCharacter.h"
#include "UObject/ConstructorHelpers.h"

AReachTheTargetGameMode::AReachTheTargetGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
