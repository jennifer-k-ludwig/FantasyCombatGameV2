/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Implementation file for Character class.
***************************************************************/
#include "Character.hpp"
#include <iostream>
#include <stdlib.h>

//Constructor
Character::Character()
{
	setAttackRoll(0);
	setDefenseRoll(0);
	setArmor(0);
	setStrengthPoints(0);
	setType("No type");
	setAttackDieType("No type");
	setDefenseDieType("No type");
}

//Destructor
Character::~Character()
{
}

//Setters
void Character::setAttackRoll(int attack)
{
	this->attackRoll = attack;
}

void Character::setDefenseRoll(int defense)
{
	this->defenseRoll = defense;
}

void Character::setArmor(int armor)
{
	this->armor = armor;
}

void Character::setStrengthPoints(int strengthPoints)
{
	this->strengthPoints = strengthPoints;
}

void Character::setType(std::string type)
{
	this->type = type;
}

void Character::setAttackDieType(std::string type)
{
	this->attackDieType = type;
}

void Character::setDefenseDieType(std::string type)
{
	this->defenseDieType = type;
}

void Character::setName(std::string name)
{
	this->name = name;
}

//Getters
int Character::getAttackRoll()
{
	return attackRoll;
}

int Character::getDefenseRoll()
{
	return defenseRoll;
}

int Character::getArmor()
{
	return armor;
}

int Character::getStrengthPoints()
{
	return strengthPoints;
}

std::string Character::getType()
{
	return type;
}

std::string Character::getAttackDieType()
{
	return attackDieType;
}

std::string Character::getDefenseDieType()
{
	return defenseDieType;
}

std::string Character::getName()
{
	return name;
}

//Methods
int Character::random(int low, int high)
{
	return low + rand() % ((high + 1) - low);
}

int Character::rollDie(int numberOfDie, int sidesOfDie)
{
	int total = 0;

	while (numberOfDie > 0)
	{
		total = total + random(1, sidesOfDie);
		numberOfDie--;
	}

	return total;
}

void Character::recovers(int originalSP)
{
	//Strength points after attack
	int tempSP = strengthPoints;

	//Difference in points before and after attack
	int difference = originalSP - strengthPoints;

	//Randomly chosen amount of points for recovery
	int recoveryPoints = random(0, difference);

	//Add recovery points to SPs	
	strengthPoints += recoveryPoints;

	//Percent recovered
	double percentChange = ((static_cast<double>(strengthPoints)/static_cast<double>(tempSP)) - 1) * 100;
	std::cout << getType() << " recovered " << percentChange << "%" << std::endl;
}
