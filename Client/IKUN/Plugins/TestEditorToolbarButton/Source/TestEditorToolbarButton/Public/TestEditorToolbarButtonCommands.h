// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "TestEditorToolbarButtonStyle.h"

class FTestEditorToolbarButtonCommands : public TCommands<FTestEditorToolbarButtonCommands>
{
public:

	FTestEditorToolbarButtonCommands()
		: TCommands<FTestEditorToolbarButtonCommands>(TEXT("TestEditorToolbarButton"), NSLOCTEXT("Contexts", "TestEditorToolbarButton", "TestEditorToolbarButton Plugin"), NAME_None, FTestEditorToolbarButtonStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
