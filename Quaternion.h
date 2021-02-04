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
	struct Quaternion
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Quaternion<T>;

		Vector<4, T> value;

		value_type& x = value.x;
		value_type& y = value.y;
		value_type& z = value.z;
		value_type& w = value.w;

		value_type& r = value.x;
		value_type& g = value.y;
		value_type& b = value.z;
		value_type& a = value.w;

		constexpr Quaternion() noexcept : value{}
		{

		}
	
		constexpr Quaternion(T xValue, T yValue, T zValue, T wValue) noexcept
			: value{ xValue , yValue , zValue , wValue }
		{
		}

		template <typename X, typename Y, typename Z, typename W>
		constexpr Quaternion(X xValue, Y yValue, Z zValue, W wValue) noexcept
			: value{ static_cast<T>(xValue) , static_cast<T>(yValue) , static_cast<T>(zValue) , static_cast<T>(wValue) }
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

		constexpr Quaternion(T s, const Vector<3, T>& vector) noexcept
			: value{ vector.x, vector.y, vector.z, s }
		{
		}

		template <typename X, typename Y>
		constexpr Quaternion(X s, const Vector<3, Y>& vector) noexcept
			: value{ static_cast<T>(vector.x), static_cast<T>(vector.y), static_cast<T>(vector.z), static_cast<T>(s) }
		{
		}

		constexpr Quaternion(const Vector<3, T>& eulerAngle) noexcept
		{
			Vector<3, T> c = math::cos(eulerAngle * T(0.5));
			Vector<3, T> s = math::sin(eulerAngle * T(0.5));

			this->w = c.x * c.y * c.z + s.x * s.y * s.z;
			this->x = s.x * c.y * c.z - c.x * s.y * s.z;
			this->y = c.x * s.y * c.z + s.x * c.y * s.z;
			this->z = c.x * c.y * s.z - s.x * s.y * c.z;
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

			T biggestVal = static_cast<T>(math::Sqrt(fourBiggestSquaredMinus1 + static_cast<T>(1)) * static_cast<T>(0.5));
			T mult = static_cast<T>(0.25) / biggestVal;

			switch (biggestIndex)
			{
			case 0:
				return Quaternion<T>(biggestVal, (m[1][2] - m[2][1]) * mult, (m[2][0] - m[0][2]) * mult, (m[0][1] - m[1][0]) * mult);
			case 1:
				return Quaternion<T>((m[1][2] - m[2][1]) * mult, biggestVal, (m[0][1] + m[1][0]) * mult, (m[2][0] + m[0][2]) * mult);
			case 2:
				return Quaternion<T>((m[2][0] - m[0][2]) * mult, (m[0][1] + m[1][0]) * mult, biggestVal, (m[1][2] + m[2][1]) * mult);
			case 3:
				return Quaternion<T>((m[0][1] - m[1][0]) * mult, (m[2][0] + m[0][2]) * mult, (m[1][2] + m[2][1]) * mult, biggestVal);
			default: // Silence a -Wswitch-default warning in GCC. Should never actually get here. Assert is just for sanity.
				assert(false);
				return Quaternion<T>(1, 0, 0, 0);
			}
		}

		constexpr explicit Quaternion(const Matrix<3, 3, T>& m) noexcept
		{
			mat2Quaternion(m);
		}

		constexpr explicit Quaternion(const Matrix<4, 4, T>& m) noexcept
		{
			mat2Quaternion(m);
		}

		constexpr type& operator=(const type& vector) noexcept
		{
			value = vector.value;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Quaternion<X>& vector) noexcept
		{
			value = vector.value;
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
		constexpr type& operator+=(const Quaternion<X>& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const Quaternion<X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

		template <typename X>
		constexpr type& operator*=(const Quaternion<X>& rhs) noexcept
		{
			const Quaternion<T> p(*this);
			const Quaternion<T> q(r);

			this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
			this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
			this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
			this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
			return *this;
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
		constexpr type& operator*=(X s) noexcept
		{
			*this = type(this->x * s, this->y * s, this->z * s, this->w * s);
			return *this;
		}


		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
		constexpr type& operator/=(X s)
		{
			*this = type(this->x / s, this->y / s, this->z / s, this->w / s);
			return *this;
		}

	

		template <typename X>
		constexpr type operator+(const Quaternion<X>& rhs) noexcept
		{
			return *this += rhs;
		}

		template <typename X>
		constexpr type operator-(const Quaternion<X>& rhs) noexcept
		{
			return *this -= rhs;
		}

		template <typename X>
		constexpr type operator*(const Quaternion<X>& rhs) noexcept
		{
			return *this *= rhs;
		}

		template <typename X>
		constexpr type operator/(const Quaternion<X>& rhs)
		{
			return *this /= rhs;
		}


		operator Matrix<3, 3, T>() const 
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

		operator Matrix<4, 4, T>() const
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

		


	};

	template<typename T>
	constexpr Quaternion<T> dot(const Quaternion<T>& a, const Quaternion<T>& b)
	{
		Vector<4, T> tmp(a.w * b.w, a.x * b.x, a.y * b.y, a.z * b.z);
		return (tmp.x + tmp.y) + (tmp.z + tmp.w);
	}

	template<typename T>
	constexpr Quaternion<T> cross(const Quaternion<T>& q1, const Quaternion<T>& q2)
	{
		return Quaternion<T>(
			q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
			q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
			q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
			q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x);
	}

	template<typename T>
	constexpr Quaternion<T> conjugate(const Quaternion<T>& q)
	{
		return Quaternion<T>(q.w, -q.x, -q.y, -q.z);
	}

	template<typename T>
	constexpr Quaternion<T> inverse(const Quaternion<T>& q)
	{
		return conjugate(q) / dot(q, q);
	}



	template<typename T>
	constexpr Quaternion<T> operator+(const Quaternion<T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	constexpr Quaternion<T> operator-(const Quaternion<T>& vector) noexcept
	{
		return Quaternion<T>(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w);
	}


	//

	template<typename T>
	constexpr Vector<3, T>operator*(const Quaternion<T>& q, const Vector<3, T>& v)
	{
		const Vector<3, T> QuatVector(q.x, q.y, q.z);
		const Vector<3, T> uv(cross(QuatVector, v));
		const Vector<3, T> uuv(cross(QuatVector, uv));

		return v + ((uv * q.w) + uuv) * static_cast<T>(2);
	}

	template<typename T>
	constexpr Vector<3, T>operator*(const Vector<3, T>& v, const Quaternion<T>& q)
	{
		return inverse(q) * v;
	}

	template<typename T>
	constexpr Vector<4, T>operator*(const Quaternion<T>& q, const Vector<4, T>& v)
	{
		return Vector<4, T>(q * Vector<3, T>(v), v.w);
	}

	template<typename T>
	constexpr Vector<4, T>operator*(const Vector<4, T>& v, const Quaternion<T>& q)
	{
		return inverse(q) * v;
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	constexpr Quaternion<T> operator*(const Quaternion<T>& q, const T& s)
	{
		return Quaternion<T>(
			q.w * s, q.x * s, q.y * s, q.z * s);
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	constexpr Quaternion<T> operator*(const T& s, const Quaternion<T>& q)
	{
		return q * s;
	}

	template<typename T, std::enable_if_t<CHECK_IS_NUMBER(T), bool> = true>
	constexpr Quaternion<T> operator/(const Quaternion<T>& q, const T& s)
	{
		return Quaternion<T>(
			q.w / s, q.x / s, q.y / s, q.z / s);
	}




}