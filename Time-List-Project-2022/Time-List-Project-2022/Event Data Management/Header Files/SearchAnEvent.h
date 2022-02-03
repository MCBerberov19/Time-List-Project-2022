#pragma once
#include <SFML/Graphics.hpp>
#include "Event.h"

namespace SearchAnEventNodes
{
	namespace PrintList
	{
		void printList(sf::RenderWindow& window, Event* head, sf::Sprite& eventBoard, sf::Font& font);

		void printListReversed(sf::RenderWindow& window, Event* tail, sf::Sprite& eventBoard, sf::Font& font);

		Event* printFoundData(Event* head, sf::String searchData, void(Event::*appendNode)(Event*, std::string&, int&, std::string&, std::string&));
	}

	namespace ClearList
	{
		void clearList(Event* head);

		void clearListTail(Event* tail);
	}

	namespace TakeNodes
	{
		void takeDataFromFile(Event*& head, void(Event::* appendNode)(Event*, std::string&, int&, std::string&, std::string&), Event* (Event::* removeHead)(Event*));

		int takeNodeIndex(int cordinateY, int node);

		int takeLastNodePos(Event* head);
	}

	namespace SaveList
	{
		void saveDataIntoFile(Event* head);

		void saveDataIntoFileTail(Event* tail);

		void saveEventInfo(Event* head, Event* tail, int cordinateY, int node, sf::String& title, sf::String& year, sf::String& topic, sf::String& description, bool& sortCheck);

		void saveAfterRemoveWhenSearched(Event* entireFile, std::string& title);
	}
}