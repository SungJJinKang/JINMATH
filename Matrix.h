#pragma once
#include "LMath_Core.h"

#include "Vector.h"

namespace Math
{
	template <size_t ComponentCount1, size_t ComponentCount2, typename T>
	struct Matrix;

	template <typename T>
	[[nodiscard]] constexpr Matrix<1, 1, T> operator+(const Matrix<1, 1, T>& lhs, const Matrix<1, 1, T>& rhs) noexcept
	{
		return Matrix<1, 1, T>{lhs.columns[0] + rhs.columns[0]};
	}

	template <typename T>
	[[nodiscard]] constexpr Matrix<1, 1, T> operator-(const Matrix<1, 1, T>& lhs, const Matrix<1, 1, T>& rhs) noexcept
	{
		return Matrix<1, 1, T>{lhs.columns[0] - rhs.columns[0]};
	}

	template <typename T>
	[[nodiscard]] constexpr Matrix<1, 1, T> operator*(const Matrix<1, 1, T>& lhs, const Matrix<1, 1, T>& rhs) noexcept
	{
		return Matrix<1, 1, T>{lhs.columns[0] * rhs.columns[0]};
	}

	/*
	template <typename T>
	[[nodiscard]] constexpr Matrix<1, 1, T> operator/(const Matrix<1, 1, T>& lhs, const Matrix<1, 1, T>& rhs)
	{
		return Matrix<1, 1, T>{lhs.columns[0] / rhs.columns[0]};
	}

	template <typename T>
	[[nodiscard]] constexpr Matrix<1, 1, T> operator%(const Matrix<1, 1, T>& lhs, const Matrix<1, 1, T>& rhs)
	{
		return Matrix<1, 1, T>{lhs.columns[0] % rhs.columns[0]};
	}
	*/
	///////////////////////////////


	template <typename T>
	[[nodiscard]] constexpr Matrix<2, 2, T> operator+(const Matrix<2, 2, T>& lhs, const Matrix<2, 2, T>& rhs) noexcept
	{
		return Matrix<2, 2, T>{lhs.columns[0] + rhs.columns[0], lhs.columns[1] + rhs.columns[1]};
	}

