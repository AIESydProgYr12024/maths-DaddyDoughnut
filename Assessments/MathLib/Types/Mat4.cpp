#include "MathLib/Types/Mat4.h"

namespace MathLib
{
	Mat4::Mat4()
	{
	}

	Mat4::Mat4(float _scalar)
	{
	}

	Mat4::Mat4(float _m1, float _m5, float _m9, float _m13, float _m2, float _m6, float _m10, float _m14, float _m3,
		float _m7, float _m11, float _m15, float _m4, float _m8, float _m12, float _m16)
	{
	}

	Mat4::Mat4(const Mat4& _other)
	{
	}

	Mat4::Mat4(Mat4&& _other) noexcept
	{
	}

	Mat4::~Mat4()
	{
	}

	void Mat4::SetRotationX(float _rot)
	{
	}

	float Mat4::GetRotationX() const
	{
		return 0;
	}

	void Mat4::SetRotationY(float _rot)
	{
	}

	float Mat4::GetRotationY() const
	{
		return 0;
	}

	void Mat4::SetRotationZ(float _rot)
	{
	}

	float Mat4::GetRotationZ() const
	{
		return 0;
	}

	void Mat4::SetTranslation(const Vec3& _trans)
	{
	}

	void Mat4::Translate(const Vec3& _trans)
	{
	}

	Vec3 Mat4::GetTranslation()
	{
		return {};
	}

	Mat4 Mat4::operator*(const Mat4& _rhs) const
	{
		return {};
	}

	Vec4 Mat4::operator*(const Vec4& _rhs) const
	{
		return {};
	}

	bool Mat4::operator==(const Mat4& _other) const
	{
		return false;
	}

	bool Mat4::operator!=(const Mat4& _other) const
	{
		return false;
	}

	Mat4& Mat4::operator=(const Mat4& _other)
	{
		return *this;
	}

	Mat4& Mat4::operator=(Mat4&& _other) noexcept
	{
		return *this;
	}
}
