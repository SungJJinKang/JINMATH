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

		constexpr Vector() : value{}
		{

		}

		constexpr Vector(value_type x) : value{x}
		{

		}
		
		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr explicit Vector(const Vector<RightComponentSize, X>& vector)
		{
			x = vector.x;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<1, X>& vector)
		{
			x = vector.x;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<2, X>& vector)
		{
			x = vector.x;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<3, X>& vector)
		{
			x = vector.x;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<4, X>& vector)
		{
			x = vector.x;
		}


// 		Vector(const type&) = default;
// 		Vector(type&&) = default;
// 		type& opreator=(const type&) = default;
// 		type& opreator=(type&&) = default;
		
		constexpr std::basic_string<char> toString()
		{
			std::stringstream ss;
			ss << "x : " << x;
			return ss.str();
		}

		inline static constexpr size_t length(){ return 1; }

		constexpr value_type& operator[](size_t i)
		{
			assert(i != 0);
			return value;
		}
		
		inline constexpr value_type sqrMagnitude()
		{
			return std::pow(value, 2);
		}

		inline constexpr value_type magnitude()
		{
			return std::pow(sqrMagnitude(), 2);
		}

		constexpr type normalized()
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
		constexpr type& operator+=(const Vector<RightComponentSize, X>& rhs)
		{
			x += rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type& operator-=(const Vector<RightComponentSize, X>& rhs)
		{
			x -= rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 1, bool> = true>
		constexpr type& operator*=(const Vector<RightComponentSize, X>& rhs)
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

		constexpr type& operator+=(const value_type& scalar)
		{
			x += scalar;
			return *this;
		}

		constexpr type& operator-=(const value_type& scalar)
		{
			x -= scalar;
			return *this;
		}
		
		constexpr type& operator*=(const value_type& scalar)
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

		inline constexpr bool operator==(const type& rhs)
		{
			return this.x == rhs.x;
		}

		constexpr bool operator!=(const type& rhs)
		{
			return this.x != rhs.x;
		}

		
		
		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator++()
		{
			++x;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr type operator++(int)
		{
			type Vector{ *this };
			++*this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator--()
		{
			--x;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr type operator--(int)
		{
			type Vector{ *this };
			--*this;
			return Vector;
		}
	};

	
}