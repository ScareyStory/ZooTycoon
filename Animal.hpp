/**************************************************************************
** Program Name: Animal.hpp
** Name:         Story Caplain
** Date:         01/24/19
** Description:  This is the implementation file for the Animal class.
**               It is the parent class in the Zoo Tycoon game.
***************************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {

private:

protected:

  int age = 1;
  int cost = 100;
  int numberOfBabies = 1;
  int baseFoodCost = 10;
  int payoff = 5;

public:

  int getAge();

  void setAge(int);

  int getCost();

  int getBabies();

  int getFoodCost();
  
  int getPayoff();

};
#endif
