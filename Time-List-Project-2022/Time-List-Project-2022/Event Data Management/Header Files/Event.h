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

	void takeDataFromFile(Event*& head);

	Event* split(Event* head);

	Event* merge(Event* f, Event* s, int sortType);

	Event* mergeSortList(Event*& head, int sortType);

	void printList(sf::RenderWindow& window, Event* head, sf::Sprite& eventBoard, sf::Font& font);

	void printListReversed(sf::RenderWindow& window, Event* tail, sf::Sprite& eventBoard, sf::Font& font);

	Event* printFoundData(Event* head, sf::String searchData);

	void clearList(Event* head);

	void clearListTail(Event* tail);

	void reverseList(Event*& head);

	int takeNodeIndex(int cordinateY, int node);

	int takeLastNodePos(Event* head);

	void saveDataIntoFile(Event* head);

	void saveDataIntoFileTail(Event* tail);

	void saveEventInfo(Event* head, Event* tail,int cordinateY, int node, sf::String& title, sf::String& year, sf::String& topic, sf::String& description, bool& sortCheck);

	void removeNode(Event*& head, Event*& tail, int cordinateY, int node, bool& sortCheck);

	void removeAfterSearch(Event*& head, Event*& tail, int cordinateY, int node, bool& sortCheck, std::string& title);
	
	void saveAfterRemoveWhenSearched(Event* entireFile ,std::string& title);
};