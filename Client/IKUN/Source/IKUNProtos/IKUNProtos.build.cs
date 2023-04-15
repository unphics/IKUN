// ue�ı���ֻ��build��target�й�
// �����ģ��ʹ�������ģ�����ӵ���build������û���õ�Ҳ������ӵ�target��������ַ����ټ�Ҳ���Ƽ�ʹ��
using System;
using UnrealBuildTool;
public class IKUNProtos : ModuleRules {
    public IKUNProtos(ReadOnlyTargetRules Target) : base(Target) {

        //bUsePrecompiled = true;
        //PrecompileForTargets = PrecompileTargetsType.Any;
        //Type = ModuleType.External;

        // core�����˴���ģ����صĴ��룬�������޷�����ģ��
        PrivateDependencyModuleNames.AddRange(new string[] { "Core" , "CoreUObject" , "Engine", "Protobuf" /*"IKUNProtobuf"*/});
        // Ĭ�ϵ������һ��ģ��Ĵ��벢û�й���������ģ�飬Ҫ���ÿһ������ߺ������е���
        // ���뱻����ģ�������ͷ�ļ����ԷŽ�Private�ļ���
        PublicIncludePaths.AddRange(new string[] { "IKUNProtos/Public" });
        PrivateIncludePaths.AddRange(new string[] { "IKUNProtos/Private" });
        bEnableUndefinedIdentifierWarnings = false; // �ر���#ifdef��#ifndef�е�δ��������ľ���
        PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS"); // ����pb��һ�Ѿ���
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
    }
}