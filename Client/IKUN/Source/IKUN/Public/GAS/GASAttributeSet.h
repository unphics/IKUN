// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GASAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class IKUN_API UGASAttributeSet : public UAttributeSet {
	GENERATED_BODY()
public:
	UGASAttributeSet();
	// 属性值发生改变前被调用，可以检查属性值是否超出范围，如果超出则将属性值限制在合理范内，或在修改属性值时触发一些游戏事件。
	// 该函数的参数包括要修改的属性和修改后的属性值，通过修改“NewValue”参数对属性值进行限制、验证或修改。
	virtual void PreAttributeChange(const FGameplayAttribute& Attr, float& NewValue) override;
	// 用于在游戏效果GE执行后进行额外的操作。该函数的参数包括GE的相关信息如类型、持续时间、来源等等。
	// 重写函数时可以根据Data参数中的信息进行特定的逻辑处理例如根据属性值的变化更新UI显示或触发一些游戏性事件。
	// 此函数在GE执行后被调用，因此可以在函数中取到GE对属性值的影响，并对GE的结果进行处理。
	// 同时，由于这个函数不会对属性值进行修改，因此可以安全地进行复杂的逻辑处理，而不会对属性值产生副作用
	// 另外，此函数在客户端与服务端上都会被调用，因此在编写逻辑时要考虑到网络同步和安全性问题
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	// 用于定义哪些属性需要在网络上同步。该函数的参数是一个数组，可以添加属性来保存需要同步的属性信息。
	// 每个属性都通过CONDITION参数来指定何时需要同步例如仅客户端、仅服务端和都要同步。
	// 此外还可以使用NOTIFY参数来指定当属性值
	// 在GetLifttimeReplicatedProps中可以使用DOREPLIFETIME_CONDITION_NOTIFY宏来定义属性的同步方式和条件
	// 此函数是在服务器和客户端上都会被调用，因此需要确保同步的属性和同步方式符合网络同步的要求，以避免出现不必要的问题。
	// 同时，在使用DOREPLIFETIME_CONDITION_NOTIFY宏时，也需要注意避免出现死循环等问题，以保证程序的稳定性和安全性。
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
protected:
	// 用于处理当一个属性值的最大值发生改变时，该属性如何调整。该函数的参数包括受影响的属性、最大属性值、新的最大属性值、受影响属性的名词
	// 调用时该函数会根据最大属性值和新的最大值的比例来调整受影响的属性值以确保受影响的属性值在新的最大范围内。例如：50/100=>100/200
	// 需要注意的是，此函数只是一个辅助函数，不能直接用于修改属性值。如果需要在修改属性值时处理属性值的最大值，可以在重写PreAttributeChange函数时进行处理，或者使用GameplayEffect中的AttributeClamp来实现。	
	void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttr/*受影响的属性*/,
		const FGameplayAttributeData& MaxAttr,float NewMaxValue,
		const FGameplayAttribute& AffectedAttrProp);
public:
	// ReplicatedUsing = OnRep_Health 强制委托，当Health被修改时调用OnRep_Health
	// ATTRIBUTE_ACCESSORS 访问器宏，
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Health)
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxHealth)
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Mana)
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxMana)
	/**攻击者的攻击力乘以基础伤害以减少生命值，因此1.0意味着没有奖励*/
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_AttackPower)
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AttackPower)
	/**基础伤害除以防御能力以获得实际伤害，因此1.0意味着没有额外奖励*/
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_DefensePower)
	FGameplayAttributeData DefensePower;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, DefensePower)
	UPROPERTY(BlueprintReadOnly, Category = "MoveSpeed", ReplicatedUsing = OnRep_MoveSpeed)
	FGameplayAttributeData MoveSpeed;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MoveSpeed)
	/**Damage是DamageExecution用来计算最终伤害的“临时”属性，然后转化为-健康*/
	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Damage)
protected:
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	virtual void OnRep_AttackPower(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	virtual void OnRep_DefensePower(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	virtual void OnRep_MoveSpeed(const FGameplayAttributeData& OldValue);
};
