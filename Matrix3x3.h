#pragma once
#include "Matrix.h"

#include "Vector3.h"
namespace Math
{
	template <typename T>
	struct Matrix<3, 3, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Matrix<3, 3, T>;
		template <typename T2>
		using col_type_template = Vector<3, T2>;
		using col_type = Vector<3, T>;

		[[nodiscard]] inline static constexpr size_t collumCount()  noexcept { return 3; }
		col_type collums[3];

		constexpr Matrix() noexcept : collums{}
		{

		}
		
		/// <summary>
		/// diagonal matrix
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		constexpr explicit Matrix(value_type value) noexcept
		{
			collums[0] = col_type(value, 0, 0, 0);
			collums[1] = col_type(0, value, 0, 0);
			collums[2] = col_type(0, 0, value, 0);
		}

		/// <summary>
		/// diagonal matrix
		/// </summary>
		/// <typeparam name="X"></typeparam>
		/// <param name="value"></param>
		/// <returns></returns>
		template <typename X>
		constexpr Matrix(X value) noexcept
		{
			collums[0] = col_type(value, 0, 0, 0);
			collums[1] = col_type(0, value, 0, 0);
			collums[2] = col_type(0, 0, value, 0);
		}

		constexpr Matrix
		(
			value_type x0, value_type y0, value_type z0,
			value_type x1, value_type y1, value_type z1,
			value_type x2, value_type y2, value_type z2
		) noexcept :
			collums{
			col_type(x0, y0, z0),
			col_type(x1, y1, z1),
			col_type(x2, y2, z2)}
		{
		}

		template <
			typename X0, typename Y0, typename Z0,
			typename X1, typename Y1, typename Z1,
			typename X2, typename Y2, typename Z2>
			constexpr Matrix
			(
				X0 x0, Y0 y0, Z0 z0,
				X1 x1, Y1 y1, Z1 z1,
				X2 x2, Y2 y2, Z2 z2,
			) noexcept :
			collums{
			col_type(x0, y0, z0),
			col_type(x1, y1, z1),
			col_type(x2, y2, z2)}
		{
		}

		constexpr Matrix(col_type collum0Value, col_type collum1Value, col_type collum2Value) noexcept
		{
			collums[0] = collum0Value;
			collums[1] = collum1Value;
			collums[2] = collum2Value;
		}

		template <typename X, typename Y, typename Z>
		constexpr Matrix(col_type_template<X> collum0, col_type_template<Y> collum1, col_type_template<Z> collum2) noexcept
		{
			collums[0] = collum0;
			collums[1] = collum1;
			collums[2] = collum2;
		}

		constexpr explicit Matrix(const Matrix<3, 3, T>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
		}

		template <typename X>
		constexpr Matrix(const Matrix<1, 1, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = 0;
			collums[2] = 0;
		}

		template <typename X>
		constexpr Matrix(const Matrix<2, 2, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = 0;
		}

		template <typename X>
		constexpr Matrix(const Matrix<3, 3, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
		}

		template <typename X>
		constexpr Matrix(const Matrix<4, 4, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
		}

		constexpr type& operator=(value_type value) noexcept
		{
			collums[0] = value;
			collums[1] = value;
			collums[2] = value;
			return *this;
		}

		constexpr type& operator=(const Matrix<3, 3, T>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<1, 1, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = 0;
			collums[2] = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<2, 2, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<3, 3, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<4, 4, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
			return *this;
		}

		// 		Matrix(const type&) = default;
		// 		Matrix(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		constexpr std::basic_string<char> toString() noexcept
		{
			std::stringstream ss;
			ss << collums[0].x << "  " << collums[1].x << "  " << collums[2].x << '\n';
			ss << collums[0].y << "  " << collums[1].y << "  " << collums[2].y << '\n';
			ss << collums[0].z << "  " << collums[1].z << "  " << collums[2].z;
			return ss.str();
		}

