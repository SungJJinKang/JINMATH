#pragma once

#include <type_traits>
#include <cmath>
#include <cassert>


#if defined(__GNUC__)  || defined( __clang__)

#  define JINMATH_FORCE_INLINE inline __attribute__ ((always_inline))
#  define JINMATH_NEVER_INLINE __attribute__ ((noinline))
#  define JINMATH_RESTRICT __JINMATH_RESTRICT
#  define JINMATH_VLA_ARRAY_ON_STACK(type__, varname__, size__) type__ varname__[size__];
#  define JINMATH_NO_DISCARD __attribute__((warn_unused_result))

#elif defined(_MSC_VER)

#  define JINMATH_FORCE_INLINE __forceinline
#  define JINMATH_NEVER_INLINE __declspec(noinline)
#  define JINMATH_RESTRICT __JINMATH_RESTRICT
#  define JINMATH_VLA_ARRAY_ON_STACK(type__, varname__, size__) type__ *varname__ = (type__*)_alloca(size__ * sizeof(type__))
#  define JINMATH_NO_DISCARD [[nodiscard]]

#else

#error Unsupported compiler. Please use MSVC or clang

#endif

#undef JINMATH_NEVER_HAPPEN

#if defined(_DEBUG)
#define JINMATH_NEVER_HAPPEN assert(false)
#elif (!defined(_DEBUG)) && defined(_MSC_VER)
#define JINMATH_NEVER_HAPPEN __assume(0)
#elif (!defined(_DEBUG)) && defined(__clang__)
#define JINMATH_NEVER_HAPPEN __builtin_unreachable()
#else
#error Unsupported compiler ( Please Use msvc or clang )
#endif



#ifndef JINMATH_CHECK_IS_NUMBER
#define JINMATH_CHECK_IS_NUMBER(t) std::is_floating_point_v<t> || std::is_integral_v<t>
#endif

#ifndef JINMATH_CHECK_IS_NOT_CV
#define JINMATH_CHECK_IS_NOT_CV(t) !std::is_const_v<t> && !std::is_volatile_v<t>
#endif

#ifndef JINMATH_MODULO
#define JINMATH_MODULO(typeA, valueA, valueB) static_cast<typeA>(std::fmod(valueA, static_cast<typeA>(valueB)))
#endif

#ifndef JINMATH_CLIP_RANGE_ZERO_TO_ONE
#define JINMATH_CLIP_RANGE_ZERO_TO_ONE		(1 << 0) // ZERO_TO_ONE
#endif
#ifndef JINMATH_CLIP_RANGE_NEGATIVE_ONE_TO_ONE
#define JINMATH_CLIP_RANGE_NEGATIVE_ONE_TO_ONE		(1 << 1) // NEGATIVE_ONE_TO_ONE
#endif
#ifndef JINMATH_LEFT_HAND
#define JINMATH_LEFT_HAND		(1 << 2) // LEFT_HANDED, For DirectX, Metal, Vulkan
#endif
#ifndef JINMATH_RIGHT_HAND
#define JINMATH_RIGHT_HAND		(1 << 3) // RIGHT_HANDED, For OpenGL, default in GLM
#endif

#ifndef JINMATH_LEFT_HAND_ZERO_TO_ONE
#define JINMATH_LEFT_HAND_ZERO_TO_ONE (JINMATH_LEFT_HAND | JINMATH_CLIP_RANGE_ZERO_TO_ONE)
#endif

#ifndef JINMATH_LEFT_HAND_NEGATIVE_ONE_TO_ONE
#define JINMATH_LEFT_HAND_NEGATIVE_ONE_TO_ONE (JINMATH_LEFT_HAND | JINMATH_CLIP_RANGE_NEGATIVE_ONE_TO_ONE)
#endif

#ifndef JINMATH_RIGHT_HAND_ZERO_TO_ONE
#define JINMATH_RIGHT_HAND_ZERO_TO_ONE (JINMATH_RIGHT_HAND | JINMATH_CLIP_RANGE_ZERO_TO_ONE)
#endif

#ifndef JINMATH_RIGHT_HAND_NEGATIVE_ONE_TO_ONE
#define JINMATH_RIGHT_HAND_NEGATIVE_ONE_TO_ONE (JINMATH_RIGHT_HAND | JINMATH_CLIP_RANGE_NEGATIVE_ONE_TO_ONE)
#endif

#ifndef JINMATH_OPEN_GL
#define JINMATH_OPEN_GL
#endif
//#define DIRECT_X

#if defined(JINMATH_OPEN_GL)
#ifndef JINMATH_CURRENT_CLIP_RANGE
#define JINMATH_CURRENT_CLIP_RANGE JINMATH_CLIP_RANGE_NEGATIVE_ONE_TO_ONE
#endif
#ifndef JINMATH_CURRENT_COORDINATE_SYSTEM
#define JINMATH_CURRENT_COORDINATE_SYSTEM JINMATH_RIGHT_HAND
#endif
#ifndef JINMATH_CURRENT_SETTING
#define JINMATH_CURRENT_SETTING JINMATH_RIGHT_HAND_NEGATIVE_ONE_TO_ONE
#endif
#elif defined(DIRECT_X)
#ifndef JINMATH_CURRENT_CLIP_RANGE
#define JINMATH_CURRENT_CLIP_RANGE JINMATH_CLIP_RANGE_ZERO_TO_ONE
#endif
#ifndef JINMATH_CURRENT_COORDINATE_SYSTEM
#define JINMATH_CURRENT_COORDINATE_SYSTEM JINMATH_LEFT_HAND
#endif
#ifndef JINMATH_CURRENT_SETTING
#define JINMATH_CURRENT_SETTING JINMATH_LEFT_HAND_ZERO_TO_ONE
#endif
#endif

#include "TypeDef.h"
#include "Reflection/Reflection.h"

D_NAMESPACE(math)
namespace math
{
	struct Matrix2x2;
	struct Matrix3x3;
	struct Matrix4x4;

	struct Vector2;
	struct Vector3;
	struct Vector4;

	struct Quaternion;
}
