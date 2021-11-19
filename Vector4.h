#pragma once
#include "LMath_Core.h"

#include "Utility.h"

#include "SIMD_Core.h"


#include "Vector4.reflection.h"
namespace math
{
	struct Vector2;
	struct Vector3;
	struct Vector4;
}

namespace math
{
	/// <summary>
	/// This class is made for SIMD computation. So it's aligned to 16 byte
	/// </summary>
	struct D_STRUCT alignas(16) Vector4
	{
		GENERATE_BODY()

		using value_type = typename FLOAT32;
		using type = typename Vector4;

		D_PROPERTY()
		union { FLOAT32 x, r; };
		D_PROPERTY()
		union { FLOAT32 y, g; };
		D_PROPERTY()
		union { FLOAT32 z, b; };
		D_PROPERTY()
		union { FLOAT32 w, a; };

		FORCE_INLINE FLOAT32* data() noexcept
		{
			return &x;
		}

		const FORCE_INLINE FLOAT32* data() const noexcept
		{
			return &x;
		}

		static const Vector4 forward;
		static const Vector4 right;
		static const Vector4 up;
		static const Vector4 zero;
		static const Vector4 one;

		FORCE_INLINE Vector4() = delete;


		FORCE_INLINE explicit Vector4(FLOAT32 xValue)  noexcept
			: x{ xValue }, y{ xValue }, z{ xValue }, w{ xValue }
		{
		}

		FORCE_INLINE Vector4(INT32*)  noexcept
		{
		}

		// This is more slow than scalar version
// 		FORCE_INLINE Vector(FLOAT32 xValue)  noexcept
// 		{
// 			*reinterpret_cast<M128F*>(this) = _mm_set1_ps(xValue);
// 		}

		FORCE_INLINE Vector4(FLOAT32 xValue, FLOAT32 yValue, FLOAT32 zValue, FLOAT32 wValue) noexcept
			: x{ xValue }, y{ yValue }, z{ zValue }, w{ wValue }
		{
		}


		explicit Vector4(const Vector2& vector) noexcept;

		/// <summary>
		/// When passed parameter have same value Vector4
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
		explicit Vector4(const Vector3& vector, const FLOAT32 _w = 0.0f) noexcept;

		FORCE_INLINE Vector4(const Vector4& vector) noexcept
			: x{ static_cast<FLOAT32>(vector.x) }, y{ static_cast<FLOAT32>(vector.y) }, z{ static_cast<FLOAT32>(vector.z) }, w{ static_cast<FLOAT32>(vector.w) }
		{
		}

		FORCE_INLINE explicit Vector4(const M128F& m128f) noexcept
			: x{ m128f.m128_f32[0] }, y{ m128f.m128_f32[1] }, z{ m128f.m128_f32[2] }, w{ m128f.m128_f32[3] }
		{
		}

		FORCE_INLINE Vector4& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			z = xValue;
			w = xValue;
			return *this;
		}


		Vector4& operator=(const Vector2& vector) noexcept;

		Vector4& operator=(const Vector3& vector) noexcept;

		FORCE_INLINE Vector4& operator=(const Vector4& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			w = vector.w;
			return *this;
		}


