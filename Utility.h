#pragma once
#include <limits>
#include <algorithm>

#include "LMath_Core.h"

namespace math
{
	inline constexpr float PI = 3.14159265358979323846f;

	inline constexpr float DEGREE_TO_RADIAN = PI / 180.0f;

	inline constexpr float RADIAN_TO_DEGREE = 180.0f / PI;

	

	template<typename T = float, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr typename T epsilon()
	{
		return std::numeric_limits<T>::epsilon();
	}


	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr typename T abs(T value)
	{
		return std::abs(value);
	}

	

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto acos(T value)
	{
		return std::acos(value);
	}
	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto asin(T value)
	{
		return std::asin(value);
	}
	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto atan(T value)
	{
		return std::atan(value);
	}
	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto atan2(T value1, T value2)
	{
		return std::atan2(value1, value2);
	}

	template<typename T, typename Limit, typename std::enable_if_t<std::is_arithmetic_v<Limit>, bool> = true, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr typename T clamp(T value, Limit Min, Limit Max)
	{
		if (value < Min)
			return Min;
		else if (value > Max)
			return Max;
		return value;
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr typename T clamp01(T value)
	{
		return math::clamp(value, T{ 0 }, T{ 1 });
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto cos(T radian)
	{
		return std::cos(radian);
	}


	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr typename T exp(T value)
	{
		return std::exp(value);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr typename T infinity()
	{
		return (std::numeric_limits<T>::max)();
	} 

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr typename T negativeInfinity()
	{
		return std::numeric_limits<T>::lowest();

	}


	template<typename Value, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true, std::enable_if_t<CHECK_IS_NUMBER(Value), bool> = true>
	FORCE_INLINE constexpr typename Floating lerpUnClamped(Value value1, Value value2, Floating t)
	{
		return value1 + t * (value2 - value1);
	}

	template<typename Value, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true, std::enable_if_t<CHECK_IS_NUMBER(Value), bool> = true>
	FORCE_INLINE constexpr typename Floating lerp(Value value1, Value value2, Floating t)
	{
		return lerpUnClamped<Value, Floating>(value1, value2, clamp01<Floating>(t));
	}

	

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto log(T value)
	{
		return std::log(value);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto log10(T value)
	{
		return std::log10(value);
	}

	template<typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	FORCE_INLINE constexpr auto Max(X x, Y y)
	{
		return std::max(x, y);
	}

	template<typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	FORCE_INLINE constexpr auto Min(X x, Y y)
	{
		return std::min(x, y);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr typename T PerlinNoise(T value);

	template<typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	FORCE_INLINE constexpr auto pow(X value, Y exp)
	{
		return std::pow(value, exp);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto sin(T radian)
	{
		return std::sin(radian);
	}


	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto sqrt(T value)
	{
		return std::sqrt(value);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto inverseSqrt(T value)
	{
		return static_cast<T>(1) / std::sqrt(value);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	FORCE_INLINE constexpr auto tan(T radian)
	{
		return std::tan(radian);
	}

	FORCE_INLINE constexpr auto Equal(float a, float b)
	{
		return math::abs(a - b) < math::epsilon<float>();
	}

	FORCE_INLINE constexpr auto Equal(double a, double b)
	{
		return math::abs(a - b) < math::epsilon<double>();
	}

	FORCE_INLINE constexpr auto Equal(float a, double b)
	{
		return Equal(static_cast<double>(a), b);
	}

	FORCE_INLINE constexpr auto Equal(double a, float b)
	{
		return Equal(a, static_cast<double>(b));
	}
	/////



}