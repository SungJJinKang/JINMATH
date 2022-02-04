#pragma once

#include "LMath_Core.h"

#include "Vector3.h"
#include "Vector4.h"
#include "Utility.h"

#include "Quaternion_Scalar.reflection.h"
namespace math
{
	struct Vector2;
	struct Vector3;
	struct Vector4;
	struct Matrix2x2;
	struct Matrix3x3;
	struct Matrix4x4;


	struct D_STRUCT Quaternion
	{
		GENERATE_BODY()

		using value_type = typename FLOAT32;
		using type = typename Quaternion;

		/// <summary>
		/// this is radian
		/// </summary>
		struct
		{
			D_PROPERTY()
			FLOAT32 w;

			D_PROPERTY()
			FLOAT32 x;

			D_PROPERTY()
			FLOAT32 y;

			D_PROPERTY()
			FLOAT32 z;
		};

		FORCE_INLINE FLOAT32* data() noexcept
		{
			return &w;
		}

		FORCE_INLINE const FLOAT32* data() const noexcept
		{
			return &w;
		}

		Quaternion() noexcept = delete;

		FORCE_INLINE Quaternion(int*)
		{}

		FORCE_INLINE explicit Quaternion(FLOAT32 value) noexcept
			: w{ value }, x{ value }, y{ value }, z{ value }
		{
		}

		FORCE_INLINE Quaternion(FLOAT32 wValue, FLOAT32 xValue, FLOAT32 yValue, FLOAT32 zValue) noexcept
			: w{ wValue }, x{ xValue }, y{ yValue }, z{ zValue }
		{
		}

		template <typename W, typename X, typename Y, typename Z>
		Quaternion(W wValue, X xValue, Y yValue, Z zValue) noexcept
			: w{ static_cast<FLOAT32>(wValue) }, x{ static_cast<FLOAT32>(xValue) }, y{ static_cast<FLOAT32>(yValue) }, z{ static_cast<FLOAT32>(zValue) }
		{
		}

		FORCE_INLINE Quaternion(const Quaternion& quat) noexcept
			: w{ quat.w }, x{ quat.x }, y{ quat.y }, z{ quat.z }
		{
		}

		
		Quaternion(FLOAT32 s, const Vector3& vector) noexcept;
		
		FORCE_INLINE explicit Quaternion(const Vector3& eulerAngle) noexcept
		{
			*this = type::EulerAngleToQuaternion(eulerAngle);
		}

		static type mat2Quaternion(const Matrix3x3& m);

		explicit Quaternion(const Matrix3x3& m) noexcept
		{
			*this = mat2Quaternion(m);
		}

		explicit Quaternion(const Matrix4x4& m) noexcept;

		FORCE_INLINE type& operator=(const type& vector) noexcept
		{
			w = vector.w;
			x = vector.x;
			y = vector.y;
			z = vector.z;
			return *this;
		}

	
		FORCE_INLINE type& operator=(const Matrix4x4& m) noexcept;

		FORCE_INLINE type& operator=(const Matrix3x3& m) noexcept;

		FORCE_INLINE type& operator=(const Vector3& eulerAngle) noexcept
		{
			*this = type::EulerAngleToQuaternion(eulerAngle);
			return *this;
		} 
		
		NO_DISCARD inline static size_t componentCount()  noexcept { return 4; }

		NO_DISCARD value_type& operator[](size_t i)
		{
			assert(i >= 0 || i < componentCount());
			switch (i)
			{
			case 0:
				return w;
			case 1:
				return x;
			case 2:
				return y;
			case 3:
				return z;
			default:
				NEVER_HAPPEN;
			}
		}

