namespace math
{
	/// <summary>
	/// This class is made for SIMD computation. So it's aligned to 32 byte
	/// Because Matrix4X4Floag is aligned to 32 byte, It will works well with __m128 functions
	/// </summary>
	template <>
	struct alignas(32) Matrix<4, 4, float>
	{
		using value_type = typename float;
		using type = typename Matrix<4, 4, float>;
		template <typename T2>
		using col_type_template = Vector<4, T2>;

		using col_type = Vector<4, float>;

		[[nodiscard]] FORCE_INLINE static constexpr size_t columnCount()  noexcept { return 4; }

		/// <summary>
		/// All columns always is aligned to 16 byte, because Matrix<4, 4, float> class is aligned to 16byte
		/// columns[0] start from address of Matrix class
		/// Vector<4, float> is 16 byte -> columns[1] is also aligned to 16 byte
		/// </summary>
		col_type columns[4];

		FORCE_INLINE float* data() noexcept
		{
			return columns[0].data();
		}

		const FORCE_INLINE float* data() const noexcept
		{
			return columns[0].data();
		}

		static const type identify;

		FORCE_INLINE void InitializeSIMD(const type& matrix) noexcept
		{
			//std::memcpy(this->data(), matrix.data(), sizeof(type)); // this is slower than SIMD

			M256F* A = reinterpret_cast<M256F*>(this);
			const float* B = reinterpret_cast<const float*>(&matrix);
			A[0] = _mm256_load_ps(B); // copy 0 ~ 256 OF B to 0 ~ 256 this
			A[1] = _mm256_load_ps(B + 8); // B + 8 -> B + sizeof(float) * 8  , copy 256 ~ 512 OF B to 256 ~ 512 this

		}

		FORCE_INLINE void InitializeSIMD(const col_type& column) noexcept
		{
			M256F* A = reinterpret_cast<M256F*>(this);
			const M128F* B = reinterpret_cast<const M128F*>(&column);
			A[0] = _mm256_broadcast_ps(B); // copy 0 ~ 256 OF B to 0 ~ 256 this
			A[1] = _mm256_broadcast_ps(B); // B + 8 -> B + sizeof(float) * 8  , copy 256 ~ 512 OF B to 256 ~ 512 this
		}

		FORCE_INLINE constexpr Matrix() noexcept : columns{}
		{
		}

		/// <summary>
		/// for not init
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE Matrix(int *) noexcept
		{
		}

		/// <summary>
		/// diagonal matrix
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		FORCE_INLINE constexpr explicit Matrix(value_type value) noexcept
			: columns{
			col_type(value, 0, 0, 0),
			col_type(0, value, 0, 0),
			col_type(0, 0, value, 0),
			col_type(0, 0, 0, value) }
		{
		}

		// we can't use SIMD at here
		// Parameters may is stored at register, not memory
		FORCE_INLINE constexpr Matrix
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

		FORCE_INLINE constexpr Matrix(const col_type& column0Value, const col_type& column1Value, const col_type& column2Value, const col_type& column3Value) noexcept
			: columns{ column0Value, column1Value, column2Value, column3Value }
		{
		}

		template <typename X, typename Y, typename Z, typename W>
		FORCE_INLINE constexpr Matrix(const col_type_template<X>& column0, const col_type_template<Y>& column1, const col_type_template<Z>& column2, const col_type_template<W>& column3) noexcept
			: columns{ column0, column1, column2, column3 }
		{
		}

		FORCE_INLINE explicit Matrix(const type& matrix) noexcept
		{
			this->InitializeSIMD(matrix);
		}
	
		template <typename X>
		FORCE_INLINE constexpr Matrix(const Matrix<1, 1, X>& matrix) noexcept
			: columns{ matrix.columns[0], {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Matrix(const Matrix<2, 2, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], {0, 0, 1, 0}, {0, 0, 0, 1} }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Matrix(const Matrix<3, 3, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], matrix.columns[2], {0, 0, 0, 1} }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Matrix(const Matrix<4, 4, X>& matrix) noexcept
			: columns{ matrix.columns[0], matrix.columns[1], matrix.columns[2], matrix.columns[3] }
		{
		}

