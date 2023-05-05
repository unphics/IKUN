// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "GASAssetManager.generated.h"

class UGASItem;
/**
 * 
 */
UCLASS()
class IKUN_API UGASAssetManager : public UAssetManager {
	GENERATED_BODY()
public:
	UGASAssetManager(){}
	virtual void StartInitialLoading() override;
	static UGASAssetManager& Get();
	// 同步加载RPGItem子类，这可能会出现问题，但在无法等待异步加载时很有用
	// 这不会维护对该项的引用，因此如果不以其他方式加载，它将进行垃圾收集
	// 第一个参数是要加载的资产标识符
	// 显示警告如果为true，则在项目加载失败时将记录警告
	UGASItem* ForceLoadItem(const FPrimaryAssetId& PrimaryAssetId, bool bLogWarning = true);
public:
	static const FPrimaryAssetType PotionItemType;
	static const FPrimaryAssetType SkillItemType;
	static const FPrimaryAssetType TokenItemType;
	static const FPrimaryAssetType WeaponItemType;
};