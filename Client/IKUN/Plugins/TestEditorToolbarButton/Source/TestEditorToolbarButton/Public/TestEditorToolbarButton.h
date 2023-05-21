// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FBlueprintEditor;
class FWorkflowAllowedTabSet;
class FToolBarBuilder;
class FMenuBuilder;

class FTestEditorToolbarButtonModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	
private:

	void RegisterMenus();

	void AddMenuExtension(FMenuBuilder& Builder);
	void AddMenuBarExtension(FMenuBarBuilder& Builder);
	void AddToolBarExtension(FToolBarBuilder& Builder);
	void AddBPMenuExtension(FMenuBuilder& Builder);
	void OnBPToolBarRegister(FWorkflowAllowedTabSet& TabSet, FName Name, TSharedPtr<FBlueprintEditor> BP);
private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
