#pragma once

#include "ErrorHandling.h"
#include "LMath_Core.h"

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
		D_PROPERTY()
		Vector4 value;

		FORCE_INLINE FLOAT32* data() noexcept
		{
			return value.data();
		}

		FORCE_INLINE const FLOAT32* data() const noexcept
		{
			return value.data();
		}

		Quaternion() noexcept = delete;

		FORCE_INLINE Quaternion(int*) : value{nullptr}
		{}

		FORCE_INLINE explicit Quaternion(FLOAT32 value) noexcept
			: value{ value , value , value , value }
		{
		}

		FORCE_INLINE Quaternion(FLOAT32 xValue, FLOAT32 yValue, FLOAT32 zValue, FLOAT32 wValue) noexcept
			: value{ xValue , yValue , zValue , wValue }
		{
		}

		template <typename X, typename Y, typename Z, typename W>
		Quaternion(X xValue, Y yValue, Z zValue, W wValue) noexcept
			: value{ static_cast<FLOAT32>(xValue) , static_cast<FLOAT32>(yValue) , static_cast<FLOAT32>(zValue) , static_cast<FLOAT32>(wValue) }
		{
		}

		FORCE_INLINE Quaternion(const Quaternion& quat) noexcept
			: value{ quat.value }
		{
		}

		
		Quaternion(FLOAT32 s, const Vector3& vector) noexcept;
		
		FORCE_INLINE explicit Quaternion(const Vector3& eulerAngle) noexcept : value(nullptr)
		{
			*this = type::EulerAngleToQuaternion(eulerAngle);
		}

		static type mat2Quaternion(const Matrix3x3& m);

		explicit Quaternion(const Matrix3x3& m) noexcept : value(nullptr)
		{
			*this = mat2Quaternion(m);
		}

		explicit Quaternion(const Matrix4x4& m) noexcept;

		FORCE_INLINE type& operator=(const type& vector) noexcept
		{
			value = vector.value;
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
			return value[i];
		}

		NO_DISCARD FORCE_INLINE const value_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < componentCount());
			return value[i];
		}

		
		FORCE_INLINE type& operator+=(const Quaternion& rhs) noexcept
		{
			value.x += rhs.value.x;
			value.y += rhs.value.y;
			value.z += rhs.value.z;
			value.w += rhs.value.w;
			return *this;
		}
		
		FORCE_INLINE type& operator-=(const Quaternion& rhs) noexcept
		{
			value.x -= rhs.value.x;
			value.y -= rhs.value.y;
			value.z -= rhs.value.z;
			value.w -= rhs.value.w;
			return *this;
		}


		FORCE_INLINE type& operator*=(const Quaternion& rhs) noexcept
		{
			const Quaternion p(*this);
			const Quaternion q(rhs);

			this->value.w = p.value.w * q.value.w - p.value.x * q.value.x - p.value.y * q.value.y - p.value.z * q.value.z;
			this->value.x = p.value.w * q.value.x + p.value.x * q.value.w + p.value.y * q.value.z - p.value.z * q.value.y;
			this->value.y = p.value.w * q.value.y + p.value.y * q.value.w + p.value.z * q.value.x - p.value.x * q.value.z;
			this->value.z = p.value.w * q.value.z + p.value.z * q.value.w + p.value.x * q.value.y - p.value.y * q.value.x;
			return *this;
		}
		
		FORCE_INLINE type& operator/=(const Quaternion& rhs) noexcept
		{
			value.x /= rhs.value.x;
			value.y /= rhs.value.y;
			value.z /= rhs.value.z;
			value.w /= rhs.value.w;
			return *this;
		}
		
		FORCE_INLINE type operator+(const Quaternion& rhs) noexcept
		{
			return *this + rhs;
		}


		FORCE_INLINE type operator-(const Quaternion& rhs) noexcept
		{
			return *this - rhs;
		}

		FORCE_INLINE type operator*(const Quaternion& rhs) noexcept
		{
			Quaternion result{ nullptr };

			result.value.w = this->value.w * rhs.value.w - this->value.x * rhs.value.x - this->value.y * rhs.value.y - this->value.z * rhs.value.z;
			result.value.x = this->value.w * rhs.value.x + this->value.x * rhs.value.w + this->value.y * rhs.value.z - this->value.z * rhs.value.y;
			result.value.y = this->value.w * rhs.value.y + this->value.y * rhs.value.w + this->value.z * rhs.value.x - this->value.x * rhs.value.z;
			result.value.z = this->value.w * rhs.value.z + this->value.z * rhs.value.w + this->value.x * rhs.value.y - this->value.y * rhs.value.x;

			return type{ result };
		}
		
		FORCE_INLINE type operator/(const Quaternion& rhs)
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

		NO_DISCARD FORCE_INLINE bool operator==(const type& rhs) noexcept
		{
			return this->value.x == rhs.value.x && this->value.y == rhs.value.y && this->value.z == rhs.value.z && this->value.w == rhs.value.w;
		}

		NO_DISCARD FORCE_INLINE bool operator!=(const type& rhs) noexcept
		{
			return this->value.x != rhs.value.x || this->value.y != rhs.value.y || this->value.z != rhs.value.z || this->value.w != rhs.value.w;
		}

		template <typename X>
		NO_DISCARD FORCE_INLINE bool operator==(const X& number) noexcept
		{
			return this->value.x == number && this->value.y == number && this->value.z == number && this->value.w == number;
		}

		template <typename X>
		NO_DISCARD FORCE_INLINE bool operator!=(const X& number) noexcept
		{
			return this->value.x != number || this->value.y != number || this->value.z != number || this->value.w != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator++() noexcept
		{
			++value.x;
			++value.y;
			++value.z;
			++value.w;
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
			--value.x;
			--value.y;
			--value.z;
			--value.w;
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
			return std::asin(::math::clamp(static_cast<FLOAT32>(-2) * (q.value.x * q.value.z - q.value.w * q.value.y), static_cast<FLOAT32>(-1), static_cast<FLOAT32>(1)));
		}

		
		static Vector3 QuaternionToEulerAngle(const Quaternion& x);
		
		static Quaternion quatLookAt(const math::Vector3& direction, const math::Vector3& up);
	};

	
	FORCE_INLINE extern FLOAT32 dot(const Quaternion& a, const Quaternion& b)
	{
		return a.value.x * b.value.x + a.value.y * b.value.y + a.value.z * b.value.z + a.value.w * b.value.w;
	}

	
	FORCE_INLINE extern Quaternion cross(const Quaternion& q1, const Quaternion& q2)
	{
		return Quaternion(
			q1.value.w * q2.value.w - q1.value.x * q2.value.x - q1.value.y * q2.value.y - q1.value.z * q2.value.z,
			q1.value.w * q2.value.x + q1.value.x * q2.value.w + q1.value.y * q2.value.z - q1.value.z * q2.value.y,
			q1.value.w * q2.value.y + q1.value.y * q2.value.w + q1.value.z * q2.value.x - q1.value.x * q2.value.z,
			q1.value.w * q2.value.z + q1.value.z * q2.value.w + q1.value.x * q2.value.y - q1.value.y * q2.value.x);
	}
	
	FORCE_INLINE extern Quaternion conjugate(const Quaternion& q)
	{
		return Quaternion(q.value.w, -q.value.x, -q.value.y, -q.value.z);
	}

	FORCE_INLINE extern Quaternion operator/(const Quaternion& q, const FLOAT32 s)
	{
		return Quaternion(
			q.value.w / s, q.value.x / s, q.value.y / s, q.value.z / s);
	}

	FORCE_INLINE extern Quaternion inverse(const Quaternion& q)
	{
		return operator/(conjugate(q), dot(q, q));
	}



	
	FORCE_INLINE extern Quaternion operator+(const Quaternion& vector) noexcept
	{
		return Quaternion{ vector };
	}

	
	FORCE_INLINE extern Quaternion operator-(const Quaternion& vector) noexcept
	{
		return Quaternion(
			-vector.value.x,
			-vector.value.y,
			-vector.value.z,
			-vector.value.w);
	}


	//
	
	FORCE_INLINE extern Vector3 operator*(const Quaternion& q, const Vector3& v);


	FORCE_INLINE extern Vector4 operator*(const Quaternion& q, const Vector4& v);

	FORCE_INLINE extern Vector4 operator*(const Vector4& v, const Quaternion& q)
	{
		return inverse(q) * v;
	}
	
	FORCE_INLINE extern Quaternion operator*(const Quaternion& q, const FLOAT32 s)
	{
		return Quaternion(
			q.value.w * s, q.value.x * s, q.value.y * s, q.value.z * s);
	}
	
	FORCE_INLINE extern Quaternion operator*(const FLOAT32 s, const Quaternion& q)
	{
		return q * s;
	}


	FORCE_INLINE extern Quaternion operator*(const Quaternion& p, const Quaternion& q)
	{
		Quaternion result{ nullptr };

		result.value.w = p.value.w * q.value.w - p.value.x * q.value.x - p.value.y * q.value.y - p.value.z * q.value.z;
		result.value.x = p.value.w * q.value.x + p.value.x * q.value.w + p.value.y * q.value.z - p.value.z * q.value.y;
		result.value.y = p.value.w * q.value.y + p.value.y * q.value.w + p.value.z * q.value.x - p.value.x * q.value.z;
		result.value.z = p.value.w * q.value.z + p.value.z * q.value.w + p.value.x * q.value.y - p.value.y * q.value.x;

		return Quaternion{ result };
	}
	
	
	
	
}
