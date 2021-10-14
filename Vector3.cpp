#include "Vector3.h"

template <typename T>
const math::Vector<3, T> math::Vector<3, T>::forward{ 0, 0, static_cast<T>(-1) };

template <typename T>
const math::Vector<3, T> math::Vector<3, T>::right{ static_cast<T>(1), 0, 0 };

template <typename T>
const math::Vector<3, T> math::Vector<3, T>::up{ 0, static_cast<T>(1), 0 };


template struct math::Vector<3, FLOAT32>;