#include "../Header Files/Event.h"
#include <regex>
#include <algorithm>

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
	}

	inputFile.close();
	head = removeHead(head);
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
		text.setString(head->title); text.setPosition(100, y+58);
		eventBoard.setPosition(63, y);
		window.draw(eventBoard); window.draw(text);
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