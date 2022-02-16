#include "../Header Files/Event.h"
#include "../Header Files/SearchAnEvent.h"

using namespace SearchAnEventNodes::TakeNodes;
using namespace SearchAnEventNodes::ClearList;

Event::Event(std::string& title, int& year, std::string& topic, std::string& description)
{
	this->title = title;
	this->year = year;
	this->topic = topic;
	this->description = description;
}

Event* Event::getTail(Event* head)
{
	if (head == NULL)
	{
		return head;
	}

	while (head->nextEvent != NULL)
	{
		head = head->nextEvent;
	}

	return head;
}

Event* Event::getHead(Event* tail)
{
	if (tail == NULL)
	{
		return tail;
	}

	while (tail->prevEvent != NULL)
	{
		tail = tail->prevEvent;
	}

	return tail;
}

void Event::appendNode(Event* head, std::string& title, int& year, std::string& topic, std::string& description)
{
	Event* tail = getTail(head);

	//Make the tail to point to a new event
	tail->nextEvent = new Event(title, year, topic, description);
	if (tail == NULL)
	{
		tail->nextEvent->prevEvent = NULL;
	}
	else
	{
		tail->nextEvent->prevEvent = tail;
	}
}

Event* Event::removeHead(Event* head)
{
	Event* newHead = head->nextEvent;
	newHead->prevEvent = NULL;
	delete head;

	return newHead;
}

//Split to two halfes
Event* Event::split(Event* head)
{
	Event* f = head, * s = head;
	while (f->nextEvent && f->nextEvent->nextEvent)
	{
		f = f->nextEvent->nextEvent;
		s = s->nextEvent;
	}

	Event* temp = s->nextEvent;
	s->nextEvent = NULL;
	return temp;
}

//Merge the two halfes and sorting them at the same time
Event* Event::merge(Event* f, Event* s, int sortType)
{
	if (!f)
		return s;

	if (!s)
		return f;

	//Check what type of sorting
	switch (sortType)
	{
	case 1:
		if (f->title <= s->title)
		{
			f->nextEvent = merge(f->nextEvent, s, sortType);
			f->nextEvent->prevEvent = f;
			f->prevEvent = NULL;
			return f;
		}
		else
		{
			s->nextEvent = merge(f, s->nextEvent, sortType);
			s->nextEvent->prevEvent = s;
			s->prevEvent = NULL;
			return s;
		}
		break;
	case 2:
		if (f->year <= s->year)
		{
			f->nextEvent = merge(f->nextEvent, s, sortType);
			f->nextEvent->prevEvent = f;
			f->prevEvent = NULL;
			return f;
		}
		else
		{
			s->nextEvent = merge(f, s->nextEvent, sortType);
			s->nextEvent->prevEvent = s;
			s->prevEvent = NULL;
			return s;
		}
		break;
	case 3:
		if (f->topic <= s->topic)
		{
			f->nextEvent = merge(f->nextEvent, s, sortType);
			f->nextEvent->prevEvent = f;
			f->prevEvent = NULL;
			return f;
		}
		else
		{
			s->nextEvent = merge(f, s->nextEvent, sortType);
			s->nextEvent->prevEvent = s;
			s->prevEvent = NULL;
			return s;
		}
		break;
	}
}

//Function to return the sorted list
Event* Event::mergeSortList(Event*& head, int sortType)
{
	if (!head || !head->nextEvent)
		return head;

	Event* secondHalf = split(head);

	//First and second half
	head = mergeSortList(head, sortType);
	secondHalf = mergeSortList(secondHalf, sortType);

	//Merge halves
	return merge(head, secondHalf, sortType);
}

