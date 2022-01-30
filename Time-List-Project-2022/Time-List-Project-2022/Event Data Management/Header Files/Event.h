#pragma once
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

struct Event
{
	std::string title;
	int year = 0;
	std::string topic;
	std::string description;
	Event* nextEvent = NULL;
	Event* prevEvent = NULL;

	std::ifstream inputFile;

	Event() {}

	Event(std::string& title, int& year, std::string& topic, std::string& description);

	Event* getTail(Event* head);

	void appendNode(Event* head, std::string& title, int& year, std::string& topic, std::string& description);

	Event* removeHead(Event* head);

	void takeDataFromFile(Event*& head);

	Event* split(Event* head);

	Event* merge(Event* f, Event* s);

	Event* mergeSortList(Event*& head);

	void printList(sf::RenderWindow& window, Event* head, sf::Sprite& eventBoard, sf::Font& font);

	void printListReversed(sf::RenderWindow& window, Event* tail, sf::Sprite& eventBoard, sf::Font& font);

	void clearList(Event* head);
};