		NO_DISCARD FORCE_INLINE const value_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < componentCount());
			switch (i)
			{
			case 0:
				return w;
			case 1:
				return x;
			case 2:
				return y;
			case 3:
				return z;
			default:
				NEVER_HAPPEN;
			}
		}

		
		FORCE_INLINE type& operator+=(const Quaternion& rhs) noexcept
		{
			w += rhs.w;
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}
		
		FORCE_INLINE type& operator-=(const Quaternion& rhs) noexcept
		{
			w += rhs.w;
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}


		FORCE_INLINE type& operator*=(const Quaternion& rhs) noexcept
		{
			const Quaternion p(*this);
			const Quaternion q(rhs);

			this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
			this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
			this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
			this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
			return *this;
		}
		
		FORCE_INLINE type& operator/=(const Quaternion& rhs) noexcept
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}
		
		FORCE_INLINE type operator+(const Quaternion& rhs) const noexcept
		{
			return *this + rhs;
		}


		FORCE_INLINE type operator-(const Quaternion& rhs) const noexcept
		{
			return *this - rhs;
		}

		FORCE_INLINE type operator*(const Quaternion& rhs) const noexcept
		{
			Quaternion result{ nullptr };

			result.w = this->w * rhs.w - this->x * rhs.x - this->y * rhs.y - this->z * rhs.z;
			result.x = this->w * rhs.x + this->x * rhs.w + this->y * rhs.z - this->z * rhs.y;
			result.y = this->w * rhs.y + this->y * rhs.w + this->z * rhs.x - this->x * rhs.z;
			result.z = this->w * rhs.z + this->z * rhs.w + this->x * rhs.y - this->y * rhs.x;

			return type{ result };
		}
		
		FORCE_INLINE type operator/(const Quaternion& rhs) const
		{
			return *this / rhs;
		}

		/*
		static Matrix3x3 convert_quaternion_to_matrix(const Quaternion& quaternion)
		{

		}
		*/

		operator Matrix3x3() const noexcept;

		operator Matrix4x4() const noexcept;

		NO_DISCARD FORCE_INLINE bool operator==(const type& rhs) const noexcept
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w;
		}

		NO_DISCARD FORCE_INLINE bool operator!=(const type& rhs) const noexcept
		{
			return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z || this->w != rhs.w;
		}

		template <typename X>
		NO_DISCARD FORCE_INLINE bool operator==(const X& number) const noexcept
		{
			return this->x == number && this->y == number && this->z == number && this->w == number;
		}

		template <typename X>
		NO_DISCARD FORCE_INLINE bool operator!=(const X& number) const noexcept
		{
			return this->x != number || this->y != number || this->z != number || this->w != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator++() noexcept
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
		FORCE_INLINE type operator++(INT32) noexcept
		{
			type Quaternion{ *this };
			++* this;
			return type{ Quaternion };
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator--() noexcept
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
		FORCE_INLINE type operator--(INT32) noexcept
		{
			type Quaternion{ *this };
			--* this;
			return type{ Quaternion };
		}

		math::Vector3 ToEulerAngle() const;
		/*
		
		static FLOAT32 angle(Quaternion const& x)
		{
			if (abs(x.w) > cos_one_over_two<FLOAT32>())
			{
				FLOAT32 const a = asin(sqrt(x.x * x.x + x.y * x.y + x.z * x.z)) * static_cast<FLOAT32>(2);
				if (x.w < static_cast<FLOAT32>(0))
					return pi<FLOAT32>() * static_cast<FLOAT32>(2) - a;
				return a;
			}

			return acos(x.w) * static_cast<FLOAT32>(2);
		}

		
		static Vector3 axis(qua<FLOAT32, Q> const& x)
		{
			FLOAT32 const tmp1 = static_cast<FLOAT32>(1) - x.w * x.w;
			if (tmp1 <= static_cast<FLOAT32>(0))
				return vec<3, FLOAT32, Q>(0, 0, 1);
			FLOAT32 const tmp2 = static_cast<FLOAT32>(1) / sqrt(tmp1);
			return vec<3, FLOAT32, Q>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
		}
		*/

		NO_DISCARD FORCE_INLINE static FLOAT32 angle(const Quaternion& x)
		{
			if (math::Abs(x.w) > 0.877582561890372716130286068203503191)
			{
				FLOAT32 const a = math::asin(math::sqrt(x.x * x.x + x.y * x.y + x.z * x.z)) * static_cast<FLOAT32>(2);
				if (x.w < static_cast<FLOAT32>(0))
				{
					return static_cast<FLOAT32>(math::PI) * static_cast<FLOAT32>(2) - a;
				}
				return a;
			}

			return acos(x.w) * static_cast<FLOAT32>(2);
		}
		
		NO_DISCARD FORCE_INLINE Vector3 axis(const Quaternion& x)
		{
			FLOAT32 const tmp1 = static_cast<FLOAT32>(1) - x.w * x.w;
			if (tmp1 <= static_cast<FLOAT32>(0))
				return Vector3(0, 0, 1);
			FLOAT32 const tmp2 = static_cast<FLOAT32>(1) / sqrt(tmp1);
			return Vector3(x.x * tmp2, x.y * tmp2, x.z * tmp2);
		}

		static Quaternion angleAxis(const FLOAT32& angle, const Vector3& v);

		template<typename X, typename Y>
		static Quaternion angleAxis(const X& angle, const Vector3& v)
		{
			const FLOAT32 a{ angle };
			const FLOAT32 s{ std::sin(a * static_cast<FLOAT32>(0.5)) };

			return Quaternion(std::cos(a * static_cast<FLOAT32>(0.5)), v * s);
		}
		
		static Quaternion EulerAngleToQuaternion(const Vector3& eulerAngle) noexcept;


		static FLOAT32 roll(const Quaternion& q);


		static FLOAT32 pitch(const Quaternion& q);


		static FLOAT32 yaw(const Quaternion& q)
		{
			return std::asin(::math::clamp(static_cast<FLOAT32>(-2) * (q.x * q.z - q.w * q.y), static_cast<FLOAT32>(-1), static_cast<FLOAT32>(1)));
		}

		
		static Vector3 QuaternionToEulerAngle(const Quaternion& x);
		
		static Quaternion quatLookAt(const math::Vector3& direction, const math::Vector3& up);
		
	};

	
	extern NO_DISCARD FORCE_INLINE FLOAT32 dot(const Quaternion& a, const Quaternion& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	
	extern NO_DISCARD FORCE_INLINE Quaternion cross(const Quaternion& q1, const Quaternion& q2)
	{
		return Quaternion(
			q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
			q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
			q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
			q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x);
	}
	
	extern NO_DISCARD FORCE_INLINE  Quaternion conjugate(const Quaternion& q)
	{
		return Quaternion(q.w, -q.x, -q.y, -q.z);
	}

	extern NO_DISCARD FORCE_INLINE  Quaternion operator/(const Quaternion& q, const FLOAT32 s)
	{
		return Quaternion(
			q.w / s, q.x / s, q.y / s, q.z / s);
	}

	extern NO_DISCARD FORCE_INLINE  Quaternion inverse(const Quaternion& q)
	{
		return operator/(conjugate(q), dot(q, q));
	}



	
	extern NO_DISCARD FORCE_INLINE Quaternion operator+(const Quaternion& vector) noexcept
	{
		return Quaternion{ vector };
	}

	
	extern NO_DISCARD FORCE_INLINE Quaternion operator-(const Quaternion& vector) noexcept
	{
		return Quaternion(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w);
	}


	//
	
	extern NO_DISCARD FORCE_INLINE Vector3 operator*(const Quaternion& q, const Vector3& v);


	extern NO_DISCARD FORCE_INLINE  Vector4 operator*(const Quaternion& q, const Vector4& v);

	extern NO_DISCARD FORCE_INLINE  Vector4 operator*(const Vector4& v, const Quaternion& q)
	{
		return inverse(q) * v;
	}
	
	extern NO_DISCARD FORCE_INLINE  Quaternion operator*(const Quaternion& q, const FLOAT32 s)
	{
		return Quaternion(
			q.w * s, q.x * s, q.y * s, q.z * s);
	}
	
	extern NO_DISCARD FORCE_INLINE  Quaternion operator*(const FLOAT32 s, const Quaternion& q)
	{
		return q * s;
	}
	

	template<typename T>
	extern NO_DISCARD FORCE_INLINE  Quaternion lerp(const Quaternion& x, const Quaternion& y, T a)
	{
		static_assert(std::is_same_v<T, FLOAT32> || std::is_same_v<T, FLOAT64>);

		// Lerp is only defined in [0, 1]
		assert(a >= static_cast<T>(0));
		assert(a <= static_cast<T>(1));

		return x * (static_cast<FLOAT32>(1) - a) + (y * a);
	}

	template<typename T>
	extern NO_DISCARD FORCE_INLINE  Quaternion slerp(const Quaternion& x, const Quaternion& y, T a)
	{
		static_assert(std::is_same_v<T, FLOAT32> || std::is_same_v<T, FLOAT64>);

		Quaternion z = y;

		T cosTheta = dot(x, y);

		// If cosTheta < 0, the interpolation will take the long way around the sphere.
		// To fix this, one quat must be negated.
		if (cosTheta < static_cast<T>(0))
		{
			z = -y;
			cosTheta = -cosTheta;
		}

		// Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
		if (cosTheta > static_cast<T>(1) - math::epsilon<T>()())
		{
			// Linear interpolation
			return Quaternion(
				math::lerp(x.w, z.w, a),
				math::lerp(x.x, z.x, a),
				math::lerp(x.y, z.y, a),
				math::lerp(x.z, z.z, a));
		}
		else
		{
			// Essential Mathematics, page 467
			T angle = math::acos(cosTheta);
			return (math::sin((static_cast<T>(1) - a) * angle) * x + math::sin(a * angle) * z) / math::sin(angle);
		}
	}
	
}
