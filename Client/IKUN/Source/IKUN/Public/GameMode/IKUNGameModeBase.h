// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Test.pb.h"
#include "IKUNGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class IKUN_API AIKUNGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:

	virtual void StartPlay();
	SearchRequest* psr;
};
