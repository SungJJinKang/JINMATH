#pragma once
#include "Vector.h"


namespace math
{
	// never put alignas
	template <typename T>
	struct Vector<3, T>
	{
		static_assert(CHECK_IS_NUMBER(T));
		static_assert(CHECK_IS_NOT_CV(T));

		using value_type = typename T;
		using type = typename Vector<3, T>;

		union { T x, r; };
		union { T y, g; };
		union { T z, b; };

		FORCE_INLINE T* data() noexcept
		{
			return &x;
		}

		const FORCE_INLINE T* data() const noexcept
		{
			return &x;
		}

		static const type forward;
		static const type right;
		static const type up;

		FORCE_INLINE constexpr Vector() noexcept : x{}, y{}, z{}
		{

		}

		/// <summary>
		/// for not init
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE Vector(INT32*)  noexcept
		{
		}

		FORCE_INLINE explicit constexpr Vector(T xValue)  noexcept
			: x{ xValue }, y{ xValue }, z{ xValue }
		{
		}

		FORCE_INLINE constexpr Vector(T xValue, T yValue, T zValue) noexcept
			: x{ xValue }, y{ yValue }, z{ zValue }
		{
		}
				
		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<1, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ 0 }, z{ 0 }
		{
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<2, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ 0 }
		{
		}

		FORCE_INLINE Vector(const type& vector) noexcept
		{
			std::memcpy(this, &vector, sizeof(type));
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<3, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ static_cast<T>(vector.z) }
		{
		}

		FORCE_INLINE Vector(const Vector<4, T>& vector) noexcept
		{
			std::memcpy(this, &vector, sizeof(type));
		}

		template <typename X>
		FORCE_INLINE constexpr Vector(const Vector<4, X>& vector) noexcept
			: x{ static_cast<T>(vector.x) }, y{ static_cast<T>(vector.y) }, z{ static_cast<T>(vector.z) }
		{
		}

		FORCE_INLINE constexpr type& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			z = xValue;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<1, X>& vector) noexcept
		{
			x = vector.x;
			y = 0;
			z = 0;
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<2, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = 0;
			return *this;
		}
		
		FORCE_INLINE type& operator=(const type& vector) noexcept
		{
			std::memcpy(this, &vector, sizeof(type));
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<3, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			return *this;
		}

		FORCE_INLINE type& operator=(const Vector<4, T>& vector) noexcept
		{
			std::memcpy(this, &vector, sizeof(type));
			return *this;
		}

		template <typename X>
		FORCE_INLINE constexpr type& operator=(const Vector<4, X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
			return *this;
		}

