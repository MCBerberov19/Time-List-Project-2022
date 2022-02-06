#include "../Header Files/UserChoiceManagement.h"
#include "../Header Files/EnterAnEvent.h"
#include "../Header Files/SearchAnEvent.h"
#include "../Header Files/TestsGenerator.h"
#include <vector>
#include <regex>
#include <iostream>

void ChoiceFlow::MainMenu::playSound(sf::SoundBuffer& buffer, sf::Sound& sound, int soundType)
{
	switch (soundType) 
	{
		case 1:
			buffer.loadFromFile("Sounds/click.wav");
			break;
		case 2:
			buffer.loadFromFile("Sounds/click.wav");
			break;
		case 3:
			buffer.loadFromFile("Sounds/click.wav");
			break;
		case 4:
			buffer.loadFromFile("Sounds/click.wav");
			break;
		case 5:
			buffer.loadFromFile("Sounds/click.wav");
			break;
	}

	sound.setBuffer(buffer);
	sound.play();
}

void ChoiceFlow::MainMenu::onClickMainMenu(sf::RenderWindow& window, sf::Event& event1, int& stage, sf::SoundBuffer& buffer, sf::Sound& sound)
{
	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 260 && sf::Mouse::getPosition(window).x <= 560) &&
				(sf::Mouse::getPosition(window).y >= 305 && sf::Mouse::getPosition(window).y <= 390))
			{
				playSound(buffer, sound, 1);
				stage = 1;
			}
			else if ((sf::Mouse::getPosition(window).x >= 260 && sf::Mouse::getPosition(window).x <= 560) &&
				(sf::Mouse::getPosition(window).y >= 455 && sf::Mouse::getPosition(window).y <= 540))
			{
				playSound(buffer, sound, 1);
				stage = 2;
			}
			else if ((sf::Mouse::getPosition(window).x >= 260 && sf::Mouse::getPosition(window).x <= 560) &&
				(sf::Mouse::getPosition(window).y >= 605 && sf::Mouse::getPosition(window).y <= 690))
			{
				playSound(buffer, sound, 1);
				stage = 3;
			}
		}
	}
}

void ChoiceFlow::EnterAnEvent::onClickEventPage(sf::RenderWindow& window, sf::Event& event1, int& stage, int& box, sf::String& title, sf::String& year, sf::String& topic, sf::String& description)
{
	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 30 && sf::Mouse::getPosition(window).x <= 90) && //Back
				(sf::Mouse::getPosition(window).y >= 30 && sf::Mouse::getPosition(window).y <= 90))
			{
				//Going back to the main menu
				stage = 0;
			}

			else if ((sf::Mouse::getPosition(window).x >= 180 && sf::Mouse::getPosition(window).x <= 605) && //title
				(sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 160))
			{
				box = 1;
			}

			else if ((sf::Mouse::getPosition(window).x >= 150 && sf::Mouse::getPosition(window).x <= 305) && //year
				(sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 260))
			{
				box = 2;
			}

			else if ((sf::Mouse::getPosition(window).x >= 440 && sf::Mouse::getPosition(window).x <= 685) && //topic
				(sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 260))
			{
				box = 3;
			}

			else if ((sf::Mouse::getPosition(window).x >= 140 && sf::Mouse::getPosition(window).x <= 680) && //description
				(sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 600))
			{
				box = 4;
			}

			else if ((sf::Mouse::getPosition(window).x >= 285 && sf::Mouse::getPosition(window).x <= 525) && //enter
				(sf::Mouse::getPosition(window).y >= 650 && sf::Mouse::getPosition(window).y <= 735))
			{
				if (title.getSize() > 0 && topic.getSize() > 0 && description.getSize() > 0 && year.getSize() > 0)
				{
					//Enter an event button
					EnterAnEventC* newEvent = new EnterAnEventC(title, stoi(year.toAnsiString()), topic, description);
					delete newEvent;

					stage = 0;
					title = "";
					topic = "";
					description = "";
					year = "";
				}
			}
			else {
				box = 0;
			}
		}
	}
}

void ChoiceFlow::EnterAnEvent::inputEventData(sf::Event& event1, sf::String& text, int size, bool num)
{
	if (event1.type == sf::Event::TextEntered)
	{
		if (event1.text.unicode == '\b' && text.getSize() > 0)
		{
			text.erase(text.getSize() - 1, 1);
		}
		else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && text.getSize() <= size)
		{
			if (num)
			{
				if (event1.text.unicode > 47 && event1.text.unicode < 58)
				{
					text += static_cast<char>(event1.text.unicode);
				}
			}
			else
			{
				text += static_cast<char>(event1.text.unicode);
				if (text.getSize() >= 2
					&& text[text.getSize() - 1] ==
					text[text.getSize() - 2])
				{
					text.erase(text.getSize() - 1, 1);
				}
			}
		}
	}
}

