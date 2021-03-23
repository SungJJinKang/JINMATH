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
		
		[[nodiscard]] inline static constexpr size_t columnCount() noexcept { return 1; }
		col_type columns[1]; // don't change to column

		T* data() noexcept
		{
			return columns[0].data();
		}

		const T* data() const noexcept
		{
			return columns[0].data();
		}

		static const type identify;

		constexpr Matrix() noexcept : columns{}
		{

		}

		constexpr explicit Matrix(value_type value) noexcept
			: columns{ col_type(value) }
		{
		}

		constexpr Matrix(col_type column0Value) noexcept
			: columns{ column0Value }
		{
		}

		template <typename X>
		constexpr Matrix(col_type_template<X> column0) noexcept
			: columns{ column0 }
		{
		}

		constexpr explicit Matrix(const type& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		constexpr Matrix(const Matrix<1, 1, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		constexpr Matrix(const Matrix<2, 2, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		constexpr Matrix(const Matrix<3, 3, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		constexpr Matrix(const Matrix<4, 4, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		constexpr type& operator=(value_type value) noexcept
		{
			columns[0] = value;
			return *this;
		}

		constexpr type& operator=(col_type column) noexcept
		{
			columns[0] = column;
			return *this;
		}

		constexpr type& operator=(const type& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<1, 1, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<2, 2, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<3, 3, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		constexpr type& operator=(const Matrix<4, 4, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		// 		Matrix(const type&) = default;
		// 		Matrix(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		std::basic_string<char> toString() const noexcept
		{
			std::stringstream ss;
			ss << columns[0].x << '\n';
			return ss.str();
		}

		[[nodiscard]] constexpr col_type& operator[](size_t i)
		{
			assert(i == 0);
			return columns[i];
		}

		[[nodiscard]] constexpr const col_type& operator[](size_t i) const
		{
			assert(i == 0);
			return columns[i];
		}



		template <typename X>
		constexpr type operator+(const Matrix<1, 1, X>& rhs) noexcept
		{
			return type(columns[0] + rhs.columns[0]);
		}

		template <typename X>
		constexpr type operator-(const Matrix<1, 1, X>& rhs) noexcept
		{
			return type(columns[0] - rhs.columns[0]);
		}

		template <typename X>
		constexpr type operator*(const Matrix<1, 1, X>& rhs) noexcept
		{
			return Matrix<1, 1, T>(columns[0] * rhs.columns[0]);
		}


		constexpr type operator+(T rhs) noexcept
		{
			return type(columns[0] + rhs);
		}

		constexpr type operator-(T rhs) noexcept
		{
			return type(columns[0] - rhs);
		}

		constexpr type operator*(T rhs) noexcept
		{
			return type(columns[0] * rhs);

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
		constexpr type& operator+=(const Matrix<1, 1, X>& rhs) noexcept
		{
			columns[0] += rhs.columns[0];
			return *this;
		}

		template <typename X>
		constexpr type& operator-=(const Matrix<1, 1, X>& rhs) noexcept
		{
			columns[0] -= rhs.columns[0];
			return *this;
		}


		template <typename X>
		constexpr type& operator*=(const Matrix<1, 1, X>& rhs) noexcept
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

		constexpr type& operator+=(T scalar) noexcept
		{
			columns[0] += scalar;
			return *this;
		}

		constexpr type& operator-=(T scalar) noexcept
		{
			columns[0] -= scalar;
			return *this;
		}

		constexpr type& operator*=(T scalar) noexcept
		{
			columns[0] *= scalar;
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
			return this->columns[0] == rhs.columns[0];
		}

		[[nodiscard]] constexpr bool operator!=(const type& rhs) noexcept
		{
			return this->columns[0] != rhs.columns[0];
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		[[nodiscard]] inline constexpr bool operator==(const X& number) noexcept
		{
			return this->columns[0] == number;
		}

		template <typename X, std::enable_if_t<CHECK_IS_NUMBER(X), bool> = true>
		[[nodiscard]] inline constexpr bool operator!=(const X& number) noexcept
		{
			return this->columns[0] != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator++() noexcept
		{
			++columns[0];
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

		operator std::basic_string<char>() noexcept
		{
			return this->toString();
		}

		/*
		constexpr type inverse()
		{
			return type{ *this };
		}

		constexpr type transpose()
		{
			return type{ *this };
		}
		*/
	};

	template<typename T>
	constexpr Matrix<1, 1, T> operator+(const Matrix<1, 1, T>& matrix) noexcept
	{
		return matrix;
	}

	template<typename T>
	constexpr Matrix<1, 1, T> operator-(const Matrix<1, 1, T>& matrix) noexcept
	{
		return Matrix<1, 1, T>(
			-matrix.columns[0]);
	}

	using Matrix1x1 = typename Matrix<1, 1, float>;

	extern template struct math::Matrix<1, 1, float>;
	extern template struct math::Matrix<1, 1, double>;
}