#include <chrono>
#include <iostream>

#include "../Matrix4x4.h"
#include "../Vector4.h"
#include "../Vector3.h"

int main()
{
	math::Matrix4x4 a{ 2.0f };
	math::Vector3 b{ 2.0f };


	{
		auto now = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < 10000000; i++)
		{
			math::Vector3 c = a * b;
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
	}

	
	
}