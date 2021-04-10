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
		using value_type = typename float;
		using type = typename Quaternion;

		Vector<4, float> value;

		constexpr Quaternion() noexcept : value{ 0,0,0,1.0f }
		{

		}
	
		constexpr Quaternion(float value) noexcept
			: value{ value , value , value , value }
		{
		}

		template <typename X>
		constexpr Quaternion(X xValue) noexcept
			: value{ static_cast<float>(value) , static_cast<float>(value) , static_cast<float>(value) , static_cast<float>(value) }
		{
		}

		constexpr Quaternion(float xValue, float yValue, float zValue, float wValue) noexcept
			: value{ xValue , yValue , zValue , wValue }
		{
		}

		template <typename X, typename Y, typename Z, typename W>
		constexpr Quaternion(X xValue, Y yValue, Z zValue, W wValue) noexcept
			: value{ static_cast<float>(xValue) , static_cast<float>(yValue) , static_cast<float>(zValue) , static_cast<float>(wValue) }
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

		constexpr Quaternion(float s, const Vector<3, float>& vector) noexcept
			: value{ vector.x, vector.y, vector.z, s }
		{
		}


		template <typename X, typename Y>
		constexpr Quaternion(X s, const Vector<3, Y>& vector) noexcept
			: value{ static_cast<float>(vector.x), static_cast<float>(vector.y), static_cast<float>(vector.z), static_cast<float>(s) }
		{
		}

		constexpr Quaternion(const Vector<3, float>& eulerAngle) noexcept
		{
			*this = type::eulerAngle(eulerAngle);
		}

		static constexpr type mat2Quaternion(const Matrix<3, 3, float>& m)
		{
			float fourXSquaredMinus1 = m[0][0] - m[1][1] - m[2][2];
			float fourYSquaredMinus1 = m[1][1] - m[0][0] - m[2][2];
			float fourZSquaredMinus1 = m[2][2] - m[0][0] - m[1][1];
			float fourWSquaredMinus1 = m[0][0] + m[1][1] + m[2][2];

			int biggestIndex = 0;
			float fourBiggestSquaredMinus1 = fourWSquaredMinus1;
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

			float biggestVal = static_cast<float>(math::sqrt(fourBiggestSquaredMinus1 + static_cast<float>(1)) * static_cast<float>(0.5));
			float mult = static_cast<float>(0.25) / biggestVal;

			switch (biggestIndex)
			{
			case 0:
				return Quaternion<float>(biggestVal, (m[1][2] - m[2][1]) * mult, (m[2][0] - m[0][2]) * mult, (m[0][1] - m[1][0]) * mult);
			case 1:
				return Quaternion<float>((m[1][2] - m[2][1]) * mult, biggestVal, (m[0][1] + m[1][0]) * mult, (m[2][0] + m[0][2]) * mult);
			case 2:
				return Quaternion<float>((m[2][0] - m[0][2]) * mult, (m[0][1] + m[1][0]) * mult, biggestVal, (m[1][2] + m[2][1]) * mult);
			case 3:
				return Quaternion<float>((m[0][1] - m[1][0]) * mult, (m[2][0] + m[0][2]) * mult, (m[1][2] + m[2][1]) * mult, biggestVal);
			default: // Silence a -Wswitch-default warning in GCC. Should never actually get here. Assert is just for sanity.
				assert(false);
				return Quaternion<float>(1, 0, 0, 0);
			}
		}

		constexpr explicit Quaternion(const Matrix<3, 3, float>& m) noexcept
		{
			mat2Quaternion(m);
		}

		constexpr explicit Quaternion(const Matrix<4, 4, float>& m) noexcept
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

		FORCE_INLINE constexpr type& operator=(const Matrix<4, 4, float>& m) noexcept
		{
			mat2Quaternion(m);
			return *this;
		}

		FORCE_INLINE constexpr type& operator=(const Matrix<3, 3, float>& m) noexcept
		{
			mat2Quaternion(m);
			return *this;
		}

		FORCE_INLINE constexpr type& operator=(const Vector<3, float>& eulerAngle) noexcept
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

		[[nodiscard]] inline static constexpr size_t componentCount()  noexcept { return 4; }

		[[nodiscard]] value_type& operator[](size_t i)
		{
			assert(i >= 0 || i < componentCount());
			return value[i];
		}

		[[nodiscard]] FORCE_INLINE constexpr const value_type& operator[](size_t i) const
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
			const Quaternion<float> p(*this);
			const Quaternion<float> q(rhs);

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
		static Matrix<3, 3, float> convert_quaternion_to_matrix(const Quaternion& quaternion)
		{

		}
		*/

		inline operator Matrix<3, 3, float>() const noexcept
		{
			Matrix<3, 3, float> Result(float(1));
			float qxx(this->value.x * this->value.x);
			float qyy(this->value.y * this->value.y);
			float qzz(this->value.z * this->value.z);
			float qxz(this->value.x * this->value.z);
			float qxy(this->value.x * this->value.y);
			float qyz(this->value.y * this->value.z);
			float qwx(this->value.w * this->value.x);
			float qwy(this->value.w * this->value.y);
			float qwz(this->value.w * this->value.z);

			Result[0][0] = float(1) - float(2) * (qyy + qzz);
			Result[0][1] = float(2) * (qxy + qwz);
			Result[0][2] = float(2) * (qxz - qwy);

			Result[1][0] = float(2) * (qxy - qwz);
			Result[1][1] = float(1) - float(2) * (qxx + qzz);
			Result[1][2] = float(2) * (qyz + qwx);

			Result[2][0] = float(2) * (qxz + qwy);
			Result[2][1] = float(2) * (qyz - qwx);
			Result[2][2] = float(1) - float(2) * (qxx + qyy);
			return Result;
		}

		inline operator Matrix<4, 4, float>() const noexcept
		{
			return Matrix<4, 4, float>(this->operator math::Matrix<3, 3, float>());
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
		FORCE_INLINE constexpr type operator++(int) noexcept
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
		FORCE_INLINE constexpr type operator--(int) noexcept
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
		template<typename float>
		static float angle(Quaternion<float> const& x)
		{
			if (abs(x.w) > cos_one_over_two<float>())
			{
				float const a = asin(sqrt(x.x * x.x + x.y * x.y + x.z * x.z)) * static_cast<float>(2);
				if (x.w < static_cast<float>(0))
					return pi<float>() * static_cast<float>(2) - a;
				return a;
			}

			return acos(x.w) * static_cast<float>(2);
		}

		template<typename float>
		static Vector<3, float> axis(qua<float, Q> const& x)
		{
			float const tmp1 = static_cast<float>(1) - x.w * x.w;
			if (tmp1 <= static_cast<float>(0))
				return vec<3, float, Q>(0, 0, 1);
			float const tmp2 = static_cast<float>(1) / sqrt(tmp1);
			return vec<3, float, Q>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
		}
		*/

		static Quaternion<float> angleAxis(const float& angle, const Vector<3, float>& v)
		{
			const float a{ angle };
			const float s{ math::sin(a * static_cast<float>(0.5)) };

			return Quaternion<float>(math::cos(a * static_cast<float>(0.5)), v * s);
		}

		template<typename X, typename Y>
		static Quaternion<float> angleAxis(const X& angle, const Vector<3, Y>& v)
		{
			const float a{ angle };
			const float s{ math::sin(a * static_cast<float>(0.5)) };

			return Quaternion<float>(math::cos(a * static_cast<float>(0.5)), v * s);
		}

		static Quaternion<float> eulerAngle(const Vector<3, float>& eulerAngle) noexcept
		{
			Vector<3, float> c = math::cos(eulerAngle * float(0.5));
			Vector<3, float> s = math::sin(eulerAngle * float(0.5));

			return Quaternion<float>
			{
				s.x* c.y* c.z - c.x * s.y * s.z,
				c.x* s.y* c.z + s.x * c.y * s.z,
				c.x* c.y* s.z - s.x * s.y * c.z,
				c.x* c.y* c.z + s.x * s.y * s.z
			};
		}

		template<typename X>
		static Quaternion<float> EulerAngleToQuaternion(const Vector<3, X>& eulerAngle) noexcept
		{
			Vector<3, float> c = math::cos(eulerAngle * float(0.5));
			Vector<3, float> s = math::sin(eulerAngle * float(0.5));

			return Quaternion<float>
			{
				s.x * c.y * c.z - c.x * s.y * s.z,
				c.x * s.y * c.z + s.x * c.y * s.z,
				c.x * c.y * s.z - s.x * s.y * c.z,
				c.x * c.y * c.z + s.x * s.y * s.z
			};
		}


		template<typename float>
		static float roll(const Quaternion<float>& q)
		{
			const float y = static_cast<float>(2) * (q.value.x * q.value.y + q.value.w * q.value.z);
			const float x = q.value.w * q.value.w + q.value.x * q.value.x - q.value.y * q.value.y - q.value.z * q.value.z;

			float epsilon = math::epsilon<float>();
			if (Vector<2, float>(x, y) == epsilon && Vector<2, float>(0) == epsilon) //avoid atan2(0,0) - handle singularity - Matiis
			{
				return static_cast<float>(0);
			}
			return static_cast<float>(math::atan2(y, x));
		}

		template<typename float>
		static float pitch(const Quaternion<float>& q)
		{
			//return float(atan(float(2) * (q.value.y * q.value.z + q.value.w * q.value.x).w * q.value.w - q.value.x * q.value.x - q.value.y * q.value.y + q.value.z * q.value.z));
			const float y = static_cast<float>(2) * (q.value.y * q.value.z + q.value.w * q.value.x);
			const float x = q.value.w * q.value.w - q.value.x * q.value.x - q.value.y * q.value.y + q.value.z * q.value.z;

			float epsilon = math::epsilon<float>();
			if (Vector<2, float>(x, y) == epsilon && Vector<2, float>(0) == epsilon) //avoid atan2(0,0) - handle singularity - Matiis
			{
				return static_cast<float>(static_cast<float>(2) * math::atan2(q.value.x, q.value.w));
			}

			return static_cast<float>(math::atan2(y, x));
		}

		template<typename float>
		static float yaw(const Quaternion<float>& q)
		{
			return math::asin(math::clamp(static_cast<float>(-2) * (q.value.x * q.value.z - q.value.w * q.value.y), static_cast<float>(-1), static_cast<float>(1)));
		}

		template<typename float>
		static Vector<3, float> QuaternionToEulerAngle(const Quaternion<float>& x)
		{
			return Vector<3, float>(Quaternion<float>::pitch(x), Quaternion<float>::yaw(x), Quaternion<float>::roll(x));
		}
	};

	template<typename float>
	float dot(const Quaternion<float>& a, const Quaternion<float>& b)
	{
		return a.value.x * b.value.x + a.value.y * b.value.y + a.value.z * b.value.z + a.value.w * b.value.w;
	}

	template<typename float>
	Quaternion<float> cross(const Quaternion<float>& q1, const Quaternion<float>& q2)
	{
		return Quaternion<float>(
			q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
			q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
			q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
			q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x);
	}

	template<typename float>
	Quaternion<float> conjugate(const Quaternion<float>& q)
	{
		return Quaternion<float>(q.value.w, -q.value.x, -q.value.y, -q.value.z);
	}

	template<typename float>
	Quaternion<float> inverse(const Quaternion<float>& q)
	{
		return conjugate(q) / dot(q, q);
	}



	template<typename float>
	Quaternion<float> operator+(const Quaternion<float>& vector) noexcept
	{
		return vector;
	}

	template<typename float>
	Quaternion<float> operator-(const Quaternion<float>& vector) noexcept
	{
		return Quaternion<float>(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w);
	}


	//

	template<typename float>
	FORCE_INLINE Vector<3, float>operator*(const Quaternion<float>& q, const Vector<3, float>& v)
	{
		const Vector<3, float> QuatVector(q.value.x, q.value.y, q.value.z);
		const Vector<3, float> uv(cross(QuatVector, v));
		const Vector<3, float> uuv(cross(QuatVector, uv));

		return v + ((uv * q.value.w) + uuv) * static_cast<float>(2);
	}

	template<typename float>
	FORCE_INLINE Vector<3, float>operator*(const Vector<3, float>& v, const Quaternion<float>& q)
	{
		return inverse(q) * v;
	}

	template<typename float>
	FORCE_INLINE Vector<4, float>operator*(const Quaternion<float>& q, const Vector<4, float>& v)
	{
		return Vector<4, float>(q * Vector<3, float>(v), v.w);
	}

	template<typename float>
	FORCE_INLINE Vector<4, float>operator*(const Vector<4, float>& v, const Quaternion<float>& q)
	{
		return inverse(q) * v;
	}

	template<typename float, std::enable_if_t<CHECK_IS_NUMBER(float), bool> = true>
	FORCE_INLINE Quaternion<float> operator*(const Quaternion<float>& q, const float& s)
	{
		return Quaternion<float>(
			q.value.w * s, q.value.x * s, q.value.y * s, q.value.z * s);
	}

	template<typename float, std::enable_if_t<CHECK_IS_NUMBER(float), bool> = true>
	FORCE_INLINE Quaternion<float> operator*(const float& s, const Quaternion<float>& q)
	{
		return q * s;
	}

	template<typename float, std::enable_if_t<CHECK_IS_NUMBER(float), bool> = true>
	FORCE_INLINE Quaternion<float> operator*(const Quaternion<float>& p, const Quaternion<float>& q)
	{
		return p * q;
	}

	template<typename float, std::enable_if_t<CHECK_IS_NUMBER(float), bool> = true>
	FORCE_INLINE Quaternion<float> operator/(const Quaternion<float>& q, float s)
	{
		return Quaternion<float>(
			q.value.w / s, q.value.x / s, q.value.y / s, q.value.z / s);
	}

}

