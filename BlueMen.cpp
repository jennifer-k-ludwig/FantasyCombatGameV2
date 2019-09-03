/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Implementation file for BlueMen class.
***************************************************************/
#include "Character.hpp"
#include "BlueMen.hpp"
#include <iostream>
//Constructor
BlueMen::BlueMen()
{
	setAttackRoll(0);
	setDefenseRoll(0);
	setArmor(3);
	setStrengthPoints(12);
	setType("Blue Men");
	setAttackDieType("2d10");
	setDefenseDieType("3d6");
}

//Methods
int BlueMen::attack()
{
	setAttackRoll(rollDie(2, 10));
	return attackRoll;
}

int BlueMen::defense(int attack)
{
	if (strengthPoints > 8)
		setDefenseRoll(rollDie(3, 6));
	else if (strengthPoints > 4)
	{	
//		std::cout << "\nBlue Men used Mob and lost a die!\n";
		setDefenseRoll(rollDie(2, 6)); 
		setDefenseDieType("2d6"); 
	}
	else if (strengthPoints > 0)		
	{	
//		std::cout << "\nBlue Men used Mob and lost a die!\n";
		setDefenseRoll(rollDie(1, 6)); 
		setDefenseDieType("1d6"); 
	}

	return (attack - defenseRoll - armor);
}
