// Fill out your copyright notice in the Description page of Project Settings.


#include "Prefab.h"
#include "Widgets/Input/SSlider.h"
#include "SlateOptMacros.h"
#include "Widgets/SUserWidget.h"
#include "Widgets/Layout/SGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SPrefab::Construct(const FArguments& InArgs) {
	int32 BoxId = 0;
	CheckedBoxes.SetNum(2);
	SPrefab::Construct(
		SUserWidget::FArguments().HAlign(HAlign_Fill).VAlign(VAlign_Fill)
		[
			SNew(SGridPanel).FillColumn(0,1).FillColumn(1,3)
			.FillRow(0,1).FillRow(1,1).FillRow(2,1).FillRow(3,1)
			+ SGridPanel::Slot(0,0).HAlign(HAlign_Center).VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(FText::FromString(TEXT("百分比")))
			]
			+ SGridPanel::Slot(0,1).HAlign(HAlign_Center).VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(FText::FromString(TEXT("二选一")))
			]
			+ SGridPanel::Slot(0,2).HAlign(HAlign_Center).VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(FText::FromString(TEXT("下拉选项")))
			]
			+ SGridPanel::Slot(0,3).HAlign(HAlign_Center).VAlign(VAlign_Center)
			[
				SNew(STextBlock).Text(FText::FromString(TEXT("百分比")))
			]
			+ SGridPanel::Slot(1,0).HAlign(HAlign_Fill).VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().FillWidth(3)
				[
					SAssignNew(Slider,SSlider)
				]
				+ SHorizontalBox::Slot().FillWidth(1)
				[
					SNew(STextBlock).Text_Lambda([this]() {
						return FText::FromString(FString::SanitizeFloat(Slider.IsValid() ? Slider->GetValue() : 0.f));
					})
				]
			]
			+ SGridPanel::Slot(1,1).HAlign(HAlign_Fill).VAlign(VAlign_Fill)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().FillWidth(1)
				[
					SAssignNew(CheckedBoxes[0], SCheckBox).IsChecked(true).OnCheckStateChanged(FOnCheckStateChanged::CreateLambda([this](ECheckBoxState newState) {
						switch (newState) {
							
						}
					}))
				]
			]
		]
	)
}
TSharedRef<SPrefab> SPrefab::New() {
	return MakeShareable(new SPrefab());
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
