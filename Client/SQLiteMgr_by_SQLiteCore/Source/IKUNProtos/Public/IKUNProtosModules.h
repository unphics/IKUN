#pragma once
#include "Modules/ModuleManager.h"
// ��ģ���๫���������ط�
// ģ������̳���IModuleInterface�ӿ��࣬�����ģ�鹲����������

class FIKUNProtosModules : public IModuleInterface {
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};