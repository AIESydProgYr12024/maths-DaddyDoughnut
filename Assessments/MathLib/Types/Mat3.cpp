// ReSharper disable CppClangTidyClangDiagnosticReorderCtor
// ReSharper disable CppMemberInitializersOrder
#include "MathLib/Types/Mat3.h"
#include "MathLib/MathFunctions.h"

#include <sstream>

using std::stringstream;

namespace MathLib
{
	Mat3::Mat3() :
		m1{ 0.f }, m4{ 0.f }, m7{ 0.f },
		m2{ 0.f }, m5{ 0.f }, m8{ 0.f },
		m3{ 0.f }, m6{ 0.f }, m9{ 0.f }
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

	Mat3::Mat3(float _matrix[9])
	{
		for (size_t i = 0; i < MAT_3_SIZE; ++i)
			data[i] = _matrix[i];
	}

	// translate matrix from a Vec3
	Mat3 Mat3::CreateTranslation(const Vec3& _trans)
	{
		return
		{
			1.f, 0.f, _trans.x,
			0.f, 1.f, _trans.y,
			0.f, 0.f, _trans.z
		};
	}

	// translate matrix from two floats
	Mat3 Mat3::CreateTranslation(float _x, float _y)
	{
		return CreateTranslation(Vec2{ _x, _y });
	}

	// translate matrix from three floats
	Mat3 Mat3::CreateTranslation(float _x, float _y, float _z)
	{
		return CreateTranslation(Vec2{ _x, _y, _z });
	}

	// scale matrix from a Vec3
	Mat3 Mat3::CreateScale(const Vec3& _scale)
	{
		return
		{
			_scale.x, 0.f, 0.f,
			0.f, _scale.y, 0.f,
			0.f, 0.f, _scale.z
		};
	}

	// scale matrix from two floats
	Mat3 Mat3::CreateScale(float _x, float _y)
	{
		return CreateScale(Vec2{ _x, _y });
	}

	// scale matrix from three floats
	Mat3 Mat3::CreateScale(float _x, float _y, float _z)
	{
		return CreateScale(Vec3{ _x, _y, _z });
	}

	// create a euler rotation matrix  
	Mat3 Mat3::CreateEulerRotation(float _x, float _y, float _z)
	{
		return CreateEulerRotation(Vec3{ _x, _y, _z });
	}

	// create a euler rotation matrix from a Vec3 
	Mat3 Mat3::CreateEulerRotation(const Vec3& _euler)
	{
		const Mat3 x = CreateXRotation(_euler.x * DEG2RAD);
		const Mat3 y = CreateYRotation(_euler.y * DEG2RAD);
		const Mat3 z = CreateZRotation(_euler.z * DEG2RAD);

		return x * y * z;
	}

	// return an identity matrix
	Mat3 Mat3::Identity()
	{
		return { 1.f };
	}

	// transpose the matrix
	Mat3 Mat3::Transposed()
	{
		return
		{
			m1, m2, m3,
			m4, m5, m6,
			m7, m8, m9
		};
	}

	// convert the matrix to a string
	string Mat3::ToString() const
	{
		stringstream stream;

		stream << "(";

		for (size_t i = 0; i < MAT_3_SIZE; ++i)
		{
			stream << data[i];

			if (i + 1 < MAT_3_SIZE)
				stream << ", ";
		}

		stream << ")";

		return stream.str();
	}

	// Copy constructor
	Mat3::Mat3(const Mat3& _other) :
		m1{ _other.m1 }, m4{ _other.m4 }, m7{ _other.m7 },
		m2{ _other.m2 }, m5{ _other.m5 }, m8{ _other.m8 },
		m3{ _other.m3 }, m6{ _other.m6 }, m9{ _other.m9 }
	{
	}

	// Move constructor
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

	// create a transformed matrix
	Mat3 Mat3::CreateTransform(const Vec2& _trans, float _rot, const Vec2* _scale, float _xRot, float _yRot)
	{
		const Vec2 scale = _scale != nullptr ? *_scale : Vec2{ 1.f, 1.f };

		const Mat3 transMat = CreateTranslation(_trans);
		const Mat3 scaleMat = CreateScale(scale);

		const Mat3 xRotMat = CreateXRotation(_xRot);
		const Mat3 yRotMat = CreateYRotation(_yRot);
		const Mat3 zRotMat = CreateZRotation(_rot);
		const Mat3 rotMat = xRotMat * yRotMat * zRotMat;

		return transMat * rotMat * scaleMat;
	}

	// create a translated matrix from a Vec2
	Mat3 Mat3::CreateTranslation(const Vec2& _trans)
	{
		return
		{
			1.f, 0.f, _trans.x,
			0.f, 1.f, _trans.y,
			0.f, 0.f, 1.f
		};
	}

	// create a scaled matrix from a Vec2
	Mat3 Mat3::CreateScale(const Vec2& _scale)
	{
		return
		{
			_scale.x, 0.f, 0.f,
			0.f, _scale.y, 0.f,
			0.f, 0.f, 1.f
		};
	}

	// create an rotated matrix on the x axis 
	Mat3 Mat3::CreateXRotation(float _rot)
	{
		const float cos = cosf(_rot);
		const float sin = sinf(_rot);

		return
		{
			1.f, 0.f, 0.f,
			0.f, cos, -sin,
			0.f, sin, cos
		};
	}

