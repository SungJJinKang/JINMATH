#pragma once
#include "Vector.h"

namespace math
{
	template <typename T>
	struct Vector<2, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Vector<2, T>;

		union { T x, r; };
		union { T y, g; };

		const T* data() const
		{
			return &x;
		}

		static const type right;
		static const type up;


		SIMD_CONSTEXPR Vector() noexcept : x{}, y{}
		{

		}

		SIMD_CONSTEXPR explicit Vector(T xValue)  noexcept
			: x{ xValue }, y { xValue }
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Vector(X xValue)  noexcept
			: x{ static_cast<T>(xValue) }, y{ static_cast<T>(xValue) }
		{
		}

		template <typename X, typename Y>
		SIMD_CONSTEXPR Vector(X xValue, Y yValue) noexcept
			: x{ static_cast<T>(xValue) }, y{ static_cast<T>(yValue) }
		{
		}

		SIMD_CONSTEXPR explicit Vector(const type& vector) noexcept
			: x{ vector.x }, y{ vector.y}
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Vector(const Vector<1, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ 0}
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Vector(const Vector<2, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y)}
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Vector(const Vector<3, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y)}
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Vector(const Vector<4, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y)}
		{
		}

		SIMD_CONSTEXPR type& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			return *this;
		}

		SIMD_CONSTEXPR type& operator=(const type& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			y = 0;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Vector<4, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

// 		Vector(const type&) = default;
// 		Vector(type&&) = default;
// 		type& opreator=(const type&) = default;
// 		type& opreator=(type&&) = default;

		SIMD_CONSTEXPR std::basic_string<char> toString() const noexcept
		{
			std::stringstream ss;
			ss << x << "  " << y;
			return ss.str();
		}

		[[nodiscard]] inline static SIMD_CONSTEXPR size_t componentCount(){ return 2; }

		[[nodiscard]] SIMD_CONSTEXPR value_type& operator[](size_t i)
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
			default:
				__assume(0);
			}
		}

		[[nodiscard]] SIMD_CONSTEXPR const value_type& operator[](size_t i) const
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
			default:
				__assume(0);
			}
		}
		

		[[nodiscard]] inline SIMD_CONSTEXPR auto sqrMagnitude() const noexcept
		{
			return x* x + y * y;
		}

		[[nodiscard]] inline SIMD_CONSTEXPR auto magnitude() const noexcept
		{
			return math::sqrt(sqrMagnitude());
		}

		[[nodiscard]] SIMD_CONSTEXPR type normalized() const
		{
			auto mag = magnitude();
			if (mag == 0)
				return type{};

			return type{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag) };
		}

		SIMD_CONSTEXPR void Normalize()
		{
			auto mag = magnitude();
			if (mag > math::epsilon<T>())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
			}
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		SIMD_CONSTEXPR type operator+(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x + rhs.x, y + rhs.y);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		SIMD_CONSTEXPR type operator-(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x - rhs.x, y - rhs.y);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		SIMD_CONSTEXPR type operator*(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x * rhs.x, y * rhs.y);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		SIMD_CONSTEXPR type operator/(const Vector<RightComponentSize, X>& rhs)
		{
			return type(x / rhs.x, y / rhs.y);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		SIMD_CONSTEXPR type operator%(const Vector<RightComponentSize, X>& rhs)
		{
			return type(MODULO(T, x, rhs.x), MODULO(T, y, rhs.y));
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		SIMD_CONSTEXPR type& operator+=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		SIMD_CONSTEXPR type& operator-=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		SIMD_CONSTEXPR type& operator*=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		SIMD_CONSTEXPR type& operator/=(const Vector<RightComponentSize, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		SIMD_CONSTEXPR type& operator%=(const Vector<RightComponentSize, X>& rhs)
		{
			MODULO(T, x, rhs.x);
			MODULO(T, y, rhs.y);
			return *this;
		}

		//

		

		//

		[[nodiscard]] inline SIMD_CONSTEXPR bool operator==(const type& rhs) noexcept
		{
			return this->x == rhs.x && this->y == rhs.y;
		}

		[[nodiscard]] SIMD_CONSTEXPR bool operator!=(const type& rhs) noexcept
		{
			return this->x != rhs.x || this->y != rhs.y;
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		[[nodiscard]] inline SIMD_CONSTEXPR bool operator==(const X& number) noexcept
		{
			return this->x == number && this->y == number;
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		[[nodiscard]] inline SIMD_CONSTEXPR bool operator!=(const X& number) noexcept
		{
			return this->x != number || this->y != number;
		}

		//

		template <typename X>
		SIMD_CONSTEXPR type& operator+=(const X& scalar) noexcept
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator-=(const X& scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator*=(const X& scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator/=(const X& scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator%=(const X& scalar)
		{
			MODULO(T, x, scalar);
			MODULO(T, y, scalar);
			return *this;
		}

		//

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		SIMD_CONSTEXPR type& operator++() noexcept
		{
			++x;
			++y;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		SIMD_CONSTEXPR type operator++(int) noexcept
		{
			type Vector{ *this };
			++* this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		SIMD_CONSTEXPR type& operator--() noexcept
		{
			--x;
			--y;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		SIMD_CONSTEXPR type operator--(int) noexcept
		{
			type Vector{ *this };
			--* this;
			return Vector;
		}

		SIMD_CONSTEXPR operator std::basic_string<char>() noexcept
		{
			return this->toString();
		}
	};

	template<typename T>
	SIMD_CONSTEXPR Vector<2, T> operator+(const Vector<2, T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	SIMD_CONSTEXPR Vector<2, T> operator-(const Vector<2, T>& vector) noexcept
	{
		return Vector<2, T>(
			-vector.x,
			-vector.y);
	}

	using Vector2 = Vector<2, float>;

}