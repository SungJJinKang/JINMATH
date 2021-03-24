#include <chrono>
#include <iostream>

#include "../Matrix4x4.h"
int main()
{
	math::Matrix4x4 a{ 1.0f, 2.0f, 3.0f, 4.0f, 1.0f, 2.0f, 3.0f, 4.0f, 1.0f, 2.0f, 3.0f, 4.0f, 1.0f, 2.0f, 3.0f, 4.0f };
	math::Matrix4x4 b{ 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f, 17.0f };

	math::Matrix4x4 c{};

	math::Vector4 d{ 1.0f, 2.0f, 3.0f, 4.0f };

	auto now = std::chrono::high_resolution_clock::now();

	
	
	for (int i = 0; i < 1000000; i++)
 	{
		c = a * d;
 	}

	


	auto end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
}