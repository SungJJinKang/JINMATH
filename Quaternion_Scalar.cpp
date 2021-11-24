#include "Quaternion_Scalar.h"

#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

math::Quaternion::Quaternion(FLOAT32 s, const Vector3& vector) noexcept: value{ vector.x, vector.y, vector.z, s }
{
}


math::Quaternion::type math::Quaternion::mat2Quaternion(const Matrix3x3& m)
{
	FLOAT32 fourXSquaredMinus1 = m[0][0] - m[1][1] - m[2][2];
	FLOAT32 fourYSquaredMinus1 = m[1][1] - m[0][0] - m[2][2];
	FLOAT32 fourZSquaredMinus1 = m[2][2] - m[0][0] - m[1][1];
	FLOAT32 fourWSquaredMinus1 = m[0][0] + m[1][1] + m[2][2];

	INT32 biggestIndex = 0;
	FLOAT32 fourBiggestSquaredMinus1 = fourWSquaredMinus1;
	if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourXSquaredMinus1;
		biggestIndex = 1;
	}
	if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourYSquaredMinus1;
		biggestIndex = 2;
	}
	if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourZSquaredMinus1;
		biggestIndex = 3;
	}

	FLOAT32 biggestVal = static_cast<FLOAT32>(::std::sqrt(fourBiggestSquaredMinus1 + static_cast<FLOAT32>(1)) * static_cast<FLOAT32>(0.5));
	FLOAT32 mult = static_cast<FLOAT32>(0.25) / biggestVal;

	switch (biggestIndex)
	{
	case 0:
		return Quaternion(biggestVal, (m[1][2] - m[2][1]) * mult, (m[2][0] - m[0][2]) * mult, (m[0][1] - m[1][0]) * mult);
	case 1:
		return Quaternion((m[1][2] - m[2][1]) * mult, biggestVal, (m[0][1] + m[1][0]) * mult, (m[2][0] + m[0][2]) * mult);
	case 2:
		return Quaternion((m[2][0] - m[0][2]) * mult, (m[0][1] + m[1][0]) * mult, biggestVal, (m[1][2] + m[2][1]) * mult);
	case 3:
		return Quaternion((m[0][1] - m[1][0]) * mult, (m[2][0] + m[0][2]) * mult, (m[1][2] + m[2][1]) * mult, biggestVal);
	default: // Silence a -Wswitch-default warning in GCC. Should never actually get here. Assert is just for sanity.
		assert(false);
		return Quaternion(1, 0, 0, 0);
	}
}

math::Quaternion::Quaternion(const Matrix4x4& m) noexcept : value(nullptr)
{
	mat2Quaternion(static_cast<Matrix3x3>( m));
}

math::Quaternion::type& math::Quaternion::operator=(const Matrix4x4& m) noexcept
{
	mat2Quaternion(static_cast<Matrix3x3>(m));
	return *this;
}

math::Quaternion::type& math::Quaternion::operator=(const Matrix3x3& m) noexcept
{
	mat2Quaternion(m);
	return *this;
}

math::Quaternion::operator math::Matrix3x3() const noexcept
{
	Matrix3x3 Result{ FLOAT32(1) };

	FLOAT32 qxx(this->value.x * this->value.x);
	FLOAT32 qyy(this->value.y * this->value.y);
	FLOAT32 qzz(this->value.z * this->value.z);
	FLOAT32 qxz(this->value.x * this->value.z);
	FLOAT32 qxy(this->value.x * this->value.y);
	FLOAT32 qyz(this->value.y * this->value.z);
	FLOAT32 qwx(this->value.w * this->value.x);
	FLOAT32 qwy(this->value.w * this->value.y);
	FLOAT32 qwz(this->value.w * this->value.z);

	Result[0][0] = FLOAT32(1) - FLOAT32(2) * (qyy + qzz);
	Result[0][1] = FLOAT32(2) * (qxy + qwz);
	Result[0][2] = FLOAT32(2) * (qxz - qwy);

	Result[1][0] = FLOAT32(2) * (qxy - qwz);
	Result[1][1] = FLOAT32(1) - FLOAT32(2) * (qxx + qzz);
	Result[1][2] = FLOAT32(2) * (qyz + qwx);

	Result[2][0] = FLOAT32(2) * (qxz + qwy);
	Result[2][1] = FLOAT32(2) * (qyz - qwx);
	Result[2][2] = FLOAT32(1) - FLOAT32(2) * (qxx + qyy);

	return Result;
}

