#include "../../Event Data Management/Header Files/UserChoiceManagement.h"
#include "../Header Files/FrontEnd.h"
#include "../../Event Data Management/Header Files/Event.h"
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
	searchButton.setPosition(160, 390);
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
	titleText.setPosition(240, 125);
	titleText.setString(ChoiceFlow::EnterAnEvent::inputData::title);
	yearText.setFont(font);
	yearText.setCharacterSize(25);
	yearText.setFillColor(sf::Color::Black);
	yearText.setPosition(210, 218);
	yearText.setString(ChoiceFlow::EnterAnEvent::inputData::year);
	topicText.setFont(font);
	topicText.setCharacterSize(25);
	topicText.setFillColor(sf::Color::Black);
	topicText.setPosition(505, 220);
	topicText.setString(ChoiceFlow::EnterAnEvent::inputData::topic);
	descriptionText1.setFont(font);
	descriptionText1.setCharacterSize(25);
	descriptionText1.setFillColor(sf::Color::Black);
	descriptionText1.setPosition(305, 338);
	descriptionText2.setFont(font);
	descriptionText2.setCharacterSize(25);
	descriptionText2.setFillColor(sf::Color::Black);
	descriptionText2.setPosition(145, 370);
	descriptionText3.setFont(font);
	descriptionText3.setCharacterSize(25);
	descriptionText3.setFillColor(sf::Color::Black);
	descriptionText3.setPosition(145, 402);
	descriptionText4.setFont(font);
	descriptionText4.setCharacterSize(25);
	descriptionText4.setFillColor(sf::Color::Black);
	descriptionText4.setPosition(145, 434);
	descriptionText5.setFont(font);
	descriptionText5.setCharacterSize(25);
	descriptionText5.setFillColor(sf::Color::Black);
	descriptionText5.setPosition(145, 466);
	descriptionText6.setFont(font);
	descriptionText6.setCharacterSize(25);
	descriptionText6.setFillColor(sf::Color::Black);
	descriptionText6.setPosition(145, 498);
	descriptionText7.setFont(font);
	descriptionText7.setCharacterSize(25);
	descriptionText7.setFillColor(sf::Color::Black);
	descriptionText7.setPosition(145, 530);
	descriptionText8.setFont(font);
	descriptionText8.setCharacterSize(25);
	descriptionText8.setFillColor(sf::Color::Black);
	descriptionText8.setPosition(145, 562);

	window.draw(background);
	backButton.setPosition(30, 30);
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

	ChoiceFlow::EnterAnEvent::seperateLinesInDescription(ChoiceFlow::EnterAnEvent::inputData::description, descriptionText1, descriptionText2, descriptionText3, descriptionText4, descriptionText5, descriptionText6, descriptionText7, descriptionText8);

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

void printSearchAnEventPage(sf::RenderWindow& window, Event*& head, Event*& tail)
{
	sf::Texture t1, t2, t3, t4, t5, t6 ,t7, t8, t9, t10;
	sf::Font font;
	font.loadFromFile("Images and Fonts/arial.ttf");

	t1.loadFromFile("Images and Fonts/background.jpg");
	t2.loadFromFile("Images and Fonts/back.png");
	t3.loadFromFile("Images and Fonts/search_box.png");
	t4.loadFromFile("Images and Fonts/ascending_sort.png");
	t5.loadFromFile("Images and Fonts/descending_sort.png");
	t6.loadFromFile("Images and Fonts/sort_by_title.png");
	t7.loadFromFile("Images and Fonts/sort_by_year.png");
	t8.loadFromFile("Images and Fonts/sort_by_topic.png");
	t9.loadFromFile("Images and Fonts/event_board.png");
	t10.loadFromFile("Images and Fonts/search.png");

	sf::Sprite background(t1);
	sf::Sprite backButton(t2);
	sf::Sprite searchBox(t3);
	sf::Sprite ascendingSort(t4);
	sf::Sprite descendingSort(t5);
	sf::Sprite sortByTitle(t6);
	sf::Sprite sortByYear(t7);
	sf::Sprite sortByTopic(t8);
	sf::Sprite eventBoard(t9);
	sf::Sprite searchButton(t10);

	window.draw(background);
	backButton.setPosition(30, 30);
	window.draw(backButton);
	searchBox.setPosition(-50, 50);
	window.draw(searchBox);
	ascendingSort.setPosition(333, 160);
	descendingSort.setPosition(333, 160); // Create check for printing ascending or descending on click
	//eventBoard.setPosition(63, 220); <- these are the cordinates
	if (ChoiceFlow::SearchedAnEvent::sortCheck)
	{
		window.draw(ascendingSort);
		head->printList(window, head, eventBoard, font);
	}
	else
	{
		window.draw(descendingSort);
		tail->printListReversed(window, tail, eventBoard, font);
	}
	sortByTitle.setPosition(-10, 78);
	sortByYear.setPosition(-90, 10);
	sortByTopic.setPosition(-90, 10);
	switch (ChoiceFlow::SearchedAnEvent::sortType)
	{
	case 1:
		window.draw(sortByTitle);
		break;
	case 2:
		window.draw(sortByYear);
		break;
	case 3:
		window.draw(sortByTopic);
		break;
	}
	searchButton.setPosition(252, 685);
	window.draw(searchButton);
}

