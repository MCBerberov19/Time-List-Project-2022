#pragma once
#include "Event.h"

typedef void(Event::* appendNodeCallback)(Event*, std::string&, int&, std::string&, std::string&);

typedef Event* (Event::* removeHeadCallback)(Event*);

namespace SearchAnEventNodes
{
	namespace PrintList
	{
		void printList(sf::RenderWindow& window, Event* head, sf::Sprite& eventBoard, sf::Font& font);

		void printListReversed(sf::RenderWindow& window, Event* tail, sf::Sprite& eventBoard, sf::Font& font);

		Event* printFoundData(Event* head, sf::String searchData, 
			appendNodeCallback appendNode, int& sortType, bool& sortCheck);
	}

	namespace ClearList
	{
		void clearList(Event* head);

		void clearListTail(Event* tail);
	}

	namespace TakeNodes
	{
		void takeDataFromFile(Event*& head, appendNodeCallback appendNode, removeHeadCallback removeHead);

		int takeNodeIndex(int cordinateY, int node);

		int takeLastNodePos(Event* head);

		bool checkValidSpaces(int cordinateY);
	}

	namespace SaveList
	{
		void saveDataIntoFile(Event* head);

		void saveDataIntoFileTail(Event* tail);

		void saveEventInfo(Event* head, Event* tail, int cordinateY, int node, sf::String& title, sf::String& year,
		sf::String& topic, sf::String& description, bool& sortCheck);

		void saveAfterRemoveWhenSearched(Event* entireFile, std::string& title);
	}
}