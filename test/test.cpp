#include <chrono>
#include <iostream>

#include "../Matrix_utility.h"
#include "../Matrix4x4.h"
#include "../Vector4.h"
#include "../Vector3.h"

#include "../../../Graphics/Acceleration/LinearData_ViewFrustumCulling/DataStructure/EntityBlock.h"

struct AA
{
	alignas(16) int a[10]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
};


int main()
{
	int a{ ~0 };
	AA k ;
	std::cout << sizeof(doom::graphics::EntityBlock) << std::endl;
	constexpr math::Matrix4x4 mvpMatrix{ };
	//mvpMatrix = math::translate(math::Vector3(1.0f)) * math::rotate(45.0f, math::Vector3(2.0f)) * math::scale(math::Vector3(4.0f));

	math::Vector4 plane[8]{};

	alignas(32) bool da[100];
	
	{
		auto now = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < 100000; i++)
		{
			//math::ExtractPlanesFromMVPMatrixForSIMD(mvpMatrix, false, plane);
		}


		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
	}
	/*
	{
		auto now = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < 100000; i++)
		{
			math::ExtractPlanesFromMVPMatrixForSIMDVer2(mvpMatrix, false, plane);
		}
	

		auto end = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - now).count() << std::endl;
	}
	*/
}