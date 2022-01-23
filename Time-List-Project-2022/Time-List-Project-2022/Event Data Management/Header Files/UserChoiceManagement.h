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
		void onClickEventPage(sf::RenderWindow& window, sf::Event& event1, int& stage);
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