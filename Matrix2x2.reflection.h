#pragma once

// Utility Header File ( Don't Edit this )
// SourceFilePath : C:\Doom3FromScratch\Doom3\Source\Core\Math\LightMath_Cpp\Matrix2x2.cpp


#ifdef _Source_Core_Math_LightMath_Cpp_Matrix2x2_reflection_h

#error "_Source_Core_Math_LightMath_Cpp_Matrix2x2_reflection_h already included, missing '#pragma once' in _Source_Core_Math_LightMath_Cpp_Matrix2x2_reflection_h"

#endif

#define _Source_Core_Math_LightMath_Cpp_Matrix2x2_reflection_h


#include <type_traits>
#include <cassert>


//-------------------------------------------


#ifdef GENERATE_BODY_FULLNAME_math__Matrix2x2
#error "GENERATE_BODY_FULLNAME_math__Matrix2x2 already included...."
#endif


#undef CURRENT_TYPE_ALIAS_math__Matrix2x2
#define CURRENT_TYPE_ALIAS_math__Matrix2x2 \
typedef math::Matrix2x2 Current;


#undef TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Matrix2x2
#define TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Matrix2x2 \
inline static const unsigned long int TYPE_FULL_NAME_HASH_VALUE = 2184993582; \
inline static const char* const TYPE_FULL_NAME = "math::Matrix2x2"; \
inline static const char* const TYPE_SHORT_NAME = "Matrix2x2"; \


#undef TYPE_CHECK_FUNCTION_Matrix2x2
#define TYPE_CHECK_FUNCTION_Matrix2x2 \
attrNoReflect void __TYPE_CHECK() { static_assert(std::is_same_v<std::remove_reference<decltype(*this)>::type, Current> == true, "ERROR : WRONG TYPE. Please Check GENERATED_~ MACROS");} \


#undef GENERATE_BODY_FULLNAME_math__Matrix2x2
#define GENERATE_BODY_FULLNAME_math__Matrix2x2(...) \
CURRENT_TYPE_ALIAS_math__Matrix2x2 \
TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Matrix2x2 \
TYPE_CHECK_FUNCTION_Matrix2x2 \


//Type Short Name ( without namespace, only type name ) Version Macros.
#define GENERATE_BODY_Matrix2x2(...) GENERATE_BODY_FULLNAME_math__Matrix2x2(__VA_ARGS__)


#undef GENERATE_BODY
#define GENERATE_BODY(...) GENERATE_BODY_FULLNAME_math__Matrix2x2(__VA_ARGS__)


//-------------------------------------------


