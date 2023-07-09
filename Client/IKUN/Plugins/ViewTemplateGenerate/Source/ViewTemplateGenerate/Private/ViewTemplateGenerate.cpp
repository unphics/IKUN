// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewTemplateGenerate.h"
#include "ViewTemplateGenerateStyle.h"
#include "ViewTemplateGenerateCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "ViewTemplateGen.h"

static const FName ViewTemplateGenerateTabName("ViewTemplateGenerate");
#define LOCTEXT_NAMESPACE "FViewTemplateGenerateModule"

void FViewTemplateGenerateModule::StartupModule() {
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FViewTemplateGenerateStyle::Initialize();
	FViewTemplateGenerateStyle::ReloadTextures();
	FViewTemplateGenerateCommands::Register();
	PluginCommands = MakeShareable(new FUICommandList);
	PluginCommands->MapAction(
		FViewTemplateGenerateCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FViewTemplateGenerateModule::PluginButtonClicked),
		FCanExecuteAction());
	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FViewTemplateGenerateModule::RegisterMenus));
}

void FViewTemplateGenerateModule::ShutdownModule() {
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);
	FViewTemplateGenerateStyle::Shutdown();
	FViewTemplateGenerateCommands::Unregister();
}

void FViewTemplateGenerateModule::PluginButtonClicked() {
	ViewTemplateGen::Gen();
}

void FViewTemplateGenerateModule::RegisterMenus() {
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);
	{
		// 定位加在哪里；定位段；在段里添加动作
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
		Section.AddMenuEntryWithCommandList(FViewTemplateGenerateCommands::Get().PluginAction, PluginCommands);
	}
	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("ViewTemplateGen");
		FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FViewTemplateGenerateCommands::Get().PluginAction));
		Entry.SetCommandList(PluginCommands);
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FViewTemplateGenerateModule, ViewTemplateGenerate)