#pragma once
namespace Math
{
	template <size_t RowComponentCount, size_t RowComponentColl, typename T>
	struct Matrix
	{
		static_assert(std::is_arithmetic_v<T>);
	};

}