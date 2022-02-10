#include "pch.h"
#include "CppUnitTest.h"
#include "../Time-List-Project-2022/Event Data Management/Header Files/TestsGenerator.h"
#include "../Time-List-Project-2022/Event Data Management/Header Files/SearchAnEvent.h"
//#include "../Time-List-Project-2022/Event Data Management/CPP Files/SearchAnEvent.cpp"
//#include "../Time-List-Project-2022/Event Data Management/CPP Files/TestsGenerator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
		
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnNodeIndexWhenCordinateYIsInRange)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnVariableNodeWhenCordinateYIsInRange)
		{
			// Arrange
			int cordinateY = 295, node = 1;

			// Act
			int result = SearchAnEventNodes::TakeNodes::takeNodeIndex(cordinateY, node);

			// Assert
			Assert::AreEqual(1, result);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnBinaryRepresentationOfTwo)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnBinaryRepresentationOfTwo)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 0 };

			// Act
			binary = eventGenerator.convertToBinary(2);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}
			
		}
	};
}
