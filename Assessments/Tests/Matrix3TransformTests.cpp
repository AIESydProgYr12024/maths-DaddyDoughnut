#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathLib/Types/Mat3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::MathLib::Mat3;
using ::MathLib::Vec3;

namespace MathLibraryTests
{
	TEST_CLASS(Mat3TransformTests)
	{
	public:
		// make trans from floats
		TEST_METHOD(MakeTranslationFloats)
		{
			Mat3 actual = Mat3::CreateTranslation(1.2f, 3.4f, 1.0f);

			Assert::AreEqual(
				Mat3(
					1.0f, 0.0f, 1.2f,
					0.0f, 1.0f, 3.4f,
					0.f, 0.f, 1.0f),
				actual);
		}
		// make trans from vector
		TEST_METHOD(MakeTranslationVector)
		{
			Mat3 actual = Mat3::CreateTranslation(Vec3{ 1.2f, 3.4f, 1.0f });

			Assert::AreEqual(
				Mat3(
					1.0f, 0.0f, 1.2f,
					0.0f, 1.0f, 3.4f,
					0.f, 0.f, 1.0f),
				actual);
		}
		// make rotX from float
		TEST_METHOD(MakeRotateXFloat)
		{
			Mat3 actual = Mat3::CreateXRotation(3.98f);

			Assert::AreEqual(
				Mat3(
					1, 0, 0,
					0, -0.668648f, 0.743579f,
					0, -0.743579f, -0.668648f),
				actual);
		}
		// make rotY from float
		TEST_METHOD(MakeRotateYFloat)
		{
			Mat3 actual = Mat3::CreateYRotation(1.76f);

			Assert::AreEqual(
				Mat3(
					-0.188077f, 0, 0.982154f,
					0, 1, 0,
					-0.982154f, 0, -0.188077f),
				actual);
		}
		// make rotZ from float
		TEST_METHOD(MakeRotateZFloat)
		{
			Mat3 actual = Mat3::CreateZRotation(9.62f);

			Assert::AreEqual(
				Mat3(-0.981005f, 0.193984f, 0.f, 
					-0.193984f, -0.981005f, 0.f, 
					0.f, 0.f, 1.f),
				actual);
		}
		// make rot from euler (floats)
		TEST_METHOD(MakeRotateEulerFloat)
		{
			Mat3 actual = Mat3::CreateEulerRotation(1.0f, 2.0f, 3.0f);

			Assert::AreEqual(
				Mat3(0.998021f, -0.051720f, 0.035760f,
					0.052304f, 0.998509f, -0.015602f,
					-0.034899f, 0.017442f, 0.999239f),
				actual);
		}
		// make rot from euler (vector)
		TEST_METHOD(MakeRotateEulerVector)
		{
			Mat3 actual = Mat3::CreateEulerRotation({ 1.0f, 2.0f, 3.0f });

			Assert::AreEqual(
				Mat3(0.998021f, -0.051720f, 0.035760f,
					0.052304f, 0.998509f, -0.015602f,
					-0.034899f, 0.017442f, 0.999239f),
				actual);

		}
		// make scale from floats
		TEST_METHOD(MakeScaleFloat2D)
		{
			Mat3 actual = Mat3::CreateScale(MathLib::Vec2{ 2.0f, 3.0f });

			Assert::AreEqual(
				Mat3(2.0f, 0.0f, 0.0f,
						0.0f, 3.0f, 0.0f,
						0.0f, 0.0f, 1.0f), actual);
		}
		// make scale from floats
		TEST_METHOD(MakeScaleFloat3D)
		{
			Mat3 actual = Mat3::CreateScale(Vec3{ 2.0f, 3.0f, 4.0f });

			Assert::AreEqual(
				Mat3(2.0f, 0.0f, 0.0f,
					0.0f, 3.0f, 0.0f,
					0.0f, 0.0f, 4.0f), actual);
		}
		// make scale from vector
		TEST_METHOD(MakeScaleVec3)
		{
			Mat3 actual = Mat3::CreateScale(Vec3{ 2.0f, 3.0f, 4.0f });

			Assert::AreEqual(
				Mat3(2.0f, 0.0f, 0.0f,
					0.0f, 3.0f, 0.0f,
					0.0f, 0.0f, 4.0f), actual);
		}
	};
}
