#pragma once
#include "IKUNAssetToolkit.h"
#include "IKUNAsset.h"
#include "Widgets/Input/SSlider.h"

namespace IkunAssetToolkit {
	static const FName AppIdentifier("IKUNAssetEditorApp");
	static const FName TabId("IKUNAssetEditTab"); // 标签页的名字
}

void FIKUNAssetToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& inTabManager) {
	FAssetEditorToolkit::RegisterTabSpawners(inTabManager);
	SAssignNew(textBlock, STextBlock).Text(FText::FromString(FString::FromInt(IsValid(ikunAsset) ? ikunAsset->id : 0)));
	// 注册自己的标签页
	inTabManager->RegisterTabSpawner(IkunAssetToolkit::TabId, FOnSpawnTab::CreateLambda([this](const FSpawnTabArgs& args) {
		return SNew(SDockTab).TabRole(PanelTab)[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().FillWidth(1).HAlign(HAlign_Fill).VAlign(VAlign_Fill)[detailsView.ToSharedRef()]
			+ SHorizontalBox::Slot().FillWidth(1).HAlign(HAlign_Center).VAlign(VAlign_Center)[textBlock.ToSharedRef()]
			+ SHorizontalBox::Slot().FillWidth(1).HAlign(HAlign_Fill).VAlign(VAlign_Center)[
				SNew(SSlider).Value(IsValid(ikunAsset) ? ikunAsset->id / 10000.f : 0.f)
				.OnValueChanged_Lambda([this](float value) {
					UE_LOG(LogTemp,Error,TEXT("走到这里了  0"));
					if (textBlock.IsValid()) {
						textBlock->SetText(FText::FromString(FString::FromInt((int32)(value * 10000))));
					}
					if (IsValid(ikunAsset)) {
						ikunAsset->id = (int32)(value * 10000);
					}
				})
				.OnMouseCaptureEnd_Lambda([this]() {ikunAsset->MarkPackageDirty();})
			]
		];
	}));
}

void FIKUNAssetToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& inTabManager) {
	FAssetEditorToolkit::UnregisterTabSpawners(inTabManager);
	inTabManager->UnregisterTabSpawner(IkunAssetToolkit::TabId);
}

void FIKUNAssetToolkit::Initialize(UIKUNAsset* InNewAsset, const EToolkitMode::Type InMode,
	const TSharedPtr<IToolkitHost>& InToolkitHost) {
	ikunAsset = InNewAsset;
	UE_LOG(LogTemp,Error,TEXT("走到这里了  1"));
	// 构造一个layout
	const TSharedRef<FTabManager::FLayout> layout = FTabManager::NewLayout("IKUNAssetEditor")->AddArea(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Horizontal)
		->Split(FTabManager::NewStack()->AddTab(GetToolbarTabId(), ETabState::OpenedTab))
		// 要把自己的标签页放进去
		->Split(FTabManager::NewStack()->AddTab(IkunAssetToolkit::TabId, ETabState::OpenedTab))
	);
	InitAssetEditor(InMode,InToolkitHost,IkunAssetToolkit::AppIdentifier,layout, true, true, InNewAsset);
	RegenerateMenusAndToolbars(); // 重新生成菜单和工具条
	UE_LOG(LogTemp,Error,TEXT("走到这里了  2"));
}

FText FIKUNAssetToolkit::GetBaseToolkitName() const {
	return FText::FromString(TEXT("IKUNAssetBaseToolkit"));
}
FName FIKUNAssetToolkit::GetToolkitFName() const {
	return FName("IKUNAssetToolkit");
}
FLinearColor FIKUNAssetToolkit::GetWorldCentricTabColorScale() const {
	return FLinearColor(0.5f, 0.2f, 0.3f, 0.4f);
}
FString FIKUNAssetToolkit::GetWorldCentricTabPrefix() const {
	return FString(TEXT("IKUNAssetEditorPrefix"));
}
