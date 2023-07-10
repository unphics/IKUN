#pragma once

#include "CoreMinimal.h"

struct Gen_Button {
	static void Gen(const FString& nameClass, TMap<FString,FString>& map, TFieldIterator<FProperty>& it) {
		FString get = FString(TEXT("function " + nameClass + "_C: get" + it->GetName() + "()\n \nend\n \n"));
		FString set = FString(TEXT("function " + nameClass + "_C: set" + it->GetName() + "()\n \nend\n \n"));
		map.Add(it->GetName(), get + set);
	}
};

struct Gen_Image {
	static void Gen(const FString& nameClass, TMap<FString,FString>& map, TFieldIterator<FProperty>& it) {
		FString get = FString(TEXT("function " + nameClass + "_C: get" + it->GetName() + "()\n \nend\n \n"));
		FString set = FString(TEXT("function " + nameClass + "_C: set" + it->GetName() + "()\n \nend\n \n"));
		map.Add(it->GetName(), get + set);
	}
};

struct Gen_CanvasPannel {
	static void Gen(const FString& nameClass, TMap<FString,FString>& map, TFieldIterator<FProperty>& it) {
		FString get = FString(TEXT("function " + nameClass + "_C: get" + it->GetName() + "()\n \nend\n \n"));
		FString set = FString(TEXT("function " + nameClass + "_C: set" + it->GetName() + "()\n \nend\n \n"));
		map.Add(it->GetName(), get + set);
	}
};

struct Gen_TextBlock {
	static void Gen(const FString& nameClass, TMap<FString,FString>& map, TFieldIterator<FProperty>& it) {
		FString get = FString(TEXT("function " + nameClass + "_C: get" + it->GetName() + "()\n \nend\n \n"));
		FString set = FString(TEXT("function " + nameClass + "_C: set" + it->GetName() + "()\n \nend\n \n"));
		map.Add(it->GetName(), get + set);
	}
};

struct Gen_ProgressBar {
	static void Gen(const FString& nameClass, TMap<FString,FString>& map, TFieldIterator<FProperty>& it) {
		FString get = FString(TEXT("function " + nameClass + "_C: get" + it->GetName() + "()\n \nend\n \n"));
		FString set = FString(TEXT("function " + nameClass + "_C: set" + it->GetName() + "()\n \nend\n \n"));
		map.Add(it->GetName(), get + set);
	}
};