void printInfoPage(sf::RenderWindow& window)
{
	sf::Text titleText, yearText, topicText, descriptionText1, descriptionText2, descriptionText3, descriptionText4, descriptionText5, descriptionText6, descriptionText7, descriptionText8;
	sf::Texture t1, t2, t3, t4, t5, t6;
	sf::Font font;
	font.loadFromFile("Images and Fonts/arial.ttf");

	t1.loadFromFile("Images and Fonts/background.jpg");
	t2.loadFromFile("Images and Fonts/back.png");
	t3.loadFromFile("Images and Fonts/title.png");
	t4.loadFromFile("Images and Fonts/year.png");
	t5.loadFromFile("Images and Fonts/topic.png");
	t6.loadFromFile("Images and Fonts/description.png");

	sf::Sprite background(t1);
	sf::Sprite backButton(t2);
	sf::Sprite title(t3);
	sf::Sprite year(t4);
	sf::Sprite topic(t5);
	sf::Sprite description(t6);

	titleText.setFont(font);
	titleText.setCharacterSize(25);
	titleText.setFillColor(sf::Color::Black);
	titleText.setPosition(240, 125);
	titleText.setString(ChoiceFlow::SearchedAnEvent::inputData::title);
	yearText.setFont(font);
	yearText.setCharacterSize(25);
	yearText.setFillColor(sf::Color::Black);
	yearText.setPosition(210, 218);
	yearText.setString(ChoiceFlow::SearchedAnEvent::inputData::year);
	topicText.setFont(font);
	topicText.setCharacterSize(25);
	topicText.setFillColor(sf::Color::Black);
	topicText.setPosition(505, 220);
	topicText.setString(ChoiceFlow::SearchedAnEvent::inputData::topic);
	descriptionText1.setFont(font);
	descriptionText1.setCharacterSize(25);
	descriptionText1.setFillColor(sf::Color::Black);
	descriptionText1.setPosition(305, 338);
	descriptionText2.setFont(font);
	descriptionText2.setCharacterSize(25);
	descriptionText2.setFillColor(sf::Color::Black);
	descriptionText2.setPosition(145, 370);
	descriptionText3.setFont(font);
	descriptionText3.setCharacterSize(25);
	descriptionText3.setFillColor(sf::Color::Black);
	descriptionText3.setPosition(145, 402);
	descriptionText4.setFont(font);
	descriptionText4.setCharacterSize(25);
	descriptionText4.setFillColor(sf::Color::Black);
	descriptionText4.setPosition(145, 434);
	descriptionText5.setFont(font);
	descriptionText5.setCharacterSize(25);
	descriptionText5.setFillColor(sf::Color::Black);
	descriptionText5.setPosition(145, 466);
	descriptionText6.setFont(font);
	descriptionText6.setCharacterSize(25);
	descriptionText6.setFillColor(sf::Color::Black);
	descriptionText6.setPosition(145, 498);
	descriptionText7.setFont(font);
	descriptionText7.setCharacterSize(25);
	descriptionText7.setFillColor(sf::Color::Black);
	descriptionText7.setPosition(145, 530);
	descriptionText8.setFont(font);
	descriptionText8.setCharacterSize(25);
	descriptionText8.setFillColor(sf::Color::Black);
	descriptionText8.setPosition(145, 562);

	window.draw(background);
	backButton.setPosition(30, 30);
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

	ChoiceFlow::EnterAnEvent::seperateLinesInDescription(ChoiceFlow::SearchedAnEvent::inputData::description, descriptionText1, descriptionText2, descriptionText3, descriptionText4, descriptionText5, descriptionText6, descriptionText7, descriptionText8);

	window.draw(descriptionText1);
	window.draw(descriptionText2);
	window.draw(descriptionText3);
	window.draw(descriptionText4);
	window.draw(descriptionText5);
	window.draw(descriptionText6);
	window.draw(descriptionText7);
	window.draw(descriptionText8);
}

