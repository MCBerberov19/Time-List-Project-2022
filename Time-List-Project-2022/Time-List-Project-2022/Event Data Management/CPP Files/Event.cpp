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
	if (head == NULL)
	{
		return head;
	}

	while (head->nextEvent != NULL)
	{
		head = head->nextEvent;
	}

	return head;
}

Event* Event::getHead(Event* tail)
{
	if (tail == NULL)
	{
		return tail;
	}

	while (tail->prevEvent != NULL)
	{
		tail = tail->prevEvent;
	}

	return tail;
}

void Event::appendNode(Event* head, std::string& title, int& year, std::string& topic, std::string& description)
{
	Event* tail = getTail(head);

	tail->nextEvent = new Event(title, year, topic, description);
	if (tail == NULL)
	{
		tail->nextEvent->prevEvent = NULL;
	}
	else
	{
		tail->nextEvent->prevEvent = tail;
	}

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
	std::ifstream inputFile; inputFile.open("Events.txt", std::ios::in | std::ios::app);
	std::string data;
	int cur = 0;

	std::string title, topic, description;
	int year;

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

Event* Event::merge(Event* f, Event* s, int sortType)
{
	if (!f)
		return s;

	if (!s)
		return f;

	switch (sortType)
	{
	case 1:
		if (f->title <= s->title)
		{
			f->nextEvent = merge(f->nextEvent, s, sortType);
			f->nextEvent->prevEvent = f;
			f->prevEvent = NULL;
			return f;
		}
		else
		{
			s->nextEvent = merge(f, s->nextEvent, sortType);
			s->nextEvent->prevEvent = s;
			s->prevEvent = NULL;
			return s;
		}
		break;
	case 2:
		if (f->year <= s->year)
		{
			f->nextEvent = merge(f->nextEvent, s, sortType);
			f->nextEvent->prevEvent = f;
			f->prevEvent = NULL;
			return f;
		}
		else
		{
			s->nextEvent = merge(f, s->nextEvent, sortType);
			s->nextEvent->prevEvent = s;
			s->prevEvent = NULL;
			return s;
		}
		break;
	case 3:
		if (f->topic <= s->topic)
		{
			f->nextEvent = merge(f->nextEvent, s, sortType);
			f->nextEvent->prevEvent = f;
			f->prevEvent = NULL;
			return f;
		}
		else
		{
			s->nextEvent = merge(f, s->nextEvent, sortType);
			s->nextEvent->prevEvent = s;
			s->prevEvent = NULL;
			return s;
		}
		break;
	}

}

Event* Event::mergeSortList(Event*& head, int sortType)
{
	if (!head || !head->nextEvent)
		return head;

	Event* secondHalf = split(head);

	head = mergeSortList(head, sortType);
	secondHalf = mergeSortList(secondHalf, sortType);

	return merge(head, secondHalf, sortType);
}

void Event::printList(sf::RenderWindow& window, Event* head, sf::Sprite& eventBoard, sf::Font& font)
{
	sf::Text text; text.setFont(font); text.setCharacterSize(28); text.setFillColor(sf::Color::Black);
	int y = 220;
	int i = 0;

	while (head != NULL)
	{
		if (i == 6)
		{
			return;
		}

		text.setString(head->title); text.setPosition(100, y + 58);
		eventBoard.setPosition(63, y);
		window.draw(eventBoard); window.draw(text);
		//std::cout << head->title << " " << head->year << " " << head->topic << " " << head->description << std::endl;
		head = head->nextEvent; y += 70;
		i++;
	}
}

void Event::printListReversed(sf::RenderWindow& window, Event* tail, sf::Sprite& eventBoard, sf::Font& font)
{
	sf::Text text; text.setFont(font); text.setCharacterSize(28); text.setFillColor(sf::Color::Black);
	int y = 220;
	int i = 0;

	while (tail != NULL)
	{
		if (i == 6)
		{
			return;
		}

		text.setString(tail->title); text.setPosition(100, y + 58);
		eventBoard.setPosition(63, y);
		window.draw(eventBoard); window.draw(text);
		//std::cout << tail->title << " " << tail->year << " " << tail->topic << " " << tail->description << std::endl;
		tail = tail->prevEvent; y += 70;
		i++;
	}
}

Event* Event::printFoundData(Event* head, sf::String searchData)
{
	Event* newHead = new Event;
	int cur = 0;
	std::string year;
	while (head != NULL)
	{
		if (std::regex_match(searchData.toAnsiString(), std::regex(R"(^^\s*[-+]?((\d+(\.\d+)?)|(\d+\.)|(\.\d+))(e[-+]?\d+)?\s*$)")))
		{
			year = searchData.toAnsiString();
			if (head->year == stoi(year))
			{
				appendNode(newHead, head->title, head->year, head->topic, head->description);
				cur++;
			}
		}
		else
		{
			if (head->title == searchData.toAnsiString() || head->topic == searchData.toAnsiString())
			{
				appendNode(newHead, head->title, head->year, head->topic, head->description);
				cur++;
			}
		}
		head = head->nextEvent;
	}

	if (cur > 0)
	{
		newHead = newHead->removeHead(newHead);
	}

	return newHead;
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

void Event::clearListTail(Event* tail)
{
	if (tail == NULL)
	{
		return;
	}

	Event* temp = tail->prevEvent;
	delete tail;
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

void Event::saveDataIntoFileTail(Event* tail)
{
	std::ofstream outputData; outputData.open("Events.txt", std::ios::out | std::ios::trunc);

	while (tail != NULL)
	{
		outputData << tail->title << " " << std::to_string(tail->year) << " " << tail->topic << " " << tail->description << std::endl;
		tail = tail->prevEvent;
	}

	outputData.close();
}

void Event::saveEventInfo(Event* head, Event* tail, int cordinateY, int node, sf::String& title, sf::String& year, sf::String& topic, sf::String& description, bool& sortCheck)
{
	int nodeCur = 1;
	if (takeNodeIndex(cordinateY, node) != 0)
	{
		if (sortCheck)
		{
			while (head != NULL)
			{
				if (nodeCur == takeNodeIndex(cordinateY, node))
				{
					title = head->title;
					year = std::to_string(head->year);
					topic = head->topic;
					description = head->description;
					break;
				}
				head = head->nextEvent;
				nodeCur++;
			}
		}
		else
		{
			while (tail != NULL)
			{
				if (nodeCur == takeNodeIndex(cordinateY, node))
				{
					title = tail->title;
					year = std::to_string(tail->year);
					topic = tail->topic;
					description = tail->description;
					break;
				}
				tail = tail->prevEvent;
				nodeCur++;
			}
		}
	}
}

void Event::removeNode(Event*& head, Event*& tail, int cordinateY, int node, bool& sortCheck)
{
	int nodeCur = 1;
	Event* headCur = head;
	Event* tailCur = getTail(head);

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
						tail->prevEvent->nextEvent = NULL;
						head = headCur;
						tailCur = tailCur->prevEvent;
						tail = tailCur;
						break;
					}
					else
					{
						head->prevEvent->nextEvent = head->nextEvent;
						head->nextEvent->prevEvent = head->prevEvent;
						head = headCur;
						tail = tailCur;
						break;
					}
				}
				nodeCur++;
				head = head->nextEvent;
			}
			saveDataIntoFile(head);
		}
		else
		{
			while (tail != NULL)
			{
				if (nodeCur == takeNodeIndex(cordinateY, node))
				{
					if (takeNodeIndex(cordinateY, node) == 1)
					{
						if (tail->prevEvent == NULL)
						{
							tail->clearListTail(tail);
							head = NULL;
							tail = NULL;
						}
						else
						{
							tail->prevEvent->nextEvent = NULL;
							tail = tail->prevEvent;
						}
						break;

					}
					else if (takeNodeIndex(cordinateY, node) == last)
					{
						tail->nextEvent->prevEvent = NULL;
						head->nextEvent->prevEvent = NULL;
						headCur = headCur->nextEvent;
						tail = tailCur;
						head = headCur;
						break;
					}
					else
					{
						tail->prevEvent->nextEvent = tail->nextEvent;
						tail->nextEvent->prevEvent = tail->prevEvent;
						delete tail;
						tail = tailCur;
						head = headCur;
						break;
					}
				}
				nodeCur++;
				tail = tail->prevEvent;
			}
			saveDataIntoFileTail(tail);
		}
	}
}