	template <typename T>
	[[nodiscard]] constexpr Matrix<2, 2, T> operator-(const Matrix<2, 2, T>& lhs, const Matrix<2, 2, T>& rhs) noexcept
	{
		return Matrix<2, 2, T>{lhs.columns[0] - rhs.columns[0], lhs.columns[1] - rhs.columns[1]};

	}
	template <typename T>
	[[nodiscard]] constexpr Matrix<2, 2, T> operator*(const Matrix<2, 2, T>& lhs, const Matrix<2, 2, T>& rhs) noexcept
	{
		const Vector<2, T> SrcA0 = lhs.columns[0];
		const Vector<2, T> SrcA1 = lhs.columns[1];

		const Vector<2, T> SrcB0 = rhs.columns[0];
		const Vector<2, T> SrcB1 = rhs.columns[1];

		Matrix<2, 2, T> Result;
		Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1];
		Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1];
		return Result;
	}

	/*
	template <typename T>
	[[nodiscard]] constexpr Matrix<2, 2, T> operator/(const Matrix<2, 2, T>& lhs, const Matrix<2, 2, T>& rhs)
	{
		return Matrix<2, 2, T>{lhs.columns[0] / rhs.columns[0], lhs.columns[1] / rhs.columns[1]};
	}

	template <typename T>
	[[nodiscard]] constexpr Matrix<2, 2, T> operator%(const Matrix<2, 2, T>& lhs, const Matrix<2, 2, T>& rhs)
	{
		return Matrix<2, 2, T>{lhs.columns[0] % rhs.columns[0], lhs.columns[1] % rhs.columns[1]};
	}
	*/
	////////////////

	template <typename T>
	[[nodiscard]] constexpr Matrix<3, 3, T> operator+(const Matrix<3, 3, T>& lhs, const Matrix<3, 3, T>& rhs) noexcept
	{
		return Matrix<3, 3, T>{lhs.columns[0] + rhs.columns[0], lhs.columns[1] + rhs.columns[1], lhs.columns[2] + rhs.columns[2]};
	}

	template <typename T>
	[[nodiscard]] constexpr Matrix<3, 3, T> operator-(const Matrix<3, 3, T>& lhs, const Matrix<3, 3, T>& rhs) noexcept
	{
		return Matrix<3, 3, T>{lhs.columns[0] - rhs.columns[0], lhs.columns[1] - rhs.columns[1], lhs.columns[2] - rhs.columns[2]};

	}
	template <typename T>
	[[nodiscard]] constexpr Matrix<3, 3, T> operator*(const Matrix<3, 3, T>& lhs, const Matrix<3, 3, T>& rhs) noexcept
	{
		const Vector<3, T> SrcA0 = lhs.columns[0];
		const Vector<3, T> SrcA1 = lhs.columns[1];
		const Vector<3, T> SrcA2 = lhs.columns[2];

		const Vector<3, T> SrcB0 = rhs.columns[0];
		const Vector<3, T> SrcB1 = rhs.columns[1];
		const Vector<3, T> SrcB2 = rhs.columns[2];

		Matrix<3, 3, T> Result;
		Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2];
		Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2];
		Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2];
		return Result;
	}

	/*
	template <typename T>
	[[nodiscard]] constexpr Matrix<3, 3, T> operator/(const Matrix<3, 3, T>& lhs, const Matrix<3, 3, T>& rhs)
	{
		return Matrix<3, 3, T>{lhs.columns[0] / rhs.columns[0], lhs.columns[1] / rhs.columns[1], lhs.columns[2] / rhs.columns[2]};
	}

	template <typename T>
	[[nodiscard]] constexpr Matrix<3, 3, T> operator%(const Matrix<3, 3, T>& lhs, const Matrix<3, 3, T>& rhs)
	{
		return Matrix<3, 3, T>{lhs.columns[0] % rhs.columns[0], lhs.columns[1] % rhs.columns[1], lhs.columns[2] % rhs.columns[2]};
	}
	*/
	////////////

	template <typename T>
	[[nodiscard]] constexpr Matrix<4, 4, T> operator+(const Matrix<4, 4, T>& lhs, const Matrix<4, 4, T>& rhs) noexcept
	{
		return Matrix<4, 4, T>{lhs.columns[0] + rhs.columns[0], lhs.columns[1] + rhs.columns[1], lhs.columns[2] + rhs.columns[2], lhs.columns[3] + rhs.columns[3]};
	}

	template <typename T>
	[[nodiscard]] constexpr Matrix<4, 4, T> operator-(const Matrix<4, 4, T>& lhs, const Matrix<4, 4, T>& rhs) noexcept
	{
		return Matrix<4, 4, T>{lhs.columns[0] - rhs.columns[0], lhs.columns[1] - rhs.columns[1], lhs.columns[2] - rhs.columns[2], lhs.columns[3] - rhs.columns[3]};
	}
	template <typename T>
	[[nodiscard]] constexpr Matrix<4, 4, T> operator*(const Matrix<4, 4, T>& lhs, const Matrix<4, 4, T>& rhs) noexcept
	{
		const Vector<4, T> SrcA0 = lhs.columns[0];
		const Vector<4, T> SrcA1 = lhs.columns[1];
		const Vector<4, T> SrcA2 = lhs.columns[2];
		const Vector<4, T> SrcA3 = lhs.columns[3];

		const Vector<4, T> SrcB0 = rhs.columns[0];
		const Vector<4, T> SrcB1 = rhs.columns[1];
		const Vector<4, T> SrcB2 = rhs.columns[2];
		const Vector<4, T> SrcB3 = rhs.columns[3];

		Matrix<4, 4, T> Result;
		Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3];
		Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3];
		Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3];
		Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3];
		return Result;
	}

	/*
	template <typename T>
	[[nodiscard]] constexpr Matrix<4, 4, T> operator/(const Matrix<4, 4, T>& lhs, const Matrix<4, 4, T>& rhs)
	{
		return Matrix<4, 4, T>{lhs.columns[0] / rhs.columns[0], lhs.columns[1] / rhs.columns[1], lhs.columns[2] / rhs.columns[2], lhs.columns[3] / rhs.columns[3]};
	}

	template <typename T>
	[[nodiscard]] constexpr Matrix<4, 4, T> operator%(const Matrix<4, 4, T>& lhs, const Matrix<4, 4, T>& rhs)
	{
		return Matrix<4, 4, T>{lhs.columns[0] % rhs.columns[0], lhs.columns[1] % rhs.columns[1], lhs.columns[2] % rhs.columns[2], lhs.columns[3] % rhs.columns[3]};
	}
	*/


	///////////////////


	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<1, 1, X> operator+(const Matrix<1, 1, X>& lhs, Y scalar) noexcept
	{
		return Matrix<1, 1, X>{lhs.columns[0] + scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<1, 1, X> operator-(const Matrix<1, 1, X>& lhs, Y scalar) noexcept
	{
		return Matrix<1, 1, X>{lhs.columns[0] - scalar};
	}
	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<1, 1, X> operator*(const Matrix<1, 1, X>& lhs, Y scalar) noexcept
	{
		return Matrix<1, 1, X>{lhs.columns[0] * scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<1, 1, X> operator/(const Matrix<1, 1, X>& lhs, Y scalar)
	{
		return Matrix<1, 1, X>{lhs.columns[0] / scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<1, 1, X> operator%(const Matrix<1, 1, X>& lhs, Y scalar)
	{
		return Matrix<1, 1, X>{lhs.columns[0] % scalar};
	}

	///////////////////////////////


	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<2, 2, X> operator+(const Matrix<2, 2, X>& lhs, Y scalar) noexcept
	{
		return Matrix<2, 2, X>{lhs.columns[0] + scalar, lhs.columns[1] + scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<2, 2, X> operator-(const Matrix<2, 2, X>& lhs, Y scalar) noexcept
	{
		return Matrix<2, 2, X>{lhs.columns[0] - scalar, lhs.columns[1] - scalar};

	}
	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<2, 2, X> operator*(const Matrix<2, 2, X>& lhs, Y scalar) noexcept
	{
		return Matrix<2, 2, X>{lhs.columns[0] * scalar, lhs.columns[1] * scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<2, 2, X> operator/(const Matrix<2, 2, X>& lhs, Y scalar)
	{
		return Matrix<2, 2, X>{lhs.columns[0] / scalar, lhs.columns[1] / scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<2, 2, X> operator%(const Matrix<2, 2, X>& lhs, Y scalar)
	{
		return Matrix<2, 2, X>{lhs.columns[0] % scalar, lhs.columns[1] % scalar};
	}

	////////////////

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<3, 3, X> operator+(const Matrix<3, 3, X>& lhs, Y scalar) noexcept
	{
		return Matrix<3, 3, X>{lhs.columns[0] + scalar, lhs.columns[1] + scalar, lhs.columns[2] + scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<3, 3, X> operator-(const Matrix<3, 3, X>& lhs, Y scalar) noexcept
	{
		return Matrix<3, 3, X>{lhs.columns[0] - scalar, lhs.columns[1] - scalar, lhs.columns[2] - scalar};

	}
	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<3, 3, X> operator*(const Matrix<3, 3, X>& lhs, Y scalar) noexcept
	{
		return Matrix<3, 3, X>{lhs.columns[0] * scalar, lhs.columns[1] * scalar, lhs.columns[2] * scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<3, 3, X> operator/(const Matrix<3, 3, X>& lhs, Y scalar)
	{
		return Matrix<3, 3, X>{lhs.columns[0] / scalar, lhs.columns[1] / scalar, lhs.columns[2] / scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<3, 3, X> operator%(const Matrix<3, 3, X>& lhs, Y scalar)
	{
		return Matrix<3, 3, X>{lhs.columns[0] % scalar, lhs.columns[1] % scalar, lhs.columns[2] % scalar};
	}

	////////////

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<4, 4, X> operator+(const Matrix<4, 4, X>& lhs, Y scalar) noexcept
	{
		return Matrix<4, 4, X>{lhs.columns[0] + scalar, lhs.columns[1] + scalar, lhs.columns[2] + scalar, lhs.columns[3] + scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<4, 4, X> operator-(const Matrix<4, 4, X>& lhs, Y scalar) noexcept
	{
		return Matrix<4, 4, X>{lhs.columns[0] - scalar, lhs.columns[1] - scalar, lhs.columns[2] - scalar, lhs.columns[3] - scalar};
	}
	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<4, 4, X> operator*(const Matrix<4, 4, X>& lhs, Y scalar) noexcept
	{
		return Matrix<4, 4, X>{lhs.columns[0] * scalar, lhs.columns[1] * scalar, lhs.columns[2] * scalar, lhs.columns[3] * scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<4, 4, X> operator/(const Matrix<4, 4, X>& lhs, Y scalar)
	{
		return Matrix<4, 4, X>{lhs.columns[0] / scalar, lhs.columns[1] / scalar, lhs.columns[2] / scalar, lhs.columns[3] / scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<4, 4, X> operator%(const Matrix<4, 4, X>& lhs, Y scalar)
	{
		return Matrix<4, 4, X>{lhs.columns[0] % scalar, lhs.columns[1] % scalar, lhs.columns[2] % scalar, lhs.columns[3] % scalar};
	}

	////////////////////////////////

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<1, 1, Y> operator+(X scalar, const Matrix<1, 1, Y>& rhs) noexcept
	{
		return Matrix<1, 1, Y>{scalar + rhs.columns[0]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<1, 1, Y> operator-(X scalar, const Matrix<1, 1, Y>& rhs) noexcept
	{
		return Matrix<1, 1, Y>{scalar - rhs.columns[0]};
	}
	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<1, 1, Y> operator*(X scalar, const Matrix<1, 1, Y>& rhs) noexcept
	{
		return Matrix<1, 1, Y>{scalar * rhs.columns[0]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<1, 1, Y> operator/(X scalar, const Matrix<1, 1, Y>& rhs)
	{
		return Matrix<1, 1, Y>{scalar / rhs.columns[0]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<1, 1, Y> operator%(X scalar, const Matrix<1, 1, Y>& rhs)
	{
		return Matrix<1, 1, Y>{scalar % rhs.columns[0]};
	}

	///////////////////////////////


	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<2, 2, Y> operator+(X scalar, const Matrix<2, 2, Y>& rhs) noexcept
	{
		return Matrix<2, 2, Y>{scalar + rhs.columns[0], scalar + rhs.columns[1]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<2, 2, Y> operator-(X scalar, const Matrix<2, 2, Y>& rhs) noexcept
	{
		return Matrix<2, 2, Y>{scalar - rhs.columns[0], scalar - rhs.columns[1]};

	}
	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<2, 2, Y> operator*(X scalar, const Matrix<2, 2, Y>& rhs) noexcept
	{
		return Matrix<2, 2, Y>{scalar * rhs.columns[0], scalar * rhs.columns[1]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<2, 2, Y> operator/(X scalar, const Matrix<2, 2, Y>& rhs)
	{
		return Matrix<2, 2, Y>{scalar / rhs.columns[0], scalar / rhs.columns[1]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<2, 2, Y> operator%(X scalar, const Matrix<2, 2, Y>& rhs)
	{
		return Matrix<2, 2, Y>{scalar % rhs.columns[0], scalar % rhs.columns[1]};
	}

	////////////////

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<3, 3, Y> operator+(X scalar, const Matrix<3, 3, Y>& rhs) noexcept
	{
		return Matrix<3, 3, Y>{scalar + rhs.columns[0], scalar + rhs.columns[1], scalar + rhs.columns[2]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<3, 3, Y> operator-(X scalar, const Matrix<3, 3, Y>& rhs) noexcept
	{
		return Matrix<3, 3, Y>{scalar - rhs.columns[0], scalar - rhs.columns[1], scalar - rhs.columns[2]};

	}
	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<3, 3, Y> operator*(X scalar, const Matrix<3, 3, Y>& rhs) noexcept
	{
		return Matrix<3, 3, Y>{scalar * rhs.columns[0], scalar * rhs.columns[1], scalar * rhs.columns[2]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<3, 3, Y> operator/(X scalar, const Matrix<3, 3, Y>& rhs)
	{
		return Matrix<3, 3, Y>{scalar / rhs.columns[0], scalar / rhs.columns[1], scalar / rhs.columns[2]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<3, 3, Y> operator%(X scalar, const Matrix<3, 3, Y>& rhs)
	{
		return Matrix<3, 3, Y>{scalar % rhs.columns[0], scalar % rhs.columns[1], scalar % rhs.columns[2]};
	}

	////////////

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<4, 4, Y> operator+(X scalar, const Matrix<4, 4, Y>& rhs) noexcept
	{
		return Matrix<4, 4, Y>{scalar + rhs.columns[0], scalar + rhs.columns[1], scalar + rhs.columns[2], scalar + rhs.columns[3]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<4, 4, Y> operator-(X scalar, const Matrix<4, 4, Y>& rhs) noexcept
	{
		return Matrix<4, 4, Y>{scalar - rhs.columns[0], scalar - rhs.columns[1], scalar - rhs.columns[2], scalar - rhs.columns[3]};
	}
	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<4, 4, Y> operator*(X scalar, const Matrix<4, 4, Y>& rhs) noexcept
	{
		return Matrix<4, 4, Y>{scalar * rhs.columns[0], scalar * rhs.columns[1], scalar * rhs.columns[2], rhs.columns[3] * scalar};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<4, 4, Y> operator/(X scalar, const Matrix<4, 4, Y>& rhs)
	{
		return Matrix<4, 4, Y>{scalar / rhs.columns[0], scalar / rhs.columns[1], scalar / rhs.columns[2], scalar / rhs.columns[3]};
	}

	template <typename X, typename Y>
	[[nodiscard]] constexpr Matrix<4, 4, Y> operator%(X scalar, const Matrix<4, 4, Y>& rhs)
	{
		return Matrix<4, 4, Y>{scalar % rhs.columns[0], scalar % rhs.columns[1], scalar % rhs.columns[2], scalar % rhs.columns[3]};
	}



}