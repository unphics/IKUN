// Copyright Epic Games, Inc. All Rights Reserved.

#include "MVVMTemplateGenerateCommands.h"

#define LOCTEXT_NAMESPACE "FMVVMTemplateGenerateModule"

void FMVVMTemplateGenerateCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "MVVMTemplateGenerate", "Execute MVVMTemplateGenerate action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
