#pragma once

class Vector {
public:
	static void func();
	static UE::Math::TVector<float> cross(FVector3f a, FVector3f b);
	static float dot1 (FVector3f a, FVector3f b);
	static float dot2 (FVector3f a, FVector3f b);
};
