
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
		ShadowVariableWarningLevel = WarningLevel.Off; // 关闭变量阴影，否则会和ue产生冲突
		bEnableUndefinedIdentifierWarnings = false; // 关闭由#ifdef、#ifndef中的未定义产生的警告
		if(Target.Platform == UnrealTargetPlatform.Win64) {
			bEnableExceptions = true; // win64启用异常处理
            PublicAdditionalLibraries.Add(Path.Combine(pathProtobuf, "lib", "libprotobuf.lib"));
        }
		PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS"); // 避免pb报一堆警告
		*/
    }
}
