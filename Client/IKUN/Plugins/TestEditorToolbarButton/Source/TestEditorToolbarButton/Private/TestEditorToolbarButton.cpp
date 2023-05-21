// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestEditorToolbarButton.h"
#include "TestEditorToolbarButtonStyle.h"
#include "TestEditorToolbarButtonCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
// 两个模块的头文件
#include "IAnimationBlueprintEditorModule.h" // 动画蓝图相关
#include "BlueprintEditorModule.h" // 蓝图编辑器模块
#include "WorkflowOrientedApp/WorkflowTabManager.h"
#include "BlueprintEditor.h"

static const FName TestEditorToolbarButtonTabName("TestEditorToolbarButton");

#define LOCTEXT_NAMESPACE "FTestEditorToolbarButtonModule"

void FTestEditorToolbarButtonModule::StartupModule() {
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FTestEditorToolbarButtonStyle::Initialize(); // 长得像是决定样式的
	FTestEditorToolbarButtonStyle::ReloadTextures();

	FTestEditorToolbarButtonCommands::Register(); // 决定安妮命令的 
	
	PluginCommands = MakeShareable(new FUICommandList);

	// 像是一个绑定，映射动作的
	PluginCommands->MapAction(
		FTestEditorToolbarButtonCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FTestEditorToolbarButtonModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FTestEditorToolbarButtonModule::RegisterMenus));
}

void FTestEditorToolbarButtonModule::ShutdownModule() {
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FTestEditorToolbarButtonStyle::Shutdown();

	FTestEditorToolbarButtonCommands::Unregister();
}

void FTestEditorToolbarButtonModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	// 内容：将代码添加到TestEditorToolbarButton.cpp中的FTestEditorToolbar按钮模块：PluginButtonClicked()以覆盖此按钮的操作
	FText DialogText = FText::Format(
							// LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							LOCTEXT("PluginButtonDialogText", "这里是测试的编辑器工具按钮点击弹窗。\n添加代码到{1}中的{1}来覆盖这个按钮的操作。"),
							FText::FromString(TEXT("FTestEditorToolbarButtonModule::PluginButtonClicked()")),
							FText::FromString(TEXT("TestEditorToolbarButton.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FTestEditorToolbarButtonModule::RegisterMenus() {
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);
	{
		// 定位到要加在哪里
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		// 找到段
		FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
		// 在段里面，添加动作
		Section.AddMenuEntryWithCommandList(FTestEditorToolbarButtonCommands::Get().PluginAction, PluginCommands);
	}
	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
		FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FTestEditorToolbarButtonCommands::Get().PluginAction));
		Entry.SetCommandList(PluginCommands);
	}
	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
		// 以下为自己添加的。注意：不要在同一个位置添加两次同一个操作的入口。
		FToolMenuEntry* entry = &Section.AddEntry(
			FToolMenuEntry::InitToolBarButton(
				FTestEditorToolbarButtonCommands::Get().PluginAction,
				TAttribute<FText>(), // 这些都是默认参数，相当于没写
				TAttribute<FText>(),
				TAttribute<FSlateIcon>(),
				NAME_None,
				TOptional<FName>("又是我")
				)
			);
		entry->SetCommandList(PluginCommands);
		entry->InsertPosition.Position = EToolMenuInsertType::First;
	}
	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		// 再加一个，这次选择文件段
		FToolMenuSection* sectionFile = &ToolbarMenu->FindOrAddSection("File");
		FToolMenuEntry* entry = &sectionFile->AddEntry(FToolMenuEntry::InitToolBarButton(FTestEditorToolbarButtonCommands::Get().PluginAction));
		entry->SetCommandList(PluginCommands);
		entry->InsertPosition.Position = EToolMenuInsertType::First;
	}
	{
		// 加一个主菜单的
		UToolMenus* toolMenus = UToolMenus::Get();
		UToolMenu* ikunMenu = toolMenus->RegisterMenu("LevelEditor.MainMenu.IKUN");
		UToolMenu* menuBar = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu");
		FToolMenuSection& section = ikunMenu->AddSection("MySection0");
		section.AddMenuEntryWithCommandList(FTestEditorToolbarButtonCommands::Get().PluginAction,PluginCommands);
		menuBar->AddSubMenu(
			"MainMenu",
			"MySection0",
			"IKUN",
			LOCTEXT("MyMenu","IKUN"));
	}
	IAnimationBlueprintEditorModule& animBPEditorModule = FModuleManager::LoadModuleChecked<IAnimationBlueprintEditorModule>("AnimationBlueprintEditor");
	{
		// 在动画蓝图编辑器的帮助菜单里添加一个编辑器工具扩展按钮
		TSharedPtr<FExtender> menuExtender = MakeShareable(new FExtender);
		// 扩展器就是对扩展行为的包装
		menuExtender->AddMenuExtension("HelpApplication"/*在哪儿扩展，定位的扩展点*/,
			EExtensionHook::After, PluginCommands,
			FMenuExtensionDelegate::CreateRaw(this, &FTestEditorToolbarButtonModule::AddMenuExtension));
		animBPEditorModule.GetMenuExtensibilityManager()->AddExtender(menuExtender);
	}
	{
		// 在动画蓝图编辑器的菜单条里新增一项
		TSharedPtr<FExtender> menuExtender = MakeShareable(new FExtender);
		menuExtender->AddMenuBarExtension("Help", EExtensionHook::After,PluginCommands,
			FMenuBarExtensionDelegate::CreateRaw(this, &FTestEditorToolbarButtonModule::AddMenuBarExtension));
		animBPEditorModule.GetMenuExtensibilityManager()->AddExtender(menuExtender);
	}
	{
		// 在动画蓝图编辑器的工具条里新增一项
		TSharedPtr<FExtender> menuExtender = MakeShareable(new FExtender);
		menuExtender->AddToolBarExtension("Settings",EExtensionHook::After,PluginCommands,
			FToolBarExtensionDelegate::CreateRaw(this,&FTestEditorToolbarButtonModule::AddToolBarExtension));
		animBPEditorModule.GetToolBarExtensibilityManager()->AddExtender(menuExtender);
	}
	{
		// 普通蓝图窗口
		FBlueprintEditorModule& BPEditorModule = FModuleManager::LoadModuleChecked<FBlueprintEditorModule>(TEXT("Kismet"));
		TSharedPtr<FExtender> menuExtender = MakeShareable(new FExtender);
		menuExtender->AddMenuExtension("HelpApplication",EExtensionHook::After,PluginCommands,
			FMenuExtensionDelegate::CreateRaw(this,&FTestEditorToolbarButtonModule::AddBPMenuExtension));
		BPEditorModule.GetMenuExtensibilityManager()->AddExtender(menuExtender);
		// http://wlosok.cz/editor-plugins-in-ue4-3-toolbar-button/
	}
	{
		// 蓝图编辑器窗口菜单扩展
		UToolMenu* menu = UToolMenus::Get()->ExtendMenu("AssetEditor.BlueprintEditor.MainMenu.Window");
		FToolMenuSection& section = menu->FindOrAddSection("WindowLayout");
		section.AddMenuEntryWithCommandList(FTestEditorToolbarButtonCommands::Get().PluginAction,PluginCommands);
	}
	{
		// 蓝图编辑器工具栏扩展
		FBlueprintEditorModule& BlueprintEditorModule = FModuleManager::LoadModuleChecked<FBlueprintEditorModule>(TEXT("Kismet"));
		BlueprintEditorModule.OnRegisterTabsForEditor().AddRaw(this, &FTestEditorToolbarButtonModule::OnBPToolBarRegister);
	}
}

