#include <chrono>
#include <iostream>

#include "../Matrix_utility.h"
#include "../Matrix4x4.h"
#include "../Vector4.h"
#include "../Vector3.h"




int main()
{
	math::Vector3 vec3{ 1.0f, 2.0f, 3.0f };
	math::Matrix4x4 mat4
	{
		1.0f, 2.0f, 3.0f, 4.0f,
		1.0f, 2.0f, 3.0f, 4.0f,
		1.0f, 2.0f, 3.0f, 4.0f,
		1.0f, 2.0f, 3.0f, 4.0f
	};

	



	{
		auto now = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < 10000000; i++)
		{
			math::Vector3 Result{ mat4 * vec3 };
		}


		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
	}
}