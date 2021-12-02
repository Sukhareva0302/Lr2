#include "pch.h"
#include "CppUnitTest.h"
#include "..\ConsoleApplication1\ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_BinarySearch)
		{
			int array[10];
			for (int i = 0; i < 10; i++) //0 1 2 3 4 5 6 7 8 9
			{
				array[i] = i;
			}
			Assert::AreEqual(BinarySearch(0, 10, array), 0);
			Assert::AreEqual(BinarySearch(6, 10, array), 6);
			Assert::AreEqual(BinarySearch(9, 10, array), 9);
			bool check_invalid_argurent=false;
			try
			{
				BinarySearch(66, 10, array);
			}
			catch (invalid_argument)
			{
				check_invalid_argurent = true;
			}
			Assert::IsTrue(check_invalid_argurent);
		}
		TEST_METHOD(Test_QuickSort)
		{
			int array[10];
			for (int i = 9; i >= 0; i--)
			{
				array[i] = i;
			}
			QuickSort(array, 0, 9);
			Assert::AreEqual(array[0], 0);
			Assert::AreEqual(array[1], 1);
			Assert::AreEqual(array[2], 2);
			Assert::AreEqual(array[3], 3);
			Assert::AreEqual(array[4], 4);
			Assert::AreEqual(array[5], 5);
			Assert::AreEqual(array[6], 6);
			Assert::AreEqual(array[7], 7);
			Assert::AreEqual(array[8], 8);
			Assert::AreEqual(array[9], 9);
		}
		TEST_METHOD(Test_InsertionSort)
		{
			int array[10];
			for (int i = 9; i >= 0; i--)
			{
				array[i] = i;
			}
			InsertionSort(10, array);
			Assert::AreEqual(array[0], 0);
			Assert::AreEqual(array[1], 1);
			Assert::AreEqual(array[2], 2);
			Assert::AreEqual(array[3], 3);
			Assert::AreEqual(array[4], 4);
			Assert::AreEqual(array[5], 5);
			Assert::AreEqual(array[6], 6);
			Assert::AreEqual(array[7], 7);
			Assert::AreEqual(array[8], 8);
			Assert::AreEqual(array[9], 9);
		}
		TEST_METHOD(Test_BogoSort)
		{
			int array[10];
			for (int i = 9; i >= 0; i--)
			{
				array[i] = i;
			}
			BogoSort(10, array);
			Assert::AreEqual(array[0], 0);
			Assert::AreEqual(array[1], 1);
			Assert::AreEqual(array[2], 2);
			Assert::AreEqual(array[3], 3);
			Assert::AreEqual(array[4], 4);
			Assert::AreEqual(array[5], 5);
			Assert::AreEqual(array[6], 6);
			Assert::AreEqual(array[7], 7);
			Assert::AreEqual(array[8], 8);
			Assert::AreEqual(array[9], 9);
		}
		TEST_METHOD(Test_CountingSort)
		{
			char array[10];// should be (()).ABTTc
			array[0] = '(';
			array[1] = 'T';
			array[2] = '.';
			array[3] = 'T';
			array[4] = ')';
			array[5] = '(';
			array[6] = 'A';
			array[7] = 'B';
			array[8] = 'c';
			array[9] = ')';
			CountingSort(10, array);
			Assert::AreEqual(array[0], '(');
			Assert::AreEqual(array[1], '(');
			Assert::AreEqual(array[2], ')');
			Assert::AreEqual(array[3], ')');
			Assert::AreEqual(array[4], '.');
			Assert::AreEqual(array[5], 'A');
			Assert::AreEqual(array[6], 'B');
			Assert::AreEqual(array[7], 'T');
			Assert::AreEqual(array[8], 'T');
			Assert::AreEqual(array[9], 'c');
		}
	};
}
