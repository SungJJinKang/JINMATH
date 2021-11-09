#pragma once

#include "Vector.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Matrix3x3.h"
#include "Matrix4x4.h"

#include "Utility.h"

namespace math
{
	struct Quaternion
	{
		using value_type = typename FLOAT32;
		using type = typename Quaternion;

		_Vector4<FLOAT32> value;

		Quaternion() noexcept : value{ 0,0,0,1.0f }
		{

		}
	
		Quaternion(FLOAT32 value) noexcept
			: value{ value , value , value , value }
		{
		}

		Quaternion(FLOAT32 xValue, FLOAT32 yValue, FLOAT32 zValue, FLOAT32 wValue) noexcept
			: value{ xValue , yValue , zValue , wValue }
		{
		}

		template <typename X, typename Y, typename Z, typename W>
		Quaternion(X xValue, Y yValue, Z zValue, W wValue) noexcept
			: value{ static_cast<FLOAT32>(xValue) , static_cast<FLOAT32>(yValue) , static_cast<FLOAT32>(zValue) , static_cast<FLOAT32>(wValue) }
		{
		}

		Quaternion(const Quaternion& quat) noexcept
			: value{ quat.value }
		{
		}

		
		Quaternion(FLOAT32 s, const _Vector3<FLOAT32>& vector) noexcept
			: value{ vector.x, vector.y, vector.z, s }
		{
		}


		template <typename X, typename Y>
		Quaternion(X s, const _Vector3<Y>& vector) noexcept
			: value{ static_cast<FLOAT32>(vector.x), static_cast<FLOAT32>(vector.y), static_cast<FLOAT32>(vector.z), static_cast<FLOAT32>(s) }
		{
		}

		Quaternion(const _Vector3<FLOAT32>& eulerAngle) noexcept
		{
			*this = type::eulerAngle(eulerAngle);
		}

		static type mat2Quaternion(const _Matrix3x3<FLOAT32>& m)
		{
			FLOAT32 fourXSquaredMinus1 = m[0][0] - m[1][1] - m[2][2];
			FLOAT32 fourYSquaredMinus1 = m[1][1] - m[0][0] - m[2][2];
			FLOAT32 fourZSquaredMinus1 = m[2][2] - m[0][0] - m[1][1];
			FLOAT32 fourWSquaredMinus1 = m[0][0] + m[1][1] + m[2][2];

			INT32 biggestIndex = 0;
			FLOAT32 fourBiggestSquaredMinus1 = fourWSquaredMinus1;
			if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
			{
				fourBiggestSquaredMinus1 = fourXSquaredMinus1;
				biggestIndex = 1;
			}
			if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
			{
				fourBiggestSquaredMinus1 = fourYSquaredMinus1;
				biggestIndex = 2;
			}
			if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
			{
				fourBiggestSquaredMinus1 = fourZSquaredMinus1;
				biggestIndex = 3;
			}

			FLOAT32 biggestVal = static_cast<FLOAT32>(math::sqrt(fourBiggestSquaredMinus1 + static_cast<FLOAT32>(1)) * static_cast<FLOAT32>(0.5));
			FLOAT32 mult = static_cast<FLOAT32>(0.25) / biggestVal;

			switch (biggestIndex)
			{
			case 0:
				return Quaternion(biggestVal, (m[1][2] - m[2][1]) * mult, (m[2][0] - m[0][2]) * mult, (m[0][1] - m[1][0]) * mult);
			case 1:
				return Quaternion((m[1][2] - m[2][1]) * mult, biggestVal, (m[0][1] + m[1][0]) * mult, (m[2][0] + m[0][2]) * mult);
			case 2:
				return Quaternion((m[2][0] - m[0][2]) * mult, (m[0][1] + m[1][0]) * mult, biggestVal, (m[1][2] + m[2][1]) * mult);
			case 3:
				return Quaternion((m[0][1] - m[1][0]) * mult, (m[2][0] + m[0][2]) * mult, (m[1][2] + m[2][1]) * mult, biggestVal);
			default: // Silence a -Wswitch-default warning in GCC. Should never actually get here. Assert is just for sanity.
				assert(false);
				return Quaternion(1, 0, 0, 0);
			}
		}

		explicit Quaternion(const _Matrix3x3<FLOAT32>& m) noexcept
		{
			mat2Quaternion(m);
		}

		explicit Quaternion(const _Matrix4x4<FLOAT32>& m) noexcept
		{
			mat2Quaternion(m);
		}

		FORCE_INLINE type& operator=(const type& vector) noexcept
		{
			value = vector.value;
			return *this;
		}

	
		FORCE_INLINE type& operator=(const _Matrix4x4<FLOAT32>& m) noexcept
		{
			mat2Quaternion(m);
			return *this;
		}

