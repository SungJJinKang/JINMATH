#pragma once
#include "Matrix.h"
namespace Math
{
	template <typename T>
	struct Matrix<2, 2, T>
	{
		static_assert(std::is_arithmetic_v<T>);

		using value_type = typename T;
		using type = typename Matrix<2, 2, T>;
	};

	template <typename T>
	using Matrix2x2 = Matrix<2, 2, T>;
}