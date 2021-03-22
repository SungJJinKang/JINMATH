#pragma once
#include "Matrix.h"

#include "Vector3.h"
namespace math
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

		[[nodiscard]] inline static SIMD_CONSTEXPR size_t columnCount()  noexcept { return 3; }
		col_type columns[3];

		const T* data() const
		{
			return &(columns[0].x);
		}

		static const type identify;

		SIMD_CONSTEXPR Matrix() noexcept : columns{}
		{

		}
		
		/// <summary>
		/// diagonal matrix
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		SIMD_CONSTEXPR explicit Matrix(value_type value) noexcept 
			: columns{ 
			col_type(value, 0, 0),
			col_type(0, value, 0), 
			col_type(0, 0, value) }
		{
		}

		/// <summary>
		/// diagonal matrix
		/// </summary>
		/// <typeparam name="X"></typeparam>
		/// <param name="value"></param>
		/// <returns></returns>
		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true >
		SIMD_CONSTEXPR Matrix(X value) noexcept
			: columns{ 
			col_type(value, 0, 0), 
			col_type(0, value, 0), 
			col_type(0, 0, value) }
		{
		}

		SIMD_CONSTEXPR Matrix
		(
			value_type x0, value_type y0, value_type z0,
			value_type x1, value_type y1, value_type z1,
			value_type x2, value_type y2, value_type z2
		) noexcept : columns{
			col_type(x0, x1, x2),
			col_type(y0, y1, y2),
			col_type(z0, z1, z2) }
		{
		}

		template <
			typename X0, typename Y0, typename Z0,
			typename X1, typename Y1, typename Z1,
			typename X2, typename Y2, typename Z2
		>
			SIMD_CONSTEXPR Matrix
			(
				X0 x0, Y0 y0, Z0 z0,
				X1 x1, Y1 y1, Z1 z1,
				X2 x2, Y2 y2, Z2 z2
			) noexcept : columns{
				col_type(x0, x1, x2),
				col_type(y0, y1, y2),
				col_type(z0, z1, z2)}
		{
		}

		SIMD_CONSTEXPR Matrix(col_type column0Value, col_type column1Value, col_type column2Value) noexcept
			: columns{ column0Value, column1Value, column2Value }
		{
		}

		template <typename X, typename Y, typename Z>
		SIMD_CONSTEXPR Matrix(col_type_template<X> column0, col_type_template<Y> column1, col_type_template<Z> column2) noexcept
			: columns{ column0, column1, column2 }
		{
		}

		SIMD_CONSTEXPR explicit Matrix(const type& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], matrix.columns[2] }
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Matrix(const Matrix<1, 1, X>& matrix) noexcept
			: columns{ matrix.columns[0], {0, 1, 0}, {0, 0, 1} }
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Matrix(const Matrix<2, 2, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], {0, 0, 1} }
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Matrix(const Matrix<3, 3, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], matrix.columns[2] }
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Matrix(const Matrix<4, 4, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], matrix.columns[2] }
		{
		}

		SIMD_CONSTEXPR type& operator=(value_type value) noexcept
		{
			columns[0] = value;
			columns[1] = value;
			columns[2] = value;
			return *this;
		}

		SIMD_CONSTEXPR type& operator=(const type& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = matrix.columns[2];
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Matrix<1, 1, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = 0;
			columns[2] = 0;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Matrix<2, 2, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = 0;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Matrix<3, 3, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = matrix.columns[2];
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Matrix<4, 4, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = matrix.columns[2];
			return *this;
		}

		// 		Matrix(const type&) = default;
		// 		Matrix(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		SIMD_CONSTEXPR std::basic_string<char> toString() const noexcept
		{
			std::stringstream ss;
			ss << columns[0].x << "  " << columns[1].x << "  " << columns[2].x << '\n';
			ss << columns[0].y << "  " << columns[1].y << "  " << columns[2].y << '\n';
			ss << columns[0].z << "  " << columns[1].z << "  " << columns[2].z;
			return ss.str();
		}

		[[nodiscard]] SIMD_CONSTEXPR col_type& operator[](size_t i)
		{
			assert(i >= 0 || i < columnCount());
			return columns[i];
		}

		[[nodiscard]] SIMD_CONSTEXPR const col_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < columnCount());
			return columns[i];
		}



		template <typename X>
		SIMD_CONSTEXPR type operator+(const Matrix<3, 3, X>& rhs) noexcept
		{
			return type(columns[0] + rhs.columns[0], columns[1] + rhs.columns[1], columns[2] + rhs.columns[2]);
		}

		template <typename X>
		SIMD_CONSTEXPR type operator-(const Matrix<3, 3, X>& rhs) noexcept
		{
			return type(columns[0] - rhs.columns[0], columns[1] - rhs.columns[1], columns[2] - rhs.columns[2]);
		}

		template <typename X>
		SIMD_CONSTEXPR type operator*(const Matrix<3, 3, X>& rhs) noexcept
		{
			const col_type SrcA0 = columns[0];
			const col_type SrcA1 = columns[1];
			const col_type SrcA2 = columns[2];

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
		SIMD_CONSTEXPR type operator/(const Matrix<4, X>& rhs)
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		template <typename X>
		SIMD_CONSTEXPR type operator%(const Matrix<4, X>& rhs)
		{
			return type(x % rhs.x, y % rhs.y, z % rhs.z, w % rhs.w);
		}
		*/

		template <typename X>
		SIMD_CONSTEXPR type& operator+=(const Matrix<3, 3, X>& rhs) noexcept
		{
			columns[0] += rhs.columns[0];
			columns[1] += rhs.columns[1];
			columns[2] += rhs.columns[2];
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator-=(const Matrix<3, 3, X>& rhs) noexcept
		{
			columns[0] -= rhs.columns[0];
			columns[1] -= rhs.columns[1];
			columns[2] -= rhs.columns[2];
			return *this;
		}


		template <typename X>
		SIMD_CONSTEXPR type& operator*=(const Matrix<3, 3, X>& rhs) noexcept
		{
			return (*this = *this * rhs);
		}



		/*
		template <typename X>
		SIMD_CONSTEXPR type& operator/=(const Matrix<4, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator%=(const Matrix<4, X>& rhs)
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
		SIMD_CONSTEXPR type& operator+=(const X& scalar) noexcept
		{
			columns[0] += scalar;
			columns[1] += scalar;
			columns[2] += scalar;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator-=(const X& scalar) noexcept
		{
			columns[0] -= scalar;
			columns[1] -= scalar;
			columns[2] -= scalar;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator*=(const X& scalar) noexcept
		{
			columns[0] *= scalar;
			columns[1] *= scalar;
			columns[2] *= scalar;
			return *this;
		}

		/*
		template <typename X>
		SIMD_CONSTEXPR type& operator/=(const X& scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}


		template <typename X, std::enable_if_t<std::is_integral_v<X>, bool> = true>
		SIMD_CONSTEXPR type& operator%=(const X& scalar)
		{
			x %= scalar;
			y %= scalar;
			z %= scalar;
			w %= scalar;
			return *this;
		}

		template <typename X, std::enable_if_t<std::is_floating_point_v<X>, bool> = true>
		SIMD_CONSTEXPR type& operator%=(const X& scalar)
		{

			x %= std::fmod(x, scalar);
			y %= std::fmod(y, scalar);
			z %= std::fmod(z, scalar);
			w %= std::fmod(w, scalar);
			return *this;
		}
		*/

		//

		[[nodiscard]] inline SIMD_CONSTEXPR bool operator==(const type& rhs) noexcept
		{
			return this->columns[0] == rhs.columns[0] && this->columns[1] == rhs.columns[1] && this->columns[2] == rhs.columns[2];
		}

		[[nodiscard]] SIMD_CONSTEXPR bool operator!=(const type& rhs) noexcept
		{
			return this->columns[0] != rhs.columns[0] || this->columns[1] != rhs.columns[1] || this->columns[2] != rhs.columns[2];
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		[[nodiscard]] inline SIMD_CONSTEXPR bool operator==(const X& number) noexcept
		{
			return this->columns[0] == number && this->columns[1] == number && this->columns[2] == number;
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		[[nodiscard]] inline SIMD_CONSTEXPR bool operator!=(const X& number) noexcept
		{
			return this->columns[0] != number || this->columns[1] != number || this->columns[2] != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		SIMD_CONSTEXPR type& operator++() noexcept
		{
			++columns[0];
			++columns[1];
			++columns[2];
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		SIMD_CONSTEXPR type operator++(int) noexcept
		{
			type Matrix{ *this };
			++* this;
			return Matrix;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		SIMD_CONSTEXPR type& operator--() noexcept
		{
			--columns[0];
			--columns[1];
			--columns[2];
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		SIMD_CONSTEXPR type operator--(int) noexcept
		{
			type Matrix{ *this };
			--* this;
			return Matrix;
		}

		SIMD_CONSTEXPR operator std::basic_string<char>() noexcept
		{
			return this->toString();
		}

		template <typename U = T, std::enable_if_t<std::is_signed_v<U>, bool> = true>
		SIMD_CONSTEXPR type inverse()
		{
			value_type OneOverDetercolumnsinant = static_cast<value_type>(1) / (
				+columns[0][0] * (columns[1][1] * columns[2][2] - columns[2][1] * columns[1][2])
				- columns[1][0] * (columns[0][1] * columns[2][2] - columns[2][1] * columns[0][2])
				+ columns[2][0] * (columns[0][1] * columns[1][2] - columns[1][1] * columns[0][2]));

			type Inverse;
			Inverse[0][0] = +(columns[1][1] * columns[2][2] - columns[2][1] * columns[1][2]) * OneOverDetercolumnsinant;
			Inverse[1][0] = -(columns[1][0] * columns[2][2] - columns[2][0] * columns[1][2]) * OneOverDetercolumnsinant;
			Inverse[2][0] = +(columns[1][0] * columns[2][1] - columns[2][0] * columns[1][1]) * OneOverDetercolumnsinant;
			Inverse[0][1] = -(columns[0][1] * columns[2][2] - columns[2][1] * columns[0][2]) * OneOverDetercolumnsinant;
			Inverse[1][1] = +(columns[0][0] * columns[2][2] - columns[2][0] * columns[0][2]) * OneOverDetercolumnsinant;
			Inverse[2][1] = -(columns[0][0] * columns[2][1] - columns[2][0] * columns[0][1]) * OneOverDetercolumnsinant;
			Inverse[0][2] = +(columns[0][1] * columns[1][2] - columns[1][1] * columns[0][2]) * OneOverDetercolumnsinant;
			Inverse[1][2] = -(columns[0][0] * columns[1][2] - columns[1][0] * columns[0][2]) * OneOverDetercolumnsinant;
			Inverse[2][2] = +(columns[0][0] * columns[1][1] - columns[1][0] * columns[0][1]) * OneOverDetercolumnsinant;

			return Inverse;
		}

		SIMD_CONSTEXPR type transpose()
		{
			type Result;
			Result[0][0] = columns[0][0];
			Result[0][1] = columns[1][0];
			Result[0][2] = columns[2][0];

			Result[1][0] = columns[0][1];
			Result[1][1] = columns[1][1];
			Result[1][2] = columns[2][1];

			Result[2][0] = columns[0][2];
			Result[2][1] = columns[1][2];
			Result[2][2] = columns[2][2];
			return Result;
		}

		SIMD_CONSTEXPR value_type determinant()
		{
			return
				+columns[0][0] * (columns[1][1] * columns[2][2] - columns[2][1] * columns[1][2])
				- columns[1][0] * (columns[0][1] * columns[2][2] - columns[2][1] * columns[0][2])
				+ columns[2][0] * (columns[0][1] * columns[1][2] - columns[1][1] * columns[0][2]);
		}

		SIMD_CONSTEXPR auto trace()
		{
			return columns[0][0] + columns[1][1] + columns[2][2];
		}
	};

	template<typename T>
	SIMD_CONSTEXPR Matrix<3, 3, T> operator+(const Matrix<3, 3, T>& matrix) noexcept
	{
		return matrix;
	}

	template<typename T>
	SIMD_CONSTEXPR Matrix<3, 3, T> operator-(const Matrix<3, 3, T>& matrix) noexcept
	{
		return Matrix<3, 3, T>(
			-matrix.columns[0],
			-matrix.columns[1],
			-matrix.columns[2]);
	}

	using Matrix3x3 = typename Matrix<3, 3, float>;
}