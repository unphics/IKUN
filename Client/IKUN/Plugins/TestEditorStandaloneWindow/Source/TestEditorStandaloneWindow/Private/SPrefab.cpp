#include "..\Public\SPrefab.h"
#include "Widgets/Input/SSlider.h"
#include "SlateOptMacros.h"
#include "Widgets/SUserWidget.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/Input/SCheckBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

class SPrefabImpl : public SPrefab {
private:
	TSharedPtr<class SSlider> Slider;
	TArray<TSharedPtr<class SCheckBox>> CheckBoxes;
	TSharedPtr<class STextBlock> ComboText;
	TArray<TSharedPtr<FString>> Options;
public:
	void Construct(const FArguments& InArgs) {
		int32 BoxId = 0;
		CheckBoxes.SetNum(2);
		if (Options.Num() <= 0) {
			Options.Add(MakeShareable(new FString(TEXT("0"))));
			Options.Add(MakeShareable(new FString(TEXT("1"))));
			Options.Add(MakeShareable(new FString(TEXT("2"))));
		}
		SUserWidget::Construct( SUserWidget::FArguments().HAlign(HAlign_Fill).VAlign(VAlign_Fill)[
			SNew(SGridPanel).FillColumn(0, 1).FillColumn(1, 3).FillRow(0, 1).FillRow(1, 1).FillRow(2, 1).FillRow(3, 1) // 权重定义
			+ SGridPanel::Slot(0, 0).HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(STextBlock).Text(FText::FromString(TEXT("百分比")))]
			+ SGridPanel::Slot(0, 1).HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(STextBlock).Text(FText::FromString(TEXT("二选一")))]
			+ SGridPanel::Slot(0, 2).HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(STextBlock).Text(FText::FromString(TEXT("下拉选项")))]
			+ SGridPanel::Slot(1, 0).HAlign(HAlign_Fill).VAlign(VAlign_Center)[SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().FillWidth(3)[SAssignNew(Slider, SSlider)]
				+ SHorizontalBox::Slot().FillWidth(1).HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(STextBlock).Text_Lambda([this]() {return FText::FromString(FString::SanitizeFloat(Slider.IsValid() ? Slider->GetValue() : 0.f));})] 
			]
			+ SGridPanel::Slot(1, 1).HAlign(HAlign_Fill).VAlign(VAlign_Fill)[SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().FillWidth(1)[SAssignNew(CheckBoxes[0], SCheckBox).IsChecked(ECheckBoxState::Checked).OnCheckStateChanged_Lambda([this](ECheckBoxState newState) {
					switch (newState) {
						case ECheckBoxState::Unchecked: CheckBoxes[0]->SetIsChecked(ECheckBoxState::Checked); break;
						case ECheckBoxState::Checked:
							for(int i = 0; i < CheckBoxes.Num(); ++i) {
								if (i != 0 && CheckBoxes[i].IsValid()) {
									CheckBoxes[i]->SetIsChecked(ECheckBoxState::Unchecked);
								}
							}
						case ECheckBoxState::Undetermined: break;
						default: break;
					}
				})[SNew(STextBlock).Text(FText::FromString(TEXT("选项一")))]]
				+ SHorizontalBox::Slot().FillWidth(1)[SAssignNew(CheckBoxes[1], SCheckBox).IsChecked(ECheckBoxState::Unchecked).OnCheckStateChanged_Lambda([this](ECheckBoxState newState) {
					switch (newState) {
						case ECheckBoxState::Unchecked: CheckBoxes[1]->SetIsChecked(ECheckBoxState::Checked); break;
						case ECheckBoxState::Checked:
							for(int i = 0; i < CheckBoxes.Num(); ++i) {
								if (i != 1 && CheckBoxes[i].IsValid()) {
									CheckBoxes[i]->SetIsChecked(ECheckBoxState::Unchecked);
								}
							}
						case ECheckBoxState::Undetermined: break;
						default: break;
					}
				})[SNew(STextBlock).Text(FText::FromString(TEXT("选项二")))]]
			]
			+ SGridPanel::Slot(1, 2).HAlign(HAlign_Fill).VAlign(VAlign_Center)[SNew(SComboBox<TSharedPtr<FString>>) // 决定下拉的东西的内容而不是东西本身
				.OnGenerateWidget_Lambda([](TSharedPtr<FString> Item){return SNew(STextBlock)/*决定下拉的东西*/.Text(FText::FromString(*Item));})
				.OnSelectionChanged_Lambda([this](TSharedPtr<FString> Item, ESelectInfo::Type type) {
					if (ComboText.IsValid()) {
						ComboText->SetText(FText::FromString(*Item));
					}
				}).OptionsSource(new TArray<TSharedPtr<FString>>({MakeShareable(new FString(TEXT("0"))), MakeShareable(new FString(TEXT("1"))), MakeShareable(new FString(TEXT("2"))),}))
				[SAssignNew(ComboText, STextBlock)]
			]
			+ SGridPanel::Slot(1, 3).HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(SButton)[SNew(STextBlock).Text(FText::FromString(TEXT("确定")))]]
		]);
	}
};
TSharedRef<SPrefab> SPrefab::New() {
	return MakeShareable(new SPrefabImpl());
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
