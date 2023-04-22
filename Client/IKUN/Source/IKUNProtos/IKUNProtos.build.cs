// ue的编译只与build和target有关
// 如果有模块使用了这个模块就添加到其build里，如果都没有用到也可以添加到target里，但是这种方法少见也不推荐使用
using System;
using System.IO;
using UnrealBuildTool;
public class IKUNProtos : ModuleRules {
    public IKUNProtos(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        //bUsePrecompiled = true;
        //PrecompileForTargets = PrecompileTargetsType.Any;
        //Type = ModuleType.Runtime;

        // core包含了处理模块相关的代码，不包含无法创建模块
        PublicDependencyModuleNames.AddRange(new string[] { "Core" , "CoreUObject" , "Engine", "Protobuf" /*"IKUNProtobuf"*/});
        // 默认的情况下一个模块的代码并没有公开给其他模块，要标记每一个类或者函数进行导出
        // 不想被其他模块包含的头文件可以放进Private文件夹
        // Path.Combine(ModuleDirectory, "include")
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Public") });
        PrivateIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Private") });
        bEnableUndefinedIdentifierWarnings = false; // 关闭由#ifdef、#ifndef中的未定义产生的警告
        PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS"); // 避免pb报一堆警告
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
    }
}