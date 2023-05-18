// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GASDamageExecution.h"
#include "GAS/GASAttributeSet.h"

struct GASDamageStatics {
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);
	GASDamageStatics() {
		// 获取目标的防御能力属性。不要对其进行快照，因为我们希望在应用执行时使用运行状况值。
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, DefensePower, Target, false);
		//获取来源的攻击力。我们确实想在创建GameplayEffectSpec时对此进行快照，以执行damage。
		//（想象一下，我们发射一枚炮弹：当炮弹发射时，我们会创建通用电气规范。当它击中目标时，我们想在此时使用攻击力
		// 炮弹是发射的，而不是击中的时候）。
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, AttackPower, Source, true);
		// 还捕获源的原始伤害，通常通过执行直接传入
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, Damage, Source, true);
	}
};
static const GASDamageStatics& DamageStatics() {
	static GASDamageStatics DmgStatics;
	return DmgStatics;
}
UGASDamageExecution::UGASDamageExecution() {
	RelevantAttributesToCapture.Add(DamageStatics().DefensePowerDef);
	RelevantAttributesToCapture.Add(DamageStatics().AttackPowerDef);
	RelevantAttributesToCapture.Add(DamageStatics().DamageDef);
}
void UGASDamageExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const {
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);
	UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();
	AActor* TargetActor = SourceASC ? SourceASC->GetAvatarActor_Direct() : nullptr;
	AActor* SourceActor = SourceASC ? SourceASC->GetAvatarActor_Direct() : nullptr;
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	// 从源和目标收集标签，因为这会影响应该使用哪些buff
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	// --------------------------------------
	//	Damage Done = Damage * AttackPower / DefensePower
	//	If DefensePower is 0, it is treated as 1.0
	// --------------------------------------

	float DefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DefensePowerDef, EvaluationParameters, DefensePower);
	if (DefensePower == 0.0f) {
		DefensePower = 1.0f;
	}

	float AttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().AttackPowerDef, EvaluationParameters, AttackPower);

	float Damage = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DamageDef, EvaluationParameters, Damage);

	float DamageDone = Damage * AttackPower / DefensePower;
	if (DamageDone > 0.f){
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageProperty, EGameplayModOp::Additive, DamageDone));
	}
}
