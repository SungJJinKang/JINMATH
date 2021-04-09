namespace math
{

	/// <summary>
	/// This class is made for SIMD computation. So it's aligned to 16 byte
	/// </summary>
	template <>
	struct alignas(16) Vector<4, float>
	{
		using value_type = typename float;
		using type = typename Vector<4, float>;

		union { float x, r; };
		union { float y, g; };
		union { float z, b; };
		union { float w, a; };

		FORCE_INLINE float* data() noexcept
		{
			return &x;
		}

		const FORCE_INLINE float* data() const noexcept
		{
			return &x;
		}

		static const type forward;
		static const type right;
		static const type up;


		FORCE_INLINE constexpr Vector() noexcept : x{ }, y{ }, z{ }, w{ }
		{

		}

		/// <summary>
		/// for Not Init
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE Vector(int*) noexcept 
		{

		}

 		FORCE_INLINE explicit constexpr Vector(float xValue)  noexcept
 			: x{ xValue }, y{ xValue }, z{ xValue }, w{ xValue }
 		{
 		}

		// This is more slow than scalar version
// 		FORCE_INLINE Vector(float xValue)  noexcept
// 		{
// 			*reinterpret_cast<M128F*>(this) = _mm_set1_ps(xValue);
// 		}
		
		FORCE_INLINE constexpr Vector(float xValue, float yValue, float zValue, float wValue) noexcept
			: x{ xValue }, y{ yValue }, z{ zValue }, w{ wValue }
		{
		}
		
		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<1, X>& vector) noexcept
			: x{ static_cast<float>(vector.x) }, y{ 0 }, z{ 0 }, w{ 0 }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<2, X>& vector) noexcept
			: x{ static_cast<float>(vector.x) }, y{ static_cast<float>(vector.y) }, z{ 0 }, w{ 0 }
		{
		}

		/// <summary>
		/// When passed parameter have same value type
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
		FORCE_INLINE Vector(const Vector<3, float>& vector, float w = 0.0f) noexcept
		{
			//this is faster than x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ vector.w }
			std::memcpy(this, &vector, sizeof(float) * 3);
			this->w = w;
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<3, X>& vector, X w = 0) noexcept
			: x{ static_cast<float>(vector.x) }, y{ static_cast<float>(vector.y) }, z{ static_cast<float>(vector.z) }, w{ static_cast<float>(w) }
		{
		}

		FORCE_INLINE Vector(const type& vector) noexcept
		{
			//this is faster than x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ vector.w }
			std::memcpy(this, &vector, sizeof(type));
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<4, X>& vector) noexcept
			: x{ static_cast<float>(vector.x) }, y{ static_cast<float>(vector.y) }, z{ static_cast<float>(vector.z) }, w{ static_cast<float>(vector.w) }
		{
		}

		FORCE_INLINE constexpr type& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			z = xValue;
			w = xValue;
			return *this;
		}
		
		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			y = 0;
			z = 0;
			w = 0;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = 0;
			w = 0;
			return *this;
		}

		FORCE_INLINE type& operator=(const Vector<3, float>& vector) noexcept
		{
			std::memcpy(this, &vector, sizeof(float) * 3); 
			this->w = 0;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			w = 0;
			return *this;
		}

		/// <summary>
		/// when type T is same with parameter's value type
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
		FORCE_INLINE type& operator=(const type& vector) noexcept
		{
			// 			x = vector.x;
			// 			y = vector.y;
			// 			z = vector.z;
			// 			w = vector.w;
			std::memcpy(this, &vector, sizeof(type));
			return *this;
		}

		/// <summary>
		/// when type T is different with parameter's value type
		/// </summary>
		/// <typeparam name="X"></typeparam>
		/// <param name="vector"></param>
		/// <returns></returns>
		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<4, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			w = vector.w;
			return *this;
		}

		// 		Vector(const type&) = default;
		// 		Vector(type&&) = default;
		// 		type& opreator=(const type&) = default;
		// 		type& opreator=(type&&) = default;

		std::basic_string<char> toString() const noexcept
		{
			std::stringstream ss;
			ss << x << "  " << y << "  " << z << "  " << w;
			return ss.str();
		}

		[[nodiscard]] FORCE_INLINE static constexpr size_t componentCount() noexcept { return 4; }

		[[nodiscard]] FORCE_INLINE constexpr value_type& operator[](size_t i)
		{
			assert(i >= 0 || i < componentCount());
			switch (i)
			{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			case 3:
				return w;
				break;
			default:
				__assume(0);
			}
		}

		[[nodiscard]] FORCE_INLINE constexpr const value_type& operator[](size_t i) const
		{
			assert(i >= 0 || i < componentCount());
			switch (i)
			{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			case 3:
				return w;
				break;
			default:
				__assume(0);
			}
		}


		// scalar version is more fast than SIMD
		[[nodiscard]] FORCE_INLINE constexpr auto sqrMagnitude() const noexcept
		{
			return x * x + y * y + z * z + w * w;
		}

		// scalar version is more fast than SIMD
		[[nodiscard]] FORCE_INLINE constexpr auto magnitude() const noexcept
		{
			return math::sqrt(sqrMagnitude());
		}

		[[nodiscard]] FORCE_INLINE constexpr type normalized() const noexcept
		{
			auto mag = magnitude();
			if (mag == 0)
				return type{};

			return type{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag), static_cast<value_type>(z / mag), static_cast<value_type>(w / mag) };
		}

		FORCE_INLINE constexpr void Normalize()
		{
			auto mag = magnitude();
			if (mag > math::epsilon<float>())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
				z = static_cast<value_type>(z / mag);
				w = static_cast<value_type>(w / mag);
			}
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
		FORCE_INLINE constexpr type operator+(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
		FORCE_INLINE constexpr type operator-(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
		FORCE_INLINE constexpr type operator*(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
		FORCE_INLINE constexpr type operator/(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
		FORCE_INLINE constexpr type operator%(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(MODULO(float, x, rhs.x), MODULO(float, y, rhs.y), MODULO(float, z, rhs.z), MODULO(float, w, rhs.w));
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
		FORCE_INLINE constexpr type& operator+=(const Vector<RightComponentSize, X>& rhs)  const
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
		FORCE_INLINE constexpr type& operator-=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
		FORCE_INLINE constexpr type& operator*=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			w *= rhs.w;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
		FORCE_INLINE constexpr type& operator/=(const Vector<RightComponentSize, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		template <size_t RightComponentSize, typename X, typename std::enable_if_t<RightComponentSize >= 4, bool> = true>
		FORCE_INLINE constexpr type& operator%=(const Vector<RightComponentSize, X>& rhs)
		{
			MODULO(float, x, rhs.x);
			MODULO(float, y, rhs.y);
			MODULO(float, z, rhs.z);
			MODULO(float, w, rhs.w);
			return *this;
		}

		//

		FORCE_INLINE constexpr type& operator+=(float scalar) noexcept
		{
			x += scalar;
			y += scalar;
			z += scalar;
			w += scalar;
			return *this;
		}

		FORCE_INLINE constexpr type& operator-=(float scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			w -= scalar;
			return *this;
		}

		FORCE_INLINE constexpr type& operator*=(float scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return *this;
		}

		FORCE_INLINE constexpr type& operator/=(float scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}

		FORCE_INLINE type& operator%=(float scalar)
		{
			MODULO(float, x, scalar);
			MODULO(float, y, scalar);
			MODULO(float, z, scalar);
			MODULO(float, w, scalar);
			return *this;
		}

		//

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(const type& rhs) const noexcept
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(const type& rhs) const noexcept
		{
			return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z || this->w != rhs.w;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(float number) const noexcept
		{
			return this->x == number && this->y == number && this->z == number && this->w == number;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(float number) const noexcept
		{
			return this->x != number || this->y != number || this->z != number || this->w != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator++() noexcept
		{
			++x;
			++y;
			++z;
			++w;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE type operator++(int) noexcept
		{
			type Vector{ *this };
			++* this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE constexpr type& operator--() noexcept
		{
			--x;
			--y;
			--z;
			--w;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE type operator--(int) noexcept
		{
			type Vector{ *this };
			--* this;
			return type{ Vector };
		}

		operator std::basic_string<char>() const noexcept
		{
			return this->toString();
		}


	};

	template<>
	FORCE_INLINE Vector<4, float> operator+(const Vector<4, float>& vector) noexcept
	{
		return vector;
	}

	template<>
	FORCE_INLINE Vector<4, float> operator-(const Vector<4, float>& vector) noexcept
	{
		return Vector<4, float>
			(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w
			);
	}

	// //////////////////////

	/// <summary>
	/// maybe scalar version more fast than SIMDD
	/// </summary>
	template <>
	[[nodiscard]] FORCE_INLINE constexpr auto dot(const Vector<4, float>& lhs, const Vector<4, float>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	// AX1 don't have cos instriction
	template <>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, float> cos(const Vector<4, float>& vector)
	{
		return Vector<4, float>{math::sin(vector.x), math::sin(vector.y), math::sin(vector.z), math::sin(vector.w)};
	}

	// AX1 don't have sin instriction
	template <>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, float> sin(const Vector<4, float>& vector)
	{
		return Vector<4, float>{math::cos(vector.x), math::cos(vector.y), math::cos(vector.z), math::cos(vector.w)};
	}

	// AX1 don't have tan instriction
	template <>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, float> tan(const Vector<4, float>& vector)
	{
		return Vector<4, float>{math::tan(vector.x), math::tan(vector.y), math::tan(vector.z), math::tan(vector.w)};
	}

	template <>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, float> sqrt(const Vector<4, float>& vector)
	{
		M128F Temp = _mm_sqrt_ps(*reinterpret_cast<const M128F*>(&vector));
		return Vector<4, float>{*reinterpret_cast<Vector<4, float>*>(&Temp)};
	}

	template <>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, float> inverseSqrt(const Vector<4, float>& vector)
	{
		M128F Temp = _mm_rsqrt_ps(*reinterpret_cast<const M128F*>(&vector));
		return Vector<4, float>{*reinterpret_cast<Vector<4, float>*>(&Temp)};
	}

	template <>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, float> normalize(const Vector<4, float>& vector)
	{
		return vector * math::inverseSqrt(math::dot(vector, vector));
	}

	template<>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, float> Max(const Vector<4, float>& vector1, const Vector<4, float>& vector2)
	{
		return Vector<4, float>(math::Max(vector1.x, vector2.x), math::Max(vector1.y, vector2.y), math::Max(vector1.z, vector2.z), math::Max(vector1.w, vector2.w));
	}

	template<>
	[[nodiscard]] FORCE_INLINE constexpr Vector<4, float> Min(const Vector<4, float>& vector1, const Vector<4, float>& vector2)
	{
		return Vector<4, float>(math::Min(vector1.x, vector2.x), math::Min(vector1.y, vector2.y), math::Min(vector1.z, vector2.z), math::Min(vector1.w, vector2.w));
	}
}


