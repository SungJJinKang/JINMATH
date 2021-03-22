#pragma once

#include "Vector_SIMD.h"

namespace math
{



	template <>
	[[nodiscard]] inline SIMD_CONSTEXPR auto Vector<4, float>::sqrMagnitude() const noexcept
	{
		/*
		Vector<4, float> Result;
	
		XMM128Float(Result) = _mm_mul_ps(XMM128Float(*this), XMM128Float(*this));
		return Result.x + Result.y + Result.z + Result.w;
		*/

		Vector<4, float> Result;
		__m128 a = _mm_load_ps(this->data());
		__m128 result = _mm_mul_ps(a, a);
		_mm_store_ps(const_cast<float*>(Result.data()), result);
		return Result.x + Result.y + Result.z + Result.w;
	}

	/*
	template <>
	[[nodiscard]] inline SIMD_CONSTEXPR auto Vector<4, float>::magnitude() const noexcept
	{
#ifdef L_AVX
		return math::sqrt(sqrMagnitude());
#else
		return math::sqrt(sqrMagnitude());
#endif
		
	}
	*/

	
	template <>
	SIMD_CONSTEXPR void Vector<4, float>::Normalize()
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