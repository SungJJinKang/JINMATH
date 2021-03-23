#pragma once

namespace math
{

	template <typename X>
	constexpr Matrix<4, 4, float>::type Matrix<4, 4, float>::operator*(const Matrix<4, 4, X>& rhs) noexcept
	{
		const col_type SrcA0 = columns[0];
		const col_type SrcA1 = columns[1];
		const col_type SrcA2 = columns[2];
		const col_type SrcA3 = columns[3];

		const col_type SrcB0 = rhs[0];
		const col_type SrcB1 = rhs[1];
		const col_type SrcB2 = rhs[2];
		const col_type SrcB3 = rhs[3];

		Matrix<4, 4, float> Result;
		Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3];
		Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3];
		Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3];
		Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3];
		return Result;
	}


}