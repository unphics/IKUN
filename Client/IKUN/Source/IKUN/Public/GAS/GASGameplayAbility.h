// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GASGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class IKUN_API UGASGameplayAbility : public UGameplayAbility {
	GENERATED_BODY()
public:
	UGASGameplayAbility();
	// todo 缺少abilityType类型
	// UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GameplayEffects)
	// TMap<FGameplayTag, F>
};
