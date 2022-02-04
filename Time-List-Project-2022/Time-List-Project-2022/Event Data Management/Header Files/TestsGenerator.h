#pragma once
#include "Event.h"
#include <string>

class EventGenerator
{
private:
	std::string answer;
	int lastNodePos;
public:
	int year;
	std::string topic;

	EventGenerator(Event* entireFile, int(*takeLastNodePos)(Event*));
};