// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MVVMTemplateGenerateStyle.h"

class FMVVMTemplateGenerateCommands : public TCommands<FMVVMTemplateGenerateCommands>
{
public:

	FMVVMTemplateGenerateCommands()
		: TCommands<FMVVMTemplateGenerateCommands>(TEXT("MVVMTemplateGenerate"), NSLOCTEXT("Contexts", "MVVMTemplateGenerate", "MVVMTemplateGenerate Plugin"), NAME_None, FMVVMTemplateGenerateStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
