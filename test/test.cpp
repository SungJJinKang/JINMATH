#include <chrono>
#include <iostream>

#include "../Matrix4x4.h"
#include "../Vector4.h"
#include "../Vector3.h"

#include "../../../Graphics/Acceleration/LinearViewFrustumCulling/DataStructure/TransformData.h"


int main()
{
	unsigned int FF{ 0xFFFFFFFF };
	M128F ZERO = M128F_Zero;
	M128F ONE = M128F_EVERY_BITS_ONE;
	math::Vector4 a[8]{};
	for (int i = 0; i < 8; i++)
	{
		a[i].x = i * 4 + 0;
		a[i].y = i * 4 + 1;
		a[i].z = i * 4 + 2;
		a[i].w = i * 4 + 3;
	}

	math::Vector4 b[2]{};
	for (int i = 8; i < 10; i++)
	{
		b[i - 8].x = i * 4 + 0;
		b[i - 8].y = i * 4 + 1;
		b[i - 8].z = i * 4 + 2;
		b[i - 8].w = i * 4 + 3;
	}

	InFrustumSIMDWithTwoPoint(a, b, a[0]);


	{
		auto now = std::chrono::high_resolution_clock::now();

	

		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
	}
	
}