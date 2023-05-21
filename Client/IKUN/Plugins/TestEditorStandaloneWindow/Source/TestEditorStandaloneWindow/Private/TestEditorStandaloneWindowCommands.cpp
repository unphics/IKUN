// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestEditorStandaloneWindowCommands.h"

#define LOCTEXT_NAMESPACE "FTestEditorStandaloneWindowModule"

void FTestEditorStandaloneWindowCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "TestEditorStandaloneWindow", "Bring up TestEditorStandaloneWindow window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
