#pragma once

#include <string>
#include <sstream>

#include "LMath_Core.h"
#include "Utility.h"

namespace math
{
	template <typename T>
	struct _Vector2;

	template <typename T>
	struct _Vector3;

	template <typename T>
	struct _Vector4;

	template <typename T, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<T> lerpUnClamped(const _Vector2<T>& start, const _Vector2<T>& end, Floating t) noexcept
	{
		return start + (end - start) * t;
	}

	template <typename T, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<T> lerp(const _Vector2<T>& start, const _Vector2<T>& end, Floating t) noexcept
	{
		return lerpUnClamped(start, end, math::clamp01(t));
	}

	template <typename T, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<T> lerpUnClamped(const _Vector3<T>& start, const _Vector3<T>& end, Floating t) noexcept
	{
		return start + (end - start) * t;
	}

	template <typename T, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<T> lerp(const _Vector3<T>& start, const _Vector3<T>& end, Floating t) noexcept
	{
		return lerpUnClamped(start, end, math::clamp01(t));
	}

	template <typename T, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<T> lerpUnClamped(const _Vector4<T>& start, const _Vector4<T>& end, Floating t) noexcept
	{
		return start + (end - start) * t;
	}

	template <typename T, typename Floating, typename std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<T> lerp(const _Vector4<T>& start, const _Vector4<T>& end, Floating t) noexcept
	{
		return lerpUnClamped(start, end, math::clamp01(t));
	}


	///////////////////


