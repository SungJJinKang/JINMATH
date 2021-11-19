#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"
#include "Utility.h"

namespace math
{
	
	math::Matrix4x4 frustum(const float& left, const float& right, const float& bottom, const float& top, const float& nearVal, const float& farVal);

	
	math::Matrix4x4 infinitePerspective(float fovy, float aspect, float zNear);

	
	inline math::Matrix4x4 lookAtRH(const math::Vector3& eye, const math::Vector3& center, const math::Vector3& up)
	{
		const math::Vector3 f((center - eye).normalized());
		const math::Vector3 s(normalize(cross(f, up)));
		const math::Vector3 u(cross(s, f));

		math::Matrix4x4  Result(1);
		Result[0][0] = s.x;
		Result[1][0] = s.y;
		Result[2][0] = s.z;
		Result[0][1] = u.x;
		Result[1][1] = u.y;
		Result[2][1] = u.z;
		Result[0][2] = -f.x;
		Result[1][2] = -f.y;
		Result[2][2] = -f.z;
		Result[3][0] = -dot(s, eye);
		Result[3][1] = -dot(u, eye);
		Result[3][2] = dot(f, eye);
		return Result;
	}

	
	inline math::Matrix4x4 lookAtLH(const math::Vector3& eye, const math::Vector3& center, const math::Vector3& up)
	{
		const math::Vector3 f(normalize(center - eye));
		const math::Vector3 s(normalize(cross(up, f)));
		const math::Vector3 u(cross(f, s));

		math::Matrix4x4 Result(1);
		Result[0][0] = s.x;
		Result[1][0] = s.y;
		Result[2][0] = s.z;
		Result[0][1] = u.x;
		Result[1][1] = u.y;
		Result[2][1] = u.z;
		Result[0][2] = f.x;
		Result[1][2] = f.y;
		Result[2][2] = f.z;
		Result[3][0] = -dot(s, eye);
		Result[3][1] = -dot(u, eye);
		Result[3][2] = -dot(f, eye);
		return Result;
	}

	
	inline math::Matrix4x4 lookAt(const math::Vector3& eye, const math::Vector3& center, const math::Vector3& up)
	{
#       if (CURRENT_COORDINATE_SYSTEM == LEFT_HAND)
		return lookAtLH(eye, center, up);
#       else
		return lookAtRH(eye, center, up);
#       endif
	}

	
	inline math::Matrix4x4 orthoLH_ZO(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		math::Matrix4x4 Result(1);
		Result[0][0] = static_cast<float>(2) / (right - left);
		Result[1][1] = static_cast<float>(2) / (top - bottom);
		Result[2][2] = static_cast<float>(1) / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -zNear / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 orthoLH_NO(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		math::Matrix4x4 Result(1);
		Result[0][0] = static_cast<float>(2) / (right - left);
		Result[1][1] = static_cast<float>(2) / (top - bottom);
		Result[2][2] = static_cast<float>(2) / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -(zFar + zNear) / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 orthoRH_ZO(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		math::Matrix4x4 Result(1);
		Result[0][0] = static_cast<float>(2) / (right - left);
		Result[1][1] = static_cast<float>(2) / (top - bottom);
		Result[2][2] = -static_cast<float>(1) / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -zNear / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 orthoRH_NO(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		math::Matrix4x4 Result(1);
		Result[0][0] = static_cast<float>(2) / (right - left);
		Result[1][1] = static_cast<float>(2) / (top - bottom);
		Result[2][2] = -static_cast<float>(2) / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -(zFar + zNear) / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 ortho(const float& left, const float& right, const float& bottom, const float& top)
	{
		math::Matrix4x4 Result(static_cast<float>(1));
		Result[0][0] = static_cast<float>(2) / (right - left);
		Result[1][1] = static_cast<float>(2) / (top - bottom);
		Result[2][2] = -static_cast<float>(1);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		return Result;
	}

	
	inline math::Matrix4x4 ortho(float left, float right, float bottom, float top, float zNear, float zFar)
	{
#		if CURRENT_SETTING == LEFT_HAND_ZERO_TO_ONE
		return orthoLH_ZO(left, right, bottom, top, zNear, zFar);
#		elif CURRENT_SETTING == LEFT_HAND_NEGATIVE_ONE_TO_ONE
		return orthoLH_NO(left, right, bottom, top, zNear, zFar);
#		elif CURRENT_SETTING == RIGHT_HAND_ZERO_TO_ONE
		return orthoRH_ZO(left, right, bottom, top, zNear, zFar);
#		elif CURRENT_SETTING == RIGHT_HAND_NEGATIVE_ONE_TO_ONE
		return orthoRH_NO(left, right, bottom, top, zNear, zFar);
#		endif
	}

	
	inline math::Matrix4x4 perspectiveRH_ZO(float fovy, float aspect, float zNear, float zFar)
	{
		assert(std::abs(aspect - std::numeric_limits<float>::epsilon()) > static_cast<float>(0));

		float const tanHalfFovy = std::tan(fovy / static_cast<float>(2));

		math::Matrix4x4 Result(static_cast<float>(0));
		Result[0][0] = static_cast<float>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<float>(1) / (tanHalfFovy);
		Result[2][2] = zFar / (zNear - zFar);
		Result[2][3] = -static_cast<float>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 perspectiveRH_NO(float fovy, float aspect, float zNear, float zFar)
	{
		assert(std::abs(aspect - std::numeric_limits<float>::epsilon()) > static_cast<float>(0));

		float const tanHalfFovy = std::tan(fovy / static_cast<float>(2));

		math::Matrix4x4 Result(static_cast<float>(0));
		Result[0][0] = static_cast<float>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<float>(1) / (tanHalfFovy);
		Result[2][2] = -(zFar + zNear) / (zFar - zNear);
		Result[2][3] = -static_cast<float>(1);
		Result[3][2] = -(static_cast<float>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 perspectiveLH_ZO(float fovy, float aspect, float zNear, float zFar)
	{
		assert(std::abs(aspect - std::numeric_limits<float>::epsilon()) > static_cast<float>(0));

		float const tanHalfFovy = std::tan(fovy / static_cast<float>(2));

		math::Matrix4x4 Result(static_cast<float>(0));
		Result[0][0] = static_cast<float>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<float>(1) / (tanHalfFovy);
		Result[2][2] = zFar / (zFar - zNear);
		Result[2][3] = static_cast<float>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 perspectiveLH_NO(float fovy, float aspect, float zNear, float zFar)
	{
		assert(std::abs(aspect - std::numeric_limits<float>::epsilon()) > static_cast<float>(0));

		float const tanHalfFovy = std::tan(fovy / static_cast<float>(2));

		math::Matrix4x4 Result(static_cast<float>(0));
		Result[0][0] = static_cast<float>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<float>(1) / (tanHalfFovy);
		Result[2][2] = (zFar + zNear) / (zFar - zNear);
		Result[2][3] = static_cast<float>(1);
		Result[3][2] = -(static_cast<float>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 perspective(const float& fovy, const float& aspect, const float& zNear, const float& zFar)
	{
#		if CURRENT_SETTING == LEFT_HAND_ZERO_TO_ONE
			return perspectiveLH_ZO(fovy, aspect, zNear, zFar);
#		elif CURRENT_SETTING == LEFT_HAND_NEGATIVE_ONE_TO_ONE
			return perspectiveLH_NO(fovy, aspect, zNear, zFar);
#		elif CURRENT_SETTING == RIGHT_HAND_ZERO_TO_ONE
			return perspectiveRH_ZO(fovy, aspect, zNear, zFar);
#		elif CURRENT_SETTING == RIGHT_HAND_NEGATIVE_ONE_TO_ONE
			return perspectiveRH_NO(fovy, aspect, zNear, zFar);
#		endif
	}



	
	inline math::Matrix4x4 perspectiveFovRH_ZO(float fov, float width, float height, float zNear, float zFar)
	{
		assert(width > static_cast<float>(0));
		assert(height > static_cast<float>(0));
		assert(fov > static_cast<float>(0));

		float const rad = fov;
		float const h = std::cos(static_cast<float>(0.5) * rad) / std::sin(static_cast<float>(0.5) * rad);
		float const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		math::Matrix4x4 Result(static_cast<float>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = zFar / (zNear - zFar);
		Result[2][3] = -static_cast<float>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 perspectiveFovRH_NO(float fov, float width, float height, float zNear, float zFar)
	{
		assert(width > static_cast<float>(0));
		assert(height > static_cast<float>(0));
		assert(fov > static_cast<float>(0));

		float const rad = fov;
		float const h = std::cos(static_cast<float>(0.5) * rad) / std::sin(static_cast<float>(0.5) * rad);
		float const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		math::Matrix4x4 Result(static_cast<float>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = -(zFar + zNear) / (zFar - zNear);
		Result[2][3] = -static_cast<float>(1);
		Result[3][2] = -(static_cast<float>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 perspectiveFovLH_ZO(float fov, float width, float height, float zNear, float zFar)
	{
		assert(width > static_cast<float>(0));
		assert(height > static_cast<float>(0));
		assert(fov > static_cast<float>(0));

		float const rad = fov;
		float const h = std::cos(static_cast<float>(0.5) * rad) / std::sin(static_cast<float>(0.5) * rad);
		float const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		math::Matrix4x4 Result(static_cast<float>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = zFar / (zFar - zNear);
		Result[2][3] = static_cast<float>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	
	inline math::Matrix4x4 perspectiveFovLH_NO(float fov, float width, float height, float zNear, float zFar)
	{
		assert(width > static_cast<float>(0));
		assert(height > static_cast<float>(0));
		assert(fov > static_cast<float>(0));

		float const rad = fov;
		float const h = std::cos(static_cast<float>(0.5) * rad) / std::sin(static_cast<float>(0.5) * rad);
		float const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		math::Matrix4x4 Result(static_cast<float>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = (zFar + zNear) / (zFar - zNear);
		Result[2][3] = static_cast<float>(1);
		Result[3][2] = -(static_cast<float>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}


	
	inline math::Matrix4x4 perspectiveFov(float fov, float width, float height, float zNear, float zFar)
	{
#		if CURRENT_SETTING == LEFT_HAND_ZERO_TO_ONE
		return perspectiveFovLH_ZO(fov, width, height, zNear, zFar);
#		elif CURRENT_SETTING == LEFT_HAND_NEGATIVE_ONE_TO_ONE
		return perspectiveFovLH_NO(fov, width, height, zNear, zFar);
#		elif CURRENT_SETTING == RIGHT_HAND_ZERO_TO_ONE
		return perspectiveFovRH_ZO(fov, width, height, zNear, zFar);
#		elif CURRENT_SETTING == RIGHT_HAND_NEGATIVE_ONE_TO_ONE
		return perspectiveFovRH_NO(fov, width, height, zNear, zFar);
#		endif
	}

	/*
	template<typename float, typename U>
	math::Matrix4x4 pickMatrix(const math::Vector2& center, const math::Vector2& delta, const math::Vector4<U>& viewport);
	*/

	
	inline math::Vector3 projectZeroToOne(const math::Vector3& obj, const math::Matrix4x4& model, const math::Matrix4x4& proj, const math::Vector4& viewport)
	{
		math::Vector4 tmp = math::Vector4(obj, static_cast<float>(1));
		tmp = model * tmp;
		tmp = proj * tmp;

		tmp /= tmp.w;
		tmp.x = tmp.x * static_cast<float>(0.5) + static_cast<float>(0.5);
		tmp.y = tmp.y * static_cast<float>(0.5) + static_cast<float>(0.5);

		tmp[0] = tmp[0] * float(viewport[2]) + float(viewport[0]);
		tmp[1] = tmp[1] * float(viewport[3]) + float(viewport[1]);

		return math::Vector3(tmp);
	}

	inline math::Vector3 projectNOneToOne(const math::Vector3& obj, const math::Matrix4x4& model, const math::Matrix4x4& proj, const math::Vector4& viewport)
	{
		math::Vector4 tmp = math::Vector4(obj, static_cast<float>(1));
		tmp = model * tmp;
		tmp = proj * tmp;

		tmp /= tmp.w;
		tmp = tmp * static_cast<float>(0.5) + static_cast<float>(0.5);
		tmp[0] = tmp[0] * float(viewport[2]) + float(viewport[0]);
		tmp[1] = tmp[1] * float(viewport[3]) + float(viewport[1]);

		return math::Vector3(tmp);
	}
	
	inline math::Vector3 project(const math::Vector3& obj, const math::Matrix4x4& model, const math::Matrix4x4& proj, const math::Vector4& viewport)
	{
#		if CURRENT_CLIP_RANGE == CLIP_RANGE_NEGATIVE_ONE_TO_ONE
		return projectZeroToOne(obj, model, proj, viewport);
#		else
		return projectNOneToOne(obj, model, proj, viewport);
#		endif
	}

	
	inline math::Matrix4x4 rotate(const math::Matrix4x4& m, const float& angle, const math::Vector3& v)
	{
		const float a = angle;
		const float c = std::cos(a);
		const float s = std::sin(a);

		math::Vector3 axis(v.normalized());
		math::Vector3 temp((float(1) - c) * axis);

		math::Matrix4x4 Rotate{ nullptr };
		Rotate[0][0] = c + temp[0] * axis[0];
		Rotate[0][1] = temp[0] * axis[1] + s * axis[2];
		Rotate[0][2] = temp[0] * axis[2] - s * axis[1];

		Rotate[1][0] = temp[1] * axis[0] - s * axis[2];
		Rotate[1][1] = c + temp[1] * axis[1];
		Rotate[1][2] = temp[1] * axis[2] + s * axis[0];

		Rotate[2][0] = temp[2] * axis[0] + s * axis[1];
		Rotate[2][1] = temp[2] * axis[1] - s * axis[0];
		Rotate[2][2] = c + temp[2] * axis[2];

		math::Matrix4x4 Result{ nullptr };
		Result[0] = m[0] * Rotate[0][0] + m[1] * Rotate[0][1] + m[2] * Rotate[0][2];
		Result[1] = m[0] * Rotate[1][0] + m[1] * Rotate[1][1] + m[2] * Rotate[1][2];
		Result[2] = m[0] * Rotate[2][0] + m[1] * Rotate[2][1] + m[2] * Rotate[2][2];
		Result[3] = m[3];
		return Result;
	}

	
	FORCE_INLINE math::Matrix4x4 rotate(const float& angle, const math::Vector3& v)
	{
		return math::rotate(Matrix4x4(static_cast<float>(1)), angle, v);
	}

	
	FORCE_INLINE math::Matrix4x4 scale(const math::Matrix4x4& m, const math::Vector3& v)
	{
		math::Matrix4x4 Result{ nullptr };
		Result[0] = m[0] * v[0];
		Result[1] = m[1] * v[1];
		Result[2] = m[2] * v[2];
		Result[3] = m[3];
		return Result;
	}

	
	FORCE_INLINE math::Matrix4x4 scale(const math::Vector3& v)
	{
		return math::scale(Matrix4x4(static_cast<float>(1)), v);
	}

	
	FORCE_INLINE math::Matrix4x4 translate(const math::Matrix4x4& m, const math::Vector3& v)
	{
		math::Matrix4x4 Result(m);
		Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
		return Result;
	}

	
	FORCE_INLINE math::Matrix4x4 translate(const math::Vector3& v)
	{
		return math::translate(Matrix4x4(static_cast<float>(1)), v);;
	}

	/*
	
	math::Matrix4x4 tweakedInfinitePerspective(float fovy, float aspect, float zNear);

	template<typename float, typename U>
	math::Vector3 unProject(const math::Vector3& win, const math::Matrix4x4& model, const math::Matrix4x4& proj, const math::Vector4<U>& viewport);
	*/
}