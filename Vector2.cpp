#include "Vector2.h"

template struct math::Vector<2, float>;
template struct math::Vector<2, double>;
template struct math::Vector<2, long double>;
template struct math::Vector<2, short int>;
template struct math::Vector<2, int>;
template struct math::Vector<2, long int>;
template struct math::Vector<2, long long int>;
template struct math::Vector<2, unsigned short int>;
template struct math::Vector<2, unsigned int>;
template struct math::Vector<2, unsigned long int>;
template struct math::Vector<2, unsigned long long int>;


template <typename T>
const math::Vector<2, T> math::Vector<2, T>::right{ 1, 0 };

template <typename T>
const math::Vector<2, T> math::Vector<2, T>::up{ 0, 1 };

