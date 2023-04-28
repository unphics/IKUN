// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance/IKUNGameInstanceBase.h"

void UIKUNGameInstanceBase::PostInitProperties() {
	UE_LOG(LogTemp,Warning,TEXT("======= GameInstance Init ======="));
	Super::PostInitProperties();
	// this->SQLiteMgr = NewObject<USQLiteMgr>();
}
