#include <chrono>
#include <iostream>

#include "../Matrix4x4.h"
int main()
{
	auto now = std::chrono::high_resolution_clock::now();

	math::Matrix4x4 a{ 1.0f };
	math::Matrix4x4 b{ 2.0f };

	std::cout << __alignof(math::Matrix<4, 4, float>) << std::endl;

	auto c = a * b;

	auto end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
}