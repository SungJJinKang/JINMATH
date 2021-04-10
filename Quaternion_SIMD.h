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
	struct alignas(16) Quaternion
	{
		using value_type = typename float;
		using type = typename Quaternion;

		Vector<4, float> value;

		Quaternion() noexcept : value{ 0,0,0,1.0f }
		{

		}

		FORCE_INLINE explicit Quaternion(float value) noexcept
			: value{ value , value , value , value }
		{
		}

		FORCE_INLINE Quaternion(float xValue, float yValue, float zValue, float wValue) noexcept
			: value{ xValue , yValue , zValue , wValue }
		{
		}

		FORCE_INLINE Quaternion(const type& quat) noexcept
			: value{ quat.value }
		{
		}

		FORCE_INLINE Quaternion(const M128F& m128f) noexcept
		{
			//this is faster than x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ vector.w }
			std::memcpy(this, &m128f, sizeof(type));
		}

		FORCE_INLINE Quaternion(float s, const Vector<3, float>& vector) noexcept
			: value{ vector.x, vector.y, vector.z, s }
		{
		}

		FORCE_INLINE Quaternion(const Vector<3, float>& eulerAngle) noexcept
		{
			*this = type::eulerAngle(eulerAngle);
		}

		static type mat2Quaternion(const Matrix<3, 3, float>& m)
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

		FORCE_INLINE Quaternion(const Matrix<3, 3, float>& m) noexcept
		{
			mat2Quaternion(m);
		}

		FORCE_INLINE Quaternion(const Matrix<4, 4, float>& m) noexcept
		{
			mat2Quaternion(m);
		}

		FORCE_INLINE type& operator=(const type& vector) noexcept
		{
			value = vector.value;
			return *this;
		}

		FORCE_INLINE type& operator=(const M128F& m128f) noexcept
		{
			//this is faster than x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ vector.w }
			std::memcpy(this, &m128f, sizeof(type));
			return *this;
		}

		FORCE_INLINE type& operator=(const Matrix<4, 4, float>& m) noexcept
		{
			mat2Quaternion(m);
			return *this;
		}

		FORCE_INLINE type& operator=(const Matrix<3, 3, float>& m) noexcept
		{
			mat2Quaternion(m);
			return *this;
		}

		FORCE_INLINE type& operator=(const Vector<3, float>& eulerAngle) noexcept
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

		[[nodiscard]] inline static size_t componentCount()  noexcept { return 4; }

		[[nodiscard]] value_type& operator[](size_t i)
		{
			assert(i >= 0 || i < componentCount());
			return value[i];
		}

		[[nodiscard]] FORCE_INLINE const value_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < componentCount());
			return value[i];
		}

		FORCE_INLINE type& operator+=(const type& rhs) noexcept
		{
			value.x += rhs.value.x;
			value.y += rhs.value.y;
			value.z += rhs.value.z;
			value.w += rhs.value.w;
			return *this;
		}

		FORCE_INLINE type& operator-=(const type& rhs) noexcept
		{
			value.x -= rhs.value.x;
			value.y -= rhs.value.y;
			value.z -= rhs.value.z;
			value.w -= rhs.value.w;
			return *this;
		}


		inline static constexpr M128F QuaternionMultiplyMask1{};

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

		FORCE_INLINE type& operator/=(const type& rhs) noexcept
		{
			value.x /= rhs.value.x;
			value.y /= rhs.value.y;
			value.z /= rhs.value.z;
			value.w /= rhs.value.w;
			return *this;
		}

		FORCE_INLINE type operator+(const type& rhs) noexcept
		{
			return *this += rhs;
		}

		FORCE_INLINE type operator-(const type& rhs) noexcept
		{
			return *this -= rhs;
		}

		FORCE_INLINE type operator*(const type& rhs) noexcept
		{
			return *this *= rhs;
		}

		FORCE_INLINE type operator/(const type& rhs)
		{
			return *this /= rhs;
		}



		FORCE_INLINE type& operator+=(float number) noexcept
		{
			value.x += number;
			value.y += number;
			value.z += number;
			value.w += number;
			return *this;
		}

		FORCE_INLINE type& operator-=(float number) noexcept
		{
			value.x -= number;
			value.y -= number;
			value.z -= number;
			value.w -= number;
			return *this;
		}

		FORCE_INLINE type& operator*=(float number) noexcept
		{
			value.x *= number;
			value.y *= number;
			value.z *= number;
			value.w *= number;
			return *this;
		}

		FORCE_INLINE type& operator/=(float number) noexcept
		{
			value.x /= number;
			value.y /= number;
			value.z /= number;
			value.w /= number;
			return *this;
		}

		FORCE_INLINE type operator+(float number) noexcept
		{
			return *this += number;
		}

		FORCE_INLINE type operator-(float number) noexcept
		{
			return *this -= number;
		}

		FORCE_INLINE type operator*(float number) noexcept
		{
			return *this *= number;
		}

		FORCE_INLINE type operator/(float number)
		{
			return *this /= number;
		}
		/*
		static Matrix<3, 3, float> convert_quaternion_to_matrix(const Quaternion& quaternion)
		{

		}
		*/

		/*
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

		[[nodiscard]] FORCE_INLINE bool operator==(const type& rhs) noexcept
		{
			return this->value.x == rhs.value.x && this->value.y == rhs.value.y && this->value.z == rhs.value.z && this->value.w == rhs.value.w;
		}

		[[nodiscard]] FORCE_INLINE bool operator!=(const type& rhs) noexcept
		{
			return this->value.x != rhs.value.x || this->value.y != rhs.value.y || this->value.z != rhs.value.z || this->value.w != rhs.value.w;
		}

		[[nodiscard]] FORCE_INLINE bool operator==(float number) noexcept
		{
			return this->value.x == number && this->value.y == number && this->value.z == number && this->value.w == number;
		}

		[[nodiscard]] FORCE_INLINE bool operator!=(float number) noexcept
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
		FORCE_INLINE type operator++(int) noexcept
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
		FORCE_INLINE type operator--(int) noexcept
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
		
		static float angle(Quaternion const& x)
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

		
		static Vector<3, float> axis(qua<float, Q> const& x)
		{
			float const tmp1 = static_cast<float>(1) - x.w * x.w;
			if (tmp1 <= static_cast<float>(0))
				return vec<3, float, Q>(0, 0, 1);
			float const tmp2 = static_cast<float>(1) / sqrt(tmp1);
			return vec<3, float, Q>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
		}
		*/

		static Quaternion angleAxis(const float& angle, const Vector<3, float>& v)
		{
			const float a{ angle };
			const float s{ math::sin(a * static_cast<float>(0.5)) };

			return Quaternion(math::cos(a * static_cast<float>(0.5)), v * s);
		}

		static Quaternion eulerAngle(const Vector<3, float>& eulerAngle) noexcept
		{
			Vector<3, float> c = math::cos(eulerAngle * float(0.5));
			Vector<3, float> s = math::sin(eulerAngle * float(0.5));

			return Quaternion
			{
				s.x* c.y* c.z - c.x * s.y * s.z,
					c.x* s.y* c.z + s.x * c.y * s.z,
					c.x* c.y* s.z - s.x * s.y * c.z,
					c.x* c.y* c.z + s.x * s.y * s.z
			};
		}

		static Quaternion EulerAngleToQuaternion(const Vector<3, float>& eulerAngle) noexcept
		{
			Vector<3, float> c = math::cos(eulerAngle * float(0.5));
			Vector<3, float> s = math::sin(eulerAngle * float(0.5));

			return Quaternion
			{
				s.x* c.y* c.z - c.x * s.y * s.z,
					c.x* s.y* c.z + s.x * c.y * s.z,
					c.x* c.y* s.z - s.x * s.y * c.z,
					c.x* c.y* c.z + s.x * s.y * s.z
			};
		}


		
		static float roll(const Quaternion& q)
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

		
		static float pitch(const Quaternion& q)
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

		
		static float yaw(const Quaternion& q)
		{
			return math::asin(math::clamp(static_cast<float>(-2) * (q.value.x * q.value.z - q.value.w * q.value.y), static_cast<float>(-1), static_cast<float>(1)));
		}

		
		static Vector<3, float> QuaternionToEulerAngle(const Quaternion& x)
		{
			return Vector<3, float>(Quaternion::pitch(x), Quaternion::yaw(x), Quaternion::roll(x));
		}
	};

	
	inline float dot(const Quaternion& a, const Quaternion& b)
	{
		return a.value.x * b.value.x + a.value.y * b.value.y + a.value.z * b.value.z + a.value.w * b.value.w;
	}

	
	inline Quaternion cross(const Quaternion& q1, const Quaternion& q2)
	{
		return Quaternion(
			q1.value.w * q2.value.w - q1.value.x * q2.value.x - q1.value.y * q2.value.y - q1.value.z * q2.value.z,
			q1.value.w * q2.value.x + q1.value.x * q2.value.w + q1.value.y * q2.value.z - q1.value.z * q2.value.y,
			q1.value.w * q2.value.y + q1.value.y * q2.value.w + q1.value.z * q2.value.x - q1.value.x * q2.value.z,
			q1.value.w * q2.value.z + q1.value.z * q2.value.w + q1.value.x * q2.value.y - q1.value.y * q2.value.x);
	}

	
	inline Quaternion conjugate(const Quaternion& q)
	{
		return Quaternion(q.value.w, -q.value.x, -q.value.y, -q.value.z);
	}

	
	inline Quaternion inverse(const Quaternion& q)
	{
		return conjugate(q) / dot(q, q);
	}



	
	inline Quaternion operator+(const Quaternion& vector) noexcept
	{
		return vector;
	}

	
	inline Quaternion operator-(const Quaternion& quat) noexcept
	{
		return Quaternion(
			-quat.value.x,
			-quat.value.y,
			-quat.value.z,
			-quat.value.w);
	}


	inline FORCE_INLINE Vector<3, float> operator*(const Quaternion& q, const Vector<3, float>& v)
	{
		const Vector<3, float> QuatVector(q.value.x, q.value.y, q.value.z);
		const Vector<3, float> uv(cross(QuatVector, v));
		const Vector<3, float> uuv(cross(QuatVector, uv));

		return v + ((uv * q.value.w) + uuv) * static_cast<float>(2);
	}

	inline FORCE_INLINE Vector<3, float> operator*(const Vector<3, float>& v, const Quaternion& q)
	{
		return operator*(inverse(q), v);
	}

	inline FORCE_INLINE Vector<4, float> operator*(const Quaternion& q, const Vector<4, float>& v)
	{
		return Vector<4, float>(q * Vector<3, float>(v), v.w);
	}

	inline FORCE_INLINE Vector<4, float> operator*(const Vector<4, float>& v, const Quaternion& q)
	{
		return inverse(q) * v;
	}

	inline FORCE_INLINE Quaternion operator*(const Quaternion& q, const float& s)
	{
		return Quaternion(
			q.value.w * s, q.value.x * s, q.value.y * s, q.value.z * s);
	}

	inline FORCE_INLINE Quaternion operator*(const float& s, const Quaternion& q)
	{
		return q * s;
	}

	inline FORCE_INLINE Quaternion operator*(const Quaternion& p, const Quaternion& q)
	{
		return p * q;
	}

// 	
// 	FORCE_INLINE Quaternion operator/(const Quaternion& q, float s)
// 	{
// 		return Quaternion(
// 			q.value.w / s, q.value.x / s, q.value.y / s, q.value.z / s);
// 	}





}
