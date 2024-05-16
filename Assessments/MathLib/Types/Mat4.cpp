#include "MathLib/Types/Mat4.h"

#include "MathLib/MathFunctions.h"

namespace MathLib
{
	Mat4::Mat4() :
		m1{ 0.f }, m5{ 0.f }, m9{ 0.f }, m13{ 0.f },
		m2{ 0.f }, m6{ 0.f }, m10{ 0.f }, m14{ 0.f },
		m3{ 0.f }, m7{ 0.f }, m11{ 0.f }, m15{ 0.f },
		m4{ 0.f }, m8{ 0.f }, m12{ 0.f }, m16{ 0.f }
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

	Mat4::Mat4(float _matrix[MAT_4_SIZE])
	{
		for (size_t i = 0; i < MAT_4_SIZE; ++i)
			data[i] = _matrix[i];
	}

	Mat4 Mat4::CreateTranslation(const Vec3& _trans)
	{
		return
		{
			1.f, 0.f, 0.f, _trans.x,
			0.f, 1.f, 0.f, _trans.y,
			0.f, 0.f, 1.f, _trans.z,
			0.f, 0.f, 0.f, 1.f
		};
	}

	Mat4 Mat4::CreateTranslation(float _x, float _y, float _z)
	{
		return CreateTranslation(Vec3{ _x, _y, _z });
	}

	Mat4 Mat4::CreateScale(const Vec3& _scale)
	{
		return
		{
			_scale.x, 0.f, 0.f, 0.f,
			0.f, _scale.y, 0.f, 0.f,
			0.f, 0.f, _scale.z, 0.f,
			0.f, 0.f, 0.f, 1.f
		};
	}

	Mat4 Mat4::CreateScale(float _x, float _y, float _z)
	{
		return CreateScale(Vec3{ _x, _y, _z });
	}

	Mat4 Mat4::CreateXRotation(float _rot)
	{
		const float cos = cosf(_rot);
		const float sin = sinf(_rot);

		return
		{
			1.f, 0.f, 0.f, 0.f,
			0.f, cos, -sin, 0.f,
			0.f, sin, cos, 0.f,
			0.f, 0.f, 0.f, 1.f
		};
	}

	Mat4 Mat4::CreateYRotation(float _rot)
	{
		const float cos = cosf(_rot);
		const float sin = sinf(_rot);

		return
		{
			cos, 0.f, sin, 0.f,
			0.f, 1.f, 0.f, 0.f,
			-sin, 0.f, cos, 0.f,
			0.f, 0.f, 0.f, 1.f
		};
	}

	Mat4 Mat4::CreateZRotation(float _rot)
	{
		const float cos = cosf(_rot);
		const float sin = sinf(_rot);

		return
		{
			cos, -sin, 0.f, 0.f,
			sin, cos, 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 0.f, 1.f
		};
	}

	Mat4 Mat4::CreateEulerRotation(float _x, float _y, float _z)
	{
		return CreateEulerRotation(Vec3{ _x, _y, _z });
	}

	Mat4 Mat4::CreateEulerRotation(const Vec3& _euler)
	{
		const Mat4 x = CreateXRotation(_euler.x * DEG2RAD);
		const Mat4 y = CreateYRotation(_euler.y * DEG2RAD);
		const Mat4 z = CreateZRotation(_euler.z * DEG2RAD);

		return x * y * z;
	}

	Mat4 Mat4::Identity()
	{
		return { 1.f };
	}

	Vec4 Mat4::Transposed()
	{
		return {};
	}

