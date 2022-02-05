#pragma once
#include "Event.h"
#include <string>
#include <map>

class EventGenerator
{
private:
	int lastNodePos;
	std::vector<int> grayYear;
public:
	std::string title;
	std::string topic;

	EventGenerator(Event* entireFile, int(*takeLastNodePos)(Event*));

	std::map<std::string, std::string> generateRandomNode(Event* entireFile, int(*takeLastNodePos)(Event*));

	std::vector<int> convertToBinary(int decNum);

	std::vector<int> convertToGrayCode(int decNum);

	std::vector<int> convertToBinaryFromGray();
	
	int convertToDecimalFromBinary();
};