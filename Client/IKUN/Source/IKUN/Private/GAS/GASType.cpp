#include "GAS/GASType.h"

bool FGASItemSlot::operator==(const FGASItemSlot& Other) const {
	return ItemType == Other.ItemType && SlotNumber == Other.SlotNumber;
}
bool FGASItemSlot::operator!=(const FGASItemSlot& Other) const {
	return !(*this == Other);
}
bool FGASItemSlot::IsValid() const {
	return ItemType.IsValid() && SlotNumber >= 0;
}

bool FGASItemData::operator==(const FGASItemData& Other) const {
	return ItemCount == Other.ItemCount && ItemLevel == Other.ItemLevel;
}
bool FGASItemData::operator!=(const FGASItemData& Other) const {
	return !(*this == Other);
}
bool FGASItemData::IsValid() const {
	return ItemCount > 0;
}
void FGASItemData::UpdateItemData(const FGASItemData& Other, int32 MaxCount, int32 MaxLevel) {
	if(MaxCount <= 0) {
		MaxCount = MAX_int32;
	}
	if(MaxLevel <= 0) {
		MaxLevel = MAX_int32;
	}
	ItemCount = FMath::Clamp(ItemCount + Other.ItemCount, 1, MaxCount);
	ItemLevel = FMath::Clamp(Other.ItemLevel, 1, MaxLevel);
}

// 库存项目更改时调用的代理
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemChanged, bool, bAdded, UGASItem*, Item);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnInventoryChangedNative, bool, UGASItem*);
// 库存槽的内容发生更改时调用了代理
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FonSlottedItemChanged, FGASItemSlot, ItemSlot, UGASItem*, Item);
DECLARE_MULTICAST_DELEGATE_TwoParams(FonSlottedItemChangedNative, FGASItemSlot, UGASItem*);
// 当整个库存已加载，所有项目可能已被替换时，会调用代理
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryLoaded);
DECLARE_MULTICAST_DELEGATE(FOnInventoryLoadedNative);
// 保存游戏加载/重置后调用的代理
// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSaveGameLoaded, UGASsavegame*, savegame)
// DECLARE_MULTICAST_DELEGATE_OneParam(FOnSaveGameLoadedNative, UGASsavegame*)