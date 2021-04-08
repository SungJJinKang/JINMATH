#include "Vector4.h"

template <typename T>
const math::Vector<4, T> math::Vector<4, T>::forward{ 0, 0, static_cast<T>(-1), 0 };

template <typename T>
const math::Vector<4, T> math::Vector<4, T>::right{ static_cast<T>(1), 0, 0, 0 };

template <typename T>
const math::Vector<4, T> math::Vector<4, T>::up{ 0, static_cast<T>(1), 0, 0 };

template struct math::Vector<4, float>;