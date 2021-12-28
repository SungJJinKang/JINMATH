#include "Matrix4x4.h"

#include "Matrix2x2.h"
#include "Matrix3x3.h"

math::Matrix4x4::Matrix4x4(const Matrix2x2& matrix) noexcept
	:
	columns
	{
		col_type{ matrix.columns[0]},
		col_type{matrix.columns[1]},
		math::Vector4{0, 0, 1, 0},
		math::Vector4{0, 0, 0, 1}
	}
{
}

math::Matrix4x4::Matrix4x4(const Matrix3x3& matrix) noexcept
	:
	columns
	{
		col_type{matrix.columns[0], 0.0f},
		col_type{matrix.columns[1], 0.0f},
		col_type{matrix.columns[2], 0.0f},
		math::Vector4{0, 0, 0, 1}
	}
{
}

math::Matrix4x4& math::Matrix4x4::operator=(const Matrix2x2& matrix) noexcept
{
	columns[0] = matrix.columns[0];
	columns[1] = matrix.columns[1];
	columns[2] = 0;
	columns[3] = { 0,0,0,1 };
	return *this;
}

math::Matrix4x4& math::Matrix4x4::operator=(const Matrix3x3& matrix) noexcept
{
	columns[0] = matrix.columns[0];
	columns[1] = matrix.columns[1];
	columns[2] = matrix.columns[2];
	columns[3] = { 0,0,0,1 };
	return *this;
}

