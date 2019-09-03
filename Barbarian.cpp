/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Implementation file for Barbarian class.
***************************************************************/
#include "Character.hpp"
#include "Barbarian.hpp"

//Constructor
Barbarian::Barbarian()
{
	setAttackRoll(0);
	setDefenseRoll(0);
	setArmor(0);
	setStrengthPoints(12);
	setType("Barbarian");
	setAttackDieType("2d6");
	setDefenseDieType("2d6");
}

//Methods
int Barbarian::attack()
{
	setAttackRoll(rollDie(2, 6));
	return attackRoll;
}

int Barbarian::defense(int attack)
{
	setDefenseRoll(rollDie(2, 6));
	return (attack - defenseRoll - armor);
}

