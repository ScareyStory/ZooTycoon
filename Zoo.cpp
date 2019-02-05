/**************************************************************************
** Program Name: Zoo.hpp
** Name:         Story Caplain
** Date:         01/25/19
** Description:  This is the implementation file for the Zoo class.
***************************************************************************/
#include <iostream>
#include <random>
#include "Zoo.hpp"

//use constructor to fill arrays with zero
Zoo::Zoo() {
  for(int i = 0; i < tigeSize; i++) {
    tigerArray[i] = 0;
  }

  for(int i = 0; i < pengSize; i++) {
    penguinArray[i] = 0;
  }

  for(int i = 0; i < turtSize; i++) {
    turtleArray[i] = 0;
  }
}

//accessor
int Zoo::getTigeSize() {
  return tigeSize;
}
//accessor
int Zoo::getPengSize() {
  return pengSize;
}
//accessor
int Zoo::getTurtSize() {
  return turtSize;
}

//check if room for tigers
int Zoo::canAddTigers(int moreTigers) {
  int openCages = 0;
  for(int i = 0; i < tigeSize; i++) {
    if(tigerArray[i]==0) {
      openCages++;
    }
  }
  //If there's room, return 1
  if(openCages >= moreTigers) {
    return 1;
  }
  //If there isn't room, return 0
  else if(openCages < moreTigers) {
    return 0;
  }
  else {
    return -1;
  }
}

//check if room for penguins
int Zoo::canAddPenguins(int morePenguins) {
  int openCages = 0;
  for(int i = 0; i < pengSize; i++) {
    if(penguinArray[i]==0) {
      openCages++;
    }
  }
  //If there's room, return 1
  if(openCages >= morePenguins) {
    return 1;
  }
  //If there isn't room, return 0
  else if(openCages < morePenguins) {
    return 0;
  }
  else {
    return -1;
  }
}

//check if room for turtles
int Zoo::canAddTurtles(int moreTurtles) {
  int openCages = 0;
  for(int i = 0; i < turtSize; i++) {
    if(turtleArray[i]==0) {
      openCages++;
    }
  }
  //If there's room, return 1
  if(openCages >= moreTurtles) {
    return 1;
  }
  //If there isn't room, return 0
  else if(openCages < moreTurtles) {
    return 0;
  }
  else {
    return -1;
  }
}

//increases number of tigers
void Zoo::addTigers(int newTigers) {
  for(int i = 0; i < newTigers; i++) {
    //if there is an open cage fill it
    if(tigerArray[i]==0) {
      tigerArray[i]++;
    }
    //if cage full keep looking
    else if(tigerArray[i] > 0) {
      newTigers++;
    }
  }
}

//increases number of penguins
void Zoo::addPenguins(int newPenguins) {
  for(int i = 0; i < newPenguins; i++) {
    //if there is an open cage fill it
    if(penguinArray[i]==0) {
      penguinArray[i]++;
    }
    //if cage full keep looking
    else if(penguinArray[i] > 0) {
      newPenguins++;
    }
  }
}

void Zoo::addTurtles(int newTurtles) {
  for(int i = 0; i < newTurtles; i++) {
    //if there is an open cage fill it
    if(turtleArray[i]==0) {
      turtleArray[i]++;
    }
    //if cage full keep looking
    else if(turtleArray[i] > 0) {
      newTurtles++;
    }
  }
}

//increases all tigers age by 1 day
void Zoo::tigerAge() {  
  for(int i = 0; i < tigeSize; i++) {
    if(tigerArray[i] >= 1) {
      tigerArray[i]++;
    }
  }
}  
  
//increases all penguins age by 1 day
void Zoo::penguinAge() {
  for(int i = 0; i < pengSize; i++) {
    if(penguinArray[i] >= 1) {
      penguinArray[i]++;
    }
  }
}

//increases all turtles age by 1 day
void Zoo::turtleAge() {
  for(int i = 0; i < turtSize; i++) {
    if(turtleArray[i] >= 1) {
      turtleArray[i]++;
    }
  }
}

