#pragma once
#include <limits>

#include "LMath_Core.h"

namespace math
{
	inline FLOAT32 PI = 3.14159265358979323846f;

	inline FLOAT32 DEGREE_TO_RADIAN = PI / 180.0f;

	inline FLOAT32 RADIAN_TO_DEGREE = 180.0f / PI;

	

	template<typename T = FLOAT32, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE typename T epsilon()
	{
		return std::numeric_limits<T>::epsilon();
	}


	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE typename T abs(T value)
	{
		return std::abs(value);
	}

	

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto acos(T value)
	{
		return std::acos(value);
	}
	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto asin(T value)
	{
		return std::asin(value);
	}
	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto atan(T value)
	{
		return std::atan(value);
	}
	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto atan2(T value1, T value2)
	{
		return std::atan2(value1, value2);
	}

	template<typename T, typename Limit, typename std::enable_if_t<std::is_arithmetic_v<Limit>, bool> = true, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE typename T clamp(T value, Limit Min, Limit Max)
	{
		if (value < Min)
			return Min;
		else if (value > Max)
			return Max;
		return value;
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE typename T clamp01(T value)
	{
		return math::clamp(value, T{ 0 }, T{ 1 });
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto cos(T radian)
	{
		return std::cos(radian);
	}


	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE typename T exp(T value)
	{
		return std::exp(value);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE typename T infinity()
	{
		return (std::numeric_limits<T>::max)();
	} 

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE typename T negativeInfinity()
	{
		return std::numeric_limits<T>::lowest();

	}


	template<typename Value, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true, std::enable_if_t<CHECK_IS_NUMBER(Value), bool> = true>
	FORCE_INLINE typename Floating lerpUnClamped(Value value1, Value value2, Floating t)
	{
		return value1 + t * (value2 - value1);
	}

	template<typename Value, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true, std::enable_if_t<CHECK_IS_NUMBER(Value), bool> = true>
	FORCE_INLINE typename Floating lerp(Value value1, Value value2, Floating t)
	{
		return lerpUnClamped<Value, Floating>(value1, value2, clamp01<Floating>(t));
	}

	

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto log(T value)
	{
		return std::log(value);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto log10(T value)
	{
		return std::log10(value);
	}

	template<typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	FORCE_INLINE auto Max(X x, Y y)
	{
		return x > y ? x : y;
	}

	template<typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	FORCE_INLINE auto Min(X x, Y y)
	{
		return x < y ? x : y;
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE typename T PerlinNoise(T value);

	template<typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	FORCE_INLINE auto pow(X value, Y exp)
	{
		return std::pow(value, exp);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto sin(T radian)
	{
		return std::sin(radian);
	}


	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto sqrt(T value)
	{
		return std::sqrt(value);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto inverseSqrt(T value)
	{
		return static_cast<T>(1) / std::sqrt(value);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE auto tan(T radian)
	{
		return std::tan(radian);
	}

	FORCE_INLINE auto Equal(FLOAT32 a, FLOAT32 b)
	{
		return math::abs(a - b) < math::epsilon<FLOAT32>();
	}

	FORCE_INLINE auto Equal(FLOAT64 a, FLOAT64 b)
	{
		return math::abs(a - b) < math::epsilon<FLOAT64>();
	}

	FORCE_INLINE auto Equal(FLOAT32 a, FLOAT64 b)
	{
		return Equal(static_cast<FLOAT64>(a), b);
	}

	FORCE_INLINE auto Equal(FLOAT64 a, FLOAT32 b)
	{
		return Equal(a, static_cast<FLOAT64>(b));
	}
	/////



}