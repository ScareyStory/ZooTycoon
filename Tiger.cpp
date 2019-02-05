/***************************************************************************
** Program Name: Tiger.cpp
** Name:         Story Caplain
** Date:         01/25/19
** Description:  This is the .cpp file for the Tiger class.
**               It defines all the functions of the class.
***************************************************************************/
#include <iostream>
#include "Tiger.hpp"

int Tiger::getCost() {
  return (cost*100);
}

int Tiger::getFoodCost() {
  return (baseFoodCost*5);
}

int Tiger::getPayoff() {
  return (payoff*400);
}
