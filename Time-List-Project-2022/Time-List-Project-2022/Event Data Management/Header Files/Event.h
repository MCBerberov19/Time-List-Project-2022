#pragma once
#include <string>
#include <fstream>

struct Event
{
	std::string title;
	int year;
	std::string topic;
	std::string description;
	Event* nextEvent = NULL;

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

	void reverseList(Event*& head);

	void printList(Event* head);

	void clearList(Event* head);
};