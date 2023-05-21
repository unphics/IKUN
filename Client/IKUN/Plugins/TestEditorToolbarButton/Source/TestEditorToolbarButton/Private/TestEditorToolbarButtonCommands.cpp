// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestEditorToolbarButtonCommands.h"

#define LOCTEXT_NAMESPACE "FTestEditorToolbarButtonModule"

void FTestEditorToolbarButtonCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "TestEditorToolbarButton", "Execute TestEditorToolbarButton action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
