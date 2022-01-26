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

		void onClickEventPage(sf::RenderWindow& window, sf::Event& event1, int& stage, int& box, sf::String& title, sf::String& year, sf::String& topic, sf::String& description);

		void inputEventData(sf::Event& event1, sf::String& text, int size, bool num);

		void seperateLinesInDescription(sf::String& description, sf::Text& descriptionText1, sf::Text& descriptionText2, sf::Text& descriptionText3, sf::Text& descriptionText4, sf::Text& descriptionText5, sf::Text& descriptionText6, sf::Text& descriptionText7, sf::Text& descriptionText8);

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