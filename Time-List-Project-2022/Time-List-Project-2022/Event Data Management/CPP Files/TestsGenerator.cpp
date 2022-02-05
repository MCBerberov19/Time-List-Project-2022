#include "../Header Files/TestsGenerator.h"
#include "../Header Files/SearchAnEvent.h"
#include <stdlib.h>
#include <iostream>

EventGenerator::EventGenerator(Event* entireFile, int(*takeLastNodePos)(Event*))
{
	std::map<std::string, std::string> data = generateRandomNode(entireFile, takeLastNodePos);

	this->title = data["Title"]; 
	this->topic = data["Topic"]; 
	this->grayYear = convertToGrayCode(stoi(data["Year"]));
}

std::map<std::string, std::string> EventGenerator::generateRandomNode(Event* entireFile, int(*takeLastNodePos)(Event*))
{
	int node = rand() % takeLastNodePos(entireFile);
	int i = 0;
	std::map<std::string, std::string> data;

	while (entireFile != NULL)
	{
		if (node == i)
		{
			data = {
				{"Title", entireFile->title},
				{"Topic", entireFile->topic},
				{"Year", std::to_string(entireFile->year)}
				};

			break;
		}
		entireFile = entireFile->nextEvent;
		i++;
	}

	return data;
}

std::vector<int> EventGenerator::convertToBinary(int decNum)
{
	std::vector<int> binary;
	while (decNum > 0)
	{
		binary.push_back(decNum % 2);
		decNum /= 2;
	}
	reverse(binary.begin(), binary.end());

	return binary;
}

std::vector<int> EventGenerator::convertToGrayCode(int decNum)
{
	std::vector<int> binary = convertToBinary(decNum);
	std::vector<int> gray;

	gray.push_back(binary[0]);

	for (size_t i = 1; i < binary.size(); i++)
	{
		gray.push_back(binary[i - 1] ^ binary[i]);
	}

	return gray;
}

void printV(std::vector<int> v1)
{
	for (int i : v1)
	{
		std::cout << i;
	}
	std::cout << std::endl;
}

std::vector<int> EventGenerator::convertToBinaryFromGray()
{
	std::vector<int> bin;
	bin.push_back(this->grayYear[0]);

	for (size_t i = 1; i < this->grayYear.size(); i++)
	{
		bin.push_back(bin[i - 1] ^ grayYear[i]);
	}

	reverse(bin.begin(), bin.end());
	return bin;
}

int EventGenerator::convertToDecimalFromBinary()
{
	std::vector<int> bin = convertToBinaryFromGray();
	int decimal = 0;

	for (size_t i = 0; i < bin.size(); i++)
	{
		decimal += bin[i] * pow(2, i);
	}

	return decimal;
}