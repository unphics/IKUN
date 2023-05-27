// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SUserWidget.h"

/**
 * 
 */
class /*TESTEDITORSTANDALONEWINDOW_API*/ SPrefab : public SUserWidget {
public:
	// SLATE_BEGIN_ARGS(SPrefab) {}
	SLATE_USER_ARGS(SPrefab): _Title() {}
	SLATE_ARGUMENT(FText, Title)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	virtual void Construct(const FArguments& InArgs) = 0;


};
