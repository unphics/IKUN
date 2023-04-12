#pragma once
// 要公开某个方法给其他模块使用，需要在方法前添加导出说明符：模块名_API
#include <string>
class Test {
public:
	std::string Say();
};