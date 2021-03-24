#pragma once
#include "Vector.h"



namespace math
{
	template <typename T>
	struct Vector<4, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Vector<4, T>;

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


		FORCE_INLINE constexpr Vector() noexcept : x{ }, y{ }, z{ }, w{ }
		{

		}

		FORCE_INLINE constexpr explicit Vector(T xValue)  noexcept
			: x{ xValue }, y{ xValue }, z{ xValue }, w{ xValue }
		{
		}

		FORCE_INLINE constexpr Vector(T xValue, T yValue, T zValue, T wValue) noexcept
			: x{ xValue }, y{ yValue }, z{ zValue }, w{ wValue }
		{
		}

		FORCE_INLINE constexpr explicit Vector(const type& vector) noexcept
			: x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ vector.w }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<1, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ 0 }, z{ 0 }, w{ 0 }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<2, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ 0 }, w{ 0 }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<3, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ static_cast<T>(vector.z) }, w{ 0 }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<4, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ static_cast<T>(vector.z) }, w{ static_cast<T>(vector.w) }
		{
		}

		FORCE_INLINE constexpr type& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			z = xValue;
			w = xValue;
			return *this;
		}

		FORCE_INLINE constexpr type& operator=(const type& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			w = vector.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			y = 0;
			z = 0;
			w = 0;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = 0;
			w = 0;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			w = 0;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<4, X>& vector) noexcept
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

		[[nodiscard]] FORCE_INLINE static constexpr size_t componentCount() noexcept { return 4; }

		[[nodiscard]] FORCE_INLINE constexpr value_type& operator[](size_t i)
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

		[[nodiscard]] FORCE_INLINE constexpr const value_type& operator[](size_t i) const
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

	
		[[nodiscard]] FORCE_INLINE constexpr auto sqrMagnitude() const noexcept
		{
			return x * x + y * y + z * z + w * w;
		}

		[[nodiscard]] FORCE_INLINE constexpr auto magnitude() const noexcept
		{
			return math::sqrt(sqrMagnitude());
		}

		[[nodiscard]] FORCE_INLINE constexpr type normalized() const noexcept
		{
			auto mag = magnitude();
			if (mag == 0)
				return type{};

			return type{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag), static_cast<value_type>(z / mag), static_cast<value_type>(w / mag) };
		}

		FORCE_INLINE constexpr void Normalize()
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

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator+(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator-(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator*(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator/(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator%(const Vector<RightComponentSize, X>& rhs) const
		{
			return type(MODULO(T, x, rhs.x), MODULO(T, y, rhs.y), MODULO(T, z, rhs.z), MODULO(T, w, rhs.w));
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator+=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator-=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator*=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			w *= rhs.w;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator/=(const Vector<RightComponentSize, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator%=(const Vector<RightComponentSize, X>& rhs)
		{
			MODULO(T, x, rhs.x);
			MODULO(T, y, rhs.y);
			MODULO(T, z, rhs.z);
			MODULO(T, w, rhs.w);
			return *this;
		}

		//

		template <typename X>
		FORCE_INLINE constexpr type& operator+=(const X& scalar) noexcept
		{
			x += scalar;
			y += scalar;
			z += scalar;
			w += scalar;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator-=(const X& scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			w -= scalar;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator*=(const X& scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator/=(const X& scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator%=(const X& scalar)
		{
			MODULO(T, x, scalar);
			MODULO(T, y, scalar);
			MODULO(T, z, scalar);
			MODULO(T, w, scalar);
			return *this;
		}

		//

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(const type& rhs) const noexcept
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(const type& rhs) const noexcept
		{
			return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z || this->w != rhs.w;
		}

		template <typename X>
		[[nodiscard]] FORCE_INLINE constexpr bool operator==(const X& number) const noexcept
		{
			return this->x == number && this->y == number && this->z == number && this->w == number;
		}

		template <typename X>
		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(const X& number) const noexcept
		{
			return this->x != number || this->y != number || this->z != number || this->w != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator++() noexcept
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
		FORCE_INLINE constexpr type operator++(int) noexcept
		{
			type Vector{ *this };
			++* this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator--() noexcept
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
		FORCE_INLINE constexpr type operator--(int) noexcept
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
	FORCE_INLINE constexpr Vector<4, T> operator+(const Vector<4, T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	FORCE_INLINE constexpr Vector<4, T> operator-(const Vector<4, T>& vector) noexcept
	{
		return Vector<4, T>(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w);
	}

	// //////////////////////////////////////////////////////

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr auto dot(const Vector<4, T>& lhs, const Vector<4, T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, T> cos(const Vector<4, T>& vector)
	{
		return Vector<4, T>{math::sin(vector.x), math::sin(vector.y), math::sin(vector.z), math::sin(vector.w)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, T> sin(const Vector<4, T>& vector)
	{
		return Vector<4, T>{math::cos(vector.x), math::cos(vector.y), math::cos(vector.z), math::cos(vector.w)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, T> tan(const Vector<4, T>& vector)
	{
		return Vector<4, T>{math::tan(vector.x), math::tan(vector.y), math::tan(vector.z), math::tan(vector.w)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, T> sqrt(const Vector<4, T>& vector)
	{
		return Vector<2, T>{sqrt(vector.x), sqrt(vector.y), sqrt(vector.z), sqrt(vector.w)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, T> inverseSqrt(const Vector<4, T>& vector)
	{
		return Vector<2, T>{inverseSqrt(vector.x), inverseSqrt(vector.y), inverseSqrt(vector.z), inverseSqrt(vector.w)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, T> normalize(const Vector<4, T>& vector)
	{
		return vector * inverseSqrt(dot(vector, vector));
	}

	template<typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, T> Max(const Vector<4, T>& vector1, const Vector<4, T>& vector2)
	{
		return Vector<4, T>(math::Max(vector1.x, vector2.x), math::Max(vector1.y, vector2.y), math::Max(vector1.z, vector2.z), math::Max(vector1.w, vector2.w));
	}

	template<typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, T> Min(const Vector<4, T>& vector1, const Vector<4, T>& vector2)
	{
		return Vector<4, T>(math::Min(vector1.x, vector2.x), math::Min(vector1.y, vector2.y), math::Min(vector1.z, vector2.z), math::Min(vector1.w, vector2.w));
	}

	// //////////////////////////////////////////////////////
}


// For the time being, Don't Add SIMD To Vector4Float.
// It looks slower than scalar verison

/*
#include "SIMD_Core.h"
#ifdef SIMD_ENABLED
#include "Vector4Float_Aligned.inl"
#endif
*/

namespace math
{
	using Vector4 = Vector<4, float>;

	extern template struct math::Vector<4, float>;
	extern template struct math::Vector<4, double>;
	extern template struct math::Vector<4, long double>;
	extern template struct math::Vector<4, short int>;
	extern template struct math::Vector<4, int>;
	extern template struct math::Vector<4, long int>;
	extern template struct math::Vector<4, long long int>;
	extern template struct math::Vector<4, unsigned short int>;
	extern template struct math::Vector<4, unsigned int>;
	extern template struct math::Vector<4, unsigned long int>;
	extern template struct math::Vector<4, unsigned long long int>;
}



