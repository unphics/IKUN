// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestEditorStandaloneWindow.h"
#include "TestEditorStandaloneWindowStyle.h"
#include "TestEditorStandaloneWindowCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "Widgets/Input/SSlider.h"

static const FName TestEditorStandaloneWindowTabName("TestEditorStandaloneWindow");
static const FName tab0("tab0");
static const FName tab1("tab1");
static const FName prefab("prefab");

#define LOCTEXT_NAMESPACE "FTestEditorStandaloneWindowModule"

void FTestEditorStandaloneWindowModule::StartupModule() {
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FTestEditorStandaloneWindowStyle::Initialize();
	FTestEditorStandaloneWindowStyle::ReloadTextures();

	FTestEditorStandaloneWindowCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	// 绑定“编辑器独立窗口”点击事件
	PluginCommands->MapAction(
		FTestEditorStandaloneWindowCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FTestEditorStandaloneWindowModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FTestEditorStandaloneWindowModule::RegisterMenus));

	// 注册了一个普通的标签页的生成器
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TestEditorStandaloneWindowTabName, FOnSpawnTab::CreateRaw(this, &FTestEditorStandaloneWindowModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FTestEditorStandaloneWindowTabTitle", "TestEditorStandaloneWindow"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	// 一个btn
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(tab0,FOnSpawnTab::CreateLambda([](const FSpawnTabArgs& spawnTabArgs) {
		FText txt = LOCTEXT("WindowWidgetText","tab0");
		return SNew(SDockTab).TabRole(NomadTab)
		[
			SNew(SButton).HAlign(HAlign_Fill).VAlign(VAlign_Fill).OnClicked_Lambda([]() {
				UE_LOG(LogTemp,Warning,TEXT("你干嘛					~哎呦"));
				return FReply::Handled();
			})
			[
				SNew(STextBlock).Text(txt)
			]
		];
	})).SetDisplayName(LOCTEXT("tab0TabTitle","tab0")).SetMenuType(ETabSpawnerMenuType::Enabled);

	// 一个slider
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(tab1, FOnSpawnTab::CreateLambda([](const FSpawnTabArgs& spawnTabArgs) {
		TSharedRef<SSlider> mySlider = SNew(SSlider).Value(0.2f);
		FText widgetTxt = FText::Format(LOCTEXT("WindowWidgetText","Add code to {0} to overrride this window's contents"),
			FText::FromString(TEXT("TestEditorStandaloneWindow.cpp")));
		return SNew(SDockTab).TabRole(NomadTab)
		[
			SNew(SVerticalBox) + SVerticalBox::Slot()
			[
				mySlider
			]
			+ SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text_Lambda([mySlider]() {
					int32 result = (int32)(mySlider->GetValue() * 100);
					return FText::FromString(FString::FromInt(result));
				})
			]
		];
	})).SetDisplayName(LOCTEXT("tab0TabTitle","tab1")).SetMenuType(ETabSpawnerMenuType::Enabled);

	// 一个prefab
	// FGlobalTabmanager::Get()->RegisterNomadTabSpawner(prefab,FOnSpawnTab::CreateLambda([](const FSpawnTabArgs& spawnTabArgs) {
	// 	return SNew(SDockTab).TabRole(NomadTab)
	// 	[
	// 		// SNew()
	// 	];
	// }));
}

void FTestEditorStandaloneWindowModule::ShutdownModule() {
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FTestEditorStandaloneWindowStyle::Shutdown();

	FTestEditorStandaloneWindowCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TestEditorStandaloneWindowTabName);
}

TSharedRef<SDockTab> FTestEditorStandaloneWindowModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FTestEditorStandaloneWindowModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("TestEditorStandaloneWindow.cpp"))
		);

	return SNew(SDockTab) // 一个停靠的标签页
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FTestEditorStandaloneWindowModule::PluginButtonClicked() {
	// 点击后呼叫了一个标签页
	FGlobalTabmanager::Get()->TryInvokeTab(TestEditorStandaloneWindowTabName);
	{
		FGlobalTabmanager::Get()->TryInvokeTab(tab0);
		FGlobalTabmanager::Get()->TryInvokeTab(tab1);
	}
}

void FTestEditorStandaloneWindowModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FTestEditorStandaloneWindowCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FTestEditorStandaloneWindowCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestEditorStandaloneWindowModule, TestEditorStandaloneWindow)
