// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class /*TESTEDITORSTANDALONEWINDOW_API*/ SPrefab : public SCompoundWidget {
public:
	// SLATE_BEGIN_ARGS(SPrefab) {}
	SLATE_USER_ARGS(SPrefab){}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
private:
	TSharedPtr<class SSlider> Slider;
	TArray<TSharedPtr<class SCheckedBox>> CheckedBoxes;
	TSharedPtr<class STextBlock> ComboText;
};