	///////////////////////////////


	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<X> operator+(const _Vector2<X>& lhs, Y scalar) noexcept
	{
		return _Vector2<X>{lhs.x + scalar, lhs.y + scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<X> operator-(const _Vector2<X>& lhs, Y scalar) noexcept
	{
		return _Vector2<X>{lhs.x - scalar, lhs.y - scalar};

	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<X> operator*(const _Vector2<X>& lhs, Y scalar) noexcept
	{
		return _Vector2<X>{lhs.x * scalar, lhs.y * scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<X> operator/(const _Vector2<X>& lhs, Y scalar)
	{
		return _Vector2<X>{lhs.x / scalar, lhs.y / scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<X> operator%(const _Vector2<X>& lhs, Y scalar)
	{
		return _Vector2<X>{MODULO(X, lhs.x, scalar), MODULO(X, lhs.y, scalar)};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD bool operator==(const _Vector2<X>& lhs, Y scalar)
	{
		return lhs.x == scalar && lhs.y == scalar;
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE bool operator!=(const _Vector2<X>& lhs, Y scalar)
	{
		return lhs.x != scalar || lhs.y != scalar;
	}

	////////////////

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<X> operator+(const _Vector3<X>& lhs, Y scalar) noexcept
	{
		return _Vector3<X>{lhs.x + scalar, lhs.y + scalar, lhs.z + scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<X> operator-(const _Vector3<X>& lhs, Y scalar) noexcept
	{
		return _Vector3<X>{lhs.x - scalar, lhs.y - scalar, lhs.z - scalar};

	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<X> operator*(const _Vector3<X>& lhs, Y scalar) noexcept
	{
		return _Vector3<X>{lhs.x * scalar, lhs.y * scalar, lhs.z * scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<X> operator/(const _Vector3<X>& lhs, Y scalar)
	{
		return _Vector3<X>{lhs.x / scalar, lhs.y / scalar, lhs.z / scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<X> operator%(const _Vector3<X>& lhs, Y scalar)
	{
		return _Vector3<X>{MODULO(X, lhs.x, scalar), MODULO(X, lhs.y, scalar), MODULO(X, lhs.z, scalar)};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD bool operator==(const _Vector3<X>& lhs, Y scalar)
	{
		return lhs.x == scalar && lhs.y == scalar && lhs.z == scalar;
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE bool operator!=(const _Vector3<X>& lhs, Y scalar)
	{
		return lhs.x != scalar || lhs.y != scalar || lhs.z != scalar;
	}

	////////////

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<X> operator+(const _Vector4<X>& lhs, Y scalar) noexcept
	{
		return _Vector4<X>{lhs.x + scalar, lhs.y + scalar, lhs.z + scalar, lhs.w + scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<X> operator-(const _Vector4<X>& lhs, Y scalar) noexcept
	{
		return _Vector4<X>{lhs.x - scalar, lhs.y - scalar, lhs.z - scalar, lhs.w - scalar};
	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<X> operator*(const _Vector4<X>& lhs, Y scalar) noexcept
	{
		return _Vector4<X>{lhs.x * scalar, lhs.y * scalar, lhs.z * scalar, lhs.w * scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<X> operator/(const _Vector4<X>& lhs, Y scalar)
	{
		return _Vector4<X>{lhs.x / scalar, lhs.y / scalar, lhs.z / scalar, lhs.w / scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<X> operator%(const _Vector4<X>& lhs, Y scalar)
	{
		return _Vector4<X>{MODULO(X, lhs.x, scalar), MODULO(X, lhs.y, scalar), MODULO(X, lhs.z, scalar), MODULO(X, lhs.w, scalar)};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD bool operator==(const _Vector4<X>& lhs, Y scalar)
	{
		return lhs.x == scalar && lhs.y == scalar && lhs.z == scalar && lhs.w == scalar;
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(Y), bool> = true>
	NO_DISCARD FORCE_INLINE bool operator!=(const _Vector4<X>& lhs, Y scalar)
	{
		return lhs.x != scalar || lhs.y != scalar || lhs.z != scalar || lhs.w != scalar;
	}


	///////////////////////////////


	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<Y> operator+(X scalar, const _Vector2<Y>& rhs) noexcept
	{
		return _Vector2<Y>{scalar + rhs.x, scalar + rhs.y};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<Y> operator-(X scalar, const _Vector2<Y>& rhs) noexcept
	{
		return _Vector2<Y>{scalar - rhs.x, scalar - rhs.y};

	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<Y> operator*(X scalar, const _Vector2<Y>& rhs) noexcept
	{
		return _Vector2<Y>{scalar * rhs.x, scalar * rhs.y};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<Y> operator/(X scalar, const _Vector2<Y>& rhs)
	{
		return _Vector2<Y>{scalar / rhs.x, scalar / rhs.y};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector2<Y> operator%(X scalar, const _Vector2<Y>& rhs)
	{
		return _Vector2<Y>{MODULO(Y, scalar, rhs.x), MODULO(Y, scalar, rhs.y)};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD bool operator==(X scalar, const _Vector2<Y>& rhs)
	{
		return scalar == rhs.x && scalar == rhs.y;
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE bool operator!=(X scalar, const _Vector2<Y>& rhs)
	{
		return scalar != rhs.x || scalar != rhs.y;
	}

	////////////////

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<Y> operator+(X scalar, const _Vector3<Y>& rhs) noexcept
	{
		return _Vector3<Y>{scalar + rhs.x, scalar + rhs.y, scalar + rhs.z};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<Y> operator-(X scalar, const _Vector3<Y>& rhs) noexcept
	{
		return _Vector3<Y>{scalar - rhs.x, scalar - rhs.y, scalar - rhs.z};

	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<Y> operator*(X scalar, const _Vector3<Y>& rhs) noexcept
	{
		return _Vector3<Y>{scalar * rhs.x, scalar * rhs.y, scalar * rhs.z};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<Y> operator/(X scalar, const _Vector3<Y>& rhs)
	{
		return _Vector3<Y>{scalar / rhs.x, scalar / rhs.y, scalar / rhs.z};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector3<Y> operator%(X scalar, const _Vector3<Y>& rhs)
	{
		return _Vector3<Y>{MODULO(Y, scalar, rhs.x), MODULO(Y, scalar, rhs.y), MODULO(Y, scalar, rhs.z)};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD bool operator==(X scalar, const _Vector3<Y>& rhs)
	{
		return scalar == rhs.x && scalar == rhs.y && scalar == rhs.z;
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE bool operator!=(X scalar, const _Vector3<Y>& rhs)
	{
		return scalar != rhs.x || scalar != rhs.y || scalar != rhs.z;

	}
	////////////

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<Y> operator+(X scalar, const _Vector4<Y>& rhs) noexcept
	{
		return _Vector4<Y>{scalar + rhs.x, scalar + rhs.y, scalar + rhs.z, scalar + rhs.w};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<Y> operator-(X scalar, const _Vector4<Y>& rhs) noexcept
	{
		return _Vector4<Y>{scalar - rhs.x, scalar - rhs.y, scalar - rhs.z, scalar - rhs.w};
	}
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<Y> operator*(X scalar, const _Vector4<Y>& rhs) noexcept
	{
		return _Vector4<Y>{scalar * rhs.x, scalar * rhs.y, scalar * rhs.z, rhs.w * scalar};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<Y> operator/(X scalar, const _Vector4<Y>& rhs)
	{
		return _Vector4<Y>{scalar / rhs.x, scalar / rhs.y, scalar / rhs.z, scalar / rhs.w};
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE _Vector4<Y> operator%(X scalar, const _Vector4<Y>& rhs)
	{
		return _Vector4<Y>{MODULO(Y, scalar, rhs.x), MODULO(Y, scalar, rhs.y), MODULO(Y, scalar, rhs.z), MODULO(Y, scalar, rhs.w)};
	}
	
	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD bool operator==(X scalar, const _Vector4<Y>& rhs)
	{
		return scalar == rhs.x && scalar == rhs.y && scalar == rhs.z && scalar == rhs.w;
	}

	template <typename X, typename Y, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
	NO_DISCARD FORCE_INLINE bool operator!=(X scalar, const _Vector4<Y>& rhs)
	{
		return scalar != rhs.x || scalar != rhs.y || scalar != rhs.z || scalar != rhs.w;
	}
}