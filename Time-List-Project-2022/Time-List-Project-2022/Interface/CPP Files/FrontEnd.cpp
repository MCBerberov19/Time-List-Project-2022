#include "../../Event Data Management/Header Files/UserChoiceManagement.h"
#include "../Header Files/FrontEnd.h"

void printMainMenu(sf::RenderWindow& window)
{
	sf::Texture t1, t2, t3, t4, t5;

	t1.loadFromFile("Images and Fonts/background.jpg");
	t2.loadFromFile("Images and Fonts/logo.png");
	t3.loadFromFile("Images and Fonts/enter_button.png");
	t4.loadFromFile("Images and Fonts/search_button.png");
	t5.loadFromFile("Images and Fonts/last_button.png");

	sf::Sprite background(t1);
	sf::Sprite logo(t2);
	sf::Sprite enterButton(t3);
	sf::Sprite searchButton(t4);
	sf::Sprite lastButton(t5);

	window.draw(background);
	logo.setPosition(157, 40);
	window.draw(logo);
	enterButton.setPosition(160, 240);
	window.draw(enterButton);
	searchButton.setPosition(160,390);
	window.draw(searchButton);
	lastButton.setPosition(160, 540);
	window.draw(lastButton);
}

void printEnterAnEventPage(sf::RenderWindow& window)
{
	sf::Texture t1,t2;
	
	t1.loadFromFile("Images and Fonts/background.jpg");
	t2.loadFromFile("Images and Fonts/back.png");

	sf::Sprite background(t1);
	sf::Sprite backButton(t2);

	window.draw(background);
	backButton.setPosition(30,30);
	window.draw(backButton);
}

void printSearchAnEventPage(sf::RenderWindow& window)
{
	sf::Texture t1, t2;

	t1.loadFromFile("Images and Fonts/background.jpg");
	t2.loadFromFile("Images and Fonts/back.png");

	sf::Sprite background(t1);
	sf::Sprite backButton(t2);

	window.draw(background);
	backButton.setPosition(30, 30);
	window.draw(backButton);
}

void printLastSearchedEventsPage(sf::RenderWindow& window)
{
	sf::Texture t1, t2;

	t1.loadFromFile("Images and Fonts/background.jpg");
	t2.loadFromFile("Images and Fonts/back.png");

	sf::Sprite background(t1);
	sf::Sprite backButton(t2);

	window.draw(background);
	backButton.setPosition(30, 30);
	window.draw(backButton);
}

void setMenu(int &stage)
{

	sf::RenderWindow window(sf::VideoMode(800, 800), "History Notes", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	while (window.isOpen())
	{
		sf::Event event1;

		switch(stage)
		{
		case 0:
			printMainMenu(window);
			ChoiceFlow::MainMenu::onClickMainMenu(window, event1, stage);
			break;
		case 1:
			printEnterAnEventPage(window);
			ChoiceFlow::EnterAnEvent::onClickEventPage(window, event1, stage);
			break;
		case 2:
			printSearchAnEventPage(window);
			ChoiceFlow::SearchedAnEvent::onClickSearchPage(window, event1, stage);
			break;
		case 3:
			printLastSearchedEventsPage(window);
			ChoiceFlow::LastSearchedEvents::onClickLastEventsPage(window, event1, stage);
			break;
		}
		window.display();
		window.clear();
	}

}	