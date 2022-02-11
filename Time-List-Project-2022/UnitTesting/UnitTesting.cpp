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
		// TestsGenerator
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnBinaryRepresentationOfTwo)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Medium")
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

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnBinaryRepresentationOfFive)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Medium")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnBinaryRepresentationOfFive)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 0, 1 };

			// Act
			binary = eventGenerator.convertToBinary(5);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnBinaryRepresentationOfTen)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Medium")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnBinaryRepresentationOfTen)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 0, 1, 0 };

			// Act
			binary = eventGenerator.convertToBinary(10);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnBinaryRepresentationOfFiftyNine)
			TEST_OWNER(L"VNTeneva19")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(expectToReturnBinaryRepresentationOfFiftyNine)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 1, 1, 0, 1, 1};

			// Act
			binary = eventGenerator.convertToBinary(59);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnBinaryRepresentationOfOneHundredAndFour)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Medium")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnBinaryRepresentationOfOneHundredAndFour)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 1, 0, 1, 0, 0, 0 };

			// Act
			binary = eventGenerator.convertToBinary(104);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnBinaryRepresentationOfOneThousand)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Medium")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnBinaryRepresentationOfOneThousand)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 1, 1, 1, 1, 0, 1, 0, 0, 0 };

			// Act
			binary = eventGenerator.convertToBinary(1000);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnGrayCodeRepresentationOfFive)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Medium")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnGrayCodeRepresentationOfFive)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 1, 1 };

			// Act
			binary = eventGenerator.convertToGrayCode(5);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnGrayCodeRepresentationOfEight)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Medium")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnGrayCodeRepresentationOfEight)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 1, 0, 0 };

			// Act
			binary = eventGenerator.convertToGrayCode(8);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnGrayCodeRepresentationOfTwentyFive)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Medium")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnGrayCodeRepresentationOfTwentyFive)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 0, 1, 0, 1 };

			// Act
			binary = eventGenerator.convertToGrayCode(25);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnGrayCodeRepresentationOfOneHundredAndThirteen)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Medium")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnGrayCodeRepresentationOfOneHundredAndThirteen)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 0, 0, 1, 0, 0, 1 };

			// Act
			binary = eventGenerator.convertToGrayCode(113);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnGrayCodeRepresentationOfOneThousandAndThirtyFour)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("Medium")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnGrayCodeRepresentationOfOneThousandAndThirtyFour)
		{
			// Arrange
			EventGenerator eventGenerator;
			std::vector<int> binary;
			std::vector<int> expected = { 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1 };

			// Act
			binary = eventGenerator.convertToGrayCode(1034);

			// Assert
			for (size_t i = 0; i < binary.size(); i++)
			{
				Assert::AreEqual(expected[i], binary[i]);
			}

		}

		// SearchAnEvent
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnVariableNodeWhenCordinateYIsInRange)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("High")
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

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnZeroWhenCordinateYIsLessThanTwoHundredAndSeventy)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("High")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnZeroWhenCordinateYIsLessThanTwoHundredAndSeventy)
		{
			// Arrange
			int cordinateY = 260, node = 1;

			// Act
			int result = SearchAnEventNodes::TakeNodes::takeNodeIndex(cordinateY, node);

			// Assert
			Assert::AreEqual(0, result);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnVariableNodeWhenCordinateYIsGreaterThanThreeHundredAndTwenty)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("High")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnVariableNodeWhenCordinateYIsGreaterThanThreeHundredAndTwenty)
		{
			// Arrange
			int cordinateY = 350, node = 1;

			// Act
			int result = SearchAnEventNodes::TakeNodes::takeNodeIndex(cordinateY, node);

			// Assert
			Assert::AreEqual(2, result);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnZeroWhenCordinateYIsGreaterThanThreeHundredAndTwenty)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("High")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnZeroWhenCordinateYIsGreaterThanThreeHundredAndTwenty)
		{
			// Arrange
			int cordinateY = 330, node = 1;

			// Act
			int result = SearchAnEventNodes::TakeNodes::takeNodeIndex(cordinateY, node);

			// Assert
			Assert::AreEqual(0, result);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnZeroWhenHeadIsNull)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("High")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnZeroWhenHeadIsNull)
		{
			// Arrange
			Event* head = NULL;

			// Act
			int result = SearchAnEventNodes::TakeNodes::takeLastNodePos(head);

			// Assert
			Assert::AreEqual(0, result);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnTrueWhenCordinateYIsGreaterThanThreeHundredAndTwentyFive)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("High")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnTrueWhenCordinateYIsGreaterThanThreeHundredAndTwentyFive)
		{
			// Arrange
			int cordinateY = 350;

			// Act
			bool result = SearchAnEventNodes::TakeNodes::checkValidSpaces(cordinateY);

			// Assert
			Assert::AreEqual(true, result);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnTrueWhenCordinateYIsLessThanThreeHundredAndTwentyFive)
		TEST_OWNER(L"VNTeneva19")
		TEST_PRIORITY("High")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnTrueWhenCordinateYIsLessThanThreeHundredAndTwentyFive)
		{
			// Arrange
			int cordinateY = 250;

			// Act
			bool result = SearchAnEventNodes::TakeNodes::checkValidSpaces(cordinateY);

			// Assert
			Assert::AreEqual(true, result);
		}

	};
}
