#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2_5/Pair.h"
#include "../lab2_5/Rational.h"
#include "../lab2_5/Pair.cpp"
#include "../lab2_5/Rational.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Pair p1(5, 10);
			Assert::AreEqual(5, p1.getFirst());
			Assert::AreEqual(10, p1.getSecond());

			Pair p2;
			Assert::AreEqual(0, p2.getFirst());
			Assert::AreEqual(0, p2.getSecond());
		}
	};
}
