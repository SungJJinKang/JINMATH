#pragma once
#include "Vector.h"

namespace Math
{
	template <typename T>
	struct Vector<1, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Vector<1, T>;

		value_type value;

		value_type& x = value;

		value_type& r = value;

		constexpr Vector()  noexcept : value{}
		{

		}

		constexpr explicit Vector(T xValue)  noexcept 
			: value{ xValue }
		{

		}

		template <typename X>
		constexpr Vector(X xValue)  noexcept 
			: value{ static_cast<T>(xValue) }
		{

		}
		
		constexpr explicit Vector(const Vector<1, T>& vector) noexcept
			: value{ vector.x }
		{
		}

		template <typename X>
		constexpr Vector(const Vector<1, X>& vector) noexcept
			: value{ static_cast<T>(vector.x) }
		{
		}

		template <typename X>
		constexpr Vector(const Vector<2, X>& vector) noexcept
			: value{ static_cast<T>(vector.x) }
		{
		}

		template <typename X>
		constexpr Vector(const Vector<3, X>& vector) noexcept
			: value { static_cast<T>(vector.x) }
		{
		}

		template <typename X>
		constexpr Vector(const Vector<4, X>& vector) noexcept
			: value{ static_cast<T>(vector.x) }
		{
		}

		constexpr type& operator=(value_type xValue)  noexcept
		{
			x = xValue;
			return *this;
		}

		constexpr type& operator=(const Vector<1, T>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<4, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}



// 		Vector(const type&) = default;
// 		Vector(type&&) = default;
// 		type& opreator=(const type&) = default;
// 		type& opreator=(type&&) = default;
		
		constexpr std::basic_string<char> toString() noexcept
		{
			std::stringstream ss;
			ss << "x : " << x;
			return ss.str();
		}

		[[nodiscard]] inline static constexpr size_t length(){ return 1; }

		[[nodiscard]] value_type& operator[](size_t i)
		{
			assert(i == 0);
			return value;
		}

		[[nodiscard]] constexpr const value_type& operator[](size_t i) const
		{
			assert(i == 0);
			return value;
		}

		[[nodiscard]] inline constexpr auto sqrMagnitude() noexcept
		{
			return std::pow(x, 2);
		}

		[[nodiscard]] inline constexpr auto magnitude() noexcept
		{
			return x;
		}

		[[nodiscard]] constexpr type normalized()
		{
			return type{ 1 };
		}

		constexpr type& Normalize()
		{
			x = 1;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type operator+(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x + rhs.x);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type operator-(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x - rhs.x);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type operator*(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x * rhs.x);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type operator/(const Vector<RightComponentSize, X>& rhs)
		{
			return type(x / rhs.x);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type operator%(const Vector<RightComponentSize, X>& rhs)
		{
			return type(MODULO(T, x, rhs.x));
		}

		
		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type& operator+=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x += rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type& operator-=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x -= rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type& operator*=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x *= rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type& operator/=(const Vector<RightComponentSize, X>& rhs)
		{
			x /= rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type& operator%=(const Vector<RightComponentSize, X>& rhs)
		{
			MODULO(T, x, rhs.x);
			return *this;
		}

		template <typename X>
		constexpr type& operator+=(const X& scalar) noexcept
		{
			x += scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const X& scalar) noexcept
		{
			x -= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator*=(const X& scalar) noexcept
		{
			x *= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator/=(const X& scalar)
		{
			x /= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator%=(const X& scalar)
		{
			MODULO(T, x, scalar);
			return *this;
		}

		//

		[[nodiscard]] inline constexpr bool operator==(const type& rhs) noexcept
		{
			return this->x == rhs.x;
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this->x != rhs.x;
		}

		
		
		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator++() noexcept
		{
			++x;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr type operator++(int) noexcept
		{
			type Vector{ *this };
			++*this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator--() noexcept
		{
			--x;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr type operator--(int) noexcept
		{
			type Vector{ *this };
			--*this;
			return Vector;
		}

		constexpr operator std::basic_string<char>() noexcept
		{
			return this->toString();
		}
	};


	template<typename T>
	constexpr Vector<1, T> operator+(const Vector<1, T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	constexpr Vector<1, T> operator-(const Vector<1, T>& vector) noexcept
	{
		return Vector<1, T>(
			-vector.x);
	}

	using Vector1 = Vector<1, float>;
}