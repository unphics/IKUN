// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;
using System;

public class Protobuf : ModuleRules
{
	public Protobuf(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core" });

		PrivateDependencyModuleNames.AddRange(new string[] { });

        string pathVcpkg = Environment.GetEnvironmentVariable("VCPKG_ROOT");
        string pathProtobuf = Path.Combine(pathVcpkg, "packages", "protobuf_x64-windows");
        string pathPBInclude = Path.Combine(pathProtobuf, "include");

        PublicIncludePaths.AddRange(new string[] { pathPBInclude });
        if(Target.Platform == UnrealTargetPlatform.Win64) {
            PublicAdditionalLibraries.Add(Path.Combine(pathProtobuf, "lib", "libprotobuf.lib"));
        }

        ShadowVariableWarningLevel = WarningLevel.Warning;
        bEnableUndefinedIdentifierWarnings = false;
        bEnableExceptions = true;

	}
}
