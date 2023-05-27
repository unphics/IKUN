// Fill out your copyright notice in the Description page of Project Settings.


#include "IKUNAssetFactoryNew.h"
UIKUNAssetFactoryNew::UIKUNAssetFactoryNew(const FObjectInitializer) {
	
}

UObject* UIKUNAssetFactoryNew::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn) {
	return Super::FactoryCreateNew(InClass, InParent, InName, Flags, Context, Warn);
}

bool UIKUNAssetFactoryNew::ShouldShowInNewMenu() const {
	return Super::ShouldShowInNewMenu();
}
