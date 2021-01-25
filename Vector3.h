#pragma once
#include "Vector.h"


namespace Math
{
	template <typename T>
	struct Vector<3, T>
	{
		static_assert(CHECK_IS_NUMBER(T));

		using value_type = typename T;
		using type = typename Vector<3, T>;

		value_type value[3];

		value_type& x = value[0];
		value_type& y = value[1];
		value_type& z = value[2];

		value_type& r = value[0];
		value_type& g = value[1];
		value_type& b = value[2];

		constexpr Vector() noexcept : value{}
		{

		}

		constexpr Vector(value_type x) noexcept
		{
			value[0] = x;
			value[1] = x;
			value[2] = x;
		}

		constexpr Vector(value_type x, value_type y, value_type z) noexcept
		{
			value[0] = x;
			value[1] = y;
			value[2] = z;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr explicit Vector(const Vector<RightComponentSize, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			y = 0;
			z = 0;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = 0;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
		}

		template <typename X>
		constexpr explicit Vector(const Vector<4, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
		}

		constexpr operator=(value_type x) noexcept
		{
			value[0] = x;
			value[1] = x;
			value[2] = x;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr operator=(const Vector<RightComponentSize, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
		}

		template <typename X>
		constexpr operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			y = 0;
			z = 0;
		}

		template <typename X>
		constexpr operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = 0;
		}

		template <typename X>
		constexpr operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
		}

		template <typename X>
		constexpr operator=(const Vector<4, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
		}

// 		Vector(const type&) = default;
// 		Vector(type&&) = default;
// 		type& opreator=(const type&) = default;
// 		type& opreator=(type&&) = default;

		constexpr std::basic_string<char> toString() noexcept
		{
			std::stringstream ss;
			ss << x << "  " << y << "  " << z;
			return ss.str();
		}

		[[nodiscard]] inline static constexpr size_t length() noexcept { return 3; }


		[[nodiscard]] value_type& operator[](size_t i)
		{
			assert(i >= 0 || i < length());
			return value[i];
		}

		[[nodiscard]] constexpr value_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < length());
			return value[i];
		}


		[[nodiscard]] inline constexpr value_type sqrMagnitude() noexcept
		{
			return std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2);
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

			return type{ x / magnitude, y / magnitude, z / magnitude };
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
				z = z / magnitude;
				return *this;
			}
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr type& operator+=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr type& operator-=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr type& operator*=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr type& operator/=(const Vector<RightComponentSize, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr type& operator%=(const Vector<RightComponentSize, X>& rhs)
		{
			x %= rhs.x;
			y %= rhs.y;
			z %= rhs.z;
			return *this;
		}

		//

		constexpr type& operator+=(const value_type& scalar) noexcept
		{
			x += scalar;
			y += scalar;
			z += scalar;
			return *this;
		}

		constexpr type& operator-=(const value_type& scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			return *this;
		}
		
		constexpr type& operator*=(const value_type& scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}

		constexpr type& operator/=(const value_type& scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			return *this;
		}

		constexpr type& operator%=(const value_type& scalar)
		{
			x %= scalar;
			y %= scalar;
			z %= scalar;
			return *this;
		}

		//

		[[nodiscard]] inline constexpr bool operator==(const type& rhs) noexcept
		{
			return this.x == rhs.x && this.y == rhs.y && this.z == rhs.z;
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this.x != rhs.x || this.y != rhs.y || this.z != rhs.z;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator++() noexcept
		{
			++x;
			++y;
			++z;
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
			++* this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator--() noexcept
		{
			--x;
			--y;
			--z;
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
			--* this;
			return Vector;
		}

		
	};

}