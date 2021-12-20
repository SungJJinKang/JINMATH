#pragma once

// Utility Header File ( Don't Edit this )
// SourceFilePath : C:\Doom3FromScratch\Doom3\Source\Core\Math\LightMath_Cpp\Matrix4x4.cpp


#ifdef _Source_Core_Math_LightMath_Cpp_Matrix4x4_reflection_h

#error "_Source_Core_Math_LightMath_Cpp_Matrix4x4_reflection_h already included, missing '#pragma once' in _Source_Core_Math_LightMath_Cpp_Matrix4x4_reflection_h"

#endif

#define _Source_Core_Math_LightMath_Cpp_Matrix4x4_reflection_h


#include <type_traits>
#include <cassert>


//-------------------------------------------


#ifdef GENERATE_BODY_FULLNAME_math__Matrix4x4
#error "GENERATE_BODY_FULLNAME_math__Matrix4x4 already included...."
#endif


#undef CURRENT_TYPE_ALIAS_math__Matrix4x4
#define CURRENT_TYPE_ALIAS_math__Matrix4x4 \
typedef math::Matrix4x4 Current;


#undef TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Matrix4x4
#define TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Matrix4x4 \
inline static const unsigned long int TYPE_FULL_NAME_HASH_VALUE = 4246617505; \
inline static const char* const TYPE_FULL_NAME = "math::Matrix4x4"; \
inline static const char* const TYPE_SHORT_NAME = "Matrix4x4"; \


#undef TYPE_CHECK_FUNCTION_Matrix4x4
#define TYPE_CHECK_FUNCTION_Matrix4x4 \
attrNoReflect void __TYPE_CHECK() { static_assert(std::is_same_v<std::remove_reference<decltype(*this)>::type, Current> == true, "ERROR : WRONG TYPE. Please Check GENERATED_~ MACROS");} \


#undef GENERATE_BODY_FULLNAME_math__Matrix4x4
#define GENERATE_BODY_FULLNAME_math__Matrix4x4(...) \
CURRENT_TYPE_ALIAS_math__Matrix4x4 \
TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Matrix4x4 \
TYPE_CHECK_FUNCTION_Matrix4x4 \


//Type Short Name ( without namespace, only type name ) Version Macros.
#define GENERATE_BODY_Matrix4x4(...) GENERATE_BODY_FULLNAME_math__Matrix4x4(__VA_ARGS__)


#undef GENERATE_BODY
#define GENERATE_BODY(...) GENERATE_BODY_FULLNAME_math__Matrix4x4(__VA_ARGS__)


//-------------------------------------------


