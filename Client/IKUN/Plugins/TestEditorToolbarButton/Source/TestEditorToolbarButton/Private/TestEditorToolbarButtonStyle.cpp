// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestEditorToolbarButtonStyle.h"
#include "TestEditorToolbarButton.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FTestEditorToolbarButtonStyle::StyleInstance = nullptr;

void FTestEditorToolbarButtonStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FTestEditorToolbarButtonStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FTestEditorToolbarButtonStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("TestEditorToolbarButtonStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FTestEditorToolbarButtonStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("TestEditorToolbarButtonStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("TestEditorToolbarButton")->GetBaseDir() / TEXT("Resources"));

	FString imgPath = TEXT("20230521215338.jpg");
	Style->Set("TestEditorToolbarButton.PluginAction", new FSlateImageBrush(RootToContentDir(imgPath), Icon20x20));
	return Style;
}

void FTestEditorToolbarButtonStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FTestEditorToolbarButtonStyle::Get()
{
	return *StyleInstance;
}
