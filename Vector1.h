#pragma once
#include "Vector.h"

namespace math
{
	template <typename T>
	struct Vector<1, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Vector<1, T>;

		union { T x, r; };

		FORCE_INLINE T* data() noexcept
		{
			return &x;
		}

		const FORCE_INLINE T* data() const noexcept
		{
			return &x;
		}

		FORCE_INLINE constexpr Vector()  noexcept : x{}
		{

		}

		FORCE_INLINE explicit constexpr Vector(T xValue)  noexcept
			: x{ xValue }
		{
		}

		FORCE_INLINE constexpr Vector(const type& vector) noexcept
			: x{ vector.x }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<1, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<2, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<3, X>& vector) noexcept
			: x { static_cast<T>(vector.x) }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<4, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }
		{
		}

		FORCE_INLINE constexpr type& operator=(value_type xValue)  noexcept
		{
			x = xValue;
			return *this;
		}

		FORCE_INLINE constexpr type& operator=(const type& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<4, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}



// 		Vector(const type&) = default;
// 		Vector(type&&) = default;
// 		type& opreator=(const type&) = default;
// 		type& opreator=(type&&) = default;
		
		std::basic_string<char> toString() const noexcept
		{
			std::stringstream ss;
			ss << "x : " << x;
			return ss.str();
		}

		[[nodiscard]] FORCE_INLINE static constexpr size_t componentCount() noexcept { return 1; }

		[[nodiscard]] FORCE_INLINE constexpr value_type& operator[](size_t i)
		{
			assert(i == 0);
			switch (i)
			{
			case 0:
				return x;
				break;
			default:
				__assume(0);
			}
		}

		[[nodiscard]] FORCE_INLINE constexpr const value_type& operator[](size_t i) const
		{
			assert(i == 0);
			switch (i)
			{
			case 0:
				return x;
				break;
			default:
				__assume(0);
			}
		}

		[[nodiscard]] FORCE_INLINE constexpr auto sqrMagnitude() const noexcept
		{
			return x * x;
		}

		[[nodiscard]] FORCE_INLINE constexpr auto magnitude() const noexcept
		{
			return x;
		}

		[[nodiscard]] FORCE_INLINE constexpr type normalized() const
		{
			return type{ 1 };
		}

		FORCE_INLINE constexpr void Normalize()
		{
			x = 1;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator+(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x + rhs.x);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator-(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x - rhs.x);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator*(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x * rhs.x);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator/(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x / rhs.x);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator%(const Vector<RightComponentSize, X>& rhs) const
		{
			return type(MODULO(T, x, rhs.x));
		}

		
		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator+=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x += rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator-=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x -= rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator*=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x *= rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator/=(const Vector<RightComponentSize, X>& rhs)
		{
			x /= rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator%=(const Vector<RightComponentSize, X>& rhs)
		{
			MODULO(T, x, rhs.x);
			return *this;
		}

		
		FORCE_INLINE constexpr type& operator+=(T scalar) noexcept
		{
			x += scalar;
			return *this;
		}

		
		FORCE_INLINE constexpr type& operator-=(T scalar) noexcept
		{
			x -= scalar;
			return *this;
		}

		
		FORCE_INLINE constexpr type& operator*=(T scalar) noexcept
		{
			x *= scalar;
			return *this;
		}

		
		FORCE_INLINE constexpr type& operator/=(T scalar)
		{
			x /= scalar;
			return *this;
		}

		
		FORCE_INLINE type& operator%=(T scalar)
		{
			MODULO(T, x, scalar);
			return *this;
		}

		//

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(const type& rhs) const noexcept
		{
			return this->x == rhs.x;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(const type& rhs) const noexcept
		{
			return this->x != rhs.x;
		}

		
		[[nodiscard]] FORCE_INLINE constexpr bool operator==(T number) const noexcept
		{
			return this->x == number;
		}

		
		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(T number) const noexcept
		{
			return this->x != number;
		}
		
		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator++() noexcept
		{
			++x;
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
			++*this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator--() noexcept
		{
			--x;
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
			--*this;
			return Vector;
		}

		operator std::basic_string<char>() const noexcept
		{
			return this->toString();
		}

		
	};


	template<typename T>
	FORCE_INLINE Vector<1, T> operator+(const Vector<1, T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	FORCE_INLINE Vector<1, T> operator-(const Vector<1, T>& vector) noexcept
	{
		return Vector<1, T>(
			-vector.x);
	}

	// ////////////////////////////////////////////////////////////////////////////////////////////

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<1, T> cos(const Vector<1, T>& vector)
	{
		return Vector<1, T>{math::sin(vector.x)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<1, T> sin(const Vector<1, T>& vector)
	{
		return Vector<1, T>{math::cos(vector.x)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<1, T> tan(const Vector<1, T>& vector)
	{
		return Vector<1, T>{math::tan(vector.x)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<1, T> sqrt(const Vector<1, T>& vector)
	{
		return Vector<1, T>{sqrt(vector.x)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<1, T> inverseSqrt(const Vector<1, T>& vector)
	{
		return Vector<1, T>{inverseSqrt(vector.x)};
	}

	template<typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<1, T> Max(const Vector<1, T>& vector1, const Vector<1, T>& vector2)
	{
		return Vector<1, T>(math::Max(vector1.x, vector2.x));
	}

	template<typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<1, T> Min(const Vector<1, T>& vector1, const Vector<1, T>& vector2)
	{
		return Vector<1, T>(math::Min(vector1.x, vector2.x));
	}

	// ////////////////////////////////////////////////////////////////////////////////////////////

	using Vector1 = Vector<1, float>;

	extern template struct math::Vector<1, float>;
}