#pragma once
#include <SFML/Graphics.hpp>
#include "../../Event Data Management/Header Files/Event.h"

void printMainMenu(sf::RenderWindow& window);

void printEnterAnEventPage(sf::RenderWindow& window);

void printSearchAnEventPage(sf::RenderWindow& window, Event*& head, Event*& tail);

void printInfoPage(sf::RenderWindow& window);

void printEditPage(sf::RenderWindow& window);

void printTestKnowledgePage(sf::RenderWindow& window);

void setMenu(int& stage);