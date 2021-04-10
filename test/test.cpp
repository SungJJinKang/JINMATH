#include <chrono>
#include <iostream>


#include "../Matrix_utility.h"
#include "../Matrix4x4.h"
#include "../Vector4.h"
#include "../Vector3.h"

#include "../Quaternion.h"





int main()
{
// 	math::Vector3 vec3{ 1.0f, 2.0f, 3.0f };
// 	math::Matrix4x4 mat4
// 	{
// 		1.0f, 2.0f, 3.0f, 4.0f,
// 		1.0f, 2.0f, 3.0f, 4.0f,
// 		1.0f, 2.0f, 3.0f, 4.0f,
// 		1.0f, 2.0f, 3.0f, 4.0f
// 	};
// 
// 	M128F A{ 1.0f, 2.0f, 3.0f, 4.0f };
	math::Vector4 kk1{ 1.0f };
	math::Vector4 kk2{ 3.0f };

	math::Quaternion a{ 1.0f, 2.0f, 3.0f, 4.0f };

	{
		auto now = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < 100000000; i++)
		{
			math::Vector4 result{ kk1 + kk2 };
		}


		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
	}

	/*
	{
		auto now = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < 100000000; i++)
		{
			float dot = math::dot_SIMD(kk1, kk2);
		}


		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
	}
	*/
}