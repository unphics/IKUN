// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "IKUNAsset.generated.h"

/**
 * 
 */
UCLASS()
class IKUNASSET_API UIKUNAsset : public UObject {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = IKUNAsset)
	int32 id;
	UFUNCTION(BlueprintCallable)
	int32 getId();
};
