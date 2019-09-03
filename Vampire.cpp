/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Implementation file for Vampire class.
***************************************************************/
#include "Character.hpp"
#include "Vampire.hpp"
#include <iostream>
//Constructor
Vampire::Vampire()
{
	setAttackRoll(0);
	setDefenseRoll(0);
	setArmor(1);
	setStrengthPoints(18);
	setType("Vampire");
	setAttackDieType("1d12");
	setDefenseDieType("1d6");
}

//Methods
int Vampire::attack()
{
	setAttackRoll(rollDie(1, 12));
	return attackRoll;
}

int Vampire::defense(int attack)
{
	int outcome = random(1, 2); //Outcome is 50/50 whether charm will work

	if (outcome == 1)//Charm worked, opponent did not attack
	{	
		//std::cout << "\nVampire used charm!\n"; 
		return 0; 
	}
	else if (outcome == 2)//Charm did not work, opponent attacked
	{
		setDefenseRoll(rollDie(1, 6));
		return (attack - defenseRoll - armor);
	}
	return 0;	
}


