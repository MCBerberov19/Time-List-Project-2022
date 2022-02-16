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
		static int box;
		static bool crCheck = true;

		struct inputData
		{
			sf::String title;
			sf::String year;
			sf::String topic;
			sf::String description;
		};

		void onClickEventPage(sf::RenderWindow& window, sf::Event& event1, int& stage, int& box,
			EnterAnEvent::inputData*& eData, sf::SoundBuffer& buffer, sf::Sound& sound, bool& crCheck);

		void inputEventData(sf::Event& event1, sf::String& text, int size, bool num);

		void seperateLinesInDescription(sf::String& description, sf::Text* descriptionText);
	}
	namespace SearchedAnEvent
	{
		static bool crCheckS = true;

		struct inputData
		{
			sf::String title;
			sf::String oldTitle;
			bool oldTitleCheck;
			sf::String year;
			sf::String topic;
			sf::String description;
			bool sortVer;
			sf::String searchData;
		};

		struct checkData
		{
			bool sortCheck = true;
			int sortType = 1;
			bool ifSearched = false;
			sf::String lastSearched;
			std::string deletedTitle;
		};

		void onClickSearchPage(sf::RenderWindow& window, sf::Event& event1, int& stage,
			Event*& head, Event*& tail, SearchedAnEvent::inputData*& sData, SearchedAnEvent::checkData*& cData, int& box,
			Event*& entireFile, sf::SoundBuffer& buffer, sf::Sound& sound, bool& crCheck);

		void onClickInfoPage(sf::RenderWindow& window, sf::Event& event1, int& stage,
			sf::SoundBuffer& buffer, sf::Sound& sound, SearchedAnEvent::inputData*& sData);

		void saveEditedEventData(SearchedAnEvent::inputData*& sData);

		void onClickEditPage(sf::RenderWindow& window, sf::Event& event1, int& stage,
			int& box, SearchedAnEvent::inputData*& sData,
			SearchedAnEvent::checkData*& cData, sf::SoundBuffer& buffer, sf::Sound& sound, bool& crCheck);
	}
	namespace TestKnowledge
	{
		static bool crCheck = true;

		struct inputData
		{
			bool generated = false;
			sf::String yearAnswer;
			sf::String titleText;
			sf::String topicText;
			bool revealed = false;
			bool checked = false;
		};

		void onClickTestPage(sf::RenderWindow& window, sf::Event& event1, int& stage, Event*& entireFile,
			inputData*& tData, int& box,
			EventGenerator*& eventG, sf::SoundBuffer& buffer, sf::Sound& sound, bool& crCheck);
	}
}