// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GAS/GASAbilityTypes.h"
#include "GASGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class IKUN_API UGASGameplayAbility : public UGameplayAbility {
	GENERATED_BODY()
public:
	UGASGameplayAbility();
	// 游戏标签到游戏效果容器的map
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GameplayEffects)
	TMap<FGameplayTag, FGASGameplayEffectContainer> EffectContainerMap;
	// 使用传入的容器，制作稍后应用的游戏效果容器规范
	// UFUNCTION(BlueprintCallable, CateGory = Ability, meta = (AutoCreateRefTerm = "EventData"))
	
	
};
