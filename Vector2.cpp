#include "Vector2.h"

template <typename T>
const math::Vector<2, T> math::Vector<2, T>::right{ static_cast<T>(1), 0 };

template <typename T>
const math::Vector<2, T> math::Vector<2, T>::up{ 0, static_cast<T>(1) };

template struct math::Vector<2, FLOAT32>;