// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SQLite/SQLiteMgr.h"
#include "IKUNGameInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class IKUN_API UIKUNGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void PostInitProperties() override;
	USQLiteMgr* SQLiteMgr;
};
