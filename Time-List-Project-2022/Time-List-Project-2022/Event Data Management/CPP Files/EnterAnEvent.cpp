#include "../Header Files/EnterAnEvent.h"

EnterAnEventC::EnterAnEventC(sf::String title, int year, sf::String topic, sf::String description)
{
	this->title = title;
	this->year = year;
	this->topic = topic;
	this->description = description;

	setTextData();
}

void EnterAnEventC::setTextData()
{
	userDataOut.open("Events.txt", std::ios::app | std::ios::out);
	userDataOut << title.toAnsiString() << " " << std::to_string(year) << " " << topic.toAnsiString() 
	<< " " << description.toAnsiString() << std::endl;
}