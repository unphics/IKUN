// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS\GASAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectTypes.h"
#include "GameplayEffectExtension.h" // 包含Data.EffectSpec.GetContext()
#include "GameFramework/Character.h"
/*
#include "Abilities/RPGAttributeSet.h"
#include "Abilities/RPGAbilitySystemComponent.h"
#include "RPGCharacterBase.h"
*/
UGASAttributeSet::UGASAttributeSet(): Health(1.f), MaxHealth(1.f), Mana(0.f),
	MaxMana(0.f), AttackPower(1.f), DefensePower(1.f), MoveSpeed(1.f),
	Damage(0.f) {}
void UGASAttributeSet::PreAttributeChange(const FGameplayAttribute& Attr, float& NewValue) {
	/* 这是在属性发生变化时调用的，因此对于最大生命值/法力值，我们希望缩放当前总数以匹配*/
	Super::PreAttributeChange(Attr, NewValue);
	if(Attr == GetMaxHealthAttribute()) {
		AdjustAttributeForMaxChange(Health, MaxHealth, NewValue,
			GetHealthAttribute());
	} else if (Attr == GetMaxManaAttribute()) {
		AdjustAttributeForMaxChange(Mana, MaxMana, NewValue,
			GetMaxManaAttribute());
	}
}
void UGASAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) {
	Super::PostGameplayEffectExecute(Data);
	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext(); // 获取GE的上下文
	UAbilitySystemComponent* SourceASC = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();
	/* 计算新旧之间的增量（如果可用）*/
	float DeltaValue = 0;
	// 检查当前的GE是否是加法类型，如果是加法则EvaluatedData.Magnitude表示修改的值，否则代表修改的百分比。
	// 当前PostGameplayEffectExecute函数只是暂存了DeltaValue的值，并没有立即对属性进行更改，因为POSTGEExecute是
	// 在GE执行之后，如果在中国函数里直接修改属性的值，会导致新的修改又被重新应用到当前的GE上从而导致属性值错误，
	// 因此在PostGEExecute中只暂存，在PreAttributeChange函数中再对属性进行更改
	if(Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive) {
		
		DeltaValue = Data.EvaluatedData.Magnitude; //如果这是加法，则存储稍后传递的原始delta值
	}
	//获取目标演员，该演员应该是我们的所有者
	AActor* TargetActor = nullptr;
	AController* TargetController = nullptr;
	ACharacter* TargetCharacter = nullptr; // ARPGCharacterBase* TargetCharacter = nullptr;
	if(Data.Target.AbilityActorInfo.IsValid()/*判断GE的目标角色信息有效*/ &&
		Data.Target.AbilityActorInfo->AvatarActor.IsValid()) {
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<ACharacter>(TargetActor); // TargetCharacter = Cast<ARPGCharacterBase>(TargetActor);
	}
	if(Data.EvaluatedData.Attribute == GetDamageAttribute()) {
		// 获取来源的actor
		AActor* SourceActor = nullptr;
		AController* SourceController = nullptr;
		ACharacter* SourceCharacter = nullptr; // ARPGCharacterBase* SourceCharacter = nullptr;
		if(SourceASC && SourceASC->AbilityActorInfo.IsValid() && SourceASC->AbilityActorInfo->AvatarActor.IsValid()) {
			SourceActor = SourceASC->AbilityActorInfo->AvatarActor.Get();
			SourceController = SourceASC->AbilityActorInfo->PlayerController.Get();
			if(SourceController == nullptr && SourceActor != nullptr) {
				if(APawn* Pawn = Cast<APawn>(SourceActor)) {
					SourceController = Pawn->GetController();
				}
			}
			// 使用controller寻找来源的pawn
			if(SourceController) {
				SourceCharacter	 = Cast<ACharacter>(SourceController->GetPawn()); // ARPGCharacterBase
			} else {
				SourceCharacter = Cast<ACharacter>(SourceActor);
			}
			// 如果已设置，则根据上下文设置sourceActor
			if(Context.GetEffectCauser()) {
				SourceActor = Context.GetEffectCauser();
			}
		}
		// 尝试提取命中结果
		FHitResult HitResult;
		if(Context.GetHitResult()) {
			HitResult = *Context.GetHitResult();
		}
		// 存储所造成伤害的本地副本，并清除伤害属性
		const float LocalDamageDone = GetDamage();
		SetDamage(0.f);
		if(LocalDamageDone > 0) {
			// 应用health变化，然后钳制他
			const float	OldHealth = GetHealth();
			SetHealth(FMath::Clamp(OldHealth - LocalDamageDone, 0.f, GetMaxHealth()));
			if(TargetCharacter) {
				// this is proper damage 适当的伤害
				// TargetCharacter->HandleDamage(LocalDamageDone, HitResult, SourceTags, SourceCharacter, SourceActor);
				// 调用所有health change
				// TargetCharacter->HandleHealthChanged(-LocalDamageDone, SourceTags);
			}
		}
	} else if (Data.EvaluatedData.Attribute == GetHealthAttribute()) {
		// 处理其他健康变化，如治疗或直接修改
		// 首先钳制他们
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
		if(TargetCharacter) {
			// 调用所有health change
			// TargetCharacter->HandleHealthChanged(DeltaValue, SourceTags);
		}
	} else if (Data.EvaluatedData.Attribute == GetManaAttribute()) {
		// 钳制mana
		SetMana(FMath::Clamp(GetMana(), 0.f,GetMaxMana()));
		if(TargetCharacter) {
			// 调用所有mana change
			// TargetCharacter->HandleManaChanged(DeltaValue, SourceTags);
		}
	} else if (Data.EvaluatedData.Attribute == GetMoveSpeedAttribute()) {
		if(TargetCharacter) {
			// TargetCharacter->HandleMoveSpeedChanged(DeltaValue, SourceTags);
		}
	}
}
void UGASAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	// 使用DOREPLIFETIME宏为AttributeSet中的属性生成默认的同步代码，以便在网络游戏中进行网络同步，默认为当属性变化后就会被同步
	DOREPLIFETIME(UGASAttributeSet, Health);
	DOREPLIFETIME(UGASAttributeSet, MaxHealth);
	DOREPLIFETIME(UGASAttributeSet, Mana);
	DOREPLIFETIME(UGASAttributeSet, MaxMana);
	DOREPLIFETIME(UGASAttributeSet, AttackPower);
	DOREPLIFETIME(UGASAttributeSet, DefensePower);
	DOREPLIFETIME(UGASAttributeSet, Damage);
}
void UGASAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttr/*受影响的属性*/,
	const FGameplayAttributeData& MaxAttr,float NewMaxValue,
	const FGameplayAttribute& AffectedAttrProp) {
	UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();
	const float CurMaxValue = MaxAttr.GetCurrentValue();
	if(!FMath::IsNearlyEqual(CurMaxValue,NewMaxValue) && ASC) { // 判断当前最大值和新的最大值相等
		const float CurValue = AffectedAttr.GetCurrentValue(); // 获取受影响属性的最大值
		// 计算出要变化的值
		float NewDelta = (CurMaxValue > 0.f) ? (CurValue * NewMaxValue / CurMaxValue) - CurValue : NewMaxValue; 
		// 将要变化的值应用到受影响属性上。
		// ApplyModToAttributeUnsafe可以直接修改属性的值而不需要使用GE，这个函数通常用于处理属性值的变化
		ASC->ApplyModToAttributeUnsafe(AffectedAttrProp, EGameplayModOp::Additive, NewDelta);
	}
}
void UGASAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue) {
	// GAMEPLAYATTRIBUTE_REPNOTIFY宏用于在属性同步时触发属性值的更新，在GAS的OnRep_中使用来触发属性值的更新
	// 第一个参数是当前类名，第二个参数是要同步的属性名称，第三个参数是同步前的属性(可选)
	// 需要注意的是GAMEPLAYATTRIBUTE_REPNOTIFY宏会自动调用PostGameplayEffectExecute进行属性值更新，因此调用这个宏时通常不需要手动更新
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Health, OldValue);
}
void UGASAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxHealth, OldValue);
}
void UGASAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldValue) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Mana, OldValue);
}
void UGASAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldValue) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxMana, OldValue);
}
void UGASAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldValue) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AttackPower, OldValue);
}
void UGASAttributeSet::OnRep_DefensePower(const FGameplayAttributeData& OldValue) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, DefensePower, OldValue);
}
void UGASAttributeSet::OnRep_MoveSpeed(const FGameplayAttributeData& OldValue) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MoveSpeed, OldValue);
}