void ChoiceFlow::EnterAnEvent::seperateLinesInDescription(sf::String& description, sf::Text& descriptionText1, sf::Text& descriptionText2, sf::Text& descriptionText3, sf::Text& descriptionText4, sf::Text& descriptionText5, sf::Text& descriptionText6, sf::Text& descriptionText7, sf::Text& descriptionText8)
{
	if (description.getSize() > 0 && description.getSize() <= 28)
	{
		descriptionText1.setString(description.substring(0, 29));
	}
	else if (description.getSize() > 28 && description.getSize() <= 71)
	{
		descriptionText1.setString(description.substring(0, 29));
		descriptionText2.setString(description.substring(29, 72));
	}
	else if (description.getSize() > 71 && description.getSize() <= 116)
	{
		descriptionText1.setString(description.substring(0, 29));
		descriptionText2.setString(description.substring(29, 43));
		descriptionText3.setString(description.substring(72, 117));
	}
	else if (description.getSize() > 116 && description.getSize() <= 160)
	{
		descriptionText1.setString(description.substring(0, 29));
		descriptionText2.setString(description.substring(29, 43));
		descriptionText3.setString(description.substring(72, 44));
		descriptionText4.setString(description.substring(116, 161));
	}
	else if (description.getSize() > 160 && description.getSize() <= 203)
	{
		descriptionText1.setString(description.substring(0, 29));
		descriptionText2.setString(description.substring(29, 43));
		descriptionText3.setString(description.substring(72, 44));
		descriptionText4.setString(description.substring(116, 44));
		descriptionText5.setString(description.substring(160, 204));
	}
	else if (description.getSize() > 203 && description.getSize() <= 244)
	{
		descriptionText1.setString(description.substring(0, 29));
		descriptionText2.setString(description.substring(29, 43));
		descriptionText3.setString(description.substring(72, 44));
		descriptionText4.setString(description.substring(116, 44));
		descriptionText5.setString(description.substring(160, 43));
		descriptionText6.setString(description.substring(203, 245));
	}
	else if (description.getSize() > 244 && description.getSize() <= 284)
	{
		descriptionText1.setString(description.substring(0, 29));
		descriptionText2.setString(description.substring(29, 43));
		descriptionText3.setString(description.substring(72, 44));
		descriptionText4.setString(description.substring(116, 44));
		descriptionText5.setString(description.substring(160, 43));
		descriptionText6.setString(description.substring(203, 41));
		descriptionText7.setString(description.substring(244, 285));
	}
	else if (description.getSize() > 284 && description.getSize() <= 317)
	{
		descriptionText1.setString(description.substring(0, 29));
		descriptionText2.setString(description.substring(29, 43));
		descriptionText3.setString(description.substring(72, 44));
		descriptionText4.setString(description.substring(116, 44));
		descriptionText5.setString(description.substring(160, 43));
		descriptionText6.setString(description.substring(203, 41));
		descriptionText7.setString(description.substring(244, 40));
		descriptionText8.setString(description.substring(284, 317));
	}
}

