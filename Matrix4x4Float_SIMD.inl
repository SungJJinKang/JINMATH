#include <Vector3.h>
#include <Vector4.h>

#include "SIMD_Core.h"

namespace math
{
	/// <summary>
	/// This class is made for SIMD computation. So it's aligned to 32 byte
	/// Because Matrix4X4Floag is aligned to 32 byte, It will works well with __m128 functions
	/// </summary>
	template <>
	struct alignas(32) Matrix<4, 4, FLOAT32>
	{
		using value_type = typename FLOAT32;
		using type = typename Matrix<4, 4, FLOAT32>;
		template <typename T2>
		using col_type_template = Vector<4, T2>;

		using col_type = Vector<4, FLOAT32>;

		[[nodiscard]] FORCE_INLINE static size_t columnCount()  noexcept { return 4; }

		/// <summary>
		/// All columns always is aligned to 16 byte, because Matrix<4, 4, FLOAT32> class is aligned to 16byte
		/// columns[0] start from address of Matrix class
		/// Vector<4, FLOAT32> is 16 byte -> columns[1] is also aligned to 16 byte
		/// </summary>
		col_type columns[4];

		FORCE_INLINE FLOAT32* data() noexcept
		{
			return columns[0].data();
		}

		const FORCE_INLINE FLOAT32* data() const noexcept
		{
			return columns[0].data();
		}

		static const type identify;

		FORCE_INLINE void InitializeSIMD(const type& matrix) noexcept
		{
			//std::memcpy(this->data(), matrix.data(), sizeof(type)); // this is slower than SIMD

			M256F* A = reinterpret_cast<M256F*>(this);
			const FLOAT32* B = reinterpret_cast<const FLOAT32*>(&matrix);
			A[0] = _mm256_load_ps(B); // copy 0 ~ 256 OF B to 0 ~ 256 this
			A[1] = _mm256_load_ps(B + 8); // B + 8 -> B + sizeof(FLOAT32) * 8  , copy 256 ~ 512 OF B to 256 ~ 512 this

		}

		FORCE_INLINE void InitializeSIMD(const col_type& column) noexcept
		{
			M256F* A = reinterpret_cast<M256F*>(this);
			const M128F* B = reinterpret_cast<const M128F*>(&column);
			A[0] = _mm256_broadcast_ps(B); // copy 0 ~ 256 OF B to 0 ~ 256 this
			A[1] = _mm256_broadcast_ps(B); // B + 8 -> B + sizeof(FLOAT32) * 8  , copy 256 ~ 512 OF B to 256 ~ 512 this
		}

		FORCE_INLINE Matrix() noexcept : columns{}
		{
		}

		/// <summary>
		/// for not init
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE Matrix(INT32 *) noexcept
		{
		}

		/// <summary>
		/// diagonal matrix
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		FORCE_INLINE explicit Matrix(value_type value) noexcept
			: columns{
			col_type(value, 0, 0, 0),
			col_type(0, value, 0, 0),
			col_type(0, 0, value, 0),
			col_type(0, 0, 0, value) }
		{
		}

		// we can't use SIMD at here
		// Parameters may is stored at register, not memory
		FORCE_INLINE Matrix
		(
			value_type x0, value_type y0, value_type z0, value_type w0,
			value_type x1, value_type y1, value_type z1, value_type w1,
			value_type x2, value_type y2, value_type z2, value_type w2,
			value_type x3, value_type y3, value_type z3, value_type w3
		) noexcept : columns{
			col_type(x0, x1, x2, x3),
			col_type(y0, y1, y2, y3),
			col_type(z0, z1, z2, z3),
			col_type(w0, w1, w2, w3) }
		{
		}

		FORCE_INLINE Matrix(const col_type& columnValue)
		{
			this->InitializeSIMD(columnValue);
		}

		FORCE_INLINE Matrix(const col_type& column0Value, const col_type& column1Value, const col_type& column2Value, const col_type& column3Value) noexcept
			: columns{ column0Value, column1Value, column2Value, column3Value }
		{
		}

		template <typename X, typename Y, typename Z, typename W>
		FORCE_INLINE Matrix(const col_type_template<X>& column0, const col_type_template<Y>& column1, const col_type_template<Z>& column2, const col_type_template<W>& column3) noexcept
			: columns{ column0, column1, column2, column3 }
		{
		}

		FORCE_INLINE Matrix(const type& matrix) noexcept
		{
			this->InitializeSIMD(matrix);
		}

		template <typename X>
		FORCE_INLINE Matrix(const Matrix<1, 1, X>& matrix) noexcept
			: columns{ matrix.columns[0], {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} }
		{
		}

		template <typename X>
		FORCE_INLINE Matrix(const Matrix<2, 2, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], {0, 0, 1, 0}, {0, 0, 0, 1} }
		{
		}

