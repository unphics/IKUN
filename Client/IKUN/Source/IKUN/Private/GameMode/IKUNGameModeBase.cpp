// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode/IKUNGameModeBase.h"
#include "3DMath/Math.h"

void AIKUNGameModeBase::StartPlay() {
	Super::StartPlay();
	UE_LOG(LogTemp, Warning, TEXT("=========== GameModeBase StartPlay =========="));
	this->sqliteMgr = NewObject<USQLiteMgr>();

	Math::run();
}

void AIKUNGameModeBase::BeginDestroy() {
	Super::BeginDestroy();
	
}