	// create an rotated matrix on the y axis 
	Mat3 Mat3::CreateYRotation(float _rot)
	{
		const float cos = cosf(_rot);
		const float sin = sinf(_rot);

		return
		{
			cos, 0.f, sin,
			0.f, 1.f, 0.f,
			-sin, 0.f, cos
		};

	}

	// create an rotated matrix on the z axis 
	Mat3 Mat3::CreateZRotation(float _rot)
	{
		const float cos = cosf(_rot);
		const float sin = sinf(_rot);

		return
		{
			cos, -sin, 0.f,
			sin, cos, 0.f,
			0.f, 0.f, 1.f
		};
	}

	// set rotation on the x axis
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

	// get rotation on the x axis
	float Mat3::GetRotationX() const
	{
		return atan2(m2, m1);
	}

	// set rotation on the y axis
	void Mat3::SetRotationY(float _rot)
	{
		const float xLen = sqrtf(m1 * m1 + m2 * m2 + m3 * m3);
		const float zLen = sqrtf(m7 * m7 + m8 * m8 + m9 * m9);

		const float cos = cosf(_rot);
		const float sin = sinf(_rot);

		m5 = cos * xLen;
		m8 = sin * zLen;
		m6 = -sin * xLen;
		m9 = cos * zLen;
	}

	// get rotation on the y axis
	float Mat3::GetRotationY() const
	{
		return atan2f(-m4, m5);
	}

	// set rotation on the z axis
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

	// get rotation on the z axis
	float Mat3::GetRotationZ() const
	{
		return atan2f(m7, m9);
	}

	// set translation of the matrix
	void Mat3::SetTranslation(const Vec2& _trans)
	{
		m7 = _trans.x;
		m8 = _trans.y;
	}

	// set translation of the matrix
	void Mat3::Translate(const Vec2& _trans)
	{
		m7 = _trans.x;
		m8 = _trans.y;
	}

	// get translation of the matrix
	Vec2 Mat3::GetTranslation()
	{
		return { m7, m8 };
	}

	// set scale of the matrix
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

	// get scale of the matrix
	Vec2 Mat3::GetScale() const
	{
		const float xAlen = sqrtf(m1 * m1 + m2 * m2 + m3 * m3);
		const float yAlen = sqrtf(m4 * m4 + m5 * m5 + m6 * m6);

		return { xAlen, yAlen };
	}

	// transform a point
	Vec2 Mat3::TransformPoint(const Vec2& _point) const
	{
		return
		{
			_point.x * m1 + _point.y * m4 + m7,
			_point.x * m2 + _point.y * m5 + m8
		};
	}

	// transform a vector
	Vec2 Mat3::TransformVector(const Vec2& _vec) const
	{
		return
		{
			_vec.x * m1 + _vec.y * m4,
			_vec.x * m2 + _vec.y * m5
		};
	}

	// multiply matrices
	Mat3 Mat3::operator*(const Mat3& _rhs) const
	{
		return
		{
			m1 * _rhs.m1 + m2 * _rhs.m4 + m3 * _rhs.m7,
			m4 * _rhs.m1 + m5 * _rhs.m4 + m6 * _rhs.m7,
			m7 * _rhs.m1 + m8 * _rhs.m4 + m9 * _rhs.m7,

			m1 * _rhs.m2 + m2 * _rhs.m5 + m3 * _rhs.m8,
			m4 * _rhs.m2 + m5 * _rhs.m5 + m6 * _rhs.m8,
			m7 * _rhs.m2 + m8 * _rhs.m5 + m9 * _rhs.m8,

			m1 * _rhs.m3 + m2 * _rhs.m6 + m3 * _rhs.m9,
			m4 * _rhs.m3 + m5 * _rhs.m6 + m6 * _rhs.m9,
			m7 * _rhs.m3 + m8 * _rhs.m6 + m9 * _rhs.m9
		};
	}

	// multiply matrix with vector
	Vec3 Mat3::operator*(const Vec3& _rhs) const
	{
		return
		{
			m1 * _rhs.x + m2 * _rhs.y + m3 * _rhs.z,
			m4 * _rhs.x + m5 * _rhs.y + m6 * _rhs.z,
			m7 * _rhs.x + m8 * _rhs.y + m9 * _rhs.z
		};
	}


	bool Mat3::operator==(const Mat3& _other) const
	{
		return
			Compare(m1, _other.m1) && Compare(m2, _other.m2) && Compare(m3, _other.m3) &&
			Compare(m4, _other.m4) && Compare(m5, _other.m5) && Compare(m6, _other.m6) &&
			Compare(m7, _other.m7) && Compare(m8, _other.m8) && Compare(m9, _other.m9);
	}

	bool Mat3::operator!=(const Mat3& _other) const
	{
		return !(*this == _other);
	}

	// copy operator
	Mat3& Mat3::operator=(const Mat3& _other)
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

		return *this;
	}

	// move operator
	Mat3& Mat3::operator=(Mat3&& _other) noexcept
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

		_other.m1 = 0.f;
		_other.m2 = 0.f;
		_other.m3 = 0.f;
		_other.m4 = 0.f;
		_other.m5 = 0.f;
		_other.m6 = 0.f;
		_other.m7 = 0.f;
		_other.m8 = 0.f;
		_other.m9 = 0.f;

		return *this;
	}
}
