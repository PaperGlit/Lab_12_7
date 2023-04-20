#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_7/Lab_12_7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab127
{
	TEST_CLASS(UnitTestLab127)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first1 = NULL, *first2 = NULL, *last1 = NULL, *last2 = NULL, *first3 = NULL, *last3 = NULL;
			for (int i = 1; i <= 5; i++)
				enqueue(first1, last1, i);
			for (int j = 6; j <= 10; j++)
				enqueue(first2, last2, j);
			concat(first1, first2);
			for (int k = 1; k <= 10; k++)
			{
				Assert::AreEqual(first1->info, k);
				first1 = first1->link;
			}
		}
	};
}
