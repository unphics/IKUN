// Copyright Epic Games, Inc. All Rights Reserved.

#include "MVVMTemplateGenerate.h"
#include "MVVMTemplateGenerateStyle.h"
#include "MVVMTemplateGenerateCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "MVVMTemplateGen.h"

static const FName MVVMTemplateGenerateTabName("MVVMTemplateGenerate");
#define LOCTEXT_NAMESPACE "FMVVMTemplateGenerateModule"

void FMVVMTemplateGenerateModule::StartupModule() {
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FMVVMTemplateGenerateStyle::Initialize();
	FMVVMTemplateGenerateStyle::ReloadTextures();
	FMVVMTemplateGenerateCommands::Register();
	PluginCommands = MakeShareable(new FUICommandList);
	PluginCommands->MapAction(
		FMVVMTemplateGenerateCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FMVVMTemplateGenerateModule::PluginButtonClicked),
		FCanExecuteAction());
	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMVVMTemplateGenerateModule::RegisterMenus));
}

void FMVVMTemplateGenerateModule::ShutdownModule() {
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);
	FMVVMTemplateGenerateStyle::Shutdown();
	FMVVMTemplateGenerateCommands::Unregister();
}

void FMVVMTemplateGenerateModule::PluginButtonClicked() {
	MVVMTemplateGen::Gen();
}

void FMVVMTemplateGenerateModule::RegisterMenus() {
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);
	{
		// 定位加在哪里；定位段；在段里添加动作
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
		Section.AddMenuEntryWithCommandList(FMVVMTemplateGenerateCommands::Get().PluginAction, PluginCommands);
	}
	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("MVVMTemplateGen");
		FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMVVMTemplateGenerateCommands::Get().PluginAction));
		Entry.SetCommandList(PluginCommands);
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMVVMTemplateGenerateModule, MVVMTemplateGenerate)