#include "MathLib/Types/Vec3.h"

#include "MathLib/Types/Vec2.h"
#include "MathLib/MathFunctions.h"

namespace MathLib
{
	Vec3::Vec3()
		: x{ 0.f }, y{ 0.f }, z{ 0.f }
	{
	}

	Vec3::Vec3(float _scalar)
		: x{ _scalar }, y{ _scalar }, z{ _scalar }
	{
	}

	Vec3::Vec3(float _x, float _y, float _z)
		: x{ _x }, y{ _y }, z{ _z }
	{
	}

	Vec3::Vec3(initializer_list<float> _values)
	{
		for (size_t i = 0; i < VEC_3_SIZE; ++i)
		{
			data[i] = *(_values.begin() + i);
		}
	}

	Vec3::Vec3(Vector3 _vector)
		: x{ _vector.x }, y{ _vector.y }, z{ _vector.z }
	{
	}

	Vec3::Vec3(const Vec3& _other)
		: x{ _other.x }, y{ _other.y}
	{
	}

	Vec3::Vec3(Vec3&& _other) noexcept
		: x{ _other.x }, y{ _other.y }
	{

		_other.x = 0.f;
		_other.y = 0.f;
		_other.z = 0.f;

	}

	Vec3::~Vec3() = default;

	Vec3 Vec3::Add(const Vec3& _lhs, const Vec3& _rhs)
	{
		return {};
	}

	Vec3 Vec3::Subtract(const Vec3& _lhs, const Vec3& _rhs)
	{
		return {};
	}

	Vec3 Vec3::Scale(const Vec3& _lhs, float _rhs)
	{
		return {};
	}

	Vec3 Vec3::Normalised(const Vec3& _vec)
	{
		return {};
	}

	float Vec3::Distance(const Vec3& _a, const Vec3& _b)
	{
		return 0;
	}

	float Vec3::Dot(const Vec3& _lhs, const Vec3& _rhs)
	{
		return 0;
	}

	Vec3 Vec3::Cross(const Vec3& _lhs, const Vec3& _rhs)
	{
		return {};
	}

	Vec3 Vec3::Lerp(const Vec3& _a, const Vec3& _b, float _t)
	{
		return {};
	}

	float Vec3::Dot(const Vec3& _rhs) const
	{
		return 0;
	}

	Vec3 Vec3::Cross(const Vec3& _rhs) const
	{
		return {};
	}

	float Vec3::Magnitude() const
	{
		return 0;
	}

	float Vec3::MagnitudeSqr() const
	{
		return 0;
	}

	void Vec3::Normalise()
	{
	}

	Vec3 Vec3::Normalised() const
	{
		return {};
	}

	string Vec3::ToString() const
	{
		return "";
	}

	Vec3::operator Vector3() const
	{
		return { x, y, z };
	}

	bool Vec3::operator==(const Vec3& _other) const
	{
		return Compare(x, _other.x) && Compare(y, _other.y) && Compare(z, _other.z);
	}

	bool Vec3::operator!=(const Vec3& _other) const
	{
		return !(*this == _other);
	}

	Vec3 Vec3::operator-(const Vec3& _other) const
	{
		return {};
	}

	Vec3& Vec3::operator-=(const Vec3& _other)
	{
		return *this;
	}

	Vec3 Vec3::operator+(const Vec3& _other) const
	{
		return {};
	}

	Vec3& Vec3::operator+=(const Vec3& _other)
	{
		return *this;
	}

	Vec3 Vec3::operator*(float _other) const
	{
		return {};
	}

	Vec3& Vec3::operator*=(float _other)
	{
		return *this;
	}

	Vec3& Vec3::operator=(const Vec3& _other)
	{
		if (*this == _other)
			return *this;

		x = _other.x;
		y = _other.y;
		z = _other.z;

		return *this;
	}

	Vec3& Vec3::operator=(Vec3&& _other) noexcept
	{
		if (*this == _other)
			return *this;

		x = _other.x;
		y = _other.y;
		z = _other.z;

		_other.x = 0.f;
		_other.y = 0.f;
		_other.z = 0.f;

		return *this;
	}
}
