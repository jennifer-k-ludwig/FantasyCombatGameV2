/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/17/2019
 * Description: Main file for Fantasy Combat Tournament.
***************************************************************/
#include "Queue.h"
#include "Stack.h"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <algorithm>

#include "driverFunctions.hpp"

int main()
{
	clearScreen();
	std::cout << ":: Fantasy Combat Tournament ::\n\n";
	
	std::cout << "Menu" << std::endl;
	std::cout << "---------------------------------------------------\n";
	std::cout << "1. Play\n";
	std::cout << "2. Exit\n\n";
	
	bool choiceInvalid = true;
	std::string selection = "";

	while (choiceInvalid)
	{
		std::cout << "Enter a number from the menu above: ";
		std::getline(std::cin, selection);

		if (isInteger(selection))
		{
			if (std::stoi(selection) == 1)
			{	playGame(); choiceInvalid = false; }
			else if (std::stoi(selection) == 2)
			{	choiceInvalid = false; }
		}
 	} 

	return 0;
}



