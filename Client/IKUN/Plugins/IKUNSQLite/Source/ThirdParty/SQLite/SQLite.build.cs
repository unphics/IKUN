using UnrealBuildTool;
using System.IO;
using System;

public class SQLite : ModuleRules {
	public SQLite(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		Type = ModuleType.External;
		if (Target.Platform == UnrealTargetPlatform.Win64) {
			PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
			PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "lib"));
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "lib", "sqlite3_x64.lib"));
		}
		bEnableUndefinedIdentifierWarnings = false;
	}
}