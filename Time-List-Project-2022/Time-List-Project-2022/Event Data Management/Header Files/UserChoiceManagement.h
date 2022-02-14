#pragma once
#include <SFML/Audio.hpp>
#include "TestsGenerator.h"

namespace ChoiceFlow
{
	namespace MainMenu
	{
		void playSound(sf::SoundBuffer& buffer, sf::Sound& sound, int soundType);

		void onClickMainMenu(sf::RenderWindow& window, sf::Event& event1, int& stage, sf::SoundBuffer& buffer, 
		sf::Sound& sound);
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

		void onClickEventPage(sf::RenderWindow& window, sf::Event& event1, int& stage, int& box, sf::String& title, 
		sf::String& year, sf::String& topic, sf::String& description, sf::SoundBuffer& buffer, sf::Sound& sound);

		void inputEventData(sf::Event& event1, sf::String& text, int size, bool num);

		void seperateLinesInDescription(sf::String& description, sf::Text* descriptionText);
	}
	namespace SearchedAnEvent
	{
		namespace inputData
		{
			static sf::String title;
			static sf::String oldTitle;
			static bool oldTitleCheck = true;
			static sf::String year;
			static sf::String topic;
			static sf::String description;
			static bool sortVer = false;
			static sf::String searchData;
		}

		static bool crCheck = true;
		static bool sortCheck = true;
		static int sortType = 1;
		static bool ifSearched = false;
		static sf::String lastSearched;
		static std::string deletedTitle;

		void onClickSearchPage(sf::RenderWindow& window, sf::Event& event1, int& stage, Event*& head, Event*& tail,
		bool& crCheck, bool& sortCheck, sf::String& title, sf::String& year, sf::String& topic, sf::String& description, 
		int& sortType, int& box, sf::String& searchData, Event*& entireFile, sf::SoundBuffer& buffer, sf::Sound& sound);

		void onClickInfoPage(sf::RenderWindow& window, sf::Event& event1, int& stage, sf::SoundBuffer& buffer, sf::Sound& sound);

		void saveEditedEventData(sf::String& title, sf::String& year, sf::String& topic, sf::String& description);

		void onClickEditPage(sf::RenderWindow& window, sf::Event& event1, int& stage, int& box, sf::String& title, 
		sf::String& year, sf::String& topic, sf::String& description, bool& crCheck, int& sortType, 
		sf::SoundBuffer& buffer, sf::Sound& sound);
	}
	namespace TestKnowledge
	{
		namespace inputData
		{
			static bool generated = false;
			static bool crCheck = true;
			static sf::String yearAnswer;
			static sf::String titleText;
			static sf::String topicText;
			static bool revealed = false;
			static bool checked = false;
		}

		void onClickTestPage(sf::RenderWindow& window, sf::Event& event1, int& stage, Event*& entireFile, 
		bool& crCheck, int& box, sf::String& yearAnswer, sf::String& titleText, sf::String& topicText, 
		EventGenerator*& eventG, bool& revealed, bool& generated, bool& checked, sf::SoundBuffer& buffer, sf::Sound& sound);
	}
}