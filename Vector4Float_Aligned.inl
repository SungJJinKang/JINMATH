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

		FORCE_INLINE constexpr explicit Vector(float xValue)  noexcept
			: x{ xValue }, y{ xValue }, z{ xValue }, w{ xValue }
		{
		}

		FORCE_INLINE constexpr Vector(float xValue, float yValue, float zValue, float wValue) noexcept
			: x{ xValue }, y{ yValue }, z{ zValue }, w{ wValue }
		{
		}

		FORCE_INLINE constexpr explicit Vector(const type& vector) noexcept
			: x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ vector.w }
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

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<3, X>& vector) noexcept
			: x{ static_cast<float>(vector.x) }, y{ static_cast<float>(vector.y) }, z{ static_cast<float>(vector.z) }, w{ 0 }
		{
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

		FORCE_INLINE constexpr type& operator=(const type& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			w = vector.w;
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

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			w = 0;
			return *this;
		}

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

		[[nodiscard]] inline static constexpr size_t componentCount() noexcept { return 4; }

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



		[[nodiscard]] FORCE_INLINE constexpr auto sqrMagnitude() const noexcept
		{
			return x * x + y * y + z * z + w * w;
		}

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

		template <typename X>
		FORCE_INLINE constexpr type& operator+=(const X& scalar) noexcept
		{
			x += scalar;
			y += scalar;
			z += scalar;
			w += scalar;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator-=(const X& scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			w -= scalar;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator*=(const X& scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator/=(const X& scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator%=(const X& scalar)
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

		template <typename X>
		[[nodiscard]] FORCE_INLINE constexpr bool operator==(const X& number) const noexcept
		{
			return this->x == number && this->y == number && this->z == number && this->w == number;
		}

		template <typename X>
		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(const X& number) const noexcept
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
		FORCE_INLINE constexpr type operator++(int) noexcept
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
		FORCE_INLINE constexpr type operator--(int) noexcept
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
	FORCE_INLINE constexpr Vector<4, float> operator+(const Vector<4, float>& vector) noexcept
	{
		return vector;
	}

	template<>
	FORCE_INLINE constexpr Vector<4, float> operator-(const Vector<4, float>& vector) noexcept
	{
		return Vector<4, float>(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w);
	}
}


