#pragma once

#include "AssetTypeActions_Base.h"

class FIKUNAssetActions : public FAssetTypeActions_Base {
public:
	// 获得分类，content右键的上面属于基础资产，下面属于高级资产，有分类
	virtual uint32 GetCategories() override;
	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual FColor GetTypeColor() const override;
	// 当打开的时候法师什么
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;
};
