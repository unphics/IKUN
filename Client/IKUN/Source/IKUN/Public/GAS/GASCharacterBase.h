// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "GAS/GASItem.h"
#include "GASCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class IKUN_API AGASCharacterBase : public ACharacter, public IAbilitySystemInterface {
	GENERATED_BODY()
public:
	AGASCharacterBase();
	virtual void PossessedBy(AController* NewController) override; // 被新controller控制时调用
    virtual void UnPossessed() override; // 失去controller时调用
    virtual void OnRep_Controller() override; // 当controller发生变化时调用
	// 用于声明需要进行网络同步的属性
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UFUNCTION(BlueprintCallable)
	virtual float GetHealth() const;
	UFUNCTION(BlueprintCallable)
	virtual float GetMaxHealth() const;
	UFUNCTION(BlueprintCallable)
	virtual float GetMana() const;
	UFUNCTION(BlueprintCallable)
	virtual float GetMaxMana() const;
	UFUNCTION(BlueprintCallable)
	virtual float GetMoveSpeed() const;
	UFUNCTION(BlueprintCallable)
	virtual int32 GetCharacterLevel() const;
	// 尝试激活指定物品插槽中的任何功能。如果未找到可激活能力或激活失败，将返回false
	// 如果它认为它已激活，则返回true，但由于稍后的激活失败，它可能会返回误报。
	// 如果bAllowRemoteActivation为true，它将远程激活本地/服务器功能，如果为false，它将仅尝试本地激活该功能
	// todo 缺少ItemSlot
	// UFUNCTION(BlueprintCallable, Category = "Abilities")
	// bool ActiveAbilitiesWithItemSlot(UGASItem Item, bool AllowRemoteActiv = true);
	// 返回绑定到物品槽的活动能力列表，只有当该功能当前在运行时才会返回
	// UFUNCTION(BlueprintCallable, Category = "Abilities")
	// void GetActiveAbilitiesWithItemSlot
};