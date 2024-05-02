#pragma once

#include <raylib/raylib.h>

#include <string>
#include <initializer_list>

using std::string;
using std::initializer_list;

#define VEC_4_SIZE 4

namespace MathLib
{
	class Vec4
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};

			float data[VEC_4_SIZE];
		};
	public:
		static Vec4 one;
		static Vec4 zero;
		static Vec4 half;
		static Vec4 up;
		static Vec4 down;
		static Vec4 left;
		static Vec4 right;
		static Vec4 forward;
		static Vec4 back;

	public:
		Vec4();
		Vec4(float _scalar);
		Vec4(float _x, float _y, float _z, float _w);
		Vec4(initializer_list<float> _values);
		Vec4(Vector4 _value);

		Vec4(const Vec4& _other);
		Vec4(Vec4&& _other) noexcept;

		~Vec4();

	public:
		static Vec4 Add(const Vec4& _lhs, const Vec4& _rhs);
		static Vec4 Subtract(const Vec4& _lhs, const Vec4& _rhs);
		static Vec4 Scale(const Vec4& _lhs, float _rhs);

		static Vec4 Normalised(const Vec4& _vec);
		static float Distance(const Vec4& _a, const Vec4& _b);

		static float Dot(const Vec4& _lhs, const Vec4& _rhs);

		static Vec4 Lerp(const Vec4& _a, const Vec4& _b, float _t);

	public:
		float Dot(const Vec4& _rhs) const;

		float Magnitude() const;
		float MagnitudeSqr() const;

		void Normalise();
		Vec4 Normalised() const;

		string ToString() const;

	public:
		operator Vector4() const;

		bool operator ==(const Vec4& _other) const;
		bool operator !=(const Vec4& _other) const;

		Vec4 operator -(const Vec4& _other) const;
		Vec4& operator -=(const Vec4& _other);

		Vec4 operator +(const Vec4& _other) const;
		Vec4& operator +=(const Vec4& _other);

		Vec4 operator *(float _other) const;
		Vec4& operator *=(float _other);

		Vec4& operator=(const Vec4& _other);
		Vec4& operator=(Vec4&& _other) noexcept;

	};

	extern Vec4 operator*(float _lhs, const Vec4& _rhs);
}