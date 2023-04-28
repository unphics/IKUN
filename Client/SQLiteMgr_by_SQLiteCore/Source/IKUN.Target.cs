// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class IKUNTarget : TargetRules
{
	public IKUNTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "IKUN" } ); 
        //ExtraModuleNames.AddRange(new string[] { "IKUNProtos" });
    }
}