	string Mat4::ToString() const
	{
		return "";
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
		const float yLen = sqrtf(m5 * m5 + m6 * m6 + m7 * m7);
		const float zLen = sqrtf(m9 * m9 + m10 * m10 + m11 * m11);

		const float cos = cosf(_rot);
		const float sin = sinf(_rot);

		m6 = cos * yLen;
		m10 = -sin * zLen;
		m7 = sin * yLen;
		m11 = cos * zLen;
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
		return
		{
			m1 * _rhs.m1 + m2 * _rhs.m5 + m3 * _rhs.m9 + m4 * _rhs.m13,
			m5 * _rhs.m1 + m6 * _rhs.m5 + m7 * _rhs.m9 + m8 * _rhs.m13,
			m9 * _rhs.m1 + m10 * _rhs.m5 + m11 * _rhs.m9 + m12 * _rhs.m13,
			m13 * _rhs.m1 + m14 * _rhs.m5 + m15 * _rhs.m9 + m16 * _rhs.m13,

			m1 * _rhs.m2 + m2 * _rhs.m6 + m3 * _rhs.m10 + m4 * _rhs.m14,
			m5 * _rhs.m2 + m6 * _rhs.m6 + m7 * _rhs.m10 + m8 * _rhs.m14,
			m9 * _rhs.m2 + m10 * _rhs.m6 + m11 * _rhs.m10 + m12 * _rhs.m14,
			m13 * _rhs.m2 + m14 * _rhs.m6 + m15 * _rhs.m10 + m16 * _rhs.m14,

			m1 * _rhs.m3 + m2 * _rhs.m7 + m3 * _rhs.m11 + m4 * _rhs.m15,
			m5 * _rhs.m3 + m6 * _rhs.m7 + m7 * _rhs.m11 + m8 * _rhs.m15,
			m9 * _rhs.m3 + m10 * _rhs.m7 + m11 * _rhs.m11 + m12 * _rhs.m15,
			m13 * _rhs.m3 + m14 * _rhs.m7 + m15 * _rhs.m11 + m16 * _rhs.m15,

			m1 * _rhs.m4 + m2 * _rhs.m8 + m3 * _rhs.m12 + m4 * _rhs.m16,
			m5 * _rhs.m4 + m6 * _rhs.m8 + m7 * _rhs.m12 + m8 * _rhs.m16,
			m9 * _rhs.m4 + m10 * _rhs.m8 + m11 * _rhs.m12 + m12 * _rhs.m16,
			m13 * _rhs.m4 + m14 * _rhs.m8 + m15 * _rhs.m12 + m16 * _rhs.m16
			
		};
	}

	Vec4 Mat4::operator*(const Vec4& _rhs) const
	{
		return
		{
			m1 * _rhs.x + m2 * _rhs.y + m3 * _rhs.z + m4 * _rhs.w,
			m5 * _rhs.x + m6 * _rhs.y + m7 * _rhs.z + m8 * _rhs.w,
			m9 * _rhs.x + m10 * _rhs.y + m11 * _rhs.z + m12 * _rhs.w,
			m13 * _rhs.x + m14 * _rhs.y + m15 * _rhs.z + m16 * _rhs.w
		};
	}

	bool Mat4::operator==(const Mat4& _other) const
	{
		return
			Compare(m1, _other.m1) && Compare(m2, _other.m2) && Compare(m3, _other.m3) && Compare(m3, _other.m3) &&
			Compare(m5, _other.m5) && Compare(m6, _other.m6) && Compare(m7, _other.m7) && Compare(m8, _other.m8) &&
			Compare(m9, _other.m9) && Compare(m10, _other.m10) && Compare(m11, _other.m11) && Compare(m12, _other.m12) &&
			Compare(m13, _other.m13) && Compare(m14, _other.m14) && Compare(m15, _other.m15) && Compare(m16, _other.m16);

			
	}

	bool Mat4::operator!=(const Mat4& _other) const
	{
		return !(*this == _other);
	}

	Mat4& Mat4::operator=(const Mat4& _other)
	{
		if (*this == _other)
			return *this;

		m1 = _other.m1;
		m2 = _other.m2;
		m3 = _other.m3;
		m4 = _other.m4;
		m5 = _other.m5;
		m6 = _other.m6;
		m7 = _other.m7;
		m8 = _other.m8;
		m9 = _other.m9;
		m10 = _other.m10;
		m11 = _other.m11;
		m12 = _other.m12;
		m13 = _other.m13;
		m14 = _other.m14;
		m15 = _other.m15;
		m16 = _other.m16;

		return *this;
	}

	Mat4& Mat4::operator=(Mat4&& _other) noexcept
	{
		if (*this == _other)
			return *this;

		m1 = _other.m1;
		m2 = _other.m2;
		m3 = _other.m3;
		m4 = _other.m4;
		m5 = _other.m5;
		m6 = _other.m6;
		m7 = _other.m7;
		m8 = _other.m8;
		m9 = _other.m9;
		m10 = _other.m10;
		m11 = _other.m11;
		m12 = _other.m12;
		m13 = _other.m13;
		m14 = _other.m14;
		m15 = _other.m15;
		m16 = _other.m16;

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

		return *this;
	}
}
