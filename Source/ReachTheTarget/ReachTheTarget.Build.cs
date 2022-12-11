// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ReachTheTarget : ModuleRules
{
	public ReachTheTarget(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayTasks", "NavigationSystem" });
	}
}
