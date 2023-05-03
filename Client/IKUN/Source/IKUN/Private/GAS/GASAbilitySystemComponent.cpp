// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GASAbilitySystemComponent.h"
UGASAbilitySystemComponent::UGASAbilitySystemComponent() {}

void UGASAbilitySystemComponent::GetActiveAbilitiesWithTags(
	const FGameplayTagContainer& GameplayTagContainer, TArray<UGameplayAbility>& ActiveAbilities) {
	TArray<FGameplayAbilitySpec*> AbilitiesToActive;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(GameplayTagContainer, AbilitiesToActive,
		false);
	
}

int32 UGASAbilitySystemComponent::GetDefaultAbilityLevel() const {}

UGASAbilitySystemComponent* UGASAbilitySystemComponent::GetAbilitySystemComponentFromActor(const AActor* Actor,
	bool LookForComponent) {}
