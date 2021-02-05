#pragma once
#include "Matrix.h"

#include "Vector4.h"
#include "Quaternion.h"
namespace math
{
	template <typename T>
	struct Matrix<4, 4, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Matrix<4, 4, T>;
		template <typename T2>
		using col_type_template = Vector<4, T2>;
		using col_type = Vector<4, T>;

		[[nodiscard]] inline static constexpr size_t columnCount()  noexcept { return 4; }
		col_type columns[4];

		static const type identify;

		constexpr Matrix() noexcept : columns{}
		{

		}

		/// <summary>
		/// diagonal matrix
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		constexpr explicit Matrix(value_type value) noexcept
			: columns{ 
			col_type(value, 0, 0, 0), 
			col_type(0, value, 0, 0), 
			col_type(0, 0, value, 0), 
			col_type(0, 0, 0, value) }
		{
		}

		/// <summary>
		/// diagonal matrix
		/// </summary>
		/// <typeparam name="X"></typeparam>
		/// <param name="value"></param>
		/// <returns></returns>
		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		constexpr Matrix(X value) noexcept
			: columns{ 
			col_type(value, 0, 0, 0), 
			col_type(0, value, 0, 0), 
			col_type(0, 0, value, 0), 
			col_type(0, 0, 0, value) }
		{
		}

		constexpr Matrix
		(
			value_type x0, value_type y0, value_type z0, value_type w0,
			value_type x1, value_type y1, value_type z1, value_type w1,
			value_type x2, value_type y2, value_type z2, value_type w2,
			value_type x3, value_type y3, value_type z3, value_type w3
		) noexcept : columns{
			col_type(x0, x1, x2, x3),
			col_type(y0, y1, y2, y3),
			col_type(z0, z1, z2, z3),
			col_type(w0, w1, w2, w3) }
		{
		}

		template <
			typename X0, typename Y0, typename Z0, typename W0,
			typename X1, typename Y1, typename Z1, typename W1,
			typename X2, typename Y2, typename Z2, typename W2,
			typename X3, typename Y3, typename Z3, typename W3
		>
		constexpr Matrix
		(
			X0 x0, Y0 y0, Z0 z0, W0 w0,
			X1 x1, Y1 y1, Z1 z1, W1 w1,
			X2 x2, Y2 y2, Z2 z2, W2 w2,
			X3 x3, Y3 y3, Z3 z3, W3 w3
		) noexcept : columns{
			col_type(x0, x1, x2, x3),
			col_type(y0, y1, y2, y3),
			col_type(z0, z1, z2, z3),
			col_type(w0, w1, w2, w3)}
		{
		}
		
		constexpr Matrix(col_type column0Value, col_type column1Value, col_type column2Value, col_type column3Value) noexcept
			: columns{ column0Value, column1Value, column2Value, column3Value }
		{
		}

		template <typename X, typename Y, typename Z, typename W>
		constexpr Matrix(col_type_template<X> column0, col_type_template<Y> column1, col_type_template<Z> column2, col_type_template<W> column3) noexcept
			: columns{ column0, column1, column2, column3 }
		{
		}

