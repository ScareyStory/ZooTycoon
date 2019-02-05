/***************************************************************************
** Program Name: main.cpp
** Name:         Story Caplain
** Date:         01/25/19
** Description:  This program lets the user play a Zoo tycoon game. The user
**               starts with $100,000 and can buy animals to start. Tigers
**               cost $10000, penguins cost $1000, and turtles cost $100.
**               The game lasts until the user quits or runs out of money.
**               A random event can happen each day, with either negative
**               or positive consequences. Animals make money for the zoo
**               each day.
***************************************************************************/
#include <iostream>
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Zoo.hpp"
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

  int funds = 100000;     //player's money count
  int val   = 1;          //used for input validation
  int play  = 0;          //used to check if user wants to play
  int day   = 1;          //keeps track of what day it is

  int tigersBought   = 0; //used to track tigers bought per day
  int penguinsBought = 0; //used to track penguins bought per day
  int turtlesBought  = 0; //used to track turtles bought per day

  Tiger   tig;            //Tiger object
  Penguin peng;           //Pengiun object
  Turtle  turt;           //Turtle object
  Zoo     z;              //Zoo object  

  play = menu();

  while(play == 1) {

    int cost = 0; //to show user how much their animal purchases cost

    cout << "\n";
    cout << "Thank you for playing! In this game you will run a zoo.\n";
    cout << "You can purchase tigers, penguins, and turtles which return\n";
    cout << "a profit based on zoo attendance that kind of animal can\n";
    cout << "bring. Be wary! a random event can occur each day, either\n";
    cout << "bad, good, or neutral. As long as you have either money or\n";
    cout << "an animal you can continue running, else the zoo shuts down.";
    cout << "\nTo start, you must buy one or two of each animal.\n";
    cout << "Also, random events don't start happening until the 2nd day.";
    cout << endl;



    cout << "\nWould you like to purchase 1 or 2 tigers to start: ";
    cin  >> tigersBought;
    val = 1;
    while(val == 1) {
      if(cin.fail() || tigersBought < 1 || tigersBought > 2) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter a 1 or 2: " << endl;
        cin  >> tigersBought;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');

    cout << "Would you like to purchase 1 or 2 penguins to start: ";
    cin  >> penguinsBought;
    val = 1;
    while(val == 1) {
      if(cin.fail() || penguinsBought < 1 || penguinsBought > 2) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter a 1 or 2: " << endl;
        cin  >> penguinsBought;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();    
    cin.ignore(256, '\n');

    cout << "Would you like to purchase 1 or 2 turtles to start: ";
    cin  >> turtlesBought;
    val = 1;
    while(val == 1) {
      if(cin.fail() || turtlesBought < 1 || turtlesBought > 2) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter a 1 or 2: " << endl;
        cin  >> turtlesBought;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');

    //find money left after initial purchases.
    int newFunds = 0;
    newFunds = funds - (tigersBought*(tig.getCost()))
                     - (penguinsBought*(peng.getCost()))
                     - (turtlesBought*(turt.getCost()));
    cost = funds - newFunds;
    funds = newFunds;

    cout << "\nCost of purchases: " << cost << endl;
    cout << "Funds now equals: " << funds << endl;

    z.addTigers(tigersBought);
    z.addPenguins(penguinsBought);
    z.addTurtles(turtlesBought);

    //Subtract feeding costs for animals bought on day 1
    int dailyCost = 0;
    dailyCost += (tigersBought*(tig.getFoodCost()));
    dailyCost += (penguinsBought*(peng.getFoodCost()));
    dailyCost += (turtlesBought*(turt.getFoodCost()));

    funds -= dailyCost;

    cout << "It cost $" <<dailyCost<< " to feed animals bought today\n";

    //Add payoffs for animals bought on day 1
    int dailyRevenue = 0;
    dailyRevenue += (tigersBought*(tig.getPayoff()));
    dailyRevenue += (penguinsBought*(peng.getPayoff()));
    dailyRevenue += (turtlesBought*(turt.getPayoff()));

    funds += dailyRevenue;

    cout << "The animals brought in $" <<dailyRevenue<< " in ticket fees\n";

    cout << "\n";    

    while(play==1) {
      
      day++; //new day
      
      z.tigerAge();   //tigers grow older one day
      z.penguinAge(); //penguins grow older one day
      z.turtleAge();  //turtles grow older one day

      tigersBought   = 0; //used to track tigers bought per day
      penguinsBought = 0; //used to track penguins bought per day
      turtlesBought  = 0; //used to track turtles bought per day
      
      cout << "\n\n";
      cout << "It is now day " << day << " would you like to buy animals?";
      cout << "\nYou have $" << funds << " to spend" << endl;

      cout << "\nHow many tigers would you like to buy?: ";
      cin  >> tigersBought;
      val = 1;
      //if bad input or too expensive a purchase
      while(val == 1) {
        if(cin.fail() || ((tigersBought*(tig.getCost())) > funds)) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Make sure you have enough money for your purchase.\n";
          cout << "You tried to spend $" << tigersBought*(tig.getCost()) 
               << endl;
          cout << "And you currently have $" << funds << endl;
          cout << "How many tigers would you like to buy?: ";
          cin  >> tigersBought;
        }
        //if user attempts to double the exhibit   
        else if(z.getTigeSize() <= tigersBought) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nWe cannot grow the tiger exhibit that quickly";
          cout << "\nIf you try to double, or more than double your";
          cout << "\ncurrent tiger count we cannot build ample living";
          cout << "\nspace in one day. Try a number less than double.";
          cout << "\nHow many tigers would you like to buy?: ";
          cin  >> tigersBought;
        }
        else if(!cin.fail()) {
          val = 0;
        }   
      }   
      cin.clear();
      cin.ignore(256, '\n');
     
      funds -= (tigersBought*(tig.getCost())); 
      cout << "\nYou now have $" << funds << " to spend" << endl;

      cout << "\nHow many penguins would you like to buy?: ";
      cin  >> penguinsBought;
      val = 1;
      //if bad input or too expensive a purchase
      while(val == 1) {
        if(cin.fail() || ((penguinsBought*(peng.getCost())) > funds)) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Make sure you have enough money for your purchase.\n";
          cout << "You tried to spend $" << penguinsBought*(peng.getCost()) 
               << endl;
          cout << "And you currently have $" << funds << endl;
          cout << "How many penguins would you like to buy?: ";
          cin  >> penguinsBought;
        }   
        //if user attempts to double the exhibit   
        else if(z.getPengSize() <= penguinsBought) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nWe cannot grow the penguin exhibit that quickly";
          cout << "\nIf you try to double, or more than double your";
          cout << "\ncurrent penguin count we cannot build ample living";
          cout << "\nspace in one day. Try a number less than double.";
          cout << "\nHow many penguins would you like to buy?: ";
          cin  >> penguinsBought;
        }
        else if(!cin.fail()) {
          val = 0;
        }   
      }   
      cin.clear();
      cin.ignore(256, '\n');
      
      funds -= (penguinsBought*(peng.getCost())); 
      cout << "\nYou now have $" << funds << " to spend" << endl;

      cout << "\nHow many turtles would you like to buy?: ";
      cin  >> turtlesBought;
      val = 1;
      //if bad input or too expensive a purchase
      while(val == 1) {
        if(cin.fail() || ((turtlesBought*(turt.getCost())) > funds)) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Make sure you have enough money for your purchase.\n";
          cout << "You tried to spend $" << turtlesBought*(turt.getCost()) 
               << endl;
          cout << "And you currently have $" << funds << endl;
          cout << "How many turtles would you like to buy?: ";
          cin  >> turtlesBought;
        }
        //if user attempts to double the exhibit   
        else if(z.getTurtSize() <= turtlesBought) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nWe cannot grow the turtle exhibit that quickly";
          cout << "\nIf you try to double, or more than double your";
          cout << "\ncurrent turtle count we cannot build ample living";
          cout << "\nspace in one day. Try a number less than double.";
          cout << "\nHow many turtles would you like to buy?: ";
          cin  >> turtlesBought;
        }
        else if(!cin.fail()) {
          val = 0;
        }   
      }   
      cin.clear();
      cin.ignore(256, '\n');

      funds -= (turtlesBought*(turt.getCost())); 
      cout << "\nYou now have $" << funds << " to spend" << endl;
      
      //if no space make space
      if((z.canAddTigers(tigersBought))==0) {
        //double the array size
        z.tigerResize();
        //add new tigers
        z.addTigers(tigersBought);
      }
      //if space add tigers
      else if((z.canAddTigers(tigersBought))==1) {
        //add new tigers
        z.addTigers(tigersBought);
      }

      //if no space make space
      if((z.canAddPenguins(penguinsBought))==0) {
        //double the array size
        z.penguinResize();
        //add new penguins
        z.addPenguins(penguinsBought);
      }
      //if space add penguins
      else if((z.canAddPenguins(penguinsBought))==1) {
        //add new penguins
        z.addPenguins(penguinsBought);
      }

      //if no space make space
      if((z.canAddTurtles(turtlesBought))==0) {
        //double the array size
        z.turtleResize();
        //add new turtles
        z.addTurtles(turtlesBought);
      }
      //if space add turtles
      else if((z.canAddTurtles(turtlesBought))==1) {
        //add new turtles
        z.addTurtles(turtlesBought);
      }
     
      //tigs, pngs, and trts hold the number of each animal
      int tigs = z.howManyTigers();
      int pngs = z.howManyPenguins();
      int trts = z.howManyTurtles();

      //calculate feeding costs
      int dailyCosts = 0;
      dailyCosts += tigs*(tig.getFoodCost());
      dailyCosts += pngs*(peng.getFoodCost());
      dailyCosts += trts*(turt.getFoodCost());

      //total purchases of new animals
      int dailyPurchases = 0;
      dailyPurchases += tigersBought*(tig.getCost());
      dailyPurchases += penguinsBought*(peng.getCost());
      dailyPurchases += tigersBought*(turt.getCost());

      //add payoff revenue
      int dailyRevenue = 0;
      dailyRevenue += tigs*(tig.getPayoff());
      dailyRevenue += pngs*(peng.getPayoff());
      dailyRevenue += trts*(turt.getPayoff());

      //Daily profit
      int dailyProfit = (dailyRevenue - dailyCosts - dailyPurchases);

      //calculate funds
      funds -= dailyCosts;
      funds += dailyRevenue;
      
      //for checking if animal arrays have any animals
      //these values are used in randomEvent to determine how the
      //random events occur
      int a = z.tigerCheck();
      int b = z.penguinCheck();
      int c = z.turtleCheck();

      //RANDOM EVENT AT END OF DAY
      //funds either returns a 1, 2, 3, or the amount of earnings due to
      //a boom in attendance due to tigers
      int randReturn = 0;

      randReturn = z.randomEvent(a,b,c);

      //1 = tiger was born, now it is added to the array
      if(randReturn == 1) {

        int tigerBaby = tig.getBabies();

        //if no space for tiger, make space
        if((z.canAddTigers(tigerBaby))==0) {
          //double array size
          z.tigerResize();
          //now add baby
          z.addTigers(tigerBaby);
        }
        else if((z.canAddTigers(tigerBaby))==1) {
          z.addTigers(tigerBaby);
        }
      }

      //2 = penguin was born, now it is added to the array
      else if(randReturn == 2) {

        int penguinBabies = peng.getBabies();

        //if no space for penguin, make space
        if((z.canAddPenguins(penguinBabies))==0) {
          //double array size
          z.penguinResize();
          //now add baby
          z.addPenguins(penguinBabies);
        }
        else if((z.canAddPenguins(penguinBabies))==1) {
          z.addPenguins(penguinBabies);
        }
      }

      //3 = turtle was born, now it is added to the array
      else if(randReturn == 3) {

        int turtleBabies = turt.getBabies();
        
        //if no space for turtle, make space
        if((z.canAddTurtles(turtleBabies))==0) {
          //double array size
          z.turtleResize();
          //now add baby
          z.addTurtles(turtleBabies);
        }
        else if((z.canAddTurtles(turtleBabies))==1) {
          z.addTurtles(turtleBabies);
        }
      }

      //if randReturn is greater than 3, it is returning earnings from
      //random event 2, a boom in zoo attendance due to tigers
      else if(randReturn > 3) {
        funds += randReturn;
      }

      //tigs, pngs, and trts hold the number of each animal after random
      tigs = z.howManyTigers();
      pngs = z.howManyPenguins();
      trts = z.howManyTurtles();
      
      cout << "\nHere is today's report: " << endl;
      cout << "The zoo has $" << funds << " in funds.\n";
      cout << "The zoo made " << dailyProfit << " dollars today.\n";
      cout << "The zoo has " << tigs << " tigers\n";
      cout << "The zoo has " << pngs << " penguins\n";
      cout << "The zoo has " << trts << " turtles\n";

      //Use for debugging purposes
      /*
      z.print1();
      z.print2();
      z.print3();
      cout << "\n";    
      */

      //If user runs out of funds, end game
      if(funds<=0) {
        cout << "\nThe zoo has ran out of money...\n";
        cout << "It will not reopen tomorrow, the game is over...\n";
        play++;
      }
      //If user has funds, ask if they'd like to keep playing
      else if(funds > 0) {
        char cont;
        cout << "\nWould you like to run the zoo another day?\n";
        cout << "Enter p to keep playing, or any other key to quit: ";
        cin  >> cont;
        if(cin.fail() || (cont != 'p' && cont != 'P')) {
          play++;
        }
        else if(cont == 'p' || cont == 'P') {
          play = 1;
        }
      }
    } //end of second while loop

  //delete arrays
  z.deleter();

  cout << "\nThank you for playing Zoo Tycoon! I hope you enjoyed it.\n";
  cout << "Your zoo ran for " << day << " day(s)!\n\n\n";
  play++;

  } //end of first while loop
  return 0;
}
