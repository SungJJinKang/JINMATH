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

		FORCE_INLINE Vector()  noexcept : x{}
		{

		}

		FORCE_INLINE explicit Vector(T xValue)  noexcept
			: x{ xValue }
		{
		}

		FORCE_INLINE Vector(const type& vector) noexcept
			: x{ vector.x }
		{
		}

		template <typename X>
		FORCE_INLINE Vector(const Vector<1, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }
		{
		}

		template <typename X>
		FORCE_INLINE Vector(const Vector<2, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }
		{
		}

		template <typename X>
		FORCE_INLINE Vector(const Vector<3, X>& vector) noexcept
			: x { static_cast<T>(vector.x) }
		{
		}

		template <typename X>
		FORCE_INLINE Vector(const Vector<4, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }
		{
		}

		FORCE_INLINE type& operator=(value_type xValue)  noexcept
		{
			x = xValue;
			return *this;
		}

		FORCE_INLINE type& operator=(const type& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Vector<4, X>& vector) noexcept
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

		NO_DISCARD FORCE_INLINE static size_t componentCount() noexcept { return 1; }

		NO_DISCARD FORCE_INLINE value_type& operator[](size_t i)
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

		NO_DISCARD FORCE_INLINE const value_type& operator[](size_t i) const
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

		NO_DISCARD FORCE_INLINE auto sqrMagnitude() const noexcept
		{
			return x * x;
		}

		NO_DISCARD FORCE_INLINE auto magnitude() const noexcept
		{
			return x;
		}

		NO_DISCARD FORCE_INLINE type normalized() const
		{
			return type{ 1 };
		}

		FORCE_INLINE void Normalize()
		{
			x = 1;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type operator+(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x + rhs.x);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type operator-(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x - rhs.x);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type operator*(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x * rhs.x);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type operator/(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x / rhs.x);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type operator%(const Vector<RightComponentSize, X>& rhs) const
		{
			return type(MODULO(T, x, rhs.x));
		}

		
		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator+=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x += rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator-=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x -= rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator*=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x *= rhs.x;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator/=(const Vector<RightComponentSize, X>& rhs)
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

		
		FORCE_INLINE type& operator+=(T scalar) noexcept
		{
			x += scalar;
			return *this;
		}

		
		FORCE_INLINE type& operator-=(T scalar) noexcept
		{
			x -= scalar;
			return *this;
		}

		
		FORCE_INLINE type& operator*=(T scalar) noexcept
		{
			x *= scalar;
			return *this;
		}

		
		FORCE_INLINE type& operator/=(T scalar)
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

		NO_DISCARD FORCE_INLINE bool operator==(const type& rhs) const noexcept
		{
			return this->x == rhs.x;
		}

		NO_DISCARD FORCE_INLINE bool operator!=(const type& rhs) const noexcept
		{
			return this->x != rhs.x;
		}

		
		NO_DISCARD FORCE_INLINE bool operator==(T number) const noexcept
		{
			return this->x == number;
		}

		
		NO_DISCARD FORCE_INLINE bool operator!=(T number) const noexcept
		{
			return this->x != number;
		}
		
		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator++() noexcept
		{
			++x;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE type operator++(INT32) noexcept
		{
			type Vector{ *this };
			++*this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator--() noexcept
		{
			--x;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE type operator--(INT32) noexcept
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
	NO_DISCARD FORCE_INLINE Vector<1, T> cos(const Vector<1, T>& vector)
	{
		return Vector<1, T>{math::sin(vector.x)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE Vector<1, T> sin(const Vector<1, T>& vector)
	{
		return Vector<1, T>{math::cos(vector.x)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE Vector<1, T> tan(const Vector<1, T>& vector)
	{
		return Vector<1, T>{math::tan(vector.x)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE Vector<1, T> sqrt(const Vector<1, T>& vector)
	{
		return Vector<1, T>{sqrt(vector.x)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE Vector<1, T> inverseSqrt(const Vector<1, T>& vector)
	{
		return Vector<1, T>{inverseSqrt(vector.x)};
	}

	template<typename T>
	NO_DISCARD FORCE_INLINE Vector<1, T> Max(const Vector<1, T>& vector1, const Vector<1, T>& vector2)
	{
		return Vector<1, T>(math::Max(vector1.x, vector2.x));
	}

	template<typename T>
	NO_DISCARD FORCE_INLINE Vector<1, T> Min(const Vector<1, T>& vector1, const Vector<1, T>& vector2)
	{
		return Vector<1, T>(math::Min(vector1.x, vector2.x));
	}

	// ////////////////////////////////////////////////////////////////////////////////////////////

	using Vector1 = Vector<1, FLOAT32>;

	extern template struct math::Vector<1, FLOAT32>;
}