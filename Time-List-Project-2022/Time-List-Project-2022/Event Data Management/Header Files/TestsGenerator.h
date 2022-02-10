#pragma once
#include "Event.h"
#include <map>

typedef int(*takeLastNodePosCallback)(Event*);

class EventGenerator
{
private:
	int lastNodePos;
	std::vector<int> grayYear;
public:
	std::string title;
	std::string topic;

	EventGenerator(Event* entireFile, takeLastNodePosCallback takeLastNodePos);

	std::map<std::string, std::string> generateRandomNode(Event* entireFile, takeLastNodePosCallback takeLastNodePos);

	std::vector<int> convertToBinary(int decNum);

	std::vector<int> convertToGrayCode(int decNum);

	std::vector<int> convertToBinaryFromGray();

	int convertToDecimalFromBinary();
};