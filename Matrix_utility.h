#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"
#include "Utility.h"

namespace math
{
	template<typename T>
	constexpr math::Matrix<4, 4, T> frustum(const T& left, const T& right, const T& bottom, const T& top, const T& nearVal, const T& farVal);

	template<typename T>
	constexpr math::Matrix<4, 4, T> infinitePerspective(T fovy, T aspect, T zNear);

	template<typename T>
	constexpr math::Matrix<4, 4, T> lookAtRH(const math::Vector<3, T>& eye, const math::Vector<3, T>& center, const math::Vector<3, T>& up)
	{
		const math::Vector<3, T> f((center - eye).normalized());
		const math::Vector<3, T> s(normalize(cross(f, up)));
		const math::Vector<3, T> u(cross(s, f));

		math::Matrix<4, 4, T>  Result(1);
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

	template<typename T>
	constexpr math::Matrix<4, 4, T> lookAtLH(const math::Vector<3, T>& eye, const math::Vector<3, T>& center, const math::Vector<3, T>& up)
	{
		const math::Vector<3, T> f(normalize(center - eye));
		const math::Vector<3, T> s(normalize(cross(up, f)));
		const math::Vector<3, T> u(cross(f, s));

		math::Matrix<4, 4, T> Result(1);
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

	template<typename T>
	constexpr math::Matrix<4, 4, T> lookAt(const math::Vector<3, T>& eye, const math::Vector<3, T>& center, const math::Vector<3, T>& up)
	{
#       if (CURRENT_COORDINATE_SYSTEM == LEFT_HAND)
		return lookAtLH(eye, center, up);
#       else
		return lookAtRH(eye, center, up);
#       endif
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> orthoLH_ZO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		math::Matrix<4, 4, T> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = static_cast<T>(1) / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -zNear / (zFar - zNear);
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> orthoLH_NO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		math::Matrix<4, 4, T> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = static_cast<T>(2) / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -(zFar + zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> orthoRH_ZO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		math::Matrix<4, 4, T> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = -static_cast<T>(1) / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -zNear / (zFar - zNear);
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> orthoRH_NO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		math::Matrix<4, 4, T> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = -static_cast<T>(2) / (zFar - zNear);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		Result[3][2] = -(zFar + zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> ortho(const T& left, const T& right, const T& bottom, const T& top)
	{
		math::Matrix<4, 4, T> Result(static_cast<T>(1));
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = -static_cast<T>(1);
		Result[3][0] = -(right + left) / (right - left);
		Result[3][1] = -(top + bottom) / (top - bottom);
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> ortho(T left, T right, T bottom, T top, T zNear, T zFar)
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

	template<typename T>
	constexpr math::Matrix<4, 4, T> perspectiveRH_ZO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

		T const tanHalfFovy = math::tan(fovy / static_cast<T>(2));

		math::Matrix<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = zFar / (zNear - zFar);
		Result[2][3] = -static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> perspectiveRH_NO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(math::abs(aspect - math::epsilon<T>()) > static_cast<T>(0));

		T const tanHalfFovy = math::tan(fovy / static_cast<T>(2));

		math::Matrix<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = -(zFar + zNear) / (zFar - zNear);
		Result[2][3] = -static_cast<T>(1);
		Result[3][2] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> perspectiveLH_ZO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - math::epsilon<T>()) > static_cast<T>(0));

		T const tanHalfFovy = math::tan(fovy / static_cast<T>(2));

		math::Matrix<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = zFar / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> perspectiveLH_NO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - math::epsilon<T>()) > static_cast<T>(0));

		T const tanHalfFovy = math::tan(fovy / static_cast<T>(2));

		math::Matrix<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = (zFar + zNear) / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> perspective(const T& fovy, const T& aspect, const T& zNear, const T& zFar)
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



	template<typename T>
	math::Matrix<4, 4, T> perspectiveFovRH_ZO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = math::cos(static_cast<T>(0.5) * rad) / math::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		math::Matrix<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = zFar / (zNear - zFar);
		Result[2][3] = -static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	math::Matrix<4, 4, T> perspectiveFovRH_NO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = math::cos(static_cast<T>(0.5) * rad) / math::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		math::Matrix<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = -(zFar + zNear) / (zFar - zNear);
		Result[2][3] = -static_cast<T>(1);
		Result[3][2] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	math::Matrix<4, 4, T> perspectiveFovLH_ZO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = math::cos(static_cast<T>(0.5) * rad) / math::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		math::Matrix<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = zFar / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	math::Matrix<4, 4, T> perspectiveFovLH_NO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = math::cos(static_cast<T>(0.5) * rad) / math::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		math::Matrix<4, 4, T> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = (zFar + zNear) / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}


	template<typename T>
	math::Matrix<4, 4, T> perspectiveFov(T fov, T width, T height, T zNear, T zFar)
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
	template<typename T, typename U>
	constexpr math::Matrix<4, 4, T> pickMatrix(const math::Vector<2, T>& center, const math::Vector<2, T>& delta, const math::Vector<4, U>& viewport);
	*/



	template<typename T, typename U>
	constexpr math::Vector<3, T> projectZeroToOne(const math::Vector<3, T>& obj, const math::Matrix<4, 4, T>& model, const math::Matrix<4, 4, T>& proj, const math::Vector<4, U>& viewport)
	{
		math::Vector<4, T> tmp = math::Vector<4, T>(obj, static_cast<T>(1));
		tmp = model * tmp;
		tmp = proj * tmp;

		tmp /= tmp.w;
		tmp.x = tmp.x * static_cast<T>(0.5) + static_cast<T>(0.5);
		tmp.y = tmp.y * static_cast<T>(0.5) + static_cast<T>(0.5);

		tmp[0] = tmp[0] * T(viewport[2]) + T(viewport[0]);
		tmp[1] = tmp[1] * T(viewport[3]) + T(viewport[1]);

		return math::Vector<3, T>(tmp);
	}

	template<typename T, typename U>
	constexpr math::Vector<3, T> projectNOneToOne(const math::Vector<3, T>& obj, const math::Matrix<4, 4, T>& model, const math::Matrix<4, 4, T>& proj, const math::Vector<4, U>& viewport)
	{
		math::Vector<4, T> tmp = math::Vector<4, T>(obj, static_cast<T>(1));
		tmp = model * tmp;
		tmp = proj * tmp;

		tmp /= tmp.w;
		tmp = tmp * static_cast<T>(0.5) + static_cast<T>(0.5);
		tmp[0] = tmp[0] * T(viewport[2]) + T(viewport[0]);
		tmp[1] = tmp[1] * T(viewport[3]) + T(viewport[1]);

		return math::Vector<3, T>(tmp);
	}

	template<typename T, typename U>
	constexpr math::Vector<3, T> project(const math::Vector<3, T>& obj, const math::Matrix<4, 4, T>& model, const math::Matrix<4, 4, T>& proj, const math::Vector<4, U>& viewport)
	{
#		if CURRENT_CLIP_RANGE == CLIP_RANGE_NEGATIVE_ONE_TO_ONE
		return projectZeroToOne(obj, model, proj, viewport);
#		else
		return projectNOneToOne(obj, model, proj, viewport);
#		endif
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> rotate(const math::Matrix<4, 4, T>& m, const T& angle, const math::Vector<3, T>& v)
	{
		const T a = angle;
		const T c = math::cos(a);
		const T s = math::sin(a);

		math::Vector<3, T> axis(v.normalized());
		math::Vector<3, T> temp((T(1) - c) * axis);

		math::Matrix<4, 4, T> Rotate;
		Rotate[0][0] = c + temp[0] * axis[0];
		Rotate[0][1] = temp[0] * axis[1] + s * axis[2];
		Rotate[0][2] = temp[0] * axis[2] - s * axis[1];

		Rotate[1][0] = temp[1] * axis[0] - s * axis[2];
		Rotate[1][1] = c + temp[1] * axis[1];
		Rotate[1][2] = temp[1] * axis[2] + s * axis[0];

		Rotate[2][0] = temp[2] * axis[0] + s * axis[1];
		Rotate[2][1] = temp[2] * axis[1] - s * axis[0];
		Rotate[2][2] = c + temp[2] * axis[2];

		math::Matrix<4, 4, T> Result;
		Result[0] = m[0] * Rotate[0][0] + m[1] * Rotate[0][1] + m[2] * Rotate[0][2];
		Result[1] = m[0] * Rotate[1][0] + m[1] * Rotate[1][1] + m[2] * Rotate[1][2];
		Result[2] = m[0] * Rotate[2][0] + m[1] * Rotate[2][1] + m[2] * Rotate[2][2];
		Result[3] = m[3];
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> rotate(const T& angle, const math::Vector<3, T>& v)
	{
		return math::rotate(Matrix<4, 4, T>(static_cast<T>(1)), angle, v);
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> scale(const math::Matrix<4, 4, T>& m, const math::Vector<3, T>& v)
	{
		math::Matrix<4, 4, T> Result;
		Result[0] = m[0] * v[0];
		Result[1] = m[1] * v[1];
		Result[2] = m[2] * v[2];
		Result[3] = m[3];
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> scale(const math::Vector<3, T>& v)
	{
		return math::scale(Matrix<4, 4, T>(static_cast<T>(1)), v);
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> translate(const math::Matrix<4, 4, T>& m, const math::Vector<3, T>& v)
	{
		math::Matrix<4, 4, T> Result(m);
		Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
		return Result;
	}

	template<typename T>
	constexpr math::Matrix<4, 4, T> translate(const math::Vector<3, T>& v)
	{
		return math::translate(Matrix<4, 4, T>(static_cast<T>(1)), v);;
	}

	/*
	template<typename T>
	constexpr math::Matrix<4, 4, T> tweakedInfinitePerspective(T fovy, T aspect, T zNear);

	template<typename T, typename U>
	constexpr math::Vector<3, T> unProject(const math::Vector<3, T>& win, const math::Matrix<4, 4, T>& model, const math::Matrix<4, 4, T>& proj, const math::Vector<4, U>& viewport);
	*/
}