		constexpr explicit Matrix(const type& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], matrix.columns[2], matrix.columns[3] }
		{
		}

		template <typename X>
		constexpr Matrix(const Matrix<1, 1, X>& matrix) noexcept
			: columns{ matrix.columns[0], 0, 0, 0 }
		{
		}

		template <typename X>
		constexpr Matrix(const Matrix<2, 2, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], 0, 0 }
		{
		}

		template <typename X>
		constexpr Matrix(const Matrix<3, 3, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], matrix.columns[2], 0 }
		{
		}

		template <typename X>
		constexpr Matrix(const Matrix<4, 4, X>& matrix) noexcept
			: columns { matrix.columns[0], matrix.columns[1], matrix.columns[2], matrix.columns[3] }
		{
		}

		constexpr type& operator=(value_type value) noexcept
		{
			columns[0] = value;
			columns[1] = value;
			columns[2] = value;
			columns[3] = value;
			return *this;
		}

		constexpr type& operator=(const type& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = matrix.columns[2];
			columns[3] = matrix.columns[3];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<1, 1, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = 0;
			columns[2] = 0;
			columns[3] = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<2, 2, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = 0;
			columns[3] = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<3, 3, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = matrix.columns[2];
			columns[3] = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<4, 4, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = matrix.columns[2];
			columns[3] = matrix.columns[3];
			return *this;
		}

		// 		Matrix(const type&) = default;
		// 		Matrix(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		constexpr std::basic_string<char> toString() noexcept
		{
			std::stringstream ss;
			ss << columns[0].x << "  " << columns[1].x << "  " << columns[2].x << "  " << columns[3].x << '\n';
			ss << columns[0].y << "  " << columns[1].y << "  " << columns[2].y << "  " << columns[3].y << '\n';
			ss << columns[0].z << "  " << columns[1].z << "  " << columns[2].z << "  " << columns[3].z << '\n';
			ss << columns[0].w << "  " << columns[1].w << "  " << columns[2].w << "  " << columns[3].w;
			return ss.str();
		}

		[[nodiscard]] col_type& operator[](size_t i)
		{
			assert(i >= 0 || i < columnCount());
			return columns[i];
		}

		[[nodiscard]] constexpr const col_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < columnCount());
			return columns[i];
		}



		template <typename X>
		constexpr type operator+(const Matrix<4, 4, X>& rhs) noexcept
		{
			return type(columns[0] + rhs.columns[0], columns[1] + rhs.columns[1], columns[2] + rhs.columns[2], columns[3] + rhs.columns[3]);
		}

		template <typename X>
		constexpr type operator-(const Matrix<4, 4, X>& rhs) noexcept
		{
			return type(columns[0] - rhs.columns[0], columns[1] - rhs.columns[1], columns[2] - rhs.columns[2], columns[3] - rhs.columns[3]);
		}

		template <typename X>
		constexpr type operator*(const Matrix<4, 4, X>& rhs) noexcept
		{
			const col_type SrcA0 = columns[0];
			const col_type SrcA1 = columns[1];
			const col_type SrcA2 = columns[2];
			const col_type SrcA3 = columns[3];

			const col_type SrcB0 = rhs[0];
			const col_type SrcB1 = rhs[1];
			const col_type SrcB2 = rhs[2];
			const col_type SrcB3 = rhs[3];

			Matrix<4, 4, T> Result;
			Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3];
			Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3];
			Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3];
			Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3];
			return Result;
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
		constexpr type& operator+=(const Matrix<4, 4, X>& rhs) noexcept
		{
			columns[0] += rhs.columns[0];
			columns[1] += rhs.columns[1];
			columns[2] += rhs.columns[2];
			columns[3] += rhs.columns[3];
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const Matrix<4, 4, X>& rhs) noexcept
		{
			columns[0] -= rhs.columns[0];
			columns[1] -= rhs.columns[1];
			columns[2] -= rhs.columns[2];
			columns[3] -= rhs.columns[3];
			return *this;
		}

		
		template <typename X>
		constexpr type& operator*=(const Matrix<4, 4, X>& rhs) noexcept
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
			columns[0] += scalar;
			columns[1] += scalar;
			columns[2] += scalar;
			columns[3] += scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const X& scalar) noexcept
		{
			columns[0] -= scalar;
			columns[1] -= scalar;
			columns[2] -= scalar;
			columns[3] -= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator*=(const X& scalar) noexcept
		{
			columns[0] *= scalar;
			columns[1] *= scalar;
			columns[2] *= scalar;
			columns[3] *= scalar;
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
			return this->columns[0] == rhs.columns[0] && this->columns[1] == rhs.columns[1] && this->columns[2] == rhs.columns[2] && this->columns[3] == rhs.columns[3];
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this->columns[0] != rhs.columns[0] || this->columns[1] != rhs.columns[1] || this->columns[2] != rhs.columns[2] || this->columns[3] != rhs.columns[3];
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator++() noexcept
		{
			++columns[0];
			++columns[1];
			++columns[2];
			++columns[3];
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
			--columns[0];
			--columns[1];
			--columns[2];
			--columns[3];
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
			value_type Coef00 = columns[2][2] * columns[3][3] - columns[3][2] * columns[2][3];
			value_type Coef02 = columns[1][2] * columns[3][3] - columns[3][2] * columns[1][3];
			value_type Coef03 = columns[1][2] * columns[2][3] - columns[2][2] * columns[1][3];

			value_type Coef04 = columns[2][1] * columns[3][3] - columns[3][1] * columns[2][3];
			value_type Coef06 = columns[1][1] * columns[3][3] - columns[3][1] * columns[1][3];
			value_type Coef07 = columns[1][1] * columns[2][3] - columns[2][1] * columns[1][3];

			value_type Coef08 = columns[2][1] * columns[3][2] - columns[3][1] * columns[2][2];
			value_type Coef10 = columns[1][1] * columns[3][2] - columns[3][1] * columns[1][2];
			value_type Coef11 = columns[1][1] * columns[2][2] - columns[2][1] * columns[1][2];

			value_type Coef12 = columns[2][0] * columns[3][3] - columns[3][0] * columns[2][3];
			value_type Coef14 = columns[1][0] * columns[3][3] - columns[3][0] * columns[1][3];
			value_type Coef15 = columns[1][0] * columns[2][3] - columns[2][0] * columns[1][3];

			value_type Coef16 = columns[2][0] * columns[3][2] - columns[3][0] * columns[2][2];
			value_type Coef18 = columns[1][0] * columns[3][2] - columns[3][0] * columns[1][2];
			value_type Coef19 = columns[1][0] * columns[2][2] - columns[2][0] * columns[1][2];

			value_type Coef20 = columns[2][0] * columns[3][1] - columns[3][0] * columns[2][1];
			value_type Coef22 = columns[1][0] * columns[3][1] - columns[3][0] * columns[1][1];
			value_type Coef23 = columns[1][0] * columns[2][1] - columns[2][0] * columns[1][1];

			col_type Fac0(Coef00, Coef00, Coef02, Coef03);
			col_type Fac1(Coef04, Coef04, Coef06, Coef07);
			col_type Fac2(Coef08, Coef08, Coef10, Coef11);
			col_type Fac3(Coef12, Coef12, Coef14, Coef15);
			col_type Fac4(Coef16, Coef16, Coef18, Coef19);
			col_type Fac5(Coef20, Coef20, Coef22, Coef23);

			col_type Vec0(columns[1][0], columns[0][0], columns[0][0], columns[0][0]);
			col_type Vec1(columns[1][1], columns[0][1], columns[0][1], columns[0][1]);
			col_type Vec2(columns[1][2], columns[0][2], columns[0][2], columns[0][2]);
			col_type Vec3(columns[1][3], columns[0][3], columns[0][3], columns[0][3]);

			col_type Inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
			col_type Inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
			col_type Inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
			col_type Inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

			col_type SignA(+1, -1, +1, -1);
			col_type SignB(-1, +1, -1, +1);
			type Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

			col_type Row0(Inverse[0][0], Inverse[1][0], Inverse[2][0], Inverse[3][0]);

			col_type Dot0(columns[0] * Row0);
			value_type Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

			value_type OneOverDeterminant = static_cast<value_type>(1) / Dot1;

			return type{ Inverse * OneOverDeterminant };
		}

		constexpr type transpose()
		{
			type Result;
			Result[0][0] = columns[0][0];
			Result[0][1] = columns[1][0];
			Result[0][2] = columns[2][0];
			Result[0][3] = columns[3][0];

			Result[1][0] = columns[0][1];
			Result[1][1] = columns[1][1];
			Result[1][2] = columns[2][1];
			Result[1][3] = columns[3][1];

			Result[2][0] = columns[0][2];
			Result[2][1] = columns[1][2];
			Result[2][2] = columns[2][2];
			Result[2][3] = columns[3][2];

			Result[3][0] = columns[0][3];
			Result[3][1] = columns[1][3];
			Result[3][2] = columns[2][3];
			Result[3][3] = columns[3][3];
			return Result;
		}

		template <typename U = T, std::enable_if_t<std::is_signed_v<U>, bool> = true>
		constexpr value_type determinant()
		{
			value_type SubFactor00 = columns[2][2] * columns[3][3] - columns[3][2] * columns[2][3];
			value_type SubFactor01 = columns[2][1] * columns[3][3] - columns[3][1] * columns[2][3];
			value_type SubFactor02 = columns[2][1] * columns[3][2] - columns[3][1] * columns[2][2];
			value_type SubFactor03 = columns[2][0] * columns[3][3] - columns[3][0] * columns[2][3];
			value_type SubFactor04 = columns[2][0] * columns[3][2] - columns[3][0] * columns[2][2];
			value_type SubFactor05 = columns[2][0] * columns[3][1] - columns[3][0] * columns[2][1];

			col_type DetCof(
				+(columns[1][1] * SubFactor00 - columns[1][2] * SubFactor01 + columns[1][3] * SubFactor02),
				-(columns[1][0] * SubFactor00 - columns[1][2] * SubFactor03 + columns[1][3] * SubFactor04),
				+(columns[1][0] * SubFactor01 - columns[1][1] * SubFactor03 + columns[1][3] * SubFactor05),
				-(columns[1][0] * SubFactor02 - columns[1][1] * SubFactor04 + columns[1][2] * SubFactor05));

			return
				columns[0][0] * DetCof[0] + columns[0][1] * DetCof[1] +
				columns[0][2] * DetCof[2] + columns[0][3] * DetCof[3];
		}

		
		constexpr auto trace()
		{
			return columns[0][0] + columns[1][1] + columns[2][2] + columns[3][3];
		}
	};

	template<typename T>
	constexpr Matrix<4, 4, T> operator+(const Matrix<4, 4, T>& matrix) noexcept
	{
		return matrix;
	}

	template<typename T>
	constexpr Matrix<4, 4, T> operator-(const Matrix<4, 4, T>& matrix) noexcept
	{
		return Matrix<4, 4, T>(
			-matrix.columns[0],
			-matrix.columns[1],
			-matrix.columns[2],
			-matrix.columns[3]);
	}

	using Matrix4x4 = typename Matrix<4, 4, float>;
}