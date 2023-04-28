// Fill out your copyright notice in the Description page of Project Settings.


#include "SQLite/SQLiteMgr.h"
#include "SQLiteResultSet.h"

void USQLiteMgr::PostInitProperties() {
	Super::PostInitProperties();
	// 初始化sqlite对象，以此打开和链接db文件
	this->sqlite = new FSQLiteDatabase();
	// 打开基础表
	FString pathBaseDb = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir() / "SQLiteDB"/ "IKUNDataBase.db");
	if(!sqlite->Open(*pathBaseDb, ESQLiteDatabaseOpenMode::ReadOnly)) { //  || !sqlite->IsValid()
		UE_LOG(LogLoad, Error, TEXT("Failed to Open SQLite : %s !!!"), *sqlite->GetLastError());
		// 初始化失败
	} else {
		FSQLitePreparedStatement allTableStatment;
		allTableStatment.Create(*sqlite, TEXT("select * from AllTable"), ESQLitePreparedStatementFlags::Persistent);
		this->arrStatment.Add(TEXT("All"), &allTableStatment);
	}
}
void USQLiteMgr::BeginDestroy() {
	Super::BeginDestroy();
	if(!sqlite->Close()) {
		UE_LOG(LogLoad, Error, TEXT("Failed to Close SQLite : %s !!!"), *sqlite->GetLastError());
	} else {
		delete sqlite;
	}
}
void USQLiteMgr::GetRowByID(FString path,FString tableName,FString id,
		std::function<ESQLitePreparedStatementExecuteRowResult(const FSQLitePreparedStatement&)> InCallback) {
	FString ppath = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()/path);
	if(this->sqlite->Open(*ppath,ESQLiteDatabaseOpenMode::ReadOnly) == true) {
		UE_LOG(LogLoad,Warning,TEXT("Open Data Base Succeed !!!"));
		FString str = FString::Printf(TEXT("SELECT * FROM %s WHERE ID = %s"),*tableName, *id);
		this->sqlite->Execute(*str, InCallback);
		sqlite->Close();
	} else {
		UE_LOG(LogLoad,Warning,TEXT("Open Data Base Failed !!!"));
	}
}
ANSICHAR* USQLiteMgr::GetByName(const FSQLitePreparedStatement& db, const TCHAR* name, bool & b) {
	FString str;
	b &= db.GetColumnValueByName(name, str);
	return TCHAR_TO_UTF8(*str);
}
ANSICHAR* USQLiteMgr::GetByName(const FSQLitePreparedStatement& db, const TCHAR* name) {
	FString str;
	bool b = db.GetColumnValueByName(name, str);
	if(!b) {
		UE_LOG(LogTemp,Error,TEXT("SQLite Find Field '%s' Failed !!!"), *FString(name));
	}
	return TCHAR_TO_UTF8(*str);
}