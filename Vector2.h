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

		T* data() noexcept
		{
			return &x;
		}

		const T* data() const noexcept
		{
			return &x;
		}

		static const type right;
		static const type up;


		constexpr Vector() noexcept : x{}, y{}
		{

		}

		constexpr explicit Vector(T xValue)  noexcept
			: x{ xValue }, y { xValue }
		{
		}


		constexpr Vector(T xValue, T yValue) noexcept
			: x{ xValue }, y{ yValue }
		{
		}

		constexpr explicit Vector(const type& vector) noexcept
			: x{ vector.x }, y{ vector.y}
		{
		}

		template <typename X>
		constexpr Vector(const Vector<1, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ 0}
		{
		}

		template <typename X>
		constexpr Vector(const Vector<2, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y)}
		{
		}

		template <typename X>
		constexpr Vector(const Vector<3, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y)}
		{
		}

		template <typename X>
		constexpr Vector(const Vector<4, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y)}
		{
		}

		constexpr type& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			return *this;
		}

		constexpr type& operator=(const type& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			y = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Vector<4, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

// 		Vector(const type&) = default;
// 		Vector(type&&) = default;
// 		type& opreator=(const type&) = default;
// 		type& opreator=(type&&) = default;

		std::basic_string<char> toString() const noexcept
		{
			std::stringstream ss;
			ss << x << "  " << y;
			return ss.str();
		}

		[[nodiscard]] inline static constexpr size_t componentCount() noexcept { return 2; }

		[[nodiscard]] constexpr value_type& operator[](size_t i)
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
			default:
				__assume(0);
			}
		}
		

		[[nodiscard]] inline constexpr auto sqrMagnitude() const noexcept
		{
			return x* x + y * y;
		}

		[[nodiscard]] inline constexpr auto magnitude() const noexcept
		{
			return math::sqrt(sqrMagnitude());
		}

		[[nodiscard]] constexpr type normalized() const
		{
			auto mag = magnitude();
			if (mag == 0)
				return type{};

			return type{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag) };
		}

		constexpr void Normalize()
		{
			auto mag = magnitude();
			if (mag > math::epsilon<T>())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
			}
		}

		template <size_t RightComponentSize, typename X>
		constexpr type operator+(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x + rhs.x, y + rhs.y);
		}

		template <size_t RightComponentSize, typename X>
		constexpr type operator-(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x - rhs.x, y - rhs.y);
		}

		template <size_t RightComponentSize, typename X>
		constexpr type operator*(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			return type(x * rhs.x, y * rhs.y);
		}

		template <size_t RightComponentSize, typename X>
		constexpr type operator/(const Vector<RightComponentSize, X>& rhs)
		{
			return type(x / rhs.x, y / rhs.y);
		}

		template <size_t RightComponentSize, typename X>
		constexpr type operator%(const Vector<RightComponentSize, X>& rhs)
		{
			return type(MODULO(T, x, rhs.x), MODULO(T, y, rhs.y));
		}

		template <size_t RightComponentSize, typename X>
		constexpr type& operator+=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		constexpr type& operator-=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		constexpr type& operator*=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		constexpr type& operator/=(const Vector<RightComponentSize, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		constexpr type& operator%=(const Vector<RightComponentSize, X>& rhs)
		{
			MODULO(T, x, rhs.x);
			MODULO(T, y, rhs.y);
			return *this;
		}

		//

		

		//

		[[nodiscard]] inline constexpr bool operator==(const type& rhs) noexcept
		{
			return this->x == rhs.x && this->y == rhs.y;
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this->x != rhs.x || this->y != rhs.y;
		}

		template <typename X>
		[[nodiscard]] inline constexpr bool operator==(const X& number) noexcept
		{
			return this->x == number && this->y == number;
		}

		template <typename X>
		[[nodiscard]] inline constexpr bool operator!=(const X& number) noexcept
		{
			return this->x != number || this->y != number;
		}

		//

		template <typename X>
		constexpr type& operator+=(const X& scalar) noexcept
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const X& scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator*=(const X& scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator/=(const X& scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator%=(const X& scalar)
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
		constexpr type& operator++() noexcept
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

		operator std::basic_string<char>() noexcept
		{
			return this->toString();
		}

		// //////////////////////////////////////////////////////////////////

		template <typename T>
		[[nodiscard]] FORCE_INLINE constexpr auto dot(const Vector<2, T>& lhs, const Vector<2, T>& rhs)
		{
			return lhs.x * rhs.x + lhs.y * rhs.y;
		}

		template <typename T>
		[[nodiscard]] FORCE_INLINE constexpr Vector<2, T> cos(const Vector<2, T>& vector)
		{
			return Vector<2, T>{math::sin(vector.x), math::sin(vector.y)};
		}

		template <typename T>
		[[nodiscard]] FORCE_INLINE constexpr Vector<2, T> sin(const Vector<2, T>& vector)
		{
			return Vector<2, T>{math::cos(vector.x), math::cos(vector.y)};
		}

		template <typename T>
		[[nodiscard]] FORCE_INLINE constexpr Vector<2, T> tan(const Vector<2, T>& vector)
		{
			return Vector<2, T>{math::tan(vector.x), math::tan(vector.y)};
		}

		template <typename T>
		[[nodiscard]] FORCE_INLINE constexpr Vector<2, T> sqrt(const Vector<2, T>& vector)
		{
			return Vector<2, T>{sqrt(vector.x), sqrt(vector.y)};
		}

		template <typename T>
		[[nodiscard]] FORCE_INLINE constexpr Vector<2, T> inverseSqrt(const Vector<2, T>& vector)
		{
			return Vector<2, T>{inverseSqrt(vector.x), inverseSqrt(vector.y)};
		}

		template <typename T>
		[[nodiscard]] FORCE_INLINE constexpr Vector<2, T> normalize(const Vector<2, T>& vector)
		{
			return vector * inverseSqrt(dot(vector, vector));
		}

		template<typename T>
		[[nodiscard]] FORCE_INLINE constexpr Vector<2, T> Max(const Vector<2, T>& vector1, const Vector<2, T>& vector2)
		{
			return Vector<2, T>(math::Max(vector1.x, vector2.x), math::Max(vector1.y, vector2.y));
		}

		template<typename T>
		[[nodiscard]] FORCE_INLINE constexpr Vector<2, T> Min(const Vector<2, T>& vector1, const Vector<2, T>& vector2)
		{
			return Vector<2, T>(math::Min(vector1.x, vector2.x), math::Min(vector1.y, vector2.y));
		}

		// //////////////////////////////////////////////////////////////////

	};

	template<typename T>
	constexpr Vector<2, T> operator+(const Vector<2, T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	constexpr Vector<2, T> operator-(const Vector<2, T>& vector) noexcept
	{
		return Vector<2, T>(
			-vector.x,
			-vector.y);
	}

	using Vector2 = Vector<2, float>;


	extern template struct math::Vector<2, float>;
	extern template struct math::Vector<2, double>;
	extern template struct math::Vector<2, long double>;
	extern template struct math::Vector<2, short int>;
	extern template struct math::Vector<2, int>;
	extern template struct math::Vector<2, long int>;
	extern template struct math::Vector<2, long long int>;
	extern template struct math::Vector<2, unsigned short int>;
	extern template struct math::Vector<2, unsigned int>;
	extern template struct math::Vector<2, unsigned long int>;
	extern template struct math::Vector<2, unsigned long long int>;

}