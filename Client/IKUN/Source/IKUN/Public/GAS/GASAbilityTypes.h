// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "GASAbilityTypes.generated.h"
class UGASTargetType;
// 定义游戏效果、标签和目标信息列表的结构
// 这些容器在蓝图或资产中静态定义，然后在运行时转换为规范
USTRUCT(BlueprintType)
struct FGASGameplayEffectContainer {
	GENERATED_BODY()
public:
	FGASGameplayEffectContainer(){}
	// 设定目标确定的方式
	// todo 缺少UGASTargetType
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffectContainer)
	// TSubclassOf<UGASTargetType> TargetType;
	// 应用于目标的游戏效果列表
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffectContainer)
	TArray<TSubclassOf<UGameplayEffect>> TargetGameplayEffectClasses;
};
// RPGGameplayEffectContainer的“处理”版本，可以传递并可能应用
USTRUCT(BlueprintType)
struct FGASGameplayEffectContainerSpec {
	GENERATED_BODY()
public:
	FGASGameplayEffectContainerSpec(){}
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffectContainer)
	FGameplayAbilityTargetDataHandle TargetData;
	// 应用于目标的GE列表
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffectContainer)
	TArray<FGameplayEffectSpecHandle> TargetGameplayEffectSpecs;
	// 如果有任何有效的效果规格，则返回true
	bool HasValidEffects() const;
	// 如果有任何有效目标，则返回true
	bool HasValidTargets() const;
	// adds new targets to target data
	void AddTargets(const TArray<FHitResult>& HitResults, const TArray<AActor*>& TargetActors);
};
