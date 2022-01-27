#include "../Header Files/Event.h"
#include <iostream>

Event::Event(std::string& title, int& year, std::string& topic, std::string& description)
{
	this->title = title;
	this->year = year;
	this->topic = topic;
	this->description = description;
}

Event* Event::getTail(Event* head)
{
	while (head->nextEvent != NULL)
	{
		head = head->nextEvent;
	}

	return head;
}

void Event::appendNode(Event* head, std::string& title, int& year, std::string& topic, std::string& description)
{
	Event* tail = getTail(head);

	tail->nextEvent = new Event(title, year, topic, description);
}

Event* Event::removeHead(Event* head)
{
	Event* newHead = head->nextEvent;
	delete head;

	return newHead;
}

void Event::takeDataFromFile(Event*& head)
{
	inputFile.open("Events.txt", std::ios::in | std::ios::app);
	std::string data;

	while (std::getline(inputFile, data))
	{
		title = data.substr(0, data.find('9') - 1);
		data.erase(0, data.find('9'));
		year = std::stoi(data.substr(data.find('9'), data.find(' ')));
		data.erase(data.find('9'), data.find(' ') + 1);
		topic = data.substr(0, data.find(' '));
		data.erase(0, data.find(' ') + 1);
		description = data;

		appendNode(head, title, year, topic, description);
	}

	head = removeHead(head);
}

void Event::printList(Event* head)
{
	if (head == NULL)
	{
		return;
	}

	std::cout << head->title <<std::endl;
	printList(head->nextEvent);
}