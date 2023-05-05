// Fill out your copyright notice in the Description page of Project Settings.

#include "GAS/GASAssetManager.h"
#include "GAS/GASItem.h"
#include "AbilitySystemGlobals.h"

const FPrimaryAssetType UGASAssetManager::PotionItemType = TEXT("Potion");
const FPrimaryAssetType UGASAssetManager::SkillItemType = TEXT("Skill");
const FPrimaryAssetType UGASAssetManager::TokenItemType = TEXT("Token");
const FPrimaryAssetType UGASAssetManager::WeaponItemType = TEXT("Weapon");
void UGASAssetManager::StartInitialLoading() {
	Super::StartInitialLoading();
	UAbilitySystemGlobals::Get().InitGlobalData();
}

UGASAssetManager& UGASAssetManager::Get() {
	UGASAssetManager* This = Cast<UGASAssetManager>(GEngine->AssetManager);
	if(This) {
		return *This;
	} else {
		UE_LOG(LogTemp, Fatal, TEXT("Invalid AssetManager in DefaultEngine.ini, must be GASAssetManager!"));
		return *NewObject<UGASAssetManager>();
	}
}
UGASItem* UGASAssetManager::ForceLoadItem(const FPrimaryAssetId& PrimaryAssetId, bool bLogWarning) {
	FSoftObjectPath ItemPath = GetPrimaryAssetPath(PrimaryAssetId);
	// 这会产生同步负载，并可能发生故障
	UGASItem* LoadedItem = Cast<UGASItem>(ItemPath.TryLoad());
	if(bLogWarning && LoadedItem == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Failed to load item for identifier %s"), *PrimaryAssetId.ToString());
	}
	return LoadedItem;
}