void ChoiceFlow::SearchedAnEvent::onClickSearchPage(sf::RenderWindow& window, sf::Event& event1, int& stage, Event*& head, Event*& tail, bool& crCheck, bool& sortCheck, sf::String& title, sf::String& year, sf::String& topic, sf::String& description, int& sortType, int& box, sf::String& searchData, Event*& entireFile, sf::SoundBuffer& buffer, sf::Sound& sound)
{
	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 30 && sf::Mouse::getPosition(window).x <= 90) &&
				(sf::Mouse::getPosition(window).y >= 30 && sf::Mouse::getPosition(window).y <= 90))
			{
				//Going back to the main menu
				stage = 0;
				SearchAnEventNodes::ClearList::clearList(head);
				crCheck = true;
				box = 0;
				searchData = "";
				sortType = 1;
				sortCheck = true;
			}
			else if ((sf::Mouse::getPosition(window).x >= 85 && sf::Mouse::getPosition(window).x <= 710) &&
				(sf::Mouse::getPosition(window).y >= 125 && sf::Mouse::getPosition(window).y <= 182))
			{
				//Type box
				box = 1;
			}
			else if ((sf::Mouse::getPosition(window).x >= 85 && sf::Mouse::getPosition(window).x <= 178) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 255))
			{
				//Sort by title
				sortType = 1;
				head->mergeSortList(head, 1);
				tail = tail->getTail(head);
				head = head->getHead(tail);
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 179 && sf::Mouse::getPosition(window).x <= 290) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 255))
			{
				//Sort by year
				sortType = 2;
				head->mergeSortList(head, 2);
				tail = tail->getTail(head);
				head = head->getHead(tail);
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 291 && sf::Mouse::getPosition(window).x <= 387) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 255))
			{
				//Sort by topic
				sortType = 3;
				head->mergeSortList(head, 3);
				tail = tail->getTail(head);
				head = head->getHead(tail);
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 470 && sf::Mouse::getPosition(window).x <= 590) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 250))
			{
				//Sort ascending
				sortCheck = true;
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 592 && sf::Mouse::getPosition(window).x <= 710) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 250))
			{
				//Sort descending
				sortCheck = false;
				tail = tail->getTail(head);
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 255 && sf::Mouse::getPosition(window).x <= 555) &&
				(sf::Mouse::getPosition(window).y >= 685 && sf::Mouse::getPosition(window).y <= 780))
			{
				//Search button
				if (searchData.getSize() > 0)
				{
					sortCheck = true;
					head = SearchAnEventNodes::PrintList::printFoundData(entireFile, searchData, &Event::appendNode);
					box = 0;
					lastSearched = searchData;
					searchData = "";
					ChoiceFlow::SearchedAnEvent::ifSearched = true;
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 575 && sf::Mouse::getPosition(window).x <= 620)
			{
				//Info button
				stage = 4;
				SearchAnEventNodes::SaveList::saveEventInfo(head, tail, sf::Mouse::getPosition(window).y, 1, title, year, topic, description, sortCheck);
				box = 0;
			}
			else if (sf::Mouse::getPosition(window).x >= 621 && sf::Mouse::getPosition(window).x <= 659)
			{
				//Edit button
				stage = 5;
				SearchAnEventNodes::SaveList::saveEventInfo(head, tail, sf::Mouse::getPosition(window).y, 1, title, year, topic, description, sortCheck);
				box = 0;
			}
			else if (sf::Mouse::getPosition(window).x >= 660 && sf::Mouse::getPosition(window).x <= 705)
			{
				//Remove an event
				ChoiceFlow::MainMenu::playSound(buffer, sound, 2);
				if (ChoiceFlow::SearchedAnEvent::ifSearched)
				{
					head->removeAfterSearch(head, tail, sf::Mouse::getPosition(window).y, 1, sortCheck, deletedTitle);
					SearchAnEventNodes::SaveList::saveAfterRemoveWhenSearched(entireFile, deletedTitle);
					SearchAnEventNodes::ClearList::clearList(entireFile);
					entireFile = new Event;
					SearchAnEventNodes::TakeNodes::takeDataFromFile(entireFile, &Event::appendNode, &Event::removeHead);
				}
				else
				{
					head->removeNode(head, tail, sf::Mouse::getPosition(window).y, 1, sortCheck);
					SearchAnEventNodes::TakeNodes::takeDataFromFile(entireFile, &Event::appendNode, &Event::removeHead);
				}
				box = 0;
			}
			else
			{
				box = 0;
			}
		}

	}
}

void ChoiceFlow::SearchedAnEvent::onClickInfoPage(sf::RenderWindow& window, sf::Event& event1, int& stage)
{
	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 30 && sf::Mouse::getPosition(window).x <= 90) &&
				(sf::Mouse::getPosition(window).y >= 30 && sf::Mouse::getPosition(window).y <= 90))
			{
				//Going back to the search menu
				stage = 2;
			}
		}
	}
}

void ChoiceFlow::SearchedAnEvent::saveEditedEventData(sf::String& title, sf::String& year, sf::String& topic, sf::String& description)
{
	std::ifstream curData; curData.open("Events.txt", std::ios::in | std::ios::app);
	std::string data, editedData, curTitle;
	std::vector<std::string> lines;
	std::smatch yearMatch;

	editedData = title.toAnsiString() + " " + year.toAnsiString() + " " + topic.toAnsiString() + " " + description.toAnsiString();
	bool found = true;
	int pos = 0;

	while (std::getline(curData, data))
	{
		std::regex_search(data, yearMatch, std::regex("[1-9]"));
		curTitle = data.substr(0, yearMatch.position() - 1);;
		lines.push_back(data);
		if (inputData::oldTitle == curTitle)
		{
			found = false;
		}
		else
		{
			if (found)
			{
				pos++;
			}
		}
	}
	curData.close();

	std::ofstream newData; newData.open("Events.txt", std::ios::out | std::ios::trunc);

	for (size_t i = 0; i < lines.size(); i++)
	{
		if (i == pos)
		{
			newData << editedData << std::endl;
		}
		else
		{
			newData << lines[i] << std::endl;
		}
	}
	newData.close();
}

