/***************************************************************************
** Program Name: Penguin.cpp
** Name:         Story Caplain
** Date:         01/25/19
** Description:  This is the .cpp file for the Penguin class.
**               It defines all the functions of the class.
***************************************************************************/
#include <iostream>
#include "Penguin.hpp"

int Penguin::getCost() {
  return (cost*10);
}

int Penguin::getBabies() {
  return (numberOfBabies*5);
}

int Penguin::getPayoff() {
  return (payoff*20);
}
