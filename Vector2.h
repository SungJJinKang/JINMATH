#pragma once
#include "LMath_Core.h"
#include "Utility.h"

#include "Vector2.reflection.h"
namespace math
{
	struct Vector2;
	struct Vector3;
	struct Vector4;

	struct D_STRUCT Vector2
	{
		GENERATE_BODY()

		using value_type = float;
		using type = typename Vector2;

		D_PROPERTY()
		union { float x, r; };
		D_PROPERTY()
		union { float y, g; };

		FORCE_INLINE float* data() noexcept
		{
			return &x;
		}

		const FORCE_INLINE float* data() const noexcept
		{
			return &x;
		}


		static const Vector2 right;
		static const Vector2 up;


		FORCE_INLINE Vector2() = delete;
		FORCE_INLINE Vector2(INT32*)  noexcept
		{
		}

		FORCE_INLINE explicit Vector2(float xValue)  noexcept
			: x{ xValue }, y { xValue }
		{
		}


		FORCE_INLINE Vector2(float xValue, float yValue) noexcept
			: x{ xValue }, y{ yValue }
		{
		}
		
		FORCE_INLINE Vector2(const Vector2& vector) noexcept
			: x{ vector.x }, y{ vector.y}
		{
		}

		
		explicit Vector2(const Vector3& vector) noexcept;
		explicit Vector2(const Vector4& vector) noexcept;

		FORCE_INLINE Vector2& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			return *this;
		}
				
		FORCE_INLINE Vector2& operator=(const Vector2& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			return *this;
		}

		
		Vector2& operator=(const Vector3& vector) noexcept;
		Vector2& operator=(const Vector4& vector) noexcept;

		// 		Vector(const Vector2&) = default;
// 		Vector(Vector2&&) = default;
// 		Vector2& opreator=(const Vector2&) = default;
// 		Vector2& opreator=(Vector2&&) = default;

	

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
		

		NO_DISCARD FORCE_INLINE FLOAT32 sqrMagnitude() const noexcept
		{
			return x* x + y * y;
		}

		NO_DISCARD FORCE_INLINE FLOAT32 magnitude() const noexcept
		{
			return std::sqrt(sqrMagnitude());
		}

