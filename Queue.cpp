#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"

#include "Queue.h"
#include <iostream>

Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
	points = 0;
}

Queue::~Queue()
{
	if (!isEmpty())
	{
		do
		{
			QueueNode *garbage = front;
			front = front->next;
			garbage->next = nullptr;
			delete garbage;
			garbage = nullptr;
		} while (front != nullptr);
	}
}

void Queue::push(Character *player)
{
	if (isEmpty())
	{
		front = new QueueNode(player);
		rear = front;
	}
	else
	{
		rear->next = new QueueNode(player);
		rear = rear->next;
	}
}

Character* Queue::pop()
{
	if (isEmpty())
	{
		std::cout << "Team is empty.\n";
	}
	else if (front == rear)
	{
		Character* playerTemp = front->player;
		front->next = nullptr;
		delete front;
		front = nullptr;
		return playerTemp;
	}
	else
	{
		Character* playerTemp = front->player;
		QueueNode *temp = front;
		front = front->next;
		temp->next = nullptr;
		delete temp;
		temp = nullptr;
		return playerTemp;
	}
}

Character* Queue::getFront()
{
	if (!isEmpty())
	{	return front->player;}
	else
	{ std::cout << "Team is empty.\n"; }
}

bool Queue::isEmpty() const
{ return front == nullptr; }

void Queue::printQueue()
{
	if (isEmpty())
	{ std::cout << "Team is empty."; }
	else if (front == rear)
	{
		std::cout << "Player 1:\n";
		std::cout << "Name: " << front->player->getName() << std::endl;
		std::cout << "Type: " << front->player->getType() << std::endl;
	}
	else
	{
		QueueNode *current = front;
		int num = 0;
		do
		{
			std::cout << "Player " << ++num << ":\n";
			std::cout << "Name: " << current->player->getName() << std::endl;
			std::cout << "Type: " << current->player->getType() << std::endl;
			current = current->next;
			std::cout << std::endl;

		} while (current != nullptr);
	}
	std::cout << std::endl;
}

void Queue::addPoint(int point)
{
	points = points + point;
}

int Queue::getPoints()
{
	return points;
}
