#include "../Header Files/TestsGenerator.h"
#include "../Header Files/SearchAnEvent.h"
#include <stdlib.h>

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

