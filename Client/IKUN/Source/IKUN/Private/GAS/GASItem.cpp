// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GASItem.h"
bool UGASItem::IsConsumable() const {
	if(MaxCount <= 0) {
		return true;
	}
	return false;
}
FString UGASItem::GetIdentifierString() const {
	return GetPrimaryAssetId().ToString();
}

FPrimaryAssetId UGASItem::GetPrimaryAssetId() const {
	// 这是一个数据资产，而不是蓝图，所以我们可以只使用原始FName
	// 对于蓝图，您需要处理剥离_C后缀
	// return Super::GetPrimaryAssetId();
	return FPrimaryAssetId(ItemType, GetFName());
}
