#pragma once

// Utility Header File ( Don't Edit this )
// SourceFilePath : __Source_Core_Math_JINMATH_Matrix3x3_reflection_h


#ifdef __Source_Core_Math_JINMATH_Matrix3x3_reflection_h

#error "__Source_Core_Math_JINMATH_Matrix3x3_reflection_h already included, missing '#pragma once' in __Source_Core_Math_JINMATH_Matrix3x3_reflection_h"

#endif

#define __Source_Core_Math_JINMATH_Matrix3x3_reflection_h


#include <type_traits>
#include <cassert>


//-------------------------------------------


#ifdef GENERATE_BODY_FULLNAME_math__Matrix3x3
#error "GENERATE_BODY_FULLNAME_math__Matrix3x3 already included...."
#endif


#undef CURRENT_TYPE_ALIAS_math__Matrix3x3
#define CURRENT_TYPE_ALIAS_math__Matrix3x3 \
typedef math::Matrix3x3 Current;


#undef TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Matrix3x3
#define TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Matrix3x3 \
inline static const unsigned long int TYPE_FULL_NAME_HASH_VALUE = 3773195857; \
inline static const char* const TYPE_FULL_NAME = "math::Matrix3x3"; \
inline static const char* const TYPE_SHORT_NAME = "Matrix3x3"; \


#undef TYPE_CHECK_FUNCTION_Matrix3x3
#define TYPE_CHECK_FUNCTION_Matrix3x3 \
attrNoReflect void __TYPE_CHECK() { static_assert(std::is_same_v<std::remove_reference<decltype(*this)>::type, Current> == true, "ERROR : WRONG TYPE. Please Check GENERATED_~ MACROS");} \


#undef GENERATE_BODY_FULLNAME_math__Matrix3x3
#define GENERATE_BODY_FULLNAME_math__Matrix3x3(...) \
CURRENT_TYPE_ALIAS_math__Matrix3x3 \
TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Matrix3x3 \
TYPE_CHECK_FUNCTION_Matrix3x3 \


//Type Short Name ( without namespace, only type name ) Version Macros.
#define GENERATE_BODY_Matrix3x3(...) GENERATE_BODY_FULLNAME_math__Matrix3x3(__VA_ARGS__)


#undef GENERATE_BODY
#define GENERATE_BODY(...) GENERATE_BODY_FULLNAME_math__Matrix3x3(__VA_ARGS__)


//-------------------------------------------


