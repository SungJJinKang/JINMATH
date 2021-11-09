#include <TypeDef.h>
#include "CompilerMacros.h"

#include "SIMD_Core.h"
#include "Vector3.h"

namespace math
{
	template <size_t ComponentCount, typename T>
	struct Vector;
	/// <summary>
	/// This class is made for SIMD computation. So it's aligned to 16 byte
	/// </summary>

	template <>
	struct alignas(16) _Vector4<FLOAT32>
	{
		using value_type = typename FLOAT32;
		using type = typename _Vector4<FLOAT32>;

		union { FLOAT32 x, r; };
		union { FLOAT32 y, g; };
		union { FLOAT32 z, b; };
		union { FLOAT32 w, a; };

		FORCE_INLINE FLOAT32* data() noexcept
		{
			return &x;
		}

		const FORCE_INLINE FLOAT32* data() const noexcept
		{
			return &x;
		}

		static const type forward;
		static const type right;
		static const type up;
		static const type zero;
		static const type one;

		FORCE_INLINE _Vector4() noexcept : x{ }, y{ }, z{ }, w{ }
		{

		}


 		FORCE_INLINE explicit _Vector4(FLOAT32 xValue)  noexcept
 			: x{ xValue }, y{ xValue }, z{ xValue }, w{ xValue }
 		{
 		}

		// This is more slow than scalar version
// 		FORCE_INLINE Vector(FLOAT32 xValue)  noexcept
// 		{
// 			*reinterpret_cast<M128F*>(this) = _mm_set1_ps(xValue);
// 		}
		
		FORCE_INLINE _Vector4(FLOAT32 xValue, FLOAT32 yValue, FLOAT32 zValue, FLOAT32 wValue) noexcept
			: x{ xValue }, y{ yValue }, z{ zValue }, w{ wValue }
		{
		}
		
		template <typename X>
		FORCE_INLINE _Vector4(const _Vector2<X>& vector) noexcept
			: x{ static_cast<FLOAT32>(vector.x) }, y{ static_cast<FLOAT32>(vector.y) }, z{ 0 }, w{ 0 }
		{
		}

		/// <summary>
		/// When passed parameter have same value type
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
		FORCE_INLINE _Vector4(const _Vector3<FLOAT32>& vector, const FLOAT32 _w = 0.0f) noexcept
			: x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ _w }
		{
		}

		template <typename X>
		FORCE_INLINE _Vector4(const _Vector3<X>& vector, X w = 0) noexcept
			: x{ static_cast<FLOAT32>(vector.x) }, y{ static_cast<FLOAT32>(vector.y) }, z{ static_cast<FLOAT32>(vector.z) }, w{ static_cast<FLOAT32>(w) }
		{
		}

