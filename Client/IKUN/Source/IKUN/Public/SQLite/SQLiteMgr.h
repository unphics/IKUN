// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "sqlite3.h"
#include "SQLiteMgr.generated.h"

/**
 * 
 */
UCLASS()
class IKUN_API USQLiteMgr : public UObject {
	GENERATED_BODY()
public:
	virtual void PostInitProperties() override; // 推荐使用，代替构造函数
	virtual void BeginDestroy() override; // 推荐使用，代替析构函数
	TMap<std::string*, sqlite3_stmt*> mapStmt;
private:
	sqlite3* pSQLite;
	std::vector<std::string> arrTableName;
	bool InitSQliteMgr();
};