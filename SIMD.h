#pragma once

#include "JINMATHCore.h"


#if defined(__AVX__) || defined(__AVX2__)

#ifndef SIMD_ENABLED
#define SIMD_ENABLED
#endif

#ifndef L_AVX
#define L_AVX
#endif

#else

#error "Please Enable AVX1 or AVX2 option"

#endif



/*

//simd function is not markd as constexpr
//so enclosing function decide whether to use according to whether to support simd
#ifndef LMATH_CONSTEXPR

#ifdef L_AVX
#define LMATH_
#else
#define LMATH_constexpr
#endif

#endif

*/