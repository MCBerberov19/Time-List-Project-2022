#include "../Header Files/UserChoiceManagement.h"
#include "../Header Files/EnterAnEvent.h"
#include "../Header Files/SearchAnEvent.h"
#include <vector>
#include <regex>

using namespace ChoiceFlow;
using namespace SearchAnEventNodes::ClearList;
using namespace SearchAnEventNodes::TakeNodes;

void MainMenu::playSound(sf::SoundBuffer& buffer, sf::Sound& sound, int soundType)
{
	switch (soundType)
	{
	case 1:
		buffer.loadFromFile("Sounds/click.wav");
		break;
	case 2:
		buffer.loadFromFile("Sounds/sort.wav");
		break;
	case 3:
		buffer.loadFromFile("Sounds/search.wav");
		break;
	case 4:
		buffer.loadFromFile("Sounds/delete.wav");
		break;
	case 5:
		buffer.loadFromFile("Sounds/generate.wav");
		break;
	case 6:
		buffer.loadFromFile("Sounds/reveal.wav");
		break;
	case 7:
		buffer.loadFromFile("Sounds/check.wav");
		break;
	case 8:
		buffer.loadFromFile("Sounds/enter.wav");
		break;
	}

	sound.setBuffer(buffer);
	sound.play();
}

void MainMenu::onClickMainMenu(sf::RenderWindow& window, sf::Event& event1, int& stage,
	sf::SoundBuffer& buffer, sf::Sound& sound)
{
	while (window.pollEvent(event1))
	{

		//Close the window
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 260 && sf::Mouse::getPosition(window).x <= 560) &&
				(sf::Mouse::getPosition(window).y >= 305 && sf::Mouse::getPosition(window).y <= 390)) //Enter an event page
			{
				playSound(buffer, sound, 1);
				stage = 1;
			}
			else if ((sf::Mouse::getPosition(window).x >= 260 && sf::Mouse::getPosition(window).x <= 560) &&
				(sf::Mouse::getPosition(window).y >= 455 && sf::Mouse::getPosition(window).y <= 540)) //Search an event page
			{
				playSound(buffer, sound, 1);
				stage = 2;
			}
			else if ((sf::Mouse::getPosition(window).x >= 260 && sf::Mouse::getPosition(window).x <= 560) &&
				(sf::Mouse::getPosition(window).y >= 605 && sf::Mouse::getPosition(window).y <= 690)) // Test your knowledge
			{
				playSound(buffer, sound, 1);
				stage = 3;
			}
		}
	}
}

void EnterAnEvent::onClickEventPage(sf::RenderWindow& window, sf::Event& event1, int& stage, int& box,
	EnterAnEvent::inputData*& eData, sf::SoundBuffer& buffer, sf::Sound& sound, bool& crCheck)
{
	while (window.pollEvent(event1))
	{
		//Close the window
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 30 && sf::Mouse::getPosition(window).x <= 90) &&
				(sf::Mouse::getPosition(window).y >= 30 && sf::Mouse::getPosition(window).y <= 90)) //Back
			{
				MainMenu::playSound(buffer, sound, 1);
				stage = 0;
				crCheck = true;
				delete eData;
			}

			else if ((sf::Mouse::getPosition(window).x >= 180 && sf::Mouse::getPosition(window).x <= 605) && //Title
				(sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 160))
			{
				box = 1;
			}

			else if ((sf::Mouse::getPosition(window).x >= 150 && sf::Mouse::getPosition(window).x <= 305) && //Year
				(sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 260))
			{
				box = 2;
			}

			else if ((sf::Mouse::getPosition(window).x >= 440 && sf::Mouse::getPosition(window).x <= 685) && //Topic
				(sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 260))
			{
				box = 3;
			}

			else if ((sf::Mouse::getPosition(window).x >= 140 && sf::Mouse::getPosition(window).x <= 680) && //Description
				(sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 600))
			{
				box = 4;
			}

			else if ((sf::Mouse::getPosition(window).x >= 285 && sf::Mouse::getPosition(window).x <= 525) && //Enter
				(sf::Mouse::getPosition(window).y >= 650 && sf::Mouse::getPosition(window).y <= 735))
			{
				if (eData->title.getSize() > 0 && eData->topic.getSize() > 0 && eData->description.getSize() > 0 && eData->year.getSize() > 0)
				{
					//Enter an event button
					MainMenu::playSound(buffer, sound, 8);
					EnterAnEventC* newEvent = new EnterAnEventC(eData->title, stoi(eData->year.toAnsiString()), eData->topic, eData->description);
					delete newEvent;

					stage = 0;
					eData->title = "";
					eData->topic = "";
					eData->description = "";
					eData->year = "";

					crCheck = true;
					delete eData;
				}
			}
			else
			{
				box = 0;
			}
		}
	}
}