//resize array
void Zoo::tigerResize() {

  int *temp;
  temp = new int[2*tigeSize];
  for(int i = 0; i < tigeSize; i++) {
    temp[i] = tigerArray[i];
  }
  tigeSize *= 2;
  delete [] tigerArray;
  tigerArray = temp;

}

//resize array
void Zoo::penguinResize() {

  int *temp;
  temp = new int[2*pengSize];
  for(int i = 0; i < pengSize; i++) {
    temp[i] = penguinArray[i];
  }
  pengSize *= 2;
  delete [] penguinArray;
  penguinArray = temp;

}

//resize array
void Zoo::turtleResize() {

  int *temp;
  temp = new int[2*turtSize];
  for(int i = 0; i < turtSize; i++) {
    temp[i] = turtleArray[i];
  }
  turtSize *= 2;
  delete [] turtleArray;
  turtleArray = temp;

}

//check if there are any animals
//0 - none of that animal
//1 = at least one baby but no adults of that animal
//2 = at least one adult of that animal
int Zoo::tigerCheck() {

  int atLeastOne = 0;

  for(int i = 0; i < tigeSize; i++) {
    //if there is a baby tiger
    if(tigerArray[i] >= 1 && tigerArray[i] < 3) {
      atLeastOne = 1;
    }
    //if there is an adult tiger
    else if(tigerArray[i] >= 3) {
      atLeastOne = 2;
      return atLeastOne;
    }
  }
  if(atLeastOne == 1 || atLeastOne == 0) {
    return atLeastOne;
  }
  else {
    return atLeastOne;
  }
}  

int Zoo::penguinCheck() {

  int atLeastOne = 0;
  
  for(int i = 0; i < pengSize; i++) {
    //if there is a baby penguin
    if(penguinArray[i] >= 1 && penguinArray[i] < 3) {
      atLeastOne = 1;
    }
    //if there is an adult penguin
    else if(penguinArray[i] >= 3) {
      atLeastOne = 2;
      return atLeastOne;
    }
  }
  if(atLeastOne == 1 || atLeastOne == 0) {
    return atLeastOne;
  }
  else {
    return atLeastOne;
  }
}  

int Zoo::turtleCheck() {
  
  int atLeastOne = 0;

  for(int i = 0; i < turtSize; i++) {
    //if there is a baby turtle
    if(turtleArray[i] >= 1 && turtleArray[i] < 3) {
      atLeastOne = 1;
    }
    //if there is an adult turtle
    else if(turtleArray[i] >= 3) {
      atLeastOne = 2;
      return atLeastOne;
    }
  }
  if(atLeastOne == 1 || atLeastOne == 0) {
    return atLeastOne;
  }
  else {
    return atLeastOne;
  }
}  

//delete arrays
void Zoo::deleter() {

  delete [] tigerArray;
  tigerArray = NULL;

  delete [] penguinArray;
  penguinArray = NULL;

  delete [] turtleArray;
  turtleArray = NULL;

}

void Zoo::print1() {
  std::cout << "\nTiger Array:\n";
  for(int i = 0; i < tigeSize; i++) {
    std::cout << tigerArray[i] << " ";
    if(( i % 10 ) == 9) {
      std::cout << "\n";
    }
  }
}

void Zoo::print2() {
  std::cout << "\nPenguin Array:\n";
  for(int i = 0; i < pengSize; i++) {
    std::cout << penguinArray[i] << " ";
    if(( i % 10 ) == 9) {
      std::cout << "\n";
    }
  }
}

void Zoo::print3() {
  std::cout << "\nTurtle Array:\n";
  for(int i = 0; i < turtSize; i++) {
    std::cout << turtleArray[i] << " ";
    if(( i % 10 ) == 9) {
      std::cout << "\n";
    }
  }
}

//Function to see how many tigers there are
int Zoo::howManyTigers() {
  int ti = 0; //tigers
  for(int i=0; i < tigeSize; i++) {
    if(tigerArray[i]>=1) {
      ti++;
    }
  }
  return ti;
}

