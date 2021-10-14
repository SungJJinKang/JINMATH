#pragma once
#include "LMath_Core.h"
#include "Vector2.h"
#include "Vector3.h"

namespace math
{
	template <INT32 ComponentCount, typename T>
	constexpr math::Vector<ComponentCount, T> ClosestPointOnSphere(const math::Vector<ComponentCount, T>& sphereCenter, FLOAT32 radius, const math::Vector<ComponentCount, T>& point)
	{
		//assert(radius > 0);
		return (point - sphereCenter).normalized() * radius;
	}

	template <INT32 ComponentCount, typename T>
	constexpr bool IsSphereOverlap(const math::Vector<ComponentCount, T>& sphereCenterA, FLOAT32 radiusA, const math::Vector<ComponentCount, T>& sphereCenterB, FLOAT32 radiusB)
	{
		return  math::pow(radiusA + radiusB, 2) > (sphereCenterA - sphereCenterB).sqrMagnitude();
	}

	template <INT32 ComponentCount, typename T>
	constexpr bool IsSphereOverlap(const math::Vector<ComponentCount, T>& sphereCenterA, FLOAT32 radiusA, const math::Vector<ComponentCount, T>& point)
	{
		return  math::pow(radiusA, 2) > (sphereCenterA - point).sqrMagnitude();
	}
}