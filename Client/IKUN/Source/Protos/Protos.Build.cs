// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Protos : ModuleRules
{
	public Protos(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnableUndefinedIdentifierWarnings = false;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Protobuf" });

		PrivateDependencyModuleNames.AddRange(new string[] { });

        PublicIncludePaths.AddRange(new string[] {"Protos/Public"});
        PrivateIncludePaths.AddRange(new string[] {"Protos/Private"});
    }
}
