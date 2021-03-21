#include <chrono>
#include <iostream>

#include "../Vector4.h"
int main()
{
	auto now = std::chrono::high_resolution_clock::now();

	math::Vector4 a{ 4 };

	auto end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - now).count() << std::endl;
}