//Function to see how many tigers there are
int Zoo::howManyPenguins() {
  int p = 0; //penguins
  for(int i=0; i < pengSize; i++) {
    if(penguinArray[i]>=1) {
      p++;
    }
  }
  return p;
}

//Function to see how many tigers there are
int Zoo::howManyTurtles() {
  int tu = 0; //turtles
  for(int i=0; i < turtSize; i++) {
    if(turtleArray[i]>=1) {
      tu++;
    }
  }
  return tu;
}

//Function takes in result of tigerCheck, penguinCheck etc. as params
int Zoo::randomEvent(int tigers, int penguins, int turtles) {
  int rando = 0;
  rando = rand();      //stores a random number inside rando
  rando = (rando % 4); //makes the random number in the range 0-3
  rando++;             //makes the random number in the range 1-4

  //if no animals, make random event be that nothing occurrs
  if(tigers==0&&penguins==0&&turtles==0&&(rando==1||rando==2||rando==3)) {
    rando = 4;
  }

  //If rando is 1, an animal dies
  if(rando==1) {
    int randomSpecies = 0;               //represents one of 3 species
    randomSpecies = rand();              //random number
    randomSpecies = (randomSpecies % 3); //random number range 0-2
    randomSpecies++;                     //random number range 1-3

    std::cout << "\n\n\nOh no... it looks like an animal is sick";

    //if no tigers but there are penguins, penguin dies
    if(tigers==0 && penguins!=0 && randomSpecies==1) {
      randomSpecies = 2;
    }
    //if no tigers or penguins but there are turtles, turtle dies
    else if(tigers==0 && turtles!=0 && randomSpecies==1) {
      randomSpecies = 3;
    }
    //if no penguins but there are tigers, a tiger dies
    else if(penguins==0 && tigers!=0 && randomSpecies==2) {
      randomSpecies = 1;
    }
    //if no penguins or tigers but there are turtles, a turtle dies
    else if(penguins==0 && turtles!=0 && randomSpecies==2) {
      randomSpecies = 3;
    }
    //if no turtles but there are penguins, a penguin dies
    else if(turtles==0 && penguins!= 0 && randomSpecies==3) {
      randomSpecies = 2;
    }
    //if no turtles or penguins, but there are tigers, a tiger dies
    else if(turtles==0 && tigers!=0 && randomSpecies==3) {
      randomSpecies = 1;
    }

    //if randomSpecies is 1, a tiger dies
    if(randomSpecies==1) {
      int randomTiger = 0;
      int tigerCount = tigeSize;
      
      randomTiger = rand();
      randomTiger = (randomTiger % tigerCount);
    
      int i = 0;

      while(i == 0) {
        if(tigerArray[randomTiger] >= 1) {
          tigerArray[randomTiger] = 0;
          i++;
        }
        else if(tigerArray[randomTiger] == 0 
                && randomTiger != (tigeSize-1)) {
                randomTiger++;
        }
        else {
          randomTiger = 0;
        }
      }
      std::cout << "\n\nA Tiger has died of illness...\n\n\n";
    }

    //if randomSpecies is 2, a penguin dies 
    if(randomSpecies==2) {
      int randomPenguin = 0;
      int penguinCount = pengSize;
      
      randomPenguin = rand();
      randomPenguin = (randomPenguin % penguinCount);
     
      int i = 0;

      while(i == 0) {
        if(penguinArray[randomPenguin] >= 1) {
          penguinArray[randomPenguin] = 0;
          std::cout << "\nPenguin "<<randomPenguin<<" died.\n";
          i++;
        }
        else if(penguinArray[randomPenguin] == 0 
                && randomPenguin != (pengSize-1)) {
                randomPenguin++;
        }
        else {
          randomPenguin = 0;
        }
      }
      std::cout << "\n\nA Penguin has died of illness...\n\n\n";
    }

    //if randomSpecies is 3, a turtle dies
    if(randomSpecies==3) {
      int randomTurtle = 0;
      int turtleCount = turtSize;
      
      randomTurtle = rand();
      randomTurtle = (randomTurtle % turtleCount);
     
      int i = 0;

      while(i == 0) {
        if(turtleArray[randomTurtle] >= 1) {
          turtleArray[randomTurtle] = 0;
          std::cout << "\nTurtle "<<randomTurtle<<" died.\n";
          i++;
        }
        else if(turtleArray[randomTurtle] == 0 
                && randomTurtle != (turtSize-1)) {
                randomTurtle++;
        }
        else {
          randomTurtle = 0;
        }
      }
      std::cout << "\n\nA Turtle has died of illness...\n\n\n";
    }
    return 0; 
  } // end of rando == 1

  //Tigers make more money
  else if(rando==2) {

    std::cout << "\n\n";
    std::cout << "\nBreaking news! People worldwide want to see tigers!\n";
    if(tigers==0) {
      std::cout << "Although it looks like your zoo has none...\n";
      std::cout << "No extra money is made.\n";
      return 0;
    }
    else if(tigers > 0) {      
      std::cout << "Tiger enthusiasts flock to your zoo!\n";
      
      int numberOfTigers = 0;
      for(int x = 0; x < tigeSize; x++) {
        if(tigerArray[x]>=1) {
          numberOfTigers++;
        }
      }

      //make the random boost in earnings between 250 and 500
      int randomEarnings = rand();
      randomEarnings = randomEarnings % 251;
      randomEarnings += 250;

      randomEarnings = randomEarnings * numberOfTigers;

      std::cout << "You earn $" << randomEarnings << " extra today.\n";
      std::cout << "\n\n";

      return randomEarnings;      
    }
  } //end of rando == 2

  //A baby animal is born
  else if(rando==3) {

    std::cout << "\n\n";
    std::cout << "\nQuickly! Alert the zoo that a baby is being born!\n";
    int randomSpecies = rand();
    randomSpecies = (randomSpecies % 3);
    randomSpecies++;

    //if no adult tigers but there are adult penguins, a penguin is born
    if(tigers!=2 && penguins==2 && randomSpecies==1) {
      randomSpecies = 2;
    }
    //if no adult tigers or adult penguins but there are adult turtles 
    //a turtle is born
    else if(tigers!=2 && turtles==2 && randomSpecies==1) {
      randomSpecies = 3;
    }
    //if no adult penguins but there are adult tigers, a tiger is born
    else if(penguins!=2 && tigers==2 && randomSpecies==2) {
      randomSpecies = 1;
    }
    //if no adult penguins or adult tigers but there are adult turtles 
    //a turtle is born
    else if(penguins!=2 && turtles==2 && randomSpecies==2) {
      randomSpecies = 3;
    }
    //if no adult turtles but there are adult penguins, a penguin is born
    else if(turtles!=2 && penguins==2 && randomSpecies==3) {
      randomSpecies = 2;
    }
    //if no adult turtles or adult penguins but there are adult tigers 
    //a tiger is born
    else if(turtles!=2 && tigers==2 && randomSpecies==3) {
      randomSpecies = 1;
    }

    //1 = tiger
    if(randomSpecies==1) {
      
      std::cout << "It is a baby tiger! The zoo now has a new tiger.\n";
      std::cout << "\n\n";

      return randomSpecies;
    }

    //2 = penguin
    else if(randomSpecies==2) {
      
      std::cout << "It is a baby penguin! The zoo now has a new penguin.\n";
      std::cout << "\n\n";

      return randomSpecies;
    }

    //3 = turtle
    else if(randomSpecies==3) {

      std::cout << "It is a baby turtle! The zoo now has a new turtle.\n";
      std::cout << "\n\n";

      return randomSpecies;
    }
  
    std::cout << "\n\n";
  
  } //end of rando == 3

  else {

    std::cout << "\n\n\nToday was a quiet day at the zoo.\n\n\n";

    return 0;
  }
} //End of random event function
