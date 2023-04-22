// Copyright Epic Games, Inc. All Rights Reserved.


#include "GameMode/IKUNGameModeBase.h"
#include "SQLiteDatabase.h"
#include "SQLiteResultSet.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
void TestSqliteSupport();
void AIKUNGameModeBase::StartPlay() {
	Super::StartPlay();
	UE_LOG(LogTemp, Display, TEXT("=========== GameModeBase::StartPlay() =========="));
	
	TestSqliteSupport();
}
void TestSqliteSupport() {
	FSQLiteDatabase sqlite;
	FString strDBPath = *FPaths::ProjectContentDir();
	strDBPath+="SQLiteDB";
	FString strPath = FPaths::Combine(*strDBPath, L"IKUNBase.db");
	FString str2 = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()/TEXT("SQLiteDB")/"IKUNDataBase.db");
	if(sqlite.Open(*str2, ESQLiteDatabaseOpenMode::ReadOnly)) {
		UE_LOG(LogTemp,Warning,TEXT("open sqlite data succeed !!!"));
	} else {
		UE_LOG(LogTemp,Warning,TEXT("open sqlite data failed !!!"));
	}
	sqlite.Close();
	


	FString Path = str2; //FPaths::ConvertRelativePathToFull(FPaths::AutomationTransientDir() / TEXT("SQLiteTests") / "SQLiteTest.db");
	// IFileManager::Get().Delete(*Path);
	bool bSuccess = true;
	// 用于读取记录并检查是否为预期记录的实用程序功能。
	auto ReadBackRecordsAndValidateValues = [](FSQLiteDatabase& Db)
	{
		bool bSucceeded = true;

		// 读回记录。
		FString SelectStatement = TEXT("SELECT * FROM users ORDER BY id");
		Db.Execute(*SelectStatement, [&bSucceeded](const FSQLitePreparedStatement& Callback)
		{
			int64 Id;
			FString Name;
			FString Title;
			Callback.GetColumnValueByName(TEXT("id"), Id);
			Callback.GetColumnValueByName(TEXT("name"), Name);
			Callback.GetColumnValueByName(TEXT("title"), Title);

			bSucceeded &= (Id == 1);
			bSucceeded &= (Name == TEXT("John"));
			bSucceeded &= (Title == TEXT("Manager"));

			return ESQLitePreparedStatementExecuteRowResult::Stop;
		});

		return bSucceeded;
	};

	// Exercise very basic SQLite HAL operations (open, close, seek, lock, unlock, etc)
	// 练习非常基本的SQLite HAL操作（打开、关闭、查找、锁定、解锁等）
	{
		FSQLiteDatabase TestDb;
		bSuccess &= TestDb.Open(*Path, ESQLiteDatabaseOpenMode::ReadWriteCreate);

		// Create a table.
		FString Statement = TEXT("CREATE TABLE users (id INTEGER NOT NULL,name TEXT, title TEXT)");
		bSuccess &= TestDb.Execute(*Statement);

		// Insert few records.
		Statement = TEXT("INSERT INTO users (id, name, title) VALUES (1, 'John', 'Manager')");
		bSuccess &= TestDb.Execute(*Statement);
		Statement = TEXT("INSERT INTO users (id, name, title) VALUES (2, 'Mark', 'Engineer')");
		bSuccess &= TestDb.Execute(*Statement);

		// Read back the Records.
		bSuccess &= ReadBackRecordsAndValidateValues(TestDb);
		bSuccess &= TestDb.Close();
	}

	// Check if the database reloads correctly.
	// 检查数据库是否正确重新加载。
	{
		FSQLiteDatabase TestDb;
		bSuccess &= TestDb.Open(*Path, ESQLiteDatabaseOpenMode::ReadWriteCreate);
		bSuccess &= ReadBackRecordsAndValidateValues(TestDb);
		TestDb.Close();
	}
}