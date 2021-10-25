#include "Matrix.h"
#include "Matrix1x1.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

using namespace math;

template struct math::Matrix<1, 1, FLOAT32>;
template struct math::Matrix<2, 2, FLOAT32>;
template struct math::Matrix<3, 3, FLOAT32>;
template struct math::Matrix<4, 4, FLOAT32>;


template struct math::Matrix<1, 1, FLOAT64>;
template struct math::Matrix<2, 2, FLOAT64>;
template struct math::Matrix<3, 3, FLOAT64>;
template struct math::Matrix<4, 4, FLOAT64>;



/*
template struct Matrix<1, 1, long FLOAT64>;
template struct Matrix<2, 2, long FLOAT64>;
template struct Matrix<3, 3, long FLOAT64>;

template struct Matrix<1, 1, short INT32>;
template struct Matrix<2, 2, short INT32>;
template struct Matrix<3, 3, short INT32>;

template struct Matrix<1, 1, INT32>;
template struct Matrix<2, 2, INT32>;
template struct Matrix<3, 3, INT32>;

template struct Matrix<1, 1, long INT32>;
template struct Matrix<2, 2, long INT32>;
template struct Matrix<3, 3, long INT32>;

template struct Matrix<1, 1, long long INT32>;
template struct Matrix<2, 2, long long INT32>;
template struct Matrix<3, 3, long long INT32>;

template struct Matrix<1, 1, unsigned short INT32>;
template struct Matrix<2, 2, unsigned short INT32>;
template struct Matrix<3, 3, unsigned short INT32>;

template struct Matrix<1, 1, UINT32>;
template struct Matrix<2, 2, UINT32>;
template struct Matrix<3, 3, UINT32>;

template struct Matrix<1, 1, UINT32 INT32>;
template struct Matrix<2, 2, UINT32 INT32>;
template struct Matrix<3, 3, UINT32 INT32>;

template struct Matrix<1, 1, UINT64 INT32>;
template struct Matrix<2, 2, UINT64 INT32>;
template struct Matrix<3, 3, UINT64 INT32>;
*/


template <typename T>
const math::Matrix<1, 1, T> math::Matrix<1, 1, T>::identify{ static_cast<T>(1) };

template <typename T>
const math::Matrix<2, 2, T> math::Matrix<2, 2, T>::identify{ static_cast<T>(1) };

template <typename T>
const math::Matrix<3, 3, T> math::Matrix<3, 3, T>::identify{ static_cast<T>(1) };

template <typename T>
const math::Matrix<4, 4, T> math::Matrix<4, 4, T>::identify{ static_cast<T>(1) };