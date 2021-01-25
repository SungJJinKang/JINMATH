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

		template <size_t ComponentCount, typename T, std::enable_if_t<ComponentCount >= 1, bool> = true>
		constexpr explicit Matrix(const Matrix<ComponentCount, ComponentCount, T>& matrix) noexcept
		{
			value[0].x = matrix.value[0].x;
		}

		constexpr operator=(value_type x)  noexcept
		{
			value[0] = x;
		}

		template <size_t ComponentCount, typename T, std::enable_if_t<ComponentCount >= 1, bool> = true>
		constexpr operator=(const Matrix<ComponentCount, ComponentCount, T>& matrix) noexcept
		{
			value[0].x = matrix.value[0].x;
		}

		

	};

	using Matrix1x1 = typename Matrix<1, 1, float>;
}