#include "../Header Files/UserChoiceManagement.h"
#include "../Header Files/EnterAnEvent.h"
#include "../Header Files/SearchAnEvent.h"
#include <iostream>
#include <vector>
#include <regex>

void ChoiceFlow::MainMenu::onClickMainMenu(sf::RenderWindow& window, sf::Event& event1, int& stage)
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
				stage = 1;
			}
			else if ((sf::Mouse::getPosition(window).x >= 260 && sf::Mouse::getPosition(window).x <= 560) &&
				(sf::Mouse::getPosition(window).y >= 455 && sf::Mouse::getPosition(window).y <= 540))
			{
				stage = 2;
			}
			else if ((sf::Mouse::getPosition(window).x >= 260 && sf::Mouse::getPosition(window).x <= 560) &&
				(sf::Mouse::getPosition(window).y >= 605 && sf::Mouse::getPosition(window).y <= 690))
			{
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

void ChoiceFlow::SearchedAnEvent::onClickSearchPage(sf::RenderWindow& window, sf::Event& event1, int& stage, Event*& head, Event*& tail, bool& crCheck, bool& sortCheck, sf::String& title, sf::String& year, sf::String& topic, sf::String& description, int& sortType)
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
				stage = 0;
				head->clearList(head);
				crCheck = true;
			}
			else if ((sf::Mouse::getPosition(window).x >= 85 && sf::Mouse::getPosition(window).x <= 710) &&
				(sf::Mouse::getPosition(window).y >= 125 && sf::Mouse::getPosition(window).y <= 182))
			{
				//Type
			}
			else if ((sf::Mouse::getPosition(window).x >= 85 && sf::Mouse::getPosition(window).x <= 178) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 255))
			{
				sortType = 1;
				head->mergeSortList(head, 1);
				tail = tail->getTail(head);
				head = head->getHead(tail);
			}
			else if ((sf::Mouse::getPosition(window).x >= 179 && sf::Mouse::getPosition(window).x <= 290) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 255))
			{
				sortType = 2;
				head->mergeSortList(head, 2);
				tail = tail->getTail(head);
			}
			else if ((sf::Mouse::getPosition(window).x >= 291 && sf::Mouse::getPosition(window).x <= 387) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 255))
			{
				sortType = 3;
				head->mergeSortList(head, 3);
				tail = tail->getTail(head);
			}
			else if ((sf::Mouse::getPosition(window).x >= 470 && sf::Mouse::getPosition(window).x <= 590) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 250))
			{
				sortCheck = true;
			}
			else if ((sf::Mouse::getPosition(window).x >= 592 && sf::Mouse::getPosition(window).x <= 710) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 250))
			{
				sortCheck = false;
			}
			else if ((sf::Mouse::getPosition(window).x >= 255 && sf::Mouse::getPosition(window).x <= 555) &&
				(sf::Mouse::getPosition(window).y >= 685 && sf::Mouse::getPosition(window).y <= 780))
			{
				//Search (Print only the first six found)
			}
			else if (sf::Mouse::getPosition(window).x >= 575 && sf::Mouse::getPosition(window).x <= 620)
			{
				stage = 4;
				head->saveEventInfo(head, tail, sf::Mouse::getPosition(window).y, 1, title, year, topic, description, sortCheck);
			}
			else if (sf::Mouse::getPosition(window).x >= 621 && sf::Mouse::getPosition(window).x <= 659)
			{
				stage = 5;
				head->saveEventInfo(head, tail, sf::Mouse::getPosition(window).y, 1, title, year, topic, description, sortCheck);
			}
			else if (sf::Mouse::getPosition(window).x >= 660 && sf::Mouse::getPosition(window).x <= 705)
			{
				head->removeNode(head, tail, sf::Mouse::getPosition(window).y, 1, sortCheck);
			}
		}

		/*if (event1.type == sf::Event::MouseMoved)
		{
			std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
		}*/
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

void ChoiceFlow::SearchedAnEvent::onClickEditPage(sf::RenderWindow& window, sf::Event& event1, int& stage, int& box, sf::String& title, sf::String& year, sf::String& topic, sf::String& description, bool& crCheck,int& sortType)
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

void ChoiceFlow::LastSearchedEvents::onClickLastEventsPage(sf::RenderWindow& window, sf::Event& event1, int& stage)
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
				stage = 0;
			}

		}
	}
}