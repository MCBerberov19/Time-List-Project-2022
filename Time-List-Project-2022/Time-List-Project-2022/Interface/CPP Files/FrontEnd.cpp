#include "../../Event Data Management/Header Files/UserChoiceManagement.h"
#include "../Header Files/FrontEnd.h"

namespace inputData
{
	int box;
	sf::String title;
	sf::String year;
	sf::String topic;
	sf::String description;

	int descStage = 0;
}

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
	sf::Text titleText, yearText, topicText, descriptionText1, descriptionText2, descriptionText3, descriptionText4, descriptionText5, descriptionText6, descriptionText7, descriptionText8;
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
	titleText.setString(inputData::title);
	yearText.setFont(font);
	yearText.setCharacterSize(25);
	yearText.setFillColor(sf::Color::Black);
	yearText.setPosition(210, 218); //4
	yearText.setString(inputData::year);
	topicText.setFont(font);
	topicText.setCharacterSize(25);
	topicText.setFillColor(sf::Color::Black);
	topicText.setPosition(505, 220); //12
	topicText.setString(inputData::topic);
	descriptionText1.setFont(font);
	descriptionText1.setCharacterSize(25);
	descriptionText1.setFillColor(sf::Color::Black);
	descriptionText1.setPosition(305, 338); //305, 338 first sentence , max size = 28
	//descriptionText1.setString("Testasdasdasdsadasdasdsadaaa");
	descriptionText2.setFont(font);
	descriptionText2.setCharacterSize(25);
	descriptionText2.setFillColor(sf::Color::Black);
	descriptionText2.setPosition(145, 370); //145, 370 first sentence, max size = 40
	//descriptionText2.setString("Testasdasdasdsadasdasdsadasdaasdasdsdsad"); 
	descriptionText3.setFont(font);
	descriptionText3.setCharacterSize(25);
	descriptionText3.setFillColor(sf::Color::Black);
	descriptionText3.setPosition(145, 402); //145, 402 first sentence, max size = 40
	//descriptionText3.setString("Testasdasdasdsadasdasdsadasdaasdasdsdsad");
	descriptionText4.setFont(font);
	descriptionText4.setCharacterSize(25);
	descriptionText4.setFillColor(sf::Color::Black);
	descriptionText4.setPosition(145, 434); //145, 434 first sentence, max size = 40
	//descriptionText4.setString("Testasdasdasdsadasdasdsadasdaasdasdsdsad");
	descriptionText5.setFont(font);
	descriptionText5.setCharacterSize(25);
	descriptionText5.setFillColor(sf::Color::Black);
	descriptionText5.setPosition(145, 466); //145, 466 first sentence, max size = 40
	//descriptionText5.setString("Testasdasdasdsadasdasdsadasdaasdasdsdsad");
	descriptionText6.setFont(font);
	descriptionText6.setCharacterSize(25);
	descriptionText6.setFillColor(sf::Color::Black);
	descriptionText6.setPosition(145, 498); //145, 498 first sentence, max size = 40
	//descriptionText6.setString("Testasdasdasdsadasdasdsadasdaasdasdsdsad");
	descriptionText7.setFont(font);
	descriptionText7.setCharacterSize(25);
	descriptionText7.setFillColor(sf::Color::Black);
	descriptionText7.setPosition(145, 530); //145, 530 first sentence, max size = 40
	//descriptionText7.setString("Testasdasdasdsadasdasdsadasdaasdasdsdsad");
	descriptionText8.setFont(font);
	descriptionText8.setCharacterSize(25);
	descriptionText8.setFillColor(sf::Color::Black);
	descriptionText8.setPosition(145, 562); //145, 562 first sentence, max size = 40
	//descriptionText8.setString("Testasdasdasdsadasdasdsadasdaasdasdsdsad");

	//if(inputData::description.getSize())

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
	/*if (inputData::description.getSize() > 0 && inpi)
	{
		descriptionText1.setString(inputData::description.substring(0, 28));
		if (inputData::description.getSize() > 28) //Create a function for this (ifs to check if the size is higher than and less than)
		{

		}
	}*/

	ChoiceFlow::EnterAnEvent::seperateLinesInDescription(inputData::description, descriptionText1, descriptionText2, descriptionText3, descriptionText4, descriptionText5, descriptionText6, descriptionText7, descriptionText8);

	window.draw(descriptionText1);
	window.draw(descriptionText2);
	window.draw(descriptionText3);
	window.draw(descriptionText4);
	window.draw(descriptionText5);
	window.draw(descriptionText6);
	window.draw(descriptionText7);
	window.draw(descriptionText8);
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
			ChoiceFlow::EnterAnEvent::onClickEventPage(window, event1, stage, inputData::box);
			printEnterAnEventPage(window);
			switch (inputData::box)
			{
				case 1:
					ChoiceFlow::EnterAnEvent::inputEventData(event1, inputData::title, 27, false);
					break;
				case 2:
					ChoiceFlow::EnterAnEvent::inputEventData(event1, inputData::year,4, true);
					break;
				case 3:
					ChoiceFlow::EnterAnEvent::inputEventData(event1, inputData::topic,12, false);
					break;
				case 4:
					ChoiceFlow::EnterAnEvent::inputEventData(event1, inputData::description, 308, false);
					break;
			}
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