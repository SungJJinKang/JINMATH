#pragma once
#include "Matrix.h"
namespace Math
{
	template <typename T>
	struct Matrix<4, 4, T>
	{
		static_assert(std::is_arithmetic_v<T>);

		using value_type = typename T;
		using type = typename Matrix<4, 4, T>;
	};

	template <typename T>
	using Matrix4x4 = Matrix<4, 4, T>;
}