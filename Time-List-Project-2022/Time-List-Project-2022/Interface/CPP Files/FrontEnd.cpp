#include "../../Event Data Management/Header Files/UserChoiceManagement.h"
#include "../Header Files/FrontEnd.h"
#include "../../Event Data Management/Header Files/SearchAnEvent.h"

using namespace ChoiceFlow;

void printMainMenu(sf::RenderWindow& window)
{
	sf::Texture t1, t2, t3, t4, t5;

	t1.loadFromFile("Images and Fonts/background.jpg");
	t2.loadFromFile("Images and Fonts/logo.png");
	t3.loadFromFile("Images and Fonts/enter_button.png");
	t4.loadFromFile("Images and Fonts/search_button.png");
	t5.loadFromFile("Images and Fonts/test_knowledge_button.png");

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
	sf::Text titleText, yearText, topicText, descriptionText[8];
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
	titleText.setString(EnterAnEvent::inputData::title);
	yearText.setFont(font);
	yearText.setCharacterSize(25);
	yearText.setFillColor(sf::Color::Black);
	yearText.setPosition(210, 218);
	yearText.setString(EnterAnEvent::inputData::year);
	topicText.setFont(font);
	topicText.setCharacterSize(25);
	topicText.setFillColor(sf::Color::Black);
	topicText.setPosition(505, 220);
	topicText.setString(EnterAnEvent::inputData::topic);

	descriptionText[0].setFont(font);
	descriptionText[0].setCharacterSize(25);
	descriptionText[0].setFillColor(sf::Color::Black);
	descriptionText[0].setPosition(305, 338);

	int y = 370;

	for (int i = 1; i < 8; i++)
	{
		descriptionText[i].setFont(font);
		descriptionText[i].setCharacterSize(25);
		descriptionText[i].setFillColor(sf::Color::Black);
		descriptionText[i].setPosition(145, y);
		y += 32;
	}

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

	EnterAnEvent::seperateLinesInDescription(EnterAnEvent::inputData::description, descriptionText);

	for (int i = 0; i < 8; i++)
	{
		window.draw(descriptionText[i]);
	}

	enter.setPosition(275, 645);
	window.draw(enter);
}

void printSearchAnEventPage(sf::RenderWindow& window, Event*& head, Event*& tail)
{
	sf::Text searchData;
	sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
	sf::Font font;
	font.loadFromFile("Images and Fonts/arial.ttf");

	searchData.setCharacterSize(28);
	searchData.setFont(font);
	searchData.setFillColor(sf::Color::Black);
	searchData.setPosition(332, 139);
	searchData.setString(SearchedAnEvent::inputData::searchData);

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
	window.draw(searchData);
	ascendingSort.setPosition(333, 160);
	descendingSort.setPosition(333, 160);
	//Check for print ascending(from head to tail) or descending(from tail to head).
	if (SearchedAnEvent::sortCheck)
	{
		window.draw(ascendingSort);
		SearchAnEventNodes::PrintList::printList(window, head, eventBoard, font);
	}
	else
	{
		window.draw(descendingSort);
		SearchAnEventNodes::PrintList::printListReversed(window, tail, eventBoard, font);
	}
	sortByTitle.setPosition(-10, 78);
	sortByYear.setPosition(-90, 10);
	sortByTopic.setPosition(-90, 10);
	//Check for print sorted by par
	switch (SearchedAnEvent::sortType)
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
	sf::Text titleText, yearText, topicText, descriptionText[8];
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
	titleText.setString(SearchedAnEvent::inputData::title);
	yearText.setFont(font);
	yearText.setCharacterSize(25);
	yearText.setFillColor(sf::Color::Black);
	yearText.setPosition(210, 218);
	yearText.setString(SearchedAnEvent::inputData::year);
	topicText.setFont(font);
	topicText.setCharacterSize(25);
	topicText.setFillColor(sf::Color::Black);
	topicText.setPosition(505, 220);
	topicText.setString(SearchedAnEvent::inputData::topic);

	descriptionText[0].setFont(font);
	descriptionText[0].setCharacterSize(25);
	descriptionText[0].setFillColor(sf::Color::Black);
	descriptionText[0].setPosition(305, 338);

	int y = 370;

	for (int i = 1; i < 8; i++)
	{
		descriptionText[i].setFont(font);
		descriptionText[i].setCharacterSize(25);
		descriptionText[i].setFillColor(sf::Color::Black);
		descriptionText[i].setPosition(145, y);
		y += 32;
	}

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

	EnterAnEvent::seperateLinesInDescription(SearchedAnEvent::inputData::description, descriptionText);

	for (int i = 0; i < 8; i++)
	{
		window.draw(descriptionText[i]);
	}
}

