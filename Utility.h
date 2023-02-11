#pragma once
#include "JINMATHCore.h"

#include <limits>

namespace math
{
	extern FLOAT64 PI;
	extern FLOAT64 DEGREE_TO_RADIAN;
	extern FLOAT64 RADIAN_TO_DEGREE;

	template <typename T>
	JINMATH_NO_DISCARD inline T epsilon()
	{
		static_assert(std::is_same_v<T, FLOAT32> || std::is_same_v<T, FLOAT64>);

		return std::numeric_limits<T>::epsilon();
	}

	
	JINMATH_NO_DISCARD inline FLOAT32 epsilon_FLOAT32()
	{
		return std::numeric_limits<FLOAT32>::epsilon();
	}
	
	JINMATH_NO_DISCARD inline FLOAT64 epsilon_FLOAT64()
	{
		return std::numeric_limits<FLOAT64>::epsilon();
	}

	/*template<typename T>
	JINMATH_NO_DISCARD inline typename T abs(T value)
	{
		return std::abs(value);
	}*/

	

	template<typename T>
	JINMATH_NO_DISCARD inline auto acos(T value)
	{
		return std::acos(value);
	}
	template<typename T>
	JINMATH_NO_DISCARD inline auto asin(T value)
	{
		return std::asin(value);
	}
	template<typename T>
	JINMATH_NO_DISCARD inline auto atan(T value)
	{
		return std::atan(value);
	}
	template<typename T>
	JINMATH_NO_DISCARD inline auto atan2(T value1, T value2)
	{
		return std::atan2(value1, value2);
	}

	template<typename X>
	JINMATH_NO_DISCARD inline X Abs(const X x)
	{
		return (x > (X)0) ? x : -x;
	}

	template<typename X>
	JINMATH_NO_DISCARD inline X Max(const X x, const  X y)
	{
		return (x > y) ? x : y;
	}

	template<typename X>
	JINMATH_NO_DISCARD inline X Min(const X x, const  X y)
	{
		return (x < y) ? x : y;
	}

	template<typename T, typename Limit>
	JINMATH_NO_DISCARD inline T clamp(T value, Limit minVal, Limit maxVal)
	{
		return math::Min(math::Max(value, minVal), maxVal);
	}

	template<typename T>
	JINMATH_NO_DISCARD inline T clamp01(T value)
	{
		return math::clamp(value, T{ 0 }, T{ 1 });
	}

	template<typename T>
	JINMATH_NO_DISCARD inline T exp(T value)
	{
		return std::exp(value);
	}

	template<typename T>
	JINMATH_NO_DISCARD inline T infinity()
	{
		return (std::numeric_limits<T>::max)();
	} 

	template<typename T>
	JINMATH_NO_DISCARD inline T negativeInfinity()
	{
		return std::numeric_limits<T>::lowest();

	}


	template<typename Value, typename Floating>
	JINMATH_NO_DISCARD inline Floating lerpUnClamped(Value value1, Value value2, Floating t)
	{
		static_assert(std::is_same_v<Floating, FLOAT32> || std::is_same_v<Floating, FLOAT64>);
		return value1 + t * (value2 - value1);
	}

	template<typename Value, typename Floating>
	JINMATH_NO_DISCARD inline Floating lerp(Value value1, Value value2, Floating t)
	{
		static_assert(std::is_same_v<Floating, FLOAT32> || std::is_same_v<Floating, FLOAT64>);
		return lerpUnClamped<Value, Floating>(value1, value2, clamp01<Floating>(t));
	}

	

	template<typename T>
	JINMATH_NO_DISCARD inline auto log(T value)
	{
		return std::log(value);
	}

	template<typename T>
	JINMATH_NO_DISCARD inline auto log10(T value)
	{
		return std::log10(value);
	}

	

	/*template<typename T>
	JINMATH_NO_DISCARD inline typename T PerlinNoise(T value);*/

	
	template<typename X, typename Y>
	JINMATH_NO_DISCARD inline auto pow(X value, Y exp)
	{
		return std::pow(value, exp);
	}

	template<typename T>
	JINMATH_NO_DISCARD inline auto sin(T radian)
	{
		return std::sin(radian);
	}

	template<typename T>
	JINMATH_NO_DISCARD inline auto cos(T radian)
	{
		return std::cos(radian);
	}

	template<typename T>
	JINMATH_NO_DISCARD inline auto tan(T radian)
	{
		return std::tan(radian);
	}

	template<typename T>
	JINMATH_NO_DISCARD inline auto sqrt(T value)
	{
		return std::sqrt(value);
	}
	

	template<typename T>
	JINMATH_NO_DISCARD inline auto inverseSqrt(T value)
	{
		return static_cast<T>(1) / std::sqrt(value);
	}

	
	JINMATH_NO_DISCARD JINMATH_FORCE_INLINE bool Equal(FLOAT32 a, FLOAT32 b)
	{
		return std::abs(a - b) < std::numeric_limits<FLOAT32>::epsilon();;
	}

	JINMATH_NO_DISCARD JINMATH_FORCE_INLINE bool Equal(FLOAT64 a, FLOAT64 b)
	{
		return std::abs(a - b) < std::numeric_limits<FLOAT64>::epsilon();;
	}

	JINMATH_NO_DISCARD JINMATH_FORCE_INLINE bool Equal(FLOAT32 a, FLOAT64 b)
	{
		return Equal(static_cast<FLOAT64>(a), b);
	}

	JINMATH_NO_DISCARD JINMATH_FORCE_INLINE bool Equal(FLOAT64 a, FLOAT32 b)
	{
		return Equal(a, static_cast<FLOAT64>(b));
	}
	/////



}