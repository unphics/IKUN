#include "3DMath/Vector.h"

void Vector::func() {
	FVector3f a = FVector3f(32.0f,66.2f,180.3f);
	FVector3f b = FVector3f(132.0f,-66.2f,24.3f);
	
	// 向量叉乘 
	auto c1 = a.Cross(b);
	auto c2 = cross(a, b);
	UE_LOG(LogTemp,Warning,TEXT("c1: %f, %f, %f。c2: %f, %f, %f"),c1.X,c1.Y,c1.Z,c2.X,c2.Y,c2.Z);

	// 向量点乘
	auto d1 = a.Dot(b);
	auto d2 = dot1(a,b);
	UE_LOG(LogTemp,Warning,TEXT("d1: %f。d2: %f"),d1,d2);
}

UE::Math::TVector<float> Vector::cross(FVector3f a, FVector3f b) {
	UE::Math::TVector<float> c;
	c.X = a.Y * b.Z - a.Z * b.Y;
	c.Y = a.Z * b.X - a.X * b.Z;
	c.Z = a.X * b.Y - a.Y * b.X;
	return c;
}
float Vector::dot1 (FVector3f a, FVector3f b) {
	return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}

// float dot2 (FVector3f a, FVector3f b) {
// 	return a.Size() * b.Size() * FVector::CosineAngle(a, b);
// }