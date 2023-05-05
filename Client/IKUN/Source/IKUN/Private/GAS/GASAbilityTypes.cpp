// Fill out your copyright notice in the Description page of Project Settings.

#include "GAS/GASAbilityTypes.h"

bool FGASGameplayEffectContainerSpec::HasValidEffects() const {
	return TargetGameplayEffectSpecs.Num() > 0;
}
bool FGASGameplayEffectContainerSpec::HasValidTargets() const {
	return TargetData.Num() > 0;
}
void FGASGameplayEffectContainerSpec::AddTargets(const TArray<FHitResult>& HitResults,
	const TArray<AActor*>& TargetActors) {
	for(const FHitResult& HitResult : HitResults) {
		// FGameplayAbilityTargetData_SingleTargetHit是用于存储GA目标数据的结构体，用于描述GA所影响的目标对象
		FGameplayAbilityTargetData_SingleTargetHit* NewData = new FGameplayAbilityTargetData_SingleTargetHit(HitResult);
		TargetData.Add(NewData);
	}
	if(TargetActors.Num() > 0) {
		FGameplayAbilityTargetData_ActorArray* NewData = new FGameplayAbilityTargetData_ActorArray();
		NewData->TargetActorArray.Append(TargetActors);
		TargetData.Add(NewData);
	}
}
