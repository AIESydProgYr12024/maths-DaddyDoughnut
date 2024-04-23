#include "MathLib/Types/Mat3.h"

namespace MathLib
{
	Mat3::Mat3()
	{
	}

	Mat3::Mat3(float _scalar)
	{
	}

	Mat3::Mat3(float _m1, float _m4, float _m7, float _m2, float _m5, float _m8, float _m3, float _m6, float _m9)
	{
	}

	Mat3::Mat3(const Mat3& _other)
	{
	}

	Mat3::Mat3(Mat3&& _other) noexcept
	{
	}

	Mat3::~Mat3()
	{
	}

	Mat3 Mat3::CreateTransform(const Vec2& _trans, float _rot, const Vec2* _scale, float _xRot, float _yRot)
	{
		return {};
	}

	Mat3 Mat3::CreateTranslation(const Vec2& _trans)
	{
		return {};
	}

	Mat3 Mat3::CreateScale(const Vec2& _scale)
	{
		return {};
	}

	Mat3 Mat3::CreateXRotation(float _rot)
	{
		return {};
	}

	Mat3 Mat3::CreateYRotation(float _rot)
	{
		return {};
	}

	Mat3 Mat3::CreateZRotation(float _rot)
	{
		return {};
	}

	void Mat3::SetRotationX(float _rot)
	{
	}

	float Mat3::GetRotationX() const
	{
		return 0;
	}

	void Mat3::SetRotationY(float _rot)
	{
	}

	float Mat3::GetRotationY() const
	{
		return 0;
	}

	void Mat3::SetRotationZ(float _rot)
	{
	}

	float Mat3::GetRotationZ() const
	{
		return 0;
	}

	void Mat3::SetTranslation(const Vec2& _trans)
	{
	}

	void Mat3::Translate(const Vec2& _trans)
	{
	}

	Vec2 Mat3::GetTranslation()
	{
		return {};
	}

	void Mat3::SetScale(const Vec2& _scale)
	{
	}

	Vec2 Mat3::GetScale() const
	{
		return {};
	}

	Vec2 Mat3::TransformPoint(const Vec2& _point) const
	{
		return {};
	}

	Vec2 Mat3::TransformVector(const Vec2& _vec) const
	{
		return {};
	}

	Mat3 Mat3::operator*(const Mat3& _rhs) const
	{
		return {};
	}

	Vec3 Mat3::operator*(const Vec3& _rhs) const
	{
		return {};
	}

	bool Mat3::operator==(const Mat3& _other) const
	{
		return false;
	}

	bool Mat3::operator!=(const Mat3& _other) const
	{
		return false;
	}

	Mat3& Mat3::operator=(const Mat3& _other)
	{
		return *this;
	}

	Mat3& Mat3::operator=(Mat3&& _other) noexcept
	{
		return *this;
	}
}
