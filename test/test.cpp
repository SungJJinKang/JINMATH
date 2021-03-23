#include <chrono>
#include <iostream>

#include "../Matrix4x4.h"
int main()
{
	auto now = std::chrono::high_resolution_clock::now();

	math::Vector4 a{ 1.0f, 2.0f, 3.0f, 4.0f };
	

// 	math::Matrix4x4 a{ math::Vector4(1.0f), math::Vector4(2.0f), math::Vector4(3.0f), math::Vector4(4.0f) };
// 	math::Matrix4x4 b{ math::Vector4(2.0f), math::Vector4(3.0f), math::Vector4(4.0f), math::Vector4(5.0f) };
// 	
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		auto c = a * b;
// 	}

	


	auto end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
}