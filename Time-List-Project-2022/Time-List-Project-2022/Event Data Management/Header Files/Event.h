#pragma once
#include <string>

class Event 
{
private:
	std::string topic;
	int year;
	std::string theme;
	std::string description;

public:
	Event(std::string topic, int year, std::string theme, std::string description)
	{
		this->topic = topic;
		this->year = year;
		this->theme = theme;
		this->description = description;
	}

	~Event() 
	{

	}
};