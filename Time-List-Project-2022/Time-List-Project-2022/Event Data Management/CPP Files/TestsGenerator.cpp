#include "../Header Files/TestsGenerator.h"
#include "../Header Files/SearchAnEvent.h"
#include <stdlib.h>

EventGenerator::EventGenerator(Event* entireFile, int(*takeLastNodePos)(Event*))
{
	std::map<std::string, std::string> data = generateRandomNode(entireFile, takeLastNodePos);

	this->title = data["Title"]; 
	this->topic = data["Topic"]; 
	this->year = stoi(data["Year"]); //gray code
}

std::map<std::string, std::string> EventGenerator::generateRandomNode(Event* entireFile, int(*takeLastNodePos)(Event*))
{
	int node = rand() % takeLastNodePos(entireFile);
	int i = 0;
	std::map<std::string, std::string> data;

	while (entireFile != NULL)
	{
		if (node == i)
		{
			data = {
				{"Title", entireFile->title},
				{"Topic", entireFile->topic},
				{"Year", std::to_string(entireFile->year)}
				};

			break;
		}
		entireFile = entireFile->nextEvent;
		i++;
	}

	return data;
}