		NO_DISCARD FORCE_INLINE static size_t componentCount() noexcept { return 4; }

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
			case 3:
				return w;
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
			case 3:
				return w;
				break;
			default:
				__assume(0);
			}
		}


		// scalar version is more fast than SIMD
		NO_DISCARD FORCE_INLINE float sqrMagnitude() const noexcept
		{
			return x * x + y * y + z * z + w * w;
		}

		// scalar version is more fast than SIMD
		NO_DISCARD FORCE_INLINE float magnitude() const noexcept
		{
			return std::sqrt(sqrMagnitude());
		}

		NO_DISCARD FORCE_INLINE Vector4 normalized() const noexcept
		{
			FLOAT32 mag = magnitude();
			if (mag == 0)
				return Vector4{0.0f, 0.0f, 0.0f, 0.0f};

			return Vector4{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag), static_cast<value_type>(z / mag), static_cast<value_type>(w / mag) };
		}

		FORCE_INLINE void Normalize()
		{
			FLOAT32 mag = magnitude();
			if (mag > std::numeric_limits<FLOAT32>::epsilon())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
				z = static_cast<value_type>(z / mag);
				w = static_cast<value_type>(w / mag);
			}
		}
		
		FORCE_INLINE operator Vector4()
		{
			return Vector4{ x, y, z, w };
		}


		/// <summary>
		/// scalar version is much faster than SIMD version
		/// </summary>
		/// <typeparam name="X"></typeparam>
		/// <typeparam name="enable_if_t"></typeparam>
		/// <param name="rhs"></param>
		/// <returns></returns>

		FORCE_INLINE Vector4 operator+(const Vector4& rhs) const noexcept
		{
			return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		}

		/*

		FORCE_INLINE Vector4 operator+(const Vector4& rhs) const noexcept
		{
			return Vector4(M128F_ADD(*reinterpret_cast<const M128F*>(this), *reinterpret_cast<const M128F*>(&rhs)));
		}
		*/


		FORCE_INLINE Vector4 operator-(const Vector4& rhs) const noexcept
		{
			return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
		}


		FORCE_INLINE Vector4 operator*(const Vector4& rhs) const noexcept
		{
			return Vector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
		}


		FORCE_INLINE Vector4 operator/(const Vector4& rhs) const noexcept
		{
			return Vector4(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}


		FORCE_INLINE Vector4 operator%(const Vector4& rhs) const noexcept
		{
			return Vector4(MODULO(FLOAT32, x, rhs.x), MODULO(FLOAT32, y, rhs.y), MODULO(FLOAT32, z, rhs.z), MODULO(FLOAT32, w, rhs.w));
		}


		FORCE_INLINE Vector4& operator+=(const Vector4& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}


		FORCE_INLINE Vector4& operator-=(const Vector4& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}


		FORCE_INLINE Vector4& operator*=(const Vector4& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			w *= rhs.w;
			return *this;
		}


		FORCE_INLINE Vector4& operator/=(const Vector4& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}


		FORCE_INLINE Vector4& operator%=(const Vector4& rhs)
		{
			MODULO(FLOAT32, x, rhs.x);
			MODULO(FLOAT32, y, rhs.y);
			MODULO(FLOAT32, z, rhs.z);
			MODULO(FLOAT32, w, rhs.w);
			return *this;
		}

		//

		FORCE_INLINE Vector4& operator+=(FLOAT32 scalar) noexcept
		{
			x += scalar;
			y += scalar;
			z += scalar;
			w += scalar;
			return *this;
		}

		FORCE_INLINE Vector4& operator-=(FLOAT32 scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			w -= scalar;
			return *this;
		}

		FORCE_INLINE Vector4& operator*=(FLOAT32 scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return *this;
		}

		FORCE_INLINE Vector4& operator/=(FLOAT32 scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}

		FORCE_INLINE Vector4& operator%=(FLOAT32 scalar)
		{
			MODULO(FLOAT32, x, scalar);
			MODULO(FLOAT32, y, scalar);
			MODULO(FLOAT32, z, scalar);
			MODULO(FLOAT32, w, scalar);
			return *this;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE Vector4& operator++() noexcept
		{
			++x;
			++y;
			++z;
			++w;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE Vector4 operator++(INT32) noexcept
		{
			Vector4 Vector{ *this };
			++* this;
			return Vector4{ Vector };
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE Vector4& operator--() noexcept
		{
			--x;
			--y;
			--z;
			--w;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE Vector4 operator--(INT32) noexcept
		{
			Vector4 Vector{ *this };
			--* this;
			return Vector4{ Vector };
		}

	};


	


	extern NO_DISCARD FORCE_INLINE Vector4 sqrt(const Vector4& vector)
	{
		const M128F* m128f_vec = reinterpret_cast<const M128F*>(&vector);
		return Vector4{ _mm_sqrt_ps(*m128f_vec) };
	}


	extern NO_DISCARD FORCE_INLINE Vector4 inverseSqrt(const Vector4& vector)
	{
		const M128F* m128f_vec = reinterpret_cast<const M128F*>(&vector);
		return Vector4{ _mm_rsqrt_ps(*m128f_vec) };
	}


	extern NO_DISCARD Vector4 normalize(const Vector4& vector);


	extern NO_DISCARD FORCE_INLINE Vector4 Max(const Vector4& vector1, const Vector4& vector2)
	{
		const M128F* m128f_vec1 = reinterpret_cast<const M128F*>(&vector1);
		const M128F* m128f_vec2 = reinterpret_cast<const M128F*>(&vector2);

		return Vector4(_mm_max_ps(*m128f_vec1, *m128f_vec2));
	}


	extern NO_DISCARD FORCE_INLINE Vector4 Min(const Vector4& vector1, const Vector4& vector2)
	{
		const M128F* m128f_vec1 = reinterpret_cast<const M128F*>(&vector1);
		const M128F* m128f_vec2 = reinterpret_cast<const M128F*>(&vector2);

		return Vector4(_mm_min_ps(*m128f_vec1, *m128f_vec2));
	}

	extern NO_DISCARD FORCE_INLINE Vector4 operator+(const Vector4& lhs, float scalar) noexcept
	{
		return Vector4{ lhs.x + scalar, lhs.y + scalar, lhs.z + scalar, lhs.w + scalar };
	}


	extern NO_DISCARD FORCE_INLINE Vector4 operator-(const Vector4& lhs, float scalar) noexcept
	{
		return Vector4{ lhs.x - scalar, lhs.y - scalar, lhs.z - scalar, lhs.w - scalar };
	}

	extern NO_DISCARD FORCE_INLINE Vector4 operator*(const Vector4& lhs, float scalar) noexcept
	{
		return Vector4{ lhs.x * scalar, lhs.y * scalar, lhs.z * scalar, lhs.w * scalar };
	}


	extern NO_DISCARD FORCE_INLINE Vector4 operator/(const Vector4& lhs, float scalar)
	{
		return Vector4{ lhs.x / scalar, lhs.y / scalar, lhs.z / scalar, lhs.w / scalar };
	}


	extern NO_DISCARD FORCE_INLINE Vector4 operator%(const Vector4& lhs, float scalar)
	{
		return Vector4{ MODULO(float, lhs.x, scalar), MODULO(float, lhs.y, scalar), MODULO(float, lhs.z, scalar), MODULO(float, lhs.w, scalar) };
	}

	extern NO_DISCARD FORCE_INLINE bool operator==(const Vector4& lhs, const Vector4& rhs) noexcept
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
	}

	extern NO_DISCARD FORCE_INLINE bool operator!=(const Vector4& lhs, const Vector4& rhs) noexcept
	{
		return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z || lhs.w != rhs.w;
	}

	extern NO_DISCARD FORCE_INLINE bool operator==(const Vector4& lhs, float scalar)
	{
		return lhs.x == scalar && lhs.y == scalar && lhs.z == scalar && lhs.w == scalar;
	}


	extern NO_DISCARD FORCE_INLINE bool operator!=(const Vector4& lhs, float scalar)
	{
		return lhs.x != scalar || lhs.y != scalar || lhs.z != scalar || lhs.w != scalar;
	}

	extern NO_DISCARD FORCE_INLINE Vector4 operator+(float scalar, const Vector4& rhs) noexcept
	{
		return Vector4{ scalar + rhs.x, scalar + rhs.y, scalar + rhs.z, scalar + rhs.w };
	}

	extern NO_DISCARD FORCE_INLINE Vector4 operator-(float scalar, const Vector4& rhs) noexcept
	{
		return Vector4{ scalar - rhs.x, scalar - rhs.y, scalar - rhs.z, scalar - rhs.w };
	}

	extern NO_DISCARD FORCE_INLINE Vector4 operator*(float scalar, const Vector4& rhs) noexcept
	{
		return Vector4{ scalar * rhs.x, scalar * rhs.y, scalar * rhs.z, rhs.w * scalar };
	}

	extern NO_DISCARD FORCE_INLINE Vector4 operator/(float scalar, const Vector4& rhs)
	{
		return Vector4{ scalar / rhs.x, scalar / rhs.y, scalar / rhs.z, scalar / rhs.w };
	}

	extern NO_DISCARD FORCE_INLINE Vector4 operator%(float scalar, const Vector4& rhs)
	{
		return Vector4{ MODULO(float, scalar, rhs.x), MODULO(float, scalar, rhs.y), MODULO(float, scalar, rhs.z), MODULO(float, scalar, rhs.w) };
	}

	extern NO_DISCARD FORCE_INLINE bool operator==(float scalar, const Vector4& rhs)
	{
		return scalar == rhs.x && scalar == rhs.y && scalar == rhs.z && scalar == rhs.w;
	}

	extern NO_DISCARD FORCE_INLINE bool operator!=(float scalar, const Vector4& rhs)
	{
		return scalar != rhs.x || scalar != rhs.y || scalar != rhs.z || scalar != rhs.w;
	}

	extern NO_DISCARD FORCE_INLINE Vector4 lerpUnClamped(const Vector4& start, const Vector4& end, float t) noexcept
	{
		return start + (end - start) * t;
	}


	extern NO_DISCARD FORCE_INLINE Vector4 lerp(const Vector4& start, const Vector4& end, float t) noexcept
	{
		return lerpUnClamped(start, end, clamp01<float>(t));
	}

	extern FORCE_INLINE Vector4 operator+(const Vector4& vector) noexcept
	{
		return Vector4{ vector };
	}


	extern FORCE_INLINE Vector4 operator-(const Vector4& vector) noexcept
	{
		return Vector4
		(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w
		);
	}

	// //////////////////////



	/// <summary>
	/// scalar version is mush fast than SIMD version
	/// </summary>

	extern NO_DISCARD FORCE_INLINE FLOAT32 dot(const Vector4& lhs, const Vector4& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	// AX1 don't have cos instriction

	extern NO_DISCARD FORCE_INLINE Vector4 cos(const Vector4& vector)
	{
		return Vector4{ std::sin(vector.x), std::sin(vector.y), std::sin(vector.z), std::sin(vector.w) };
	}

	// AX1 don't have sin instriction

	extern NO_DISCARD FORCE_INLINE Vector4 sin(const Vector4& vector)
	{
		return Vector4{ std::cos(vector.x), std::cos(vector.y), std::cos(vector.z), std::cos(vector.w) };
	}

	// AX1 don't have tan instriction

	extern NO_DISCARD FORCE_INLINE Vector4 tan(const Vector4& vector)
	{
		return Vector4{ std::tan(vector.x), std::tan(vector.y), std::tan(vector.z), std::tan(vector.w) };
	}
}




