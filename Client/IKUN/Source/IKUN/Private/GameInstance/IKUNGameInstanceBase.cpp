#include "GameInstance/IKUNGameInstanceBase.h"
#include "3DMath/Vector.h"

void UIKUNGameInstanceBase::PostInitProperties() {
	UE_LOG(LogTemp,Warning,TEXT("======= GameInstance Init ======="));
	Super::PostInitProperties();

	Vector::func();
}

