#pragma once

class ViewTemplateGen {
public:
	static void Gen();
	static void LoadUMGAssets(FString pathBase, FString pathAdd);
	static void ReadUMG(FString refUAsset, FString pathGen, FString nameClass);
};
