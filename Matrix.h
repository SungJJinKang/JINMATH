#pragma once
#include "LMath_Core.h"

#include "Vector.h"

namespace Math
{
	template <size_t RowComponentCount, size_t RowComponentColl, typename T>
	struct Matrix;

	template <typename T, size_t RowCount, size_t ColCount>
	[[nodiscard]] constexpr Matrix<RowCount, ColCount, T> operator+(const Matrix<RowCount, ColCount, T>& lhs, const Matrix<RowCount, ColCount, T>& rhs) noexcept
	{
		return  Matrix<RowCount, ColCount, T>{lhs.x + rhs.x};
	}

	template <typename T, size_t RowCount, size_t ColCount>
	[[nodiscard]] constexpr Matrix<RowCount, ColCount, T> operator-(const Matrix<RowCount, ColCount, T>& lhs, const Matrix<RowCount, ColCount, T>& rhs) noexcept
	{
		return  Matrix<RowCount, ColCount, T>{lhs.x - rhs.x};
	}


}