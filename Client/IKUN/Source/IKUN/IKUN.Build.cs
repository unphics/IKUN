// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IKUN : ModuleRules
{
	public IKUN(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        //ShadowVariableWarningLevel = WarningLevel.Warning;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" /*,"IKUNProtobuf"*/, "Protobuf", "IKUNProtos" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        //bEnableUndefinedIdentifierWarnings = false;
        //bEnableExceptions = true;

    }
}
