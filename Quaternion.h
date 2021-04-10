#pragma once


#include "LMath_Core.h"



#include "SIMD_Core.h"

#ifndef SIMD_ENABLED
#include "Quaternion_Scalar.h"
#else
#include "Quaternion_SIMD.h"
#endif

