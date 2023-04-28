// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class IKUN : ModuleRules
{
	public IKUN(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        //ShadowVariableWarningLevel = WarningLevel.Warning;

        PublicDependencyModuleNames.AddRange(new string[] 
        {
	        "Core",
	        "CoreUObject",
	        "Engine",
	        "InputCore",
	        // "IKUNProtobuf",
	        "Protobuf",
	        // "IKUNProtos",
	        "DatabaseSupport",
	        "SQLiteCore",
	        "SQLiteSupport",
        });
        PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "Public", "Protos"));
		PrivateDependencyModuleNames.AddRange(new string[] {  });

        //bEnableUndefinedIdentifierWarnings = false;
        //bEnableExceptions = true;
        // bEnableUndefinedIdentifierWarnings = false; // 关闭由#ifdef、#ifndef中的未定义产生的警告
        // PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS"); // 避免pb报一堆警告
    }
}