void printEditPage(sf::RenderWindow& window)
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
	t7.loadFromFile("Images and Fonts/save.png");

	sf::Sprite background(t1);
	sf::Sprite backButton(t2);
	sf::Sprite title(t3);
	sf::Sprite year(t4);
	sf::Sprite topic(t5);
	sf::Sprite description(t6);
	sf::Sprite save(t7);
	titleText.setFont(font);
	titleText.setCharacterSize(25);
	titleText.setFillColor(sf::Color::Black);
	titleText.setPosition(240, 125);
	titleText.setString(ChoiceFlow::SearchedAnEvent::inputData::title);
	yearText.setFont(font);
	yearText.setCharacterSize(25);
	yearText.setFillColor(sf::Color::Black);
	yearText.setPosition(210, 218);
	yearText.setString(ChoiceFlow::SearchedAnEvent::inputData::year);
	topicText.setFont(font);
	topicText.setCharacterSize(25);
	topicText.setFillColor(sf::Color::Black);
	topicText.setPosition(505, 220);
	topicText.setString(ChoiceFlow::SearchedAnEvent::inputData::topic);
	descriptionText1.setFont(font);
	descriptionText1.setCharacterSize(25);
	descriptionText1.setFillColor(sf::Color::Black);
	descriptionText1.setPosition(305, 338);
	descriptionText2.setFont(font);
	descriptionText2.setCharacterSize(25);
	descriptionText2.setFillColor(sf::Color::Black);
	descriptionText2.setPosition(145, 370);
	descriptionText3.setFont(font);
	descriptionText3.setCharacterSize(25);
	descriptionText3.setFillColor(sf::Color::Black);
	descriptionText3.setPosition(145, 402);
	descriptionText4.setFont(font);
	descriptionText4.setCharacterSize(25);
	descriptionText4.setFillColor(sf::Color::Black);
	descriptionText4.setPosition(145, 434);
	descriptionText5.setFont(font);
	descriptionText5.setCharacterSize(25);
	descriptionText5.setFillColor(sf::Color::Black);
	descriptionText5.setPosition(145, 466);
	descriptionText6.setFont(font);
	descriptionText6.setCharacterSize(25);
	descriptionText6.setFillColor(sf::Color::Black);
	descriptionText6.setPosition(145, 498);
	descriptionText7.setFont(font);
	descriptionText7.setCharacterSize(25);
	descriptionText7.setFillColor(sf::Color::Black);
	descriptionText7.setPosition(145, 530);
	descriptionText8.setFont(font);
	descriptionText8.setCharacterSize(25);
	descriptionText8.setFillColor(sf::Color::Black);
	descriptionText8.setPosition(145, 562);

	window.draw(background);
	backButton.setPosition(30, 30);
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

	ChoiceFlow::EnterAnEvent::seperateLinesInDescription(ChoiceFlow::SearchedAnEvent::inputData::description, descriptionText1, descriptionText2, descriptionText3, descriptionText4, descriptionText5, descriptionText6, descriptionText7, descriptionText8);

	window.draw(descriptionText1);
	window.draw(descriptionText2);
	window.draw(descriptionText3);
	window.draw(descriptionText4);
	window.draw(descriptionText5);
	window.draw(descriptionText6);
	window.draw(descriptionText7);
	window.draw(descriptionText8);
	save.setPosition(270, 645);
	window.draw(save);
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

