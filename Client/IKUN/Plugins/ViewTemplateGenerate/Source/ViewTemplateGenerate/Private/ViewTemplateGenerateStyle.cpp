// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewTemplateGenerateStyle.h"
#include "ViewTemplateGenerate.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FViewTemplateGenerateStyle::StyleInstance = nullptr;

void FViewTemplateGenerateStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FViewTemplateGenerateStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FViewTemplateGenerateStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("ViewTemplateGenerateStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FViewTemplateGenerateStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("ViewTemplateGenerateStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("ViewTemplateGenerate")->GetBaseDir() / TEXT("Resources"));

	// Style->Set("ViewTemplateGenerate.PluginAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));

	// 设置按钮样式
	FString imgPath = TEXT("kk.jpg");
	Style->Set("ViewTemplateGenerate.PluginAction", new FSlateImageBrush(RootToContentDir(imgPath), Icon20x20));
	
	return Style;
}

void FViewTemplateGenerateStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FViewTemplateGenerateStyle::Get()
{
	return *StyleInstance;
}
