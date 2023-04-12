// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
//#include "../Protos/Public/Test.pb.h"

UMyGameInstance::UMyGameInstance() {
	UE_LOG(LogTemp, Display, TEXT("-------------- Protobuf Test"));
	//csprotos::LoginReq req;
	//req.set_appid(333);
	//req.set_username("qqq");
	//FString str = req.username().c_str();
	//UE_LOG(LogTemp, Display, TEXT("--------- num: %d, str: %s"), req.appid(), *str);

}