void setMenu(int& stage)
{

	sf::RenderWindow window(sf::VideoMode(800, 800), "History Notes", sf::Style::Close);
	window.setFramerateLimit(30);

	Event* head = NULL;
	Event* tail = NULL;

	while (window.isOpen())
	{
		sf::Event event1;

		switch (stage)
		{
		case 0:
			printMainMenu(window);
			ChoiceFlow::MainMenu::onClickMainMenu(window, event1, stage);
			break;
		case 1:
			ChoiceFlow::EnterAnEvent::onClickEventPage(window, event1, stage, ChoiceFlow::EnterAnEvent::inputData::box, ChoiceFlow::EnterAnEvent::inputData::title, ChoiceFlow::EnterAnEvent::inputData::year, ChoiceFlow::EnterAnEvent::inputData::topic, ChoiceFlow::EnterAnEvent::inputData::description);
			printEnterAnEventPage(window);
			switch (ChoiceFlow::EnterAnEvent::inputData::box)
			{
			case 1:
				ChoiceFlow::EnterAnEvent::inputEventData(event1, ChoiceFlow::EnterAnEvent::inputData::title, 27, false);
				break;
			case 2:
				ChoiceFlow::EnterAnEvent::inputEventData(event1, ChoiceFlow::EnterAnEvent::inputData::year, 4, true);
				break;
			case 3:
				ChoiceFlow::EnterAnEvent::inputEventData(event1, ChoiceFlow::EnterAnEvent::inputData::topic, 12, false);
				break;
			case 4:
				ChoiceFlow::EnterAnEvent::inputEventData(event1, ChoiceFlow::EnterAnEvent::inputData::description, 316, false);
				break;
			}
			break;
		case 2:
			if (ChoiceFlow::SearchedAnEvent::crCheck)
			{
				head = new Event; tail = new Event;
				head->takeDataFromFile(head);
				head->mergeSortList(head,1);
				tail = tail->getTail(head);
				head = head->getHead(tail);
				ChoiceFlow::SearchedAnEvent::crCheck = false;
			}
			printSearchAnEventPage(window, head, tail);
			ChoiceFlow::SearchedAnEvent::onClickSearchPage(window, event1, stage, head, tail, ChoiceFlow::SearchedAnEvent::crCheck, ChoiceFlow::SearchedAnEvent::sortCheck, ChoiceFlow::SearchedAnEvent::inputData::title, ChoiceFlow::SearchedAnEvent::inputData::year, ChoiceFlow::SearchedAnEvent::inputData::topic, ChoiceFlow::SearchedAnEvent::inputData::description, ChoiceFlow::SearchedAnEvent::sortType);
			if (ChoiceFlow::EnterAnEvent::inputData::box == 1)
			{
				//input
			}
			break;
		case 3:
			printLastSearchedEventsPage(window);
			ChoiceFlow::LastSearchedEvents::onClickLastEventsPage(window, event1, stage);
			break;
		case 4:
			printInfoPage(window);
			ChoiceFlow::SearchedAnEvent::onClickInfoPage(window, event1, stage);
			break;
		case 5:
			printEditPage(window);
			ChoiceFlow::SearchedAnEvent::onClickEditPage(window, event1, stage, ChoiceFlow::EnterAnEvent::inputData::box, ChoiceFlow::SearchedAnEvent::inputData::title, ChoiceFlow::SearchedAnEvent::inputData::year, ChoiceFlow::SearchedAnEvent::inputData::topic, ChoiceFlow::SearchedAnEvent::inputData::description, ChoiceFlow::SearchedAnEvent::crCheck, ChoiceFlow::SearchedAnEvent::sortType);
			switch (ChoiceFlow::EnterAnEvent::inputData::box)
			{
			case 1:
				ChoiceFlow::EnterAnEvent::inputEventData(event1, ChoiceFlow::SearchedAnEvent::inputData::title, 27, false);
				break;
			case 2:
				ChoiceFlow::EnterAnEvent::inputEventData(event1, ChoiceFlow::SearchedAnEvent::inputData::year, 4, true);
				break;
			case 3:
				ChoiceFlow::EnterAnEvent::inputEventData(event1, ChoiceFlow::SearchedAnEvent::inputData::topic, 12, false);
				break;
			case 4:
				ChoiceFlow::EnterAnEvent::inputEventData(event1, ChoiceFlow::SearchedAnEvent::inputData::description, 316, false);
				break;
			}
			break;
		}
		window.display();
		window.clear();
	}

}