#include "../Header Files/UserChoiceManagement.h"
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

void ChoiceFlow::EnterAnEvent::onClickEventPage(sf::RenderWindow& window, sf::Event& event1, int& stage, int& box)
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
	std::cout << description.getSize() << std::endl;

	if (description.getSize() > 0 && description.getSize() <= 30)
	{
		descriptionText1.setString(description.substring(0, description.getSize()));
	}
	else if (description.getSize() > 30 && description.getSize() <= 68)
	{
		descriptionText1.setString(description.substring(0, 30));
		descriptionText2.setString(description.substring(30, 67));
	}
	else if (description.getSize() > 68 && description.getSize() <= 108)
	{
		descriptionText1.setString(description.substring(0, 27));
		descriptionText2.setString(description.substring(27, 67));
		descriptionText3.setString(description.substring(67, 107));
	}
	else if (description.getSize() > 108 && description.getSize() <= 148)
	{
		descriptionText1.setString(description.substring(0, 27));
		descriptionText2.setString(description.substring(27, 67));
		descriptionText3.setString(description.substring(67, 107));
		descriptionText4.setString(description.substring(107, 147));
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