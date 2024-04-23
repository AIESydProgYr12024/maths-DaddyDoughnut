#pragma once

#include "Vec3.h"
#include "Vec4.h"

#define MAT_4_SIZE (VEC_4_SIZE * VEC_4_SIZE)

namespace MathLib
{
	class Mat4
	{
	public:
		union
		{
			struct
			{
				float m1;
				float m2;
				float m3;
				float m4;
				float m5;
				float m6;
				float m7;
				float m8;
				float m9;
				float m10;
				float m11;
				float m12;
				float m13;
				float m14;
				float m15;
				float m16;
			};

			float data[MAT_4_SIZE];
		};

	public:
		Mat4();
		Mat4(float _scalar);
		Mat4(float _m1, float _m5, float _m9, float _m13,
			float _m2, float _m6, float _m10, float _m14,
			float _m3, float _m7, float _m11, float _m15,
			float _m4, float _m8, float _m12, float _m16);

		Mat4(const Mat4& _other);
		Mat4(Mat4&& _other) noexcept;

		~Mat4();

	public:
		void SetRotationX(float _rot);
		float GetRotationX() const;

		void SetRotationY(float _rot);
		float GetRotationY() const;

		void SetRotationZ(float _rot);
		float GetRotationZ() const;

		void SetTranslation(const Vec3& _trans);
		void Translate(const Vec3& _trans);
		Vec3 GetTranslation();

	public:
		Mat4 operator*(const Mat4& _rhs) const;
		Vec4 operator*(const Vec4& _rhs) const;

		bool operator==(const Mat4& _other) const;
		bool operator!=(const Mat4& _other) const;

		Mat4& operator=(const Mat4& _other);
		Mat4& operator=(Mat4&& _other) noexcept;

	};
}