#include "3DMath/Matrix.h"

FMatrix add(FMatrix a, FMatrix b);
FMatrix multiple(FMatrix a, float b);

void Matrix::func() {
	FMatrix m1;
	m1.M[0][0] = 1.f;
	m1.M[0][1] = 2.f;
	m1.M[1][0] = 3.f;
	m1.M[1][2] = 4.f;
	FMatrix m2;
	m2.M[0][0] = 4.f;
	m2.M[0][1] = 3.f;
	m2.M[1][0] = 2.f;
	m2.M[1][2] = 1.f;

	FMatrix m3 = add(m1, m2);
	FMatrix m4 = m1 + m2;

	FMatrix m5 = multiple(m1, 2.f);
	FMatrix m6 = m1 * 2.f;
}

FMatrix add(FMatrix a, FMatrix b) {
	FMatrix mtx;
	mtx.M[0][0] = a.M[0][0] + b.M[0][0];
	mtx.M[1][0] = a.M[1][0] + b.M[1][0];
	mtx.M[2][0] = a.M[2][0] + b.M[2][0];
	mtx.M[3][0] = a.M[3][0] + b.M[3][0];
	mtx.M[0][1] = a.M[0][1] + b.M[0][1];
	mtx.M[1][1] = a.M[1][1] + b.M[1][1];
	mtx.M[2][1] = a.M[2][1] + b.M[2][1];
	mtx.M[3][1] = a.M[3][1] + b.M[3][1];
	mtx.M[0][2] = a.M[0][2] + b.M[0][2];
	mtx.M[1][2] = a.M[1][2] + b.M[1][2];
	mtx.M[2][2] = a.M[2][2] + b.M[2][2];
	mtx.M[3][2] = a.M[3][2] + b.M[3][2];
	mtx.M[0][3] = a.M[0][3] + b.M[0][3];
	mtx.M[1][3] = a.M[1][3] + b.M[1][3];
	mtx.M[2][3] = a.M[2][3] + b.M[2][3];
	mtx.M[3][3] = a.M[3][3] + b.M[3][3];
	return mtx;
}
FMatrix multiple(FMatrix a, float b) {
	FMatrix mtx;
	mtx.M[0][0] = a.M[0][0] * b;
	mtx.M[1][0] = a.M[1][0] * b;
	mtx.M[2][0] = a.M[2][0] * b;
	mtx.M[3][0] = a.M[3][0] * b;
	mtx.M[0][1] = a.M[0][1] * b;
	mtx.M[1][1] = a.M[1][1] * b;
	mtx.M[2][1] = a.M[2][1] * b;
	mtx.M[3][1] = a.M[3][1] * b;
	mtx.M[0][2] = a.M[0][2] * b;
	mtx.M[1][2] = a.M[1][2] * b;
	mtx.M[2][2] = a.M[2][2] * b;
	mtx.M[3][2] = a.M[3][2] * b;
	mtx.M[0][3] = a.M[0][3] * b;
	mtx.M[1][3] = a.M[1][3] * b;
	mtx.M[2][3] = a.M[2][3] * b;
	mtx.M[3][3] = a.M[3][3] * b;
	return mtx;
}