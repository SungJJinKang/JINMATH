#pragma once

#include <cassert>
#include <type_traits>
#include <cmath>
namespace Math
{
	template <size_t ComponentCount, typename T>
	struct Vector
	{
		static_assert(true, "Worng Template Parameter");
	};

	using Vector1 = Vector<1, float>;
	using Vector2 = Vector<2, float>;
	using Vector3 = Vector<3, float>;
	using Vector4 = Vector<4, float>;

	template <size_t ComponentCount, typename X, typename Y>
	constexpr Vector<ComponentCount, X> operator+(const Vector<ComponentCount, X>& lhs, const Vector<ComponentCount, Y>& rhs)
	{
		return Vector<ComponentCount, X>{lhs + rhs};
	}

	template <size_t ComponentCount, typename X, typename Y>
	constexpr Vector<ComponentCount, X> operator-(const Vector<ComponentCount, X>& lhs, const Vector<ComponentCount, Y>& rhs)
	{
		return Vector<ComponentCount, X>{lhs - rhs};
	}

	template <size_t ComponentCount, typename X, typename Y>
	constexpr Vector<ComponentCount, X> operator*(const Vector<ComponentCount, X>& lhs, const Vector<ComponentCount, Y>& rhs)
	{
		return Vector<ComponentCount, X>{lhs* rhs};
	}

	template <size_t ComponentCount, typename X, typename Y>
	constexpr Vector<ComponentCount, X> operator/(const Vector<ComponentCount, X>& lhs, const Vector<ComponentCount, Y>& rhs)
	{
		return Vector<ComponentCount, X>{lhs / rhs};
	}

	template <size_t ComponentCount, typename X, typename Y>
	constexpr Vector<ComponentCount, X> operator%(const Vector<ComponentCount, X>& lhs, const Vector<ComponentCount, Y>& rhs)
	{
		return Vector<ComponentCount, X>{lhs% rhs};
	}


	///////////////////

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
	constexpr Vector<1, X> operator+(const Vector<1, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<1, X>{lhs.x + rhs.x};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
	constexpr Vector<1, X> operator-(const Vector<1, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<1, X>{lhs.x - rhs.x};
	}
	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
	constexpr Vector<1, X> operator*(const Vector<1, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<1, X>{lhs.x* rhs.x};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
	constexpr Vector<1, X> operator/(const Vector<1, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<1, X>{lhs.x / rhs.x};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
	constexpr Vector<1, X> operator%(const Vector<1, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<1, X>{lhs.x% rhs.x};
	}

	///////////////////////////////


	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	constexpr Vector<2, X> operator+(const Vector<2, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<2, X>{lhs.x + rhs.x, lhs.y + rhs.y};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	constexpr Vector<2, X> operator-(const Vector<2, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<2, X>{lhs.x - rhs.x, lhs.y - rhs.y};

	}
	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	constexpr Vector<2, X> operator*(const Vector<2, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<2, X>{lhs.x* rhs.x, lhs.y* rhs.y};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	constexpr Vector<2, X> operator/(const Vector<2, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<2, X>{lhs.x / rhs.x, lhs.y / rhs.y};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	constexpr Vector<2, X> operator%(const Vector<2, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<2, X>{lhs.x% rhs.x, lhs.y% rhs.y};
	}

	////////////////

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	constexpr Vector<3, X> operator+(const Vector<3, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<3, X>{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	constexpr Vector<3, X> operator-(const Vector<3, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<3, X>{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};

	}
	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	constexpr Vector<3, X> operator*(const Vector<3, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<3, X>{lhs.x* rhs.x, lhs.y* rhs.y, lhs.z* rhs.z};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	constexpr Vector<3, X> operator/(const Vector<3, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<3, X>{lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	constexpr Vector<3, X> operator%(const Vector<3, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<3, X>{lhs.x% rhs.x, lhs.y% rhs.y, lhs.z% rhs.z};
	}

	////////////

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
	constexpr Vector<4, X> operator+(const Vector<4, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<4, X>{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
	constexpr Vector<4, X> operator-(const Vector<4, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<4, X>{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
	}
	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
	constexpr Vector<4, X> operator*(const Vector<4, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<4, X>{lhs.x* rhs.x, lhs.y* rhs.y, lhs.z* rhs.z, lhs.w* rhs.w};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
	constexpr Vector<4, X> operator/(const Vector<4, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<4, X>{lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
	}

	template <size_t RightComponentSize, typename X, typename Y, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
	constexpr Vector<4, X> operator%(const Vector<4, X>& lhs, const Vector<RightComponentSize, Y>& rhs)
	{
		return Vector<4, X>{lhs.x % rhs.x, lhs.y % rhs.y, lhs.z % rhs.z, lhs.w % rhs.w};
	}
}