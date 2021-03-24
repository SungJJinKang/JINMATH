#pragma once
// references :
// https://stackoverflow.com/questions/66743623/what-is-difference-between-m128a-and-m128a?noredirect=1#comment117984269_66743623
// https://stackoverflow.com/questions/52112605/is-reinterpret-casting-between-hardware-simd-vector-pointer-and-the-correspond
// https://stackoverflow.com/questions/6996764/fastest-way-to-do-horizontal-sse-vector-sum-or-other-reduction
// Unreal Engine Source Code  
//

#include "SIMD.h"

#ifdef SIMD_ENABLED



#include <immintrin.h>


typedef __m128	M128F;
typedef __m128d M128D;
typedef __m128i M128I;


typedef __m256	M256F;
typedef __m256d M256D;
typedef __m256i M256I;

/*
#ifndef M128F
#define M128F(VECTOR4FLOAT) *reinterpret_cast<M128F*>(&VECTOR4FLOAT)
#endif

#ifndef M128D
#define M128D(VECTOR4DOUBLE) *reinterpret_cast<M128D*>(&VECTOR4DOUBLE)
#endif

#ifndef M128I
#define M128I(VECTOR4INT) *reinterpret_cast<M128I*>(&VECTOR4INT)
#endif
*/

//https://software.intel.com/sites/landingpage/IntrinsicsGuide/#expand=69,124,3928,5197&techs=SSE,SSE2,SSE3,SSSE3,SSE4_1,SSE4_2,AVX&text=_mm_shuffle_ps
#define SHUFFLEMASK(A0,A1,B2,B3) ( (A0) | ((A1)<<2) | ((B2)<<4) | ((B3)<<6) )

#define M128F_REPLICATE(M128F, ElementIndex) _mm_permute_ps(M128F, SHUFFLEMASK(ElementIndex, ElementIndex, ElementIndex, ElementIndex)) 

#define M128F_SWIZZLE(M128F, X, Y, Z, W) _mm_permute_ps(M128F, SHUFFLEMASK(X, Y, Z, W)) 

FORCE_INLINE M128F M128F_ADD(const M128F& Vec1, const M128F& Vec2)
{
	return _mm_add_ps(Vec1, Vec2);
}

FORCE_INLINE M128F M128F_SUB(const M128F& Vec1, const M128F& Vec2)
{
	return _mm_sub_ps(Vec1, Vec2);
}

FORCE_INLINE M128F M128F_MUL(const M128F& Vec1, const M128F& Vec2)
{
	return _mm_mul_ps(Vec1, Vec2);
}

FORCE_INLINE M128F M128F_DIV(const M128F& Vec1, const M128F& Vec2)
{
	return _mm_div_ps(Vec1, Vec2);
}

FORCE_INLINE M128F M128F_MUL_AND_ADD(const M128F& Vec1, const M128F& Vec2, const M128F& Vec3)
{
	return M128F_ADD(M128F_MUL(Vec1, Vec2), Vec3);
}

FORCE_INLINE M128F M128F_CROSS(const M128F& Vec1, const M128F& Vec2)
{
	M128F A_YZXW = _mm_shuffle_ps(Vec1, Vec1, SHUFFLEMASK(1, 2, 0, 3));
	M128F B_ZXYW = _mm_shuffle_ps(Vec2, Vec2, SHUFFLEMASK(2, 0, 1, 3));
	M128F A_ZXYW = _mm_shuffle_ps(Vec1, Vec1, SHUFFLEMASK(2, 0, 1, 3));
	M128F B_YZXW = _mm_shuffle_ps(Vec2, Vec2, SHUFFLEMASK(1, 2, 0, 3));
	return M128F_SUB(M128F_MUL(A_YZXW, B_ZXYW), M128F_MUL(A_ZXYW, B_YZXW));
}










#endif