		[[nodiscard]] col_type& operator[](size_t i)
		{
			assert(i >= 0 || i < collumCount());
			return collums[i];
		}

		[[nodiscard]] constexpr const col_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < collumCount());
			return collums[i];
		}



		template <typename X>
		constexpr type operator+(const Matrix<3, 3, X>& rhs) noexcept
		{
			return type(collums[0] + rhs.collums[0], collums[1] + rhs.collums[1], collums[2] + rhs.collums[2]);
		}

		template <typename X>
		constexpr type operator-(const Matrix<3, 3, X>& rhs) noexcept
		{
			return type(collums[0] - rhs.collums[0], collums[1] - rhs.collums[1], collums[2] - rhs.collums[2]);
		}

		template <typename X>
		constexpr type operator*(const Matrix<3, 3, X>& rhs) noexcept
		{
			const col_type SrcA0 = collums[0];
			const col_type SrcA1 = collums[1];
			const col_type SrcA2 = collums[2];

			const col_type SrcB0 = rhs[0];
			const col_type SrcB1 = rhs[1];
			const col_type SrcB2 = rhs[2];

			Matrix<3, 3, T> Result;
			Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2];
			Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2];
			Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2];
			return type{ Result };
		}


		/*
		template <typename X>
		constexpr type operator/(const Matrix<4, X>& rhs)
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		template <typename X>
		constexpr type operator%(const Matrix<4, X>& rhs)
		{
			return type(x % rhs.x, y % rhs.y, z % rhs.z, w % rhs.w);
		}
		*/

		template <typename X>
		constexpr type& operator+=(const Matrix<3, 3, X>& rhs) noexcept
		{
			collums[0] += rhs.collums[0];
			collums[1] += rhs.collums[1];
			collums[2] += rhs.collums[2];
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const Matrix<3, 3, X>& rhs) noexcept
		{
			collums[0] -= rhs.collums[0];
			collums[1] -= rhs.collums[1];
			collums[2] -= rhs.collums[2];
			return *this;
		}


		template <typename X>
		constexpr type& operator*=(const Matrix<3, 3, X>& rhs) noexcept
		{
			return (*this = *this * rhs);
		}



		/*
		template <typename X>
		constexpr type& operator/=(const Matrix<4, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		template <typename X>
		constexpr type& operator%=(const Matrix<4, X>& rhs)
		{
			x %= rhs.x;
			y %= rhs.y;
			z %= rhs.z;
			w %= rhs.w;
			return *this;
		}
		*/
		//

		template <typename X>
		constexpr type& operator+=(const X& scalar) noexcept
		{
			collums[0] += scalar;
			collums[1] += scalar;
			collums[2] += scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const X& scalar) noexcept
		{
			collums[0] -= scalar;
			collums[1] -= scalar;
			collums[2] -= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator*=(const X& scalar) noexcept
		{
			collums[0] *= scalar;
			collums[1] *= scalar;
			collums[2] *= scalar;
			return *this;
		}

		/*
		template <typename X>
		constexpr type& operator/=(const X& scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}


		template <typename X, std::enable_if_t<std::is_integral_v<X>, bool> = true>
		constexpr type& operator%=(const X& scalar)
		{
			x %= scalar;
			y %= scalar;
			z %= scalar;
			w %= scalar;
			return *this;
		}

		template <typename X, std::enable_if_t<std::is_floating_point_v<X>, bool> = true>
		constexpr type& operator%=(const X& scalar)
		{

			x %= std::fmod(x, scalar);
			y %= std::fmod(y, scalar);
			z %= std::fmod(z, scalar);
			w %= std::fmod(w, scalar);
			return *this;
		}
		*/

		//

		[[nodiscard]] inline constexpr bool operator==(const type& rhs) noexcept
		{
			return this->collums[0] == rhs.collums[0] && this->collums[1] == rhs.collums[1] && this->collums[2] == rhs.collums[2];
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this->collums[0] != rhs.collums[0] || this->collums[1] != rhs.collums[1] || this->collums[2] != rhs.collums[2];
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator++() noexcept
		{
			++collums[0];
			++collums[1];
			++collums[2];
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr type operator++(int) noexcept
		{
			type Matrix{ *this };
			++* this;
			return Matrix;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator--() noexcept
		{
			--collums[0];
			--collums[1];
			--collums[2];
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr type operator--(int) noexcept
		{
			type Matrix{ *this };
			--* this;
			return Matrix;
		}

		constexpr operator std::basic_string<char>() noexcept
		{
			return this->toString();
		}

		constexpr type inverse()
		{
			value_type OneOverDetercollumsinant = static_cast<value_type>(1) / (
				+collums[0][0] * (collums[1][1] * collums[2][2] - collums[2][1] * collums[1][2])
				- collums[1][0] * (collums[0][1] * collums[2][2] - collums[2][1] * collums[0][2])
				+ collums[2][0] * (collums[0][1] * collums[1][2] - collums[1][1] * collums[0][2]));

			type Inverse;
			Inverse[0][0] = +(collums[1][1] * collums[2][2] - collums[2][1] * collums[1][2]) * OneOverDetercollumsinant;
			Inverse[1][0] = -(collums[1][0] * collums[2][2] - collums[2][0] * collums[1][2]) * OneOverDetercollumsinant;
			Inverse[2][0] = +(collums[1][0] * collums[2][1] - collums[2][0] * collums[1][1]) * OneOverDetercollumsinant;
			Inverse[0][1] = -(collums[0][1] * collums[2][2] - collums[2][1] * collums[0][2]) * OneOverDetercollumsinant;
			Inverse[1][1] = +(collums[0][0] * collums[2][2] - collums[2][0] * collums[0][2]) * OneOverDetercollumsinant;
			Inverse[2][1] = -(collums[0][0] * collums[2][1] - collums[2][0] * collums[0][1]) * OneOverDetercollumsinant;
			Inverse[0][2] = +(collums[0][1] * collums[1][2] - collums[1][1] * collums[0][2]) * OneOverDetercollumsinant;
			Inverse[1][2] = -(collums[0][0] * collums[1][2] - collums[1][0] * collums[0][2]) * OneOverDetercollumsinant;
			Inverse[2][2] = +(collums[0][0] * collums[1][1] - collums[1][0] * collums[0][1]) * OneOverDetercollumsinant;

			return Inverse;
		}

		constexpr type transpose()
		{
			type Result;
			Result[0][0] = collums[0][0];
			Result[0][1] = collums[1][0];
			Result[0][2] = collums[2][0];

			Result[1][0] = collums[0][1];
			Result[1][1] = collums[1][1];
			Result[1][2] = collums[2][1];

			Result[2][0] = collums[0][2];
			Result[2][1] = collums[1][2];
			Result[2][2] = collums[2][2];
			return Result;
		}

		constexpr value_type determinant()
		{
			return
				+collums[0][0] * (collums[1][1] * collums[2][2] - collums[2][1] * collums[1][2])
				- collums[1][0] * (collums[0][1] * collums[2][2] - collums[2][1] * collums[0][2])
				+ collums[2][0] * (collums[0][1] * collums[1][2] - collums[1][1] * collums[0][2]);
		}
	};

	template<typename T>
	constexpr Matrix<3, 3, T> operator+(const Matrix<3, 3, T>& matrix) noexcept
	{
		return matrix;
	}

	template<typename T>
	constexpr Matrix<3, 3, T> operator-(const Matrix<3, 3, T>& matrix) noexcept
	{
		return Matrix<3, 3, T>(
			-matrix.collums[0],
			-matrix.collums[1],
			-matrix.collums[2]);
	}

	using Matrix3x3 = typename Matrix<3, 3, float>;
}