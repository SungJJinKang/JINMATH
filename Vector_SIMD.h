#pragma once

#include "SIMD.h"

#ifdef ENABLE_SIMD

namespace math
{
	template <typename T>
	struct Aligned16Vector4
	{
		__declspec(align(16)) T data[4];
	};


}

#endif