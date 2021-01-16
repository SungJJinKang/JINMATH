#pragma once
#include "Matrix.h"
namespace Math
{
	template <typename T>
	struct Matrix<3, 3, T>
	{
		static_assert(std::is_arithmetic_v<T>);

		using value_type = typename T;
		using type = typename Matrix<3, 3, T>;
	};

	template <typename T>
	using Matrix3x3 = Matrix<3, 3, T>;
}