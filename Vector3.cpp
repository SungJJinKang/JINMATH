#include "Vector3.h"

template <typename T>
const math::_Vector3<T> math::_Vector3<T>::forward{ 0, 0, static_cast<T>(-1) };

template <typename T>
const math::_Vector3<T> math::_Vector3<T>::right{ static_cast<T>(1), 0, 0 };

template <typename T>
const math::_Vector3<T> math::_Vector3<T>::up{ 0, static_cast<T>(1), 0 };


template struct math::_Vector3<FLOAT32>;
template struct math::_Vector3<INT32>;