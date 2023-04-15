#pragma once
#include "Modules/ModuleManager.h"
// 将模块类公开给其他地方
// 模块主类继承自IModuleInterface接口类，主类和模块共享生命周期

class FIKUNProtosModules : public IModuleInterface {
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};