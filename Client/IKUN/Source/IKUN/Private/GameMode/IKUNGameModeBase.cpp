// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode/IKUNGameModeBase.h"

void AIKUNGameModeBase::StartPlay() {
	Super::StartPlay();
	UE_LOG(LogTemp, Warning, TEXT("=========== GameModeBase StartPlay =========="));
	this->sqliteMgr = NewObject<USQLiteMgr>();
}

void AIKUNGameModeBase::BeginDestroy() {
	Super::BeginDestroy();
	
}
