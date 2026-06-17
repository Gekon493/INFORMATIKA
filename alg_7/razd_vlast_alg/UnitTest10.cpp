#include "pch.h"
#include "CppUnitTest.h"
#include "C:\\Users\\user\\source\\repos\\ConsoleApplication13\\ConsoleApplication13.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMaxSubarray
{
    TEST_CLASS(UnitTestMaxSubarray)
    {
    public:
        TEST_METHOD(Test_Example)
        {
            vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5 };
            int result = maxSubarraySum(arr, 0, arr.size() - 1);
            Assert::AreEqual(6, result);
        }

        TEST_METHOD(Test_AllPositive)
        {
            vector<int> arr = { 1, 2, 3, 4, 5 };
            int result = maxSubarraySum(arr, 0, arr.size() - 1);
            Assert::AreEqual(15, result);
        }
    };
}