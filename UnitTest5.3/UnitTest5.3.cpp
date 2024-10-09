#include "pch.h"
#include "CppUnitTest.h"
#include "../LabAP5.3.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 // Correcting the namespace declaration
{
    // Factorial function defined outside the test class
    int factorial(int n) {
        int fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestF_GreaterThanOrEqualTo1)
        {
            double x = 1.0;
            double expected = cos(x / 2) / (1 + pow(sin(x), 2));
            double result = f(x);
            Assert::AreEqual(expected, result, 0.0001);
        }

        TEST_METHOD(TestF_LessThan1)
        {
            double x = 0.5;
            double expected = 0.0;  // Initialize expected to 0.0
            double a = 1.0;  // Starting term for the series

            // Calculate expected value using the series logic
            for (int i = 0; i < 6; ++i)
            {
                expected += a;
                a *= (pow(x, 3) / (factorial(2 * (i + 1))));
            }

            double result = f(x);
            Assert::AreEqual(expected, result, 0.0001);
        }
    };
}
