#pragma once
#include "Utility.h"
namespace math
{

	FLOAT32 Pythagorean(FLOAT32 a, FLOAT32 b)
	{
		return std::sqrt(a * a + b * b);
	}
	
	FLOAT32 Pythagorean(FLOAT32 a, FLOAT32 b, FLOAT32 c)
	{
		return std::sqrt(a * a + b * b + c * c);
	}
}