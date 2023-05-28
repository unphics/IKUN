// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "IKUNAssetFactoryInput.generated.h"

/**
 * 
 */
UCLASS()
class IKUNASSETEDITOR_API UIKUNAssetFactoryInput : public UFactory {
	GENERATED_BODY()
public:
	UIKUNAssetFactoryInput(const FObjectInitializer& ObjectInitializer);
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
		const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
};
