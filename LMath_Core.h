#pragma once

#include <type_traits>
#include <cmath>
#include <cassert>

#define CHECK_IS_NUMBER(t) std::is_floating_point_v<t> || std::is_integral_v<t>
#define CHECK_IS_NOT_CV(t) !std::is_const_v<t> && !std::is_volatile_v<t>

#define MODULO(typeA, valueA, valueB) static_cast<typeA>(std::fmod(valueA, static_cast<typeA>(valueB)))

#define CLIP_RANGE_ZERO_TO_ONE		(1 << 0) // ZERO_TO_ONE
#define CLIP_RANGE_NEGATIVE_ONE_TO_ONE		(1 << 1) // NEGATIVE_ONE_TO_ONE
#define LEFT_HAND		(1 << 2) // LEFT_HANDED, For DirectX, Metal, Vulkan
#define RIGHT_HAND		(1 << 3) // RIGHT_HANDED, For OpenGL, default in GLM

#define OPEN_GL
//#define DIRECT_X

#ifdef OPEN_GL
#define CURRENT_CLIP_RANGE CLIP_RANGE_NEGATIVE_ONE_TO_ONE
#define CURRENT_COORDINATE_SYSTEM RIGHT_HAND

#elif DIRECT_X
#define CURRENT_CLIP_RANGE CLIP_RANGE_ZERO_TO_ONE
#define CURRENT_COORDINATE_SYSTEM LEFT_HAND
#endif

