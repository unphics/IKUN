// Fill out your copyright notice in the Description page of Project Settings.


#include "SQLite/SQLiteMgr.h"

void USQLiteMgr::PostInitProperties() {
	Super::PostInitProperties();
	if(this->OpenDataBase()) {
		const char* sql = "	SELECT * FROM users WHERE id = ?";
		sqlite3_stmt* stmt;
		if(sqlite3_prepare_v3(this->pSQLite, sql, -1, SQLITE_OPEN_READONLY, &stmt, nullptr) != SQLITE_OK) {
			UE_LOG(LogTemp,Warning,TEXT("Failed to Create SQLite Statement !!!"));
		}
		int id = 1;
		sqlite3_bind_int(stmt, 1, id);
		// sqlite3_step()
		if(sqlite3_step(stmt) == SQLITE_ROW) {
			const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt,1));
			UE_LOG(LogTemp,Warning,TEXT("--------- name: %s"), *FString(name));
		}else {
			UE_LOG(LogTemp,Warning,TEXT("Failed to Step SQLite Statement !!!"));
		}
		
		sqlite3_reset(stmt);
		sqlite3_finalize(stmt);
		UE_LOG(LogTemp,Warning,TEXT("end"));
	}
}

void USQLiteMgr::BeginDestroy() {
	Super::BeginDestroy();
	sqlite3_close(this->pSQLite);
}
bool USQLiteMgr::OpenDataBase() {
	const char* path = "H:\\ue4project\\IKUN-main\\Client\\IKUN\\Content\\SQLiteDB\\IKUNDataBase.db";
	if(!FPaths::FileExists(FString(path))) {
		UE_LOG(LogTemp, Warning, TEXT("Data Base Not Exist !!!"));
		return false;
	}
	if(sqlite3_open_v2(path, &(this->pSQLite),SQLITE_OPEN_READONLY,nullptr) != SQLITE_OK) {
		UE_LOG(LogTemp, Warning, TEXT("Open Data Base Failed !!!"));
		return false;
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Open Data Base Succeed !!!"));
		return true;
	}
}