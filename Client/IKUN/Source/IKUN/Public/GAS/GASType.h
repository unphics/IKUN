// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
// 此标头用于类和蓝图在整个游戏中使用的枚举和结构
// 在单个标头中收集这些有助于避免递归标头包含的问题
// 它也是放置数据表行结构之类的东西的好地方
#include "UObject/PrimaryAssetId.h"
#include "GASType.generated.h"

class UGASItem;
class UGASSaveGame;

// 表示项的槽的结构，显示在UI中
USTRUCT(BlueprintType)
struct IKUN_API FGASItemSlot {
	GENERATED_BODY()
public:
	// -1代表无效slot
	FGASItemSlot(): SlotNumber(-1){}
	FGASItemSlot(const FPrimaryAssetType& InItemType, int32 InSlotNumber): ItemType(InItemType),
		SlotNumber(InSlotNumber) {}
	bool operator==(const FGASItemSlot& Other) const;
	bool operator!=(const FGASItemSlot& Other) const;
	// 这是个全局函数，但是有一个条件是必须在类实例化后才可见，这个inline是防止头文件重定义的
	friend inline uint32 GetTypeHash(const FGASItemSlot& Key) {
		uint32 Hash = 0;
		Hash = HashCombine(Hash, GetTypeHash(Key.ItemType));
		Hash = HashCombine(Hash, (uint32)Key.SlotNumber);
		return Hash;
	}
	bool IsValid() const;
public:
	// 可以放入此插槽的item类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FPrimaryAssetType ItemType;
	// The number of this slot, 0 indexed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 SlotNumber;
};

// 玩家库存中URPGItem的额外信息
USTRUCT(BlueprintType)
struct IKUN_API FGASItemData {
	GENERATED_BODY()
public:
	// 构造函数，默认为计数/级别1，因此在蓝图中声明它们将为您提供预期的行为
	FGASItemData(): ItemCount(1), ItemLevel(1) {}
	FGASItemData(int32 InItemCount, int32 InItemLevel): ItemCount(InItemCount),
		ItemLevel(InItemLevel) {}
	bool operator==(const FGASItemData& Other) const;
	bool operator!=(const FGASItemData& Other) const;
	// 如果计数大于0，则返回true
	bool IsValid() const;
	// 附加项目数据，这会添加计数并覆盖其他所有内容
	void UpdateItemData(const FGASItemData& Other, int32 MaxCount, int32 MaxLevel);
public:
	// 库存中此项目的实例数永远不能低于1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 ItemCount;
	// 此项目的级别。此级别为所有实例共享，永远不能低于1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 ItemLevel;
};
