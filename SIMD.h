#pragma once

#define ENABLE_SIMD

#ifdef ENABLE_SIMD

#ifdef __AVX__

#define L_AVX

#include <immintrin.h>



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

//simd function is not markd as SIMD_CONSTEXPR
//so enclosing function decide whether to use SIMD_CONSTEXPR according to whether to support simd
#ifdef L_AVX
#define SIMD_CONSTEXPR 
#else
#define SIMD_CONSTEXPR constexpr
#endif