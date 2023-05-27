using UnrealBuildTool;
using System.IO;

public class IKUNAssetEditor : ModuleRules {
	public IKUNAssetEditor(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivateIncludePaths.AddRange(new string[]{"IKUNAssetEditor/Private/Actions", "IKUNAssetEditor/Public"});
		PublicIncludePaths.AddRange(new string[]{"IKUNAssetEditor/Public"});
		PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
		PublicDependencyModuleNames.AddRange(new string[]{"Core"});
		PrivateDependencyModuleNames.AddRange(new string[]{"CoreUObject", "Engine", "Slate", "SlateCore", "UnrealEd", "IKUNAsset"});
	}
}