// Fill out your copyright notice in the Description page of Project Settings.


#include "SQLite/SQLiteMgr.h"
#include "SQLiteResultSet.h"

void USQLiteMgr::PostInitProperties() {
	Super::PostInitProperties();
	// this->sqlite = NewObject<FSQLiteDatabase>();
	this->sqlite = MakeShared<FSQLiteDatabase>();
}
void USQLiteMgr::BeginDestroy() {
	Super::BeginDestroy();
}
void USQLiteMgr::GetRowByID(FString relativePath,FString tableName,FString id,
		std::function<ESQLitePreparedStatementExecuteRowResult(const FSQLitePreparedStatement&)> InCallback){
	FString path = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()/relativePath);
	if(this->sqlite->Open(*path,ESQLiteDatabaseOpenMode::ReadOnly)) {
		UE_LOG(LogLoad,Warning,TEXT("Open Data Base Succeed !!!"));
		FString str(TEXT("SELECT * FROM %s WHERE ID = %s", *tableName, *id));
		this->sqlite->Execute(*str, InCallback);
	} else {
		UE_LOG(LogLoad,Warning,TEXT("Open Data Base Failed !!!"));
	}
	sqlite->Close();
}

