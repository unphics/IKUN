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
