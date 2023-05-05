// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GASTargetType.generated.h"

// class AGASCharacterBase;

/*用于确定GA目标的类
它是用来运行目标逻辑的蓝图
这并不是GameplayAbilityTargetactor的子类，因为这个类从未被实例化到世界中
这可以作为游戏特定目标蓝图的基础
如果你的目标更复杂，你可能需要在world里实例化一次，或者作为一个集合的actor*/
UCLASS(Blueprintable, meta = (ShowWorldContextPin))
class IKUN_API UGASTargetType : public UObject {
	GENERATED_BODY()
public:
	UGASTargetType() {}
	// 调用以确定要应用游戏效果的目标
	// UFUNCTION(BlueprintNativeEvent)
	// void GetTarget(AGASCharacterBase* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData,
	// 	TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const;
};
/* Trivial target type that uses the owner */
UCLASS()
class IKUN_API UGASTargetType_UseOwner : public UGASTargetType {
	GENERATED_BODY()
public:
	UGASTargetType_UseOwner(){}
	// 使用传入的事件数据
	// virtual void GetTarget_Implementation(AGASCharacterBase* TargetingCharacter, AActor* TargetingActor,
	// 	FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const override;
};
/* Trivial target type that pulls the target out of the event data*/
UCLASS(NotBlueprintable)
class IKUN_API UGASTargetType_UseEventData : public UGASTargetType {
	GENERATED_BODY()
public:
	// virtual void GetTarget_Implementation(AGASCharacterBase* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const override;
};