void EnterAnEvent::inputEventData(sf::Event& event1, sf::String& text, int size, bool num)
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

void EnterAnEvent::seperateLinesInDescription(sf::String& description, sf::Text* descriptionText)
{
	if (description.getSize() > 0 && description.getSize() <= 28)
	{
		descriptionText[0].setString(description.substring(0, 29));
	}
	else if (description.getSize() > 28 && description.getSize() <= 71)
	{
		descriptionText[0].setString(description.substring(0, 29));
		descriptionText[1].setString(description.substring(29, 72));
	}
	else if (description.getSize() > 71 && description.getSize() <= 116)
	{
		descriptionText[0].setString(description.substring(0, 29));
		descriptionText[1].setString(description.substring(29, 43));
		descriptionText[2].setString(description.substring(72, 117));
	}
	else if (description.getSize() > 116 && description.getSize() <= 160)
	{
		descriptionText[0].setString(description.substring(0, 29));
		descriptionText[1].setString(description.substring(29, 43));
		descriptionText[2].setString(description.substring(72, 44));
		descriptionText[3].setString(description.substring(116, 161));
	}
	else if (description.getSize() > 160 && description.getSize() <= 203)
	{
		descriptionText[0].setString(description.substring(0, 29));
		descriptionText[1].setString(description.substring(29, 43));
		descriptionText[2].setString(description.substring(72, 44));
		descriptionText[3].setString(description.substring(116, 44));
		descriptionText[4].setString(description.substring(160, 204));
	}
	else if (description.getSize() > 203 && description.getSize() <= 244)
	{
		descriptionText[0].setString(description.substring(0, 29));
		descriptionText[1].setString(description.substring(29, 43));
		descriptionText[2].setString(description.substring(72, 44));
		descriptionText[3].setString(description.substring(116, 44));
		descriptionText[4].setString(description.substring(160, 43));
		descriptionText[5].setString(description.substring(203, 245));
	}
	else if (description.getSize() > 244 && description.getSize() <= 284)
	{
		descriptionText[0].setString(description.substring(0, 29));
		descriptionText[1].setString(description.substring(29, 43));
		descriptionText[2].setString(description.substring(72, 44));
		descriptionText[3].setString(description.substring(116, 44));
		descriptionText[4].setString(description.substring(160, 43));
		descriptionText[5].setString(description.substring(203, 41));
		descriptionText[6].setString(description.substring(244, 285));
	}
	else if (description.getSize() > 284 && description.getSize() <= 317)
	{
		descriptionText[0].setString(description.substring(0, 29));
		descriptionText[1].setString(description.substring(29, 43));
		descriptionText[2].setString(description.substring(72, 44));
		descriptionText[3].setString(description.substring(116, 44));
		descriptionText[4].setString(description.substring(160, 43));
		descriptionText[5].setString(description.substring(203, 41));
		descriptionText[6].setString(description.substring(244, 40));
		descriptionText[7].setString(description.substring(284, 317));
	}
}

