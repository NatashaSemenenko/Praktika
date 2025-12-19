#include "pch.h"
#include "CppUnitTest.h"
#include "..\task7\task7.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(PowerRootOperationsTests)
    {
    public:

        // Позитивный тест: square
        TEST_METHOD(TestSquare_Positive)
        {
            double value = 3.0;
            double expected = 9.0;
            double result = PowerRootOperations::square(value);
            Assert::AreEqual(expected, result, 0.0001);
        }

        // Позитивный тест: nthRoot (кубический корень)
        TEST_METHOD(TestNthRoot_Positive)
        {
            double value = 27.0;
            double n = 3.0;
            double expected = 3.0;
            double result = PowerRootOperations::nthRoot(value, n);
            Assert::AreEqual(expected, result, 0.0001);
        }

        // Негативный тест: корень из отрицательного значения (чётная степень)
        TEST_METHOD(TestNthRoot_NegativeNumber_ThrowsException)
        {
            // Arrange: Пытаемся извлечь квадратный корень (2) из -16
            double number = -16.0;
            double n = 2.0;
            Assert::ExpectException<std::invalid_argument>(
                [this, number, n]() {
                    // Это действие должно вызвать ошибку
                    PowerRootOperations::nthRoot(number, n);
                }
            );
        }

        // Негативный тест: корень нулевой степени
        TEST_METHOD(TestNthRoot_ZeroDegree_ThrowsException)
        {
            // Arrange: Пытаемся извлечь корень 0-й степени (математически невозможно по формуле 1/n)
            double number = 10.0;
            double n = 0.0;

            // Assert: Ожидаем исключение
            Assert::ExpectException<std::invalid_argument>(
                [this, number, n]() {
                    PowerRootOperations::nthRoot(number, n);
                }
            );
        }
    };
}