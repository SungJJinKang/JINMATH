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
		
		[[nodiscard]] FORCE_INLINE static constexpr SIZE_T columnCount() noexcept { return 1; }
		col_type columns[1]; // don't change to column

		FORCE_INLINE T* data() noexcept
		{
			return columns[0].data();
		}

		const FORCE_INLINE T* data() const noexcept
		{
			return columns[0].data();
		}

		static const type identify;

		FORCE_INLINE constexpr Matrix() noexcept : columns{}
		{

		}

		FORCE_INLINE constexpr explicit Matrix(value_type value) noexcept
			: columns{ col_type(value) }
		{
		}

		FORCE_INLINE constexpr Matrix(const col_type& column0Value) noexcept
			: columns{ column0Value }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Matrix(const col_type_template<X>& column0) noexcept
			: columns{ column0 }
		{
		}

		FORCE_INLINE constexpr explicit Matrix(const type& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Matrix(const Matrix<1, 1, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Matrix(const Matrix<2, 2, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Matrix(const Matrix<3, 3, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Matrix(const Matrix<4, 4, X>& matrix) noexcept
			: columns{ matrix.columns[0] }
		{
		}

		FORCE_INLINE constexpr type& operator=(value_type value) noexcept
		{
			columns[0] = value;
			return *this;
		}

		FORCE_INLINE constexpr type& operator=(const col_type& column) noexcept
		{
			columns[0] = column;
			return *this;
		}

		FORCE_INLINE constexpr type& operator=(const type& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Matrix<1, 1, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Matrix<2, 2, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Matrix<3, 3, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Matrix<4, 4, X>& matrix) noexcept
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

		[[nodiscard]] FORCE_INLINE constexpr col_type& operator[](SIZE_T i)
		{
			assert(i == 0);
			return columns[i];
		}

		[[nodiscard]] FORCE_INLINE constexpr const col_type& operator[](SIZE_T i) const
		{
			assert(i == 0);
			return columns[i];
		}



		template <typename X>
		FORCE_INLINE constexpr type operator+(const Matrix<1, 1, X>& rhs) const noexcept
		{
			return type(columns[0] + rhs.columns[0]);
		}

		template <typename X>
		FORCE_INLINE constexpr type operator-(const Matrix<1, 1, X>& rhs) const noexcept
		{
			return type(columns[0] - rhs.columns[0]);
		}

		template <typename X>
		FORCE_INLINE constexpr type operator*(const Matrix<1, 1, X>& rhs) const noexcept
		{
			return Matrix<1, 1, T>(columns[0] * rhs.columns[0]);
		}


		FORCE_INLINE constexpr type operator+(T rhs) const noexcept
		{
			return type(columns[0] + rhs);
		}

		FORCE_INLINE constexpr type operator-(T rhs) const noexcept
		{
			return type(columns[0] - rhs);
		}

		FORCE_INLINE constexpr type operator*(T rhs) const noexcept
		{
			return type(columns[0] * rhs);

		}
		/*
		template <typename X>
		FORCE_INLINE constexpr type operator/(const Matrix<4, X>& rhs)
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		template <typename X>
		FORCE_INLINE constexpr type operator%(const Matrix<4, X>& rhs)
		{
			return type(x % rhs.x, y % rhs.y, z % rhs.z, w % rhs.w);
		}
		*/

		template <typename X>
		FORCE_INLINE constexpr type& operator+=(const Matrix<1, 1, X>& rhs) noexcept
		{
			columns[0] += rhs.columns[0];
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator-=(const Matrix<1, 1, X>& rhs) noexcept
		{
			columns[0] -= rhs.columns[0];
			return *this;
		}


		template <typename X>
		FORCE_INLINE constexpr type& operator*=(const Matrix<1, 1, X>& rhs) noexcept
		{
			return (*this = *this * rhs);
		}



		/*
		template <typename X>
		FORCE_INLINE constexpr type& operator/=(const Matrix<4, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator%=(const Matrix<4, X>& rhs)
		{
			x %= rhs.x;
			y %= rhs.y;
			z %= rhs.z;
			w %= rhs.w;
			return *this;
		}
		*/
		//

		FORCE_INLINE constexpr type& operator+=(T scalar) noexcept
		{
			columns[0] += scalar;
			return *this;
		}

		FORCE_INLINE constexpr type& operator-=(T scalar) noexcept
		{
			columns[0] -= scalar;
			return *this;
		}

		FORCE_INLINE constexpr type& operator*=(T scalar) noexcept
		{
			columns[0] *= scalar;
			return *this;
		}

		/*
		template <typename X>
		FORCE_INLINE constexpr type& operator/=(const X& scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}


		template <typename X, std::enable_if_t<std::is_integral_v<X>, bool> = true>
		FORCE_INLINE type& operator%=(const X& scalar)
		{
			x %= scalar;
			y %= scalar;
			z %= scalar;
			w %= scalar;
			return *this;
		}

		template <typename X, std::enable_if_t<std::is_floating_point_v<X>, bool> = true>
		FORCE_INLINE type& operator%=(const X& scalar)
		{

			x %= std::fmod(x, scalar);
			y %= std::fmod(y, scalar);
			z %= std::fmod(z, scalar);
			w %= std::fmod(w, scalar);
			return *this;
		}
		*/

		//

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(const type& rhs) const noexcept
		{
			return this->columns[0] == rhs.columns[0];
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(const type& rhs) const noexcept
		{
			return this->columns[0] != rhs.columns[0];
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(T number) const noexcept
		{
			return this->columns[0] == number;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(T number) const noexcept
		{
			return this->columns[0] != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator++() noexcept
		{
			++columns[0];
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE constexpr type operator++(INT32) noexcept
		{
			type Matrix{ *this };
			++* this;
			return Matrix;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator--() noexcept
		{
			--columns[0];
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE constexpr type operator--(INT32) noexcept
		{
			type Matrix{ *this };
			--* this;
			return Matrix;
		}

		operator std::basic_string<char>() const noexcept
		{
			return this->toString();
		}

		/*
		inline constexpr type inverse()
		{
			return type{ *this };
		}

		inline constexpr type transpose()
		{
			return type{ *this };
		}
		*/
	};

	template<typename T>
	FORCE_INLINE constexpr Matrix<1, 1, T> operator+(const Matrix<1, 1, T>& matrix) noexcept
	{
		return matrix;
	}

	template<typename T>
	FORCE_INLINE constexpr Matrix<1, 1, T> operator-(const Matrix<1, 1, T>& matrix) noexcept
	{
		return Matrix<1, 1, T>(
			-matrix.columns[0]);
	}

	using Matrix1x1 = typename Matrix<1, 1, FLOAT32>;

	extern template struct math::Matrix<1, 1, FLOAT32>;
	extern template struct math::Matrix<1, 1, FLOAT64>;
}