void SearchedAnEvent::onClickSearchPage(sf::RenderWindow& window, sf::Event& event1, int& stage,
	Event*& head, Event*& tail, SearchedAnEvent::inputData*& sData, SearchedAnEvent::checkData*& cData, int& box,
	Event*& entireFile, sf::SoundBuffer& buffer, sf::Sound& sound, bool& crCheck)
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
				(sf::Mouse::getPosition(window).y >= 30 && sf::Mouse::getPosition(window).y <= 90)) //Back
			{
				MainMenu::playSound(buffer, sound, 1);
				stage = 0;
				clearList(head);
				box = 0;
				sData->searchData = "";
				cData->sortType = 1;
				cData->sortCheck = true;
				crCheck = true;
				delete sData; delete cData;
			}
			else if ((sf::Mouse::getPosition(window).x >= 85 && sf::Mouse::getPosition(window).x <= 710) &&
				(sf::Mouse::getPosition(window).y >= 125 && sf::Mouse::getPosition(window).y <= 182)) //Search box
			{
				box = 1;
			}
			else if ((sf::Mouse::getPosition(window).x >= 85 && sf::Mouse::getPosition(window).x <= 178) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 255)) //Sort by title
			{
				MainMenu::playSound(buffer, sound, 2);
				cData->sortType = 1;
				head->mergeSortList(head, 1);
				tail = tail->getTail(head);
				head = head->getHead(tail);
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 179 && sf::Mouse::getPosition(window).x <= 290) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 255)) //Sort by year
			{
				MainMenu::playSound(buffer, sound, 2);
				cData->sortType = 2;
				head->mergeSortList(head, 2);
				tail = tail->getTail(head);
				head = head->getHead(tail);
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 291 && sf::Mouse::getPosition(window).x <= 387) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 255)) //Sort by topic
			{
				MainMenu::playSound(buffer, sound, 2);
				cData->sortType = 3;
				head->mergeSortList(head, 3);
				tail = tail->getTail(head);
				head = head->getHead(tail);
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 470 && sf::Mouse::getPosition(window).x <= 590) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 250)) //Sort ascending
			{
				MainMenu::playSound(buffer, sound, 2);
				cData->sortCheck = true;
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 592 && sf::Mouse::getPosition(window).x <= 710) &&
				(sf::Mouse::getPosition(window).y >= 190 && sf::Mouse::getPosition(window).y <= 250)) //Sort descending
			{
				MainMenu::playSound(buffer, sound, 2);
				cData->sortCheck = false;
				tail = tail->getTail(head);
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 255 && sf::Mouse::getPosition(window).x <= 555) &&
				(sf::Mouse::getPosition(window).y >= 685 && sf::Mouse::getPosition(window).y <= 780)) //Search button
			{
				if (sData->searchData.getSize() > 0)
				{
					MainMenu::playSound(buffer, sound, 3);
					cData->sortCheck = true;

					head = SearchAnEventNodes::PrintList::printFoundData(entireFile, sData->searchData,
						&Event::appendNode, cData->sortType, cData->sortCheck);

					box = 0;
					cData->lastSearched = sData->searchData;
					sData->searchData = "";
					cData->ifSearched = true;
				}
			}
			else if ((sf::Mouse::getPosition(window).x >= 575 && sf::Mouse::getPosition(window).x <= 620) &&
				(sf::Mouse::getPosition(window).y >= 270 && sf::Mouse::getPosition(window).y <= 270 +
					(65 * takeLastNodePos(head)) && sf::Mouse::getPosition(window).y <= 672) &&
				checkValidSpaces(sf::Mouse::getPosition(window).y) && takeLastNodePos(head) != 0) //Info button 
			{
				MainMenu::playSound(buffer, sound, 1);
				stage = 4;
				SearchAnEventNodes::SaveList::saveEventInfo(head, tail, sf::Mouse::getPosition(window).y, 1,
					sData, cData->sortCheck);
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 621 && sf::Mouse::getPosition(window).x <= 659) &&
				(sf::Mouse::getPosition(window).y >= 270 && sf::Mouse::getPosition(window).y <= 270 +
					(65 * takeLastNodePos(head)) && sf::Mouse::getPosition(window).y <= 672) &&
				checkValidSpaces(sf::Mouse::getPosition(window).y) && takeLastNodePos(head) != 0) //Edit button 
			{
				MainMenu::playSound(buffer, sound, 1);
				stage = 5;
				SearchAnEventNodes::SaveList::saveEventInfo(head, tail, sf::Mouse::getPosition(window).y, 1,
					sData, cData->sortCheck);
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 660 && sf::Mouse::getPosition(window).x <= 705) &&
				(sf::Mouse::getPosition(window).y >= 270 && sf::Mouse::getPosition(window).y <= 270 +
					(65 * takeLastNodePos(head)) && sf::Mouse::getPosition(window).y <= 672) &&
				checkValidSpaces(sf::Mouse::getPosition(window).y) && takeLastNodePos(head) != 0) //Remove an event
			{
				MainMenu::playSound(buffer, sound, 4);
				if (cData->ifSearched)
				{
					head->removeAfterSearch(head, tail, sf::Mouse::getPosition(window).y, 1, cData->sortCheck, cData->deletedTitle);
					SearchAnEventNodes::SaveList::saveAfterRemoveWhenSearched(entireFile, cData->deletedTitle);
					clearList(entireFile);
					entireFile = new Event;
					takeDataFromFile(entireFile, &Event::appendNode, &Event::removeHead);
				}
				else
				{
					head->removeNode(head, tail, sf::Mouse::getPosition(window).y, 1, cData->sortCheck);
					takeDataFromFile(entireFile, &Event::appendNode, &Event::removeHead);
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

void SearchedAnEvent::onClickInfoPage(sf::RenderWindow& window, sf::Event& event1, int& stage,
	sf::SoundBuffer& buffer, sf::Sound& sound, SearchedAnEvent::inputData*& sData)
{
	while (window.pollEvent(event1))
	{
		//Close the window
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 30 && sf::Mouse::getPosition(window).x <= 90) &&
				(sf::Mouse::getPosition(window).y >= 30 && sf::Mouse::getPosition(window).y <= 90)) //Back
			{
				MainMenu::playSound(buffer, sound, 1);
				stage = 2;
			}
		}
	}
}

