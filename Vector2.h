#pragma once
#include "Vector.h"

namespace Math
{
	template <typename T>
	struct Vector<2, T>
	{
		static_assert(std::is_arithmetic_v<T>);

		using value_type = typename T;
		using type = typename Vector<2, T>;

		value_type value[2];
		
		value_type& x = value[0];
		value_type& y = value[1];

		value_type& r = value[0];
		value_type& g = value[1];

		Vector() : value[0]{}, value[1]{}
		{
			
		}

		explicit Vector(value_type x, value_type y) : value{x, y}
		{

		}

		Vector(const type&) = default;
		Vector(type&&) = default;
		Vector& opreator=(const type&) = default;
		Vector& opreator=(type&&) = default;

		inline static constexpr size_t length(){ return 2; }

		T& operator[](size_t i)
		{
			assert(i < 0 || i  >= length());
			return value[i];
		}
	};

	
}