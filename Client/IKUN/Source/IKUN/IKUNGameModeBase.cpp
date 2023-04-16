// Copyright Epic Games, Inc. All Rights Reserved.


#include "IKUNGameModeBase.h"
#include "Test.pb.h"
#include "PBMgr.h"

void AIKUNGameModeBase::StartPlay() {
	Super::StartPlay();
	UE_LOG(LogTemp, Display, TEXT("=========== GameModeBase::StartPlay() =========="));
	Super::StartPlay();
	//SearchRequest sr;
	//sr.set_page_number(666);
	//sr.set_query("qqqqqqqqq");
	//FString str = sr.query().c_str();
	//UE_LOG(LogTemp, Display, TEXT("======= num: %d, str: %s"), sr.clear_page_number(), str);
	//UE_LOG(LogTemp, Display, TEXT("========== num: %d"), sr.page_number());

	UPBMgr* mgr = NewObject<UPBMgr>();
	SearchRequest* obj = mgr->PBNew<SearchRequest>(std::string("SearchRequest"));

}
