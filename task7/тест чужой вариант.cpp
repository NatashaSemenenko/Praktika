#include "pch.h"
#include "CppUnitTest.h"
#include "..\пр7\пр7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(PerimeterOperationsTests)
    {
    public:
        // Тест 1: квадрат
        TEST_METHOD(TestSquarePerimeter_ValidInput_ReturnsCorrectValue)
        {
            double a = 5.0;
            double result = PerimeterOperations::squarePerimeter(a);
            Assert::AreEqual(20.0, result, 0.0001);
        }
    };
}