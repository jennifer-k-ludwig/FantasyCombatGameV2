/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Header file for driver functions.
***************************************************************/
#include "Character.hpp"
#include "Queue.h"
#include "Stack.h"

#include <string>

#ifndef DRIVERFUNCTIONS_HPP
#define DRIVERFUNCTIONS_HPP

void menuInput();
void playGame();
void setNumPlayers(int &, std::string);
void createTeam(Queue &, int);
void setPlayer(Queue &);
//void printDetails(Character *attacker, Character *defender, int damage, int newSP);
void playerAttack(Character *&attacker, Character *&defender);
bool charactersAlive(Character *p1, Character *p2);
void clearScreen();
void randomOrder(Character *, Character *);
void battle(Queue &, Queue &, Stack &);
void printResults(Queue &, Queue &);
void displayLosers(Stack &);

bool keepPlaying();
bool hasPlayers(Queue &, Queue &);
bool isInteger(std::string);

int random(int, int);

#endif
