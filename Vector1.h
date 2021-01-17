#pragma once
#include "Vector.h"

namespace Math
{
	template <typename T>
	struct Vector<1, T>
	{
		static_assert(std::is_arithmetic_v<T>);

		using value_type = typename T;
		using type = typename Vector<1, T>;

		value_type value;

		value_type& x = value;

		value_type& r = value;

		constexpr Vector()  noexcept : value{}
		{

		}

		constexpr Vector(value_type x)  noexcept : value{x}
		{

		}
		
		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr explicit Vector(const Vector<RightComponentSize, X>& vector) noexcept
		{
			x = vector.x;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<4, X>& vector) noexcept
		{
			x = vector.x;
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
			assert(i != 0);
			return value;
		}

		[[nodiscard]] constexpr value_type& operator[](size_t i) const
		{
			assert(i != 0);
			return value;
		}

		

		[[nodiscard]] inline constexpr value_type sqrMagnitude() noexcept
		{
			return std::pow(value, 2);
		}

		[[nodiscard]] inline constexpr value_type magnitude() noexcept
		{
			return std::pow(sqrMagnitude(), 2);
		}

		[[nodiscard]] constexpr type normalized()
		{
			value_type magnitude = magnitude();
			if (magnitude == 0)
				return type{};

			return type{ x / magnitude };
		}

		constexpr type& Normalize()
		{
			value_type magnitude = magnitude();
			if (magnitude == 0)
				return *this;
			else
			{
				x = x / magnitude;
				return *this;
			}
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
			x %= rhs.x;
			return *this;
		}

		constexpr type& operator+=(const value_type& scalar) noexcept
		{
			x += scalar;
			return *this;
		}

		constexpr type& operator-=(const value_type& scalar) noexcept
		{
			x -= scalar;
			return *this;
		}
		
		constexpr type& operator*=(const value_type& scalar) noexcept
		{
			x *= scalar;
			return *this;
		}

		constexpr type& operator/=(const value_type& scalar)
		{
			x /= scalar;
			return *this;
		}

		constexpr type& operator%=(const value_type& scalar)
		{
			x %= scalar;
			return *this;
		}

		//

		[[nodiscard]] inline constexpr bool operator==(const type& rhs) noexcept
		{
			return this.x == rhs.x;
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this.x != rhs.x;
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
	};

	
}