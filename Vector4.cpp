#include "Vector4.h"

const math::Vector<4, FLOAT32> math::Vector<4, FLOAT32>::forward{ 0, 0, static_cast<FLOAT32>(-1), 0 };
const math::Vector<4, FLOAT32> math::Vector<4, FLOAT32>::right{ static_cast<FLOAT32>(1), 0, 0, 0 };
const math::Vector<4, FLOAT32> math::Vector<4, FLOAT32>::up{ 0, static_cast<FLOAT32>(1), 0, 0 };
const math::Vector<4, FLOAT32> math::Vector<4, FLOAT32>::zero{ 0, 0, 0, 0 };
const math::Vector<4, FLOAT32> math::Vector<4, FLOAT32>::one{ static_cast<FLOAT32>(1), static_cast<FLOAT32>(1), static_cast<FLOAT32>(1), static_cast<FLOAT32>(1) };

template struct math::Vector<4, FLOAT32>;