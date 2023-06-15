// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode/IKUNGameModeBase.h"
#include "3DMath/Vector.h"
#include "3DMath/Matrix.h"

void AIKUNGameModeBase::StartPlay() {
	Super::StartPlay();
	UE_LOG(LogTemp, Warning, TEXT("=========== GameModeBase StartPlay =========="));
	this->sqliteMgr = NewObject<USQLiteMgr>();

	Vector::func();
	Matrix::func();
}

void AIKUNGameModeBase::BeginDestroy() {
	Super::BeginDestroy();
	
}
