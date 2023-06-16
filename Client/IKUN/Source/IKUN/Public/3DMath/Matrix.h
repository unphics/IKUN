#pragma once

class Matrix{
public:
	static void func();

	static FMatrix add(FMatrix a, FMatrix b);
	static FMatrix cross(FMatrix a, float b);
	static FMatrix dot(FMatrix a, FMatrix b);
	static FMatrix transpose(FMatrix a); // 转置
	static FMatrix getUnit();
};
