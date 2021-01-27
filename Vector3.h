#pragma once
#include "Vector.h"


namespace Math
{
	template <typename T>
	struct Vector<3, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

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

		constexpr explicit Vector(T xValue)  noexcept
			: value{ xValue , xValue, xValue }
		{
		}

		template <typename X>
		constexpr Vector(X xValue)  noexcept
			: value{ static_cast<T>(xValue) , static_cast<T>(xValue), static_cast<T>(xValue) }
		{
		}


		template <typename X, typename Y, typename Z>
		constexpr Vector(X xValue, Y yValue, Z zValue) noexcept
			: value{ static_cast<T>(xValue) , static_cast<T>(yValue), static_cast<T>(zValue) }
		{
		}

		constexpr explicit Vector(const Vector<3, T>& vector) noexcept
			: value{ x , y, z }
		{
		}
		
		template <typename X>
		constexpr Vector(const Vector<1, X>& vector) noexcept
			: value{ static_cast<T>(vector.x) , 0, 0 }
		{
		}

		template <typename X>
		constexpr Vector(const Vector<2, X>& vector) noexcept
			: value{ static_cast<T>(vector.x) , static_cast<T>(vector.y), 0 }
		{
		}

		template <typename X>
		constexpr Vector(const Vector<3, X>& vector) noexcept
			: value{ static_cast<T>(vector.x) , static_cast<T>(vector.y), static_cast<T>(vector.z) }
		{
		}

		template <typename X>
		constexpr Vector(const Vector<4, X>& vector) noexcept
			: value{ static_cast<T>(vector.x) , static_cast<T>(vector.y), static_cast<T>(vector.z)}
		{
		}

		constexpr type& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			z = xValue;
			return *this;
		}

		constexpr type& operator=(const Vector<3, T>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			y = 0;
			z = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<4, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			return *this;
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

		[[nodiscard]] constexpr const value_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < length());
			return value[i];
		}


		[[nodiscard]] inline constexpr auto sqrMagnitude() noexcept
		{
			return std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2);
		}

		[[nodiscard]] inline constexpr auto magnitude() noexcept
		{
			return std::sqrt(sqrMagnitude());
		}

		[[nodiscard]] constexpr type normalized()
		{
			auto mag = magnitude();
			if (mag == 0)
				return type{};

			return type{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag), static_cast<value_type>(z / mag) };
		}

		constexpr type& Normalize()
		{
			auto mag = magnitude();
			if (mag == 0)
				return *this;
			else
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
				z = static_cast<value_type>(z / mag);
				return *this;
			}
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr type operator+(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x + rhs.x, y + rhs.y, z + rhs.z);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr type operator-(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x - rhs.x, y - rhs.y, z - rhs.z);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr type operator*(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x * rhs.x, y * rhs.y, z * rhs.z);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr type operator/(const Vector<RightComponentSize, X>& rhs)
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 3, bool> = true>
		constexpr type operator%(const Vector<RightComponentSize, X>& rhs)
		{
			return type(MODULO(T, x, rhs.x), MODULO(T, y, rhs.y), MODULO(T, z, rhs.z));
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
			MODULO(T, x, rhs.x);
			MODULO(T, y, rhs.y);
			MODULO(T, z, rhs.z);
			return *this;
		}

		//

		template <typename X>
		constexpr type& operator+=(const X& scalar) noexcept
		{
			x += scalar;
			y += scalar;
			z += scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const X& scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator*=(const X& scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator/=(const X& scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator%=(const X& scalar)
		{
			MODULO(T, x, scalar);
			MODULO(T, y, scalar);
			MODULO(T, z, scalar);
			return *this;
		}

		//

		[[nodiscard]] inline constexpr bool operator==(const type& rhs) noexcept
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z;
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

		constexpr operator std::basic_string<char>() noexcept
		{
			return this->toString();
		}
	};

	template<typename T>
	constexpr Vector<3, T> operator+(const Vector<3, T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	constexpr Vector<3, T> operator-(const Vector<3, T>& vector) noexcept
	{
		return Vector<3, T>(
			-vector.x,
			-vector.y,
			-vector.z);
	}

	using Vector3 = Vector<3, float>;
}