#include "MathLib/Types/Mat4.h"

namespace MathLib
{
	Mat4::Mat4() :
		m1{ 1.f }, m5{ 0.f }, m9{ 0.f }, m13{ 0.f },
		m2{ 0.f }, m6{ 1.f }, m10{ 0.f }, m14{ 0.f },
		m3{ 0.f }, m7{ 0.f }, m11{ 1.f }, m15{ 0.f },
		m4{ 0.f }, m8{ 0.f }, m12{ 0.f }, m16{ 1.f }
	{
	}

	Mat4::Mat4(float _scalar) :
		m1{ _scalar }, m5{ 0.f }, m9{ 0.f }, m13{ 0.f },
		m2{ 0.f }, m6{ _scalar }, m10{ 0.f }, m14{ 0.f },
		m3{ 0.f }, m7{ 0.f }, m11{ _scalar }, m15{ 0.f },
		m4{ 0.f }, m8{ 0.f }, m12{ 0.f }, m16{ _scalar }
	{
	}

	Mat4::Mat4(float _m1, float _m5, float _m9, float _m13, float _m2, float _m6, float _m10, float _m14, float _m3,
		float _m7, float _m11, float _m15, float _m4, float _m8, float _m12, float _m16) :
		m1{ _m1 }, m5{ _m5 }, m9{ _m9 }, m13{ _m13 },
		m2{ _m2 }, m6{ _m6 }, m10{ _m10 }, m14{ _m14 },
		m3{ _m3 }, m7{ _m7 }, m11{ _m11 }, m15{ _m15 },
		m4{ _m4 }, m8{ _m8 }, m12{ _m12 }, m16{ _m16 }
	{
	}

	Mat4::Mat4(const Mat4& _other) :
		m1{ _other.m1 }, m5{ _other.m5 }, m9{ _other.m9 }, m13{ _other.m13 },
		m2{ _other.m2 }, m6{ _other.m6 }, m10{ _other.m10 }, m14{ _other.m14 },
		m3{ _other.m3 }, m7{ _other.m7 }, m11{ _other.m11 }, m15{ _other.m15 },
		m4{ _other.m4 }, m8{ _other.m8 }, m12{ _other.m12 }, m16{ _other.m16 }
	{
	}

	Mat4::Mat4(Mat4&& _other) noexcept :
		m1{ _other.m1 }, m5{ _other.m5 }, m9{ _other.m9 }, m13{ _other.m13 },
		m2{ _other.m2 }, m6{ _other.m6 }, m10{ _other.m10 }, m14{ _other.m14 },
		m3{ _other.m3 }, m7{ _other.m7 }, m11{ _other.m11 }, m15{ _other.m15 },
		m4{ _other.m4 }, m8{ _other.m8 }, m12{ _other.m12 }, m16{ _other.m16 }
	{
		_other.m1 = 0.f;
		_other.m2 = 0.f;
		_other.m3 = 0.f;
		_other.m4 = 0.f;
		_other.m5 = 0.f;
		_other.m6 = 0.f;
		_other.m7 = 0.f;
		_other.m8 = 0.f;
		_other.m9 = 0.f;
		_other.m10 = 0.f;
		_other.m11 = 0.f;
		_other.m12 = 0.f;
		_other.m13 = 0.f;
		_other.m14 = 0.f;
		_other.m15 = 0.f;
		_other.m16 = 0.f;
	}

	Mat4::~Mat4() = default;

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
