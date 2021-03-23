#include "Vector4.h"

template struct math::Vector<4, float>;
template struct math::Vector<4, double>;
template struct math::Vector<4, long double>;
template struct math::Vector<4, short int>;
template struct math::Vector<4, int>;
template struct math::Vector<4, long int>;
template struct math::Vector<4, long long int>;
template struct math::Vector<4, unsigned short int>;
template struct math::Vector<4, unsigned int>;
template struct math::Vector<4, unsigned long int>;
template struct math::Vector<4, unsigned long long int>;


template <typename T>
const math::Vector<4, T> math::Vector<4, T>::forward{ 0, 0, static_cast<T>(-1), 0 };

template <typename T>
const math::Vector<4, T> math::Vector<4, T>::right{ static_cast<T>(1), 0, 0, 0 };

template <typename T>
const math::Vector<4, T> math::Vector<4, T>::up{ 0, static_cast<T>(1), 0, 0 };

