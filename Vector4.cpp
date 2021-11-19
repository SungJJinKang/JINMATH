#include "Vector4.h"

#include "Vector2.h"
#include "Vector3.h"

const math::Vector4 math::Vector4::forward{0.0f, 0.0f, -1.0f, 0.0f};
const math::Vector4 math::Vector4::right{ 1.0f, 0.0f, 0.0f, 0.0f };
const math::Vector4 math::Vector4::up{ 0.0f, 1.0f, 0.0f, 0.0f };
const math::Vector4 math::Vector4::zero{ 0.0f, 0.0f, 0.0f, 0.0f };
const math::Vector4 math::Vector4::one{ 1.0f, 1.0f, 1.0f, 1.0f };

math::Vector4::Vector4(const Vector2& vector) noexcept: x{ vector.x }, y{ vector.y }, z{ 0 }, w{ 0 }
{
}

math::Vector4::Vector4(const Vector3& vector, float w) noexcept: x{ vector.x }, y{ vector.y }, z{ vector.z }, w{ w }
{
}

math::Vector4::type& math::Vector4::operator=(const Vector2& vector) noexcept
{
	x = vector.x;
	y = vector.y;
	z = 0;
	w = 0;
	return *this;
}

math::Vector4::type& math::Vector4::operator=(const Vector3& vector) noexcept
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = 0;
	return *this;
}

extern NO_DISCARD math::Vector4 math::normalize(const Vector4& vector)
{
	return vector * math::inverseSqrt(math::dot(vector, vector));
}