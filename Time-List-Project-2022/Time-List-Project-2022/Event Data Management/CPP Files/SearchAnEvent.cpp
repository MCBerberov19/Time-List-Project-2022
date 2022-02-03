#include "../Header Files/SearchAnEvent.h"
#include <regex>

void SearchAnEventNodes::PrintList::printList(sf::RenderWindow& window, Event* head, sf::Sprite& eventBoard, sf::Font& font)
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

void SearchAnEventNodes::PrintList::printListReversed(sf::RenderWindow& window, Event* tail, sf::Sprite& eventBoard, sf::Font& font)
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

Event* SearchAnEventNodes::PrintList::printFoundData(Event* head, sf::String searchData, void(Event::* appendNode)(Event*, std::string&, int&, std::string&, std::string&))
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
				head->appendNode(newHead, head->title, head->year, head->topic, head->description);
				cur++;
			}
		}
		else
		{
			if (head->title == searchData.toAnsiString() || head->topic == searchData.toAnsiString())
			{
				head->appendNode(newHead, head->title, head->year, head->topic, head->description);
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

void SearchAnEventNodes::ClearList::clearList(Event* head)
{
	if (head == NULL)
	{
		return;
	}

	Event* temp = head->nextEvent;
	delete head;
	clearList(temp);
}

void SearchAnEventNodes::ClearList::clearListTail(Event* tail)
{
	if (tail == NULL)
	{
		return;
	}

	Event* temp = tail->prevEvent;
	delete tail;
	clearList(temp);
}

void SearchAnEventNodes::TakeNodes::takeDataFromFile(Event*& head, void(Event::* appendNode)(Event*, std::string&,
	int&, std::string&, std::string&), Event*(Event::*removeHead)(Event*))
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

		head->appendNode(head, title, year, topic, description);
		cur++;
	}

	inputFile.close();

	if (cur > 0)
	{
		head = head->removeHead(head);
	}
}

int SearchAnEventNodes::TakeNodes::takeNodeIndex(int cordinateY, int node)
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

int SearchAnEventNodes::TakeNodes::takeLastNodePos(Event* head)
{
	int pos = 0;

	while (head != NULL)
	{
		pos++;
		head = head->nextEvent;
	}

	return pos;
}

void SearchAnEventNodes::SaveList::saveDataIntoFile(Event* head)
{
	std::ofstream outputData; outputData.open("Events.txt", std::ios::out | std::ios::trunc);

	while (head != NULL)
	{
		outputData << head->title << " " << std::to_string(head->year) << " " << head->topic << " " << head->description << std::endl;
		head = head->nextEvent;
	}

	outputData.close();
}

void SearchAnEventNodes::SaveList::saveDataIntoFileTail(Event* tail)
{
	std::ofstream outputData; outputData.open("Events.txt", std::ios::out | std::ios::trunc);

	while (tail != NULL)
	{
		outputData << tail->title << " " << std::to_string(tail->year) << " " << tail->topic << " " << tail->description << std::endl;
		tail = tail->prevEvent;
	}

	outputData.close();
}

void SearchAnEventNodes::SaveList::saveEventInfo(Event* head, Event* tail, int cordinateY, int node, sf::String& title, sf::String& year, sf::String& topic, sf::String& description, bool& sortCheck)
{
	int nodeCur = 1;
	if (SearchAnEventNodes::TakeNodes::takeNodeIndex(cordinateY, node) != 0)
	{
		if (sortCheck)
		{
			while (head != NULL)
			{
				if (nodeCur == SearchAnEventNodes::TakeNodes::takeNodeIndex(cordinateY, node))
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
				if (nodeCur == SearchAnEventNodes::TakeNodes::takeNodeIndex(cordinateY, node))
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

void SearchAnEventNodes::SaveList::saveAfterRemoveWhenSearched(Event* entireFile, std::string& title)
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