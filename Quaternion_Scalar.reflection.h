#pragma once

// Utility Header File ( Don't Edit this )
// SourceFilePath : C:\Doom3FromScratch\Doom3\Source\Core\Math\LightMath_Cpp\Quaternion_Scalar.cpp


#ifdef C__Doom3FromScratch_Doom3_Source_Core_Math_LightMath_Cpp_Quaternion_Scalar_reflection_h

#error "C:\Doom3FromScratch\Doom3\Source\Core\Math\LightMath_Cpp\Quaternion_Scalar.reflection.h already included, missing '#pragma once' in C:\Doom3FromScratch\Doom3\Source\Core\Math\LightMath_Cpp\Quaternion_Scalar.reflection.h"

#endif

#define C__Doom3FromScratch_Doom3_Source_Core_Math_LightMath_Cpp_Quaternion_Scalar_reflection_h


#include <type_traits>
#include <cassert>


//-------------------------------------------


#ifdef GENERATE_BODY_FULLNAME_math__Quaternion
#error "GENERATE_BODY_FULLNAME_math__Quaternion already included...."
#endif


#undef CURRENT_TYPE_ALIAS_math__Quaternion
#define CURRENT_TYPE_ALIAS_math__Quaternion \
typedef math::Quaternion Current;


#undef TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Quaternion
#define TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Quaternion \
inline static const unsigned long int TYPE_FULL_NAME_HASH_VALUE = 3718895100; \
inline static const char* const TYPE_FULL_NAME = "math::Quaternion"; \
inline static const char* const TYPE_SHORT_NAME = "Quaternion"; \


#undef TYPE_CHECK_FUNCTION_Quaternion
#define TYPE_CHECK_FUNCTION_Quaternion \
attrNoReflect void __TYPE_CHECK() { static_assert(std::is_same_v<std::remove_reference<decltype(*this)>::type, Current> == true, "ERROR : WRONG TYPE. Please Check GENERATED_~ MACROS");} \


#undef GENERATE_BODY_FULLNAME_math__Quaternion
#define GENERATE_BODY_FULLNAME_math__Quaternion(...) \
CURRENT_TYPE_ALIAS_math__Quaternion \
TYPE_FULLNAME_HASH_VALUE_NAME_STRING_math__Quaternion \
TYPE_CHECK_FUNCTION_Quaternion \


//Type Short Name ( without namespace, only type name ) Version Macros.
#define GENERATE_BODY_Quaternion(...) GENERATE_BODY_FULLNAME_math__Quaternion(__VA_ARGS__)


#undef GENERATE_BODY
#define GENERATE_BODY(...) GENERATE_BODY_FULLNAME_math__Quaternion(__VA_ARGS__)


//-------------------------------------------