		FORCE_INLINE _Vector4(const type& vector) noexcept
			: x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ vector.w }
		{
		}

		template <typename X>
		FORCE_INLINE _Vector4(const _Vector4<X>& vector) noexcept
			: x{ static_cast<FLOAT32>(vector.x) }, y{ static_cast<FLOAT32>(vector.y) }, z{ static_cast<FLOAT32>(vector.z) }, w{ static_cast<FLOAT32>(vector.w) }
		{
		}

		FORCE_INLINE _Vector4(const M128F& m128f) noexcept
			: x{ m128f.m128_f32[0] }, y{ m128f.m128_f32[1] }, z{ m128f.m128_f32[2] }, w{ m128f.m128_f32[3] }
		{
		}

		FORCE_INLINE type& operator=(value_type xValue) noexcept
		{
			x = xValue;
			y = xValue;
			z = xValue;
			w = xValue;
			return *this;
		}
		
		template <typename X>
		FORCE_INLINE type& operator=(const _Vector2<X>& vector) noexcept
		{
			x = vector.x;
			y = vector.y;
			z = 0;
			w = 0;
			return *this;
		}

		FORCE_INLINE type& operator=(const _Vector3<FLOAT32>& vector) noexcept
		{
			std::memcpy(this, &vector, sizeof(FLOAT32) * 3); 
			this->w = 0;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator=(const _Vector3<X>& vector) noexcept
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

		/*
		FORCE_INLINE type& operator=(const M128F& m128f) noexcept
		{
			//this is faster than x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ vector.w }
			std::memcpy(this, &m128f, sizeof(type));
			return *this;
		}
		*/

		/// <summary>
		/// when type T is different with parameter's value type
		/// </summary>
		/// <typeparam name="X"></typeparam>
		/// <param name="vector"></param>
		/// <returns></returns>
		template <typename X>
		FORCE_INLINE type& operator=(const _Vector4<X>& vector) noexcept
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

		NO_DISCARD FORCE_INLINE static size_t componentCount() noexcept { return 4; }

		NO_DISCARD FORCE_INLINE value_type& operator[](size_t i)
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

		NO_DISCARD FORCE_INLINE const value_type& operator[](size_t i) const
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
		NO_DISCARD FORCE_INLINE auto sqrMagnitude() const noexcept
		{
			return x * x + y * y + z * z + w * w;
		}

		// scalar version is more fast than SIMD
		NO_DISCARD FORCE_INLINE auto magnitude() const noexcept
		{
			return math::sqrt(sqrMagnitude());
		}

		NO_DISCARD FORCE_INLINE type normalized() const noexcept
		{
			auto mag = magnitude();
			if (mag == 0)
				return type{};

			return type{ static_cast<value_type>(x / mag), static_cast<value_type>(y / mag), static_cast<value_type>(z / mag), static_cast<value_type>(w / mag) };
		}

		FORCE_INLINE void Normalize()
		{
			auto mag = magnitude();
			if (mag > math::epsilon<FLOAT32>())
			{
				x = static_cast<value_type>(x / mag);
				y = static_cast<value_type>(y / mag);
				z = static_cast<value_type>(z / mag);
				w = static_cast<value_type>(w / mag);
			}
		}

		/// <summary>
		/// scalar version is much faster than SIMD version
		/// </summary>
		/// <typeparam name="X"></typeparam>
		/// <typeparam name="enable_if_t"></typeparam>
		/// <param name="rhs"></param>
		/// <returns></returns>
		template <typename X>
		FORCE_INLINE type operator+(const _Vector4<X>& rhs) const noexcept
		{
			return type(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		}

		/*
		
		FORCE_INLINE type operator+(const _Vector4<FLOAT32>& rhs) const noexcept
		{
			return type(M128F_ADD(*reinterpret_cast<const M128F*>(this), *reinterpret_cast<const M128F*>(&rhs)));
		}
		*/

		template <typename X>
		FORCE_INLINE type operator-(const _Vector4<X>& rhs) const noexcept
		{
			return type(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
		}

		template <typename X>
		FORCE_INLINE type operator*(const _Vector4<X>& rhs) const noexcept
		{
			return type(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
		}

		template <typename X>
		FORCE_INLINE type operator/(const _Vector4<X>& rhs) const noexcept
		{
			return type(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		template <typename X>
		FORCE_INLINE type operator%(const _Vector4<X>& rhs) const noexcept
		{
			return type(MODULO(FLOAT32, x, rhs.x), MODULO(FLOAT32, y, rhs.y), MODULO(FLOAT32, z, rhs.z), MODULO(FLOAT32, w, rhs.w));
		}

		template <typename X>
		FORCE_INLINE type& operator+=(const _Vector4<X>& rhs) noexcept
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator-=(const _Vector4<X>& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator*=(const _Vector4<X>& rhs) noexcept
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			w *= rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator/=(const _Vector4<X>& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		template <typename X>
		FORCE_INLINE type& operator%=(const _Vector4<X>& rhs)
		{
			MODULO(FLOAT32, x, rhs.x);
			MODULO(FLOAT32, y, rhs.y);
			MODULO(FLOAT32, z, rhs.z);
			MODULO(FLOAT32, w, rhs.w);
			return *this;
		}

		//

		FORCE_INLINE type& operator+=(FLOAT32 scalar) noexcept
		{
			x += scalar;
			y += scalar;
			z += scalar;
			w += scalar;
			return *this;
		}

		FORCE_INLINE type& operator-=(FLOAT32 scalar) noexcept
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;
			w -= scalar;
			return *this;
		}

		FORCE_INLINE type& operator*=(FLOAT32 scalar) noexcept
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return *this;
		}

		FORCE_INLINE type& operator/=(FLOAT32 scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}

		FORCE_INLINE type& operator%=(FLOAT32 scalar)
		{
			MODULO(FLOAT32, x, scalar);
			MODULO(FLOAT32, y, scalar);
			MODULO(FLOAT32, z, scalar);
			MODULO(FLOAT32, w, scalar);
			return *this;
		}

		//

		NO_DISCARD FORCE_INLINE bool operator==(const type& rhs) const noexcept
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w;
		}

		NO_DISCARD FORCE_INLINE bool operator!=(const type& rhs) const noexcept
		{
			return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z || this->w != rhs.w;
		}

		NO_DISCARD FORCE_INLINE bool operator==(FLOAT32 number) const noexcept
		{
			return this->x == number && this->y == number && this->z == number && this->w == number;
		}

		NO_DISCARD FORCE_INLINE bool operator!=(FLOAT32 number) const noexcept
		{
			return this->x != number || this->y != number || this->z != number || this->w != number;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator++() noexcept
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
		FORCE_INLINE type operator++(INT32) noexcept
		{
			type Vector{ *this };
			++* this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		FORCE_INLINE type& operator--() noexcept
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
		FORCE_INLINE type operator--(INT32) noexcept
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

	
	FORCE_INLINE _Vector4<FLOAT32> operator+(const _Vector4<FLOAT32>& vector) noexcept
	{
		return vector;
	}

	
	FORCE_INLINE _Vector4<FLOAT32> operator-(const _Vector4<FLOAT32>& vector) noexcept
	{
		return _Vector4<FLOAT32>
			(
			-vector.x,
			-vector.y,
			-vector.z,
			-vector.w
			);
	}

	// //////////////////////

	
	
	/// <summary>
	/// scalar version is mush fast than SIMD version
	/// </summary>
	
	NO_DISCARD FORCE_INLINE auto dot(const _Vector4<FLOAT32>& lhs, const _Vector4<FLOAT32>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	// AX1 don't have cos instriction
	
	NO_DISCARD FORCE_INLINE _Vector4<FLOAT32> cos(const _Vector4<FLOAT32>& vector)
	{
		return _Vector4<FLOAT32>{math::sin(vector.x), math::sin(vector.y), math::sin(vector.z), math::sin(vector.w)};
	}

	// AX1 don't have sin instriction
	
	NO_DISCARD FORCE_INLINE _Vector4<FLOAT32> sin(const _Vector4<FLOAT32>& vector)
	{
		return _Vector4<FLOAT32>{math::cos(vector.x), math::cos(vector.y), math::cos(vector.z), math::cos(vector.w)};
	}

	// AX1 don't have tan instriction
	
	NO_DISCARD FORCE_INLINE _Vector4<FLOAT32> tan(const _Vector4<FLOAT32>& vector)
	{
		return _Vector4<FLOAT32>{math::tan(vector.x), math::tan(vector.y), math::tan(vector.z), math::tan(vector.w)};
	}

	
	NO_DISCARD FORCE_INLINE _Vector4<FLOAT32> sqrt(const _Vector4<FLOAT32>& vector)
	{
		const M128F* m128f_vec = reinterpret_cast<const M128F*>(&vector);
		return _Vector4<FLOAT32>{_mm_sqrt_ps(*m128f_vec)};
	}

	
	NO_DISCARD FORCE_INLINE _Vector4<FLOAT32> inverseSqrt(const _Vector4<FLOAT32>& vector)
	{
		const M128F* m128f_vec = reinterpret_cast<const M128F*>(&vector);
		return _Vector4<FLOAT32>{_mm_rsqrt_ps(*m128f_vec)};
	}

	
	NO_DISCARD FORCE_INLINE _Vector4<FLOAT32> normalize(const _Vector4<FLOAT32>& vector)
	{
		return vector * math::inverseSqrt(math::dot(vector, vector));
	}

	
	NO_DISCARD FORCE_INLINE _Vector4<FLOAT32> Max(const _Vector4<FLOAT32>& vector1, const _Vector4<FLOAT32>& vector2)
	{
		const M128F* m128f_vec1 = reinterpret_cast<const M128F*>(&vector1);
		const M128F* m128f_vec2 = reinterpret_cast<const M128F*>(&vector2);

		return _Vector4<FLOAT32>(_mm_max_ps(*m128f_vec1, *m128f_vec2));
	}

	
	NO_DISCARD FORCE_INLINE _Vector4<FLOAT32> Min(const _Vector4<FLOAT32>& vector1, const _Vector4<FLOAT32>& vector2)
	{
		const M128F* m128f_vec1 = reinterpret_cast<const M128F*>(&vector1);
		const M128F* m128f_vec2 = reinterpret_cast<const M128F*>(&vector2);
		
		return _Vector4<FLOAT32>(_mm_min_ps(*m128f_vec1, *m128f_vec2));
	}
}