		FORCE_INLINE type& operator=(const _Matrix3x3<FLOAT32>& m) noexcept
		{
			mat2Quaternion(m);
			return *this;
		}

		FORCE_INLINE type& operator=(const _Vector3<FLOAT32>& eulerAngle) noexcept
		{
			*this = type::eulerAngle(eulerAngle);
			return *this;
		} 


		// 		Quaternion(const type&) = default;
		// 		Quaternion(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		std::basic_string<char> toString() noexcept
		{
			std::stringstream ss;
			ss << value.x << "  " << value.y << "  " << value.z << "  " << value.w;
			return ss.str();
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
			Quaternion result;

			result.value.w = this->value.w * rhs.value.w - this->value.x * rhs.value.x - this->value.y * rhs.value.y - this->value.z * rhs.value.z;
			result.value.x = this->value.w * rhs.value.x + this->value.x * rhs.value.w + this->value.y * rhs.value.z - this->value.z * rhs.value.y;
			result.value.y = this->value.w * rhs.value.y + this->value.y * rhs.value.w + this->value.z * rhs.value.x - this->value.x * rhs.value.z;
			result.value.z = this->value.w * rhs.value.z + this->value.z * rhs.value.w + this->value.x * rhs.value.y - this->value.y * rhs.value.x;

			return result;
		}
		
		FORCE_INLINE type operator/(const Quaternion& rhs)
		{
			return *this / rhs;
		}

		/*
		static _Matrix3x3<FLOAT32> convert_quaternion_to_matrix(const Quaternion& quaternion)
		{

		}
		*/

		inline operator _Matrix3x3<FLOAT32>() const noexcept
		{
			_Matrix3x3<FLOAT32> Result(FLOAT32(1));
			FLOAT32 qxx(this->value.x * this->value.x);
			FLOAT32 qyy(this->value.y * this->value.y);
			FLOAT32 qzz(this->value.z * this->value.z);
			FLOAT32 qxz(this->value.x * this->value.z);
			FLOAT32 qxy(this->value.x * this->value.y);
			FLOAT32 qyz(this->value.y * this->value.z);
			FLOAT32 qwx(this->value.w * this->value.x);
			FLOAT32 qwy(this->value.w * this->value.y);
			FLOAT32 qwz(this->value.w * this->value.z);

			Result[0][0] = FLOAT32(1) - FLOAT32(2) * (qyy + qzz);
			Result[0][1] = FLOAT32(2) * (qxy + qwz);
			Result[0][2] = FLOAT32(2) * (qxz - qwy);

			Result[1][0] = FLOAT32(2) * (qxy - qwz);
			Result[1][1] = FLOAT32(1) - FLOAT32(2) * (qxx + qzz);
			Result[1][2] = FLOAT32(2) * (qyz + qwx);

			Result[2][0] = FLOAT32(2) * (qxz + qwy);
			Result[2][1] = FLOAT32(2) * (qyz - qwx);
			Result[2][2] = FLOAT32(1) - FLOAT32(2) * (qxx + qyy);
			return Result;
		}

		inline operator _Matrix4x4<FLOAT32>() const noexcept
		{
			return _Matrix4x4<FLOAT32>(this->operator math::_Matrix3x3<FLOAT32>());
		}

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
			return Quaternion;
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

		operator std::basic_string<char>() noexcept
		{
			return this->toString();
		}

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

		
		static _Vector3<FLOAT32> axis(qua<FLOAT32, Q> const& x)
		{
			FLOAT32 const tmp1 = static_cast<FLOAT32>(1) - x.w * x.w;
			if (tmp1 <= static_cast<FLOAT32>(0))
				return vec<3, FLOAT32, Q>(0, 0, 1);
			FLOAT32 const tmp2 = static_cast<FLOAT32>(1) / sqrt(tmp1);
			return vec<3, FLOAT32, Q>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
		}
		*/

		static Quaternion angleAxis(const FLOAT32& angle, const _Vector3<FLOAT32>& v)
		{
			const FLOAT32 a{ angle };
			const FLOAT32 s{ math::sin(a * static_cast<FLOAT32>(0.5)) };

			return Quaternion(math::cos(a * static_cast<FLOAT32>(0.5)), v * s);
		}

		template<typename X, typename Y>
		static Quaternion angleAxis(const X& angle, const _Vector3<Y>& v)
		{
			const FLOAT32 a{ angle };
			const FLOAT32 s{ math::sin(a * static_cast<FLOAT32>(0.5)) };

			return Quaternion(math::cos(a * static_cast<FLOAT32>(0.5)), v * s);
		}

		static Quaternion eulerAngle(const _Vector3<FLOAT32>& eulerAngle) noexcept
		{
			_Vector3<FLOAT32> c = math::cos(eulerAngle * FLOAT32(0.5));
			_Vector3<FLOAT32> s = math::sin(eulerAngle * FLOAT32(0.5));

			return Quaternion
			{
				s.x* c.y* c.z - c.x * s.y * s.z,
				c.x* s.y* c.z + s.x * c.y * s.z,
				c.x* c.y* s.z - s.x * s.y * c.z,
				c.x* c.y* c.z + s.x * s.y * s.z
			};
		}

