#pragma once
#include "Utility.h"
namespace math
{

	float Pythagorean(float a, float b)
	{
		return math::sqrt(a * a + b * b);
	}
	
	float Pythagorean(float a, float b, float c)
	{
		return math::sqrt(a * a + b * b + c * c);
	}
}