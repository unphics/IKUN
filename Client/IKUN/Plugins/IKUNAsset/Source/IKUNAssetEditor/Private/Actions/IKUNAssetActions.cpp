#include "IKUNAssetActions.h"
#include "IKUNAsset.h"
#include "Toolkits/IKUNAssetToolkit.h"

uint32 FIKUNAssetActions::GetCategories() {
	return EAssetTypeCategories::Basic;
}
FText FIKUNAssetActions::GetName() const {
	return FText::FromString(GetSupportedClass()->GetName());
}
UClass* FIKUNAssetActions::GetSupportedClass() const {
	return UIKUNAsset::StaticClass();
}
FColor FIKUNAssetActions::GetTypeColor() const {
	return FColor::Red;
}

void FIKUNAssetActions::OpenAssetEditor(const TArray<UObject*>& InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor) {
	// FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
	EToolkitMode::Type mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;
	// 循环当前选择的多个资源，如果能转成ikunasset就初始化，传到自定义的编辑器里面
	for (auto obj = InObjects.CreateConstIterator(); obj; ++obj) {
		auto newAsset = Cast<UIKUNAsset>(*obj);
		if (newAsset) {
			TSharedRef<FIKUNAssetToolkit> editorToolkit = MakeShareable(new FIKUNAssetToolkit());
			editorToolkit->Initialize(newAsset, mode, EditWithinLevelEditor);
		}
	}
}
