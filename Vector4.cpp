#include "Vector4.h"

const math::Vector<4, float> math::Vector<4, float>::forward{ 0, 0, static_cast<float>(-1), 0 };
const math::Vector<4, float> math::Vector<4, float>::right{ static_cast<float>(1), 0, 0, 0 };
const math::Vector<4, float> math::Vector<4, float>::up{ 0, static_cast<float>(1), 0, 0 };
const math::Vector<4, float> math::Vector<4, float>::zero{ 0, 0, 0, 0 };
const math::Vector<4, float> math::Vector<4, float>::one{ static_cast<float>(1), static_cast<float>(1), static_cast<float>(1), static_cast<float>(1) };

template struct math::Vector<4, float>;