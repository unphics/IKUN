#pragma once

#include "Modules/ModuleManager.h"
#include "AssetToolsModule.h"
#include "IKUNAssetActions.h"

class FIKUNAssetEditorModule: public IModuleInterface{
public:
	TSharedPtr<IAssetTypeActions> action;
	virtual void StartupModule() override {
		IAssetTools& assetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		action  = MakeShareable(new FIKUNAssetActions);
		assetTools.RegisterAssetTypeActions(action.ToSharedRef());
	}
	virtual void ShutdownModule() override {
		FAssetToolsModule* assetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools");
		if (assetToolsModule) {
			IAssetTools& assetTools = assetToolsModule->Get();
			if (this->action.IsValid()) {
				assetTools.UnregisterAssetTypeActions(action.ToSharedRef());
			}
		}
	}	
};
IMPLEMENT_MODULE(FIKUNAssetEditorModule, IKUNAssetEditor)