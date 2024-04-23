#include "MathLib/Types/Vec3.h"

namespace MathLib
{
	Vec3::Vec3()
	{
	}

	Vec3::Vec3(float _scalar)
	{
	}

	Vec3::Vec3(float _x, float _y, float _z)
	{
	}

	Vec3::Vec3(initializer_list<float> _values)
	{
	}

	Vec3::Vec3(Vector3 _vector)
	{
	}

	Vec3::Vec3(const Vec3& _other)
	{
	}

	Vec3::Vec3(Vec3&& _other) noexcept
	{
	}

	Vec3::~Vec3()
	{
	}

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
		return {};
	}

	bool Vec3::operator==(const Vec3& _other) const
	{
		return false;
	}

	bool Vec3::operator!=(const Vec3& _other) const
	{
		return false;
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
		return *this;
	}

	Vec3& Vec3::operator=(Vec3&& _other) noexcept
	{
		return *this;
	}
}
