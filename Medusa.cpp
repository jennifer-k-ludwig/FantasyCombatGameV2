/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Implementation file for Medusa class.
***************************************************************/
#include "Character.hpp"
#include "Medusa.hpp"
#include <iostream>
//Constructor
Medusa::Medusa()
{
	setAttackRoll(0);
	setDefenseRoll(0);
	setArmor(3);
	setStrengthPoints(8);
	setType("Medusa");
	setAttackDieType("2d6");
	setDefenseDieType("1d6");
}

//Methods
int Medusa::attack()
{
	setAttackRoll(rollDie(2, 6));

	if (attackRoll == 12)
	{	//std::cout << "\nMedusa used Glare!\n"; 
		return 1000; 
	}
	else
		return attackRoll;
}

int Medusa::defense(int attack)
{
	setDefenseRoll(rollDie(1, 6));
	return (attack - defenseRoll - armor);
}
