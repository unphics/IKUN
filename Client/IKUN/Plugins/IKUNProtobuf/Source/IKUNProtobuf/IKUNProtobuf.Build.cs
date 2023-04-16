
// Copyright Epic Games, Inc. All Rights Reserved.

using System.ComponentModel;
using System.IO;
using UnrealBuildTool;
using System;

public class IKUNProtobuf : ModuleRules {
	public IKUNProtobuf(ReadOnlyTargetRules Target) : base(Target) {
        //bUsePrecompiled = true;
        //PrecompileForTargets = PrecompileTargetsType.Any;
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        bEnableUndefinedIdentifierWarnings = false;
        PublicIncludePaths.AddRange(new string[] {});
        PrivateIncludePaths.AddRange(new string[] {});
        PublicDependencyModuleNames.AddRange(new string[]{"Core","Projects"});
        PrivateDependencyModuleNames.AddRange(new string[]{});
        DynamicallyLoadedModuleNames.AddRange(new string[]{});

        /*
        bUsePrecompiled = true;
        //Type = ModuleType.External;

        string pathVcpkg = Environment.GetEnvironmentVariable("VCPKG_ROOT");
        string pathProtobuf = Path.Combine(pathVcpkg, "packages", "protobuf_x64-windows");
        string pathPBInclude = Path.Combine(pathProtobuf, "include");

        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] {pathPBInclude});
		PrivateIncludePaths.AddRange(new string[] { });
		PublicDependencyModuleNames.AddRange(new string[]{"Core", "IKUNProtobufLibrary", "Projects"});
		PrivateDependencyModuleNames.AddRange(new string[]{"CoreUObject"});
		DynamicallyLoadedModuleNames.AddRange(new string[]{ });
		ShadowVariableWarningLevel = WarningLevel.Off; // �رձ�����Ӱ��������ue������ͻ
		bEnableUndefinedIdentifierWarnings = false; // �ر���#ifdef��#ifndef�е�δ��������ľ���
		if(Target.Platform == UnrealTargetPlatform.Win64) {
			bEnableExceptions = true; // win64�����쳣����
            PublicAdditionalLibraries.Add(Path.Combine(pathProtobuf, "lib", "libprotobuf.lib"));
        }
		PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS"); // ����pb��һ�Ѿ���
		*/
    }
}
