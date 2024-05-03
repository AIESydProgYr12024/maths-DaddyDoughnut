#pragma once

#include "Vec2.h"
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
				

				float m1;  // 11
				float m2;  // 21
				float m3;  // 31
				float m4;  // 41
				float m5;  // 12
				float m6;  // 22
				float m7;  // 32
				float m8;  // 42
				float m9;  // 13
				float m10; // 23
				float m11; // 33
				float m12; // 43
				float m13; // 14
				float m14; // 24
				float m15; // 34
				float m16; // 44
			};
			// 11 12 13 14
			// 21 22 23 24
			// 31 32 33 34
			// 41 42 43 44
			float data[MAT_4_SIZE];
		};

	public:
		Mat4();
		Mat4(float _scalar);
		Mat4(float _m1, float _m5, float _m9, float _m13,
			float _m2, float _m6, float _m10, float _m14,
			float _m3, float _m7, float _m11, float _m15,
			float _m4, float _m8, float _m12, float _m16);
		Mat4(float _matrix[MAT_4_SIZE]);

		Mat4(const Mat4& _other);
		Mat4(Mat4&& _other) noexcept;

		~Mat4();

	public:
		static Mat4 CreateTranslation(const Vec3& _trans);
		static Mat4 CreateTranslation(float _x, float _y, float _z);
				  
		static Mat4 CreateScale(const Vec3& _scale);
		static Mat4 CreateScale(float _x, float _y, float _z);
				  
		static Mat4 CreateXRotation(float _rot);
		static Mat4 CreateYRotation(float _rot);
		static Mat4 CreateZRotation(float _rot);
				  
		static Mat4 CreateEulerRotation(float _x, float _y, float _z);
		static Mat4 CreateEulerRotation(const Vec3& _euler);
				  
		static Mat4 Identity();

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

		Vec4 Transposed();

		string ToString() const;
	public:
		Mat4 operator*(const Mat4& _rhs) const;
		Vec4 operator*(const Vec4& _rhs) const;

		bool operator==(const Mat4& _other) const;
		bool operator!=(const Mat4& _other) const;

		Mat4& operator=(const Mat4& _other);
		Mat4& operator=(Mat4&& _other) noexcept;

	};
}