math::Quaternion::operator math::Matrix4x4() const noexcept
{
	return Matrix4x4(this->operator math::Matrix3x3());
}

math::Vector3 math::Quaternion::ToEulerAngle() const
{
	return QuaternionToEulerAngle(*this);
}

math::Quaternion math::Quaternion::angleAxis(const FLOAT32& angle, const Vector3& v)
{
	const FLOAT32 a{ angle };
	const FLOAT32 s{ std::sin(a * static_cast<FLOAT32>(0.5)) };

	return Quaternion(std::cos(a * static_cast<FLOAT32>(0.5)), v * s);
}

math::Quaternion math::Quaternion::EulerAngleToQuaternion(const Vector3& eulerAngle) noexcept
{
	Vector3 c = cos(eulerAngle * FLOAT32(0.5f));
	Vector3 s = sin(eulerAngle * FLOAT32(0.5f));

	return Quaternion
	{
		s.x * c.y * c.z - c.x * s.y * s.z,
		c.x * s.y * c.z + s.x * c.y * s.z,
		c.x * c.y * s.z - s.x * s.y * c.z,
		c.x * c.y * c.z + s.x * s.y * s.z
	};
}

FLOAT32 math::Quaternion::roll(const Quaternion& q)
{
	const FLOAT32 y = static_cast<FLOAT32>(2) * (q.value.x * q.value.y + q.value.w * q.value.z);
	const FLOAT32 x = q.value.w * q.value.w + q.value.x * q.value.x - q.value.y * q.value.y - q.value.z * q.value.z;

	FLOAT32 epsilon = std::numeric_limits<FLOAT32>::epsilon();;
	if (Vector2(x, y) == epsilon && Vector2(0.0f) == epsilon) //avoid atan2(0,0) - handle singularity - Matiis
	{
		return static_cast<FLOAT32>(0);
	}
	return static_cast<FLOAT32>(std::atan2(y, x));
}

FLOAT32 math::Quaternion::pitch(const Quaternion& q)
{
	//return FLOAT32(atan(FLOAT32(2) * (q.value.y * q.value.z + q.value.w * q.value.x).w * q.value.w - q.value.x * q.value.x - q.value.y * q.value.y + q.value.z * q.value.z));
	const FLOAT32 y = static_cast<FLOAT32>(2) * (q.value.y * q.value.z + q.value.w * q.value.x);
	const FLOAT32 x = q.value.w * q.value.w - q.value.x * q.value.x - q.value.y * q.value.y + q.value.z * q.value.z;

	FLOAT32 epsilon = std::numeric_limits<FLOAT32>::epsilon();;
	if (Vector2(x, y) == epsilon && Vector2(0.0f) == epsilon) //avoid atan2(0,0) - handle singularity - Matiis
	{
		return static_cast<FLOAT32>(static_cast<FLOAT32>(2) * math::atan2(q.value.x, q.value.w));
	}

	return static_cast<FLOAT32>(math::atan2(y, x));
}

math::Vector3 math::Quaternion::QuaternionToEulerAngle(const Quaternion& x)
{
	return Vector3(Quaternion::pitch(x), Quaternion::yaw(x), Quaternion::roll(x));
}

extern math::Vector3 math::operator*(const Quaternion& q, const Vector3& v)
{
	const Vector3 QuatVector(q.value.x, q.value.y, q.value.z);
	const Vector3 uv(cross(QuatVector, v));
	const Vector3 uuv(cross(QuatVector, uv));

	return v + ((uv * q.value.w) + uuv) * static_cast<FLOAT32>(2);
}

extern math::Vector4 math::operator*(const Quaternion& q, const Vector4& v)
{
	return Vector4(q * Vector3(v), v.w);
}
