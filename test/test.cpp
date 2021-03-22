#include <chrono>
#include <iostream>

#include "../Vector4.h"
int main()
{
	auto now = std::chrono::high_resolution_clock::now();

	math::Vector4 a{ 4.0f, 3.0f, 2.0f, 1.0f };
	for (int i = 0; i < 10000; i++)
	{
		auto mag = a.sqrMagnitude();
	}


	auto end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
}