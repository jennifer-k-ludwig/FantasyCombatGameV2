/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/17/2019
 * Description: Implementation file for driver functions.
***************************************************************/
#include "driverFunctions.hpp"
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

/***************************************************************
 * Function Name: void playGame
 * Parameters: N/A
 * Description: Main gameplay function
***************************************************************/

void playGame()
{
	//Seed random number generator once (for randomOrder function)
	srand( time(NULL) );

	//While user desires to keep playing, start game
	do
	{
		int num1 = 0, num2 = 0;
		Queue team1, team2;
		Stack losers;
		std::string t1 = "Team #1", t2 = "Team #2";

		clearScreen();
		std::cout << ":: Fantasy Combat Tournament ::\n\n";

		std::cout << "Enter the number of players for each team (1-20).\n";

		//Set players team 1
		std::cout << std::endl;
		setNumPlayers(num1, t1);	

		//Set players team 2
		setNumPlayers(num2, t2);	
		
		std::cout << "\n:: Create Teams ::\n";

		//Create team 1
		std::cout << std::endl;
		std::cout << t1 << ":" << std::endl;
		std::cout << "---------------------------------------------------\n";
		createTeam(team1, num1);

		//Create team 2
		std::cout << std::endl;
		std::cout << t2 << ":" << std::endl;
		std::cout << "---------------------------------------------------\n";
		createTeam(team2, num2);

		//Print teams (for testing purposes)
		std::cout << ":: Chosen Teams ::\n";
		std::cout << "---------------------------------------------------\n";
		std::cout << t1 << std::endl;
		team1.printQueue();
	
		std::cout << std::endl;
		std::cout << t2 << std::endl;
		team2.printQueue();
		
		int round = 0;

		//While both teams have players, continue to battle
		do
		{
			std::cout << "\nRound " << ++round << std::endl;
			std::cout << "---------------------------------------------------\n";
		
			std::cout << "Team 1 " << "'" << team1.getFront()->getName() 
			<< "' (" << team1.getFront()->getType() << ") vs. Team 2 '" <<
			team2.getFront()->getName() << "' (" << team2.getFront()->getType()
			 << ")" << std::endl;
	
			battle(team1, team2, losers);
		
			//Print both teams and loser pile (for testing purposes)	
			std::cout << std::endl;
			/*	
			std::cout << ":: Chosen Teams ::\n";
			std::cout << t1 << std::endl;
			std::cout << "Points: " << team1.getPoints() << std::endl;
			team1.printQueue();
		
			std::cout << std::endl;
			std::cout << t2 << std::endl;
			std::cout << "Points: " << team2.getPoints() << std::endl;
			team2.printQueue();

			std::cout << std::endl;
			losers.printStack();
			*/
		} while (hasPlayers(team1, team2));
			
		std::cout << std::endl;
		printResults(team1, team2);
		std::cout << std::endl;
		displayLosers(losers);

	} while (keepPlaying());
}

/***************************************************************
 * Function Name: void battle
 * Parameters: Queue &, Queue &, Stack &
 * Description: Main battle function. Players at the front of
 * 		each team battle to the death of one player.
 * 		Winning team gets a point, the winner recovers,
 * 		and the head is moved to the next player.
 * 		Losing team's head gets pushed to loser stack
 * 		and removed from team.
***************************************************************/

void battle(Queue &team1, Queue &team2, Stack &losers)
{
	int beforeSPt1 = team1.getFront()->getStrengthPoints();
	int beforeSPt2 = team2.getFront()->getStrengthPoints();

	//While both characters are alive, let them battle (order of attacks is random)
	do
	{
		randomOrder(team1.getFront(), team2.getFront());

	} while (charactersAlive(team1.getFront(), team2.getFront()));

	//If player 1 loses
	if (team1.getFront()->getStrengthPoints() < 1)
	{
		std::cout << "Team 2 '" << team2.getFront()->getName() << "' ("
		<< team2.getFront()->getType() << ") won!\n\n";

		//Winner recovers
		team2.getFront()->recovers(beforeSPt2);
		
		//Pop off the front of each team
		Character *winner = team2.pop();
		Character *loser = team1.pop();

		//Add a point to team 2 and move head pointer to next position
		team2.addPoint(1);
		team2.push(winner);

		//Push team 1's head character to loser stack and remove front
		losers.push(loser);
	}

	//If player 2 loses
	else if (team2.getFront()->getStrengthPoints() < 1)
	{
		std::cout << "Team 1'" << team1.getFront()->getName() << "' ("
		<< team1.getFront()->getType() << ") won!\n\n";

		//Winner recovers
		team1.getFront()->recovers(beforeSPt1);
		
		//Pop off the front of each team
		Character *winner = team1.pop();
		Character *loser = team2.pop();

		//Add a point to team 1 and move head pointer to next position
		team1.addPoint(1);
		team1.push(winner);

		//Push team 1's character to loser stack and remove front
		losers.push(loser);
	}

}