		template <typename X>
		FORCE_INLINE Matrix(const Matrix<3, 3, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], matrix.columns[2], {0, 0, 0, 1} }
		{
		}

		template <typename X>
		FORCE_INLINE Matrix(const Matrix<4, 4, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], matrix.columns[2], matrix.columns[3] }
		{
		}

		FORCE_INLINE type& operator=(value_type value) noexcept
		{
			columns[0] = value;
			columns[1] = value;
			columns[2] = value;
			columns[3] = value;
			return *this;
		}

		FORCE_INLINE type& operator=(const col_type& column) noexcept
		{
			this->InitializeSIMD(column);
			return *this;
		}

		FORCE_INLINE type& operator=(const type& matrix) noexcept
		{
			this->InitializeSIMD(matrix);
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Matrix<1, 1, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = 0;
			columns[2] = 0;
			columns[3] = { 0,0,0,1 };
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Matrix<2, 2, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = 0;
			columns[3] = { 0,0,0,1 };
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Matrix<3, 3, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = matrix.columns[2];
			columns[3] = { 0,0,0,1 };
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const Matrix<4, 4, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = matrix.columns[2];
			columns[3] = matrix.columns[3];
			return *this;
		}

		// 		Matrix(const type&) = default;
		// 		Matrix(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		std::basic_string<char> toString() const noexcept
		{
			std::stringstream ss;
			ss << columns[0].x << "  " << columns[1].x << "  " << columns[2].x << "  " << columns[3].x << '\n';
			ss << columns[0].y << "  " << columns[1].y << "  " << columns[2].y << "  " << columns[3].y << '\n';
			ss << columns[0].z << "  " << columns[1].z << "  " << columns[2].z << "  " << columns[3].z << '\n';
			ss << columns[0].w << "  " << columns[1].w << "  " << columns[2].w << "  " << columns[3].w;
			return ss.str();
		}

		[[nodiscard]] FORCE_INLINE col_type& operator[](size_t i)
		{
			assert(i >= 0 || i < columnCount());
			return columns[i];
		}

		[[nodiscard]] FORCE_INLINE const col_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < columnCount());
			return columns[i];
		}

		template <typename X>
		FORCE_INLINE type operator+(const Matrix<4, 4, X>& rhs) const noexcept
		{
			return type(columns[0] + rhs.columns[0], columns[1] + rhs.columns[1], columns[2] + rhs.columns[2], columns[3] + rhs.columns[3]);
		}

		template <typename X>
		FORCE_INLINE type operator-(const Matrix<4, 4, X>& rhs) const noexcept
		{
			return type(columns[0] - rhs.columns[0], columns[1] - rhs.columns[1], columns[2] - rhs.columns[2], columns[3] - rhs.columns[3]);
		}

		inline thread_local static M256F _REULST_MAT4[2]{};
		inline thread_local static M128F TEMP_M128F{};
		inline thread_local static Vector<4, FLOAT32> TEMP_VEC4{};

		[[nodiscard]] inline type operator*(const Matrix<4, 4, FLOAT32>& rhs) const noexcept
		{
			const M128F* A = reinterpret_cast<const M128F*>(this);
			//const M128F* A = (const M128F*)this->data(); // this is slower
			const M128F* B = reinterpret_cast<const M128F*>(&rhs);
			M128F* R = reinterpret_cast<M128F*>(&_REULST_MAT4);

			// First row of result (Matrix1[0] * Matrix2).
			TEMP_M128F = M128F_MUL(M128F_REPLICATE(B[0], 0), A[0]);
			TEMP_M128F = M128F_MUL_AND_ADD(M128F_REPLICATE(B[0], 1), A[1], TEMP_M128F);
			TEMP_M128F = M128F_MUL_AND_ADD(M128F_REPLICATE(B[0], 2), A[2], TEMP_M128F);
			R[0] = M128F_MUL_AND_ADD(M128F_REPLICATE(B[0], 3), A[3], TEMP_M128F);

			// Second row of result (Matrix1[1] * Matrix2).
			TEMP_M128F = M128F_MUL(M128F_REPLICATE(B[1], 0), A[0]);
			TEMP_M128F = M128F_MUL_AND_ADD(M128F_REPLICATE(B[1], 1), A[1], TEMP_M128F);
			TEMP_M128F = M128F_MUL_AND_ADD(M128F_REPLICATE(B[1], 2), A[2], TEMP_M128F);
			R[1] = M128F_MUL_AND_ADD(M128F_REPLICATE(B[1], 3), A[3], TEMP_M128F);

			// Third row of result (Matrix1[2] * Matrix2).
			TEMP_M128F = M128F_MUL(M128F_REPLICATE(B[2], 0), A[0]);
			TEMP_M128F = M128F_MUL_AND_ADD(M128F_REPLICATE(B[2], 1), A[1], TEMP_M128F);
			TEMP_M128F = M128F_MUL_AND_ADD(M128F_REPLICATE(B[2], 2), A[2], TEMP_M128F);
			R[2] = M128F_MUL_AND_ADD(M128F_REPLICATE(B[2], 3), A[3], TEMP_M128F);

			// Fourth row of result (Matrix1[3] * Matrix2).
			TEMP_M128F = M128F_MUL(M128F_REPLICATE(B[3], 0), A[0]);
			TEMP_M128F = M128F_MUL_AND_ADD(M128F_REPLICATE(B[3], 1), A[1], TEMP_M128F);
			TEMP_M128F = M128F_MUL_AND_ADD(M128F_REPLICATE(B[3], 2), A[2], TEMP_M128F);
			R[3] = M128F_MUL_AND_ADD(M128F_REPLICATE(B[3], 3), A[3], TEMP_M128F);

			return *reinterpret_cast<type*>(&_REULST_MAT4);
		}


		template <typename X>
		[[nodiscard]] inline Vector<4, X> operator*(const Vector<4, X>& vector) const noexcept
		{
			return Vector<4, FLOAT32>
			{
				this->columns[0][0] * vector[0] + this->columns[1][0] * vector[1] + this->columns[2][0] * vector[2] + this->columns[3][0] * vector[3],
					this->columns[0][1] * vector[0] + this->columns[1][1] * vector[1] + this->columns[2][1] * vector[2] + this->columns[3][1] * vector[3],
					this->columns[0][2] * vector[0] + this->columns[1][2] * vector[1] + this->columns[2][2] * vector[2] + this->columns[3][2] * vector[3],
					this->columns[0][3] * vector[0] + this->columns[1][3] * vector[1] + this->columns[2][3] * vector[2] + this->columns[3][3] * vector[3]
			};
		}

		template <>
		[[nodiscard]] inline Vector<4, FLOAT32> operator*(const Vector<4, FLOAT32>& vector) const noexcept
		{
			const M128F* A = reinterpret_cast<const M128F*>(this);
			const M128F* B = reinterpret_cast<const M128F*>(&vector);
			M128F* R = reinterpret_cast<M128F*>(&TEMP_VEC4);

			// First row of result (Matrix1[0] * Matrix2).
			*R = M128F_MUL(M128F_REPLICATE(*B, 0), A[0]);
			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 1), A[1], *R);
			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 2), A[2], *R);
			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 3), A[3], *R);

			return TEMP_VEC4;
		}

		/// <summary>
		/// Scalar version is faster than SIMD version
		/// </summary>
		/// <typeparam name="X"></typeparam>
		/// <param name="vector"></param>
		/// <returns></returns>
		template <typename X>
		[[nodiscard]] inline Vector<4, X> operator*(const Vector<3, X>& vector) const noexcept
		{
			return Vector<4, X>
			{
				this->columns[0][0] * vector[0] + this->columns[1][0] * vector[1] + this->columns[2][0] * vector[2] + this->columns[3][0],
					this->columns[0][1] * vector[0] + this->columns[1][1] * vector[1] + this->columns[2][1] * vector[2] + this->columns[3][1],
					this->columns[0][2] * vector[0] + this->columns[1][2] * vector[1] + this->columns[2][2] * vector[2] + this->columns[3][2],
					this->columns[0][3] * vector[0] + this->columns[1][3] * vector[1] + this->columns[2][3] * vector[2] + this->columns[3][3],
			};
		}	

		
		inline thread_local static Vector<4, FLOAT32> Vec4_Parameter{1.0f};
		inline thread_local static Vector<4, FLOAT32> Vec4_Result{1.0f};
		
		inline static M128F AllOne{ _mm_set1_ps(1.0f) };
		
		/// <summary>
		/// 
		/// </summary>
		/// <typeparam name="X"></typeparam>
		/// <param name="vector"></param>
		/// <returns></returns>
		template <>
		[[nodiscard]] inline Vector<4, FLOAT32> operator*(const Vector<3, FLOAT32>& vector) const noexcept
		{
			//vec3 is not aligned to 128bit, so we need to copy temporary vec3 data to vec4
			std::memcpy(&Vec4_Parameter, &vector, sizeof(Vector<3, FLOAT32>));

			const M128F* A = reinterpret_cast<const M128F*>(this);
			const M128F* B = reinterpret_cast<const M128F*>(&vector);
			M128F* R = reinterpret_cast<M128F*>(&Vec4_Result);

			// First row of result (Matrix1[0] * Matrix2).
			*R = M128F_MUL(M128F_REPLICATE(*B, 0), A[0]);
			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 1), A[1], *R);
			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 2), A[2], *R);
			*R = M128F_MUL_AND_ADD(AllOne, A[3], *R);

			return Vec4_Result;
		}
		
		
		

