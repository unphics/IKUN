// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AbilitySystemComponent.h"
#include "GASAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class IKUN_API UGASAbilitySystemComponent : public UAbilitySystemComponent {
	GENERATED_BODY()
public:
	UGASAbilitySystemComponent();
	// 返回与标记匹配的当前活动能力实例的列表
	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer,
		TArray<UGameplayAbility/*URPGGameplayAbility*/>& ActiveAbilities);
	// 返回用于从角色派生的能力激活的默认级别
	int32 GetDefaultAbilityLevel() const;
	// AbilitySystemGlobals中返回正确类型的函数的版本
	static UGASAbilitySystemComponent* GetAbilitySystemComponentFromActor(const AActor* Actor,
		bool LookForComponent = false);
};