/***************************************************************
 * Function Name: void setNumPlayers
 * Parameters: int &, std::string
 * Description: Input validation for number of players on each
 * 		team.
***************************************************************/

void setNumPlayers(int &num, std::string team)
{
	bool choiceInvalid = true;
	std::string selection = "";

	while (choiceInvalid)
	{
		std::cout << team << ": ";
		std::getline(std::cin, selection);

		if (isInteger(selection))
		{
			if (std::stoi(selection) > 0 && std::stoi(selection) < 21)
			{ num = std::stoi(selection); choiceInvalid = false; }
			else
			{ std::cout << "Number is out of range.\n"; }
		}
		else
		{ std::cout << "Please enter an integer.\n"; }
 	}
}

/***************************************************************
 * Function Name: void createTeam
 * Parameters: Queue &, int
 * Description: Creates each team.
***************************************************************/

void createTeam(Queue &queue, int num)
{
	std::cout << "Choose a character type and name for each team member.\n";

	std::cout << "\nCharacter Types:\n";
	std::cout << "1. Vampire\n";
	std::cout << "2. Barbarian\n";
	std::cout << "3. Blue Men\n";
	std::cout << "4. Medusa\n";
	std::cout << "5. Harry Potter\n\n";

	for (int i = 0; i < num; ++i)
	{
		std::cout << "Player #" << i + 1 << std::endl;
		setPlayer(queue);
		std::cout << std::endl;
	}
}

/***************************************************************
 * Function Name: void setPlayer
 * Parameters: Queue &
 * Description: Input validation for character type and name.
 * 		Adds character to queue (team).
***************************************************************/

void setPlayer(Queue &queue)
{
	bool charInvalid = true;
	std::string selection = "", name = "";
	Character *player = nullptr;

	while (charInvalid)
	{
		std::cout << "Character Type: ";
		std::getline(std::cin, selection);

		if (isInteger(selection))
		{
			if (std::stoi(selection) == 1)
			{	player = new Vampire; charInvalid = false; }
			else if (std::stoi(selection) == 2)
			{	player = new Barbarian; charInvalid = false; }
			else if (stoi(selection) == 3)
			{	player = new BlueMen; charInvalid = false; }
			else if (std::stoi(selection) == 4)
			{	player = new Medusa; charInvalid = false; }
			else if (std::stoi(selection) == 5)
			{	player = new HarryPotter; charInvalid = false; }			
			else
				std::cout << "Please enter a number from the menu above.\n";	
		}
		else
			std::cout << "Please enter a number from the menu above.\n";	
 	}
	
	std::cout << "Name: ";
	std::getline(std::cin, name);

	player->setName(name);

	queue.push(player);
}

/***************************************************************
 * Function Name: int random
 * Parameters: int low, int high
 * Description: Returns random number between low and high.
***************************************************************/

int random(int low, int high)
{
	return low + rand() % ((high + 1) - low);
}

/***************************************************************
 * Function Name: void randomOrder
 * Parameters:
 * Description: Orders the attacks randomly. 
***************************************************************/

void randomOrder(Character *p1, Character *p2)
{
	int goesFirst = random(1, 2);

	if (goesFirst == 1)
	{
//		std::cout << "\n:: Attack #1 ::\n";
		playerAttack(p1, p2);
//		std::cout << ":: Attack #2 ::\n";
		playerAttack(p2, p1);
	}
	else if (goesFirst == 2)
	{
//		std::cout << "\n:: Attack #1 ::\n";
		playerAttack(p2, p1);
//		std::cout << ":: Attack #2 ::\n";
		playerAttack(p1, p2);
	}		
}

/***************************************************************
 * Function Name: void playerAttack 
 * Parameters: Character *attacker, Character *defender
 * Description: Carrys out one attack. 
***************************************************************/

void playerAttack(Character *&attacker, Character *&defender)
{
	int damage = defender->defense(attacker->attack());
	int newSP = defender->getStrengthPoints() - damage;

//	printDetails(attacker, defender, damage, newSP);

	defender->setStrengthPoints(newSP);
}


/***************************************************************
 * Function Name: bool charactersAlive 
 * Parameters: Character *p1, Character *p2
 * Description: Checks if both characters are alive. If so, 
 * 		returns true, if not, returns false. 
***************************************************************/

bool charactersAlive(Character *p1, Character *p2)
{
	if (p1->getStrengthPoints() > 0 && p2->getStrengthPoints() > 0)
		return true;
	else
	{
		return false;
	}
}
/***************************************************************
 * Function Name: void printDetails 
 * Parameters: Character *attacker, Character *defender, int damage, int newSP
 * Description: Prints details for each attack.
***************************************************************/

