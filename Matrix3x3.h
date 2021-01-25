#pragma once
#include "Matrix.h"
namespace Math
{
	template <typename T>
	struct Matrix<3, 3, T>
	{
		static_assert(CHECK_IS_NUMBER(T));

		using value_type = typename T;
		using type = typename Matrix<3, 3, T>;
		using col_type = Vector<3, T>;

		col_type value[3];
	};

	template <typename T>
	using Matrix3x3 = Matrix<3, 3, T>;
}