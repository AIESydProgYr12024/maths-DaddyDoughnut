#include "MathLib/Types/Vec4.h"

namespace MathLib
{
	Vec4::Vec4()
	{
	}

	Vec4::Vec4(float _scalar)
	{
	}

	Vec4::Vec4(float _x, float _y, float _z, float _w)
	{
	}

	Vec4::Vec4(initializer_list<float> _values)
	{
	}

	Vec4::Vec4(Vector4 _value)
	{
	}

	Vec4::Vec4(const Vec4& _other)
	{
	}

	Vec4::Vec4(Vec4&& _other) noexcept
	{
	}

	Vec4::~Vec4()
	{
	}

	Vec4 Vec4::Add(const Vec4& _lhs, const Vec4& _rhs)
	{
		return {};
	}

	Vec4 Vec4::Subtract(const Vec4& _lhs, const Vec4& _rhs)
	{
		return {};
	}

	Vec4 Vec4::Scale(const Vec4& _lhs, float _rhs)
	{
		return {};
	}

	Vec4 Vec4::Normalised(const Vec4& _vec)
	{
		return {};
	}

	float Vec4::Distance(const Vec4& _a, const Vec4& _b)
	{
		return 0;
	}

	float Vec4::Dot(const Vec4& _lhs, const Vec4& _rhs)
	{
		return 0;
	}

	Vec4 Vec4::Lerp(const Vec4& _a, const Vec4& _b, float _t)
	{
		return {};
	}

	float Vec4::Dot(const Vec4& _rhs) const
	{
		return 0;
	}

	float Vec4::Magnitude() const
	{
		return 0;
	}

	float Vec4::MagnitudeSqr() const
	{
		return 0;
	}

	void Vec4::Normalise()
	{
	}

	Vec4 Vec4::Normalised() const
	{
		return {};
	}

	string Vec4::ToString() const
	{
		return "";
	}

	Vec4::operator Vector4() const
	{
		return {};
	}

	bool Vec4::operator==(const Vec4& _other) const
	{
		return false;
	}

	bool Vec4::operator!=(const Vec4& _other) const
	{
		return false;
	}

	Vec4 Vec4::operator-(const Vec4& _other) const
	{
		return {};
	}

	Vec4& Vec4::operator-=(const Vec4& _other)
	{
		return *this;
	}

	Vec4 Vec4::operator+(const Vec4& _other) const
	{
		return {};
	}

	Vec4& Vec4::operator+=(const Vec4& _other)
	{
		return *this;
	}

	Vec4 Vec4::operator*(float _other) const
	{
		return {};
	}

	Vec4& Vec4::operator*=(float _other)
	{
		return *this;
	}

	Vec4& Vec4::operator=(const Vec4& _other)
	{
		return *this;
	}

	Vec4& Vec4::operator=(Vec4&& _other) noexcept
	{
		return *this;
	}

	Vec4 operator*(float _lhs, const Vec4& _rhs)
	{
		return {};
	}
}
