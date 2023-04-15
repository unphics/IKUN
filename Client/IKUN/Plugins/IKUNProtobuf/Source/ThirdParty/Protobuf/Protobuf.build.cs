using UnrealBuildTool;
using System.IO;
using System;
public class Protobuf : ModuleRules {
    public Protobuf(ReadOnlyTargetRules Target) : base(Target) {
        bUsePrecompiled = true;
        PrecompileForTargets = PrecompileTargetsType.Any;
        Type = ModuleType.External;

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
    }
}