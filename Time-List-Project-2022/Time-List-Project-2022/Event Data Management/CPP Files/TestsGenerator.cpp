#include "../Header Files/TestsGenerator.h"
#include "../Header Files/SearchAnEvent.h"
#include <stdlib.h>

EventGenerator::EventGenerator(Event* entireFile, int(*takeLastNodePos)(Event*))
{
	std::map<int, std::string> data = generateRandomNode(entireFile, takeLastNodePos);

	this->title = data[1]; this->topic = data[2]; this->year = stoi(data[3]);//gray code
}

std::map<int, std::string> EventGenerator::generateRandomNode(Event* entireFile, int(*takeLastNodePos)(Event*))
{
	int node = rand() % takeLastNodePos(entireFile);
	int i = 0;
	std::map<int, std::string> data;

	while (entireFile != NULL)
	{
		if (node == i)
		{
			data = {
				{1, entireFile->title},
				{2, entireFile->topic},
				{3, std::to_string(entireFile->year)}
				};

			break;
		}
		entireFile = entireFile->nextEvent;
		i++;
	}

	return data;
}