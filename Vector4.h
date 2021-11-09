#pragma once
#include "Vector.h"



namespace math
{
	template <typename T>
	struct _Vector4
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename _Vector4<T>;

		union { T x, r; };
		union { T y, g; };
		union { T z, b; };
		union { T w, a; };

		FORCE_INLINE T* data() noexcept
		{
			return &x;
		}

		const FORCE_INLINE T* data() const noexcept
		{
			return &x;
		}

		static const type forward;
		static const type right;
		static const type up;
		static const type zero;
		static const type one;


		FORCE_INLINE _Vector4() noexcept : x{ }, y{ }, z{ }, w{ }
		{

		}

	

		FORCE_INLINE explicit _Vector4(T xValue)  noexcept
			: x{ xValue }, y{ xValue }, z{ xValue }, w{ xValue }
		{
		}

		FORCE_INLINE _Vector4(T xValue, T yValue, T zValue, T wValue) noexcept
			: x{ xValue }, y{ yValue }, z{ zValue }, w{ wValue }
		{
		}
		
		template <typename X>
		FORCE_INLINE _Vector4(const _Vector2<X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ 0 }, w{ 0 }
		{
		}

		FORCE_INLINE _Vector4(const _Vector3<T>& vector, T _w = 0) noexcept
			: x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ _w }
		{
		}

		template <typename X>
		FORCE_INLINE _Vector4(const _Vector3<X>& vector, T w = 0) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ static_cast<T>(vector.z) }, w{ static_cast<T>(w) }
		{
		}

		FORCE_INLINE _Vector4(const type& vector) noexcept
			: x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ vector.w }
		{
		}

		template <typename X>
		FORCE_INLINE _Vector4(const _Vector4<X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ static_cast<T>(vector.z) }, w{ static_cast<T>(vector.w) }
		{
		}

		FORCE_INLINE type& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			z = xValue;
			w = xValue;
			return *this;
		}
		
		template <typename X>
		FORCE_INLINE type& operator=(const _Vector2<X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = 0;
			w = 0;
			return *this;
		}

		FORCE_INLINE type& operator=(const _Vector3<T>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;

			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const _Vector3<X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			w = 0;
			return *this;
		}

		FORCE_INLINE type& operator=(const type& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.w;
			w = vector.z;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const _Vector4<X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			w = vector.w;
			return *this;
		}

		// 		Vector(const type&) = default;
		// 		Vector(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		std::basic_string<char> toString() const noexcept
		{
			std::stringstream ss;
			ss << x << "  " << y << "  " << z << "  " << w;
			return ss.str();
		}

		NO_DISCARD FORCE_INLINE static size_t componentCount() noexcept { return 4; }

		NO_DISCARD FORCE_INLINE value_type& operator[](size_t i)
		{
			assert(i >= 0 || i < componentCount());
			switch (i)
			{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			case 3:
				return w;
				break;
			default:
				__assume(0);
			}
		}

		NO_DISCARD FORCE_INLINE const value_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < componentCount());
			switch (i)
			{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			case 3:
				return w;
				break;
			default:
				__assume(0);
			}
		}

	
		NO_DISCARD FORCE_INLINE auto sqrMagnitude() const noexcept
		{
			return x * x + y * y + z * z + w * w;
		}

		NO_DISCARD FORCE_INLINE auto magnitude() const noexcept
		{
			return math::sqrt(sqrMagnitude());
		}

		NO_DISCARD FORCE_INLINE type normalized() const noexcept
		{
			auto mag = magnitude();
			if (mag == 0)
				return type{};

			return type{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag), static_cast<value_type>(z / mag), static_cast<value_type>(w / mag) };
		}

		FORCE_INLINE void Normalize()
		{
			auto mag = magnitude();
			if (mag > math::epsilon<T>())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
				z = static_cast<value_type>(z / mag);
				w = static_cast<value_type>(w / mag);
			}
		}

		template <typename X>
		FORCE_INLINE operator _Vector2<X>()
		{
			return _Vector2<X>{static_cast<X>(x), static_cast<X>(y)};
		}

		template <typename X>
		FORCE_INLINE operator _Vector3<X>()
		{
			return _Vector3<X>{static_cast<X>(x), static_cast<X>(y), static_cast<X>(z)};
		}

		template <typename X>
		FORCE_INLINE operator _Vector4<X>()
		{
			return _Vector4<X>{static_cast<X>(x), static_cast<X>(y), static_cast<X>(z), static_cast<X>(w)};
		}

		template <typename X>
		FORCE_INLINE type operator+(const _Vector4<X>& rhs) const noexcept
		{
			return type(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		}

		template <typename X>
		FORCE_INLINE type operator-(const _Vector4<X>& rhs) const noexcept
		{
			return type(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
		}

		template <typename X>
		FORCE_INLINE type operator*(const _Vector4<X>& rhs) const noexcept
		{
			return type(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
		}

		template <typename X>
		FORCE_INLINE type operator/(const _Vector4<X>& rhs) const noexcept
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		template <typename X>
		FORCE_INLINE type operator%(const _Vector4<X>& rhs) const
		{
			return type(MODULO(T, x, rhs.x), MODULO(T, y, rhs.y), MODULO(T, z, rhs.z), MODULO(T, w, rhs.w));
		}

		template <typename X>
		FORCE_INLINE type& operator+=(const _Vector4<X>& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator-=(const _Vector4<X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator*=(const _Vector4<X>& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			w *= rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator/=(const _Vector4<X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator%=(const _Vector4<X>& rhs)
		{
			MODULO(T, x, rhs.x);
			MODULO(T, y, rhs.y);
			MODULO(T, z, rhs.z);
			MODULO(T, w, rhs.w);
			return *this;
		}

		//

		FORCE_INLINE type& operator+=(T scalar) noexcept
		{
			x += scalar;
			y += scalar;
			z += scalar;
			w += scalar;
			return *this;
		}

		FORCE_INLINE type& operator-=(T scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			w -= scalar;
			return *this;
		}

		FORCE_INLINE type& operator*=(T scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return *this;
		}

		FORCE_INLINE type& operator/=(T scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}

		FORCE_INLINE type& operator%=(T scalar)
		{
			MODULO(T, x, scalar);
			MODULO(T, y, scalar);
			MODULO(T, z, scalar);
			MODULO(T, w, scalar);
			return *this;
		}

		//

		NO_DISCARD FORCE_INLINE bool operator==(const type& rhs) const noexcept
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w;
		}

		NO_DISCARD FORCE_INLINE bool operator!=(const type& rhs) const noexcept
		{
			return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z || this->w != rhs.w;
		}

		NO_DISCARD FORCE_INLINE bool operator==(T number) const noexcept
		{
			return this->x == number && this->y == number && this->z == number && this->w == number;
		}

		NO_DISCARD FORCE_INLINE bool operator!=(T number) const noexcept
		{
			return this->x != number || this->y != number || this->z != number || this->w != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator++() noexcept
		{
			++x;
			++y;
			++z;
			++w;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE type operator++(INT32) noexcept
		{
			type Vector{ *this };
			++* this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator--() noexcept
		{
			--x;
			--y;
			--z;
			--w;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE type operator--(INT32) noexcept
		{
			type Vector{ *this };
			--* this;
			return type{ Vector };
		}

		operator std::basic_string<char>() const noexcept
		{
			return this->toString();
		}


	};

	template<typename T>
	FORCE_INLINE _Vector4<T> operator+(const _Vector4<T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	FORCE_INLINE _Vector4<T> operator-(const _Vector4<T>& vector) noexcept
	{
		return _Vector4<T>(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w);
	}

	// //////////////////////////////////////////////////////

	template <typename T>
	NO_DISCARD FORCE_INLINE auto dot(const _Vector4<T>& lhs, const _Vector4<T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE _Vector4<T> cos(const _Vector4<T>& vector)
	{
		return _Vector4<T>{math::sin(vector.x), math::sin(vector.y), math::sin(vector.z), math::sin(vector.w)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE _Vector4<T> sin(const _Vector4<T>& vector)
	{
		return _Vector4<T>{math::cos(vector.x), math::cos(vector.y), math::cos(vector.z), math::cos(vector.w)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE _Vector4<T> tan(const _Vector4<T>& vector)
	{
		return _Vector4<T>{math::tan(vector.x), math::tan(vector.y), math::tan(vector.z), math::tan(vector.w)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE _Vector4<T> sqrt(const _Vector4<T>& vector)
	{
		return _Vector4<T>{sqrt(vector.x), sqrt(vector.y), sqrt(vector.z), sqrt(vector.w)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE _Vector4<T> inverseSqrt(const _Vector4<T>& vector)
	{
		return _Vector4<T>{inverseSqrt(vector.x), inverseSqrt(vector.y), inverseSqrt(vector.z), inverseSqrt(vector.w)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE _Vector4<T> normalize(const _Vector4<T>& vector)
	{
		return vector * inverseSqrt(dot(vector, vector));
	}

	template<typename T>
	NO_DISCARD FORCE_INLINE _Vector4<T> Max(const _Vector4<T>& vector1, const _Vector4<T>& vector2)
	{
		return _Vector4<T>(math::Max(vector1.x, vector2.x), math::Max(vector1.y, vector2.y), math::Max(vector1.z, vector2.z), math::Max(vector1.w, vector2.w));
	}

	template<typename T>
	NO_DISCARD FORCE_INLINE _Vector4<T> Min(const _Vector4<T>& vector1, const _Vector4<T>& vector2)
	{
		return _Vector4<T>(math::Min(vector1.x, vector2.x), math::Min(vector1.y, vector2.y), math::Min(vector1.z, vector2.z), math::Min(vector1.w, vector2.w));
	}

	// //////////////////////////////////////////////////////
}


//This is required for 4X4Matrix * Vector4
#include "SIMD_Core.h"
#ifdef SIMD_ENABLED
#include "Vector4Float_SIMD.inl"
#endif


namespace math
{
	using Vector4 = _Vector4<FLOAT32>;
	using Vector4Int = _Vector4<INT32>;

	extern template struct _Vector4<FLOAT32>;
	extern template struct _Vector4<INT32>;
}

clcpp_reflect(math::Vector4)
clcpp_reflect(math::Vector4Int)

