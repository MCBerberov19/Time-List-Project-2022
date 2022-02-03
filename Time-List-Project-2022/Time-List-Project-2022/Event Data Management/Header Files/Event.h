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

	Event() {}

	Event(std::string& title, int& year, std::string& topic, std::string& description);

	Event* getTail(Event* head);

	Event* getHead(Event* tail);

	void appendNode(Event* head, std::string& title, int& year, std::string& topic, std::string& description);

	Event* removeHead(Event* head);

	Event* split(Event* head);

	Event* merge(Event* f, Event* s, int sortType);

	Event* mergeSortList(Event*& head, int sortType);

	void removeNode(Event*& head, Event*& tail, int cordinateY, int node, bool& sortCheck);

	void removeAfterSearch(Event*& head, Event*& tail, int cordinateY, int node, bool& sortCheck, std::string& title);
};