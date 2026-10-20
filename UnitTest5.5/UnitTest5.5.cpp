#include "pch.h"
#include "CppUnitTest.h"
#include "../5.5/5.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55
{
	TEST_CLASS(UnitTest55)
	{
	public:
		
		TEST_METHOD_INITIALIZE(ResetCounters)
		{
			current_depth = 0;
			max_depth = 0;
			total_calls = 0;
		}

		TEST_METHOD(Test_A0_0)
		{
			int result = A(0, 0);

			Assert::AreEqual(1, result);       
			Assert::AreEqual(1, max_depth);     
			Assert::AreEqual(1LL, total_calls); 
		}
		TEST_METHOD(Test_A1_0)
		{
			int result = A(1, 0);

			Assert::AreEqual(2, result);        
			Assert::AreEqual(2, max_depth);    
			Assert::AreEqual(2LL, total_calls); 
		}
		TEST_METHOD(Test_A1_2)
		{
			int result = A(1, 2);

			Assert::AreEqual(4, result);        
			Assert::AreEqual(4, max_depth);    
			Assert::AreEqual(6LL, total_calls); 
		}

	};
}