		template<typename X>
		static Quaternion EulerAngleToQuaternion(const _Vector3<X>& eulerAngle) noexcept
		{
			_Vector3<FLOAT32> c = math::cos(eulerAngle * FLOAT32(0.5));
			_Vector3<FLOAT32> s = math::sin(eulerAngle * FLOAT32(0.5));

			return Quaternion
			{
				s.x * c.y * c.z - c.x * s.y * s.z,
				c.x * s.y * c.z + s.x * c.y * s.z,
				c.x * c.y * s.z - s.x * s.y * c.z,
				c.x * c.y * c.z + s.x * s.y * s.z
			};
		}


		
		static FLOAT32 roll(const Quaternion& q)
		{
			const FLOAT32 y = static_cast<FLOAT32>(2) * (q.value.x * q.value.y + q.value.w * q.value.z);
			const FLOAT32 x = q.value.w * q.value.w + q.value.x * q.value.x - q.value.y * q.value.y - q.value.z * q.value.z;

			FLOAT32 epsilon = math::epsilon<FLOAT32>();
			if (_Vector2<FLOAT32>(x, y) == epsilon && _Vector2<FLOAT32>(0.0f) == epsilon) //avoid atan2(0,0) - handle singularity - Matiis
			{
				return static_cast<FLOAT32>(0);
			}
			return static_cast<FLOAT32>(math::atan2(y, x));
		}

		
		static FLOAT32 pitch(const Quaternion& q)
		{
			//return FLOAT32(atan(FLOAT32(2) * (q.value.y * q.value.z + q.value.w * q.value.x).w * q.value.w - q.value.x * q.value.x - q.value.y * q.value.y + q.value.z * q.value.z));
			const FLOAT32 y = static_cast<FLOAT32>(2) * (q.value.y * q.value.z + q.value.w * q.value.x);
			const FLOAT32 x = q.value.w * q.value.w - q.value.x * q.value.x - q.value.y * q.value.y + q.value.z * q.value.z;

			FLOAT32 epsilon = math::epsilon<FLOAT32>();
			if (_Vector2<FLOAT32>(x, y) == epsilon && _Vector2<FLOAT32>(0.0f) == epsilon) //avoid atan2(0,0) - handle singularity - Matiis
			{
				return static_cast<FLOAT32>(static_cast<FLOAT32>(2) * math::atan2(q.value.x, q.value.w));
			}

			return static_cast<FLOAT32>(math::atan2(y, x));
		}

		
		static FLOAT32 yaw(const Quaternion& q)
		{
			return math::asin(math::clamp(static_cast<FLOAT32>(-2) * (q.value.x * q.value.z - q.value.w * q.value.y), static_cast<FLOAT32>(-1), static_cast<FLOAT32>(1)));
		}

		
		static _Vector3<FLOAT32> QuaternionToEulerAngle(const Quaternion& x)
		{
			return _Vector3<FLOAT32>(Quaternion::pitch(x), Quaternion::yaw(x), Quaternion::roll(x));
		}
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
		return vector;
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
	
	FORCE_INLINE extern _Vector3<FLOAT32> operator*(const Quaternion& q, const _Vector3<FLOAT32>& v)
	{
		const _Vector3<FLOAT32> QuatVector(q.value.x, q.value.y, q.value.z);
		const _Vector3<FLOAT32> uv(cross(QuatVector, v));
		const _Vector3<FLOAT32> uuv(cross(QuatVector, uv));

		return v + ((uv * q.value.w) + uuv) * static_cast<FLOAT32>(2);
	}
	

	FORCE_INLINE extern _Vector4<FLOAT32> operator*(const Quaternion& q, const _Vector4<FLOAT32>& v)
	{
		return _Vector4<FLOAT32>(q * _Vector3<FLOAT32>(v), v.w);
	}
	
	FORCE_INLINE extern _Vector4<FLOAT32> operator*(const _Vector4<FLOAT32>& v, const Quaternion& q)
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
		Quaternion result;

		result.value.w = p.value.w * q.value.w - p.value.x * q.value.x - p.value.y * q.value.y - p.value.z * q.value.z;
		result.value.x = p.value.w * q.value.x + p.value.x * q.value.w + p.value.y * q.value.z - p.value.z * q.value.y;
		result.value.y = p.value.w * q.value.y + p.value.y * q.value.w + p.value.z * q.value.x - p.value.x * q.value.z;
		result.value.z = p.value.w * q.value.z + p.value.z * q.value.w + p.value.x * q.value.y - p.value.y * q.value.x;

		return result;
	}
	
	

}

