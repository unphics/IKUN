// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UObject/Object.h"
#include "IKUNAssetFactoryNew.generated.h"

/**
 * 
 */
UCLASS()
class IKUNASSETEDITOR_API UIKUNAssetFactoryNew : public UFactory {
	GENERATED_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
		UObject* Context, FFeedbackContext* Warn) override;
	// 是否出现在新建菜单里
	virtual bool ShouldShowInNewMenu() const override;
};
