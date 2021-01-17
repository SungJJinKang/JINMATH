#pragma once
#include "Vector.h"

namespace Math
{
	template <typename T>
	struct Vector<2, T>
	{
		static_assert(std::is_arithmetic_v<T>);

		using value_type = typename T;
		using type = typename Vector<2, T>;

		value_type value[2];
		
		value_type& x = value[0];
		value_type& y = value[1];

		value_type& r = value[0];
		value_type& g = value[1];

		constexpr Vector() : value{}
		{

		}

		constexpr Vector(value_type x, value_type y)
		{
			value[0] = x;
			value[1] = y;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		constexpr explicit Vector(const Vector<RightComponentSize, X>& vector)
		{
			x = vector.x;
			y = vector.y;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<1, X>& vector)
		{
			x = vector.x;
			y = 0;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<2, X>& vector)
		{
			x = vector.x;
			y = vector.y;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<3, X>& vector)
		{
			x = vector.x;
			y = vector.y;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<4, X>& vector)
		{
			x = vector.x;
			y = vector.y;
		}

// 		Vector(const type&) = default;
// 		Vector(type&&) = default;
// 		type& opreator=(const type&) = default;
// 		type& opreator=(type&&) = default;

		constexpr std::basic_string<char> toString()
		{
			std::stringstream ss;
			ss << x << "  " << y;
			return ss.str();
		}

		inline static constexpr size_t length(){ return 2; }

		constexpr T& operator[](size_t i)
		{
			assert(i < 0 || i  >= length());
			return value[i];
		}

		inline constexpr value_type sqrMagnitude()
		{
			return std::pow(x, 2) + std::pow(y, 2);
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

			return type{ x / magnitude, y / magnitude };
		}

		constexpr type& Normalize()
		{
			value_type magnitude = magnitude();
			if (magnitude == 0)
				return *this;
			else
			{
				x = x / magnitude;
				y = y / magnitude;
				return *this;
			}
		}


		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		constexpr type& operator+=(const Vector<RightComponentSize, X>& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		constexpr type& operator-=(const Vector<RightComponentSize, X>& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		constexpr type& operator*=(const Vector<RightComponentSize, X>& rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		constexpr type& operator/=(const Vector<RightComponentSize, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 2, bool> = true>
		constexpr type& operator%=(const Vector<RightComponentSize, X>& rhs)
		{
			x %= rhs.x;
			y %= rhs.y;
			return *this;
		}

		//

		

		//

		inline constexpr bool operator==(const type& rhs)
		{
			return this.x == rhs.x && this.y == rhs.y;
		}

		constexpr bool operator!=(const type& rhs)
		{
			return this.x != rhs.x || this.y != rhs.y;
		}

		//

		constexpr type& operator+=(const value_type& scalar)
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		constexpr type& operator-=(const value_type& scalar)
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}
		
		constexpr type& operator*=(const value_type& scalar)
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		constexpr type& operator/=(const value_type& scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}

		constexpr type& operator%=(const value_type& scalar)
		{
			x %= scalar;
			y %= scalar;
			return *this;
		}

		//

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator++()
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
		constexpr type operator++(int)
		{
			type Vector{ *this };
			++* this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator--()
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
		constexpr type operator--(int)
		{
			type Vector{ *this };
			--* this;
			return Vector;
		}

		
	};

	
}