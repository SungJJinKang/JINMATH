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

		constexpr Vector() : value[0]{}
		{
			
		}

		constexpr explicit Vector(value_type x) : value{x}
		{

		}

		Vector(const type&) = default;
		Vector(type&&) = default;
		Vector& opreator=(const type&) = default;
		Vector& opreator=(type&&) = default;
		

		inline static constexpr size_t length(){ return 1; }

		T& operator[](size_t i)
		{
			assert(i != 0);
			return value;
		}
		
		template <typename X>
		constexpr type& operator+(const Vector<1, X>& vec1)
		{
			value += vec1.value;
			return *this;
		}

		template <typename X>
		constexpr type& operator-(const Vector<1, X>& vec1)
		{
			value -= vec1.value;
			return *this;
		}

		template <typename X>
		constexpr type& operator*(const Vector<1, X>& vec1)
		{
			value *= vec1.value;
			return *this;
		}

		template <typename X>
		constexpr type& operator/(const Vector<1, X>& vec1)
		{
			value /= vec1.value;
			return *this;
		}

		template <typename X>
		constexpr type& operator%(const Vector<1, X>& vec1)
		{
			value %= vec1.value;
			return *this;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator++()
		{
			++value;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr type& operator++(value_type)
		{
			type Vector{ *this };
			++*this;
			return Vector;
		}

		/// <summary>
		/// prefix
		/// </summary>
		/// <returns></returns>
		constexpr type& operator--()
		{
			--value;
			return *this;
		}

		/// <summary>
		/// postfix
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		constexpr type& operator--(value_type)
		{
			type Vector{ *this };
			--*this;
			return Vector;
		}
	};

	
}