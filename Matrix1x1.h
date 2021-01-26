#pragma once
#include "Matrix.h"

#include "Vector1.h"
namespace Math
{
	template <typename T>
	struct Matrix<1, 1, T>
	{
		static_assert(CHECK_IS_NUMBER(T));

		using value_type = typename T;
		using type = typename Matrix<1, 1, T>;
		using col_type = Vector<1, T>;
		
		col_type value[1];
	
		constexpr Matrix()  noexcept
		{
			//value[0]
		}

		constexpr Matrix(value_type x)  noexcept
		{
			value[0] = x;
		}

		template <size_t ComponentCount, typename T, std::enable_if_t<(ComponentCount > 1), bool> = true>
		constexpr explicit Matrix(const Matrix<ComponentCount, ComponentCount, T>& matrix) noexcept
		{
			value[0] = matrix.value[0];
		}

		constexpr explicit Matrix(const col_type& col1) noexcept
		{
			value[0] = col1;
		}

		constexpr type& operator=(value_type x)  noexcept
		{
			value[0] = x;
			return *this;
		}

	
		template <size_t ComponentCount, typename T, std::enable_if_t<(ComponentCount > 1), bool> = true>
		constexpr type& operator=(const Matrix<ComponentCount, ComponentCount, T>& matrix) noexcept
		{
			value[0] = matrix.value[0];
			return *this;
		}

		constexpr type& operator=(const col_type& col1) noexcept
		{
			value[0] = col1;
			return *this;
		}

		template <size_t ComponentCount>
		constexpr type operator+(const Matrix<1, 1, T>& matrix) noexcept
		{
			return type(value[0] + matrix.value[0]);
		}
		
		template <typename T>
		constexpr type operator-(const Matrix<1, 1, T>& matrix) noexcept
		{
			return type(value[0] - matrix.value[0]);
		}

		//

		template <typename T>
		constexpr type operator*(const Matrix<1, 1, T>& matrix) noexcept
		{
			return type(value[0] * matrix.value[0]);
		}
	};

	using Matrix1x1 = typename Matrix<1, 1, float>;
}