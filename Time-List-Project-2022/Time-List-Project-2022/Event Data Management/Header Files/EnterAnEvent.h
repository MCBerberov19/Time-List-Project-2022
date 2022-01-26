#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>

class EnterAnEventC
{
	sf::String title;
	int year;
	sf::String topic;
	sf::String description;

	std::ofstream userDataOut;
public:

	EnterAnEventC(sf::String title, int year, sf::String topic, sf::String description);

	void setTextData();

	~EnterAnEventC()
	{
		userDataOut.close();
	}
};