// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "ViewTemplateGenerateStyle.h"

class FViewTemplateGenerateCommands : public TCommands<FViewTemplateGenerateCommands>
{
public:

	FViewTemplateGenerateCommands()
		: TCommands<FViewTemplateGenerateCommands>(TEXT("ViewTemplateGenerate"), NSLOCTEXT("Contexts", "ViewTemplateGenerate", "ViewTemplateGenerate Plugin"), NAME_None, FViewTemplateGenerateStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
