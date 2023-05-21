// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "TestEditorStandaloneWindowStyle.h"

class FTestEditorStandaloneWindowCommands : public TCommands<FTestEditorStandaloneWindowCommands>
{
public:

	FTestEditorStandaloneWindowCommands()
		: TCommands<FTestEditorStandaloneWindowCommands>(TEXT("TestEditorStandaloneWindow"), NSLOCTEXT("Contexts", "TestEditorStandaloneWindow", "TestEditorStandaloneWindow Plugin"), NAME_None, FTestEditorStandaloneWindowStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};