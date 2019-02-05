/**************************************************************************
** Program Name: Animal.cpp
** Name:         Story Caplain
** Date:         01/24/19
** Description:  This is the .cpp file for the Animal class.
**               It defines all the functions of the class.
***************************************************************************/
#include <iostream>
#include "Animal.hpp"

int Animal::getAge() {
  return age;
}

void Animal::setAge(int daysOld) {
  age = daysOld;
}

int Animal::getCost() {
  return cost;
}

int Animal::getBabies() {
  return numberOfBabies;
}

int Animal::getFoodCost() {
  return baseFoodCost;
}

int Animal::getPayoff() {
  return payoff;
}
