#pragma once
#include "Event.h"
#include <string>
#include <map>

class EventGenerator
{
private:
	int lastNodePos;
	int year;
public:
	std::string title;
	std::string topic;

	EventGenerator(Event* entireFile, int(*takeLastNodePos)(Event*));

	std::map<int,std::string> generateRandomNode(Event* entireFile, int(*takeLastNodePos)(Event*));
};