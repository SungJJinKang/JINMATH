#pragma once
#include "Vector.h"


namespace Math
{
	template <typename T>
	struct Vector<4, T>
	{
		static_assert(std::is_arithmetic_v<T>);

		using value_type = typename T;
		using type = typename Vector<4, T>;

		value_type value[4];

		value_type& x = value[0];
		value_type& y = value[1];
		value_type& z = value[2];
		value_type& w = value[3];

		value_type& r = value[0];
		value_type& g = value[1];
		value_type& b = value[2];
		value_type& a = value[3];

		Vector() : value[0]{}, value[1]{}, value[2]{}, value[3]{}
		{
			
		}

		explicit Vector(value_type x, value_type y, value_type z, value_type w) : value{x, y, z, w}
		{

		}
		
		Vector(const type&) = default;
		Vector(type&&) = default;
		Vector& opreator=(const type&) = default;
		Vector& opreator=(type&&) = default;

		inline static constexpr size_t length(){ return 4; }

		T& operator[](size_t i)
		{
			assert(i < 0 || i  >= length());
			return value[i];
		}
	};

	
}