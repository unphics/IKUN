// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GASTargetType.h"
#include "GAS/GASCharacterBase.h"

void UGASTargetType::GetTarget_Implementation(AGASCharacterBase* TargetingCharacter, AActor* TargetingActor,
	FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const {
	return;
}

void UGASTargetType_UseOwner::GetTarget_Implementation(AGASCharacterBase* TargetingCharacter, AActor* TargetingActor,
	FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const {
	Super::GetTarget_Implementation(TargetingCharacter, TargetingActor, EventData, OutHitResults, OutActors);
	OutActors.Add(TargetingCharacter);
}

void UGASTargetType_UseEventData::GetTarget_Implementation(AGASCharacterBase* TargetingCharacter,
	AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults,
	TArray<AActor*>& OutActors) const {
	Super::GetTarget_Implementation(TargetingCharacter, TargetingActor, EventData, OutHitResults, OutActors);
	const FHitResult* FoundHitResult = EventData.ContextHandle.GetHitResult();
	if(FoundHitResult) {
		OutHitResults.Add(*FoundHitResult);
	} else if (EventData.Target) {
		OutActors.Add(const_cast<AActor*>(EventData.Target));
	}
}
