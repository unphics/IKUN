using UnrealBuildTool;
using System.IO;
using System;

public class Protobuf : ModuleRules {
    public Protobuf(ReadOnlyTargetRules Target) : base(Target) {
        // 设置该模块为外部依赖模块，即作为第三方模块
        Type = ModuleType.External;

        //bUsePrecompiled = true;
        //PrecompileForTargets = PrecompileTargetsType.Any;

        if (Target.Platform == UnrealTargetPlatform.Win64) {
            PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
            // PublicSystemIncludePaths.Add("include");
            PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "lib", "libprotobuf.lib"));
        }
        ShadowVariableWarningLevel = WarningLevel.Off;
        bEnableUndefinedIdentifierWarnings = false;
        bEnableExceptions = true;
        PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");
        PublicDefinitions.Add("GOOGLE_PROTOBUF_NO_RTTI=1");
        PublicDefinitions.Add("GOOGLE_PROTOBUF_CMAKE_BUILD");



        /*
        Type = ModuleType.External;
        bUsePrecompiled = true;
        PrecompileForTargets = PrecompileTargetsType.Any;

        PublicDependencyModuleNames.AddRange(new string[] { });
        PrivateDependencyModuleNames.AddRange(new string[] { });
        if (Target.Version.MajorVersion == 4) {
            //bEnableShadowVariableWarnings = false;          
        } else if (Target.Version.MajorVersion == 5) {
            ShadowVariableWarningLevel = WarningLevel.Off;
        }
        bEnableUndefinedIdentifierWarnings = false;
        bEnableExceptions = true;
        PublicIncludePaths.Add(Path.Combine(System.IO.Path.GetFullPath(ModuleDirectory),"include"));
        PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");
        PublicDefinitions.Add("GOOGLE_PROTOBUF_NO_RTTI");

        string LibraryPath = Path.Combine(ModuleDirectory, "lib");
        if (Target.Platform == UnrealTargetPlatform.Win64) {
            PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "libprotobuf.lib" ));
        }
        */
    }
}