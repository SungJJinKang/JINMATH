#include "Matrix.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

using namespace math;

template struct math::_Matrix2x2<FLOAT32>;
template struct math::_Matrix3x3<FLOAT32>;
template struct math::_Matrix4x4<FLOAT32>;


template struct math::_Matrix2x2<FLOAT64>;
template struct math::_Matrix3x3<FLOAT64>;
template struct math::_Matrix4x4<FLOAT64>;



/*
template struct Matrix<1, 1, long FLOAT64>;
template struct _Matrix2x2<long FLOAT64>;
template struct _Matrix3x3<long FLOAT64>;

template struct Matrix<1, 1, short INT32>;
template struct _Matrix2x2<short INT32>;
template struct _Matrix3x3<short INT32>;

template struct Matrix<1, 1, INT32>;
template struct _Matrix2x2<INT32>;
template struct _Matrix3x3<INT32>;

template struct Matrix<1, 1, long INT32>;
template struct _Matrix2x2<long INT32>;
template struct _Matrix3x3<long INT32>;

template struct Matrix<1, 1, long long INT32>;
template struct _Matrix2x2<long long INT32>;
template struct _Matrix3x3<long long INT32>;

template struct Matrix<1, 1, unsigned short INT32>;
template struct _Matrix2x2<unsigned short INT32>;
template struct _Matrix3x3<unsigned short INT32>;

template struct Matrix<1, 1, UINT32>;
template struct _Matrix2x2<UINT32>;
template struct _Matrix3x3<UINT32>;

template struct Matrix<1, 1, UINT32 INT32>;
template struct _Matrix2x2<UINT32 INT32>;
template struct _Matrix3x3<UINT32 INT32>;

template struct Matrix<1, 1, UINT64 INT32>;
template struct _Matrix2x2<UINT64 INT32>;
template struct _Matrix3x3<UINT64 INT32>;
*/


template <typename T>
const math::_Matrix2x2<T> math::_Matrix2x2<T>::identify{ static_cast<T>(1) };

template <typename T>
const math::_Matrix3x3<T> math::_Matrix3x3<T>::identify{ static_cast<T>(1) };

template <typename T>
const math::_Matrix4x4<T> math::_Matrix4x4<T>::identify{ static_cast<T>(1) };