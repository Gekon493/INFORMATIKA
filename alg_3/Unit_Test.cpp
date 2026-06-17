#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "C:\\Users\\user\\source\\repos\\ConsoleApplication8\\ConsoleApplication8.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(CombSortTests)
    {
    public:
        TEST_METHOD(TestCombSort_RegularArray)
        {
            std::vector<int> arr = { 64,34,25,12,22,11,90 };
            std::vector<int> expected = { 11,12,22,25,34,64,90 };
            combSort(arr);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestCombSort_AlreadySorted)
        {
            std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
            std::vector<int> expected = { 1,2,3,4,5,6,7,8,9,10 };
            combSort(arr);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestCombSort_ReverseSorted)
        {
            std::vector<int> arr = { 10,9,8,7,6,5,4,3,2,1 };
            std::vector<int> expected = { 1,2,3,4,5,6,7,8,9,10 };
            combSort(arr);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestCombSort_AllEqual)
        {
            std::vector<int> arr = { 5,5,5,5,5,5 };
            std::vector<int> expected = { 5,5,5,5,5,5 };
            combSort(arr);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestCombSort_SingleElement)
        {
            std::vector<int> arr = { 42 };
            combSort(arr);
            Assert::AreEqual(42, arr[0]);
        }
        TEST_METHOD(TestCombSort_EmptyArray)
        {
            std::vector<int> arr = {};
            combSort(arr);
            Assert::AreEqual((size_t)0, arr.size());
        }
        TEST_METHOD(TestCombSort_TwoElements)
        {
            std::vector<int> arr = { 2,1 };
            combSort(arr);
            Assert::AreEqual(1, arr[0]);
            Assert::AreEqual(2, arr[1]);
        }
    };

    TEST_CLASS(MergeSortTests)
    {
    public:
        TEST_METHOD(TestMergeSort_RegularArray)
        {
            std::vector<int> arr = { 64,34,25,12,22,11,90 };
            std::vector<int> expected = { 11,12,22,25,34,64,90 };
            mergeSort(arr, 0, (int)arr.size() - 1);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestMergeSort_AlreadySorted)
        {
            std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
            std::vector<int> expected = { 1,2,3,4,5,6,7,8,9,10 };
            mergeSort(arr, 0, (int)arr.size() - 1);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestMergeSort_ReverseSorted)
        {
            std::vector<int> arr = { 10,9,8,7,6,5,4,3,2,1 };
            std::vector<int> expected = { 1,2,3,4,5,6,7,8,9,10 };
            mergeSort(arr, 0, (int)arr.size() - 1);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestMergeSort_AllEqual)
        {
            std::vector<int> arr = { 5,5,5,5,5,5 };
            std::vector<int> expected = { 5,5,5,5,5,5 };
            mergeSort(arr, 0, (int)arr.size() - 1);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestMergeSort_SingleElement)
        {
            std::vector<int> arr = { 42 };
            mergeSort(arr, 0, 0);
            Assert::AreEqual(42, arr[0]);
        }
        TEST_METHOD(TestMergeSort_EmptyArray)
        {
            std::vector<int> arr = {};
            Assert::AreEqual((size_t)0, arr.size());
        }
        TEST_METHOD(TestMergeSort_TwoElements)
        {
            std::vector<int> arr = { 2,1 };
            mergeSort(arr, 0, 1);
            Assert::AreEqual(1, arr[0]);
            Assert::AreEqual(2, arr[1]);
        }
    };

    TEST_CLASS(QuickSortTests)
    {
    public:
        TEST_METHOD(TestQuickSort_RegularArray)
        {
            std::vector<int> arr = { 64,34,25,12,22,11,90 };
            std::vector<int> expected = { 11,12,22,25,34,64,90 };
            if (!arr.empty()) quickSort(arr, 0, (int)arr.size() - 1);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestQuickSort_AlreadySorted)
        {
            std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
            std::vector<int> expected = { 1,2,3,4,5,6,7,8,9,10 };
            if (!arr.empty()) quickSort(arr, 0, (int)arr.size() - 1);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestQuickSort_ReverseSorted)
        {
            std::vector<int> arr = { 10,9,8,7,6,5,4,3,2,1 };
            std::vector<int> expected = { 1,2,3,4,5,6,7,8,9,10 };
            if (!arr.empty()) quickSort(arr, 0, (int)arr.size() - 1);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestQuickSort_AllEqual)
        {
            std::vector<int> arr = { 5,5,5,5,5,5 };
            std::vector<int> expected = { 5,5,5,5,5,5 };
            if (!arr.empty()) quickSort(arr, 0, (int)arr.size() - 1);
            for (size_t i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
        TEST_METHOD(TestQuickSort_SingleElement)
        {
            std::vector<int> arr = { 42 };
            quickSort(arr, 0, 0);
            Assert::AreEqual(42, arr[0]);
        }
        TEST_METHOD(TestQuickSort_EmptyArray)
        {
            std::vector<int> arr = {};
            Assert::AreEqual((size_t)0, arr.size());
        }
        TEST_METHOD(TestQuickSort_TwoElements)
        {
            std::vector<int> arr = { 2,1 };
            quickSort(arr, 0, 1);
            Assert::AreEqual(1, arr[0]);
            Assert::AreEqual(2, arr[1]);
        }
    };
}
