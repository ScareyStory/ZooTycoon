/***************************************************************************
** Program Name: Turtle.cpp
** Name:         Story Caplain
** Date:         01/25/19
** Description:  This is the .cpp file for the Turtle class.
**               It defines all the functions of the class.
***************************************************************************/
#include <iostream>
#include "Turtle.hpp"

int Turtle::getBabies() {
  return (numberOfBabies*10);
}

int Turtle::getFoodCost() {
  return (baseFoodCost*(0.5));
}

int Turtle::getPayoff() {
  return payoff;
}
