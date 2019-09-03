#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"


#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode
{
	Character *player;
	QueueNode *next;
	QueueNode(Character *playerIn, QueueNode *nextIn = nullptr)
	{
		next = nextIn;
		player = playerIn;
	}
};

class Queue
{
	private:
		QueueNode *front;
		QueueNode *rear;
		int points;
	public:
		Queue();
		~Queue();
		void push(Character*);
		Character* pop();
		Character* getFront();
		bool isEmpty() const;
		void printQueue();
		void addPoint(int);
		int getPoints();
};

#endif