void printEditPage(sf::RenderWindow& window)
{
	sf::Text titleText, yearText, topicText, descriptionText[8];

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
	titleText.setString(SearchedAnEvent::inputData::title);
	yearText.setFont(font);
	yearText.setCharacterSize(25);
	yearText.setFillColor(sf::Color::Black);
	yearText.setPosition(210, 218);
	yearText.setString(SearchedAnEvent::inputData::year);
	topicText.setFont(font);
	topicText.setCharacterSize(25);
	topicText.setFillColor(sf::Color::Black);
	topicText.setPosition(505, 220);
	topicText.setString(SearchedAnEvent::inputData::topic);

	descriptionText[0].setFont(font);
	descriptionText[0].setCharacterSize(25);
	descriptionText[0].setFillColor(sf::Color::Black);
	descriptionText[0].setPosition(305, 338);

	int y = 370;

	for (int i = 1; i < 8; i++)
	{
		descriptionText[i].setFont(font);
		descriptionText[i].setCharacterSize(25);
		descriptionText[i].setFillColor(sf::Color::Black);
		descriptionText[i].setPosition(145, y);
		y += 32;
	}

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

	EnterAnEvent::seperateLinesInDescription(SearchedAnEvent::inputData::description, descriptionText);

	for (int i = 0; i < 8; i++)
	{
		window.draw(descriptionText[i]);
	}
	
	save.setPosition(270, 645);
	window.draw(save);
}

void printTestKnowledgePage(sf::RenderWindow& window, EventGenerator* answer)
{
	sf::Texture t1, t2, t3, t4, t5, t6, t7, t8;
	sf::Text yearText, titleText, topicText, message; sf::Font font;
	font.loadFromFile("Images and Fonts/arial.ttf");

	t1.loadFromFile("Images and Fonts/background.jpg");
	t2.loadFromFile("Images and Fonts/back.png");
	t3.loadFromFile("Images and Fonts/year.png");
	t4.loadFromFile("Images and Fonts/topic.png");
	t5.loadFromFile("Images and Fonts/title.png");
	t6.loadFromFile("Images and Fonts/generate_button.png");
	t7.loadFromFile("Images and Fonts/reveal_button.png");
	t8.loadFromFile("Images and Fonts/check_button.png");

	yearText.setFont(font);
	yearText.setCharacterSize(25);
	yearText.setFillColor(sf::Color::Black);
	yearText.setPosition(193, 318);
	yearText.setString(TestKnowledge::inputData::yearAnswer);
	titleText.setFont(font);
	titleText.setCharacterSize(25);
	titleText.setFillColor(sf::Color::Black);
	titleText.setPosition(243, 160);
	titleText.setString(TestKnowledge::inputData::titleText);
	topicText.setFont(font);
	topicText.setCharacterSize(25);
	topicText.setFillColor(sf::Color::Black);
	topicText.setPosition(510, 318);
	topicText.setString(TestKnowledge::inputData::topicText);
	message.setFont(font);
	message.setCharacterSize(25);
	message.setPosition(335, 400);

	sf::Sprite background(t1);
	sf::Sprite backButton(t2);
	sf::Sprite year(t3);
	sf::Sprite topic(t4);
	sf::Sprite title(t5);
	sf::Sprite generateButton(t6);
	sf::Sprite revealButton(t7);
	sf::Sprite checkButton(t8);

	window.draw(background);
	backButton.setPosition(30, 30);
	window.draw(backButton);
	year.setPosition(135, 310);
	window.draw(year);
	window.draw(yearText);
	topic.setPosition(445, 307);
	window.draw(topic);
	window.draw(topicText);
	title.setPosition(-45, -15);
	window.draw(title);
	window.draw(titleText);
	if (TestKnowledge::inputData::checked) //Check if the check button is pressed
	{
		//If the answer is correct
		if (TestKnowledge::inputData::yearAnswer.toAnsiString() == 
			std::to_string(answer->convertToDecimalFromBinary()))
		{
			message.setFillColor(sf::Color::Green);
			message.setString("Correct!");
		}
		//Otherwise
		else
		{
			message.setFillColor(sf::Color::Red);
			message.setString("Wrong!");
		}
	}
	else
	{
		message.setString("");
	}
	window.draw(message);
	generateButton.setPosition(230, 475);
	window.draw(generateButton);
	revealButton.setPosition(25, 685);
	window.draw(revealButton);
	checkButton.setPosition(520, 683);
	window.draw(checkButton);
}