void Event::removeAfterSearch(Event*& head, Event*& tail, int cordinateY, int node, bool& sortCheck, std::string& title)
{
	int nodeCur = 1;
	Event* headCur = head;
	Event* tailCur = getTail(head);

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
							title = head->title;
							head->clearList(head);
							head = NULL;
							tail = NULL;
						}
						else
						{
							head->nextEvent->prevEvent = NULL;
							title = head->title;
							head = head->nextEvent;
						}
						break;

					}
					else if (takeNodeIndex(cordinateY, node) == last)
					{
						title = head->title;
						head->prevEvent->nextEvent = NULL;
						tail->prevEvent->nextEvent = NULL;
						head = headCur;
						tailCur = tailCur->prevEvent;
						tail = tailCur;
						break;
					}
					else
					{
						title = head->title;
						head->prevEvent->nextEvent = head->nextEvent;
						head->nextEvent->prevEvent = head->prevEvent;
						head = headCur;
						tail = tailCur;
						break;
					}
				}
				nodeCur++;
				head = head->nextEvent;
			}
		}
		else
		{
			while (tail != NULL)
			{
				if (nodeCur == takeNodeIndex(cordinateY, node))
				{
					if (takeNodeIndex(cordinateY, node) == 1)
					{
						if (tail->prevEvent == NULL)
						{
							title = tail->title;
							tail->clearListTail(tail);
							head = NULL;
							tail = NULL;
						}
						else
						{
							title = tail->title;
							tail->prevEvent->nextEvent = NULL;
							tail = tail->prevEvent;
						}
						break;

					}
					else if (takeNodeIndex(cordinateY, node) == last)
					{
						title = tail->title;
						tail->nextEvent->prevEvent = NULL;
						head->nextEvent->prevEvent = NULL;
						headCur = headCur->nextEvent;
						tail = tailCur;
						head = headCur;
						break;
					}
					else
					{
						title = tail->title;
						tail->prevEvent->nextEvent = tail->nextEvent;
						tail->nextEvent->prevEvent = tail->prevEvent;
						delete tail;
						tail = tailCur;
						head = headCur;
						break;
					}
				}
				nodeCur++;
				tail = tail->prevEvent;
			}
		}
	}
}

void Event::saveAfterRemoveWhenSearched(Event* entireFile, std::string& title)
{
	std::vector<std::string> dataV;
	std::string data;
	
	while (entireFile != NULL)
	{
		if (title != entireFile->title)
		{
			data = entireFile->title + " " + std::to_string(entireFile->year) + " " + entireFile->topic + " " + entireFile->description;
			dataV.push_back(data);
		}
		entireFile = entireFile->nextEvent;
	}

	std::ofstream dataOut; dataOut.open("Events.txt", std::ios::out | std::ios::trunc);
	for (std::string i : dataV)
	{
		dataOut << i << std::endl;
	}
	dataOut.close();
}