void FTestEditorToolbarButtonModule::AddMenuExtension(FMenuBuilder& Builder) {
	Builder.BeginSection(TEXT("MyButton"));
	Builder.AddMenuEntry(FTestEditorToolbarButtonCommands::Get().PluginAction);
	Builder.EndSection();
}
void FTestEditorToolbarButtonModule::AddMenuBarExtension(FMenuBarBuilder& Builder) {
	Builder.AddMenuEntry(FTestEditorToolbarButtonCommands::Get().PluginAction);
}

void FTestEditorToolbarButtonModule::AddToolBarExtension(FToolBarBuilder& Builder) {
	Builder.BeginSection(TEXT("My___Button"));
	Builder.AddToolBarButton(FTestEditorToolbarButtonCommands::Get().PluginAction);
	Builder.EndSection();
}

void FTestEditorToolbarButtonModule::AddBPMenuExtension(FMenuBuilder& Builder) {
	Builder.BeginSection(TEXT("MyButton"));
	Builder.AddMenuEntry(FTestEditorToolbarButtonCommands::Get().PluginAction);
	Builder.EndSection();
}

void FTestEditorToolbarButtonModule::OnBPToolBarRegister(FWorkflowAllowedTabSet& TabSet, FName Name, TSharedPtr<FBlueprintEditor> BP) {
	TSharedPtr<FExtender> toolBarExtender = MakeShareable(new FExtender);
	toolBarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands,
		FToolBarExtensionDelegate::CreateRaw(this, &FTestEditorToolbarButtonModule::AddToolBarExtension));
	BP->AddToolbarExtender(toolBarExtender);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestEditorToolbarButtonModule, TestEditorToolbarButton)