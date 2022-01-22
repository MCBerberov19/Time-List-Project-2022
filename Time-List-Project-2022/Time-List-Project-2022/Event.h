#pragma once
#include <string>

class Event
{
private:
	std::string title;
	int year;
	std::string topic;
	std::string description;

public:
	Event(std::string title, int year, std::string topic, std::string description)
	{
		this->title = title;
		this->year = year;
		this->topic = topic;
		this->description = description;
	}

	~Event()
	{

	}
};

