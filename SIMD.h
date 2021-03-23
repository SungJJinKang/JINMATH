#pragma once

#ifndef ACTIVATE_SIMD
#define ACTIVATE_SIMD
#endif

#ifdef ACTIVATE_SIMD

#ifdef __AVX__

#ifndef SIMD_ENABLED
#define SIMD_ENABLED
#endif

#ifndef L_AVX
#define L_AVX
#endif


#ifdef SIMD_ENABLED
#include <immintrin.h>

// references :
// https://stackoverflow.com/questions/66743623/what-is-difference-between-m128a-and-m128a?noredirect=1#comment117984269_66743623
// https://stackoverflow.com/questions/52112605/is-reinterpret-casting-between-hardware-simd-vector-pointer-and-the-correspond
// https://stackoverflow.com/questions/6996764/fastest-way-to-do-horizontal-sse-vector-sum-or-other-reduction
// 
//


typedef __m128	XMM128Float;
typedef __m128d XMM128Double;
typedef __m128i XMM128Int;


typedef __m256	XMM256Float;
typedef __m256d XMM256Double;
typedef __m256i XMM256Int;

#ifndef XMM128Float
#define XMM128Float(VECTOR4FLOAT) *(XMM128Float*)(&VECTOR4FLOAT)
#endif

#ifndef XMM128Double
#define XMM128Double(VECTOR4DOUBLE) *(XMM128Float*)(&VECTOR4DOUBLE)
#endif

#ifndef XMM128Int
#define XMM128Int(VECTOR4INT) *(XMM128Float*)(&VECTOR4INT)
#endif

#endif




#endif

#endif

//simd function is not markd as constexpr
//so enclosing function decide whether to use constexpr according to whether to support simd
#ifndef LMATH_CONSTEXPR

#ifdef L_AVX
#define LMATH_CONSTEXPR 
#else
#define LMATH_CONSTEXPR constexpr
#endif

#endif