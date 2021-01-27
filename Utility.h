#pragma once
#include <limits>
#include <algorithm>

#include "LMath_Core.h"

namespace Math
{
	inline constexpr float PI = 3.14159265358979323846f;

	inline constexpr float DegreeToRadian = PI / 180.0f;

	inline constexpr float RadianToDegree = 180.0f / PI;

	

	template<typename T>
	inline constexpr typename std::enable_if_t<CHECK_IS_NUMBER(T), T> Epsilon()
	{
		return std::numeric_limits<T>::epsilon();
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<CHECK_IS_NUMBER(T) && !std::is_unsigned_v<T>, T> Abs(T value)
	{
		return std::abs(value);
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<CHECK_IS_NUMBER(T) && std::is_unsigned_v<T>, T> Abs(T value)
	{
		return value;
	}

	template<typename T>
	inline constexpr auto Acos(T value)
	{
		return std::acos(value);
	}
	template<typename T>
	inline constexpr auto Asin(T value)
	{
		return std::asin(value);
	}
	template<typename T>
	inline constexpr auto Atan(T value)
	{
		return std::atan(value);
	}
	template<typename T>
	inline constexpr auto Atan2(T value1, T value2)
	{
		return std::atan2(value1, value2);
	}

	template<typename T, typename Limit, typename std::enable_if_t<std::is_arithmetic_v<Limit>, bool> = true>
	inline constexpr typename std::enable_if_t<CHECK_IS_NUMBER(T), T> Clamp(T value, Limit min, Limit max)
	{
		if (value < min)
			return min;
		else if (value > max)
			return max;
		return value;
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<CHECK_IS_NUMBER(T), T> Clamp01(T value)
	{
		return Clamp(value, T{ 0 }, T{ 1 });
	}

	template<typename T>
	inline constexpr auto CosInDegree(T degree)
	{
		return std::cos(DegreeToRadin(degree));
	}

	template<typename T>
	inline constexpr auto CosInRadian(T radian)
	{
		return std::cos(radian);
	}


	template<typename T>
	inline constexpr typename std::enable_if_t<CHECK_IS_NUMBER(T), T> Exp(T value)
	{
		return std::exp(value);
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<CHECK_IS_NUMBER(T), T> Infinity()
	{
		return (std::numeric_limits<T>::max)();
	} 

	template<typename T>
	inline constexpr typename std::enable_if_t<CHECK_IS_NUMBER(T), T> NegativeInfinity()
	{
		return std::numeric_limits<T>::lowest();

	}


	template<typename Value, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<Value>, Value> LerpUnClamped(Value value1, Value value2, Floating t)
	{
		return value1 + t * (value2 - value1);
	}

	template<typename Value, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<Value>, Value> Lerp(Value value1, Value value2, Floating t)
	{
		return LerpUnClamped<Value, Floating>(value1, value2, Clamp01<Floating>(t));
	}

	

	template<typename T>
	inline constexpr auto Log(T value)
	{
		return std::log(value);
	}

	template<typename T>
	inline constexpr auto Log10(T value)
	{
		return std::log10(value);
	}

	template<typename X, typename Y>
	inline constexpr auto Max(X x, Y y)
	{
		return (std::max)(x, y);
	}

	template<typename X, typename Y>
	inline constexpr auto Min(X x, Y y)
	{
		return (std::min)(x, y);
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<CHECK_IS_NUMBER(T), T> PerlinNoise(T value);

	template<typename X, typename Y>
	inline constexpr auto Pow(X value, Y exp)
	{
		return std::pow(value, exp);
	}

	template<typename T>
	inline constexpr auto SinInDegree(T degree)
	{
		return std::sin(DegreeToRadin(degree));
	}

	template<typename T>
	inline constexpr auto SinInRadian(T radian)
	{
		return std::sin(radian);
	}


	template<typename T>
	inline constexpr auto Sqrt(T value)
	{
		return std::sqrt(value);
	}


	template<typename T>
	inline constexpr auto TanInDegree(T degree)
	{
		return std::tan(DegreeToRadin(degree));
	}

	template<typename T>
	inline constexpr auto TanInRadian(T radian)
	{
		return std::tan(radian);
	}


}