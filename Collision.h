#pragma once
#include "LMath_Core.h"
#include "Vector2.h"
#include "Vector3.h"

namespace math
{
	template <int ComponentCount, typename T>
	SIMD_CONSTEXPR math::Vector<ComponentCount, T> ClosestPointOnSphere(const math::Vector<ComponentCount, T>& sphereCenter, float radius, const math::Vector<ComponentCount, T>& point)
	{
		//assert(radius > 0);
		return (point - sphereCenter).normalized() * radius;
	}

	template <int ComponentCount, typename T>
	SIMD_CONSTEXPR bool IsSphereOverlap(const math::Vector<ComponentCount, T>& sphereCenterA, float radiusA, const math::Vector<ComponentCount, T>& sphereCenterB, float radiusB)
	{
		return  math::pow(radiusA + radiusB, 2) > (sphereCenterA - sphereCenterB).sqrMagnitude();
	}

	template <int ComponentCount, typename T>
	SIMD_CONSTEXPR bool IsSphereOverlap(const math::Vector<ComponentCount, T>& sphereCenterA, float radiusA, const math::Vector<ComponentCount, T>& point)
	{
		return  math::pow(radiusA, 2) > (sphereCenterA - point).sqrMagnitude();
	}
}