void SearchedAnEvent::saveEditedEventData(SearchedAnEvent::inputData*& sData)
{
	std::ifstream curData; curData.open("Events.txt", std::ios::in | std::ios::app);
	std::string data, editedData, curTitle;
	std::vector<std::string> lines;
	std::smatch yearMatch;

	editedData = sData->title.toAnsiString() + " " + sData->year.toAnsiString() + " " + sData->topic.toAnsiString() + " " + sData->description.toAnsiString();
	bool found = true;
	int pos = 0;

	while (std::getline(curData, data))
	{
		std::regex_search(data, yearMatch, std::regex("[1-9]"));
		curTitle = data.substr(0, yearMatch.position() - 1);;

		lines.push_back(data);

		if (sData->oldTitle == curTitle)
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

	//Clear the file and save the edited data
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

void SearchedAnEvent::onClickEditPage(sf::RenderWindow& window, sf::Event& event1, int& stage,
	int& box, SearchedAnEvent::inputData*& sData,
	SearchedAnEvent::checkData*& cData, sf::SoundBuffer& buffer, sf::Sound& sound, bool& crCheck)
{
	if (sData->oldTitleCheck)
	{
		sData->oldTitle = sData->title;
		sData->oldTitleCheck = false;
	}

	while (window.pollEvent(event1))
	{
		//Close the window
		if (event1.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event1.key.code == sf::Mouse::Left && event1.type == sf::Event::MouseButtonPressed)
		{
			if ((sf::Mouse::getPosition(window).x >= 30 && sf::Mouse::getPosition(window).x <= 90) &&
				(sf::Mouse::getPosition(window).y >= 30 && sf::Mouse::getPosition(window).y <= 90)) //Back
			{
				MainMenu::playSound(buffer, sound, 1);
				stage = 2;
				sData->oldTitleCheck = true;
			}
			else if ((sf::Mouse::getPosition(window).x >= 180 && sf::Mouse::getPosition(window).x <= 605) && //Title
				(sf::Mouse::getPosition(window).y >= 115 && sf::Mouse::getPosition(window).y <= 160))
			{
				box = 1;
			}

			else if ((sf::Mouse::getPosition(window).x >= 150 && sf::Mouse::getPosition(window).x <= 305) && //Year
				(sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 260))
			{
				box = 2;
			}

			else if ((sf::Mouse::getPosition(window).x >= 440 && sf::Mouse::getPosition(window).x <= 685) && //Topic
				(sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 260))
			{
				box = 3;
			}

			else if ((sf::Mouse::getPosition(window).x >= 140 && sf::Mouse::getPosition(window).x <= 680) && //Description
				(sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 600))
			{
				box = 4;
			}

			else if ((sf::Mouse::getPosition(window).x >= 277 && sf::Mouse::getPosition(window).x <= 577) && //Enter
				(sf::Mouse::getPosition(window).y >= 650 && sf::Mouse::getPosition(window).y <= 750))
			{
				//Save edited an event data
				if (sData->title.getSize() > 0 && sData->topic.getSize() > 0 && sData->description.getSize() > 0 && sData->year.getSize() > 0)
				{
					MainMenu::playSound(buffer, sound, 1);
					saveEditedEventData(sData);

					sData->oldTitleCheck = true;
					sData->title = "";
					sData->topic = "";
					sData->description = "";
					sData->year = "";
					cData->sortType = 1;
					crCheck = true;
					stage = 0;
				}
			}
			else
			{
				box = 0;
			}
		}

	}
}

void TestKnowledge::onClickTestPage(sf::RenderWindow& window, sf::Event& event1, int& stage, Event*& entireFile,
	inputData*& tData, int& box,
	EventGenerator*& eventG, sf::SoundBuffer& buffer, sf::Sound& sound, bool& crCheck)
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
				(sf::Mouse::getPosition(window).y >= 30 && sf::Mouse::getPosition(window).y <= 90)) //Back
			{
				MainMenu::playSound(buffer, sound, 1);
				stage = 0;
				crCheck = true;
				clearList(entireFile);
				box = 0;
				tData->titleText = ""; tData->topicText = "";
				tData->yearAnswer = ""; tData->revealed = false;
				tData->generated = false; tData->checked = false;
				if (tData->generated)
					delete eventG;

				crCheck = true;
				delete tData;
			}
			else if ((sf::Mouse::getPosition(window).x >= 135 && sf::Mouse::getPosition(window).x <= 290) &&
				(sf::Mouse::getPosition(window).y >= 310 && sf::Mouse::getPosition(window).y <= 355)) //Year box
			{
				box = 1;
			}
			else if ((sf::Mouse::getPosition(window).x >= 240 && sf::Mouse::getPosition(window).x <= 565) &&
				(sf::Mouse::getPosition(window).y >= 485 && sf::Mouse::getPosition(window).y <= 575)) //Generate button
			{
				if (takeLastNodePos(entireFile) > 1)
				{
					MainMenu::playSound(buffer, sound, 5);
					//Generate new event if there is one create already delete that one and create new
					if (tData->generated) delete eventG;
					eventG = new EventGenerator(entireFile, &takeLastNodePos);
					tData->titleText = eventG->title; tData->topicText = eventG->topic;
					box = 0;
					tData->yearAnswer = "";
					tData->revealed = false; tData->generated = true; tData->checked = false;
				}
			}
			else if ((sf::Mouse::getPosition(window).x >= 35 && sf::Mouse::getPosition(window).x <= 275) &&
				(sf::Mouse::getPosition(window).y >= 695 && sf::Mouse::getPosition(window).y <= 775)) //Reveal the answer button
			{
				if (tData->generated)
				{
					MainMenu::playSound(buffer, sound, 6);
					tData->yearAnswer = std::to_string(eventG->convertToDecimalFromBinary());
					tData->revealed = true;
					tData->checked = false;
				}
				box = 0;
			}
			else if ((sf::Mouse::getPosition(window).x >= 525 && sf::Mouse::getPosition(window).x <= 765) &&
				(sf::Mouse::getPosition(window).y >= 700 && sf::Mouse::getPosition(window).y <= 775)) //Check the answer button
			{
				//Check if there is a generated event and the answer is typed
				if (tData->generated && tData->yearAnswer.getSize() > 0)
				{
					MainMenu::playSound(buffer, sound, 7);
					tData->checked = true;
					tData->revealed = false;
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