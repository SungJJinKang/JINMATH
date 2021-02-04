#pragma once

#include <string>
#include <sstream>

#include "LMath_Core.h"
#include "Utility.h"

namespace math
{
	template <size_t ComponentCount, typename T>
	struct Vector;

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
		return Vector<1, T>{MODULO(T, lhs.x, rhs.x)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<1, T> cos(const Vector<1, T>& vector)
	{
		return Vector<1, T>{math::sinInRadian(vector.x)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<1, T> sin(const Vector<1, T>& vector)
	{
		return Vector<1, T>{math::cosInRadian(vector.x)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<1, T> tan(const Vector<1, T>& vector)
	{
		return Vector<1, T>{math::tanInRadian(vector.x)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<1, T> sqrt(const Vector<1, T>& vector)
	{
		return Vector<1, T>{sqrt(vector.x)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<1, T> inverseSqrt(const Vector<1, T>& vector)
	{
		return Vector<1, T>{inverseSqrt(vector.x)};
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
		return Vector<2, T>{lhs.x * rhs.x, lhs.y * rhs.y};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	[[nodiscard]] constexpr Vector<2, T> operator/(const Vector<2, T>& lhs, const Vector<RightComponentSize, T>& rhs)
	{
		return Vector<2, T>{lhs.x / rhs.x, lhs.y / rhs.y};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
	[[nodiscard]] constexpr Vector<2, T> operator%(const Vector<2, T>& lhs, const Vector<RightComponentSize, T>& rhs)
	{
		return Vector<2, T>{MODULO(T, lhs.x, rhs.x), MODULO(T, lhs.y, rhs.y)};
	}

	template <typename T>
	[[nodiscard]] constexpr auto dot(const Vector<2, T>& lhs, const Vector<2, T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<2, T> cos(const Vector<2, T>& vector)
	{
		return Vector<2, T>{math::sinInRadian(vector.x), math::sinInRadian(vector.y)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<2, T> sin(const Vector<2, T>& vector)
	{
		return Vector<2, T>{math::cosInRadian(vector.x), math::cosInRadian(vector.y)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<2, T> tan(const Vector<2, T>& vector)
	{
		return Vector<2, T>{math::tanInRadian(vector.x), math::tanInRadian(vector.y)};
	}
	
	template <typename T>
	[[nodiscard]] constexpr Vector<2, T> sqrt(const Vector<2, T>& vector)
	{
		return Vector<2, T>{sqrt(vector.x), sqrt(vector.y)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<2, T> inverseSqrt(const Vector<2, T>& vector)
	{
		return Vector<2, T>{inverseSqrt(vector.x), inverseSqrt(vector.y)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<2, T> normalize(const Vector<2, T>& vector)
	{
		return vector * inverseSqrt(dot(vector, vector));
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
		return Vector<3, T>{lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	[[nodiscard]] constexpr Vector<3, T> operator/(const Vector<3, T>& lhs, const Vector<RightComponentSize, T>& rhs)
	{
		return Vector<3, T>{lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z};
	}

	template <size_t RightComponentSize, typename T, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
	[[nodiscard]] constexpr Vector<3, T> operator%(const Vector<3, T>& lhs, const Vector<RightComponentSize, T>& rhs)
	{
		return Vector<3, T>{MODULO(T, lhs.x, rhs.x), MODULO(T, lhs.y, rhs.y), MODULO(T, lhs.z, rhs.z)};
	}

	template <typename T>
	[[nodiscard]] constexpr auto dot(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<3, T> cross(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return Vector<3, T>(
			lhs.y * rhs.z - rhs.y * lhs.z,
			lhs.z * rhs.x - rhs.z * lhs.x,
			lhs.x * rhs.y - rhs.x * lhs.y);
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<3, T> cos(const Vector<3, T>& vector)
	{
		return Vector<3, T>{math::sinInRadian(vector.x), math::sinInRadian(vector.y), math::sinInRadian(vector.z)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<3, T> sin(const Vector<3, T>& vector)
	{
		return Vector<3, T>{math::cosInRadian(vector.x), math::cosInRadian(vector.y), math::cosInRadian(vector.z)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<3, T> tan(const Vector<3, T>& vector)
	{
		return Vector<3, T>{math::tanInRadian(vector.x), math::tanInRadian(vector.y), math::tanInRadian(vector.z)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<3, T> sqrt(const Vector<3, T>& vector)
	{
		return Vector<2, T>{sqrt(vector.x), sqrt(vector.y), sqrt(vector.z)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<3, T> inverseSqrt(const Vector<3, T>& vector)
	{
		return Vector<2, T>{inverseSqrt(vector.x), inverseSqrt(vector.y), inverseSqrt(vector.z)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<3, T> normalize(const Vector<3, T>& vector)
	{
		return vector * inverseSqrt(dot(vector, vector));
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
		return Vector<4, T>{lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w};
	}

	template <size_t RightComponentSize, typename T>
	[[nodiscard]] constexpr Vector<4, T> operator/(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return Vector<4, T>{lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w};
	}

	template <size_t RightComponentSize, typename T>
	[[nodiscard]] constexpr Vector<4, T> operator%(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return Vector<4, T>{MODULO(T, lhs.x, rhs.x), MODULO(T, lhs.y, rhs.y), MODULO(T, lhs.z, rhs.z), MODULO(T, lhs.w, rhs.w)};
	}

	template <typename T>
	[[nodiscard]] constexpr auto dot(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<4, T> cos(const Vector<4, T>& vector)
	{
		return Vector<4, T>{math::sinInRadian(vector.x), math::sinInRadian(vector.y), math::sinInRadian(vector.z), math::sinInRadian(vector.w)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<4, T> sin(const Vector<4, T>& vector)
	{
		return Vector<4, T>{math::cosInRadian(vector.x), math::cosInRadian(vector.y), math::cosInRadian(vector.z), math::cosInRadian(vector.w)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<4, T> tan(const Vector<4, T>& vector)
	{
		return Vector<4, T>{math::tanInRadian(vector.x), math::tanInRadian(vector.y), math::tanInRadian(vector.z), math::tanInRadian(vector.w)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<4, T> sqrt(const Vector<4, T>& vector)
	{
		return Vector<2, T>{sqrt(vector.x), sqrt(vector.y), sqrt(vector.z), sqrt(vector.w)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<4, T> inverseSqrt(const Vector<4, T>& vector)
	{
		return Vector<2, T>{inverseSqrt(vector.x), inverseSqrt(vector.y), inverseSqrt(vector.z), inverseSqrt(vector.w)};
	}

	template <typename T>
	[[nodiscard]] constexpr Vector<4, T> normalize(const Vector<4, T>& vector)
	{
		return vector * inverseSqrt(dot(vector, vector));
	}
	
	///////////////////

	
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<1, X> operator+(const Vector<1, X>& lhs, Y scalar) noexcept
	{
		return Vector<1, X>{lhs.x + scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<1, X> operator-(const Vector<1, X>& lhs, Y scalar) noexcept
	{
		return Vector<1, X>{lhs.x - scalar};
	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<1, X> operator*(const Vector<1, X>& lhs, Y scalar) noexcept
	{
		return Vector<1, X>{lhs.x * scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<1, X> operator/(const Vector<1, X>& lhs, Y scalar)
	{
		return Vector<1, X>{lhs.x / scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<1, X> operator%(const Vector<1, X>& lhs, Y scalar)
	{
		return Vector<1, X>{MODULO(X, lhs.x, scalar)};
	}

	

	///////////////////////////////


	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<2, X> operator+(const Vector<2, X>& lhs, Y scalar) noexcept
	{
		return Vector<2, X>{lhs.x + scalar, lhs.y + scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<2, X> operator-(const Vector<2, X>& lhs, Y scalar) noexcept
	{
		return Vector<2, X>{lhs.x - scalar, lhs.y - scalar};

	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<2, X> operator*(const Vector<2, X>& lhs, Y scalar) noexcept
	{
		return Vector<2, X>{lhs.x * scalar, lhs.y * scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<2, X> operator/(const Vector<2, X>& lhs, Y scalar)
	{
		return Vector<2, X>{lhs.x / scalar, lhs.y / scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<2, X> operator%(const Vector<2, X>& lhs, Y scalar)
	{
		return Vector<2, X>{MODULO(X, lhs.x, scalar), MODULO(X, lhs.y, scalar)};
	}

	////////////////

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<3, X> operator+(const Vector<3, X>& lhs, Y scalar) noexcept
	{
		return Vector<3, X>{lhs.x + scalar, lhs.y + scalar, lhs.z + scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<3, X> operator-(const Vector<3, X>& lhs, Y scalar) noexcept
	{
		return Vector<3, X>{lhs.x - scalar, lhs.y - scalar, lhs.z - scalar};

	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<3, X> operator*(const Vector<3, X>& lhs, Y scalar) noexcept
	{
		return Vector<3, X>{lhs.x * scalar, lhs.y * scalar, lhs.z * scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<3, X> operator/(const Vector<3, X>& lhs, Y scalar)
	{
		return Vector<3, X>{lhs.x / scalar, lhs.y / scalar, lhs.z / scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<3, X> operator%(const Vector<3, X>& lhs, Y scalar)
	{
		return Vector<3, X>{MODULO(X, lhs.x, scalar), MODULO(X, lhs.y, scalar), MODULO(X, lhs.z, scalar)};
	}

	////////////

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<4, X> operator+(const Vector<4, X>& lhs, Y scalar) noexcept
	{
		return Vector<4, X>{lhs.x + scalar, lhs.y + scalar, lhs.z + scalar, lhs.w + scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<4, X> operator-(const Vector<4, X>& lhs, Y scalar) noexcept
	{
		return Vector<4, X>{lhs.x - scalar, lhs.y - scalar, lhs.z - scalar, lhs.w - scalar};
	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<4, X> operator*(const Vector<4, X>& lhs, Y scalar) noexcept
	{
		return Vector<4, X>{lhs.x * scalar, lhs.y * scalar, lhs.z * scalar, lhs.w * scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<4, X> operator/(const Vector<4, X>& lhs, Y scalar)
	{
		return Vector<4, X>{lhs.x / scalar, lhs.y / scalar, lhs.z / scalar, lhs.w / scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	[[nodiscard]] constexpr Vector<4, X> operator%(const Vector<4, X>& lhs, Y scalar)
	{
		return Vector<4, X>{MODULO(X, lhs.x, scalar), MODULO(X, lhs.y, scalar), MODULO(X, lhs.z, scalar), MODULO(X, lhs.w, scalar)};
	}

	////////////////////////////////

		template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<1, Y> operator+(X scalar, const Vector<1, Y>& rhs) noexcept
	{
		return Vector<1, Y>{scalar + rhs.x};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<1, Y> operator-(X scalar, const Vector<1, Y>& rhs) noexcept
	{
		return Vector<1, Y>{scalar - rhs.x};
	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<1, Y> operator*(X scalar, const Vector<1, Y>& rhs) noexcept
	{
		return Vector<1, Y>{scalar * rhs.x};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<1, Y> operator/(X scalar, const Vector<1, Y>& rhs)
	{
		return Vector<1, Y>{scalar / rhs.x};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<1, Y> operator%(X scalar, const Vector<1, Y>& rhs)
	{
		return Vector<1, Y>{MODULO(Y, scalar, rhs.x)};
	}

	///////////////////////////////


	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<2, Y> operator+(X scalar, const Vector<2, Y>& rhs) noexcept
	{
		return Vector<2, Y>{scalar + rhs.x, scalar + rhs.y};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<2, Y> operator-(X scalar, const Vector<2, Y>& rhs) noexcept
	{
		return Vector<2, Y>{scalar - rhs.x, scalar - rhs.y};

	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<2, Y> operator*(X scalar, const Vector<2, Y>& rhs) noexcept
	{
		return Vector<2, Y>{scalar * rhs.x, scalar * rhs.y};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<2, Y> operator/(X scalar, const Vector<2, Y>& rhs)
	{
		return Vector<2, Y>{scalar / rhs.x, scalar / rhs.y};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<2, Y> operator%(X scalar, const Vector<2, Y>& rhs)
	{
		return Vector<2, Y>{MODULO(Y, scalar, rhs.x), MODULO(Y, scalar, rhs.y)};
	}

	////////////////

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<3, Y> operator+(X scalar, const Vector<3, Y>& rhs) noexcept
	{
		return Vector<3, Y>{scalar + rhs.x, scalar + rhs.y, scalar + rhs.z};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<3, Y> operator-(X scalar, const Vector<3, Y>& rhs) noexcept
	{
		return Vector<3, Y>{scalar - rhs.x, scalar - rhs.y, scalar - rhs.z};

	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<3, Y> operator*(X scalar, const Vector<3, Y>& rhs) noexcept
	{
		return Vector<3, Y>{scalar * rhs.x, scalar * rhs.y, scalar * rhs.z};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<3, Y> operator/(X scalar, const Vector<3, Y>& rhs)
	{
		return Vector<3, Y>{scalar / rhs.x, scalar / rhs.y, scalar / rhs.z};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<3, Y> operator%(X scalar, const Vector<3, Y>& rhs)
	{
		return Vector<3, Y>{MODULO(Y, scalar, rhs.x), MODULO(Y, scalar, rhs.y), MODULO(Y, scalar, rhs.z)};
	}

	////////////

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<4, Y> operator+(X scalar, const Vector<4, Y>& rhs) noexcept
	{
		return Vector<4, Y>{scalar + rhs.x, scalar + rhs.y, scalar + rhs.z, scalar + rhs.w};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<4, Y> operator-(X scalar, const Vector<4, Y>& rhs) noexcept
	{
		return Vector<4, Y>{scalar - rhs.x, scalar - rhs.y, scalar - rhs.z, scalar - rhs.w};
	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<4, Y> operator*(X scalar, const Vector<4, Y>& rhs) noexcept
	{
		return Vector<4, Y>{scalar * rhs.x, scalar * rhs.y, scalar * rhs.z, rhs.w * scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<4, Y> operator/(X scalar, const Vector<4, Y>& rhs)
	{
		return Vector<4, Y>{scalar / rhs.x, scalar / rhs.y, scalar / rhs.z, scalar / rhs.w};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	[[nodiscard]] constexpr Vector<4, Y> operator%(X scalar, const Vector<4, Y>& rhs)
	{
		return Vector<4, Y>{MODULO(Y, scalar, rhs.x), MODULO(Y, scalar, rhs.y), MODULO(Y, scalar, rhs.z), MODULO(Y, scalar, rhs.w)};
	}
	
	
}