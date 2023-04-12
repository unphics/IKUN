// ue的编译只与build和target有关
// 如果有模块使用了这个模块就添加到其build里，如果都没有用到也可以添加到target里，但是这种方法少见也不推荐使用
using UnrealBuildTool;
public class IKUNProtos : ModuleRules {
    public IKUNProtos(ReadOnlyTargetRules Target) : base(Target) {
        // core包含了处理模块相关的代码，不包含无法创建模块
        PrivateDependencyModuleNames.AddRange(new string[] { "Core" , "CoreUObject" });
        // 默认的情况下一个模块的代码并没有公开给其他模块，要标记每一个类或者函数进行导出
        // 不想被其他模块包含的头文件可以放进Private文件夹
        PublicIncludePaths.AddRange(new string[] { "IKUNProtos/Public" });
        PrivateIncludePaths.AddRange(new string[] { "IKUNProtos/Private" });

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
    }
}