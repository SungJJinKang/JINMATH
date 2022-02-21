#pragma once
#include "JINSTLCore.h"

#include "Utility.h"

#include "Vector3.reflection.h"
namespace math
{
	struct Vector2;
	struct Vector3;
	struct Vector4;

	// never put alignas
	struct D_STRUCT Vector3
	{
		GENERATE_BODY()

		using value_type = float;
		using type = typename Vector3;

		D_PROPERTY()
		union { float x, r; };
		D_PROPERTY()
		union { float y, g; };
		D_PROPERTY()
		union { float z, b; };

		FORCE_INLINE float* data() noexcept
		{
			return &x;
		}

		const FORCE_INLINE float* data() const noexcept
		{
			return &x;
		}

		static const Vector3 forward;
		static const Vector3 right;
		static const Vector3 up;

		FORCE_INLINE Vector3() = delete;

		/// <summary>
		/// for not init
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE Vector3(INT32*)  noexcept
		{
		}

		FORCE_INLINE explicit Vector3(float xValue)  noexcept
			: x{ xValue }, y{ xValue }, z{ xValue }
		{
		}

		FORCE_INLINE Vector3(float xValue, float yValue, float zValue) noexcept
			: x{ xValue }, y{ yValue }, z{ zValue }
		{
		}
		
		
		explicit Vector3(const Vector2& vector) noexcept;

		FORCE_INLINE Vector3(const Vector3& vector) noexcept
			: x{ vector.x }, y{ vector.y }, z{ vector.z }
		{
		}
		
		explicit Vector3(const Vector4& vector) noexcept;

		FORCE_INLINE Vector3& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			z = xValue;
			return *this;
		}
		
		
		Vector3& operator=(const Vector2& vector) noexcept;

		FORCE_INLINE Vector3& operator=(const Vector3& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			return *this;
		}
		
		Vector3& operator=(const Vector4& vector) noexcept;

		// 		Vector(const Vector3&) = default;
// 		Vector(Vector3&&) = default;
// 		Vector3& opreator=(const Vector3&) = default;
// 		Vector3& opreator=(Vector3&&) = default;


