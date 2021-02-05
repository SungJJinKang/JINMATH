#include "Vector3.h"

template struct math::Vector<3, float>;
template struct math::Vector<3, double>;
template struct math::Vector<3, long double>;
template struct math::Vector<3, short int>;
template struct math::Vector<3, int>;
template struct math::Vector<3, long int>;
template struct math::Vector<3, long long int>;
template struct math::Vector<3, unsigned short int>;
template struct math::Vector<3, unsigned int>;
template struct math::Vector<3, unsigned long int>;
template struct math::Vector<3, unsigned long long int>;

template <typename T>
const math::Vector<3, T> math::Vector<3, T>::forward{ 0, 0, -1 };

template <typename T>
const math::Vector<3, T> math::Vector<3, T>::right{ 1, 0, 0 };

template <typename T>
const math::Vector<3, T> math::Vector<3, T>::up{ 0, 1, 0 };

