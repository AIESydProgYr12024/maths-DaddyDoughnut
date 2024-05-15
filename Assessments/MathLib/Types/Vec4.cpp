#include "MathLib/Types/Vec4.h"
#include "MathLib/MathFunctions.h"


namespace MathLib
{
	Vec4 Vec4::one = Vec4(1.f, 1.f, 1.f, 1.f);
	Vec4 Vec4::zero = Vec4(0.f, 0.f, 0.f, 0.f);
	Vec4 Vec4::half = Vec4(.5f, .5f, .5f, .5f);
	Vec4 Vec4::up = Vec4(0.f, 1.f, 0.f, 0.f);
	Vec4 Vec4::down = Vec4(0.f, -1.f, 0.f, 0.f);
	Vec4 Vec4::left = Vec4(-1.f, 0.f, 0.f, 0.f);
	Vec4 Vec4::right = Vec4(1.f, 0.f, 0.f, 0.f);
	Vec4 Vec4::forward = Vec4(0.f, 0.f, 1.f, 0.f);
	Vec4 Vec4::back = Vec4(0.f, 0.f, -1.f, 0.f);

	Vec4::Vec4()
		: x{ 0.f }, y{ 0.f }, z{ 0.f }, w{ 0.f }
	{
	}

	Vec4::Vec4(float _scalar)
		: x{ _scalar }, y{ _scalar }, z{ _scalar }, w{ _scalar }
	{
	}

	Vec4::Vec4(float _x, float _y, float _z, float _w)
		: x{ _x }, y{ _y }, z{ _z }, w{ _w }
	{
	}

	Vec4::Vec4(initializer_list<float> _values)
	{
		for (size_t i = 0; i < VEC_4_SIZE; ++i)
		{
		}
	}

	Vec4::Vec4(Vector4 _value)
		: x{ _value.x }, y{ _value.y }, z{ _value.z }, w{ _value.w }
	{
	}

	Vec4::Vec4(const Vec4& _other)
		: x{ _other.x }, y{ _other.y }, z{ _other.z }, w{ _other.w }
	{
	}

	Vec4::Vec4(Vec4&& _other) noexcept
		: x{ _other.x }, y{ _other.y }, z{ _other.z }, w{ _other.w }
	{
		_other.x = 0.f;
		_other.y = 0.f; 
		_other.z = 0.f;
		_other.w = 0.f;

	}

	Vec4::~Vec4() = default;

	Vec4 Vec4::Add(const Vec4& _lhs, const Vec4& _rhs)
	{
		return { _lhs.x + _rhs.x, _lhs.y + _rhs.y, _lhs.z + _rhs.z, _lhs.w + _rhs.w };
	}

	Vec4 Vec4::Subtract(const Vec4& _lhs, const Vec4& _rhs)
	{
		return { _lhs.x - _rhs.x, _lhs.y - _rhs.y, _lhs.z - _rhs.z, _lhs.w - _rhs.w };
	}

	Vec4 Vec4::Scale(const Vec4& _lhs, float _rhs)
	{
		return { _lhs.x * _rhs, _lhs.y * _rhs, _lhs.z * _rhs, _lhs.w * _rhs };
	}

	Vec4 Vec4::Normalised(const Vec4& _vec)
	{
		const float mag = _vec.Magnitude();

		if (Compare(mag, 0.f))
		{
			return Vec4{ 0.f, 0.f, 0.f, 0.f };
		}
		else
		{
			return Vec4{ _vec.x / mag, _vec.y / mag, _vec.z / mag, _vec.w / mag };
		}
	}

	float Vec4::Distance(const Vec4& _a, const Vec4& _b)
	{
		return (_a - _b).Magnitude();
	}

	float Vec4::Dot(const Vec4& _lhs, const Vec4& _rhs)
	{
		return (_lhs.x * _rhs.x) + (_lhs.y * _rhs.y) + (_lhs.z * _rhs.z) + (_lhs.w * _rhs.w);
	}

	Vec4 Vec4::Lerp(const Vec4& _a, const Vec4& _b, float _t)
	{
		return {};
	}

	float Vec4::Dot(const Vec4& _rhs) const
	{
		return (x * _rhs.x) + (y * _rhs.y) + (z * _rhs.z) + (w * _rhs.w);
	}

	Vec4 Vec4::Cross(const Vec4& _rhs)
	{
		return {};
	}

	float Vec4::Magnitude() const
	{
		return sqrt((x * x) + (y * y) + (z * z) + (w * w));
	}

	float Vec4::MagnitudeSqr() const
	{
		return (x * x) + (y * y) + (z * z) + (w * w);
	}

	void Vec4::Normalise()
	{
		const float mag = Magnitude();

		if (Compare(mag, 0.f))
		{
			x = 0.f;
			y = 0.f;
			z = 0.f;
			w = 0.f;
		}
		else
		{
			x = x / mag;
			y = y / mag;
			z = z / mag;
			w = w / mag;
		}

	}

	Vec4 Vec4::Normalised() const
	{
		const float mag = Magnitude();

		if (Compare(mag, 0.f))
		{
			return Vec4{ 0.f, 0.f, 0.f, 0.f };
		}
		else
		{
			return Vec4{ x / mag, y / mag, z / mag, w / mag };
		}
	}

	string Vec4::ToString() const
	{
		return string("(") + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + string("(");
	}

	Vec4::operator Vector4() const
	{
		return { x, y, z, w};
	}

	bool Vec4::operator==(const Vec4& _other) const
	{
		return Compare(x, _other.x) && Compare(y, _other.y) && Compare(z, _other.z) && Compare(w, _other.w);
	}

	bool Vec4::operator!=(const Vec4& _other) const
	{
		return !(*this == _other);
	}

	Vec4 Vec4::operator-(const Vec4& _other) const
	{
		return { x - _other.x, y - _other.y, z - _other.z, w - _other.w };
	}

	Vec4& Vec4::operator-=(const Vec4& _other)
	{
		x -= _other.x;
		y -= _other.y;
		z -= _other.z;
		w -= _other.w;

		return *this;
	}

	Vec4 Vec4::operator+(const Vec4& _other) const
	{
		return { x + _other.x, y + _other.y, z + _other.z, w + _other.w };
	}

	Vec4& Vec4::operator+=(const Vec4& _other)
	{
		x += _other.x; 
		y += _other.y; 
		z += _other.z;
		w += _other.w;

		return *this;
	}

	Vec4 Vec4::operator*(float _other) const
	{
		return { x * _other, y * _other, z * _other, w * _other };
	}

	Vec4& Vec4::operator*=(float _other)
	{
		x *= _other; 
		y *= _other; 
		z *= _other;
		w *= _other;

		return *this;
	}

	Vec4& Vec4::operator=(const Vec4& _other)
	{
		if (*this == _other)
			return *this;

		x = _other.x;
		y = _other.y;
		z = _other.z;
		w = _other.w;

		return *this;
	}

	Vec4& Vec4::operator=(Vec4&& _other) noexcept
	{
		if (*this == _other)
			return *this;

		x = _other.x;
		y = _other.y;
		z = _other.z;
		w = _other.w;

		_other.x = 0.f;
		_other.y = 0.f;
		_other.z = 0.f;
		_other.w = 0.f;

		return *this;
	}

	Vec4 operator*(float _lhs, const Vec4& _rhs)
	{
		return { _lhs * _rhs.x, _lhs * _rhs.y, _lhs * _rhs.z, _lhs * _rhs.w };
	}
}
