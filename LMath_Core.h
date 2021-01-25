#pragma once

#include <type_traits>

#define CHECK_IS_NUMBER(t) std::is_floating_point_v<t> || std::is_integral_v<t>