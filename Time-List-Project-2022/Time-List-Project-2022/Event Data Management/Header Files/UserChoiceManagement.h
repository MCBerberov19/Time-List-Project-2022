#pragma once
#include <SFML/Graphics.hpp>

namespace ChoiceFlow
{
	namespace MainMenu
	{
		void onClickMainMenu(sf::RenderWindow& window, sf::Event& event1, int& stage);
	}
	namespace EnterAnEvent
	{
		namespace inputData
		{
			static int box;
			static sf::String title;
			static sf::String year;
			static sf::String topic;
			static sf::String description;
		}

		void onClickEventPage(sf::RenderWindow& window, sf::Event& event1, int& stage);

		void inputEventData(sf::Event& event1);
	}
	namespace SearchedAnEvent
	{
		void onClickSearchPage(sf::RenderWindow& window, sf::Event& event1, int& stage);
	}
	namespace LastSearchedEvents
	{
		void onClickLastEventsPage(sf::RenderWindow& window, sf::Event& event1, int& stage);
	}
}