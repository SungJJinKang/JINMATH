#pragma once
#include "Vector.h"


namespace Math
{
	template <typename T>
	struct Vector<3, T>
	{
		static_assert(std::is_arithmetic_v<T>);

		using value_type = typename T;
		using type = typename Vector<3, T>;

		value_type value[3];

		value_type& x = value[0];
		value_type& y = value[1];
		value_type& z = value[2];

		value_type& r = value[0];
		value_type& g = value[1];
		value_type& b = value[2];

		Vector() : value[0]{}, value[1]{}, value[2]{}
		{
			
		}

		explicit Vector(value_type x, value_type y, value_type z) : value[0]{x}, value[1]{y}, value[2]{z}
		{

		}

		Vector(const type&) = default;
		Vector(type&&) = default;
		Vector& opreator=(const type&) = default;
		Vector& opreator=(type&&) = default;
	};

}