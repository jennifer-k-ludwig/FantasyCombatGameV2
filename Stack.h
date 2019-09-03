#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"

#include "Queue.h"

#ifndef STACK_H
#define STACK_H

struct Node
{
	Character *player;
	Node *next;
	Node(Character *playerIn = nullptr, Node *nextIn = nullptr)
	{
		player = playerIn;
		next = nextIn;
	}
};

class Stack
{
	private:
		Node *top;

	public:
		Stack();
		~Stack();
		void push(Character *);
		Character* pop();
		bool isEmpty();
		void printStack();
};

#endif
