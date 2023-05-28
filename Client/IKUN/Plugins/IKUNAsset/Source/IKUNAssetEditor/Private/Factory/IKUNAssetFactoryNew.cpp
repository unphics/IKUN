// Fill out your copyright notice in the Description page of Project Settings.


#include "IKUNAssetFactoryNew.h"
#include "..\..\..\IKUNAsset\Public\IKUNAsset.h"

UIKUNAssetFactoryNew::UIKUNAssetFactoryNew(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer) {
	SupportedClass = UIKUNAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UIKUNAssetFactoryNew::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn) {
	// return Super::FactoryCreateNew(InClass, InParent, InName, Flags, Context, Warn);
	return NewObject<UIKUNAsset>(InParent, InClass, InName, Flags);
}

bool UIKUNAssetFactoryNew::ShouldShowInNewMenu() const {
	return true; // Super::ShouldShowInNewMenu();
}
