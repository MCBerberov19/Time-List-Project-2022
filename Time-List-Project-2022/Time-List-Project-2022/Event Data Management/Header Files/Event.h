#pragma once
#include <string>
#include <fstream>

struct Event 
{
	std::string title;
	int year;
	std::string topic;
	std::string description;
	Event* nextEvent=NULL;

	std::ifstream inputFile;

	Event() {}

	Event(std::string& title, int& year, std::string& topic, std::string& description);
	

	Event* getTail(Event* head);

	void appendNode(Event* head, std::string& title, int& year, std::string& topic, std::string& description);

	Event* removeHead(Event* head);

	void takeDataFromFile(Event*& head);

	void printList(Event* head);

};