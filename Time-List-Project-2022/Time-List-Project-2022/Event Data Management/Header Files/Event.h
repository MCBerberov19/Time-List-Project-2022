#pragma once
#include <string>

struct Event 
{
	std::string topic;
	int year;
	std::string theme;
	std::string description;

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