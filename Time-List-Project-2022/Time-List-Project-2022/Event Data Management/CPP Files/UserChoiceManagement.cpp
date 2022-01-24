#include "../Header Files/UserChoiceManagement.h"
#include "../../Interface/Header Files/FrontEnd.h"
#include <iostream>

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

void ChoiceFlow::EnterAnEvent::onClickEventPage(sf::RenderWindow& window, sf::Event& event1, int& stage)
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
				inputData::box = 1;
			}

			else if ((sf::Mouse::getPosition(window).x >= 150 && sf::Mouse::getPosition(window).x <= 305) && //year
				(sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 260))
			{
				inputData::box = 2;
			}

			else if ((sf::Mouse::getPosition(window).x >= 440 && sf::Mouse::getPosition(window).x <= 685) && //topic
				(sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 260))
			{
				inputData::box = 3;
			}

			else if ((sf::Mouse::getPosition(window).x >= 140 && sf::Mouse::getPosition(window).x <= 680) && //description
				(sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 600))
			{
				inputData::box = 4;
			}

			else if ((sf::Mouse::getPosition(window).x >= 285 && sf::Mouse::getPosition(window).x <= 525) && //enter
				(sf::Mouse::getPosition(window).y >= 650 && sf::Mouse::getPosition(window).y <= 735))
			{
				
			}
			else {
				inputData::box = 0;
			}
		}
	}
}

void ChoiceFlow::EnterAnEvent::inputEventData(sf::Event& event1)
{
	switch (inputData::box)
	{
	case 1:
		if (event1.type == sf::Event::TextEntered)
		{
			if (event1.text.unicode == '\b' && inputData::title.getSize() > 0)
			{
				inputData::title.erase(inputData::title.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && inputData::title.getSize() <= 27)
			{
				inputData::title += static_cast<char>(event1.text.unicode);
				if (inputData::title.getSize() >= 2
					&& inputData::title[inputData::title.getSize() - 1] ==
					inputData::title[inputData::title.getSize() - 2])
				{
					inputData::title.erase(inputData::title.getSize() - 1, 1);
				}

			}
		}
		break;
	case 2:
		if (event1.type == sf::Event::TextEntered)
		{
			if (event1.text.unicode == '\b' && inputData::year.getSize() > 0)
			{
				inputData::year.erase(inputData::year.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && inputData::year.getSize() <= 4)
			{
				inputData::year += static_cast<char>(event1.text.unicode);
				if (inputData::year.getSize() >= 2
					&& inputData::year[inputData::year.getSize() - 1] ==
					inputData::year[inputData::year.getSize() - 2])
				{
					inputData::year.erase(inputData::year.getSize() - 1, 1);
				}

			}
		}
		break;
	case 3:
		if (event1.type == sf::Event::TextEntered)
		{
			if (event1.text.unicode == '\b' && inputData::topic.getSize() > 0)
			{
				inputData::topic.erase(inputData::topic.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && inputData::topic.getSize() <= 12)
			{
				inputData::topic += static_cast<char>(event1.text.unicode);
				if (inputData::topic.getSize() >= 2
					&& inputData::topic[inputData::topic.getSize() - 1] ==
					inputData::topic[inputData::topic.getSize() - 2])
				{
					inputData::topic.erase(inputData::topic.getSize() - 1, 1);
				}

			}
		}
		break;
	case 4:
		if (event1.type == sf::Event::TextEntered)
		{
			if (event1.text.unicode == '\b' && inputData::description.getSize() > 0)
			{
				inputData::description.erase(inputData::description.getSize() - 1, 1);
			}
			else if (event1.text.unicode != '\b' && event1.text.unicode < 128 && inputData::description.getSize() <= 18)
			{
				inputData::description += static_cast<char>(event1.text.unicode);
				if (inputData::description.getSize() >= 2
					&& inputData::description[inputData::description.getSize() - 1] ==
					inputData::description[inputData::description.getSize() - 2])
				{
					inputData::description.erase(inputData::description.getSize() - 1, 1);
				}

			}
		}
		break;
	}
}

void ChoiceFlow::SearchedAnEvent::onClickSearchPage(sf::RenderWindow& window, sf::Event& event1, int& stage)
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