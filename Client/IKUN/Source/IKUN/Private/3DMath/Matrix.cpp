#include "3DMath/Matrix.h"

void Matrix::func() {
	FMatrix m1;
	m1.M[0][0] = 1.f; m1.M[0][1] = 2.f;
	m1.M[1][0] = 3.f; m1.M[1][2] = 4.f;
	FMatrix m2;
	m2.M[0][0] = 4.f; m2.M[0][1] = 3.f;
	m2.M[1][0] = 2.f; m2.M[1][2] = 1.f;

	FMatrix m3 = add(m1, m2);
	FMatrix m4 = m1 + m2;

	FMatrix m5 = cross(m1, 2.f);
	FMatrix m6 = m1 * 2.f;

	FMatrix m7 = dot(m1, m2);
	FMatrix m8 = m1 * m2;

	FMatrix m9 = transpose(m1);
	FMatrix m10 = m1.GetTransposed();
}

FMatrix Matrix::add(FMatrix a, FMatrix b) {
	FMatrix mtx;
	mtx.M[0][0]=a.M[0][0]+b.M[0][0]; mtx.M[1][0]=a.M[1][0]+b.M[1][0]; mtx.M[2][0]=a.M[2][0]+b.M[2][0]; mtx.M[3][0]=a.M[3][0]+b.M[3][0];
	mtx.M[0][1]=a.M[0][1]+b.M[0][1]; mtx.M[1][1]=a.M[1][1]+b.M[1][1]; mtx.M[2][1]=a.M[2][1]+b.M[2][1]; mtx.M[3][1]=a.M[3][1]+b.M[3][1];
	mtx.M[0][2]=a.M[0][2]+b.M[0][2]; mtx.M[1][2]=a.M[1][2]+b.M[1][2]; mtx.M[2][2]=a.M[2][2]+b.M[2][2]; mtx.M[3][2]=a.M[3][2]+b.M[3][2];
	mtx.M[0][3]=a.M[0][3]+b.M[0][3]; mtx.M[1][3]=a.M[1][3]+b.M[1][3]; mtx.M[2][3]=a.M[2][3]+b.M[2][3]; mtx.M[3][3]=a.M[3][3]+b.M[3][3];
	return mtx;
}
FMatrix Matrix::cross(FMatrix a, float b) {
	FMatrix mtx;
	mtx.M[0][0] = a.M[0][0]*b; mtx.M[1][0] = a.M[1][0]*b; mtx.M[2][0] = a.M[2][0]*b; mtx.M[3][0] = a.M[3][0]*b;
	mtx.M[0][1] = a.M[0][1]*b; mtx.M[1][1] = a.M[1][1]*b; mtx.M[2][1] = a.M[2][1]*b; mtx.M[3][1] = a.M[3][1]*b;
	mtx.M[0][2] = a.M[0][2]*b; mtx.M[1][2] = a.M[1][2]*b; mtx.M[2][2] = a.M[2][2]*b; mtx.M[3][2] = a.M[3][2]*b;
	mtx.M[0][3] = a.M[0][3]*b; mtx.M[1][3] = a.M[1][3]*b; mtx.M[2][3] = a.M[2][3]*b; mtx.M[3][3] = a.M[3][3]*b;
	return mtx;
}
FMatrix Matrix::dot(FMatrix a, FMatrix b) {
	// 需保证a的列数等于b的行数
	FMatrix mtx;
	mtx.M[0][0] = a.M[0][0] * b.M[0][0] + a.M[0][1] * b.M[1][0] + a.M[0][2] * b.M[2][0] + a.M[0][3] * b.M[3][0];
	mtx.M[1][0] = a.M[1][0] * b.M[0][0] + a.M[1][1] * b.M[1][0] + a.M[1][2] * b.M[2][0] + a.M[1][3] * b.M[3][0];
	mtx.M[2][0] = a.M[2][0] * b.M[0][0] + a.M[2][1] * b.M[1][0] + a.M[2][2] * b.M[2][0] + a.M[2][3] * b.M[3][0];
	mtx.M[3][0] = a.M[3][0] * b.M[0][0] + a.M[3][1] * b.M[1][0] + a.M[3][2] * b.M[2][0] + a.M[3][3] * b.M[3][0];
	mtx.M[0][1] = a.M[0][0] * b.M[0][1] + a.M[0][1] * b.M[1][1] + a.M[0][2] * b.M[2][1] + a.M[0][3] * b.M[3][1];
	mtx.M[1][1] = a.M[1][0] * b.M[0][1] + a.M[1][1] * b.M[1][1] + a.M[1][2] * b.M[2][1] + a.M[1][3] * b.M[3][1];
	mtx.M[2][1] = a.M[2][0] * b.M[0][1] + a.M[2][1] * b.M[1][1] + a.M[2][2] * b.M[2][1] + a.M[2][3] * b.M[3][1];
	mtx.M[3][1] = a.M[3][0] * b.M[0][1] + a.M[3][1] * b.M[1][1] + a.M[3][2] * b.M[2][1] + a.M[3][3] * b.M[3][1];
	mtx.M[0][2] = a.M[0][0] * b.M[0][2] + a.M[0][1] * b.M[1][2] + a.M[0][2] * b.M[2][2] + a.M[0][3] * b.M[3][2];
	mtx.M[1][2] = a.M[1][0] * b.M[0][2] + a.M[1][1] * b.M[1][2] + a.M[1][2] * b.M[2][2] + a.M[1][3] * b.M[3][2];
	mtx.M[2][2] = a.M[2][0] * b.M[0][2] + a.M[2][1] * b.M[1][2] + a.M[2][2] * b.M[2][2] + a.M[2][3] * b.M[3][2];
	mtx.M[3][2] = a.M[3][0] * b.M[0][2] + a.M[3][1] * b.M[1][2] + a.M[3][2] * b.M[2][2] + a.M[3][3] * b.M[3][2];
	mtx.M[0][3] = a.M[0][0] * b.M[0][3] + a.M[0][1] * b.M[1][3] + a.M[0][2] * b.M[2][3] + a.M[0][3] * b.M[3][3];
	mtx.M[1][3] = a.M[1][0] * b.M[0][3] + a.M[1][1] * b.M[1][3] + a.M[1][2] * b.M[2][3] + a.M[1][3] * b.M[3][3];
	mtx.M[2][3] = a.M[2][0] * b.M[0][3] + a.M[2][1] * b.M[1][3] + a.M[2][2] * b.M[2][3] + a.M[2][3] * b.M[3][3];
	mtx.M[3][3] = a.M[3][0] * b.M[0][3] + a.M[3][1] * b.M[1][3] + a.M[3][2] * b.M[2][3] + a.M[3][3] * b.M[3][3];
	return mtx;
}

