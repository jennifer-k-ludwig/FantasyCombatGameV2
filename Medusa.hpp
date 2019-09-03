/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Header file for Medusa class.
***************************************************************/
#include "Character.hpp"

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Character
{
	public:
		//Constructor
		Medusa();
		//Methods
		int attack();
		int defense(int);
};

#endif