// 		/ <summary>
// 		/// 
// 		/// </summary>
// 		/// <param name="vector"></param>
// 		/// <returns></returns>
// 		template <>
// 		[[nodiscard]] FORCE_INLINE Vector<3, FLOAT32> operator*(const Vector<3, FLOAT32>& vector) const noexcept
// 		{
// 			Vector<4, FLOAT32> Result{ nullptr };
// 			type Vec4{ vector };
// 
// 			const M128F* A = (const M128F*)this;
// 			const M128F* B = (const M128F*)Vec4.data();
// 			M128F* R = reinterpret_cast<M128F*>(&Result);
// 
// 			// First row of result (Matrix1[0] * Matrix2).
// 			*R = M128F_MUL(M128F_REPLICATE(*B, 0), A[0]);
// 			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 1), A[1], *R);
// 			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 2), A[2], *R);
// 			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 3), A[3], *R);
// 
// 			return Vector<3, FLOAT32>
// 			{
// 				Result
// 			};
//   		}

		FORCE_INLINE type operator+(FLOAT32 rhs) const noexcept
		{
			return type(columns[0] + rhs, columns[1] + rhs, columns[2] + rhs, columns[3] + rhs);
		}

		FORCE_INLINE type operator-(FLOAT32 rhs) const noexcept
		{
			return type(columns[0] - rhs, columns[1] - rhs, columns[2] - rhs, columns[3] - rhs);
		}

		FORCE_INLINE type operator*(FLOAT32 rhs) const noexcept
		{
			return type(columns[0] * rhs, columns[1] * rhs, columns[2] * rhs, columns[3] * rhs);
		}

		/*
		template <typename X>
		FORCE_INLINE type operator/(const Matrix<4, X>& rhs)
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		template <typename X>
		FORCE_INLINE type operator%(const Matrix<4, X>& rhs)
		{
			return type(x % rhs.x, y % rhs.y, z % rhs.z, w % rhs.w);
		}
		*/

		template <typename X>
		FORCE_INLINE type& operator+=(const Matrix<4, 4, X>& rhs) noexcept
		{
			columns[0] += rhs.columns[0];
			columns[1] += rhs.columns[1];
			columns[2] += rhs.columns[2];
			columns[3] += rhs.columns[3];
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator-=(const Matrix<4, 4, X>& rhs) noexcept
		{
			columns[0] -= rhs.columns[0];
			columns[1] -= rhs.columns[1];
			columns[2] -= rhs.columns[2];
			columns[3] -= rhs.columns[3];
			return *this;
		}


		template <typename X>
		FORCE_INLINE type& operator*=(const Matrix<4, 4, X>& rhs) noexcept
		{
			return (*this = *this * rhs);
		}



		/*
		template <typename X>
		FORCE_INLINE type& operator/=(const Matrix<4, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator%=(const Matrix<4, X>& rhs)
		{
			x %= rhs.x;
			y %= rhs.y;
			z %= rhs.z;
			w %= rhs.w;
			return *this;
		}
		*/
		//

		FORCE_INLINE type& operator+=(FLOAT32 scalar) noexcept
		{
			columns[0] += scalar;
			columns[1] += scalar;
			columns[2] += scalar;
			columns[3] += scalar;
			return *this;
		}

		FORCE_INLINE type& operator-=(FLOAT32 scalar) noexcept
		{
			columns[0] -= scalar;
			columns[1] -= scalar;
			columns[2] -= scalar;
			columns[3] -= scalar;
			return *this;
		}

		FORCE_INLINE type& operator*=(FLOAT32 scalar) noexcept
		{
			columns[0] *= scalar;
			columns[1] *= scalar;
			columns[2] *= scalar;
			columns[3] *= scalar;
			return *this;
		}

		/*
		template <typename X>
		FORCE_INLINE type& operator/=(const X& scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}


		template <typename X, std::enable_if_t<std::is_integral_v<X>, bool> = true>
		FORCE_INLINE type& operator%=(const X& scalar)
		{
			x %= scalar;
			y %= scalar;
			z %= scalar;
			w %= scalar;
			return *this;
		}

		template <typename X, std::enable_if_t<std::is_floating_point_v<X>, bool> = true>
		FORCE_INLINE type& operator%=(const X& scalar)
		{

			x %= std::fmod(x, scalar);
			y %= std::fmod(y, scalar);
			z %= std::fmod(z, scalar);
			w %= std::fmod(w, scalar);
			return *this;
		}
		*/

		//

		[[nodiscard]] FORCE_INLINE bool operator==(const type& rhs) const noexcept
		{
			return this->columns[0] == rhs.columns[0] && this->columns[1] == rhs.columns[1] && this->columns[2] == rhs.columns[2] && this->columns[3] == rhs.columns[3];
		}

		[[nodiscard]] FORCE_INLINE bool operator!=(const type& rhs) const noexcept
		{
			return this->columns[0] != rhs.columns[0] || this->columns[1] != rhs.columns[1] || this->columns[2] != rhs.columns[2] || this->columns[3] != rhs.columns[3];
		}

		[[nodiscard]] FORCE_INLINE bool operator==(FLOAT32 number) const noexcept
		{
			return this->columns[0] == number && this->columns[1] == number && this->columns[2] == number && this->columns[3] == number;
		}

		[[nodiscard]] FORCE_INLINE bool operator!=(FLOAT32 number) const noexcept
		{
			return this->columns[0] != number || this->columns[1] != number || this->columns[2] != number || this->columns[3] != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator++() noexcept
		{
			++columns[0];
			++columns[1];
			++columns[2];
			++columns[3];
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE type operator++(INT32) noexcept
		{
			type Matrix{ *this };
			++* this;
			return Matrix;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator--() noexcept
		{
			--columns[0];
			--columns[1];
			--columns[2];
			--columns[3];
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE type operator--(INT32) noexcept
		{
			type Matrix{ *this };
			--* this;
			return Matrix;
		}

		operator std::basic_string<char>() const noexcept
		{
			return this->toString();
		}

		inline type inverse() const noexcept
		{
			value_type Coef00 = columns[2][2] * columns[3][3] - columns[3][2] * columns[2][3];
			value_type Coef02 = columns[1][2] * columns[3][3] - columns[3][2] * columns[1][3];
			value_type Coef03 = columns[1][2] * columns[2][3] - columns[2][2] * columns[1][3];

			value_type Coef04 = columns[2][1] * columns[3][3] - columns[3][1] * columns[2][3];
			value_type Coef06 = columns[1][1] * columns[3][3] - columns[3][1] * columns[1][3];
			value_type Coef07 = columns[1][1] * columns[2][3] - columns[2][1] * columns[1][3];

			value_type Coef08 = columns[2][1] * columns[3][2] - columns[3][1] * columns[2][2];
			value_type Coef10 = columns[1][1] * columns[3][2] - columns[3][1] * columns[1][2];
			value_type Coef11 = columns[1][1] * columns[2][2] - columns[2][1] * columns[1][2];

			value_type Coef12 = columns[2][0] * columns[3][3] - columns[3][0] * columns[2][3];
			value_type Coef14 = columns[1][0] * columns[3][3] - columns[3][0] * columns[1][3];
			value_type Coef15 = columns[1][0] * columns[2][3] - columns[2][0] * columns[1][3];

			value_type Coef16 = columns[2][0] * columns[3][2] - columns[3][0] * columns[2][2];
			value_type Coef18 = columns[1][0] * columns[3][2] - columns[3][0] * columns[1][2];
			value_type Coef19 = columns[1][0] * columns[2][2] - columns[2][0] * columns[1][2];

			value_type Coef20 = columns[2][0] * columns[3][1] - columns[3][0] * columns[2][1];
			value_type Coef22 = columns[1][0] * columns[3][1] - columns[3][0] * columns[1][1];
			value_type Coef23 = columns[1][0] * columns[2][1] - columns[2][0] * columns[1][1];

			col_type Fac0(Coef00, Coef00, Coef02, Coef03);
			col_type Fac1(Coef04, Coef04, Coef06, Coef07);
			col_type Fac2(Coef08, Coef08, Coef10, Coef11);
			col_type Fac3(Coef12, Coef12, Coef14, Coef15);
			col_type Fac4(Coef16, Coef16, Coef18, Coef19);
			col_type Fac5(Coef20, Coef20, Coef22, Coef23);

			col_type Vec0(columns[1][0], columns[0][0], columns[0][0], columns[0][0]);
			col_type Vec1(columns[1][1], columns[0][1], columns[0][1], columns[0][1]);
			col_type Vec2(columns[1][2], columns[0][2], columns[0][2], columns[0][2]);
			col_type Vec3(columns[1][3], columns[0][3], columns[0][3], columns[0][3]);

			col_type Inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
			col_type Inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
			col_type Inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
			col_type Inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

			col_type SignA(+1, -1, +1, -1);
			col_type SignB(-1, +1, -1, +1);
			type Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

			col_type Row0(Inverse[0][0], Inverse[1][0], Inverse[2][0], Inverse[3][0]);

			col_type Dot0(columns[0] * Row0);
			value_type Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

			value_type OneOverDeterminant = static_cast<value_type>(1) / Dot1;

			return type{ Inverse * OneOverDeterminant };
		}

		inline type transpose() const noexcept
		{
			type Result;
			Result[0][0] = columns[0][0];
			Result[0][1] = columns[1][0];
			Result[0][2] = columns[2][0];
			Result[0][3] = columns[3][0];

			Result[1][0] = columns[0][1];
			Result[1][1] = columns[1][1];
			Result[1][2] = columns[2][1];
			Result[1][3] = columns[3][1];

			Result[2][0] = columns[0][2];
			Result[2][1] = columns[1][2];
			Result[2][2] = columns[2][2];
			Result[2][3] = columns[3][2];

			Result[3][0] = columns[0][3];
			Result[3][1] = columns[1][3];
			Result[3][2] = columns[2][3];
			Result[3][3] = columns[3][3];
			return Result;
		}

		template <typename U = FLOAT32, std::enable_if_t<std::is_signed_v<U>, bool> = true>
		inline value_type determinant() const noexcept
		{
			value_type SubFactor00 = columns[2][2] * columns[3][3] - columns[3][2] * columns[2][3];
			value_type SubFactor01 = columns[2][1] * columns[3][3] - columns[3][1] * columns[2][3];
			value_type SubFactor02 = columns[2][1] * columns[3][2] - columns[3][1] * columns[2][2];
			value_type SubFactor03 = columns[2][0] * columns[3][3] - columns[3][0] * columns[2][3];
			value_type SubFactor04 = columns[2][0] * columns[3][2] - columns[3][0] * columns[2][2];
			value_type SubFactor05 = columns[2][0] * columns[3][1] - columns[3][0] * columns[2][1];

			col_type DetCof(
				+(columns[1][1] * SubFactor00 - columns[1][2] * SubFactor01 + columns[1][3] * SubFactor02),
				-(columns[1][0] * SubFactor00 - columns[1][2] * SubFactor03 + columns[1][3] * SubFactor04),
				+(columns[1][0] * SubFactor01 - columns[1][1] * SubFactor03 + columns[1][3] * SubFactor05),
				-(columns[1][0] * SubFactor02 - columns[1][1] * SubFactor04 + columns[1][2] * SubFactor05));

			return
				columns[0][0] * DetCof[0] + columns[0][1] * DetCof[1] +
				columns[0][2] * DetCof[2] + columns[0][3] * DetCof[3];
		}


		FORCE_INLINE auto trace() const noexcept
		{
			return columns[0][0] + columns[1][1] + columns[2][2] + columns[3][3];
		}
	};

	template <>
	FORCE_INLINE Matrix<4, 4, FLOAT32> operator+(const Matrix<4, 4, FLOAT32>& matrix) noexcept
	{
		return matrix;
	}

	template <>
	FORCE_INLINE Matrix<4, 4, FLOAT32> operator-(const Matrix<4, 4, FLOAT32>& matrix) noexcept
	{
		return Matrix<4, 4, FLOAT32>(
			-matrix.columns[0],
			-matrix.columns[1],
			-matrix.columns[2],
			-matrix.columns[3]);
	}

	/// <summary>
	/// https://macton.smugmug.com/Other/2008-07-15-by-Eye-Fi/n-xmKDH/i-bJq8JqZ/A
	/// </summary>
	/// <param name="eightPlanes"></param>
	/// <param name="pt">position : x, y, z </param>
	/// <returns></returns>
// 	bool InFrustumSIMD(math::Vector<4, FLOAT32>* eightPlanes, const math::Vector<4, FLOAT32>& twoPoint)
// 	{
// 		const M256F*
// 
// 		FLOAT32 d;
// 		d = plane.a * pt.x + plane.b * pt.y + plane.c * pt.z + plane.d;
// 		if (d < 0) return NEGATIVE;
// 		if (d > 0) return POSITIVE;
// 		return ON_PLANE;
// 	}

	/// <summary>
	/// https://www.slideshare.net/DICEStudio/culling-the-battlefield-data-oriented-design-in-practice
	/// 
	///	eightPlanes should contain data like this
	/// Use ExtractPlanesFromMVPMatrixForSIMD
	/// 
	/// eightPlanes[0] : x of Plane0, x of Plane1, x of Plane2, x of Plane3
	/// eightPlanes[1] : y of Plane0, y of Plane1, y of Plane2, y of Plane3
	/// eightPlanes[2] : z of Plane0, z of Plane1, z of Plane2, z of Plane3
	/// eightPlanes[3] : w of Plane0, w of Plane1, w of Plane2, w of Plane3
	/// eightPlanes[4] : x of Plane4, x of Plane5, x of Plane4, x of Plane5
	/// eightPlanes[5] : y of Plane4, y of Plane5, y of Plane4, y of Plane5
	/// eightPlanes[6] : z of Plane4, z of Plane5, z of Plane4, z of Plane5
	/// eightPlanes[7] : w of Plane4, w of Plane5, w of Plane4, w of Plane5
	/// </summary>
	/// <param name="sixPlanes"></param>
	/// <param name="twoPoint">aligned to 16 byte</param>
	/// <returns>when first low bit is 1, Pos 1 is In Frustum, when second low bit is 1, Pos 2 is In Frustum,</returns>
	inline char CheckInFrustumSIMDWithTwoPoint(const math::Vector<4, FLOAT32>* eightPlanes, const math::Vector<4, FLOAT32>* twoPoint)
	{
		//We can't use M256F. because two twoPoint isn't aligned to 32 byte

		const M128F* m128f_eightPlanes = reinterpret_cast<const M128F*>(eightPlanes); // x of plane 0, 1, 2, 3  and y of plane 0, 1, 2, 3 
		const M128F* m128f_2Point = reinterpret_cast<const M128F*>(twoPoint);

		M128F posA_xxxx = M128F_REPLICATE(m128f_2Point[0], 0); // xxxx of first twoPoint and xxxx of second twoPoint
		M128F posA_yyyy = M128F_REPLICATE(m128f_2Point[0], 1); // yyyy of first twoPoint and yyyy of second twoPoint
		M128F posA_zzzz = M128F_REPLICATE(m128f_2Point[0], 2); // zzzz of first twoPoint and zzzz of second twoPoint
		
		M128F posA_rrrr = M128F_REPLICATE(m128f_2Point[0], 3); // rrrr of first twoPoint and rrrr of second twoPoint

		M128F dotPosA = M128F_MUL_AND_ADD(posA_zzzz, m128f_eightPlanes[2], m128f_eightPlanes[3]);
		dotPosA = M128F_MUL_AND_ADD(posA_yyyy, m128f_eightPlanes[1], dotPosA);
		dotPosA = M128F_MUL_AND_ADD(posA_xxxx, m128f_eightPlanes[0], dotPosA); // dot Pos A with Plane 0, dot Pos A with Plane 1, dot Pos A with Plane 2, dot Pos A with Plane 3

		M128F posB_xxxx = M128F_REPLICATE(m128f_2Point[1], 0); // xxxx of first twoPoint and xxxx of second twoPoint
		M128F posB_yyyy = M128F_REPLICATE(m128f_2Point[1], 1); // yyyy of first twoPoint and yyyy of second twoPoint
		M128F posB_zzzz = M128F_REPLICATE(m128f_2Point[1], 2); // zzzz of first twoPoint and zzzz of second twoPoint
		
		M128F posB_rrrr = M128F_REPLICATE(m128f_2Point[1], 3); // rrrr of first twoPoint and rrrr of second twoPoint

		M128F dotPosB = M128F_MUL_AND_ADD(posB_zzzz, m128f_eightPlanes[2], m128f_eightPlanes[3]);
		dotPosB = M128F_MUL_AND_ADD(posB_yyyy, m128f_eightPlanes[1], dotPosB);
		dotPosB = M128F_MUL_AND_ADD(posB_xxxx, m128f_eightPlanes[0], dotPosB); // dot Pos B with Plane 0, dot Pos B with Plane 1, dot Pos B with Plane 2, dot Pos B with Plane 3

		//https://software.intel.com/sites/landingpage/IntrinsicsGuide/#expand=69,124,4167,4167,447,447,3148,3148&techs=SSE,SSE2,SSE3,SSSE3,SSE4_1,SSE4_2,AVX&text=insert
		M128F posAB_xxxx = _mm_shuffle_ps(m128f_2Point[0], m128f_2Point[1], SHUFFLEMASK(0, 0, 0, 0)); // x of twoPoint[0] , x of twoPoint[0], x of twoPoint[1] , x of twoPoint[1]
		M128F posAB_yyyy = _mm_shuffle_ps(m128f_2Point[0], m128f_2Point[1], SHUFFLEMASK(1, 1, 1, 1)); // y of twoPoint[0] , y of twoPoint[0], y of twoPoint[1] , y of twoPoint[1]
		M128F posAB_zzzz = _mm_shuffle_ps(m128f_2Point[0], m128f_2Point[1], SHUFFLEMASK(2, 2, 2, 2)); // z of twoPoint[0] , z of twoPoint[0], z of twoPoint[1] , z of twoPoint[1]
		
		M128F posAB_rrrr = _mm_shuffle_ps(m128f_2Point[0], m128f_2Point[1], SHUFFLEMASK(3, 3, 3, 3)); // r of twoPoint[0] , r of twoPoint[1], w of twoPoint[1] , w of twoPoint[1]

		M128F dotPosAB45 = M128F_MUL_AND_ADD(posAB_zzzz, m128f_eightPlanes[6], m128f_eightPlanes[7]);
		dotPosAB45 = M128F_MUL_AND_ADD(posAB_yyyy, m128f_eightPlanes[5], dotPosAB45);
		dotPosAB45 = M128F_MUL_AND_ADD(posAB_xxxx, m128f_eightPlanes[4], dotPosAB45);

		dotPosA = _mm_cmpgt_ps(dotPosA, posA_rrrr); // if elemenet[i] have value 1, Pos A is in frustum Plane[i] ( 0 <= i < 4 )
		dotPosB = _mm_cmpgt_ps(dotPosB, posB_rrrr); // if elemenet[i] have value 1, Pos B is in frustum Plane[i] ( 0 <= i < 4 )
		dotPosAB45 = _mm_cmpgt_ps(dotPosAB45, posAB_rrrr);

		// this is wrong
		//dotPosA = _mm_cmpgt_ps(posA_rrrr, dotPosA); // if elemenet[i] have value 1, Pos A is in frustum Plane[i] ( 0 <= i < 4 )
		//dotPosB = _mm_cmpgt_ps(posB_rrrr, dotPosB); // if elemenet[i] have value 1, Pos B is in frustum Plane[i] ( 0 <= i < 4 )
		//dotPosAB45 = _mm_cmpgt_ps(posAB_rrrr, dotPosAB45);

		M128F dotPosA45 = _mm_blend_ps(dotPosAB45, dotPosA, SHUFFLEMASK(0, 3, 0, 0)); // Is In Plane with Plane[4], Plane[5], Plane[2], Plane[3]
		M128F dotPosB45 = _mm_blend_ps(dotPosB, dotPosAB45, SHUFFLEMASK(0, 3, 0, 0)); // Is In Plane with Plane[0], Plane[1], Plane[4], Plane[5]
		
		M128F RMaskA = _mm_and_ps(dotPosA, dotPosA45); //when everty bits is 1, PointA is in frustum
		M128F RMaskB = _mm_and_ps(dotPosB, dotPosB45);//when everty bits is 1, PointB is in frustum

		INT32 IsPointAInFrustum = _mm_test_all_ones(*reinterpret_cast<__m128i*>(&RMaskA)); // value is 1, Point in in frustum
		INT32 IsPointBInFrustum = _mm_test_all_ones(*reinterpret_cast<__m128i*>(&RMaskB));
		
		char IsPointABInFrustum = IsPointAInFrustum | (IsPointBInFrustum << 1);
		return IsPointABInFrustum;
	}

	/*
	inline char CheckInFrustumSIMDChunk(math::Vector<4, FLOAT32>** arrayOfEightFrustumPlanes, UINT32 frustumCount, const math::Vector<4, FLOAT32>* points, UINT32 pointCount, char* resultFlags)
	{
		for (UINT32 frustumIndex = 0; frustumIndex < frustumCount; ++frustumIndex)
		{
			const M256F* m128f_eightPlanes = reinterpret_cast<const M256F*>(arrayOfEightFrustumPlanes[frustumIndex]); // x of plane 0, 1, 2, 3  and y of plane 0, 1, 2, 3 
		
			M256F posA_xxxx; // xxxx of first twoPoint and xxxx of second twoPoint
			M128F posA_xxxx; // xxxx of first twoPoint and xxxx of second twoPoint
			M256F posA_yyyy; // yyyy of first twoPoint and yyyy of second twoPoint
			M256F posA_zzzz; // zzzz of first twoPoint and zzzz of second twoPoint

			M256F posA_rrrr; // rrrr of first twoPoint and rrrr of second twoPoint

			M256F dotPosA;

			for (UINT32 pointIndex; pointIndex < pointCount; ++pointIndex)
			{
				posA_xxxx = M256F_REPLICATE(points[pointIndex], 0); // xxxx of first twoPoint and xxxx of second twoPoint
				posA_yyyy = M128F_REPLICATE(points[pointIndex], 1); // yyyy of first twoPoint and yyyy of second twoPoint
				posA_zzzz = M128F_REPLICATE(points[pointIndex], 2); // zzzz of first twoPoint and zzzz of second twoPoint

				posA_rrrr = M128F_REPLICATE(points[pointIndex], 3); // rrrr of first twoPoint and rrrr of second twoPoint

				dotPosA = M128F_MUL_AND_ADD(posA_zzzz, m128f_eightPlanes[2], m128f_eightPlanes[3]);
				dotPosA = M128F_MUL_AND_ADD(posA_yyyy, m128f_eightPlanes[1], dotPosA);
				dotPosA = M128F_MUL_AND_ADD(posA_xxxx, m128f_eightPlanes[0], dotPosA);
			}
			
		}
		
		const M128F* m128f_2Point = reinterpret_cast<const M128F*>(twoPoint);

		M128F posA_xxxx = M128F_REPLICATE(m128f_2Point[0], 0); // xxxx of first twoPoint and xxxx of second twoPoint
		M128F posA_yyyy = M128F_REPLICATE(m128f_2Point[0], 1); // yyyy of first twoPoint and yyyy of second twoPoint
		M128F posA_zzzz = M128F_REPLICATE(m128f_2Point[0], 2); // zzzz of first twoPoint and zzzz of second twoPoint

		M128F posA_rrrr = M128F_REPLICATE(m128f_2Point[0], 3); // rrrr of first twoPoint and rrrr of second twoPoint

		M128F dotPosA = M128F_MUL_AND_ADD(posA_zzzz, m128f_eightPlanes[2], m128f_eightPlanes[3]);
		dotPosA = M128F_MUL_AND_ADD(posA_yyyy, m128f_eightPlanes[1], dotPosA);
		dotPosA = M128F_MUL_AND_ADD(posA_xxxx, m128f_eightPlanes[0], dotPosA); // dot Pos A with Plane 0, dot Pos A with Plane 1, dot Pos A with Plane 2, dot Pos A with Plane 3

		M128F posB_xxxx = M128F_REPLICATE(m128f_2Point[1], 0); // xxxx of first twoPoint and xxxx of second twoPoint
		M128F posB_yyyy = M128F_REPLICATE(m128f_2Point[1], 1); // yyyy of first twoPoint and yyyy of second twoPoint
		M128F posB_zzzz = M128F_REPLICATE(m128f_2Point[1], 2); // zzzz of first twoPoint and zzzz of second twoPoint

		M128F posB_rrrr = M128F_REPLICATE(m128f_2Point[1], 3); // rrrr of first twoPoint and rrrr of second twoPoint

		M128F dotPosB = M128F_MUL_AND_ADD(posB_zzzz, m128f_eightPlanes[2], m128f_eightPlanes[3]);
		dotPosB = M128F_MUL_AND_ADD(posB_yyyy, m128f_eightPlanes[1], dotPosB);
		dotPosB = M128F_MUL_AND_ADD(posB_xxxx, m128f_eightPlanes[0], dotPosB); // dot Pos B with Plane 0, dot Pos B with Plane 1, dot Pos B with Plane 2, dot Pos B with Plane 3

		//https://software.intel.com/sites/landingpage/IntrinsicsGuide/#expand=69,124,4167,4167,447,447,3148,3148&techs=SSE,SSE2,SSE3,SSSE3,SSE4_1,SSE4_2,AVX&text=insert
		M128F posAB_xxxx = _mm_shuffle_ps(m128f_2Point[0], m128f_2Point[1], SHUFFLEMASK(0, 0, 0, 0)); // x of twoPoint[0] , x of twoPoint[0], x of twoPoint[1] , x of twoPoint[1]
		M128F posAB_yyyy = _mm_shuffle_ps(m128f_2Point[0], m128f_2Point[1], SHUFFLEMASK(1, 1, 1, 1)); // y of twoPoint[0] , y of twoPoint[0], y of twoPoint[1] , y of twoPoint[1]
		M128F posAB_zzzz = _mm_shuffle_ps(m128f_2Point[0], m128f_2Point[1], SHUFFLEMASK(2, 2, 2, 2)); // z of twoPoint[0] , z of twoPoint[0], z of twoPoint[1] , z of twoPoint[1]

		M128F posAB_rrrr = _mm_shuffle_ps(m128f_2Point[0], m128f_2Point[1], SHUFFLEMASK(3, 3, 3, 3)); // r of twoPoint[0] , r of twoPoint[1], w of twoPoint[1] , w of twoPoint[1]

		M128F dotPosAB45 = M128F_MUL_AND_ADD(posAB_zzzz, m128f_eightPlanes[6], m128f_eightPlanes[7]);
		dotPosAB45 = M128F_MUL_AND_ADD(posAB_yyyy, m128f_eightPlanes[5], dotPosAB45);
		dotPosAB45 = M128F_MUL_AND_ADD(posAB_xxxx, m128f_eightPlanes[4], dotPosAB45);

		dotPosA = _mm_cmpgt_ps(dotPosA, posA_rrrr); // if elemenet[i] have value 1, Pos A is in frustum Plane[i] ( 0 <= i < 4 )
		dotPosB = _mm_cmpgt_ps(dotPosB, posB_rrrr); // if elemenet[i] have value 1, Pos B is in frustum Plane[i] ( 0 <= i < 4 )
		dotPosAB45 = _mm_cmpgt_ps(dotPosAB45, posAB_rrrr);

		// this is wrong
		//dotPosA = _mm_cmpgt_ps(posA_rrrr, dotPosA); // if elemenet[i] have value 1, Pos A is in frustum Plane[i] ( 0 <= i < 4 )
		//dotPosB = _mm_cmpgt_ps(posB_rrrr, dotPosB); // if elemenet[i] have value 1, Pos B is in frustum Plane[i] ( 0 <= i < 4 )
		//dotPosAB45 = _mm_cmpgt_ps(posAB_rrrr, dotPosAB45);

		M128F dotPosA45 = _mm_blend_ps(dotPosAB45, dotPosA, SHUFFLEMASK(0, 3, 0, 0)); // Is In Plane with Plane[4], Plane[5], Plane[2], Plane[3]
		M128F dotPosB45 = _mm_blend_ps(dotPosB, dotPosAB45, SHUFFLEMASK(0, 3, 0, 0)); // Is In Plane with Plane[0], Plane[1], Plane[4], Plane[5]

		M128F RMaskA = _mm_and_ps(dotPosA, dotPosA45); //when everty bits is 1, PointA is in frustum
		M128F RMaskB = _mm_and_ps(dotPosB, dotPosB45);//when everty bits is 1, PointB is in frustum

		INT32 IsPointAInFrustum = _mm_test_all_ones(*reinterpret_cast<__m128i*>(&RMaskA)); // value is 1, Point in in frustum
		INT32 IsPointBInFrustum = _mm_test_all_ones(*reinterpret_cast<__m128i*>(&RMaskB));

		char IsPointABInFrustum = IsPointAInFrustum | (IsPointBInFrustum << 1);
		return IsPointABInFrustum;
	}
	*/

	/// <summary>
	/// TODO : �̰� �Ϸ��� twoPoint �ΰ��� ��� 32byte�� align�ǰ� �ؾ���, 
	/// TODO : eightPlanes�� eightPlanes[0]�̶� eightPlanes[1] �Ѵ� x component������
	/// 
	/// </summary>
	/// <param name="eightPlanes"></param>	
	/// <param name="twoPoint"></param>
	/// <returns></returns>
// 	bool InFrustum256FSIMDWithTwoPoint(math::Vector<4, FLOAT32>* eightPlanes, const math::Vector<4, FLOAT32>* twoPoint)
// 	{
// 		//We can't use M256F. because two twoPoint isn't aligned to 32 byte
// 
// 		const M128F* m128f_eightPlanes = reinterpret_cast<const M128F*>(eightPlanes); // x of plane 0, 1, 2, 3  and y of plane 0, 1, 2, 3 
// 		const M128F* m128f_2Point = reinterpret_cast<const M128F*>(twoPoint);
// 
// 		M128F posA_xxxx = M128F_REPLICATE(m128f_2Point[0], 0); // xxxx of first twoPoint and xxxx of second twoPoint
// 		M128F posA_yyyy = M128F_REPLICATE(m128f_2Point[0], 1); // yyyy of first twoPoint and yyyy of second twoPoint
// 		M128F posA_zzzz = M128F_REPLICATE(m128f_2Point[0], 2); // zzzz of first twoPoint and zzzz of second twoPoint
// 		M128F posA_rrrr = M128F_REPLICATE(m128f_2Point[0], 3); // rrrr of first twoPoint and rrrr of second twoPoint
// 
// 		M256F dotTwoPos = M128F_MUL_AND_ADD(posA_xxxx, eightPlanes[2], eightPlanes[3]);
// 		FLOAT32 d;
// 		d = plane.a * pt.x + plane.b * pt.y + plane.c * pt.z + plane.d;
// 		if (d < 0) return NEGATIVE;
// 		if (d > 0) return POSITIVE;
// 		return ON_PLANE;
// 	}

	/// <summary>
	/// Extract 6 Planes ( 8 Planes ) From MVPMatrix
	/// SIMD Version
	///  sixPlanes[0] : x of Plane0, y of Plane0, z of Plane0, w of Plane0
	///  sixPlanes[1] : x of Plane1, y of Plane1, z of Plane1, w of Plane1
	///  sixPlanes[2] : x of Plane2, y of Plane2, z of Plane2, w of Plane2
	///  sixPlanes[3] : x of Plane3, y of Plane3, z of Plane3, w of Plane3
	///  sixPlanes[4] : x of Plane4, y of Plane4, z of Plane4, w of Plane4
	///  sixPlanes[5] : x of Plane5, y of Plane5, z of Plane5, w of Plane5
	/// references :
	/// https://www.slideshare.net/DICEStudio/culling-the-battlefield-data-oriented-design-in-practice
	/// https://www.gamedevs.org/uploads/fast-extraction-viewing-frustum-planes-from-world-view-projection-matrix.pdf
	/// https://macton.smugmug.com/Other/2008-07-15-by-Eye-Fi/n-xmKDH/i-bJq8JqZ/A
	/// </summary>
	template <>
	inline void ExtractPlanesFromVIewProjectionMatrix(const Matrix<4, 4, FLOAT32>& viewProjectionMatrix, math::Vector<4, FLOAT32>* sixPlanes, bool normalize) noexcept
	{
		sixPlanes[0].x = viewProjectionMatrix[0][3] + viewProjectionMatrix[0][0];
		sixPlanes[0].y = viewProjectionMatrix[1][3] + viewProjectionMatrix[1][0];
		sixPlanes[0].z = viewProjectionMatrix[2][3] + viewProjectionMatrix[2][0];
		sixPlanes[0].w = viewProjectionMatrix[3][3] + viewProjectionMatrix[3][0];
		// Right clipping plane
		sixPlanes[1].x = viewProjectionMatrix[0][3] - viewProjectionMatrix[0][0];
		sixPlanes[1].y = viewProjectionMatrix[1][3] - viewProjectionMatrix[1][0];
		sixPlanes[1].z = viewProjectionMatrix[2][3] - viewProjectionMatrix[2][0];
		sixPlanes[1].w = viewProjectionMatrix[3][3] - viewProjectionMatrix[3][0];
		// Top clipping plane
		sixPlanes[2].x = viewProjectionMatrix[0][3] - viewProjectionMatrix[0][1];
		sixPlanes[2].y = viewProjectionMatrix[1][3] - viewProjectionMatrix[1][1];
		sixPlanes[2].z = viewProjectionMatrix[2][3] - viewProjectionMatrix[2][1];
		sixPlanes[2].w = viewProjectionMatrix[3][3] - viewProjectionMatrix[3][1];
		// Bottom clipping plane
		sixPlanes[3].x = viewProjectionMatrix[0][3] + viewProjectionMatrix[0][1];
		sixPlanes[3].y = viewProjectionMatrix[1][3] + viewProjectionMatrix[1][1];
		sixPlanes[3].z = viewProjectionMatrix[2][3] + viewProjectionMatrix[2][1];
		sixPlanes[3].w = viewProjectionMatrix[3][3] + viewProjectionMatrix[3][1];
		// Near clipping plane
		sixPlanes[4].x = viewProjectionMatrix[0][3] + viewProjectionMatrix[0][2];
		sixPlanes[4].y = viewProjectionMatrix[1][3] + viewProjectionMatrix[1][2];
		sixPlanes[4].z = viewProjectionMatrix[2][3] + viewProjectionMatrix[2][2];
		sixPlanes[4].w = viewProjectionMatrix[3][3] + viewProjectionMatrix[3][2];
		// Far clipping plane
		sixPlanes[5].x = viewProjectionMatrix[0][3] - viewProjectionMatrix[0][2];
		sixPlanes[5].y = viewProjectionMatrix[1][3] - viewProjectionMatrix[1][2];
		sixPlanes[5].z = viewProjectionMatrix[2][3] - viewProjectionMatrix[2][2];
		sixPlanes[5].w = viewProjectionMatrix[3][3] - viewProjectionMatrix[3][2];

		// Normalize the plane equations, if requested
		if (normalize == true)
		{
			NormalizePlane(sixPlanes[0]);
			NormalizePlane(sixPlanes[1]);
			NormalizePlane(sixPlanes[2]);
			NormalizePlane(sixPlanes[3]);
			NormalizePlane(sixPlanes[4]);
			NormalizePlane(sixPlanes[5]);
		}
	}




	/// <summary>
	/// 
	///	Extract Planes for SIMD computation from VP Matrix
	/// reference : https://www.gamedevs.org/uploads/fast-extraction-viewing-frustum-planes-from-world-view-projection-matrix.pdf
	/// 
	/// eightPlanes[0] : x of Plane0, x of Plane1, x of Plane2, x of Plane3
	/// eightPlanes[1] : y of Plane0, y of Plane1, y of Plane2, y of Plane3
	/// eightPlanes[2] : z of Plane0, z of Plane1, z of Plane2, z of Plane3
	/// eightPlanes[3] : w of Plane0, w of Plane1, w of Plane2, w of Plane3
	/// 
	/// eightPlanes[4] : x of Plane4, x of Plane5, x of Plane4, x of Plane5
	/// eightPlanes[5] : y of Plane4, y of Plane5, y of Plane4, y of Plane5
	/// eightPlanes[6] : z of Plane4, z of Plane5, z of Plane4, z of Plane5
	/// eightPlanes[7] : w of Plane4, w of Plane5, w of Plane4, w of Plane5
	/// </summary>
	/// <param name="ModelViewProjectionMatrix"></param>
	/// <param name="eightPlanes"></param>
	/// <param name="normalize"></param>
	/// <returns></returns>
	template <>
	inline void ExtractSIMDPlanesFromViewProjectionMatrix(const Matrix<4, 4, FLOAT32>& viewProjectionMatrix, math::Vector<4, FLOAT32>* eightPlanes, bool normalize) noexcept
	{
		
		math::Vector4 sixPlane[6]{};

		ExtractPlanesFromVIewProjectionMatrix(viewProjectionMatrix, sixPlane, normalize);

		eightPlanes[0].x = sixPlane[0].x;
		eightPlanes[0].y = sixPlane[1].x;
		eightPlanes[0].z = sixPlane[2].x;
		eightPlanes[0].w = sixPlane[3].x;

		eightPlanes[1].x = sixPlane[0].y;
		eightPlanes[1].y = sixPlane[1].y;
		eightPlanes[1].z = sixPlane[2].y;
		eightPlanes[1].w = sixPlane[3].y;

		eightPlanes[2].x = sixPlane[0].z;
		eightPlanes[2].y = sixPlane[1].z;
		eightPlanes[2].z = sixPlane[2].z;
		eightPlanes[2].w = sixPlane[3].z;

		eightPlanes[3].x = sixPlane[0].w;
		eightPlanes[3].y = sixPlane[1].w;
		eightPlanes[3].z = sixPlane[2].w;
		eightPlanes[3].w = sixPlane[3].w;

		eightPlanes[4].x = sixPlane[4].x;
		eightPlanes[4].y = sixPlane[5].x;
		eightPlanes[4].z = sixPlane[4].x;
		eightPlanes[4].w = sixPlane[5].x;

		eightPlanes[5].x = sixPlane[4].y;
		eightPlanes[5].y = sixPlane[5].y;
		eightPlanes[5].z = sixPlane[4].y;
		eightPlanes[5].w = sixPlane[5].y;

		eightPlanes[6].x = sixPlane[4].z;
		eightPlanes[6].y = sixPlane[5].z;
		eightPlanes[6].z = sixPlane[4].z;
		eightPlanes[6].w = sixPlane[5].z;

		eightPlanes[7].x = sixPlane[4].w;
		eightPlanes[7].y = sixPlane[5].w;
		eightPlanes[7].z = sixPlane[4].w;
		eightPlanes[7].w = sixPlane[5].w;
		
	}

}

