// Copyright Epic Games, Inc. All Rights Reserved.


#include "IKUNGameModeBase.h"
#include "PBMgr.h"

void AIKUNGameModeBase::StartPlay() {
	Super::StartPlay();
	UE_LOG(LogTemp, Display, TEXT("=========== GameModeBase::StartPlay() =========="));
	Super::StartPlay();
	//SearchRequest sr;
	//sr.set_page_number(666);
	//sr.set_query("qqqqqqqqq");
	//FString str = sr.query().c_str();
	//UE_LOG(LogTemp, Display, TEXT("========== num: %d"), sr.page_number());

	UPBMgr* mgr = NewObject<UPBMgr>();
	this->psr = mgr->p;
	(*psr).set_page_number(9898998);
	(*psr).set_query("xiao hei zi");
	FString str = psr->query().c_str();
	std::cout << "str::::::" << psr->query() << std::endl;
	UE_LOG(LogTemp, Display, TEXT("========== str: %d"), psr->page_number());
	//SearchRequest* obj = mgr->PBNew<SearchRequest>(std::string("SearchRequest"));
}
