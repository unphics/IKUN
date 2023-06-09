﻿#include "MVVMTemplateGen.h"
#include "Blueprint/UserWidget.h"
#include "Containers/StringConv.h"
#include "Misc/FileHelper.h"
#include "WidgetParseInclude.h"

void MVVMTemplateGen::Gen() {
	FString pathUMGDir = FPaths::Combine(*FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()), TEXT("/UI/BP/"));
	UE_LOG(LogTemp, Log, TEXT("获取content目录: %s"), *pathUMGDir)
	MVVMTemplateGen::LoadUMGAssets(pathUMGDir, "");
}

void MVVMTemplateGen::LoadUMGAssets(FString pathBase, FString pathAdd) {
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();
	file.IterateDirectory(*(pathBase + pathAdd), [&](const TCHAR* FilenameOrDirectory, bool bIsDirectory) -> bool {
		// FilenameOrDirectory 大致为 D:/UnrealProject/IKUN/Client/IKUN/Content//UI/BP/UMG_Login.uasset
		UE_LOG(LogTemp, Log, TEXT("递归UMG目录: %s"), FilenameOrDirectory)
		TArray<FString> arrStr;
		FString str = FString(FilenameOrDirectory);
		str = str.Replace(TEXT("//"), TEXT("/")); // 将所有“//”替换为“/”
		// 处理后得到 D:/UnrealProject/IKUN/Client/IKUN/Content/UI/BP/UMG_Login.uasset

		int32 idxDot = -1;
		// 注意容易出错，我家里的ue这里的FilenameOrDirectory是绝对路径，公司的是相对路径，换引擎时注意调试一遍
		str.FindLastChar('.', idxDot);
		FString st = idxDot > 0 ? str.LeftChop(str.Len() - idxDot) : str;

		UE_LOG(LogTemp, Error, TEXT("st: %s"), *st)
		
		st.ParseIntoArray(arrStr, TEXT("/"), true); // 将字符串按照“/”切分
		// 分割后 'D:' 'UnrealProject' 'IKUN' 'Client' 'IKUN' 'Content' 'UI' 'BP' 'UMG_Login'
		UE_LOG(LogTemp, Log, TEXT("目录处理: %s"), *str)
		for (FString i : arrStr) {
			UE_LOG(LogTemp, Error, TEXT("分割: %s"), *i)
		}
		
		auto arr = arrStr;
		auto i = arr[arr.Num() - 1];
		if (bIsDirectory) {
			FString path = pathAdd + TEXT("/") + i + TEXT("/");
			UE_LOG(LogTemp, Error, TEXT("next: %s"), *path)
			LoadUMGAssets(pathBase.Replace(TEXT("//"), TEXT("/")), path);
		} else {
			if (i.StartsWith(TEXT("UMG_"))) { // 检查是否以xxx开头
				auto h = st.Replace(*FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()), TEXT(""));
				auto a = TEXT("WidgetBlueprint'/Game/") + h +TEXT(".") + i + TEXT("_C'"); // "WidgetBlueprint'/Game/UI/BP/UMG_Login.UMG_Login_C'"

				UE_LOG(LogTemp, Error, TEXT("read file: %s"), *a)
				MVVMTemplateGen::ReadUMG(a, h, i);// WidgetBlueprint'/Game/UI/BP/Task/UMG_TaskList.UMG_TaskList'
			}
		}
		return true;
	});
}

void MVVMTemplateGen::ReadUMG(FString refUAsset, FString pathGen, FString nameClass) {
	UClass* bp = LoadClass<UUserWidget>(nullptr, *refUAsset);

	// 使用map方便按条目标记处理
	TMap<FString,FString> map;
	map.Add(TEXT("require"),TEXT("require \"UnLua\"\n \n"));
	map.Add(TEXT("local"), TEXT("local " + nameClass + "_C = UnLuaClass('UI.Base.ViewModeBase')\n"));
	map.Add(TEXT("mgr"), TEXT("local UIManager = require(\"../UIManager\")\n \n"));
	map.Add(TEXT("construct"), TEXT("function " + nameClass + "_C: Construct()\n \nend\n \n"));
	
	for(TFieldIterator<FProperty> it(bp); it; ++it) {
		// UE_LOG(LogTemp, Warning, TEXT("property: %s, %s, %s, %s"), *(it->GetName()), *(it->GetFName().ToString()), *(it->GetCPPType()), *(it->GetClass()->GetName()));
		// switch-case要求编译期求值故使用else-if
		if (it->GetCPPType().Contains("Button")) {
			Gen_Button::Gen(nameClass, map, it);
		} else if (it->GetCPPType().Contains("Image")) {
			Gen_Image::Gen(nameClass, map, it);
		} else if (it->GetCPPType().Contains("CanvasPannel")) {
			Gen_CanvasPannel::Gen(nameClass, map, it);
		} else if (it->GetCPPType().Contains("TextBlock")) {
			Gen_TextBlock::Gen(nameClass, map, it);
		} else if (it->GetCPPType().Contains("ProgressBar")) {
			Gen_ProgressBar::Gen(nameClass, map, it);
		}
	}
	map.Add(TEXT("return"), TEXT("return " + nameClass + "_C"));

	// 生成目录
	FString dir = FString(FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()) + TEXT("LuaScript/") + pathGen + TEXT("_VM.lua"));

	FString ret;
	for (TTuple<FString, FString> i : map) {
		ret.Append(i.Value);
	}
	
	// 打印生成内容
	UE_LOG(LogTemp, Warning, TEXT("generate file: \n%s"), *ret)
	
	// 文件生成
	if (FFileHelper::SaveStringToFile(ret, *dir)) {
		UE_LOG(LogTemp, Log, TEXT("MVVMTemplateGen_Succeed: %s"), *dir)
	} else {
		UE_LOG(LogTemp, Warning, TEXT("MVVMTemplateGen_Failed: %s"), *dir)
	}
}

#undef __VT_GEN_DEBUG_LOG__