#pragma once

#include "LMath_Core.h"

#include "Vector.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Matrix4x4.h"
#include "Matrix3x3.h"

#include "Utility.h"

namespace math
{
	template <typename T>
	struct Quaternion_common
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Quaternion_common<T>;

		Vector<4, T> value;

		value_type& x = value.x;
		value_type& y = value.y;
		value_type& z = value.z;
		value_type& w = value.w;

		value_type& r = value.x;
		value_type& g = value.y;
		value_type& b = value.z;
		value_type& a = value.w;

		constexpr Quaternion_common() noexcept : value{ 0,0,0,1.0f }
		{

		}
	
		constexpr Quaternion_common(T value) noexcept
			: value{ value , value , value , value }
		{
		}

		template <typename X>
		constexpr Quaternion_common(X xValue) noexcept
			: value{ static_cast<T>(value) , static_cast<T>(value) , static_cast<T>(value) , static_cast<T>(value) }
		{
		}

		constexpr Quaternion_common(T xValue, T yValue, T zValue, T wValue) noexcept
			: value{ xValue , yValue , zValue , wValue }
		{
		}

		template <typename X, typename Y, typename Z, typename W>
		constexpr Quaternion_common(X xValue, Y yValue, Z zValue, W wValue) noexcept
			: value{ static_cast<T>(xValue) , static_cast<T>(yValue) , static_cast<T>(zValue) , static_cast<T>(wValue) }
		{
		}

		constexpr explicit Quaternion_common(const type& vector) noexcept
			: value{ vector.value }
		{
		}

		template <typename X>
		constexpr Quaternion_common(const Quaternion_common<X>& vector) noexcept
			: value{ vector.value }
		{
		}

		constexpr Quaternion_common(T s, const Vector<3, T>& vector) noexcept
			: value{ vector.x, vector.y, vector.z, s }
		{
		}


		template <typename X, typename Y>
		constexpr Quaternion_common(X s, const Vector<3, Y>& vector) noexcept
			: value{ static_cast<T>(vector.x), static_cast<T>(vector.y), static_cast<T>(vector.z), static_cast<T>(s) }
		{
		}

		constexpr Quaternion_common(const Vector<3, T>& eulerAngle) noexcept
		{
			*this = type::eulerAngle(eulerAngle);
		}

		static constexpr type mat2Quaternion(const Matrix<3, 3, T>& m)
		{
			T fourXSquaredMinus1 = m[0][0] - m[1][1] - m[2][2];
			T fourYSquaredMinus1 = m[1][1] - m[0][0] - m[2][2];
			T fourZSquaredMinus1 = m[2][2] - m[0][0] - m[1][1];
			T fourWSquaredMinus1 = m[0][0] + m[1][1] + m[2][2];

			int biggestIndex = 0;
			T fourBiggestSquaredMinus1 = fourWSquaredMinus1;
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

			T biggestVal = static_cast<T>(math::sqrt(fourBiggestSquaredMinus1 + static_cast<T>(1)) * static_cast<T>(0.5));
			T mult = static_cast<T>(0.25) / biggestVal;

			switch (biggestIndex)
			{
			case 0:
				return Quaternion_common<T>(biggestVal, (m[1][2] - m[2][1]) * mult, (m[2][0] - m[0][2]) * mult, (m[0][1] - m[1][0]) * mult);
			case 1:
				return Quaternion_common<T>((m[1][2] - m[2][1]) * mult, biggestVal, (m[0][1] + m[1][0]) * mult, (m[2][0] + m[0][2]) * mult);
			case 2:
				return Quaternion_common<T>((m[2][0] - m[0][2]) * mult, (m[0][1] + m[1][0]) * mult, biggestVal, (m[1][2] + m[2][1]) * mult);
			case 3:
				return Quaternion_common<T>((m[0][1] - m[1][0]) * mult, (m[2][0] + m[0][2]) * mult, (m[1][2] + m[2][1]) * mult, biggestVal);
			default: // Silence a -Wswitch-default warning in GCC. Should never actually get here. Assert is just for sanity.
				assert(false);
				return Quaternion_common<T>(1, 0, 0, 0);
			}
		}

		constexpr explicit Quaternion_common(const Matrix<3, 3, T>& m) noexcept
		{
			mat2Quaternion(m);
		}

		constexpr explicit Quaternion_common(const Matrix<4, 4, T>& m) noexcept
		{
			mat2Quaternion(m);
		}

		constexpr type& operator=(const type& vector) noexcept
		{
			value = vector.value;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Quaternion_common<X>& vector) noexcept
		{
			value = vector.value;
			return *this;
		}

		constexpr type& operator=(const Matrix<4, 4, T>& m) noexcept
		{
			mat2Quaternion(m);
			return *this;
		}

