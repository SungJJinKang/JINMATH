#pragma once

#include <type_traits>
#include <cmath>
#include <cassert>

#if defined(_MSC_VER)
#  define COMPILER_MSVC
#elif defined(__GNUC__)
#  define COMPILER_GCC
#endif

#if defined(COMPILER_GCC)
#  define FORCE_INLINE inline __attribute__ ((always_inline))
#  define NEVER_INLINE __attribute__ ((noinline))
#  define RESTRICT __restrict
#  define VLA_ARRAY_ON_STACK(type__, varname__, size__) type__ varname__[size__];
#elif defined(COMPILER_MSVC)
#  define FORCE_INLINE __forceinline
#  define NEVER_INLINE __declspec(noinline)
#  define RESTRICT __restrict
#  define VLA_ARRAY_ON_STACK(type__, varname__, size__) type__ *varname__ = (type__*)_alloca(size__ * sizeof(type__))
#endif

#ifndef CHECK_IS_NUMBER
#define CHECK_IS_NUMBER(t) std::is_floating_point_v<t> || std::is_integral_v<t>
#endif

#ifndef CHECK_IS_NOT_CV
#define CHECK_IS_NOT_CV(t) !std::is_const_v<t> && !std::is_volatile_v<t>
#endif

#ifndef MODULO
#define MODULO(typeA, valueA, valueB) static_cast<typeA>(std::fmod(valueA, static_cast<typeA>(valueB)))
#endif

#ifndef CLIP_RANGE_ZERO_TO_ONE
#define CLIP_RANGE_ZERO_TO_ONE		(1 << 0) // ZERO_TO_ONE
#endif
#ifndef CLIP_RANGE_NEGATIVE_ONE_TO_ONE
#define CLIP_RANGE_NEGATIVE_ONE_TO_ONE		(1 << 1) // NEGATIVE_ONE_TO_ONE
#endif
#ifndef LEFT_HAND
#define LEFT_HAND		(1 << 2) // LEFT_HANDED, For DirectX, Metal, Vulkan
#endif
#ifndef RIGHT_HAND
#define RIGHT_HAND		(1 << 3) // RIGHT_HANDED, For OpenGL, default in GLM
#endif

#ifndef LEFT_HAND_ZERO_TO_ONE
#define LEFT_HAND_ZERO_TO_ONE (LEFT_HAND | CLIP_RANGE_ZERO_TO_ONE)
#endif

#ifndef LEFT_HAND_NEGATIVE_ONE_TO_ONE
#define LEFT_HAND_NEGATIVE_ONE_TO_ONE (LEFT_HAND | CLIP_RANGE_NEGATIVE_ONE_TO_ONE)
#endif

#ifndef RIGHT_HAND_ZERO_TO_ONE
#define RIGHT_HAND_ZERO_TO_ONE (RIGHT_HAND | CLIP_RANGE_ZERO_TO_ONE)
#endif

#ifndef RIGHT_HAND_NEGATIVE_ONE_TO_ONE
#define RIGHT_HAND_NEGATIVE_ONE_TO_ONE (RIGHT_HAND | CLIP_RANGE_NEGATIVE_ONE_TO_ONE)
#endif

#ifndef OPEN_GL
#define OPEN_GL
#endif
//#define DIRECT_X

#ifdef OPEN_GL
#ifndef CURRENT_CLIP_RANGE
#define CURRENT_CLIP_RANGE CLIP_RANGE_NEGATIVE_ONE_TO_ONE
#endif
#ifndef CURRENT_COORDINATE_SYSTEM
#define CURRENT_COORDINATE_SYSTEM RIGHT_HAND
#endif
#ifndef CURRENT_SETTING
#define CURRENT_SETTING RIGHT_HAND_NEGATIVE_ONE_TO_ONE
#endif
#elif DIRECT_X
#ifndef CURRENT_CLIP_RANGE
#define CURRENT_CLIP_RANGE CLIP_RANGE_ZERO_TO_ONE
#endif
#ifndef CURRENT_COORDINATE_SYSTEM
#define CURRENT_COORDINATE_SYSTEM LEFT_HAND
#endif
#ifndef CURRENT_SETTING
#define CURRENT_SETTING LEFT_HAND_ZERO_TO_ONE
#endif
#endif


