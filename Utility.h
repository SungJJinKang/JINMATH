#pragma once

#include <limits>
#include <cmath>
#include <type_traits>

namespace Math
{
	template<typename T>
	constexpr typename std::enable_if_t<std::is_floating_point_v<T>, T> PI = T(3.14159265358979323846);

	template<typename T>
	constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> DegreeToRadinFomula = PI<T> / T(180);

	template<typename T>
	constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> RadinToDegreeFomula = T(180) / PI<T>;

	template<typename T>
	inline constexpr  typename std::enable_if_t<std::is_arithmetic_v<T>, T> DegreeToRadin(T degree)
	{
		return degree * DegreeToRadinFomula<T>;
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> RadinToDegree(T radian)
	{
		return radian * RadinToDegreeFomula<T>;
	}

	template<typename T>
	inline constexpr inline typename std::enable_if_t<std::is_arithmetic_v<T>, T> Epsilon()
	{
		return std::numeric_limits<T>::epsilon();
	}

	template<typename T>
	inline constexpr inline typename std::enable_if_t<std::is_arithmetic_v<T> && !std::is_unsigned_v<T>, T> Abs(T value)
	{
		return std::abs(value);
	}

	template<typename T>
	inline constexpr inline typename std::enable_if_t<std::is_arithmetic_v<T> && std::is_unsigned_v<T>, T> Abs(T value)
	{
		return value;
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> Acos(T value)
	{
		return std::acos(value);
	}
	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> Asin(T value)
	{
		return std::asin(value);
	}
	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> Atan(T value)
	{
		return std::atan(value);
	}
	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> Atan2(T value1, T value2)
	{
		return std::atan2(value1, value2);
	}

	template<typename T, typename Limit, typename std::enable_if_t<std::is_arithmetic_v<Limit>, bool> = true>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> Clamp(T value, Limit min, Limit max)
	{
		if (value < min)
			return min;
		else if (value > max)
			return max;
		return value;
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> Clamp01(T value)
	{
		return Clamp(value, 0, 1);
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> CosInDegree(T degree)
	{
		return std::cos(DegreeToRadin(degree));
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> CosInRadian(T radian)
	{
		return std::cos(radian);
	}


	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> Exp(T value)
	{
		return std::exp(value);
	}

	template<typename T>
	constexpr T Infinity = std::numeric_limits<T>::max();

	template<typename T>
	constexpr T NegativeInfinity = std::numeric_limits<T>::lowest();


	template<typename Value, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<Value>, Value> LerpUnClamped(Value value1, Value value2, Floating t)
	{
		return value1 + t(value2 - value1);
	}

	template<typename Value, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<Value>, Value> Lerp(Value value1, Value value2, Floating t)
	{
		return Clamp01<Value>(LerpUnClamped(value1, value2, t));
	}

	

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> Log(T value)
	{
		return std::log(value);
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> Log10(T value)
	{
		return std::log10(value);
	}

	template<typename T, typename std::enable_if_t<std::is_arithmetic_v<T>> = true>
	inline constexpr T Max(T x, T y)
	{
		return x > y ? x : y;
	}

	template<typename T, typename std::enable_if_t<std::is_arithmetic_v<T>> = true>
	inline constexpr T Min(T x, T y)
	{
		return x < y ? x : y;
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> PerlinNoise(T value);

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>&& std::is_floating_point_v<T>, T> Pow(T value, T exp)
	{
		return std::pow(value, exp);
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T> && !std::is_floating_point_v<T>, double> Pow(T value, T exp)
	{
		return std::pow(value, exp);
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> SinInDegree(T degree)
	{
		return std::sin(DegreeToRadin(degree));
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> SinInRadian(T radian)
	{
		return std::sin(radian);
	}


	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>&& std::is_floating_point_v<T>, T> Sqrt(T value)
	{
		return std::sqrt(value);
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>&& !std::is_floating_point_v<T>, double> Sqrt(T value)
	{
		return std::sqrt(value);
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> TanInDegree(T degree)
	{
		return std::tan(DegreeToRadin(degree));
	}

	template<typename T>
	inline constexpr typename std::enable_if_t<std::is_arithmetic_v<T>, T> TanInRadian(T radian)
	{
		return std::tan(radian);
	}


}