		NO_DISCARD FORCE_INLINE static size_t componentCount() noexcept { return 3; }


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
			case 2:
				return z;
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
			case 2:
				return z;
				break;
			default:
				__assume(0);
			}
		}


		NO_DISCARD FORCE_INLINE FLOAT32 sqrMagnitude() const noexcept
		{
			return x * x + y * y + z * z;
		}

		NO_DISCARD FORCE_INLINE FLOAT32 magnitude() const noexcept
		{
			return static_cast<FLOAT32>(std::sqrt(sqrMagnitude()));
		}

		NO_DISCARD FORCE_INLINE Vector3 normalized() const noexcept
		{
			FLOAT32 mag = magnitude();
			if (mag == 0.0f)
				return Vector3{0.0f, 0.0f, 0.0f};

			return Vector3{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag), static_cast<value_type>(z / mag) };
		}

		FORCE_INLINE void Normalize()
		{
			FLOAT32 mag = magnitude();
			if (mag > std::numeric_limits<float>::epsilon())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
				z = static_cast<value_type>(z / mag);
			}
		}

		
		FORCE_INLINE operator Vector3()
		{
			return Vector3{x, y, z};
		}
		
		FORCE_INLINE Vector3 operator+(const Vector3& rhs) const noexcept
		{
			return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
		}

		
		FORCE_INLINE Vector3 operator-(const Vector3& rhs) const noexcept
		{
			return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
		}

		
		FORCE_INLINE Vector3 operator*(const Vector3& rhs) const noexcept
		{
			return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
		}

		
		FORCE_INLINE Vector3 operator/(const Vector3& rhs) const noexcept
		{
			return Vector3(x / rhs.x, y / rhs.y, z / rhs.z);
		}

		
		FORCE_INLINE Vector3 operator%(const Vector3& rhs) const
		{
			return Vector3(MODULO(float, x, rhs.x), MODULO(float, y, rhs.y), MODULO(float, z, rhs.z));
		}

		
		FORCE_INLINE Vector3& operator+=(const Vector3& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		
		FORCE_INLINE Vector3& operator-=(const Vector3& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}

		
		FORCE_INLINE Vector3& operator*=(const Vector3& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			return *this;
		}

		
		FORCE_INLINE Vector3& operator/=(const Vector3& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			return *this;
		}

		
		FORCE_INLINE Vector3& operator%=(const Vector3& rhs)
		{
			MODULO(float, x, rhs.x);
			MODULO(float, y, rhs.y);
			MODULO(float, z, rhs.z);
			return *this;
		}

		//

		FORCE_INLINE Vector3& operator+=(float scalar) noexcept
		{
			x += scalar;
			y += scalar;
			z += scalar;
			return *this;
		}

		FORCE_INLINE Vector3& operator-=(float scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			return *this;
		}

		FORCE_INLINE Vector3& operator*=(float scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}

		FORCE_INLINE Vector3& operator/=(float scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			return *this;
		}

		FORCE_INLINE Vector3& operator%=(float scalar)
		{
			MODULO(float, x, scalar);
			MODULO(float, y, scalar);
			MODULO(float, z, scalar);
			return *this;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE Vector3& operator++() noexcept
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
		FORCE_INLINE Vector3 operator++(INT32) noexcept
		{
			Vector3 Vector{ *this };
			++* this;
			return Vector3{ Vector };
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE Vector3& operator--() noexcept
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
		FORCE_INLINE Vector3 operator--(INT32) noexcept
		{
			Vector3 Vector{ *this };
			--* this;
			return Vector3{ Vector };
		}

	};

	extern NO_DISCARD FORCE_INLINE Vector3 operator+(const Vector3& lhs, float scalar) noexcept
	{
		return Vector3{ lhs.x + scalar, lhs.y + scalar, lhs.z + scalar };
	}


	extern NO_DISCARD FORCE_INLINE Vector3 operator-(const Vector3& lhs, float scalar) noexcept
	{
		return Vector3{ lhs.x - scalar, lhs.y - scalar, lhs.z - scalar };

	}

	extern NO_DISCARD FORCE_INLINE Vector3 operator*(const Vector3& lhs, float scalar) noexcept
	{
		return Vector3{ lhs.x * scalar, lhs.y * scalar, lhs.z * scalar };
	}


	extern NO_DISCARD FORCE_INLINE Vector3 operator/(const Vector3& lhs, float scalar)
	{
		return Vector3{ lhs.x / scalar, lhs.y / scalar, lhs.z / scalar };
	}


	extern NO_DISCARD FORCE_INLINE Vector3 operator%(const Vector3& lhs, float scalar)
	{
		return Vector3{ MODULO(float, lhs.x, scalar), MODULO(float, lhs.y, scalar), MODULO(float, lhs.z, scalar) };
	}

	extern NO_DISCARD FORCE_INLINE bool operator==(const Vector3& lhs, const Vector3& rhs) noexcept
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

	extern NO_DISCARD FORCE_INLINE bool operator!=(const Vector3& lhs, const Vector3& rhs) noexcept
	{
		return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z;
	}

	extern NO_DISCARD FORCE_INLINE bool operator==(const Vector3& lhs, float scalar)
	{
		return lhs.x == scalar && lhs.y == scalar && lhs.z == scalar;
	}


	extern NO_DISCARD FORCE_INLINE bool operator!=(const Vector3& lhs, float scalar)
	{
		return lhs.x != scalar || lhs.y != scalar || lhs.z != scalar;
	}

	extern NO_DISCARD FORCE_INLINE Vector3 operator+(float scalar, const Vector3& rhs) noexcept
	{
		return Vector3{ scalar + rhs.x, scalar + rhs.y, scalar + rhs.z };
	}

	extern NO_DISCARD FORCE_INLINE Vector3 operator-(float scalar, const Vector3& rhs) noexcept
	{
		return Vector3{ scalar - rhs.x, scalar - rhs.y, scalar - rhs.z };

	}

	extern NO_DISCARD FORCE_INLINE Vector3 operator*(float scalar, const Vector3& rhs) noexcept
	{
		return Vector3{ scalar * rhs.x, scalar * rhs.y, scalar * rhs.z };
	}

	extern NO_DISCARD FORCE_INLINE Vector3 operator/(float scalar, const Vector3& rhs)
	{
		return Vector3{ scalar / rhs.x, scalar / rhs.y, scalar / rhs.z };
	}

	extern NO_DISCARD FORCE_INLINE Vector3 operator%(float scalar, const Vector3& rhs)
	{
		return Vector3{ MODULO(float, scalar, rhs.x), MODULO(float, scalar, rhs.y), MODULO(float, scalar, rhs.z) };
	}

	extern NO_DISCARD FORCE_INLINE bool operator==(float scalar, const Vector3& rhs)
	{
		return scalar == rhs.x && scalar == rhs.y && scalar == rhs.z;
	}

	extern NO_DISCARD FORCE_INLINE bool operator!=(float scalar, const Vector3& rhs)
	{
		return scalar != rhs.x || scalar != rhs.y || scalar != rhs.z;

	}

	extern NO_DISCARD FORCE_INLINE Vector3 lerpUnClamped(const Vector3& start, const Vector3& end, float t) noexcept
	{
		return start + (end - start) * t;
	}


	extern NO_DISCARD FORCE_INLINE Vector3 lerp(const Vector3& start, const Vector3& end, float t) noexcept
	{
		return lerpUnClamped(start, end, clamp01<float>(t));
	}

	extern FORCE_INLINE Vector3 operator+(const Vector3& vector) noexcept
	{
		return Vector3{ vector };
	}

	
	extern FORCE_INLINE Vector3 operator-(const Vector3& vector) noexcept
	{
		return Vector3(
			-vector.x,
			-vector.y,
			-vector.z);
	}

	// //////////////////////////////////////////////////////

	
	extern NO_DISCARD FORCE_INLINE FLOAT32 dot(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	
	extern NO_DISCARD FORCE_INLINE Vector3 cross(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(
			lhs.y * rhs.z - rhs.y * lhs.z,
			lhs.z * rhs.x - rhs.z * lhs.x,
			lhs.x * rhs.y - rhs.x * lhs.y);
	}

	
	extern NO_DISCARD FORCE_INLINE Vector3 sin(const Vector3& vector)
	{
		return Vector3{std::sin(vector.x), std::sin(vector.y), std::sin(vector.z)};
	}

	
	extern NO_DISCARD FORCE_INLINE Vector3 cos(const Vector3& vector)
	{
		return Vector3{std::cos(vector.x), std::cos(vector.y), std::cos(vector.z)};
	}

	
	extern NO_DISCARD FORCE_INLINE Vector3 tan(const Vector3& vector)
	{
		return Vector3{std::tan(vector.x), std::tan(vector.y), std::tan(vector.z)};
	}

	
	extern NO_DISCARD FORCE_INLINE Vector3 sqrt(const Vector3& vector)
	{
		return Vector3{std::sqrt(vector.x), std::sqrt(vector.y), std::sqrt(vector.z)};
	}

	
	extern NO_DISCARD FORCE_INLINE Vector3 inverseSqrt(const Vector3& vector)
	{
		return Vector3{ ::math::inverseSqrt(vector.x), ::math::inverseSqrt(vector.y), ::math::inverseSqrt(vector.z)};
	}

	
	extern NO_DISCARD Vector3 normalize(const Vector3& vector);


	extern NO_DISCARD FORCE_INLINE Vector3 Max(const Vector3& vector1, const Vector3& vector2)
	{
		return Vector3(::math::Max(vector1.x, vector2.x), ::math::Max(vector1.y, vector2.y), ::math::Max(vector1.z, vector2.z));
	}

	
	extern NO_DISCARD FORCE_INLINE Vector3 Min(const Vector3& vector1, const Vector3& vector2)
	{
		return Vector3(::math::Min(vector1.x, vector2.x), ::math::Min(vector1.y, vector2.y), ::math::Min(vector1.z, vector2.z));
	}
	
	template<typename T>
	extern NO_DISCARD FORCE_INLINE Vector3 slerp
	(
		const Vector3& x,
		const Vector3& y,
		T const& a
	)
	{
		// get cosine of angle between vectors (-1 -> 1)
		T CosAlpha = math::dot(x, y);
		// get angle (0 -> pi)
		T Alpha = math::acos(CosAlpha);
		// get sine of angle between vectors (0 -> 1)
		T SinAlpha = math::sin(Alpha);
		// this breaks down when SinAlpha = 0, i.e. Alpha = 0 or pi
		T t1 = math::sin((static_cast<T>(1) - a) * Alpha) / SinAlpha;
		T t2 = math::sin(a * Alpha) / SinAlpha;

		// interpolate src vectors
		return x * t1 + y * t2;
	}
}