		FORCE_INLINE constexpr type& operator=(value_type value) noexcept
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
		FORCE_INLINE constexpr type& operator=(const Matrix<1, 1, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = 0;
			columns[2] = 0;
			columns[3] = { 0,0,0,1 };
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Matrix<2, 2, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = 0;
			columns[3] = { 0,0,0,1 };
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Matrix<3, 3, X>& matrix) noexcept
		{
			columns[0] = matrix.columns[0];
			columns[1] = matrix.columns[1];
			columns[2] = matrix.columns[2];
			columns[3] = { 0,0,0,1 };
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Matrix<4, 4, X>& matrix) noexcept
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

		[[nodiscard]] FORCE_INLINE constexpr col_type& operator[](size_t i)
		{
			assert(i >= 0 || i < columnCount());
			return columns[i];
		}

		[[nodiscard]] FORCE_INLINE constexpr const col_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < columnCount());
			return columns[i];
		}

		template <typename X>
		FORCE_INLINE constexpr type operator+(const Matrix<4, 4, X>& rhs) const noexcept
		{
			return type(columns[0] + rhs.columns[0], columns[1] + rhs.columns[1], columns[2] + rhs.columns[2], columns[3] + rhs.columns[3]);
		}

		template <typename X>
		FORCE_INLINE constexpr type operator-(const Matrix<4, 4, X>& rhs) const noexcept
		{
			return type(columns[0] - rhs.columns[0], columns[1] - rhs.columns[1], columns[2] - rhs.columns[2], columns[3] - rhs.columns[3]);
		}

		[[nodiscard]] FORCE_INLINE type operator*(const Matrix<4, 4, float>& rhs) const noexcept
		{
			Matrix<4, 4, float> Result{ nullptr };

			const M128F* A = reinterpret_cast<const M128F*>(this);
			//const M128F* A = (const M128F*)this->data(); // this is slower
			const M128F* B = reinterpret_cast<const M128F*>(&rhs);
			M128F* R = reinterpret_cast<M128F*>(&Result);
			M128F Temp;// , R0, R1, R2, R3;

			// First row of result (Matrix1[0] * Matrix2).
			Temp = M128F_MUL(M128F_REPLICATE(B[0], 0), A[0]);
			Temp = M128F_MUL_AND_ADD(M128F_REPLICATE(B[0], 1), A[1], Temp);
			Temp = M128F_MUL_AND_ADD(M128F_REPLICATE(B[0], 2), A[2], Temp);
			R[0] = M128F_MUL_AND_ADD(M128F_REPLICATE(B[0], 3), A[3], Temp);

			// Second row of result (Matrix1[1] * Matrix2).
			Temp = M128F_MUL(M128F_REPLICATE(B[1], 0), A[0]);
			Temp = M128F_MUL_AND_ADD(M128F_REPLICATE(B[1], 1), A[1], Temp);
			Temp = M128F_MUL_AND_ADD(M128F_REPLICATE(B[1], 2), A[2], Temp);
			R[1] = M128F_MUL_AND_ADD(M128F_REPLICATE(B[1], 3), A[3], Temp);

			// Third row of result (Matrix1[2] * Matrix2).
			Temp = M128F_MUL(M128F_REPLICATE(B[2], 0), A[0]);
			Temp = M128F_MUL_AND_ADD(M128F_REPLICATE(B[2], 1), A[1], Temp);
			Temp = M128F_MUL_AND_ADD(M128F_REPLICATE(B[2], 2), A[2], Temp);
			R[2] = M128F_MUL_AND_ADD(M128F_REPLICATE(B[2], 3), A[3], Temp);

			// Fourth row of result (Matrix1[3] * Matrix2).
			Temp = M128F_MUL(M128F_REPLICATE(B[3], 0), A[0]);
			Temp = M128F_MUL_AND_ADD(M128F_REPLICATE(B[3], 1), A[1], Temp);
			Temp = M128F_MUL_AND_ADD(M128F_REPLICATE(B[3], 2), A[2], Temp);
			R[3] = M128F_MUL_AND_ADD(M128F_REPLICATE(B[3], 3), A[3], Temp);

			return Result;
		}


		template <typename X>
		[[nodiscard]] FORCE_INLINE constexpr Vector<4, X> operator*(const Vector<4, X>& vector) const noexcept
		{
			return Vector<4, float>
			{
				this->columns[0][0] * vector[0] + this->columns[1][0] * vector[1] + this->columns[2][0] * vector[2] + this->columns[3][0] * vector[3],
					this->columns[0][1] * vector[0] + this->columns[1][1] * vector[1] + this->columns[2][1] * vector[2] + this->columns[3][1] * vector[3],
					this->columns[0][2] * vector[0] + this->columns[1][2] * vector[1] + this->columns[2][2] * vector[2] + this->columns[3][2] * vector[3],
					this->columns[0][3] * vector[0] + this->columns[1][3] * vector[1] + this->columns[2][3] * vector[2] + this->columns[3][3] * vector[3]
			};
		}

		template <>
		[[nodiscard]] FORCE_INLINE Vector<4, float> operator*(const Vector<4, float>& vector) const noexcept
		{
			Vector<4, float> Result{nullptr};

			const M128F* A = (const M128F*)this;
			const M128F* B = (const M128F*)vector.data();
			M128F* R = reinterpret_cast<M128F*>(&Result);

			// First row of result (Matrix1[0] * Matrix2).
			*R = M128F_MUL(M128F_REPLICATE(*B, 0), A[0]);
			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 1), A[1], *R);
			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 2), A[2], *R);
			*R = M128F_MUL_AND_ADD(M128F_REPLICATE(*B, 3), A[3], *R);

			return Result;
		}

		template <typename X>
		[[nodiscard]] FORCE_INLINE constexpr Vector<3, X> operator*(const Vector<3, X>& vector) const noexcept
		{
			return Vector<3, X>
			{
				this->columns[0][0] * vector[0] + this->columns[1][0] * vector[1] + this->columns[2][0] * vector[2],
					this->columns[0][1] * vector[0] + this->columns[1][1] * vector[1] + this->columns[2][1] * vector[2],
					this->columns[0][2] * vector[0] + this->columns[1][2] * vector[1] + this->columns[2][2] * vector[2]
			};
		}	

		/// <summary>
		/// SIMD version is a little faster than scalar version
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
// 		template <>
// 		[[nodiscard]] FORCE_INLINE constexpr Vector<3, float> operator*(const Vector<3, float>& vector) const noexcept
// 		{
// 			return Vector<3, float>
// 			{
// 				this->columns[0][0] * vector[0] + this->columns[1][0] * vector[1] + this->columns[2][0] * vector[2],
// 					this->columns[0][1] * vector[0] + this->columns[1][1] * vector[1] + this->columns[2][1] * vector[2],
// 					this->columns[0][2] * vector[0] + this->columns[1][2] * vector[1] + this->columns[2][2] * vector[2]
// 			};
// 		}

		FORCE_INLINE constexpr type operator+(float rhs) const noexcept
		{
			return type(columns[0] + rhs, columns[1] + rhs, columns[2] + rhs, columns[3] + rhs);
		}

		FORCE_INLINE constexpr type operator-(float rhs) const noexcept
		{
			return type(columns[0] - rhs, columns[1] - rhs, columns[2] - rhs, columns[3] - rhs);
		}

		FORCE_INLINE constexpr type operator*(float rhs) const noexcept
		{
			return type(columns[0] * rhs, columns[1] * rhs, columns[2] * rhs, columns[3] * rhs);
		}

		/*
		template <typename X>
		FORCE_INLINE constexpr type operator/(const Matrix<4, X>& rhs)
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		template <typename X>
		FORCE_INLINE constexpr type operator%(const Matrix<4, X>& rhs)
		{
			return type(x % rhs.x, y % rhs.y, z % rhs.z, w % rhs.w);
		}
		*/

		template <typename X>
		FORCE_INLINE constexpr type& operator+=(const Matrix<4, 4, X>& rhs) noexcept
		{
			columns[0] += rhs.columns[0];
			columns[1] += rhs.columns[1];
			columns[2] += rhs.columns[2];
			columns[3] += rhs.columns[3];
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator-=(const Matrix<4, 4, X>& rhs) noexcept
		{
			columns[0] -= rhs.columns[0];
			columns[1] -= rhs.columns[1];
			columns[2] -= rhs.columns[2];
			columns[3] -= rhs.columns[3];
			return *this;
		}


		template <typename X>
		FORCE_INLINE constexpr type& operator*=(const Matrix<4, 4, X>& rhs) noexcept
		{
			return (*this = *this * rhs);
		}



		/*
		template <typename X>
		FORCE_INLINE constexpr type& operator/=(const Matrix<4, X>& rhs)
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

		FORCE_INLINE constexpr type& operator+=(float scalar) noexcept
		{
			columns[0] += scalar;
			columns[1] += scalar;
			columns[2] += scalar;
			columns[3] += scalar;
			return *this;
		}

		FORCE_INLINE constexpr type& operator-=(float scalar) noexcept
		{
			columns[0] -= scalar;
			columns[1] -= scalar;
			columns[2] -= scalar;
			columns[3] -= scalar;
			return *this;
		}

		FORCE_INLINE constexpr type& operator*=(float scalar) noexcept
		{
			columns[0] *= scalar;
			columns[1] *= scalar;
			columns[2] *= scalar;
			columns[3] *= scalar;
			return *this;
		}

		/*
		template <typename X>
		FORCE_INLINE constexpr type& operator/=(const X& scalar)
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

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(const type& rhs) const noexcept
		{
			return this->columns[0] == rhs.columns[0] && this->columns[1] == rhs.columns[1] && this->columns[2] == rhs.columns[2] && this->columns[3] == rhs.columns[3];
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(const type& rhs) const noexcept
		{
			return this->columns[0] != rhs.columns[0] || this->columns[1] != rhs.columns[1] || this->columns[2] != rhs.columns[2] || this->columns[3] != rhs.columns[3];
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(float number) const noexcept
		{
			return this->columns[0] == number && this->columns[1] == number && this->columns[2] == number && this->columns[3] == number;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(float number) const noexcept
		{
			return this->columns[0] != number || this->columns[1] != number || this->columns[2] != number || this->columns[3] != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator++() noexcept
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
		FORCE_INLINE constexpr type operator++(int) noexcept
		{
			type Matrix{ *this };
			++* this;
			return Matrix;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator--() noexcept
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
		FORCE_INLINE constexpr type operator--(int) noexcept
		{
			type Matrix{ *this };
			--* this;
			return Matrix;
		}

		operator std::basic_string<char>() const noexcept
		{
			return this->toString();
		}
		// TODO : Try make this using SIMD
		inline constexpr type inverse() const noexcept
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
		// TODO : Try make this using SIMD
		inline constexpr type transpose() const noexcept
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

		// TODO : Try make this using SIMD
		template <typename U = float, std::enable_if_t<std::is_signed_v<U>, bool> = true>
		inline constexpr value_type determinant() const noexcept
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


		FORCE_INLINE constexpr auto trace() const noexcept
		{
			return columns[0][0] + columns[1][1] + columns[2][2] + columns[3][3];
		}
	};

	template <>
	FORCE_INLINE constexpr Matrix<4, 4, float> operator+(const Matrix<4, 4, float>& matrix) noexcept
	{
		return matrix;
	}

	template <>
	FORCE_INLINE constexpr Matrix<4, 4, float> operator-(const Matrix<4, 4, float>& matrix) noexcept
	{
		return Matrix<4, 4, float>(
			-matrix.columns[0],
			-matrix.columns[1],
			-matrix.columns[2],
			-matrix.columns[3]);
	}

}

