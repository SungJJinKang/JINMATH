#pragma once

#include "Vector_SIMD.h"

namespace math
{



	/*
	template <>
	[[nodiscard]] inline constexpr auto Vector<4, float>::magnitude() const noexcept
	{
#ifdef L_AVX
		return math::sqrt(sqrMagnitude());
#else
		return math::sqrt(sqrMagnitude());
#endif
		
	}
	*/

	
	template <>
	constexpr void Vector<4, float>::Normalize()
	{
#ifdef L_AVX
		auto mag = magnitude();
		if (mag > math::epsilon<float>())
		{
			x = static_cast<value_type>(x / mag);
			y = static_cast<value_type>(y / mag);
			z = static_cast<value_type>(z / mag);
			w = static_cast<value_type>(w / mag);
		}
#else
		auto mag = magnitude();
		if (mag > math::epsilon<float>())
		{
			x = static_cast<value_type>(x / mag);
			y = static_cast<value_type>(y / mag);
			z = static_cast<value_type>(z / mag);
			w = static_cast<value_type>(w / mag);
		}
#endif
		
	}
	
}