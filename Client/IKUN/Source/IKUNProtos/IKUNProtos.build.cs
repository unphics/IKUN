// ue�ı���ֻ��build��target�й�
// �����ģ��ʹ�������ģ�����ӵ���build������û���õ�Ҳ������ӵ�target��������ַ����ټ�Ҳ���Ƽ�ʹ��
using UnrealBuildTool;
public class IKUNProtos : ModuleRules {
    public IKUNProtos(ReadOnlyTargetRules Target) : base(Target) {
        // core�����˴���ģ����صĴ��룬�������޷�����ģ��
        PrivateDependencyModuleNames.AddRange(new string[] { "Core" , "CoreUObject" });
        // Ĭ�ϵ������һ��ģ��Ĵ��벢û�й���������ģ�飬Ҫ���ÿһ������ߺ������е���
        // ���뱻����ģ�������ͷ�ļ����ԷŽ�Private�ļ���
        PublicIncludePaths.AddRange(new string[] { "IKUNProtos/Public" });
        PrivateIncludePaths.AddRange(new string[] { "IKUNProtos/Private" });

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
    }
}