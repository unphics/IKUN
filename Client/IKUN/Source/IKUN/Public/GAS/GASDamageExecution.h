// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GASDamageExecution.generated.h"

/**
 * 一种伤害执行，允许通过将原始伤害数与攻击力和防御力相结合来造成伤害
 * 大多数游戏都希望实现多个特定于游戏的执行
 */
UCLASS()
class IKUN_API UGASDamageExecution : public UGameplayEffectExecutionCalculation {
	GENERATED_BODY()
public:
	UGASDamageExecution();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
		FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
