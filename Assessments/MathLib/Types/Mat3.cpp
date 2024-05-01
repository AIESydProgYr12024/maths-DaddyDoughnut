// ReSharper disable CppClangTidyClangDiagnosticReorderCtor
// ReSharper disable CppMemberInitializersOrder
#include "MathLib/Types/Mat3.h"

#include "MathLib/MathFunctions.h"

namespace MathLib
{
	
	
	Mat3::Mat3() :
		m1{ 1.f }, m4{ 0.f }, m7{ 0.f },
		m2{ 0.f }, m5{ 1.f }, m8{ 0.f },
		m3{ 0.f }, m6{ 0.f }, m9{ 1.f }
	{
	}

	Mat3::Mat3(const float _scalar) :
		m1{ _scalar }, m4{ 0.f }, m7{ 0.f },
		m2{ 0.f }, m5{ _scalar }, m8{ 0.f },
		m3{ 0.f }, m6{ 0.f }, m9{ _scalar }
	{
	}

	Mat3::Mat3(const float _m1, const float _m4, const float _m7, const float _m2, const float _m5, const float _m8, const float _m3, const float _m6, const float _m9) :
		m1{ _m1 }, m4{ _m4 }, m7{ _m7 },
		m2{ _m2 }, m5{ _m5 }, m8{ _m8 },
		m3{ _m3 }, m6{ _m6 }, m9{ _m9 }
	{
	}


	Mat3::Mat3(const Mat3& _other) :
		m1{ _other.m1 }, m4{ _other.m4 }, m7{ _other.m7 },
		m2{ _other.m2 }, m5{ _other.m5 }, m8{ _other.m8 },
		m3{ _other.m3 }, m6{ _other.m6 }, m9{ _other.m9 }
	{
	}

	Mat3::Mat3(Mat3&& _other) noexcept :
		m1{ _other.m1 }, m4{ _other.m4 }, m7{ _other.m7 },
		m2{ _other.m2 }, m5{ _other.m5 }, m8{ _other.m8 },
		m3{ _other.m3 }, m6{ _other.m6 }, m9{ _other.m9 }
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
	}

	Mat3::~Mat3() = default;

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
		const float yLen = sqrtf(m4 * m4 + m5 * m5 + m6 * m6);
		const float zLen = sqrtf(m7 * m7 + m8 * m8 + m9 * m9);

		const float cos = cosf(_rot);
		const float sin = sinf(_rot);

		m5 = cos * yLen;
		m8 = -sin * zLen;
		m6 = sin * yLen;
		m9 = cos * zLen;
	}

	float Mat3::GetRotationX() const
	{
		return atan2(m2, m1);
	}

	void Mat3::SetRotationY(float _rot)
	{
	}

	float Mat3::GetRotationY() const
	{
		return atan2f(-m4, m5);
	}

	void Mat3::SetRotationZ(float _rot)
	{
		const float yLen = sqrtf(m4 * m4 + m5 * m5 + m6 * m6);
		const float xLen = sqrtf(m1 * m1 + m2 * m2 + m3 * m3);

		const float cos = cosf(_rot);
		const float sin = sinf(_rot);

		m1 = cos * xLen;
		m4 = -sin * yLen;
		m2 = sin * xLen;
		m5 = cos * yLen;
	}

	float Mat3::GetRotationZ() const
	{
		return atan2f(m7, m9);
	}

	void Mat3::SetTranslation(const Vec2& _trans)
	{
		m7 = _trans.x;
		m8 = _trans.y;
	}

	void Mat3::Translate(const Vec2& _trans)
	{
		m7 = _trans.x;
		m8 = _trans.y;
	}

	Vec2 Mat3::GetTranslation()
	{
		return { m7, m8 };
	}

	void Mat3::SetScale(const Vec2& _scale)
	{
		const float xAlen = sqrtf(m1 * m1 + m2 * m2 + m3 * m3);
		const float yAlen = sqrtf(m4 * m4 + m5 * m5 + m6 * m6);

		if (xAlen > 0.f)
		{
			m1 = m1 / xAlen * _scale.x;
			m2 = m2 / xAlen * _scale.x;
			m3 = m3 / xAlen * _scale.x;
		}
		if (yAlen > 0.f)
		{
			m4 = m4 / yAlen * _scale.y;
			m5 = m5 / yAlen * _scale.y;
			m6 = m6 / yAlen * _scale.y;
		}
	}

	Vec2 Mat3::GetScale() const
	{
		const float xAlen = sqrtf(m1 * m1 + m2 * m2 + m3 * m3);
		const float yAlen = sqrtf(m4 * m4 + m5 * m5 + m6 * m6);

		return { xAlen, yAlen };
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
