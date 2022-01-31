#include "../Header Files/Event.h"
#include <regex>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>

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
	tail->nextEvent->prevEvent = NULL;
}

Event* Event::removeHead(Event* head)
{
	Event* newHead = head->nextEvent;
	newHead->prevEvent = NULL;
	delete head;

	return newHead;
}

void Event::takeDataFromFile(Event*& head)
{
	inputFile.open("Events.txt", std::ios::in | std::ios::app);
	std::string data;
	int cur = 0;

	std::smatch yearMatch;

	size_t start;

	while (std::getline(inputFile, data))
	{
		start = 0;

		std::regex_search(data, yearMatch, std::regex("[1-9]"));

		title = data.substr(0, yearMatch.position() - 1);

		year = std::stoi(data.substr(yearMatch.position(), data.find(' ')));

		topic = data.substr(
			yearMatch.position() + std::to_string(year).size() + 1,
			std::distance(data.begin() + yearMatch.position() + std::to_string(year).size() + 1, std::find(data.begin() + yearMatch.position() + std::to_string(year).size() + 1, data.end(), ' ')));

		description = data.substr(data.find(topic) + topic.size() + 1, std::string::npos);

		appendNode(head, title, year, topic, description);
		cur++;
	}

	inputFile.close();

	if (cur > 0)
	{
		head = removeHead(head);
	}

}

Event* Event::split(Event* head)
{
	Event* f = head, * s = head;
	while (f->nextEvent && f->nextEvent->nextEvent)
	{
		f = f->nextEvent->nextEvent;
		s = s->nextEvent;
	}

	Event* temp = s->nextEvent;
	s->nextEvent = NULL;
	return temp;
}

Event* Event::merge(Event* f, Event* s)
{
	if (!f)
		return s;

	if (!s)
		return f;

	if (f->year <= s->year)
	{
		f->nextEvent = merge(f->nextEvent, s);
		f->nextEvent->prevEvent = f;
		f->prevEvent = NULL;
		return f;
	}

	{
		s->nextEvent = merge(f, s->nextEvent);
		s->nextEvent->prevEvent = s;
		s->prevEvent = NULL;
		return s;
	}
}

Event* Event::mergeSortList(Event*& head)
{
	if (!head || !head->nextEvent)
		return head;

	Event* secondHalf = split(head);

	head = mergeSortList(head);
	secondHalf = mergeSortList(secondHalf);

	return merge(head, secondHalf);
}

void Event::printList(sf::RenderWindow& window, Event* head, sf::Sprite& eventBoard, sf::Font& font)
{
	sf::Text text; text.setFont(font); text.setCharacterSize(28); text.setFillColor(sf::Color::Black);
	int y = 220;

	while (head != NULL)
	{
		text.setString(head->title); text.setPosition(100, y + 58);
		eventBoard.setPosition(63, y);
		window.draw(eventBoard); window.draw(text);
		//std::cout << head->title << " " << head->year << " " << head->topic << " " << head->description << std::endl;
		head = head->nextEvent; y += 70;
	}
}

void Event::printListReversed(sf::RenderWindow& window, Event* tail, sf::Sprite& eventBoard, sf::Font& font)
{
	sf::Text text; text.setFont(font); text.setCharacterSize(28); text.setFillColor(sf::Color::Black);
	int y = 220;

	while (tail != NULL)
	{
		text.setString(tail->title); text.setPosition(100, y + 58);
		eventBoard.setPosition(63, y);
		window.draw(eventBoard); window.draw(text);
		//std::cout << tail->title << " " << tail->year << " " << tail->topic << " " << tail->description << std::endl;
		tail = tail->prevEvent; y += 70;
	}
}

void Event::clearList(Event* head)
{
	if (head == NULL)
	{
		return;
	}

	Event* temp = head->nextEvent;
	delete head;
	clearList(temp);
}

void Event::reverseList(Event*& head)
{
	Event* current = head, * prev = NULL, * next = NULL;

	while (current != NULL)
	{
		next = current->nextEvent;
		current->prevEvent;
		prev = current;
		current = next;
	}

	head = prev;
}

int Event::takeNodeIndex(int cordinateY, int node)
{
	if (cordinateY >= 270 && cordinateY <= 320)
	{
		return node;
	}
	else if (cordinateY < 270)
	{
		return 0;
	}
	node++;
	takeNodeIndex(cordinateY - 70, node);
}

int Event::takeLastNodePos(Event* head)
{
	int pos = 0;

	while (head != NULL)
	{
		pos++;
		head = head->nextEvent;
	}

	return pos;
}

void Event::saveDataIntoFile(Event* head)
{
	std::ofstream outputData; outputData.open("Events.txt", std::ios::out | std::ios::trunc);

	while (head != NULL)
	{
		outputData << head->title << " " << std::to_string(head->year) << " " << head->topic << " " << head->description << std::endl;
		head = head->nextEvent;
	}

	outputData.close();
}

void Event::removeNode(Event*& head, Event*& tail,int cordinateY, int node, bool& sortCheck)
{
	int nodeCur = 1;
	Event* headCur = head;

	int last = takeLastNodePos(head);

	if (takeNodeIndex(cordinateY, node) != 0)
	{
		if (sortCheck)
		{
			while (head != NULL)
			{
				if (nodeCur == takeNodeIndex(cordinateY, node))
				{
					if (takeNodeIndex(cordinateY, node) == 1)
					{
						if (head->nextEvent == NULL)
						{
							head->clearList(head);
							head = NULL;
							tail = NULL;
						}
						else
						{
							head->nextEvent->prevEvent = NULL;
							head = head->nextEvent;
						}
						break;

					}
					else if (takeNodeIndex(cordinateY, node) == last)
					{
						head->prevEvent->nextEvent = NULL;
						delete head;
						head = headCur;
						break;
					}
					else
					{
						head->prevEvent->nextEvent = head->nextEvent;
						head->nextEvent->prevEvent = head->prevEvent;
						delete head;
						head = headCur;
						break;
					}
				}
				nodeCur++;
				head = head->nextEvent;
			}
		}
		saveDataIntoFile(head);
	}
}