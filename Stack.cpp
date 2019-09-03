#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"

#include "Queue.h"
#include "Stack.h"

#include <iostream>

Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	while (!isEmpty())
	{
		Node *garbage = top;
		top = top->next;
		delete garbage;
		garbage = nullptr;
	}
}

void Stack::push(Character* playerIn)
{
	if (isEmpty())
	{
		top = new Node(playerIn);
	}
	else
	{
		Node *temp = new Node(playerIn);
		temp->next = top;
		top = temp;
	}
}

Character* Stack::pop()
{
	std::cout << "Pop: ";
	if (!isEmpty())
	{
		Character *temp = top->player;
		Node *oldTop = top;
		top = oldTop->next;
		delete oldTop;
		return temp;
	}
	else
	{ std::cout << "Losers pile is empty."; }
	std::cout << std::endl;
}

bool Stack::isEmpty()
{
	return (top == nullptr);
}

void Stack::printStack()
{
	std::cout << "Losers\n";
	std::cout << "---------------------------------------------------\n";
	if (!isEmpty())	
	{
		int num = 0;
		Node *current = top;
		while (current != nullptr)
		{
			std::cout << "Loser #" << ++num << "\n";
			std::cout << "Name: " << current->player->getName() << std::endl;
			std::cout << "Type: " << current->player->getType() << std::endl;
			current = current->next;
			std::cout << std::endl;
		}
	}
	else
	{ std::cout << "Losers pile is empty."; }
	std::cout << std::endl;
}

