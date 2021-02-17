#pragma once
#include "Vector.h"


namespace math
{
	template <typename T>
	struct Vector<3, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Vector<3, T>;

		union { T x, r; };
		union { T y, g; };
		union { T z, b; };

		const T* data() const
		{
			return &x;
		}

		static const type forward;
		static const type right;
		static const type up;

		constexpr Vector() noexcept : x{}, y{}, z{}
		{

		}

		constexpr explicit Vector(T xValue)  noexcept
			: x{ xValue }, y{ xValue }, z{ xValue }
		{
		}

		template <typename X>
		constexpr Vector(X xValue)  noexcept
			: x{ static_cast<T>(xValue) }, y{ static_cast<T>(xValue) }, z{ static_cast<T>(xValue) }
		{
		}

		template <typename X, typename Y, typename Z>
		constexpr Vector(X xValue, Y yValue, Z zValue) noexcept
			: x{ static_cast<T>(xValue) }, y{ static_cast<T>(yValue) }, z{ static_cast<T>(zValue) }
		{
		}

		constexpr explicit Vector(const type& vector) noexcept
			: x{ vector.x }, y{ vector.y }, z{ vector.z }
		{
		}
		
		template <typename X>
		constexpr Vector(const Vector<1, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ 0 }, z{ 0 }
		{
		}

		template <typename X>
		constexpr Vector(const Vector<2, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ 0 }
		{
		}

		template <typename X>
		constexpr Vector(const Vector<3, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ static_cast<T>(vector.z) }
		{
		}

		template <typename X>
		constexpr Vector(const Vector<4, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ static_cast<T>(vector.z) }
		{
		}

		constexpr type& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			z = xValue;
			return *this;
		}

		constexpr type& operator=(const type& vector) noexcept
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

		[[nodiscard]] inline static constexpr size_t componentCount() noexcept { return 3; }


		[[nodiscard]] value_type& operator[](size_t i)
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
			default:
				__assume(0);
			}
		}

		[[nodiscard]] constexpr const value_type& operator[](size_t i) const
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
			default:
				__assume(0);
			}
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

		constexpr void Normalize()
		{
			auto mag = magnitude();
			if (mag > math::epsilon<T>())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
				z = static_cast<value_type>(z / mag);
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

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		[[nodiscard]] inline constexpr bool operator==(const X& number) noexcept
		{
			return this->x == number && this->y == number && this->z == number;
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		[[nodiscard]] inline constexpr bool operator!=(const X& number) noexcept
		{
			return this->x != number || this->y != number || this->z != number;
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