// Fill out your copyright notice in the Description page of Project Settings.


#include "SQLite/SQLiteMgr.h"

void USQLiteMgr::PostInitProperties() {
	Super::PostInitProperties();
	this->InitSQliteMgr();
}

void USQLiteMgr::BeginDestroy() {
	Super::BeginDestroy();
	sqlite3_close(this->pSQLite);
}
bool USQLiteMgr::InitSQliteMgr() {
	FString basePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir() / L"SQLiteDB" / L"IKUNDataBase.db");
	if(!FPaths::FileExists((basePath))) { // 检查文件存在
		UE_LOG(LogTemp, Error, TEXT("Data Base Not Exist !!!"));
		return false;
	}
	if(sqlite3_open_v2(TCHAR_TO_UTF8(*basePath), &(this->pSQLite), SQLITE_OPEN_READONLY,
		nullptr) != SQLITE_OK) { // 打开表
		UE_LOG(LogTemp, Error, TEXT("Open Data Base Failed !!!"));
		return false;
	}
	const char* sql = "SELECT * FROM AllTable WHERE ID = ?";
	sqlite3_stmt* stmtBase;
	if(sqlite3_prepare_v3(this->pSQLite, sql, -1, SQLITE_OPEN_READONLY, &stmtBase,
		nullptr) != SQLITE_OK) { // 保持一个statement
		UE_LOG(LogTemp, Error, TEXT("Failed to Create SQLite Statement !!!"));
		return false;
	}
	// 循环取到所有的表名
	int id = 1;
	sqlite3_bind_int(stmtBase, 1, id);
	while(sqlite3_step(stmtBase) == SQLITE_ROW) {
		//
		arrTableName.push_back(std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmtBase,1)),strlen(reinterpret_cast<const char*>(sqlite3_column_text(stmtBase,1)))));
		FString tableName = FString::Printf(TEXT("%s"), UTF8_TO_TCHAR(reinterpret_cast<const char*>(
			sqlite3_column_text(stmtBase,1))));
		UE_LOG(LogTemp, Warning, TEXT("Get Table Name: %s"), *tableName);
		id += 1;
		sqlite3_reset(stmtBase);
		sqlite3_bind_int(stmtBase, 1, id);
	}
	sqlite3_finalize(stmtBase);
	UE_LOG(LogTemp, Warning, TEXT("Get Table Count: %llu"), arrTableName.size());
	// 循环取出所有的表的stmt
	bool result = true;
	for(int i = 0; i < arrTableName.size(); i++) {
		std::string cmd = "SELECT * FROM " + arrTableName[i] + " WHERE ID = ?";
		sqlite3_stmt* stmt;
		FString tmp = cmd.c_str();
		UE_LOG(LogTemp,Warning,TEXT("for cur sql cmd :%s"),*tmp);
		if(sqlite3_prepare_v3(this->pSQLite, cmd.c_str(), -1, SQLITE_OPEN_READONLY, &stmt,
			nullptr) != SQLITE_OK) {
			result = false;
			FString nametable = std::string(arrTableName[i]).c_str();
			UE_LOG(LogTemp, Error, TEXT("Failed to Open Data Base : %s"), *nametable);
			continue;
		}
		mapStmt.Add(arrTableName[i].c_str(),stmt);
	}
	return true;
}