		constexpr type& operator=(const Matrix<3, 3, T>& m) noexcept
		{
			mat2Quaternion(m);
			return *this;
		}

		constexpr type& operator=(const Vector<3, T>& eulerAngle) noexcept
		{
			*this = type::eulerAngle(eulerAngle);
			return *this;
		} 


		// 		Quaternion(const type&) = default;
		// 		Quaternion(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		constexpr std::basic_string<char> toString() noexcept
		{
			std::stringstream ss;
			ss << x << "  " << y << "  " << z << "  " << w;
			return ss.str();
		}

		[[nodiscard]] inline static constexpr size_t componentCount()  noexcept { return 4; }

		[[nodiscard]] value_type& operator[](size_t i)
		{
			assert(i >= 0 || i < componentCount());
			return value[i];
		}

		[[nodiscard]] constexpr const value_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < componentCount());
			return value[i];
		}


		template <typename X>
		constexpr type& operator+=(const Quaternion_common<X>& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const Quaternion_common<X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

		template <typename X>
		constexpr type& operator*=(const Quaternion_common<X>& rhs) noexcept
		{
			const Quaternion_common<T> p(*this);
			const Quaternion_common<T> q(rhs);

			this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
			this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
			this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
			this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
			return *this;
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		constexpr type& operator*=(X s) noexcept
		{
			x *= s;
			y *= s;
			z *= s;
			w *= s;
			return *this;
		}


		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		constexpr type& operator/=(X s)
		{
			x /= s;
			y /= s;
			z /= s;
			w /= s;
			return *this;
		}

	

		template <typename X>
		constexpr type operator+(const Quaternion_common<X>& rhs) noexcept
		{
			return *this += rhs;
		}

		template <typename X>
		constexpr type operator-(const Quaternion_common<X>& rhs) noexcept
		{
			return *this -= rhs;
		}

		template <typename X>
		constexpr type operator*(const Quaternion_common<X>& rhs) noexcept
		{
			return *this *= rhs;
		}

		template <typename X>
		constexpr type operator/(const Quaternion_common<X>& rhs)
		{
			return *this /= rhs;
		}

		/*
		static Matrix<3, 3, T> convert_quaternion_to_matrix(const Quaternion& quaternion)
		{

		}
		*/

		operator Matrix<3, 3, T>() const noexcept
		{
			Matrix<3, 3, T> Result(T(1));
			T qxx(this->x * this->x);
			T qyy(this->y * this->y);
			T qzz(this->z * this->z);
			T qxz(this->x * this->z);
			T qxy(this->x * this->y);
			T qyz(this->y * this->z);
			T qwx(this->w * this->x);
			T qwy(this->w * this->y);
			T qwz(this->w * this->z);

			Result[0][0] = T(1) - T(2) * (qyy + qzz);
			Result[0][1] = T(2) * (qxy + qwz);
			Result[0][2] = T(2) * (qxz - qwy);

			Result[1][0] = T(2) * (qxy - qwz);
			Result[1][1] = T(1) - T(2) * (qxx + qzz);
			Result[1][2] = T(2) * (qyz + qwx);

			Result[2][0] = T(2) * (qxz + qwy);
			Result[2][1] = T(2) * (qyz - qwx);
			Result[2][2] = T(1) - T(2) * (qxx + qyy);
			return Result;
		}

		operator Matrix<4, 4, T>() const noexcept
		{
			return Matrix<4, 4, T>(this->operator math::Matrix<3, 3, T>());
		}

		[[nodiscard]] inline constexpr bool operator==(const type& rhs) noexcept
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w;
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z || this->w != rhs.w;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator++() noexcept
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
		constexpr type operator++(int) noexcept
		{
			type Quaternion{ *this };
			++* this;
			return Quaternion;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator--() noexcept
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
		constexpr type operator--(int) noexcept
		{
			type Quaternion{ *this };
			--* this;
			return type{ Quaternion };
		}

		constexpr operator std::basic_string<char>() noexcept
		{
			return this->toString();
		}

		/*
		template<typename T>
		static T angle(Quaternion_common<T> const& x)
		{
			if (abs(x.w) > cos_one_over_two<T>())
			{
				T const a = asin(sqrt(x.x * x.x + x.y * x.y + x.z * x.z)) * static_cast<T>(2);
				if (x.w < static_cast<T>(0))
					return pi<T>() * static_cast<T>(2) - a;
				return a;
			}

			return acos(x.w) * static_cast<T>(2);
		}

		template<typename T>
		static Vector<3, T> axis(qua<T, Q> const& x)
		{
			T const tmp1 = static_cast<T>(1) - x.w * x.w;
			if (tmp1 <= static_cast<T>(0))
				return vec<3, T, Q>(0, 0, 1);
			T const tmp2 = static_cast<T>(1) / sqrt(tmp1);
			return vec<3, T, Q>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
		}
		*/

		static Quaternion_common<T> angleAxis(const T& angle, const Vector<3, T>& v)
		{
			const T a{ angle };
			const T s{ math::sin(a * static_cast<T>(0.5)) };

			return Quaternion_common<T>(math::cos(a * static_cast<T>(0.5)), v * s);
		}

		template<typename X, typename Y>
		static Quaternion_common<T> angleAxis(const X& angle, const Vector<3, Y>& v)
		{
			const T a{ angle };
			const T s{ math::sin(a * static_cast<T>(0.5)) };

			return Quaternion_common<T>(math::cos(a * static_cast<T>(0.5)), v * s);
		}

		static Quaternion_common<T> eulerAngle(const Vector<3, T>& eulerAngle) noexcept
		{
			Vector<3, T> c = math::cos(eulerAngle * T(0.5));
			Vector<3, T> s = math::sin(eulerAngle * T(0.5));

			return Quaternion_common<T>
			{
				s.x* c.y* c.z - c.x * s.y * s.z,
				c.x* s.y* c.z + s.x * c.y * s.z,
				c.x* c.y* s.z - s.x * s.y * c.z,
				c.x* c.y* c.z + s.x * s.y * s.z
			};
		}

		template<typename X>
		static Quaternion_common<T> eulerAngle(const Vector<3, X>& eulerAngle) noexcept
		{
			Vector<3, T> c = math::cos(eulerAngle * T(0.5));
			Vector<3, T> s = math::sin(eulerAngle * T(0.5));

			return Quaternion_common<T>
			{
				s.x * c.y * c.z - c.x * s.y * s.z,
				c.x * s.y * c.z + s.x * c.y * s.z,
				c.x * c.y * s.z - s.x * s.y * c.z,
				c.x * c.y * c.z + s.x * s.y * s.z
			};
		}
	};

	template<typename T>
	constexpr Quaternion_common<T> dot(const Quaternion_common<T>& a, const Quaternion_common<T>& b)
	{
		Vector<4, T> tmp(a.w * b.w, a.x * b.x, a.y * b.y, a.z * b.z);
		return (tmp.x + tmp.y) + (tmp.z + tmp.w);
	}

	template<typename T>
	constexpr Quaternion_common<T> cross(const Quaternion_common<T>& q1, const Quaternion_common<T>& q2)
	{
		return Quaternion_common<T>(
			q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
			q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
			q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
			q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x);
	}

	template<typename T>
	constexpr Quaternion_common<T> conjugate(const Quaternion_common<T>& q)
	{
		return Quaternion_common<T>(q.w, -q.x, -q.y, -q.z);
	}

	template<typename T>
	constexpr Quaternion_common<T> inverse(const Quaternion_common<T>& q)
	{
		return conjugate(q) / dot(q, q);
	}



	template<typename T>
	constexpr Quaternion_common<T> operator+(const Quaternion_common<T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	constexpr Quaternion_common<T> operator-(const Quaternion_common<T>& vector) noexcept
	{
		return Quaternion_common<T>(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w);
	}


	//

	template<typename T>
	constexpr Vector<3, T>operator*(const Quaternion_common<T>& q, const Vector<3, T>& v)
	{
		const Vector<3, T> QuatVector(q.x, q.y, q.z);
		const Vector<3, T> uv(cross(QuatVector, v));
		const Vector<3, T> uuv(cross(QuatVector, uv));

		return v + ((uv * q.w) + uuv) * static_cast<T>(2);
	}

	template<typename T>
	constexpr Vector<3, T>operator*(const Vector<3, T>& v, const Quaternion_common<T>& q)
	{
		return inverse(q) * v;
	}

	template<typename T>
	constexpr Vector<4, T>operator*(const Quaternion_common<T>& q, const Vector<4, T>& v)
	{
		return Vector<4, T>(q * Vector<3, T>(v), v.w);
	}

	template<typename T>
	constexpr Vector<4, T>operator*(const Vector<4, T>& v, const Quaternion_common<T>& q)
	{
		return inverse(q) * v;
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	constexpr Quaternion_common<T> operator*(const Quaternion_common<T>& q, const T& s)
	{
		return Quaternion_common<T>(
			q.w * s, q.x * s, q.y * s, q.z * s);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	constexpr Quaternion_common<T> operator*(const T& s, const Quaternion_common<T>& q)
	{
		return q * s;
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	constexpr Quaternion_common<T> operator*(const Quaternion_common<T>& p, const Quaternion_common<T>& q)
	{
		return p * q;
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	constexpr Quaternion_common<T> operator/(const Quaternion_common<T>& q, const T& s)
	{
		return Quaternion_common<T>(
			q.w / s, q.x / s, q.y / s, q.z / s);
	}


	using Quaternion = typename Quaternion_common<float>;

}