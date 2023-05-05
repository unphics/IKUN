// Fill out your copyright notice in the Description page of Project Settings.

#include "GAS/GASAbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "GameFramework/Character.h"

UGASAbilitySystemComponent::UGASAbilitySystemComponent() {}
void UGASAbilitySystemComponent::GetActiveAbilitiesWithTags(
	const FGameplayTagContainer& GameplayTagContainer, TArray<UGameplayAbility*>& ActiveAbilities) {
	TArray<FGameplayAbilitySpec*> AbilitiesToActive;
	// 通过匹配标签获取可激活的GA列表。第一个参数表示谢意匹配的标签契合，第二个参数表示函数输出的结果，第三个参数表示知否只查找已激活的GA
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(GameplayTagContainer, AbilitiesToActive,
		false);
	for(FGameplayAbilitySpec* Spec : AbilitiesToActive) {
		TArray<UGameplayAbility*> AbilityInstances = Spec->GetAbilityInstances();
		for(UGameplayAbility* ActiveAbility : AbilityInstances) {
			ActiveAbilities.Add(ActiveAbility/*Cast<URPGGameplayAbility>(ActiveAbility)*/);
		}
	}
}
int32 UGASAbilitySystemComponent::GetDefaultAbilityLevel() const {
	ACharacter*/*ARPGCharacterBase**/OwningCharacter = Cast<ACharacter>(GetOwnerActor());
	if(OwningCharacter) {
		return 1; // OwningCharacter->GetCharacterLevel();
	}
	return 1;
}
UGASAbilitySystemComponent* UGASAbilitySystemComponent::GetAbilitySystemComponentFromActor(const AActor* Actor,
	bool LookForComponent) {
	return  Cast<UGASAbilitySystemComponent>(UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor,
		LookForComponent));
}
