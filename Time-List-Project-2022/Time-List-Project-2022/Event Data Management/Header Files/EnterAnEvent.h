#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>

class EnterAnEvent
{
	sf::String title;
	int year;
	sf::String topic;
	sf::String description;

	std::ofstream userDataOut;
public:
	
	EnterAnEvent(sf::String title, int year, sf::String topic, sf::String description)
	{
		this->title = title;
		this->year = year;
		this->topic = topic;
		this->description = description;
	}

	~EnterAnEvent()
	{
		userDataOut.close();
	}
};