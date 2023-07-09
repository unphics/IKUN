// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewTemplateGenerateCommands.h"

#define LOCTEXT_NAMESPACE "FViewTemplateGenerateModule"

void FViewTemplateGenerateCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "ViewTemplateGenerate", "Execute ViewTemplateGenerate action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