void ChoiceFlow::SearchedAnEvent::onClickEditPage(sf::RenderWindow& window, sf::Event& event1, int& stage, int& box, sf::String& title, sf::String& year, sf::String& topic, sf::String& description, bool& crCheck, int& sortType)
{
	if (inputData::oldTitleCheck)
	{
		inputData::oldTitle = title;
		inputData::oldTitleCheck = false;
	}

	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 30 && sf::Mouse::getPosition(window).x <= 90) &&
				(sf::Mouse::getPosition(window).y >= 30 && sf::Mouse::getPosition(window).y <= 90))
			{
				//Going back to the search menu
				stage = 2;
				inputData::oldTitleCheck = true;
			}
			else if ((sf::Mouse::getPosition(window).x >= 180 && sf::Mouse::getPosition(window).x <= 605) && //title
				(sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 160))
			{
				box = 1;
			}

			else if ((sf::Mouse::getPosition(window).x >= 150 && sf::Mouse::getPosition(window).x <= 305) && //year
				(sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 260))
			{
				box = 2;
			}

			else if ((sf::Mouse::getPosition(window).x >= 440 && sf::Mouse::getPosition(window).x <= 685) && //topic
				(sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 260))
			{
				box = 3;
			}

			else if ((sf::Mouse::getPosition(window).x >= 140 && sf::Mouse::getPosition(window).x <= 680) && //description
				(sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 600))
			{
				box = 4;
			}

			else if ((sf::Mouse::getPosition(window).x >= 277 && sf::Mouse::getPosition(window).x <= 577) && //enter
				(sf::Mouse::getPosition(window).y >= 650 && sf::Mouse::getPosition(window).y <= 750))
			{
				//Save edited an event data
				if (title.getSize() > 0 && topic.getSize() > 0 && description.getSize() > 0 && year.getSize() > 0)
				{
					saveEditedEventData(title, year, topic, description);

					inputData::oldTitleCheck = true;
					crCheck = true;
					title = "";
					topic = "";
					description = "";
					year = "";
					sortType = 1;
					stage = 0;

				}
			}
			else {
				box = 0;
			}
		}

	}
}

void ChoiceFlow::TestKnowledge::onClickTestPage(sf::RenderWindow& window, sf::Event& event1, int& stage, Event*& entireFile, bool& crCheck, int& box, sf::String& yearAnswer, sf::String& titleText, sf::String& topicText, EventGenerator*& eventG, bool& revealed, bool& generated, bool& checked)
{
	while (window.pollEvent(event1))
	{
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 30 && sf::Mouse::getPosition(window).x <= 90) &&
				(sf::Mouse::getPosition(window).y >= 30 && sf::Mouse::getPosition(window).y <= 90))
			{
				//Going back to the main menu
				stage = 0;
				crCheck = true;
				SearchAnEventNodes::ClearList::clearList(entireFile);
				box = 0;
				titleText = ""; topicText = ""; yearAnswer = ""; revealed = false; generated = false; checked = false;
				if (generated)
					delete eventG;
			}
			else if ((sf::Mouse::getPosition(window).x >= 135 && sf::Mouse::getPosition(window).x <= 290) &&
				(sf::Mouse::getPosition(window).y >= 310 && sf::Mouse::getPosition(window).y <= 355))
			{
				//Type box
				box = 1;
			}
			else if ((sf::Mouse::getPosition(window).x >= 240 && sf::Mouse::getPosition(window).x <= 565) &&
				(sf::Mouse::getPosition(window).y >= 485 && sf::Mouse::getPosition(window).y <= 575))
			{
				//Generate an event
				if (SearchAnEventNodes::TakeNodes::takeLastNodePos(entireFile) > 1)
				{
					if (generated) delete eventG;
					eventG = new EventGenerator(entireFile, &SearchAnEventNodes::TakeNodes::takeLastNodePos);
					titleText = eventG->title; topicText = eventG->topic;
					box = 0;
					yearAnswer = "";
					revealed = false; generated = true; checked = false;
				}
			}
			else if ((sf::Mouse::getPosition(window).x >= 35 && sf::Mouse::getPosition(window).x <= 275) &&
				(sf::Mouse::getPosition(window).y >= 695 && sf::Mouse::getPosition(window).y <= 775))
			{
				//Reveal the answer of the event
				if (generated)
				{
					yearAnswer = std::to_string(eventG->convertToDecimalFromBinary());
					revealed = true;
					checked = false;
				}
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 525 && sf::Mouse::getPosition(window).x <= 765) &&
				(sf::Mouse::getPosition(window).y >= 700 && sf::Mouse::getPosition(window).y <= 775))
			{
				//Check user answer
				if (generated && yearAnswer.getSize() > 0)
				{
					checked = true;
					revealed = false;
				}
				box = 0;
			}
			else
			{
				box = 0;
			}
		}
	}
}