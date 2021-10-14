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

		Vector<4, FLOAT32> value;

		constexpr Quaternion() noexcept : value{ 0,0,0,1.0f }
		{

		}
	
		constexpr Quaternion(FLOAT32 value) noexcept
			: value{ value , value , value , value }
		{
		}

		template <typename X>
		constexpr Quaternion(X xValue) noexcept
			: value{ static_cast<FLOAT32>(value) , static_cast<FLOAT32>(value) , static_cast<FLOAT32>(value) , static_cast<FLOAT32>(value) }
		{
		}

		constexpr Quaternion(FLOAT32 xValue, FLOAT32 yValue, FLOAT32 zValue, FLOAT32 wValue) noexcept
			: value{ xValue , yValue , zValue , wValue }
		{
		}

		template <typename X, typename Y, typename Z, typename W>
		constexpr Quaternion(X xValue, Y yValue, Z zValue, W wValue) noexcept
			: value{ static_cast<FLOAT32>(xValue) , static_cast<FLOAT32>(yValue) , static_cast<FLOAT32>(zValue) , static_cast<FLOAT32>(wValue) }
		{
		}

		constexpr explicit Quaternion(const type& vector) noexcept
			: value{ vector.value }
		{
		}

		template <typename X>
		constexpr Quaternion(const Quaternion<X>& vector) noexcept
			: value{ vector.value }
		{
		}

		constexpr Quaternion(FLOAT32 s, const Vector<3, FLOAT32>& vector) noexcept
			: value{ vector.x, vector.y, vector.z, s }
		{
		}


		template <typename X, typename Y>
		constexpr Quaternion(X s, const Vector<3, Y>& vector) noexcept
			: value{ static_cast<FLOAT32>(vector.x), static_cast<FLOAT32>(vector.y), static_cast<FLOAT32>(vector.z), static_cast<FLOAT32>(s) }
		{
		}

		constexpr Quaternion(const Vector<3, FLOAT32>& eulerAngle) noexcept
		{
			*this = type::eulerAngle(eulerAngle);
		}

		static constexpr type mat2Quaternion(const Matrix<3, 3, FLOAT32>& m)
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
				return Quaternion<FLOAT32>(biggestVal, (m[1][2] - m[2][1]) * mult, (m[2][0] - m[0][2]) * mult, (m[0][1] - m[1][0]) * mult);
			case 1:
				return Quaternion<FLOAT32>((m[1][2] - m[2][1]) * mult, biggestVal, (m[0][1] + m[1][0]) * mult, (m[2][0] + m[0][2]) * mult);
			case 2:
				return Quaternion<FLOAT32>((m[2][0] - m[0][2]) * mult, (m[0][1] + m[1][0]) * mult, biggestVal, (m[1][2] + m[2][1]) * mult);
			case 3:
				return Quaternion<FLOAT32>((m[0][1] - m[1][0]) * mult, (m[2][0] + m[0][2]) * mult, (m[1][2] + m[2][1]) * mult, biggestVal);
			default: // Silence a -Wswitch-default warning in GCC. Should never actually get here. Assert is just for sanity.
				assert(false);
				return Quaternion<FLOAT32>(1, 0, 0, 0);
			}
		}

		constexpr explicit Quaternion(const Matrix<3, 3, FLOAT32>& m) noexcept
		{
			mat2Quaternion(m);
		}

		constexpr explicit Quaternion(const Matrix<4, 4, FLOAT32>& m) noexcept
		{
			mat2Quaternion(m);
		}

		FORCE_INLINE constexpr type& operator=(const type& vector) noexcept
		{
			value = vector.value;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Quaternion<X>& vector) noexcept
		{
			value = vector.value;
			return *this;
		}

		FORCE_INLINE constexpr type& operator=(const Matrix<4, 4, FLOAT32>& m) noexcept
		{
			mat2Quaternion(m);
			return *this;
		}

		FORCE_INLINE constexpr type& operator=(const Matrix<3, 3, FLOAT32>& m) noexcept
		{
			mat2Quaternion(m);
			return *this;
		}

		FORCE_INLINE constexpr type& operator=(const Vector<3, FLOAT32>& eulerAngle) noexcept
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

		[[nodiscard]] inline static constexpr SIZE_T componentCount()  noexcept { return 4; }

		[[nodiscard]] value_type& operator[](SIZE_T i)
		{
			assert(i >= 0 || i < componentCount());
			return value[i];
		}

		[[nodiscard]] FORCE_INLINE constexpr const value_type& operator[](SIZE_T i) const
		{
			assert(i >= 0 || i < componentCount());
			return value[i];
		}


		template <typename X>
		FORCE_INLINE constexpr type& operator+=(const Quaternion<X>& rhs) noexcept
		{
			value.x += rhs.x;
			value.y += rhs.y;
			value.z += rhs.z;
			value.w += rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator-=(const Quaternion<X>& rhs) noexcept
		{
			value.x -= rhs.x;
			value.y -= rhs.y;
			value.z -= rhs.z;
			value.w -= rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator*=(const Quaternion<X>& rhs) noexcept
		{
			const Quaternion<FLOAT32> p(*this);
			const Quaternion<FLOAT32> q(rhs);

			this->value.w = p.value.w * q.value.w - p.value.x * q.value.x - p.value.y * q.value.y - p.value.z * q.value.z;
			this->value.x = p.value.w * q.value.x + p.value.x * q.value.w + p.value.y * q.value.z - p.value.z * q.value.y;
			this->value.y = p.value.w * q.value.y + p.value.y * q.value.w + p.value.z * q.value.x - p.value.x * q.value.z;
			this->value.z = p.value.w * q.value.z + p.value.z * q.value.w + p.value.x * q.value.y - p.value.y * q.value.x;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator/=(const Quaternion<X>& rhs) noexcept
		{
			value.x /= rhs.x;
			value.y /= rhs.y;
			value.z /= rhs.z;
			value.w /= rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type operator+(const Quaternion<X>& rhs) noexcept
		{
			return *this += rhs;
		}

		template <typename X>
		FORCE_INLINE constexpr type operator-(const Quaternion<X>& rhs) noexcept
		{
			return *this -= rhs;
		}

		template <typename X>
		FORCE_INLINE constexpr type operator*(const Quaternion<X>& rhs) noexcept
		{
			return *this *= rhs;
		}

		template <typename X>
		FORCE_INLINE constexpr type operator/(const Quaternion<X>& rhs)
		{
			return *this /= rhs;
		}

		/*
		static Matrix<3, 3, FLOAT32> convert_quaternion_to_matrix(const Quaternion& quaternion)
		{

		}
		*/

		inline operator Matrix<3, 3, FLOAT32>() const noexcept
		{
			Matrix<3, 3, FLOAT32> Result(FLOAT32(1));
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

		inline operator Matrix<4, 4, FLOAT32>() const noexcept
		{
			return Matrix<4, 4, FLOAT32>(this->operator math::Matrix<3, 3, FLOAT32>());
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(const type& rhs) noexcept
		{
			return this->value.x == rhs.value.x && this->value.y == rhs.value.y && this->value.z == rhs.value.z && this->value.w == rhs.value.w;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(const type& rhs) noexcept
		{
			return this->value.x != rhs.value.x || this->value.y != rhs.value.y || this->value.z != rhs.value.z || this->value.w != rhs.value.w;
		}

		template <typename X>
		[[nodiscard]] FORCE_INLINE constexpr bool operator==(const X& number) noexcept
		{
			return this->value.x == number && this->value.y == number && this->value.z == number && this->value.w == number;
		}

		template <typename X>
		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(const X& number) noexcept
		{
			return this->value.x != number || this->value.y != number || this->value.z != number || this->value.w != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator++() noexcept
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
		FORCE_INLINE constexpr type operator++(INT32) noexcept
		{
			type Quaternion{ *this };
			++* this;
			return Quaternion;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator--() noexcept
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
		FORCE_INLINE constexpr type operator--(INT32) noexcept
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
		template<typename FLOAT32>
		static FLOAT32 angle(Quaternion<FLOAT32> const& x)
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

		template<typename FLOAT32>
		static Vector<3, FLOAT32> axis(qua<FLOAT32, Q> const& x)
		{
			FLOAT32 const tmp1 = static_cast<FLOAT32>(1) - x.w * x.w;
			if (tmp1 <= static_cast<FLOAT32>(0))
				return vec<3, FLOAT32, Q>(0, 0, 1);
			FLOAT32 const tmp2 = static_cast<FLOAT32>(1) / sqrt(tmp1);
			return vec<3, FLOAT32, Q>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
		}
		*/

		static Quaternion<FLOAT32> angleAxis(const FLOAT32& angle, const Vector<3, FLOAT32>& v)
		{
			const FLOAT32 a{ angle };
			const FLOAT32 s{ math::sin(a * static_cast<FLOAT32>(0.5)) };

			return Quaternion<FLOAT32>(math::cos(a * static_cast<FLOAT32>(0.5)), v * s);
		}

		template<typename X, typename Y>
		static Quaternion<FLOAT32> angleAxis(const X& angle, const Vector<3, Y>& v)
		{
			const FLOAT32 a{ angle };
			const FLOAT32 s{ math::sin(a * static_cast<FLOAT32>(0.5)) };

			return Quaternion<FLOAT32>(math::cos(a * static_cast<FLOAT32>(0.5)), v * s);
		}

		static Quaternion<FLOAT32> eulerAngle(const Vector<3, FLOAT32>& eulerAngle) noexcept
		{
			Vector<3, FLOAT32> c = math::cos(eulerAngle * FLOAT32(0.5));
			Vector<3, FLOAT32> s = math::sin(eulerAngle * FLOAT32(0.5));

			return Quaternion<FLOAT32>
			{
				s.x* c.y* c.z - c.x * s.y * s.z,
				c.x* s.y* c.z + s.x * c.y * s.z,
				c.x* c.y* s.z - s.x * s.y * c.z,
				c.x* c.y* c.z + s.x * s.y * s.z
			};
		}

		template<typename X>
		static Quaternion<FLOAT32> EulerAngleToQuaternion(const Vector<3, X>& eulerAngle) noexcept
		{
			Vector<3, FLOAT32> c = math::cos(eulerAngle * FLOAT32(0.5));
			Vector<3, FLOAT32> s = math::sin(eulerAngle * FLOAT32(0.5));

			return Quaternion<FLOAT32>
			{
				s.x * c.y * c.z - c.x * s.y * s.z,
				c.x * s.y * c.z + s.x * c.y * s.z,
				c.x * c.y * s.z - s.x * s.y * c.z,
				c.x * c.y * c.z + s.x * s.y * s.z
			};
		}


		template<typename FLOAT32>
		static FLOAT32 roll(const Quaternion<FLOAT32>& q)
		{
			const FLOAT32 y = static_cast<FLOAT32>(2) * (q.value.x * q.value.y + q.value.w * q.value.z);
			const FLOAT32 x = q.value.w * q.value.w + q.value.x * q.value.x - q.value.y * q.value.y - q.value.z * q.value.z;

			FLOAT32 epsilon = math::epsilon<FLOAT32>();
			if (Vector<2, FLOAT32>(x, y) == epsilon && Vector<2, FLOAT32>(0) == epsilon) //avoid atan2(0,0) - handle singularity - Matiis
			{
				return static_cast<FLOAT32>(0);
			}
			return static_cast<FLOAT32>(math::atan2(y, x));
		}

		template<typename FLOAT32>
		static FLOAT32 pitch(const Quaternion<FLOAT32>& q)
		{
			//return FLOAT32(atan(FLOAT32(2) * (q.value.y * q.value.z + q.value.w * q.value.x).w * q.value.w - q.value.x * q.value.x - q.value.y * q.value.y + q.value.z * q.value.z));
			const FLOAT32 y = static_cast<FLOAT32>(2) * (q.value.y * q.value.z + q.value.w * q.value.x);
			const FLOAT32 x = q.value.w * q.value.w - q.value.x * q.value.x - q.value.y * q.value.y + q.value.z * q.value.z;

			FLOAT32 epsilon = math::epsilon<FLOAT32>();
			if (Vector<2, FLOAT32>(x, y) == epsilon && Vector<2, FLOAT32>(0) == epsilon) //avoid atan2(0,0) - handle singularity - Matiis
			{
				return static_cast<FLOAT32>(static_cast<FLOAT32>(2) * math::atan2(q.value.x, q.value.w));
			}

			return static_cast<FLOAT32>(math::atan2(y, x));
		}

		template<typename FLOAT32>
		static FLOAT32 yaw(const Quaternion<FLOAT32>& q)
		{
			return math::asin(math::clamp(static_cast<FLOAT32>(-2) * (q.value.x * q.value.z - q.value.w * q.value.y), static_cast<FLOAT32>(-1), static_cast<FLOAT32>(1)));
		}

		template<typename FLOAT32>
		static Vector<3, FLOAT32> QuaternionToEulerAngle(const Quaternion<FLOAT32>& x)
		{
			return Vector<3, FLOAT32>(Quaternion<FLOAT32>::pitch(x), Quaternion<FLOAT32>::yaw(x), Quaternion<FLOAT32>::roll(x));
		}
	};

	template<typename FLOAT32>
	FLOAT32 dot(const Quaternion<FLOAT32>& a, const Quaternion<FLOAT32>& b)
	{
		return a.value.x * b.value.x + a.value.y * b.value.y + a.value.z * b.value.z + a.value.w * b.value.w;
	}

	template<typename FLOAT32>
	Quaternion<FLOAT32> cross(const Quaternion<FLOAT32>& q1, const Quaternion<FLOAT32>& q2)
	{
		return Quaternion<FLOAT32>(
			q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
			q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
			q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
			q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x);
	}

	template<typename FLOAT32>
	Quaternion<FLOAT32> conjugate(const Quaternion<FLOAT32>& q)
	{
		return Quaternion<FLOAT32>(q.value.w, -q.value.x, -q.value.y, -q.value.z);
	}

	template<typename FLOAT32>
	Quaternion<FLOAT32> inverse(const Quaternion<FLOAT32>& q)
	{
		return conjugate(q) / dot(q, q);
	}



	template<typename FLOAT32>
	Quaternion<FLOAT32> operator+(const Quaternion<FLOAT32>& vector) noexcept
	{
		return vector;
	}

	template<typename FLOAT32>
	Quaternion<FLOAT32> operator-(const Quaternion<FLOAT32>& vector) noexcept
	{
		return Quaternion<FLOAT32>(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w);
	}


	//

	template<typename FLOAT32>
	FORCE_INLINE Vector<3, FLOAT32>operator*(const Quaternion<FLOAT32>& q, const Vector<3, FLOAT32>& v)
	{
		const Vector<3, FLOAT32> QuatVector(q.value.x, q.value.y, q.value.z);
		const Vector<3, FLOAT32> uv(cross(QuatVector, v));
		const Vector<3, FLOAT32> uuv(cross(QuatVector, uv));

		return v + ((uv * q.value.w) + uuv) * static_cast<FLOAT32>(2);
	}

	template<typename FLOAT32>
	FORCE_INLINE Vector<3, FLOAT32>operator*(const Vector<3, FLOAT32>& v, const Quaternion<FLOAT32>& q)
	{
		return inverse(q) * v;
	}

	template<typename FLOAT32>
	FORCE_INLINE Vector<4, FLOAT32>operator*(const Quaternion<FLOAT32>& q, const Vector<4, FLOAT32>& v)
	{
		return Vector<4, FLOAT32>(q * Vector<3, FLOAT32>(v), v.w);
	}

	template<typename FLOAT32>
	FORCE_INLINE Vector<4, FLOAT32>operator*(const Vector<4, FLOAT32>& v, const Quaternion<FLOAT32>& q)
	{
		return inverse(q) * v;
	}

	template<typename FLOAT32, std::enable_if_t<CHECK_IS_NUMBER(FLOAT32), bool> = true>
	FORCE_INLINE Quaternion<FLOAT32> operator*(const Quaternion<FLOAT32>& q, const FLOAT32& s)
	{
		return Quaternion<FLOAT32>(
			q.value.w * s, q.value.x * s, q.value.y * s, q.value.z * s);
	}

	template<typename FLOAT32, std::enable_if_t<CHECK_IS_NUMBER(FLOAT32), bool> = true>
	FORCE_INLINE Quaternion<FLOAT32> operator*(const FLOAT32& s, const Quaternion<FLOAT32>& q)
	{
		return q * s;
	}

	template<typename FLOAT32, std::enable_if_t<CHECK_IS_NUMBER(FLOAT32), bool> = true>
	FORCE_INLINE Quaternion<FLOAT32> operator*(const Quaternion<FLOAT32>& p, const Quaternion<FLOAT32>& q)
	{
		return p * q;
	}

	template<typename FLOAT32, std::enable_if_t<CHECK_IS_NUMBER(FLOAT32), bool> = true>
	FORCE_INLINE Quaternion<FLOAT32> operator/(const Quaternion<FLOAT32>& q, FLOAT32 s)
	{
		return Quaternion<FLOAT32>(
			q.value.w / s, q.value.x / s, q.value.y / s, q.value.z / s);
	}

}

