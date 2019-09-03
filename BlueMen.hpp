/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Header file for BlueMen class.
***************************************************************/
#include "Character.hpp"

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character
{
	public:
		//Constructor
		BlueMen();
		//Methods
		int attack();
		int defense(int);
};

#endif

