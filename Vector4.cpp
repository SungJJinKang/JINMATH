#include "Vector4.h"

const math::_Vector4<FLOAT32> math::_Vector4<FLOAT32>::forward{ 0, 0, static_cast<FLOAT32>(-1), 0 };
const math::_Vector4<FLOAT32> math::_Vector4<FLOAT32>::right{ static_cast<FLOAT32>(1), 0, 0, 0 };
const math::_Vector4<FLOAT32> math::_Vector4<FLOAT32>::up{ 0, static_cast<FLOAT32>(1), 0, 0 };
const math::_Vector4<FLOAT32> math::_Vector4<FLOAT32>::zero{ 0, 0, 0, 0 };
const math::_Vector4<FLOAT32> math::_Vector4<FLOAT32>::one{ static_cast<FLOAT32>(1), static_cast<FLOAT32>(1), static_cast<FLOAT32>(1), static_cast<FLOAT32>(1) };

const math::_Vector4<INT32> math::_Vector4<INT32>::forward{ 0, 0, static_cast<INT32>(-1), 0 };
const math::_Vector4<INT32> math::_Vector4<INT32>::right{ static_cast<INT32>(1), 0, 0, 0 };
const math::_Vector4<INT32> math::_Vector4<INT32>::up{ 0, static_cast<INT32>(1), 0, 0 };
const math::_Vector4<INT32> math::_Vector4<INT32>::zero{ 0, 0, 0, 0 };
const math::_Vector4<INT32> math::_Vector4<INT32>::one{ static_cast<INT32>(1), static_cast<INT32>(1), static_cast<INT32>(1), static_cast<INT32>(1) };


template struct math::_Vector4<FLOAT32>;
template struct math::_Vector4<INT32>;