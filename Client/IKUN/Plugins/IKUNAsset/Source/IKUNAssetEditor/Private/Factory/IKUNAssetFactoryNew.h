// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UObject/Object.h"
#include "IKUNAssetFactoryNew.generated.h"

/**
 * 从4.25.1开始，如果要新资源出现在content的右键创建菜单中，必须为他注册IAssetTypeActions对象
 */
UCLASS()
class IKUNASSETEDITOR_API UIKUNAssetFactoryNew : public UFactory {
	GENERATED_BODY()
public:
	UIKUNAssetFactoryNew(const FObjectInitializer& ObjectInitializer);
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
		UObject* Context, FFeedbackContext* Warn) override;
	// 是否出现在新建菜单里
	virtual bool ShouldShowInNewMenu() const override;
};
