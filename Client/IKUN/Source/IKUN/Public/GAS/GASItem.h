#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "GAS/GASGameplayAbility.h"
#include "GASItem.generated.h"

UCLASS(Abstract, BlueprintType)
class IKUN_API UGASItem : public UPrimaryDataAsset {
	GENERATED_BODY()
public:
	UGASItem(): Price(0), MaxCount(1), MaxLevel(1), AbilityLevel(1) {}
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Max)
	bool IsConsumable() const; // 消耗品
	UFUNCTION(BlueprintCallable, Category = Item)
	FString GetIdentifierString() const;
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
	FPrimaryAssetType ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	FText ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	FText ItemDesc;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	FSlateBrush ItemIcon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	int32 Price;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Max)
	int32 MaxCount;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Max)
	int32 MaxLevel;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	TSubclassOf<UGASGameplayAbility> GrantedAbility; // 授予技能
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	int32 AbilityLevel;
};
