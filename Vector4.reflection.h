#pragma once

// Utility Header File ( Don't Edit this )
// SourceFilePath : __Source_Core_Math_LightMath_Cpp_Vector4_reflection_h


#ifdef __Source_Core_Math_LightMath_Cpp_Vector4_reflection_h

#error "__Source_Core_Math_LightMath_Cpp_Vector4_reflection_h already included, missing '#pragma once' in __Source_Core_Math_LightMath_Cpp_Vector4_reflection_h"

#endif

#define __Source_Core_Math_LightMath_Cpp_Vector4_reflection_h


#include <type_traits>
#include <cassert>


//-------------------------------------------


#ifdef GENERATE_BODY_FULLNAME_math__Vector4
#error "GENERATE_BODY_FULLNAME_math__Vector4 already included...."
#endif


#undef CURRENT_TYPE_ALIAS_math__Vector4
#define CURRENT_TYPE_ALIAS_math__Vector4 \
typedef math::Vector4 Current;


#undef TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Vector4
#define TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Vector4 \
inline static const unsigned long int TYPE_FULL_NAME_HASH_VALUE = 2970189327; \
inline static const char* const TYPE_FULL_NAME = "math::Vector4"; \
inline static const char* const TYPE_SHORT_NAME = "Vector4"; \


#undef TYPE_CHECK_FUNCTION_Vector4
#define TYPE_CHECK_FUNCTION_Vector4 \
attrNoReflect void __TYPE_CHECK() { static_assert(std::is_same_v<std::remove_reference<decltype(*this)>::type, Current> == true, "ERROR : WRONG TYPE. Please Check GENERATED_~ MACROS");} \


#undef GENERATE_BODY_FULLNAME_math__Vector4
#define GENERATE_BODY_FULLNAME_math__Vector4(...) \
CURRENT_TYPE_ALIAS_math__Vector4 \
TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Vector4 \
TYPE_CHECK_FUNCTION_Vector4 \


//Type Short Name ( without namespace, only type name ) Version Macros.
#define GENERATE_BODY_Vector4(...) GENERATE_BODY_FULLNAME_math__Vector4(__VA_ARGS__)


#undef GENERATE_BODY
#define GENERATE_BODY(...) GENERATE_BODY_FULLNAME_math__Vector4(__VA_ARGS__)


//-------------------------------------------