// 		Vector(const type&) = default;
// 		Vector(type&&) = default;
// 		type& opreator=(const type&) = default;
// 		type& opreator=(type&&) = default;

		std::basic_string<char> toString() const noexcept
		{
			std::stringstream ss;
			ss << x << "  " << y << "  " << z;
			return ss.str();
		}

		[[nodiscard]] FORCE_INLINE static constexpr size_t componentCount() noexcept { return 3; }


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
			default:
				__assume(0);
			}
		}


		[[nodiscard]] FORCE_INLINE constexpr auto sqrMagnitude() const noexcept
		{
			return x * x + y * y + z * z;
		}

		[[nodiscard]] FORCE_INLINE constexpr auto magnitude() const noexcept
		{
			return static_cast<FLOAT32>(math::sqrt(sqrMagnitude()));
		}

		[[nodiscard]] FORCE_INLINE constexpr type normalized() const noexcept
		{
			auto mag = magnitude();
			if (mag == 0)
				return type{};

			return type{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag), static_cast<value_type>(z / mag) };
		}

		FORCE_INLINE constexpr void Normalize()
		{
			auto mag = magnitude();
			if (mag > math::epsilon<T>())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
				z = static_cast<value_type>(z / mag);
			}
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator+(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x + rhs.x, y + rhs.y, z + rhs.z);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator-(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x - rhs.x, y - rhs.y, z - rhs.z);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator*(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x * rhs.x, y * rhs.y, z * rhs.z);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator/(const Vector<RightComponentSize, X>& rhs) const noexcept
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z);
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type operator%(const Vector<RightComponentSize, X>& rhs) const
		{
			return type(MODULO(T, x, rhs.x), MODULO(T, y, rhs.y), MODULO(T, z, rhs.z));
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator+=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator-=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator*=(const Vector<RightComponentSize, X>& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE constexpr type& operator/=(const Vector<RightComponentSize, X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			return *this;
		}

		template <size_t RightComponentSize, typename X>
		FORCE_INLINE type& operator%=(const Vector<RightComponentSize, X>& rhs)
		{
			MODULO(T, x, rhs.x);
			MODULO(T, y, rhs.y);
			MODULO(T, z, rhs.z);
			return *this;
		}

		//

		FORCE_INLINE constexpr type& operator+=(T scalar) noexcept
		{
			x += scalar;
			y += scalar;
			z += scalar;
			return *this;
		}

		FORCE_INLINE constexpr type& operator-=(T scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			return *this;
		}

		FORCE_INLINE constexpr type& operator*=(T scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}

		FORCE_INLINE constexpr type& operator/=(T scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			return *this;
		}

		FORCE_INLINE type& operator%=(T scalar)
		{
			MODULO(T, x, scalar);
			MODULO(T, y, scalar);
			MODULO(T, z, scalar);
			return *this;
		}

		//

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(const type& rhs) const noexcept
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(const type& rhs) const noexcept
		{
			return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator==(T number) const noexcept
		{
			return this->x == number && this->y == number && this->z == number;
		}

		[[nodiscard]] FORCE_INLINE constexpr bool operator!=(T number) const noexcept
		{
			return this->x != number || this->y != number || this->z != number;
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
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE constexpr type operator++(INT32) noexcept
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
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		FORCE_INLINE constexpr type operator--(INT32) noexcept
		{
			type Vector{ *this };
			--* this;
			return Vector;
		}

		operator std::basic_string<char>() const noexcept
		{
			return this->toString();
		}
	};

	template<typename T>
	FORCE_INLINE Vector<3, T> operator+(const Vector<3, T>& vector) noexcept
	{
		return vector;
	}

	template<typename T>
	FORCE_INLINE Vector<3, T> operator-(const Vector<3, T>& vector) noexcept
	{
		return Vector<3, T>(
			-vector.x,
			-vector.y,
			-vector.z);
	}

	// //////////////////////////////////////////////////////

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr auto dot(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<3, T> cross(const Vector<3, T>& lhs, const Vector<3, T>& rhs)
	{
		return Vector<3, T>(
			lhs.y * rhs.z - rhs.y * lhs.z,
			lhs.z * rhs.x - rhs.z * lhs.x,
			lhs.x * rhs.y - rhs.x * lhs.y);
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<3, T> cos(const Vector<3, T>& vector)
	{
		return Vector<3, T>{math::sin(vector.x), math::sin(vector.y), math::sin(vector.z)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<3, T> sin(const Vector<3, T>& vector)
	{
		return Vector<3, T>{math::cos(vector.x), math::cos(vector.y), math::cos(vector.z)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<3, T> tan(const Vector<3, T>& vector)
	{
		return Vector<3, T>{math::tan(vector.x), math::tan(vector.y), math::tan(vector.z)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<3, T> sqrt(const Vector<3, T>& vector)
	{
		return Vector<2, T>{sqrt(vector.x), sqrt(vector.y), sqrt(vector.z)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<3, T> inverseSqrt(const Vector<3, T>& vector)
	{
		return Vector<2, T>{inverseSqrt(vector.x), inverseSqrt(vector.y), inverseSqrt(vector.z)};
	}

	template <typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<3, T> normalize(const Vector<3, T>& vector)
	{
		return vector * inverseSqrt(dot(vector, vector));
	}

	template<typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<3, T> Max(const Vector<3, T>& vector1, const Vector<3, T>& vector2)
	{
		return Vector<3, T>(math::Max(vector1.x, vector2.x), math::Max(vector1.y, vector2.y), math::Max(vector1.z, vector2.z));
	}

	template<typename T>
	[[nodiscard]] FORCE_INLINE constexpr Vector<3, T> Min(const Vector<3, T>& vector1, const Vector<3, T>& vector2)
	{
		return Vector<3, T>(math::Min(vector1.x, vector2.x), math::Min(vector1.y, vector2.y), math::Min(vector1.z, vector2.z));
	}

	// //////////////////////////////////////////////////////

	using Vector3 = Vector<3, FLOAT32>;

	extern template struct math::Vector<3, FLOAT32>;
}