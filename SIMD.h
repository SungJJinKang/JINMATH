#pragma once

#define ENABLE_SIMD

#ifdef ENABLE_SIMD

#ifdef __AVX__

#define L_AVX

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


#define XMM128Float(VECTOR4FLOAT) *(XMM128Float*)(&VECTOR4FLOAT)
#define XMM128Double(VECTOR4DOUBLE) *(XMM128Float*)(&VECTOR4DOUBLE)
#define XMM128Int(VECTOR4INT) *(XMM128Float*)(&VECTOR4INT)



#endif




#endif

//simd function is not markd as constexpr
//so enclosing function decide whether to use constexpr according to whether to support simd
#ifdef L_AVX
#define LMATH_CONSTEXPR 
#else
#define LMATH_CONSTEXPR constexpr
#endif