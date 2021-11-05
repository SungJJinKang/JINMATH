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

		FORCE_INLINE T* data() noexcept
		{
			return &x;
		}

		const FORCE_INLINE T* data() const noexcept
		{
			return &x;
		}

		static const type right;
		static const type up;


		FORCE_INLINE Vector() noexcept : x{}, y{}
		{

		}

		FORCE_INLINE explicit Vector(T xValue)  noexcept
			: x{ xValue }, y { xValue }
		{
		}


		FORCE_INLINE Vector(T xValue, T yValue) noexcept
			: x{ xValue }, y{ yValue }
		{
		}

		FORCE_INLINE Vector(const type& vector) noexcept
		{
			std::memcpy(this->data(), vector.data(), sizeof(type));
		}

		template <typename X>
		FORCE_INLINE Vector(const Vector<1, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ 0}
		{
		}

		template <typename X>
		FORCE_INLINE Vector(const Vector<2, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y)}
		{
		}

		template <typename X>
		FORCE_INLINE Vector(const Vector<3, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y)}
		{
		}

		template <typename X>
		FORCE_INLINE Vector(const Vector<4, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y)}
		{
		}

		FORCE_INLINE type& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			return *this;
		}

		FORCE_INLINE type& operator=(const type& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			y = 0;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Vector<4, X>& vector) noexcept
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

		NO_DISCARD FORCE_INLINE static size_t componentCount() noexcept { return 2; }

		NO_DISCARD FORCE_INLINE value_type& operator[](size_t i)
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

		NO_DISCARD FORCE_INLINE const value_type& operator[](size_t i) const
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
		

		NO_DISCARD FORCE_INLINE auto sqrMagnitude() const noexcept
		{
			return x* x + y * y;
		}

		NO_DISCARD FORCE_INLINE auto magnitude() const noexcept
		{
			return math::sqrt(sqrMagnitude());
		}

		NO_DISCARD FORCE_INLINE type normalized() const noexcept
		{
			auto mag = magnitude();
			if (mag == 0)
				return type{};

			return type{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag) };
		}

		FORCE_INLINE void Normalize()
		{
			auto mag = magnitude();
			if (mag > math::epsilon<T>())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
			}
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type operator+(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x + rhs.x, y + rhs.y);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type operator-(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x - rhs.x, y - rhs.y);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type operator*(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x * rhs.x, y * rhs.y);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type operator/(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x / rhs.x, y / rhs.y);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type operator%(const Vector<RightComponentSize, X>& rhs) const
		{
			return type(MODULO(T, x, rhs.x), MODULO(T, y, rhs.y));
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator+=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator-=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator*=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator/=(const Vector<RightComponentSize, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator%=(const Vector<RightComponentSize, X>& rhs)
		{
			MODULO(T, x, rhs.x);
			MODULO(T, y, rhs.y);
			return *this;
		}

		//

		

		//

		

		//

		
		FORCE_INLINE type& operator+=(T scalar) noexcept
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		
		FORCE_INLINE type& operator-=(T scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}

		
		FORCE_INLINE type& operator*=(T scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		
		FORCE_INLINE type& operator/=(T scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}

		
		FORCE_INLINE type& operator%=(T scalar)
		{
			MODULO(T, x, scalar);
			MODULO(T, y, scalar);
			return *this;
		}

		NO_DISCARD FORCE_INLINE bool operator==(const type& rhs) const noexcept
		{
			return this->x == rhs.x && this->y == rhs.y;
		}

		NO_DISCARD FORCE_INLINE bool operator!=(const type& rhs) const noexcept
		{
			return this->x != rhs.x || this->y != rhs.y;
		}

		
		NO_DISCARD FORCE_INLINE bool operator==(T number) const noexcept
		{
			return this->x == number && this->y == number;
		}

		
		NO_DISCARD FORCE_INLINE bool operator!=(T number) const noexcept
		{
			return this->x != number || this->y != number;
		}

		//

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator++() noexcept
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
		FORCE_INLINE type operator++(INT32) noexcept
		{
			type Vector{ *this };
			++* this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator--() noexcept
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
		FORCE_INLINE type operator--(INT32) noexcept
		{
			type Vector{ *this };
			--* this;
			return Vector;
		}

		operator std::basic_string<char>() const noexcept
		{
			return this->toString();
		}

		// //////////////////////////////////////////////////////////////////

		

		// //////////////////////////////////////////////////////////////////

	};

	template<typename T>
	FORCE_INLINE Vector<2, T> operator+(const Vector<2, T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	FORCE_INLINE Vector<2, T> operator-(const Vector<2, T>& vector) noexcept
	{
		return Vector<2, T>(
			-vector.x,
			-vector.y);
	}

	// ///////////////////////////////////////////////

	template <typename T>
	NO_DISCARD FORCE_INLINE auto dot(const Vector<2, T>& lhs, const Vector<2, T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	/// <summary>
	/// http://www.sunshine2k.de/articles/Notes_PerpDotProduct_R2.pdf
	/// 
	/// perpDot return area of the parallelogram from two vectors
	/// </summary>
	template <typename T>
	NO_DISCARD FORCE_INLINE auto perpDot(const Vector<2, T>& lhs, const Vector<2, T>& rhs)
	{
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE Vector<2, T> cos(const Vector<2, T>& vector)
	{
		return Vector<2, T>{math::sin(vector.x), math::sin(vector.y)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE Vector<2, T> sin(const Vector<2, T>& vector)
	{
		return Vector<2, T>{math::cos(vector.x), math::cos(vector.y)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE Vector<2, T> tan(const Vector<2, T>& vector)
	{
		return Vector<2, T>{math::tan(vector.x), math::tan(vector.y)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE Vector<2, T> sqrt(const Vector<2, T>& vector)
	{
		return Vector<2, T>{sqrt(vector.x), sqrt(vector.y)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE Vector<2, T> inverseSqrt(const Vector<2, T>& vector)
	{
		return Vector<2, T>{inverseSqrt(vector.x), inverseSqrt(vector.y)};
	}

	template <typename T>
	NO_DISCARD FORCE_INLINE Vector<2, T> normalize(const Vector<2, T>& vector)
	{
		return vector * inverseSqrt(dot(vector, vector));
	}

	template<typename T>
	NO_DISCARD FORCE_INLINE Vector<2, T> Max(const Vector<2, T>& vector1, const Vector<2, T>& vector2)
	{
		return Vector<2, T>(math::Max(vector1.x, vector2.x), math::Max(vector1.y, vector2.y));
	}

	template<typename T>
	NO_DISCARD FORCE_INLINE Vector<2, T> Min(const Vector<2, T>& vector1, const Vector<2, T>& vector2)
	{
		return Vector<2, T>(math::Min(vector1.x, vector2.x), math::Min(vector1.y, vector2.y));
	}

	// ///////////////////////////////////////////////

	using Vector2 = Vector<2, FLOAT32>;


	extern template struct math::Vector<2, FLOAT32>;

}