FMatrix Matrix::transpose(FMatrix a) {
	FMatrix mtx;
	mtx.M[0][0] = a.M[0][0]; mtx.M[1][0] = a.M[0][1]; mtx.M[2][0] = a.M[0][2]; mtx.M[3][0] = a.M[0][3];
	mtx.M[0][1] = a.M[1][0]; mtx.M[1][1] = a.M[1][1]; mtx.M[2][1] = a.M[1][2]; mtx.M[3][1] = a.M[1][3];
	mtx.M[0][2] = a.M[2][0]; mtx.M[1][2] = a.M[2][1]; mtx.M[2][2] = a.M[2][2]; mtx.M[3][2] = a.M[2][3];
	mtx.M[0][3] = a.M[3][0]; mtx.M[1][3] = a.M[3][1]; mtx.M[2][3] = a.M[3][2]; mtx.M[3][3] = a.M[3][3];
	return mtx;
}

FMatrix Matrix::getUnit() {
	FMatrix mtx;
	mtx.M[0][0] = 1; mtx.M[1][0] = 0; mtx.M[2][0] = 0; mtx.M[3][0] = 0;
	mtx.M[0][1] = 0; mtx.M[1][1] = 1; mtx.M[2][1] = 0; mtx.M[3][1] = 0;
	mtx.M[0][2] = 0; mtx.M[1][2] = 0; mtx.M[2][2] = 1; mtx.M[3][2] = 0;
	mtx.M[0][3] = 0; mtx.M[1][3] = 0; mtx.M[2][3] = 0; mtx.M[3][3] = 1;
	return mtx;
}
