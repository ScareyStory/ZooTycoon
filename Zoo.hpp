/**************************************************************************
** Program Name: Zoo.hpp
** Name:         Story Caplain
** Date:         01/25/19
** Description:  This is the implementation file for the Zoo class.
***************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include <iostream>

class Zoo {

private:

  int tigeSize = 10;
  int pengSize = 10;
  int turtSize = 10;

  int *tigerArray   = new int[tigeSize];
  int *penguinArray = new int[pengSize];
  int *turtleArray  = new int[turtSize];

protected:

public:

  //Constructor
  Zoo();

  //size accessor
  int getTigeSize();
  int getPengSize();
  int getTurtSize();

  //Checks to see if the number of animals bought or born can fit in the
  //current array or if resizing is necessary.
  int canAddTigers(int);
  int canAddPenguins(int);
  int canAddTurtles(int);

  //add number of each animal bought or born
  void addTigers(int);
  void addPenguins(int);
  void addTurtles(int);

  //loop through array and increase each element by 1
  //this increase represents aging a day
  void tigerAge();   
  void penguinAge(); 
  void turtleAge();  

  //resizes arrays
  void tigerResize();     
  void penguinResize();   
  void turtleResize();    

  //loop through array and check if each element is one to see if
  //there are still any animals at the end of each turn
  int tigerCheck();
  int penguinCheck();
  int turtleCheck();

  //Deletes the animal arrays
  void deleter();         

  //Prints arrays
  void print1();
  void print2();
  void print3();

  //Returns how many of each animal there are
  int howManyTigers();
  int howManyPenguins();
  int howManyTurtles();

  //Creates random event
  int randomEvent(int, int, int);

};
#endif
