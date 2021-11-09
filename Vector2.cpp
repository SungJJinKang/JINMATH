#include "Vector2.h"

template <typename T>
const math::_Vector2<T> math::_Vector2<T>::right{ static_cast<T>(1), 0 };

template <typename T>
const math::_Vector2<T> math::_Vector2<T>::up{ 0, static_cast<T>(1) };

template struct math::_Vector2<FLOAT32>;
template struct math::_Vector2<INT32>;