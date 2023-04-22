// Fill out your copyright notice in the Description page of Project Settings.


#include "SQLite/SQLiteMgr.h"

void USQLiteMgr::PostInitProperties() {
	Super::PostInitProperties();
	// this->sqlite = NewObject<FSQLiteDatabase>();
	this->sqlite = MakeShared<FSQLiteDatabase>();
}
void USQLiteMgr::BeginDestroy() {
	Super::BeginDestroy();
}
void USQLiteMgr::GetRowByID(FString relativePath){
	FString path = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()/relativePath);
	if(this->sqlite->Open(*path,ESQLiteDatabaseOpenMode::ReadOnly)) {
		UE_LOG(LogLoad,Warning,TEXT("Open Data Base Succeed !!!"));
	} else {
		UE_LOG(LogLoad,Warning,TEXT("Open Data Base Failed !!!"));
	}
	sqlite->Close();
}

