#pragma once

#include <type_traits>
namespace Math
{
	template <size_t ComponentCount, typename T>
	struct Vector
	{
		static_assert(true);
	};

	template <typename T>
	using Vector1 = Vector<1, T>;

	template <typename T>
	using Vector2 = Vector<2, T>;

	template <typename T>
	using Vector3 = Vector<3, T>;

	template <typename T>
	using Vector4 = Vector<4, T>;

	template <size_t ComponentCount, typename X, typename Y>
	Vector<ComponentCount, X> operator+(const Vector<ComponentCount, X>& vec1, const Vector<ComponentCount, Y>& vec2)
	{
		return Vector<ComponentCount, X>{vec1 + vec2};
	}

	template <size_t ComponentCount, typename X, typename Y>
	Vector<ComponentCount, X> operator-(const Vector<ComponentCount, X>& vec1, const Vector<ComponentCount, Y>& vec2)
	{
		return Vector<ComponentCount, X>{vec1 - vec2};
	}

	template <size_t ComponentCount, typename X, typename Y>
	Vector<ComponentCount, X> operator*(const Vector<ComponentCount, X>& vec1, const Vector<ComponentCount, Y>& vec2)
	{
		return Vector<ComponentCount, X>{vec1* vec2};
	}

	template <size_t ComponentCount, typename X, typename Y>
	Vector<ComponentCount, X> operator/(const Vector<ComponentCount, X>& vec1, const Vector<ComponentCount, Y>& vec2)
	{
		return Vector<ComponentCount, X>{vec1 / vec2};
	}

	template <size_t ComponentCount, typename X, typename Y>
	Vector<ComponentCount, X> operator%(const Vector<ComponentCount, X>& vec1, const Vector<ComponentCount, Y>& vec2)
	{
		return Vector<ComponentCount, X>{vec1 % vec2};
	}
}