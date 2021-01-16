#pragma once
#include "Vector.h"

namespace Math
{
	template <typename T>
	struct Vector<1, T>
	{
		static_assert(std::is_arithmetic_v<T>);

		using value_type = typename T;
		using type = typename Vector<1, T>;

		value_type value;

		value_type& x = value;

		value_type& r = value;

		Vector() : value[0]{}
		{
			
		}

		explicit Vector(value_type x) : value[0]{x}
		{

		}

		Vector(const type&) = default;
		Vector(type&&) = default;
		Vector& opreator=(const type&) = default;
		Vector& opreator=(type&&) = default;
		
		template <typename X>
		Vector& operator+(const Vector<1, X>& vec1)
		{
			value += vec1.value;
			return *this;
		}

		template <typename X>
		Vector& operator-(const Vector<1, X>& vec1)
		{
			value -= vec1.value;
			return *this;
		}

		template <typename X>
		Vector& operator*(const Vector<1, X>& vec1)
		{
			value *= vec1.value;
			return *this;
		}

		template <typename X>
		Vector& operator/(const Vector<1, X>& vec1)
		{
			value /= vec1.value;
			return *this;
		}

		template <typename X>
		Vector& operator%(const Vector<1, X>& vec1)
		{
			value %= vec1.value;
			return *this;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		Vector& operator++()
		{
			++value;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		Vector& operator++(value_type)
		{
			type Vector{ *this };
			++*this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		Vector& operator--()
		{
			--value;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		Vector& operator--(value_type)
		{
			type Vector{ *this };
			--*this;
			return Vector;
		}
	};

	
}