/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Header file for HarryPotter class.
***************************************************************/
#include "Character.hpp"

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter : public Character
{
	private:
		int lives;
	public:
		//Constructor
		HarryPotter();
		//Setters
		void setLives(int);
		//Methods
		int attack();
		int defense(int);
};

#endif

