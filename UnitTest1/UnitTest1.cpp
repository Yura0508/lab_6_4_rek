#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_6_4_rek/lab_6_4_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(MaxTest)
        {
            int arr[] = { 1, 3, 5, 7, 9 };
            int index;
            int max = Max(arr, 5, 0, arr[0], index);
            Assert::AreEqual(max, 9);
            Assert::AreEqual(index, 4);
        }

        TEST_METHOD(ProductBetweenZerosTest)
        {
            int arr1[] = { 1, 0, 2, 3, 0, 4 };
            Assert::AreEqual(ProductBetweenZeros(arr1, 6), 6); // 2 * 3

            int arr2[] = { 0, 0, 2, 5 };
            Assert::AreEqual(ProductBetweenZeros(arr2, 4), 0); // No elements between zeros

            int arr3[] = { 1, 2, 3 };
            Assert::AreEqual(ProductBetweenZeros(arr3, 3), 0); // No zeros
        }

        TEST_METHOD(AddOddEvenIndexedTest)
        {
            int arr[] = { 0, 1, 2, 3, 4, 5 };
            int* separatedArray = new int[6]; // Максимальний розмір
            int index = 0;

            AddOddIndexed(arr, 6, separatedArray, index, 0);
            AddEvenIndexed(arr, 6, separatedArray, index, 0);

            // Expected: {1, 3, 5, 0, 2, 4}
            Assert::AreEqual(separatedArray[0], 1);
            Assert::AreEqual(separatedArray[1], 3);
            Assert::AreEqual(separatedArray[2], 5);
            Assert::AreEqual(separatedArray[3], 0);
            Assert::AreEqual(separatedArray[4], 2);
            Assert::AreEqual(separatedArray[5], 4);

            delete[] separatedArray; // Очищення пам'яті
        }
	};
}
