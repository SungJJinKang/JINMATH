#pragma once

#include <cassert>
#include <type_traits>
#include <cmath>

#include <string>
#include <sstream>

namespace Math
{
	template <size_t ComponentCount, typename T>
	struct Vector
	{
		static_assert(true, "Wrong Template Parameter");
	};

	using Vector1 = Vector<1, float>;
	using Vector2 = Vector<2, float>;
	using Vector3 = Vector<3, float>;
	using Vector4 = Vector<4, float>;


	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
	[[nodiscard]] constexpr Vector<1, T> operator+(const Vector<1, T>& lhs, const Vector<RightComponentSize, T>& rhs) noexcept
	{
		return Vector<1, T>{lhs.x + rhs.x};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
	[[nodiscard]] constexpr Vector<1, T> operator-(const Vector<1, T>& lhs, const Vector<RightComponentSize, T>& rhs) noexcept
	{
		return Vector<1, T>{lhs.x - rhs.x};
	}
	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
	[[nodiscard]] constexpr Vector<1, T> operator*(const Vector<1, T>& lhs, const Vector<RightComponentSize, T>& rhs) noexcept
	{
		return Vector<1, T>{lhs.x * rhs.x};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
	[[nodiscard]] constexpr Vector<1, T> operator/(const Vector<1, T>& lhs, const Vector<RightComponentSize, T>& rhs)
	{
		return Vector<1, T>{lhs.x / rhs.x};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
	[[nodiscard]] constexpr Vector<1, T> operator%(const Vector<1, T>& lhs, const Vector<RightComponentSize, T>& rhs)
	{
		return Vector<1, T>{lhs.x% rhs.x};
	}

	///////////////////////////////


	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	[[nodiscard]] constexpr Vector<2, T> operator+(const Vector<2, T>& lhs, const Vector<RightComponentSize, T>& rhs) noexcept
	{
		return Vector<2, T>{lhs.x + rhs.x, lhs.y + rhs.y};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	[[nodiscard]] constexpr Vector<2, T> operator-(const Vector<2, T>& lhs, const Vector<RightComponentSize, T>& rhs) noexcept
	{
		return Vector<2, T>{lhs.x - rhs.x, lhs.y - rhs.y};

	}
	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	[[nodiscard]] constexpr Vector<2, T> operator*(const Vector<2, T>& lhs, const Vector<RightComponentSize, T>& rhs) noexcept
	{
		return Vector<2, T>{lhs.x* rhs.x, lhs.y* rhs.y};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	[[nodiscard]] constexpr Vector<2, T> operator/(const Vector<2, T>& lhs, const Vector<RightComponentSize, T>& rhs)
	{
		return Vector<2, T>{lhs.x / rhs.x, lhs.y / rhs.y};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	[[nodiscard]] constexpr Vector<2, T> operator%(const Vector<2, T>& lhs, const Vector<RightComponentSize, T>& rhs)
	{
		return Vector<2, T>{lhs.x% rhs.x, lhs.y% rhs.y};
	}

	////////////////

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	[[nodiscard]] constexpr Vector<3, T> operator+(const Vector<3, T>& lhs, const Vector<RightComponentSize, T>& rhs) noexcept
	{
		return Vector<3, T>{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	[[nodiscard]] constexpr Vector<3, T> operator-(const Vector<3, T>& lhs, const Vector<RightComponentSize, T>& rhs) noexcept
	{
		return Vector<3, T>{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};

	}
	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	[[nodiscard]] constexpr Vector<3, T> operator*(const Vector<3, T>& lhs, const Vector<RightComponentSize, T>& rhs) noexcept
	{
		return Vector<3, T>{lhs.x* rhs.x, lhs.y* rhs.y, lhs.z* rhs.z};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	[[nodiscard]] constexpr Vector<3, T> operator/(const Vector<3, T>& lhs, const Vector<RightComponentSize, T>& rhs)
	{
		return Vector<3, T>{lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	[[nodiscard]] constexpr Vector<3, T> operator%(const Vector<3, T>& lhs, const Vector<RightComponentSize, T>& rhs)
	{
		return Vector<3, T>{lhs.x% rhs.x, lhs.y% rhs.y, lhs.z% rhs.z};
	}

	////////////

	template <size_t RightComponentSize, typename T>
	[[nodiscard]] constexpr Vector<4, T> operator+(const Vector<4, T>& lhs, const Vector<4, T>& rhs) noexcept
	{
		return Vector<4, T>{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
	}

	template <size_t RightComponentSize, typename T>
	[[nodiscard]] constexpr Vector<4, T> operator-(const Vector<4, T>& lhs, const Vector<4, T>& rhs) noexcept
	{
		return Vector<4, T>{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
	}
	template <size_t RightComponentSize, typename T>
	[[nodiscard]] constexpr Vector<4, T> operator*(const Vector<4, T>& lhs, const Vector<4, T>& rhs) noexcept
	{
		return Vector<4, T>{lhs.x* rhs.x, lhs.y* rhs.y, lhs.z* rhs.z, lhs.w* rhs.w};
	}

	template <size_t RightComponentSize, typename T>
	[[nodiscard]] constexpr Vector<4, T> operator/(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return Vector<4, T>{lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
	}

	template <size_t RightComponentSize, typename T>
	[[nodiscard]] constexpr Vector<4, T> operator%(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return Vector<4, T>{lhs.x % rhs.x, lhs.y % rhs.y, lhs.z % rhs.z, lhs.w % rhs.w};
	}



	///////////////////

	
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<1, X> operator+(const Vector<1, X>& lhs, Y scalar) noexcept
	{
		return Vector<1, X>{lhs.x + scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<1, X> operator-(const Vector<1, X>& lhs, Y scalar) noexcept
	{
		return Vector<1, X>{lhs.x - scalar};
	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<1, X> operator*(const Vector<1, X>& lhs, Y scalar) noexcept
	{
		return Vector<1, X>{lhs.x* scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<1, X> operator/(const Vector<1, X>& lhs, Y scalar)
	{
		return Vector<1, X>{lhs.x / scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<1, X> operator%(const Vector<1, X>& lhs, Y scalar)
	{
		return Vector<1, X>{lhs.x % scalar};
	}

	///////////////////////////////


	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<2, X> operator+(const Vector<2, X>& lhs, Y scalar) noexcept
	{
		return Vector<2, X>{lhs.x + scalar, lhs.y + scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<2, X> operator-(const Vector<2, X>& lhs, Y scalar) noexcept
	{
		return Vector<2, X>{lhs.x - scalar, lhs.y - scalar};

	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<2, X> operator*(const Vector<2, X>& lhs, Y scalar) noexcept
	{
		return Vector<2, X>{lhs.x* scalar, lhs.y* scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<2, X> operator/(const Vector<2, X>& lhs, Y scalar)
	{
		return Vector<2, X>{lhs.x / scalar, lhs.y / scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<2, X> operator%(const Vector<2, X>& lhs, Y scalar)
	{
		return Vector<2, X>{lhs.x% scalar, lhs.y% scalar};
	}

	////////////////

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<3, X> operator+(const Vector<3, X>& lhs, Y scalar) noexcept
	{
		return Vector<3, X>{lhs.x + scalar, lhs.y + scalar, lhs.z + scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<3, X> operator-(const Vector<3, X>& lhs, Y scalar) noexcept
	{
		return Vector<3, X>{lhs.x - scalar, lhs.y - scalar, lhs.z - scalar};

	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<3, X> operator*(const Vector<3, X>& lhs, Y scalar) noexcept
	{
		return Vector<3, X>{lhs.x* scalar, lhs.y* scalar, lhs.z* scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<3, X> operator/(const Vector<3, X>& lhs, Y scalar)
	{
		return Vector<3, X>{lhs.x / scalar, lhs.y / scalar, lhs.z / scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<3, X> operator%(const Vector<3, X>& lhs, Y scalar)
	{
		return Vector<3, X>{lhs.x% scalar, lhs.y% scalar, lhs.z% scalar};
	}

	////////////

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<4, X> operator+(const Vector<4, X>& lhs, Y scalar) noexcept
	{
		return Vector<4, X>{lhs.x + scalar, lhs.y + scalar, lhs.z + scalar, lhs.w + scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<4, X> operator-(const Vector<4, X>& lhs, Y scalar) noexcept
	{
		return Vector<4, X>{lhs.x - scalar, lhs.y - scalar, lhs.z - scalar, lhs.w - scalar};
	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<4, X> operator*(const Vector<4, X>& lhs, Y scalar) noexcept
	{
		return Vector<4, X>{lhs.x* scalar, lhs.y* scalar, lhs.z* scalar, lhs.w* scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<4, X> operator/(const Vector<4, X>& lhs, Y scalar)
	{
		return Vector<4, X>{lhs.x / scalar, lhs.y / scalar, lhs.z / scalar, lhs.w / scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<Y>, bool> = true>
	[[nodiscard]] constexpr Vector<4, X> operator%(const Vector<4, X>& lhs, Y scalar)
	{
		return Vector<4, X>{lhs.x % scalar, lhs.y % scalar, lhs.z % scalar, lhs.w % scalar};
	}

	////////////////////////////////

		template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<1, Y> operator+(X scalar, const Vector<1, Y>& rhs) noexcept
	{
		return Vector<1, Y>{scalar + rhs.x};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<1, Y> operator-(X scalar, const Vector<1, Y>& rhs) noexcept
	{
		return Vector<1, Y>{scalar - rhs.x};
	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<1, Y> operator*(X scalar, const Vector<1, Y>& rhs) noexcept
	{
		return Vector<1, Y>{scalar * rhs.x};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<1, Y> operator/(X scalar, const Vector<1, Y>& rhs)
	{
		return Vector<1, Y>{scalar / rhs.x};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<1, Y> operator%(X scalar, const Vector<1, Y>& rhs)
	{
		return Vector<1, Y>{scalar % rhs.x};
	}

	///////////////////////////////


	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<2, Y> operator+(X scalar, const Vector<2, Y>& rhs) noexcept
	{
		return Vector<2, Y>{scalar + rhs.x, scalar + rhs.y};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<2, Y> operator-(X scalar, const Vector<2, Y>& rhs) noexcept
	{
		return Vector<2, Y>{scalar - rhs.x, scalar - rhs.y};

	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<2, Y> operator*(X scalar, const Vector<2, Y>& rhs) noexcept
	{
		return Vector<2, Y>{scalar * rhs.x, scalar * rhs.y};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<2, Y> operator/(X scalar, const Vector<2, Y>& rhs)
	{
		return Vector<2, Y>{scalar / rhs.x, scalar / rhs.y};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<2, Y> operator%(X scalar, const Vector<2, Y>& rhs)
	{
		return Vector<2, Y>{scalar * rhs.x, scalar * rhs.y};
	}

	////////////////

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<3, Y> operator+(X scalar, const Vector<3, Y>& rhs) noexcept
	{
		return Vector<3, Y>{scalar + rhs.x, scalar + rhs.y, scalar + rhs.z};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<3, Y> operator-(X scalar, const Vector<3, Y>& rhs) noexcept
	{
		return Vector<3, Y>{scalar - rhs.x, scalar - rhs.y, scalar - rhs.z};

	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<3, Y> operator*(X scalar, const Vector<3, Y>& rhs) noexcept
	{
		return Vector<3, Y>{scalar * rhs.x, scalar * rhs.y, scalar * rhs.z};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<3, Y> operator/(X scalar, const Vector<3, Y>& rhs)
	{
		return Vector<3, Y>{scalar / rhs.x, scalar / rhs.y, scalar / rhs.z};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<3, Y> operator%(X scalar, const Vector<3, Y>& rhs)
	{
		return Vector<3, Y>{scalar * rhs.x, scalar * rhs.y, scalar % rhs.z};
	}

	////////////

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<4, Y> operator+(X scalar, const Vector<4, Y>& rhs) noexcept
	{
		return Vector<4, Y>{scalar + rhs.x, scalar + rhs.y, scalar + rhs.z, scalar + rhs.w};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<4, Y> operator-(X scalar, const Vector<4, Y>& rhs) noexcept
	{
		return Vector<4, Y>{scalar - rhs.x, scalar - rhs.y, scalar - rhs.z, scalar - rhs.w};
	}
	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<4, Y> operator*(X scalar, const Vector<4, Y>& rhs) noexcept
	{
		return Vector<4, Y>{scalar * rhs.x, scalar * rhs.y, scalar * rhs.z, rhs.w* scalar};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<4, Y> operator/(X scalar, const Vector<4, Y>& rhs)
	{
		return Vector<4, Y>{scalar / rhs.x, scalar / rhs.y, scalar / rhs.z, scalar / rhs.w};
	}

	template <typename X, typename Y, typename std::enable_if_t<std::is_arithmetic_v<X>, bool> = true>
	[[nodiscard]] constexpr Vector<4, Y> operator%(X scalar, const Vector<4, Y>& rhs)
	{
		return Vector<4, Y>{scalar % rhs.x, scalar % rhs.y, scalar % rhs.z, scalar % rhs.w};
	}
	
	
}