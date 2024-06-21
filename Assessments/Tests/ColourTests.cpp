#include "CppUnitTest.h"
#include "TestToString.h"

#include "Utils.h"
#include "MathLib/Types/Colour.h"
#include <UnitTestLib.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::MathLib::Colour;
using ::UnitLib::Byte;

namespace MathLibraryTests
{
	TEST_CLASS(ColourTests)
	{
	public:
		// default constructor
		TEST_METHOD(ColourDefaultConstructor)
		{
			Colour actual;
			Assert::AreEqual( Colour(0, 0, 0, 255).value, actual.value ); 
		}

		// parameterized constructor
		TEST_METHOD(ColourParamConstructor)
		{
			Colour actual{ 32, 64, 10, 255 };

			Assert::AreEqual( Colour(32, 64, 10, 255).value, actual.value);
		}

		// Check equality method
		TEST_METHOD(ColourEqualityOperator)
		{
			Colour actual;
			Assert::IsTrue( Colour(0, 0, 0, 255) == actual);
		}

		// setting r
		TEST_METHOD(SetRed)
		{
			Colour actual(32, 64, 10, 255);
			actual.SetRed(128);
			Assert::AreEqual( Colour(128, 64, 10, 255).value, actual.value);
		}
		
		// setting g
		TEST_METHOD(SetGreen)
		{
			Colour actual(32, 64, 10, 255);
			actual.SetGreen(128);
			Assert::AreEqual(Colour(32, 128, 10, 255).value, actual.value);
		}

		// setting b
		TEST_METHOD(SetBlue)
		{
			Colour actual(32, 64, 10, 255);
			actual.SetBlue(128);
			Assert::AreEqual(Colour(32, 64, 128, 255).value, actual.value);
		}

		// setting a
		TEST_METHOD(SetAlpha)
		{
			Colour actual(32, 64, 10, 255);
			actual.SetAlpha(128);
			Assert::AreEqual(Colour(32, 64, 10, 128).value, actual.value);
		}
		// Get Red
		TEST_METHOD(GetRed)
		{
			const Colour actual(32, 64, 10, 255);
			const uint8_t red = actual.Red();
			Assert::AreEqual(red, static_cast<uint8_t>(32));
		}
		// Get Green
		TEST_METHOD(GetGreen)
		{
			const Colour actual(32, 64, 10, 255);
			const uint8_t green = actual.Green();
			Assert::AreEqual(green, static_cast<uint8_t>(64));
		}
		// Get Blue
		TEST_METHOD(GetBlue)
		{
			const Colour actual(32, 64, 10, 255);
			const uint8_t blue = actual.Blue();
			Assert::AreEqual(blue, static_cast<uint8_t>(10));
		}
		// Get Alpha
		TEST_METHOD(GetAlpha)
		{
			const Colour actual(32, 64, 0, 255);
			const uint8_t alpha = actual.Alpha();
			Assert::AreEqual(alpha, static_cast<uint8_t>(255));
		}
	};
}