void setMenu(int& stage)
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "History Notes", sf::Style::Close);
	sf::Event event1;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	Event* head = NULL, * entireFile = NULL, * tail = NULL;
	EventGenerator* eventG = NULL;

	while (window.isOpen())
	{
		switch (stage)
		{
		case 0:
			printMainMenu(window);
			MainMenu::onClickMainMenu(window, event1, stage, buffer, sound);
			break;
		case 1:
			EnterAnEvent::onClickEventPage(window, event1, stage,EnterAnEvent::inputData::box, 
			EnterAnEvent::inputData::title, EnterAnEvent::inputData::year, 
			EnterAnEvent::inputData::topic, EnterAnEvent::inputData::description, buffer, sound);
			printEnterAnEventPage(window);
			switch (EnterAnEvent::inputData::box)
			{
			case 1: //Input the title
				EnterAnEvent::inputEventData(event1, EnterAnEvent::inputData::title, 27, false);
				break;
			case 2: //Input the year
				EnterAnEvent::inputEventData(event1, EnterAnEvent::inputData::year, 4, true);
				break;
			case 3: //Input the topic
				EnterAnEvent::inputEventData(event1, EnterAnEvent::inputData::topic, 12, false);
				break;
			case 4: //Input the description
				EnterAnEvent::inputEventData(event1, EnterAnEvent::inputData::description, 316, false);
				break;
			}
			break;
		case 2:
			if (SearchedAnEvent::crCheck) //Check if the list is created
			{
				head = new Event; tail = new Event; entireFile = new Event;
				SearchAnEventNodes::TakeNodes::takeDataFromFile(head, &Event::appendNode, &Event::removeHead);
				SearchAnEventNodes::TakeNodes::takeDataFromFile(entireFile, &Event::appendNode, &Event::removeHead);
				head->mergeSortList(head, 1);
				tail = tail->getTail(head);
				head = head->getHead(tail);
				SearchedAnEvent::crCheck = false;
			}
			printSearchAnEventPage(window, head, tail);

			SearchedAnEvent::onClickSearchPage(window, event1, stage, head, tail, 
			SearchedAnEvent::crCheck, SearchedAnEvent::sortCheck, 
			SearchedAnEvent::inputData::title, SearchedAnEvent::inputData::year, 
			SearchedAnEvent::inputData::topic, SearchedAnEvent::inputData::description, 
			SearchedAnEvent::sortType, EnterAnEvent::inputData::box,
			SearchedAnEvent::inputData::searchData, entireFile, buffer, sound);

			if (EnterAnEvent::inputData::box == 1) //input search data
			{
				EnterAnEvent::inputEventData(event1, SearchedAnEvent::inputData::searchData, 25, false);
			}
			break;
		case 3:
			printTestKnowledgePage(window, eventG);
			if (TestKnowledge::inputData::crCheck) //Check if the list is created
			{
				entireFile = new Event;
				SearchAnEventNodes::TakeNodes::takeDataFromFile(entireFile, &Event::appendNode, &Event::removeHead);
				TestKnowledge::inputData::crCheck = false;
			}

			TestKnowledge::onClickTestPage(window, event1, stage, entireFile, 
			TestKnowledge::inputData::crCheck, EnterAnEvent::inputData::box, 
			TestKnowledge::inputData::yearAnswer, TestKnowledge::inputData::titleText, 
			TestKnowledge::inputData::topicText, eventG, TestKnowledge::inputData::revealed, 
			TestKnowledge::inputData::generated, TestKnowledge::inputData::checked, buffer, sound);

			if (EnterAnEvent::inputData::box == 1 && !TestKnowledge::inputData::revealed && 
			TestKnowledge::inputData::generated && !TestKnowledge::inputData::checked)
			{
				//Input the year answer data
				EnterAnEvent::inputEventData(event1, TestKnowledge::inputData::yearAnswer, 4, true);
			}
			break;
		case 4:
			printInfoPage(window);
			SearchedAnEvent::onClickInfoPage(window, event1, stage, buffer, sound);
			break;
		case 5:
			printEditPage(window);

			SearchedAnEvent::onClickEditPage(window, event1, stage, EnterAnEvent::inputData::box, 
			SearchedAnEvent::inputData::title, SearchedAnEvent::inputData::year, 
			SearchedAnEvent::inputData::topic, SearchedAnEvent::inputData::description, 
			SearchedAnEvent::crCheck, SearchedAnEvent::sortType, buffer, sound);

			switch (EnterAnEvent::inputData::box)
			{
			case 1: //Input the title in the edit page
				EnterAnEvent::inputEventData(event1, SearchedAnEvent::inputData::title, 27, false);
				break;
			case 2: //Input the year in the edit page
				EnterAnEvent::inputEventData(event1, SearchedAnEvent::inputData::year, 4, true);
				break;
			case 3: //Input the topic in the edit page
				EnterAnEvent::inputEventData(event1, SearchedAnEvent::inputData::topic, 12, false);
				break;
			case 4: //Input the description in the edit page
				EnterAnEvent::inputEventData(event1, SearchedAnEvent::inputData::description, 316, false);
				break;
			}
			break;
		}
		window.display();
		window.clear();
	}
}