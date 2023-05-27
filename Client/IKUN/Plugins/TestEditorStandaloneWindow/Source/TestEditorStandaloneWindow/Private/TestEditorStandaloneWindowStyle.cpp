// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestEditorStandaloneWindowStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FTestEditorStandaloneWindowStyle::StyleInstance = nullptr;

void FTestEditorStandaloneWindowStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FTestEditorStandaloneWindowStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FTestEditorStandaloneWindowStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("TestEditorStandaloneWindowStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon30x30(30.0f, 30.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(Style->RootToContentDir(RelativePath, TEXT(".jpg")), __VA_ARGS__)

TSharedRef< FSlateStyleSet > FTestEditorStandaloneWindowStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("TestEditorStandaloneWindowStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("TestEditorStandaloneWindow")->GetBaseDir() / TEXT("Resources"));

	// Style->Set("TestEditorStandaloneWindow.OpenPluginWindow", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));

	FString imgPath = TEXT("20230521213836.jpg");
	// FSlateImageBrush* imgBrush = new FSlateImageBrush(imgPath, FVector2D(30.f, 30.f));
	// Style->Set("TestEditorStandaloneWindow.OpenPluginWindow", imgBrush);

	// Style->Set("TestEditorStandaloneWindow.OpenPluginWindow", new IMAGE_BRUSH(TEXT("20230521213836"), Icon30x30));
	Style->Set("TestEditorStandaloneWindow.OpenPluginWindow", new FSlateImageBrush(RootToContentDir(imgPath),Icon30x30));
	
	return Style;
}

#undef IMAGE_BRUSH

void FTestEditorStandaloneWindowStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FTestEditorStandaloneWindowStyle::Get()
{
	return *StyleInstance;
}
