#include "Matrix.h"
#include "Matrix1x1.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

using namespace Math;

template struct Matrix<1, 1, float>;
template struct Matrix<2, 2, float>;
template struct Matrix<3, 3, float>;
template struct Matrix<4, 4, float>;

template struct Matrix<1, 1, double>;
template struct Matrix<2, 2, double>;
template struct Matrix<3, 3, double>;
template struct Matrix<4, 4, double>;

template struct Matrix<1, 1, long double>;
template struct Matrix<2, 2, long double>;
template struct Matrix<3, 3, long double>;
template struct Matrix<4, 4, long double>;

template struct Matrix<1, 1, short int>;
template struct Matrix<2, 2, short int>;
template struct Matrix<3, 3, short int>;
template struct Matrix<4, 4, short int>;

template struct Matrix<1, 1, int>;
template struct Matrix<2, 2, int>;
template struct Matrix<3, 3, int>;
template struct Matrix<4, 4, int>;

template struct Matrix<1, 1, long int>;
template struct Matrix<2, 2, long int>;
template struct Matrix<3, 3, long int>;
template struct Matrix<4, 4, long int>;

template struct Matrix<1, 1, long long int>;
template struct Matrix<2, 2, long long int>;
template struct Matrix<3, 3, long long int>;
template struct Matrix<4, 4, long long int>;

template struct Matrix<1, 1, unsigned short int>;
template struct Matrix<2, 2, unsigned short int>;
template struct Matrix<3, 3, unsigned short int>;
template struct Matrix<4, 4, unsigned short int>;

template struct Matrix<1, 1, unsigned int>;
template struct Matrix<2, 2, unsigned int>;
template struct Matrix<3, 3, unsigned int>;
template struct Matrix<4, 4, unsigned int>;

template struct Matrix<1, 1, unsigned long int>;
template struct Matrix<2, 2, unsigned long int>;
template struct Matrix<3, 3, unsigned long int>;
template struct Matrix<4, 4, unsigned long int>;

template struct Matrix<1, 1, unsigned long long int>;
template struct Matrix<2, 2, unsigned long long int>;
template struct Matrix<3, 3, unsigned long long int>;
template struct Matrix<4, 4, unsigned long long int>;




