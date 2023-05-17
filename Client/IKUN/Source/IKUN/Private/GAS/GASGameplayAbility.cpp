// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GASGameplayAbility.h"
#include "GAS/GASCharacterBase.h"
#include "GAS/GASAbilitySystemComponent.h"
#include "GAS/GASTargetType.h"
UGASGameplayAbility::UGASGameplayAbility() {}
FGASGameplayEffectContainerSpec UGASGameplayAbility::MakeEffectContainerSpecFromContainer(
	const FGASGameplayEffectContainer& Container, const FGameplayEventData& EventData, int32 OverrideGameplayLevel) {
	AActor* OwningActor = GetOwningActorFromActorInfo();
	AGASCharacterBase* OwningCharacter = Cast<AGASCharacterBase>(OwningActor);
	UGASAbilitySystemComponent* OwningASC = UGASAbilitySystemComponent::GetAbilitySystemComponentFromActor(OwningActor);
	FGASGameplayEffectContainerSpec ReturnSpec;
	if (OwningASC) {
		// 如果我们有一个目标类型，那么运行目标逻辑。这是可选的，以后可以添加目标
		if (Container.TargetType.Get()) {
			TArray<FHitResult> HitResults;
			TArray<AActor*> TargetActors;
			const UGASTargetType* TargetTypeCDO = Container.TargetType.GetDefaultObject();
			AActor* AvatarActor = GetAvatarActorFromActorInfo();
			TargetTypeCDO->GetTargets(OwningCharacter, AvatarActor, EventData, HitResults, TargetActors);
			ReturnSpec.AddTargets(HitResults, TargetActors);
		}
		// 如果我们没有覆盖级别，请对功能本身使用默认级别
		if (OverrideGameplayLevel == INDEX_NONE) {
			OverrideGameplayLevel = OverrideGameplayLevel = this->GetAbilityLevel(); //OwningASC->GetDefaultAbilityLevel();
		}
		// 为每个应用的效果构建GESpecs
		for (const TSubclassOf<UGameplayEffect>& EffectClass: Container.TargetGameplayEffectClasses) {
			ReturnSpec.TargetGameplayEffectSpecs.Add(MakeOutgoingGameplayEffectSpec(EffectClass, OverrideGameplayLevel));
		}
	}
	return ReturnSpec;
}
FGASGameplayEffectContainerSpec UGASGameplayAbility::MakeEffectContainerSpec(FGameplayTag ContainerTag,
	const FGameplayEventData& EventData, int32 OverrideGameplayLevel) {
	FGASGameplayEffectContainer* FoundContainer = EffectContainerMap.Find(ContainerTag);
	if (FoundContainer){
		return MakeEffectContainerSpecFromContainer(*FoundContainer, EventData, OverrideGameplayLevel);
	}
	return FGASGameplayEffectContainerSpec();
}
TArray<FActiveGameplayEffectHandle> UGASGameplayAbility::ApplyEffectContainerSpec(
	const FGASGameplayEffectContainerSpec& ContainerSpec) {
	TArray<FActiveGameplayEffectHandle> AllEffects;
	// 迭代效果规格列表，并将其应用于目标数据
	for (const FGameplayEffectSpecHandle& SpecHandle : ContainerSpec.TargetGameplayEffectSpecs)
	{
		AllEffects.Append(K2_ApplyGameplayEffectSpecToTarget(SpecHandle, ContainerSpec.TargetData));
	}
	return AllEffects;
}
TArray<FActiveGameplayEffectHandle> UGASGameplayAbility::ApplyEffectContainer(FGameplayTag ContainerTag,
	const FGameplayEventData& EventData, int32 OverrideGameplayLevel) {
	FGASGameplayEffectContainerSpec Spec = MakeEffectContainerSpec(ContainerTag, EventData, OverrideGameplayLevel);
	return ApplyEffectContainerSpec(Spec);
}
