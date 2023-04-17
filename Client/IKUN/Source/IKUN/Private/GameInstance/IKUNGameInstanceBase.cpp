// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance/IKUNGameInstanceBase.h"

UIKUNGameInstanceBase::UIKUNGameInstanceBase() {
	UE_LOG(LogTemp, Display, TEXT("========== GameIns Constructor =========="));
	
}



/*
#include "Test.pb.h"
UIKUNGameInstanceBase::UIKUNGameInstanceBase() {
	UE_LOG(LogTemp, Display, TEXT("========== GameIns Constructor =========="));
	this->PBMgr = CreateDefaultSubobject<UPBMgr>(TEXT("PBMgr"));

}
UPBMgr* UIKUNGameInstanceBase::GetPBMgr() {
	return this->PBMgr;
}
*/