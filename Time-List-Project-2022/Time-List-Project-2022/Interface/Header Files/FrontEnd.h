#pragma once
#include "../../Event Data Management/Header Files/TestsGenerator.h"

void printMainMenu(sf::RenderWindow& window);

void printEnterAnEventPage(sf::RenderWindow& window);

void printSearchAnEventPage(sf::RenderWindow& window, Event*& head, Event*& tail);

void printInfoPage(sf::RenderWindow& window);

void printEditPage(sf::RenderWindow& window);

void printTestKnowledgePage(sf::RenderWindow& window, EventGenerator* answer);

void setMenu(int& stage);