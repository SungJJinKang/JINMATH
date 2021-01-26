#pragma once
#include "Matrix.h"

#include "Vector4.h"
namespace Math
{
	template <typename T>
	struct Matrix<4, 4, T>
	{
		static_assert(CHECK_IS_NUMBER(T));

		using value_type = typename T;
		using type = typename Matrix<4, 4, T>;
		using col_type = Vector<4, T>;

		col_type value[4];
	};

	template <typename T>
	using Matrix4x4 = Matrix<4, 4, T>;
}