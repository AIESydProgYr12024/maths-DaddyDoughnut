#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathLib/Types/Mat4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::MathLib::Mat4;
using ::MathLib::Vec3;

namespace MathLibraryTests
{
	TEST_CLASS(Mat4TransformTests)
	{
	public:
		// make trans from floats
		TEST_METHOD(MakeTranslationFloats)
		{
			Mat4 actual = Mat4::CreateTranslation(2.0f, 3.0f, 4.0f);

			Assert::AreEqual(
				Mat4(1, 0, 0, 2.f,
					0, 1, 0, 3.f,
					0, 0, 1, 4.f,
					0, 0.f, 0.f, 1), actual);
		}
		// make trans from vector
		TEST_METHOD(MakeTranslationVector)
		{
			Mat4 actual = Mat4::CreateTranslation(Vec3(2.0f, 3.0f, 4.0f));

			Assert::AreEqual(
				Mat4(1, 0, 0, 2.f,
					0, 1, 0, 3.f,
					0, 0, 1, 4.f,
					0, 0.f, 0.f, 1), actual);
		}
		// make rotX from float
		TEST_METHOD(MakeRotateXFloat)
		{
			Mat4 actual = Mat4::CreateXRotation(4.5f);

			Assert::AreEqual(
				Mat4(1, 0, 0, 0,
				0, -0.210796f, 0.97753f, 0,
				0, -0.97753f, -0.210796f, 0,
				0, 0, 0, 1), actual);
		}
		// make rotY from float
		TEST_METHOD(MakeRotateYFloat)
		{
			Mat4 actual = Mat4::CreateYRotation(-2.6f);

			Assert::AreEqual(
				Mat4(-0.856889f, 0, -0.515501f, 0,
				0, 1, 0, 0,
				0.515501f, 0, -0.856889f, 0,
				0, 0, 0, 1), actual);
		}
		// make rotZ from float
		TEST_METHOD(MakeRotateZFloat)
		{
			Mat4 actual = Mat4::CreateZRotation(0.72f);

			Assert::AreEqual(
				Mat4(0.751806f, -0.659385f, 0, 0,
					0.659385f, 0.751806f, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1), actual);
		}
		// make rot from euler (floats)
		TEST_METHOD(MakeRotateEulerFloat)
		{
			Mat4 actual = Mat4::CreateEulerRotation(Vec3(1.0f, 2.0f, 3.0f));

			Assert::AreEqual(
				Mat4(0.998021f, -0.051720f, 0.035760f, 0.0f,
					0.052304f, 0.998509f, -0.015602f, 0.0f,
					-0.034899f, 0.017442f, 0.999239f,
					0.0f, 0.0f, 0.0f, 0.0f, 1.0f),
				actual);
		}
		// make rot from euler (vector)
		TEST_METHOD(MakeRotateEulerVector)
		{
			Mat4 actual = Mat4::CreateEulerRotation(Vec3(1.0f, 2.0f, 3.0f));

			Assert::AreEqual(
				Mat4(0.998021f, -0.051720f, 0.035760f, 0.0f,
					0.052304f, 0.998509f, -0.015602f, 0.0f,
					-0.034899f, 0.017442f, 0.999239f,
					0.0f, 0.0f, 0.0f, 0.0f, 1.0f),
				actual);
		}
		// make scale from floats
		TEST_METHOD(MakeScaleFloat3D)
		{
			Mat4 actual = Mat4::CreateScale(2.0f, 3.0f, 4.0f);

			Assert::AreEqual(
				Mat4(2.0f, 0, 0, 0,
				0, 3.0f, 0, 0,
				0, 0, 4.0f, 0,
				0, 0, 0, 1), actual);

		}
		// make scale from vector
		TEST_METHOD(MakeScaleVec3)
		{
			Mat4 actual = Mat4::CreateScale(Vec3(2.0f, 3.0f, 4.0f));

			Assert::AreEqual(
				Mat4(2.0f, 0, 0, 0,
					0, 3.0f, 0, 0,
					0, 0, 4.0f, 0,
					0, 0, 0, 1), actual);
		}
	};
}