void printDetails(Character *attacker, Character *defender, int damage, int newSP)
{
	std::cout << "Attacker type: " << attacker->getType() << std::endl;
	std::cout << "Dice roll (" << attacker->getAttackDieType() << "): " << attacker->getAttackRoll() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Defender type: " << defender->getType() << std::endl;
	std::cout << "Dice roll (" << defender->getDefenseDieType() << "): " << defender->getDefenseRoll() << std::endl;
	std::cout << "Armor: " << defender->getArmor() << std::endl;
	std::cout << "Damage: " << damage << std::endl;
	std::cout << "Strength points: " << defender->getStrengthPoints() << std::endl;
	std::cout << "New strength points: " << newSP << std::endl;
	std::cout << std::endl;
}


/***************************************************************
 * Function Name: bool keepPlaying
 * Parameters: N/A
 * Description: Asks user if they would like to keep playing.
***************************************************************/

bool keepPlaying()
{
	std::string choice;
	bool choiceInvalid = true;

	std::cout << "Menu" << std::endl;
	std::cout << "---------------------------------------------------\n";
	std::cout << "1. Play again" << std::endl;
	std::cout << "2. Exit" << std::endl;

	while (choiceInvalid)
	{
		std::cout << "\nPlease enter a number from the menu above: ";	
		std::getline(std::cin, choice);

		if (isInteger(choice))
		{
			if (std::stoi(choice) == 1)
			{	return true; }
			else if (std::stoi(choice) == 2)
				return false;
		}
 	} 

	return false;
}

/***************************************************************
 * Function Name: bool isInteger
 * Parameters: std::string
 * Description: Returns false string is empty, returns true if
 * 		string length is 1 and the first char of string
 * 		is a digit, returns false if first char of 
 * 		string is - and the second char is not a digit,
 * 		and checks if the rest of the string is a digit.
 * Source: Phi Luu
***************************************************************/

bool isInteger(std::string s)
{
	if (s.empty())
		return false;

	if (s.length() == 1 && isdigit(s[0]))
		return true;

	if (s[0] != '-' && !isdigit(s[0]))
		return false;

	return (std::all_of(s.begin() + 1, s.end(), ::isdigit));
}


/***************************************************************
 * Function Name: void clearScreen
 * Parameters: None
 * Description: Clears screen by inserting 100 lines.
***************************************************************/

void clearScreen()
{
	std::cout << std::string(100, '\n');
}


/***************************************************************
 * Function Name: bool hasPlayers
 * Parameters:	Queue, Queue
 * Description: Checks if both queues are empty. If not, game
 * 		continues. If one or both queues are empty,
 * 		game ends.
***************************************************************/

bool hasPlayers(Queue &queue1, Queue &queue2)
{
	if (queue1.isEmpty() && queue2.isEmpty())
	{
		std::cout << "Team 1 and Team 2 are out of players. GAME OVER.\n";
		return false;
	}
	else if (queue1.isEmpty())
	{
		std::cout << "Team 1 is out of players. GAME OVER.\n";
		return false;
	}
	else if (queue2.isEmpty())
	{
		std::cout << "Team 2 is out of players. GAME OVER.\n";
		return false;
	}
	else
		return true;
}

/***************************************************************
 * Function Name: void printResults
 * Parameters: Queue, Queue
 * Description: Prints final points and determines winner.
***************************************************************/

void printResults(Queue &queue1, Queue &queue2)
{
	std::cout << ":: Results ::\n";
	std::cout << "Team 1 Points: " << queue1.getPoints() << std::endl;
	std::cout << "Team 2 Points: " << queue2.getPoints() << std::endl;

	if (queue1.getPoints() > queue2.getPoints())
	{ std::cout << "Team 1 wins!" << std::endl; }
	else if (queue2.getPoints() > queue1.getPoints())
	{ std::cout << "Team 2 wins!" << std::endl; }
	else
	{ std::cout << "Team 1 and Team 2 tied!" << std::endl; }
}

/***************************************************************
 * Function Name: void displayLosers
 * Parameters: Stack
 * Description: Prints stack of losers at user's request.
***************************************************************/

void displayLosers(Stack &losers)
{
	std::string answer = "";
	bool invalid = true;

	while(invalid)
	{
		std::cout << "Would you like to see the contents of the loser pile? y/n?\n";
		std::getline(std::cin, answer);

		if (answer.length() > 1)
			std::cout << "Please enter y or n." << std::endl;
		else if (tolower(answer[0]) == 'y')
		{	std::cout << std::endl;
			losers.printStack(); invalid = false;}
		else if (tolower(answer[0]) == 'n')
		{	invalid = false;}
		else
			std::cout << "Please enter y or n." << std::endl;
	}

}
