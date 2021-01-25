#pragma once
#include "Matrix.h"
namespace Math
{
	template <typename T>
	struct Matrix<2, 2, T>
	{
		static_assert(CHECK_IS_NUMBER(T));

		using value_type = typename T;
		using type = typename Matrix<2, 2, T>;
		using col_type = Vector<2, T>;

		col_type value[2];
	};

	template <typename T>
	using Matrix2x2 = Matrix<2, 2, T>;
}