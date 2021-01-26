#pragma once
#include "Matrix.h"

#include "Vector2.h"
namespace Math
{
	template <typename T>
	struct Matrix<2, 2, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Matrix<2, 2, T>;
		template <typename T2>
		using col_type_template = Vector<2, T2>;
		using col_type = Vector<2, T>;

		[[nodiscard]] inline static constexpr size_t collumCount()  noexcept { return 2; }
		col_type collums[2];

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
		}

		constexpr Matrix
		(
			value_type x0, value_type y0,
			value_type x1, value_type y1
		) noexcept :
			collums{
			col_type(x0, y0),
			col_type(x1, y1)
			}
		{
		}

		template <
			typename X0, typename Y0,
			typename X1, typename Y1>
			constexpr Matrix
			(
				X0 x0, Y0 y0,
				X1 x1, Y1 y1
			) noexcept :
			collums{
			col_type(x0, y0),
			col_type(x1, y1) }
		{
		}

		constexpr Matrix(col_type collum0Value, col_type collum1Value) noexcept
		{
			collums[0] = collum0Value;
			collums[1] = collum1Value;
		}

		template <typename X, typename Y>
		constexpr Matrix(col_type_template<X> collum0, col_type_template<Y> collum1) noexcept
		{
			collums[0] = collum0;
			collums[1] = collum1;
		}

		constexpr explicit Matrix(const Matrix<2, 2, T>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
		}

		template <typename X>
		constexpr Matrix(const Matrix<1, 1, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = 0;
		}

		template <typename X>
		constexpr Matrix(const Matrix<2, 2, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
		}

		template <typename X>
		constexpr Matrix(const Matrix<3, 3, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
		}

		template <typename X>
		constexpr Matrix(const Matrix<4, 4, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
		}

		constexpr type& operator=(value_type value) noexcept
		{
			collums[0] = value;
			collums[1] = value;
			return *this;
		}

		constexpr type& operator=(const Matrix<2, 2, T>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<1, 1, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = 0;
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<2, 2, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<3, 3, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<4, 4, X>& matrix) noexcept
		{
			collums[0] = matrix.collums[0];
			collums[1] = matrix.collums[1];
			return *this;
		}

		// 		Matrix(const type&) = default;
		// 		Matrix(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		constexpr std::basic_string<char> toString() noexcept
		{
			std::stringstream ss;
			ss << collums[0].x << "  " << collums[1].x << '\n';
			ss << collums[0].y << "  " << collums[1].y << '\n';
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
		constexpr type operator+(const Matrix<2, 2, X>& rhs) noexcept
		{
			return type(collums[0] + rhs.collums[0], collums[1] + rhs.collums[1]);
		}

		template <typename X>
		constexpr type operator-(const Matrix<2, 2, X>& rhs) noexcept
		{
			return type(collums[0] - rhs.collums[0], collums[1] - rhs.collums[1]);
		}

		template <typename X>
		constexpr type operator*(const Matrix<2, 2, X>& rhs) noexcept
		{
			const col_type SrcA0 = collums[0];
			const col_type SrcA1 = collums[1];

			const col_type SrcB0 = rhs[0];
			const col_type SrcB1 = rhs[1];

			Matrix<2, 2, T> Result;
			Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1];
			Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1];
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
		constexpr type& operator+=(const Matrix<2, 2, X>& rhs) noexcept
		{
			collums[0] += rhs.collums[0];
			collums[1] += rhs.collums[1];
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const Matrix<2, 2, X>& rhs) noexcept
		{
			collums[0] -= rhs.collums[0];
			collums[1] -= rhs.collums[1];
			return *this;
		}


		template <typename X>
		constexpr type& operator*=(const Matrix<2, 2, X>& rhs) noexcept
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
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const X& scalar) noexcept
		{
			collums[0] -= scalar;
			collums[1] -= scalar;
			return *this;
		}

		template <typename X>
		constexpr type& operator*=(const X& scalar) noexcept
		{
			collums[0] *= scalar;
			collums[1] *= scalar;
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
			return this->collums[0] == rhs.collums[0] && this->collums[1] == rhs.collums[1];
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this->collums[0] != rhs.collums[0] || this->collums[1] != rhs.collums[1];
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator++() noexcept
		{
			++collums[0];
			++collums[1];
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
				+collums[0][0] * collums[1][1]
				- collums[1][0] * collums[0][1]);

			type Inverse(
				+collums[1][1] * OneOverDetercollumsinant,
				-collums[0][1] * OneOverDetercollumsinant,
				-collums[1][0] * OneOverDetercollumsinant,
				+collums[0][0] * OneOverDetercollumsinant);

			return Inverse;
		}

		constexpr type transpose()
		{
			type Result;
			Result[0][0] = collums[0][0];
			Result[0][1] = collums[1][0];
			Result[1][0] = collums[0][1];
			Result[1][1] = collums[1][1];
			return Result;
		}

		constexpr value_type determinant()
		{
			return collums[0][0] * collums[1][1] - collums[1][0] * collums[0][1];
		}
	};

	template<typename T>
	constexpr Matrix<2, 2, T> operator+(const Matrix<2, 2, T>& matrix) noexcept
	{
		return matrix;
	}

	template<typename T>
	constexpr Matrix<2, 2, T> operator-(const Matrix<2, 2, T>& matrix) noexcept
	{
		return Matrix<2, 2, T>(
			-matrix.collums[0],
			-matrix.collums[1]);
	}

	using Matrix2x2 = typename Matrix<2, 2, float>;
}