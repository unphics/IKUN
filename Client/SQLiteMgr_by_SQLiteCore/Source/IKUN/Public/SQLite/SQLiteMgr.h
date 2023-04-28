// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SQLiteDatabase.h"
#include "SQLitePreparedStatement.h"
#include "Templates/Function.h"
#include "SQLiteMgr.generated.h"

/**
 * 
 */
UCLASS()
class IKUN_API USQLiteMgr : public UObject {
	GENERATED_BODY()
public:
	// 通过id获取该行的所有数据
	// UFUNCTION()
	void GetRowByID(FString path,FString tableName,FString id,
		std::function<ESQLitePreparedStatementExecuteRowResult(const FSQLitePreparedStatement&)>InCallback);
	static ANSICHAR* GetByName(const FSQLitePreparedStatement& db, const TCHAR* name, bool & b); // 工具方法
	static ANSICHAR* GetByName(const FSQLitePreparedStatement& db, const TCHAR* name);
	TMap<const TCHAR*, FSQLitePreparedStatement*> arrStatment;
private:
	virtual void PostInitProperties() override; // 推荐使用，代替构造函数
	virtual void BeginDestroy() override; // 推荐使用，代替析构函数
	// TSharedPtr<FSQLiteDatabase> sqlite;
	FSQLiteDatabase* sqlite;
};
