/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Header file for Vampire class.
***************************************************************/
#include "Character.hpp"

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire : public Character
{
	public:
		//Constructor
		Vampire();
		//Methods
		int attack();
		int defense(int);
};

#endif

