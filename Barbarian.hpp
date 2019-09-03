/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Header file for Barbarian class.
***************************************************************/
#include "Character.hpp"

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian : public Character
{
	public:
		//Constructor
		Barbarian();
		//Methods
		int attack();
		int defense(int);
};

#endif

