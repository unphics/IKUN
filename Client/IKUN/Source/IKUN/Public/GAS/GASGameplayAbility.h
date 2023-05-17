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
	// 根据给定的GE容器创建GE容器的规范。参数一给定的容器，包含一组GE；参数二传递的游戏事件数据。
	UFUNCTION(BlueprintCallable, CateGory = Ability, meta = (AutoCreateRefTerm = "EventData"))
	virtual FGASGameplayEffectContainerSpec MakeEffectContainerSpecFromContainer(const FGASGameplayEffectContainer& Container,
		const FGameplayEventData& EventData, int32 OverrideGameplayLevel = -1);
	// 从EffectContainerMap中搜索并制作稍后应用的游戏效果容器规范
	UFUNCTION(BlueprintCallable, CateGory = Ability, meta = (AutoCreateRefTerm = "EventData"))
	virtual FGASGameplayEffectContainerSpec MakeEffectContainerSpec(FGameplayTag ContainerTag, const FGameplayEventData& EventData,
		int32 OverrideGameplayLevel = -1);
	// 应用先前创建的游戏效果容器规范
	UFUNCTION(BlueprintCallable, Category = Ability)
	virtual TArray<FActiveGameplayEffectHandle> ApplyEffectContainerSpec(const FGASGameplayEffectContainerSpec& ContainerSpec);
	// 通过创建并应用规范，应用游戏效果容器
	UFUNCTION(BlueprintCallable, CateGory = Ability, meta = (AutoCreateRefTerm = "EventData"))
	virtual TArray<FActiveGameplayEffectHandle> ApplyEffectContainer(FGameplayTag ContainerTag, const FGameplayEventData& EventData,
		int32 OverrideGameplayLevel = -1);
public:
	// 游戏标签到游戏效果容器的map
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GameplayEffects)
	TMap<FGameplayTag, FGASGameplayEffectContainer> EffectContainerMap;
};
