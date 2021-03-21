#pragma once

//#define ENABLE_SIMD

#ifdef ENABLE_SIMD

#include <immintrin.h>

#ifdef __AVX__
#define L_AVX
#endif

#endif