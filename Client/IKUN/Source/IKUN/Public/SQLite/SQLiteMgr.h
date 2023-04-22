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
class IKUN_API USQLiteMgr : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION()
	virtual void PostInitProperties() override; // 推荐使用，代替构造函数
	virtual void BeginDestroy() override; // 推荐使用，代替析构函数
	// UFUNCTION()
	void GetRowByID(FString relativePath,FString tableName,FString id,
		std::function<ESQLitePreparedStatementExecuteRowResult(const FSQLitePreparedStatement&)>InCallback);
private:
	TSharedPtr<FSQLiteDatabase> sqlite;
};
