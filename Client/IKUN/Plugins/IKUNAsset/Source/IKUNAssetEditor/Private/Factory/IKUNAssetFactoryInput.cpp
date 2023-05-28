#include "IKUNAssetFactoryInput.h"
#include "IKUNAsset\Public\IKUNAsset.h"


#include "Misc/FileHelper.h"


UIKUNAssetFactoryInput::UIKUNAssetFactoryInput(const FObjectInitializer& ObjectInitializer) {
	Formats.Add(FString(TEXT("ikun;"))); // 文件后缀
	SupportedClass = UIKUNAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

UObject* UIKUNAssetFactoryInput::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) {
	// 把文件的内容导入字节数组，然后把字节数组一个个的赋给他的整数值
	UIKUNAsset* newAsset = nullptr;
	TArray<uint8> bytes;
	if (FFileHelper::LoadFileToArray(bytes, *Filename) && bytes.Num() >= sizeof(int32)) {
		newAsset = NewObject<UIKUNAsset>(InParent, InClass, InName, Flags);
		for (uint32 i = 0; i < sizeof(int32); ++i) {
			newAsset->id |= bytes[i] << (i * 8);
		}
	}
	bOutOperationCanceled = false;
	return newAsset;
}
