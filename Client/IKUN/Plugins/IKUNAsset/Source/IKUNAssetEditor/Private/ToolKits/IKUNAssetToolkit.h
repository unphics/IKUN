#pragma once

#include "Toolkits/AssetEditorToolkit.h"

class FIKUNAssetToolkit: public FAssetEditorToolkit {
public:
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& inTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& inTabManager) override;
	void Initialize(class UIKUNAsset* InNewAsset, const EToolkitMode::Type InMode, const TSharedPtr<IToolkitHost>& InToolkitHost);
	virtual FText GetBaseToolkitName() const override;
	virtual FName GetToolkitFName() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
private:
	class UIKUNAsset* ikunAsset;
	TSharedPtr<STextBlock> textBlock;
	TSharedPtr<class IDetailsView> detailsView;
};
