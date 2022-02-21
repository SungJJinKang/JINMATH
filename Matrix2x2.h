#pragma once
#include "JINMATHCore.h"

#include "Vector2.h"

#include "Matrix2x2.reflection.h"
namespace math
{

	struct Matrix2x2;
	struct Matrix3x3;
	struct Matrix4x4;

	struct Vector2;
	struct Vector3;
	struct Vector4;
	
	struct D_STRUCT Matrix2x2
	{
		GENERATE_BODY()

		using value_type = float;
		using type = typename Matrix2x2;
		using col_type = Vector2;

		NO_DISCARD FORCE_INLINE static size_t columnCount() noexcept { return 2; }

		D_PROPERTY()
		col_type columns[2];

		FORCE_INLINE float* data() noexcept
		{
			return columns[0].data();
		}

		const FORCE_INLINE float* data() const noexcept
		{
			return columns[0].data();
		}

		static const Matrix2x2 identify;

		FORCE_INLINE Matrix2x2() = delete;

		FORCE_INLINE Matrix2x2(INT32*) noexcept : columns{ nullptr, nullptr }
		{

		}

		/// <summary>
		/// diagonal matrix
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		FORCE_INLINE explicit Matrix2x2(value_type value) noexcept
			: columns{
			col_type(value, 0),
			col_type(0, value) }
		{
		}

		FORCE_INLINE Matrix2x2
		(
			value_type x0, value_type y0,
			value_type x1, value_type y1
		) noexcept : columns{
			col_type(x0, x1),
			col_type(y0, y1)}
		{
		}

		
		FORCE_INLINE Matrix2x2(const col_type& column0, const col_type& column1) noexcept
			: columns{ col_type{column0}, col_type{column1} }
		{
		}
		
		FORCE_INLINE Matrix2x2(const Matrix2x2& matrix) noexcept
			: columns{ col_type{matrix.columns[0]}, col_type{matrix.columns[1]} }
		{
		}

		
		FORCE_INLINE explicit Matrix2x2(const Matrix3x3& matrix) noexcept;


		FORCE_INLINE explicit Matrix2x2(const Matrix4x4& matrix) noexcept;

		FORCE_INLINE Matrix2x2& operator=(value_type value) noexcept
		{
			columns[0] = value;
			columns[1] = value;
			return *this;
		}

		FORCE_INLINE Matrix2x2& operator=(const col_type& column) noexcept
		{
			columns[0] = column;
			columns[1] = column;
			return *this;
		}
		
		FORCE_INLINE Matrix2x2& operator=(const Matrix2x2& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			return *this;
		}

		
		FORCE_INLINE Matrix2x2& operator=(const Matrix3x3& matrix) noexcept;
		
		FORCE_INLINE Matrix2x2& operator=(const Matrix4x4& matrix) noexcept;

		NO_DISCARD FORCE_INLINE col_type& operator[](size_t i)
		{
			assert(i >= 0 || i < columnCount());
			return columns[i];
		}