		NO_DISCARD FORCE_INLINE Vector2 normalized() const noexcept
		{
			FLOAT32 mag = magnitude();
			if (mag == 0)
				return Vector2{0.0f, 0.0f};

			return Vector2{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag) };
		}

		FORCE_INLINE void Normalize()
		{
			FLOAT32 mag = magnitude();
			if (mag > std::numeric_limits<FLOAT32>::epsilon())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
			}
		}

		
		FORCE_INLINE operator Vector2()
		{
			return Vector2{x, y};
		}

		FORCE_INLINE Vector2 operator+(const Vector2& rhs) const noexcept
		{
			return Vector2(x + rhs.x, y + rhs.y);
		}

		
		FORCE_INLINE Vector2 operator-(const Vector2& rhs) const noexcept
		{
			return Vector2(x - rhs.x, y - rhs.y);
		}

		
		FORCE_INLINE Vector2 operator*(const Vector2& rhs) const noexcept
		{
			return Vector2(x * rhs.x, y * rhs.y);
		}

		
		FORCE_INLINE Vector2 operator/(const Vector2& rhs) const noexcept
		{
			return Vector2(x / rhs.x, y / rhs.y);
		}

		
		FORCE_INLINE Vector2 operator%(const Vector2& rhs) const
		{
			return Vector2(MODULO(float, x, rhs.x), MODULO(float, y, rhs.y));
		}

		
		FORCE_INLINE Vector2& operator+=(const Vector2& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		
		FORCE_INLINE Vector2& operator-=(const Vector2& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		
		FORCE_INLINE Vector2& operator*=(const Vector2& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		
		FORCE_INLINE Vector2& operator/=(const Vector2& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}

		
		FORCE_INLINE Vector2& operator%=(const Vector2& rhs)
		{
			MODULO(float, x, rhs.x);
			MODULO(float, y, rhs.y);
			return *this;
		}

		
		//

		

		//

		

		//

		
		FORCE_INLINE Vector2& operator+=(float scalar) noexcept
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		
		FORCE_INLINE Vector2& operator-=(float scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}

		
		FORCE_INLINE Vector2& operator*=(float scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		
		FORCE_INLINE Vector2& operator/=(float scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}

		
		FORCE_INLINE Vector2& operator%=(float scalar)
		{
			MODULO(float, x, scalar);
			MODULO(float, y, scalar);
			return *this;
		}

		



		//

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE Vector2& operator++() noexcept
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
		FORCE_INLINE Vector2 operator++(INT32) noexcept
		{
			Vector2 Vector{ *this };
			++* this;
			return Vector2{ Vector };
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE Vector2& operator--() noexcept
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
		FORCE_INLINE Vector2 operator--(INT32) noexcept
		{
			Vector2 Vector{ *this };
			--* this;
			return Vector2{ Vector };
		}
		
	};

	extern NO_DISCARD FORCE_INLINE Vector2 operator+(const Vector2& lhs, float scalar) noexcept
	{
		return Vector2{ lhs.x + scalar, lhs.y + scalar };
	}


	extern NO_DISCARD FORCE_INLINE Vector2 operator-(const Vector2& lhs, float scalar) noexcept
	{
		return Vector2{ lhs.x - scalar, lhs.y - scalar };

	}

	extern NO_DISCARD FORCE_INLINE Vector2 operator*(const Vector2& lhs, float scalar) noexcept
	{
		return Vector2{ lhs.x * scalar, lhs.y * scalar };
	}


	extern NO_DISCARD FORCE_INLINE Vector2 operator/(const Vector2& lhs, float scalar)
	{
		return Vector2{ lhs.x / scalar, lhs.y / scalar };
	}


	extern NO_DISCARD FORCE_INLINE Vector2 operator%(const Vector2& lhs, float scalar)
	{
		return Vector2{ MODULO(float, lhs.x, scalar), MODULO(float, lhs.y, scalar) };
	}

	extern NO_DISCARD FORCE_INLINE bool operator==(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	extern NO_DISCARD FORCE_INLINE bool operator!=(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		return lhs.x != rhs.x || lhs.y != rhs.y;
	}

	extern NO_DISCARD FORCE_INLINE bool operator==(const Vector2& lhs, float scalar)
	{
		return lhs.x == scalar && lhs.y == scalar;
	}


	extern NO_DISCARD FORCE_INLINE bool operator!=(const Vector2& lhs, float scalar)
	{
		return lhs.x != scalar || lhs.y != scalar;
	}

	extern NO_DISCARD FORCE_INLINE Vector2 operator+(float scalar, const Vector2& rhs) noexcept
	{
		return Vector2{ scalar + rhs.x, scalar + rhs.y };
	}

	extern NO_DISCARD FORCE_INLINE Vector2 operator-(float scalar, const Vector2& rhs) noexcept
	{
		return Vector2{ scalar - rhs.x, scalar - rhs.y };

	}

	extern NO_DISCARD FORCE_INLINE Vector2 operator*(float scalar, const Vector2& rhs) noexcept
	{
		return Vector2{ scalar * rhs.x, scalar * rhs.y };
	}

	extern NO_DISCARD FORCE_INLINE Vector2 operator/(float scalar, const Vector2& rhs)
	{
		return Vector2{ scalar / rhs.x, scalar / rhs.y };
	}

	extern NO_DISCARD FORCE_INLINE Vector2 operator%(float scalar, const Vector2& rhs)
	{
		return Vector2{ MODULO(float, scalar, rhs.x), MODULO(float, scalar, rhs.y) };
	}

	extern NO_DISCARD FORCE_INLINE bool operator==(float scalar, const Vector2& rhs)
	{
		return scalar == rhs.x && scalar == rhs.y;
	}

	extern NO_DISCARD FORCE_INLINE bool operator!=(float scalar, const Vector2& rhs)
	{
		return scalar != rhs.x || scalar != rhs.y;
	}

	extern NO_DISCARD FORCE_INLINE Vector2 lerpUnClamped(const Vector2& start, const Vector2& end, float t) noexcept
	{
		return start + (end - start) * t;
	}


	extern NO_DISCARD FORCE_INLINE Vector2 lerp(const Vector2& start, const Vector2& end, float t) noexcept
	{
		return lerpUnClamped(start, end, clamp01(t));
	}
	
	extern FORCE_INLINE Vector2 operator+(const Vector2& vector) noexcept
	{
		return Vector2{ vector };
	}

	
	extern FORCE_INLINE Vector2 operator-(const Vector2& vector) noexcept
	{
		return Vector2(
			-vector.x,
			-vector.y);
	}

	// ///////////////////////////////////////////////

	
	extern NO_DISCARD FORCE_INLINE FLOAT32 dot(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	/// <summary>
	/// http://www.sunshine2k.de/articles/Notes_PerpDotProduct_R2.pdf
	/// 
	/// perpDot return area of the parallelogram from two vectors
	/// </summary>
	
	extern NO_DISCARD FORCE_INLINE FLOAT32 perpDot(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}

	
	extern NO_DISCARD FORCE_INLINE Vector2 cos(const Vector2& vector)
	{
		return Vector2{std::sin(vector.x), std::sin(vector.y)};
	}

	
	extern NO_DISCARD FORCE_INLINE Vector2 sin(const Vector2& vector)
	{
		return Vector2{ std::cos(vector.x), std::cos(vector.y)};
	}

	
	extern NO_DISCARD FORCE_INLINE Vector2 tan(const Vector2& vector)
	{
		return Vector2{ std::tan(vector.x), std::tan(vector.y)};
	}

	
	extern NO_DISCARD FORCE_INLINE Vector2 sqrt(const Vector2& vector)
	{
		return Vector2{std::sqrt(vector.x), std::sqrt(vector.y)};
	}

	
	extern NO_DISCARD FORCE_INLINE Vector2 inverseSqrt(const Vector2& vector)
	{
		return Vector2{ ::math::inverseSqrt(vector.x), ::math::inverseSqrt(vector.y)};
	}

	
	extern NO_DISCARD Vector2 normalize(const Vector2& vector);


	extern NO_DISCARD FORCE_INLINE Vector2 Max(const Vector2& vector1, const Vector2& vector2)
	{
		return Vector2(::math::Max(vector1.x, vector2.x), ::math::Max(vector1.y, vector2.y));
	}

	
	extern NO_DISCARD FORCE_INLINE Vector2 Min(const Vector2& vector1, const Vector2& vector2)
	{
		return Vector2(::math::Min(vector1.x, vector2.x), ::math::Min(vector1.y, vector2.y));
	}

	// ///////////////////////////////////////////////
}

