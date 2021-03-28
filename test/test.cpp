#include <chrono>
#include <iostream>

#include "../Matrix_utility.h"
#include "../Matrix4x4.h"
#include "../Vector4.h"
#include "../Vector3.h"


struct AA
{
	alignas(16) int a[10]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
};


int main()
{
	M128F a = M128F_EVERY_BITS_ONE;
	M128F b = M128F_Zero;

	M128F dotPosA45 = _mm_blend_ps(a, b, SHUFFLEMASK(0, 3, 0, 0)); 
	M128F dotPosB45 = _mm_blend_ps(b, a, SHUFFLEMASK(0, 3, 0, 0)); 


// 	alignas(32) bool da[2]{ true, false };
// 	int a{ 0 };
// 
// 	int i = 1;
// 
// 	char result = i | ( i << 1 );
// 	bool abc = (result & 1) << 1;
// 	bool abcd = ( (result & 2) >> 1 ) << 1;
// 	
	
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