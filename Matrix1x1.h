#pragma once
#include "Matrix.h"

#include "Vector1.h"
namespace math
{
	template <typename T>
	struct Matrix<1, 1, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Matrix<1, 1, T>;
		template <typename T2>
		using col_type_template = Vector<1, T2>;
		using col_type = Vector<1, T>;
		
		[[nodiscard]] inline static SIMD_CONSTEXPR size_t columnCount()  noexcept { return 1; }
		col_type columns[1]; // don't change to column

		const T* data() const
		{
			return &(columns[0].x);
		}

		static const type identify;

		SIMD_CONSTEXPR Matrix() noexcept : columns{}
		{

		}

		SIMD_CONSTEXPR explicit Matrix(value_type value) noexcept
			: columns{ value }
		{
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		SIMD_CONSTEXPR Matrix(X value) noexcept
			: columns{ static_cast<T>(value) }
		{
		}


		SIMD_CONSTEXPR Matrix(col_type column0Value) noexcept
			: columns{ column0Value }
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Matrix(col_type_template<X> column0) noexcept
			: columns{ column0 }
		{
		}

		SIMD_CONSTEXPR explicit Matrix(const type& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Matrix(const Matrix<1, 1, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Matrix(const Matrix<2, 2, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Matrix(const Matrix<3, 3, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		SIMD_CONSTEXPR Matrix(const Matrix<4, 4, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		SIMD_CONSTEXPR type& operator=(value_type value) noexcept
		{
			columns[0] = value;
			return *this;
		}

		SIMD_CONSTEXPR type& operator=(const type& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Matrix<1, 1, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Matrix<2, 2, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Matrix<3, 3, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator=(const Matrix<4, 4, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		// 		Matrix(const type&) = default;
		// 		Matrix(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		SIMD_CONSTEXPR std::basic_string<char> toString() const noexcept
		{
			std::stringstream ss;
			ss << columns[0].x << '\n';
			return ss.str();
		}

		[[nodiscard]] SIMD_CONSTEXPR col_type& operator[](size_t i)
		{
			assert(i == 0);
			return columns[i];
		}

		[[nodiscard]] SIMD_CONSTEXPR const col_type& operator[](size_t i) const
		{
			assert(i == 0);
			return columns[i];
		}



		template <typename X>
		SIMD_CONSTEXPR type operator+(const Matrix<1, 1, X>& rhs) noexcept
		{
			return type(columns[0] + rhs.columns[0]);
		}

		template <typename X>
		SIMD_CONSTEXPR type operator-(const Matrix<1, 1, X>& rhs) noexcept
		{
			return type(columns[0] - rhs.columns[0]);
		}

		template <typename X>
		SIMD_CONSTEXPR type operator*(const Matrix<1, 1, X>& rhs) noexcept
		{
			return Matrix<1, 1, T>(columns[0] * rhs.columns[0]);
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
		SIMD_CONSTEXPR type& operator+=(const Matrix<1, 1, X>& rhs) noexcept
		{
			columns[0] += rhs.columns[0];
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator-=(const Matrix<1, 1, X>& rhs) noexcept
		{
			columns[0] -= rhs.columns[0];
			return *this;
		}


		template <typename X>
		SIMD_CONSTEXPR type& operator*=(const Matrix<1, 1, X>& rhs) noexcept
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
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator-=(const X& scalar) noexcept
		{
			columns[0] -= scalar;
			return *this;
		}

		template <typename X>
		SIMD_CONSTEXPR type& operator*=(const X& scalar) noexcept
		{
			columns[0] *= scalar;
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
			return this->columns[0] == rhs.columns[0];
		}

		[[nodiscard]] SIMD_CONSTEXPR bool operator!=(const type& rhs) noexcept
		{
			return this->columns[0] != rhs.columns[0];
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		[[nodiscard]] inline SIMD_CONSTEXPR bool operator==(const X& number) noexcept
		{
			return this->columns[0] == number;
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		[[nodiscard]] inline SIMD_CONSTEXPR bool operator!=(const X& number) noexcept
		{
			return this->columns[0] != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		SIMD_CONSTEXPR type& operator++() noexcept
		{
			++columns[0];
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

		/*
		SIMD_CONSTEXPR type inverse()
		{
			return type{ *this };
		}

		SIMD_CONSTEXPR type transpose()
		{
			return type{ *this };
		}
		*/
	};

	template<typename T>
	SIMD_CONSTEXPR Matrix<1, 1, T> operator+(const Matrix<1, 1, T>& matrix) noexcept
	{
		return matrix;
	}

	template<typename T>
	SIMD_CONSTEXPR Matrix<1, 1, T> operator-(const Matrix<1, 1, T>& matrix) noexcept
	{
		return Matrix<1, 1, T>(
			-matrix.columns[0]);
	}

	using Matrix1x1 = typename Matrix<1, 1, float>;
}