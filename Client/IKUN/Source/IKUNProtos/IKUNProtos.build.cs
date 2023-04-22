// ue�ı���ֻ��build��target�й�
// �����ģ��ʹ�������ģ�����ӵ���build������û���õ�Ҳ������ӵ�target��������ַ����ټ�Ҳ���Ƽ�ʹ��
using System;
using System.IO;
using UnrealBuildTool;
public class IKUNProtos : ModuleRules {
    public IKUNProtos(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        //bUsePrecompiled = true;
        //PrecompileForTargets = PrecompileTargetsType.Any;
        //Type = ModuleType.Runtime;

        // core�����˴���ģ����صĴ��룬�������޷�����ģ��
        PublicDependencyModuleNames.AddRange(new string[] { "Core" , "CoreUObject" , "Engine", "Protobuf" /*"IKUNProtobuf"*/});
        // Ĭ�ϵ������һ��ģ��Ĵ��벢û�й���������ģ�飬Ҫ���ÿһ������ߺ������е���
        // ���뱻����ģ�������ͷ�ļ����ԷŽ�Private�ļ���
        // Path.Combine(ModuleDirectory, "include")
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Public") });
        PrivateIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Private") });
        bEnableUndefinedIdentifierWarnings = false; // �ر���#ifdef��#ifndef�е�δ��������ľ���
        PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS"); // ����pb��һ�Ѿ���
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
    }
}