void Event::removeNode(Event*& head, Event*& tail, int cordinateY, int node, bool& sortCheck)
{
	int nodeCur = 1;
	Event* headCur = head;
	Event* tailCur = getTail(head);

	int last = takeLastNodePos(head);

	if (takeNodeIndex(cordinateY, node) != 0)
	{
		if (sortCheck)
		{
			while (head != NULL)
			{
				//Check the cordinates of the clicked event
				if (nodeCur == takeNodeIndex(cordinateY, node))
				{
					if (takeNodeIndex(cordinateY, node) == 1)
					{
						if (head->nextEvent == NULL)
						{
							clearList(head);
							head = NULL;
							tail = NULL;
						}
						else
						{
							head->nextEvent->prevEvent = NULL;
							head = head->nextEvent;
						}
						break;

					}
					else if (takeNodeIndex(cordinateY, node) == last)
					{
						head->prevEvent->nextEvent = NULL;
						tail->prevEvent->nextEvent = NULL;
						head = headCur;
						tailCur = tailCur->prevEvent;
						tail = tailCur;
						break;
					}
					else
					{
						head->prevEvent->nextEvent = head->nextEvent;
						head->nextEvent->prevEvent = head->prevEvent;
						head = headCur;
						tail = tailCur;
						break;
					}
				}
				nodeCur++;
				head = head->nextEvent;
			}
			SearchAnEventNodes::SaveList::saveDataIntoFile(head);
		}
		else
		{
			while (tail != NULL)
			{
				//Check the cordinates of the clicked event
				if (nodeCur == takeNodeIndex(cordinateY, node))
				{
					if (takeNodeIndex(cordinateY, node) == 1)
					{
						if (tail->prevEvent == NULL)
						{
							clearListTail(tail);
							head = NULL;
							tail = NULL;
						}
						else
						{
							tail->prevEvent->nextEvent = NULL;
							tail = tail->prevEvent;
						}
						break;

					}
					else if (takeNodeIndex(cordinateY, node) == last)
					{
						tail->nextEvent->prevEvent = NULL;
						head->nextEvent->prevEvent = NULL;
						headCur = headCur->nextEvent;
						tail = tailCur;
						head = headCur;
						break;
					}
					else
					{
						tail->prevEvent->nextEvent = tail->nextEvent;
						tail->nextEvent->prevEvent = tail->prevEvent;
						delete tail;
						tail = tailCur;
						head = headCur;
						break;
					}
				}
				nodeCur++;
				tail = tail->prevEvent;
			}
			SearchAnEventNodes::SaveList::saveDataIntoFileTail(tail);
		}
	}
}

void Event::removeAfterSearch(Event*& head, Event*& tail, int cordinateY, int node, bool& sortCheck,
	std::string& title)
{
	int nodeCur = 1;
	Event* headCur = head;
	Event* tailCur = getTail(head);

	int last = takeLastNodePos(head);

	if (takeNodeIndex(cordinateY, node) != 0)
	{
		if (sortCheck)
		{
			while (head != NULL)
			{
				if (nodeCur == takeNodeIndex(cordinateY, node))
				{
					if (takeNodeIndex(cordinateY, node) == 1)
					{
						if (head->nextEvent == NULL)
						{
							title = head->title;
							clearList(head);
							head = NULL;
							tail = NULL;
						}
						else
						{
							head->nextEvent->prevEvent = NULL;
							title = head->title;
							head = head->nextEvent;
						}
						break;

					}
					else if (takeNodeIndex(cordinateY, node) == last)
					{
						title = head->title;
						head->prevEvent->nextEvent = NULL;
						tail->prevEvent->nextEvent = NULL;
						head = headCur;
						tailCur = tailCur->prevEvent;
						tail = tailCur;
						break;
					}
					else
					{
						title = head->title;
						head->prevEvent->nextEvent = head->nextEvent;
						head->nextEvent->prevEvent = head->prevEvent;
						head = headCur;
						tail = tailCur;
						break;
					}
				}
				nodeCur++;
				head = head->nextEvent;
			}
		}
		else
		{
			while (tail != NULL)
			{
				if (nodeCur == takeNodeIndex(cordinateY, node))
				{
					if (takeNodeIndex(cordinateY, node) == 1)
					{
						if (tail->prevEvent == NULL)
						{
							title = tail->title;
							clearListTail(tail);
							head = NULL;
							tail = NULL;
						}
						else
						{
							title = tail->title;
							tail->prevEvent->nextEvent = NULL;
							tail = tail->prevEvent;
						}
						break;

					}
					else if (takeNodeIndex(cordinateY, node) == last)
					{
						title = tail->title;
						tail->nextEvent->prevEvent = NULL;
						head->nextEvent->prevEvent = NULL;
						headCur = headCur->nextEvent;
						tail = tailCur;
						head = headCur;
						break;
					}
					else
					{
						title = tail->title;
						tail->prevEvent->nextEvent = tail->nextEvent;
						tail->nextEvent->prevEvent = tail->prevEvent;
						delete tail;
						tail = tailCur;
						head = headCur;
						break;
					}
				}
				nodeCur++;
				tail = tail->prevEvent;
			}
		}
	}
}