		NO_DISCARD FORCE_INLINE const col_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < columnCount());
			return columns[i];
		}



		
		FORCE_INLINE Matrix2x2 operator+(const Matrix2x2& rhs) const noexcept
		{
			return Matrix2x2(columns[0] + rhs.columns[0], columns[1] + rhs.columns[1]);
		}

		
		FORCE_INLINE Matrix2x2 operator-(const Matrix2x2& rhs) const noexcept
		{
			return Matrix2x2(columns[0] - rhs.columns[0], columns[1] - rhs.columns[1]);
		}

		
		NO_DISCARD FORCE_INLINE Matrix2x2 operator*(const Matrix2x2& rhs) const noexcept;


		NO_DISCARD FORCE_INLINE Vector2 operator*(const Vector2& vector) const noexcept
		{
			return Vector2
			{
				this->columns[0][0] * vector[0] + this->columns[1][0] * vector[1],
					this->columns[0][1] * vector[0] + this->columns[1][1] * vector[1],
			};
		}

		FORCE_INLINE Matrix2x2 operator+(float rhs) const noexcept
		{
			return Matrix2x2(columns[0] + rhs, columns[1] + rhs);
		}

		FORCE_INLINE Matrix2x2 operator-(float rhs) const noexcept
		{
			return Matrix2x2(columns[0] - rhs, columns[1] - rhs);
		}

		FORCE_INLINE Matrix2x2 operator*(float rhs) const noexcept
		{
			return Matrix2x2(columns[0] * rhs, columns[1] * rhs);
		}

		/*
		
		FORCE_INLINE Matrix2x2 operator/(const Matrix<4, X>& rhs)
		{
			return Matrix2x2(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		
		FORCE_INLINE Matrix2x2 operator%(const Matrix<4, X>& rhs)
		{
			return Matrix2x2(x % rhs.x, y % rhs.y, z % rhs.z, w % rhs.w);
		}
		*/

		
		FORCE_INLINE Matrix2x2& operator+=(const Matrix2x2& rhs) noexcept
		{
			columns[0] += rhs.columns[0];
			columns[1] += rhs.columns[1];
			return *this;
		}

		
		FORCE_INLINE Matrix2x2& operator-=(const Matrix2x2& rhs) noexcept
		{
			columns[0] -= rhs.columns[0];
			columns[1] -= rhs.columns[1];
			return *this;
		}


		
		FORCE_INLINE Matrix2x2& operator*=(const Matrix2x2& rhs) noexcept
		{
			return (*this = *this * rhs);
		}



		/*
		
		FORCE_INLINE Matrix2x2& operator/=(const Matrix<4, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		
		FORCE_INLINE Matrix2x2& operator%=(const Matrix<4, X>& rhs)
		{
			x %= rhs.x;
			y %= rhs.y;
			z %= rhs.z;
			w %= rhs.w;
			return *this;
		}
		*/
		//

		FORCE_INLINE Matrix2x2& operator+=(float scalar) noexcept
		{
			columns[0] += scalar;
			columns[1] += scalar;
			return *this;
		}

		FORCE_INLINE Matrix2x2& operator-=(float scalar) noexcept
		{
			columns[0] -= scalar;
			columns[1] -= scalar;
			return *this;
		}

		FORCE_INLINE Matrix2x2& operator*=(float scalar) noexcept
		{
			columns[0] *= scalar;
			columns[1] *= scalar;
			return *this;
		}

		/*
		
		FORCE_INLINE Matrix2x2& operator/=(const X& scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}


		template <typename X, std::enable_if_t<std::is_integral_v<X>, bool> = true>
		FORCE_INLINE Matrix2x2& operator%=(const X& scalar)
		{
			x %= scalar;
			y %= scalar;
			z %= scalar;
			w %= scalar;
			return *this;
		}

		template <typename X, std::enable_if_t<std::is_floating_point_v<X>, bool> = true>
		FORCE_INLINE Matrix2x2& operator%=(const X& scalar)
		{

			x %= std::fmod(x, scalar);
			y %= std::fmod(y, scalar);
			z %= std::fmod(z, scalar);
			w %= std::fmod(w, scalar);
			return *this;
		}
		*/

		//

		NO_DISCARD FORCE_INLINE bool operator==(const Matrix2x2& rhs) const noexcept
		{
			return this->columns[0] == rhs.columns[0] && this->columns[1] == rhs.columns[1];
		}

		NO_DISCARD FORCE_INLINE bool operator!=(const Matrix2x2& rhs) const noexcept
		{
			return this->columns[0] != rhs.columns[0] || this->columns[1] != rhs.columns[1];
		}

		NO_DISCARD FORCE_INLINE bool operator==(float number) const noexcept
		{
			return this->columns[0] == number && this->columns[1] == number;
		}

		NO_DISCARD FORCE_INLINE bool operator!=(float number) const noexcept
		{
			return this->columns[0] != number || this->columns[1] != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE Matrix2x2& operator++() noexcept
		{
			++columns[0];
			++columns[1];
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE Matrix2x2 operator++(INT32) noexcept
		{
			Matrix2x2 Matrix{ *this };
			++* this;
			return Matrix2x2{ Matrix };
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE Matrix2x2& operator--() noexcept
		{
			--columns[0];
			--columns[1];
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE Matrix2x2 operator--(INT32) noexcept
		{
			Matrix2x2 Matrix{ *this };
			--* this;
			return Matrix2x2{ Matrix };
		}
		
		template <typename U = float, std::enable_if_t<std::is_signed_v<U>, bool> = true>
		inline Matrix2x2 inverse() const noexcept
		{
			value_type OneOverDetercolumnsinant = static_cast<value_type>(1) / (
				+columns[0][0] * columns[1][1]
				- columns[1][0] * columns[0][1]);

			Matrix2x2 Inverse(
				+columns[1][1] * OneOverDetercolumnsinant,
				-columns[0][1] * OneOverDetercolumnsinant,
				-columns[1][0] * OneOverDetercolumnsinant,
				+columns[0][0] * OneOverDetercolumnsinant);

			return Inverse;
		}

		inline Matrix2x2 transpose() const noexcept
		{
			Matrix2x2 Result{ nullptr };
			Result[0][0] = columns[0][0];
			Result[0][1] = columns[1][0];
			Result[1][0] = columns[0][1];
			Result[1][1] = columns[1][1];
			return Matrix2x2{ Result };
		}

		inline value_type determinant() const noexcept
		{
			return columns[0][0] * columns[1][1] - columns[1][0] * columns[0][1];
		}

		inline FLOAT32 trace() const noexcept
		{
			return columns[0][0] + columns[1][1];
		}
	};
	
	extern NO_DISCARD FORCE_INLINE Matrix2x2 operator+(const Matrix2x2& matrix) noexcept
	{
		return Matrix2x2{ matrix };
	}
	
	extern NO_DISCARD FORCE_INLINE Matrix2x2 operator-(const Matrix2x2& matrix) noexcept
	{
		return Matrix2x2(
			-matrix.columns[0],
			-matrix.columns[1]);
	}
	
}

