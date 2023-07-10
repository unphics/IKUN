// Copyright Epic Games, Inc. All Rights Reserved.

#include "MVVMTemplateGenerateStyle.h"
#include "MVVMTemplateGenerate.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FMVVMTemplateGenerateStyle::StyleInstance = nullptr;

void FMVVMTemplateGenerateStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FMVVMTemplateGenerateStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FMVVMTemplateGenerateStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MVVMTemplateGenerateStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FMVVMTemplateGenerateStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("MVVMTemplateGenerateStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("MVVMTemplateGenerate")->GetBaseDir() / TEXT("Resources"));

	// Style->Set("MVVMTemplateGenerate.PluginAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));

	// 设置按钮样式
	FString imgPath = TEXT("kk.jpg");
	Style->Set("MVVMTemplateGenerate.PluginAction", new FSlateImageBrush(RootToContentDir(imgPath), Icon20x20));
	
	return Style;
}

void FMVVMTemplateGenerateStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FMVVMTemplateGenerateStyle::Get()
{
	return *StyleInstance;
}
