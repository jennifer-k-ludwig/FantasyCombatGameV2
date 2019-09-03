/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Implementation file for HarryPotter class.
***************************************************************/
#include "Character.hpp"
#include "HarryPotter.hpp"
#include <iostream>
//Constructor
HarryPotter::HarryPotter()
{
	setAttackRoll(0);
	setDefenseRoll(0);
	setArmor(0);
	setStrengthPoints(10);
	setType("Harry Potter");
	setLives(1);
	setAttackDieType("2d6");
	setDefenseDieType("2d6");
}
//Setters
void HarryPotter::setLives(int lives)
{
	this->lives = lives;
}

//Methods
int HarryPotter::attack()
{
	setAttackRoll(rollDie(2, 6));
	return attackRoll;
}

int HarryPotter::defense(int attack)
{
	setDefenseRoll(rollDie(2, 6));
	int damage = attack - defenseRoll - armor;
	int tempSP = strengthPoints - damage;

	if (tempSP < 1 && lives > 0)
	{
		setStrengthPoints(20);
		lives--;
//		std::cout << "\nHarry Potter used Hogwarts and came back to life!\n";
		return 0;
	}
	else
		return damage;
}
