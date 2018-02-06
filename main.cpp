/*
 Name: Prinn Prinyanut
 Class: CSCI 2412
 Description: HW01
 Due Date: Feb 1 2018
 */

//MARK: - includes
#include "guess.h"
#include <iostream>
using namespace std;

//MARK: - Main function
int main() {
    
    //create object
    Guess play;
    
    //call function play game
    play.welcomeScreen();
    play.playGame();
    
    return 0;
}
