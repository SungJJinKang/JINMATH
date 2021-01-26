#pragma once
#include "Matrix.h"

#include "Vector4.h"
namespace Math
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

		[[nodiscard]] inline static constexpr size_t collumCount()  noexcept { return 4; }
		col_type collums[4];

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
			collums[0] = col_type(value , 0, 0, 0);
			collums[1] = col_type(0, value, 0, 0);
			collums[2] = col_type(0, 0, value, 0);
			collums[3] = col_type(0, 0, 0, value);
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
			collums[3] = col_type(0, 0, 0, value);
		}

		constexpr Matrix
		(
			value_type x0, value_type y0, value_type z0, value_type w0,
			value_type x1, value_type y1, value_type z1, value_type w1,
			value_type x2, value_type y2, value_type z2, value_type w2,
			value_type x3, value_type y3, value_type z3, value_type w3
		) noexcept :
			collums{
			col_type(x0, y0, z0, w0),
			col_type(x1, y1, z1, w1),
			col_type(x2, y2, z2, w2),
			col_type(x3, y3, z3, w3)}
		{
		}

		template <
			typename X0, typename Y0, typename Z0, typename W0,
			typename X1, typename Y1, typename Z1, typename W1,
			typename X2, typename Y2, typename Z2, typename W2,
			typename X3, typename Y3, typename Z3, typename W3>
		constexpr Matrix
		(
			X0 x0, Y0 y0, Z0 z0, W0 w0,
			X1 x1, Y1 y1, Z1 z1, W2 w1,
			X2 x2, Y2 y2, Z2 z2, W2 w2,
			X3 x3, Y3 y3, Z3 z3, W3 w3
		) noexcept :
			collums{
			col_type(x0, y0, z0, w0),
			col_type(x1, y1, z1, w1),
			col_type(x2, y2, z2, w2),
			col_type(x3, y3, z3, w3) }
		{
		}
		
		constexpr Matrix(col_type collum0Value, col_type collum1Value, col_type collum2Value, col_type collum3Value) noexcept
		{
			collums[0] = collum0Value;
			collums[1] = collum1Value;
			collums[2] = collum2Value;
			collums[3] = collum3Value;
		}

		template <typename X, typename Y, typename Z, typename W>
		constexpr Matrix(col_type_template<X> collum0, col_type_template<Y> collum1, col_type_template<Z> collum2, col_type_template<W> collum3) noexcept
		{
			collums[0] = collum0;
			collums[1] = collum1;
			collums[2] = collum2;
			collums[3] = collum3;
		}

		constexpr explicit Matrix(const Matrix<4, 4, T>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
			collums[3] = matrix.collums[3];
		}

		template <typename X>
		constexpr Matrix(const Matrix<1, 1, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = 0;
			collums[2] = 0;
			collums[3] = 0;
		}

		template <typename X>
		constexpr Matrix(const Matrix<2, 2, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = 0;
			collums[3] = 0;
		}

		template <typename X>
		constexpr Matrix(const Matrix<3, 3, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
			collums[3] = 0;
		}

		template <typename X>
		constexpr Matrix(const Matrix<4, 4, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
			collums[3] = matrix.collums[3];
		}

		constexpr type& operator=(value_type value) noexcept
		{
			collums[0] = value;
			collums[1] = value;
			collums[2] = value;
			collums[3] = value;
			return *this;
		}

		constexpr type& operator=(const Matrix<4, 4, T>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
			collums[3] = matrix.collums[3];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<1, 1, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = 0;
			collums[2] = 0;
			collums[3] = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<2, 2, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = 0;
			collums[3] = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<3, 3, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
			collums[3] = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<4, 4, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			collums[2] = matrix.collums[2];
			collums[3] = matrix.collums[3];
			return *this;
		}

		// 		Matrix(const type&) = default;
		// 		Matrix(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		constexpr std::basic_string<char> toString() noexcept
		{
			std::stringstream ss;
			ss << collums[0].x << "  " << collums[1].x << "  " << collums[2].x << "  " << collums[3].x << '\n';
			ss << collums[0].y << "  " << collums[1].y << "  " << collums[2].y << "  " << collums[3].y << '\n';
			ss << collums[0].z << "  " << collums[1].z << "  " << collums[2].z << "  " << collums[3].z << '\n';
			ss << collums[0].w << "  " << collums[1].w << "  " << collums[2].w << "  " << collums[3].w;
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
		constexpr type operator+(const Matrix<4, 4, X>& rhs) noexcept
		{
			return type(collums[0] + rhs.collums[0], collums[1] + rhs.collums[1], collums[2] + rhs.collums[2], collums[3] + rhs.collums[3]);
		}

		template <typename X>
		constexpr type operator-(const Matrix<4, 4, X>& rhs) noexcept
		{
			return type(collums[0] - rhs.collums[0], collums[1] - rhs.collums[1], collums[2] - rhs.collums[2], collums[3] - rhs.collums[3]);
		}

		template <typename X>
		constexpr type operator*(const Matrix<4, 4, X>& rhs) noexcept
		{
			const col_type SrcA0 = collums[0];
			const col_type SrcA1 = collums[1];
			const col_type SrcA2 = collums[2];
			const col_type SrcA3 = collums[3];

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
			collums[0] += rhs.collums[0];
			collums[1] += rhs.collums[1];
			collums[2] += rhs.collums[2];
			collums[3] += rhs.collums[3];
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const Matrix<4, 4, X>& rhs) noexcept
		{
			collums[0] -= rhs.collums[0];
			collums[1] -= rhs.collums[1];
			collums[2] -= rhs.collums[2];
			collums[3] -= rhs.collums[3];
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
			collums[0] += scalar;
			collums[1] += scalar;
			collums[2] += scalar;
			collums[3] += scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const X& scalar) noexcept
		{
			collums[0] -= scalar;
			collums[1] -= scalar;
			collums[2] -= scalar;
			collums[3] -= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator*=(const X& scalar) noexcept
		{
			collums[0] *= scalar;
			collums[1] *= scalar;
			collums[2] *= scalar;
			collums[3] *= scalar;
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
			return this->collums[0] == rhs.collums[0] && this->collums[1] == rhs.collums[1] && this->collums[2] == rhs.collums[2] && this->collums[3] == rhs.collums[3];
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this->collums[0] != rhs.collums[0] || this->collums[1] != rhs.collums[1] || this->collums[2] != rhs.collums[2] || this->collums[3] != rhs.collums[3];
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
			++collums[3];
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
			--collums[3];
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
			value_type Coef00 = collums[2][2] * collums[3][3] - collums[3][2] * collums[2][3];
			value_type Coef02 = collums[1][2] * collums[3][3] - collums[3][2] * collums[1][3];
			value_type Coef03 = collums[1][2] * collums[2][3] - collums[2][2] * collums[1][3];

			value_type Coef04 = collums[2][1] * collums[3][3] - collums[3][1] * collums[2][3];
			value_type Coef06 = collums[1][1] * collums[3][3] - collums[3][1] * collums[1][3];
			value_type Coef07 = collums[1][1] * collums[2][3] - collums[2][1] * collums[1][3];

			value_type Coef08 = collums[2][1] * collums[3][2] - collums[3][1] * collums[2][2];
			value_type Coef10 = collums[1][1] * collums[3][2] - collums[3][1] * collums[1][2];
			value_type Coef11 = collums[1][1] * collums[2][2] - collums[2][1] * collums[1][2];

			value_type Coef12 = collums[2][0] * collums[3][3] - collums[3][0] * collums[2][3];
			value_type Coef14 = collums[1][0] * collums[3][3] - collums[3][0] * collums[1][3];
			value_type Coef15 = collums[1][0] * collums[2][3] - collums[2][0] * collums[1][3];

			value_type Coef16 = collums[2][0] * collums[3][2] - collums[3][0] * collums[2][2];
			value_type Coef18 = collums[1][0] * collums[3][2] - collums[3][0] * collums[1][2];
			value_type Coef19 = collums[1][0] * collums[2][2] - collums[2][0] * collums[1][2];

			value_type Coef20 = collums[2][0] * collums[3][1] - collums[3][0] * collums[2][1];
			value_type Coef22 = collums[1][0] * collums[3][1] - collums[3][0] * collums[1][1];
			value_type Coef23 = collums[1][0] * collums[2][1] - collums[2][0] * collums[1][1];

			col_type Fac0(Coef00, Coef00, Coef02, Coef03);
			col_type Fac1(Coef04, Coef04, Coef06, Coef07);
			col_type Fac2(Coef08, Coef08, Coef10, Coef11);
			col_type Fac3(Coef12, Coef12, Coef14, Coef15);
			col_type Fac4(Coef16, Coef16, Coef18, Coef19);
			col_type Fac5(Coef20, Coef20, Coef22, Coef23);

			col_type Vec0(collums[1][0], collums[0][0], collums[0][0], collums[0][0]);
			col_type Vec1(collums[1][1], collums[0][1], collums[0][1], collums[0][1]);
			col_type Vec2(collums[1][2], collums[0][2], collums[0][2], collums[0][2]);
			col_type Vec3(collums[1][3], collums[0][3], collums[0][3], collums[0][3]);

			col_type Inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
			col_type Inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
			col_type Inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
			col_type Inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

			col_type SignA(+1, -1, +1, -1);
			col_type SignB(-1, +1, -1, +1);
			type Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

			col_type Row0(Inverse[0][0], Inverse[1][0], Inverse[2][0], Inverse[3][0]);

			col_type Dot0(collums[0] * Row0);
			value_type Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

			value_type OneOverDeterminant = static_cast<value_type>(1) / Dot1;

			return type{ Inverse * OneOverDeterminant };
		}

		constexpr type transpose()
		{
			type Result;
			Result[0][0] = collums[0][0];
			Result[0][1] = collums[1][0];
			Result[0][2] = collums[2][0];
			Result[0][3] = collums[3][0];

			Result[1][0] = collums[0][1];
			Result[1][1] = collums[1][1];
			Result[1][2] = collums[2][1];
			Result[1][3] = collums[3][1];

			Result[2][0] = collums[0][2];
			Result[2][1] = collums[1][2];
			Result[2][2] = collums[2][2];
			Result[2][3] = collums[3][2];

			Result[3][0] = collums[0][3];
			Result[3][1] = collums[1][3];
			Result[3][2] = collums[2][3];
			Result[3][3] = collums[3][3];
			return Result;
		}

		constexpr value_type determinant()
		{
			value_type SubFactor00 = collums[2][2] * collums[3][3] - collums[3][2] * collums[2][3];
			value_type SubFactor01 = collums[2][1] * collums[3][3] - collums[3][1] * collums[2][3];
			value_type SubFactor02 = collums[2][1] * collums[3][2] - collums[3][1] * collums[2][2];
			value_type SubFactor03 = collums[2][0] * collums[3][3] - collums[3][0] * collums[2][3];
			value_type SubFactor04 = collums[2][0] * collums[3][2] - collums[3][0] * collums[2][2];
			value_type SubFactor05 = collums[2][0] * collums[3][1] - collums[3][0] * collums[2][1];

			col_type DetCof(
				+(collums[1][1] * SubFactor00 - collums[1][2] * SubFactor01 + collums[1][3] * SubFactor02),
				-(collums[1][0] * SubFactor00 - collums[1][2] * SubFactor03 + collums[1][3] * SubFactor04),
				+(collums[1][0] * SubFactor01 - collums[1][1] * SubFactor03 + collums[1][3] * SubFactor05),
				-(collums[1][0] * SubFactor02 - collums[1][1] * SubFactor04 + collums[1][2] * SubFactor05));

			return
				collums[0][0] * DetCof[0] + collums[0][1] * DetCof[1] +
				collums[0][2] * DetCof[2] + collums[0][3] * DetCof[3];
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
			-matrix.collums[0],
			-matrix.collums[1],
			-matrix.collums[2],
			-matrix.collums[3]);
	}

	using Matrix4x4 = typename Matrix<4, 4, float>;
}