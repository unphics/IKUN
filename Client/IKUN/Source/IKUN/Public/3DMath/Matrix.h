#pragma once

class Matrix{
public:
	static void func();

	static FMatrix add(FMatrix a, FMatrix b);
	static FMatrix cross(FMatrix a, float b);
	static FMatrix dot(FMatrix a, FMatrix b);
	static FMatrix transpose(FMatrix a); // 转置
	static FMatrix getUnit();
	// 矩阵没有除法，但是有除法的逆运算（限定正方形矩阵）
	static FMatrix inverse();
};
