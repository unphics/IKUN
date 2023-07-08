// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode/IKUNGameModeBase.h"
#include "3DMath/Math.h"

void AIKUNGameModeBase::StartPlay() {
	Super::StartPlay();
	UE_LOG(LogTemp, Warning, TEXT("=========== GameModeBase StartPlay =========="));
	this->sqliteMgr = NewObject<USQLiteMgr>();

	UClass* bp = LoadClass<AActor>(nullptr, TEXT("Blueprint'/Game/BP_Actor.BP_Actor_C'"));
	for(TFieldIterator<FProperty> it(bp); it; ++it) {
		auto i = it;
		// if(TIsSame<FName, decltype(i)>::Value) {
		// 	UE_LOG(LogTemp, Warning, TEXT("find uclass field which is fname"));
		// }
		UE_LOG(LogTemp, Warning, TEXT("property: %s, %s"), *(it->GetName()), *(it->GetFName().ToString()));
	}

	Math::run();
}

void AIKUNGameModeBase::BeginDestroy() {
	Super::BeginDestroy();
	
}
