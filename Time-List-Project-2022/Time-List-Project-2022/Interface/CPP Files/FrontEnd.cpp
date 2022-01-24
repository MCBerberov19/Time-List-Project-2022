#include "../../Event Data Management/Header Files/UserChoiceManagement.h"
#include "../Header Files/FrontEnd.h"
#include <iostream>

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
	sf::Text titleText, yearText, topicText, descriptionText;
	sf::Texture t1, t2, t3, t4, t5, t6, t7;
	sf::Font font;
	font.loadFromFile("Images and Fonts/arial.ttf");

	t1.loadFromFile("Images and Fonts/background.jpg");
	t2.loadFromFile("Images and Fonts/back.png");
	t3.loadFromFile("Images and Fonts/title.png");
	t4.loadFromFile("Images and Fonts/year.png");
	t5.loadFromFile("Images and Fonts/topic.png");
	t6.loadFromFile("Images and Fonts/description.png");
	t7.loadFromFile("Images and Fonts/enter.png");

	sf::Sprite background(t1);
	sf::Sprite backButton(t2);
	sf::Sprite title(t3);
	sf::Sprite year(t4);
	sf::Sprite topic(t5);
	sf::Sprite description(t6);
	sf::Sprite enter(t7);
	titleText.setFont(font);
	titleText.setCharacterSize(25);
	titleText.setFillColor(sf::Color::Black);
	titleText.setPosition(240, 125); //27
	std::string res = ChoiceFlow::EnterAnEvent::inputData::title.toAnsiString();
	std::cout << res;
	titleText.setString(ChoiceFlow::EnterAnEvent::inputData::title);
	yearText.setFont(font);
	yearText.setCharacterSize(25);
	yearText.setFillColor(sf::Color::Black);
	yearText.setPosition(210, 218); //4
	yearText.setString(ChoiceFlow::EnterAnEvent::inputData::year);
	topicText.setFont(font);
	topicText.setCharacterSize(25);
	topicText.setFillColor(sf::Color::Black);
	topicText.setPosition(505, 220); //12
	topicText.setString(ChoiceFlow::EnterAnEvent::inputData::topic);
	descriptionText.setFont(font);
	descriptionText.setCharacterSize(25);
	descriptionText.setFillColor(sf::Color::Black);
	descriptionText.setPosition(500, 550);
	descriptionText.setString(ChoiceFlow::EnterAnEvent::inputData::description);

	window.draw(background);
	backButton.setPosition(30,30);
	window.draw(backButton);
	title.setPosition(-50, -50);
	window.draw(title);
	window.draw(titleText);
	year.setPosition(150, 210);
	window.draw(year);
	window.draw(yearText);
	topic.setPosition(440, 208);
	window.draw(topic);
	window.draw(topicText);
	description.setPosition(10, 280);
	window.draw(description);
	window.draw(descriptionText);
	enter.setPosition(275, 645);
	window.draw(enter);
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
			ChoiceFlow::EnterAnEvent::onClickEventPage(window, event1, stage);
			printEnterAnEventPage(window);
			ChoiceFlow::EnterAnEvent::inputEventData(event1);
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