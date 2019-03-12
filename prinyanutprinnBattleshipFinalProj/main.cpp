/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: Final Project (Battleship)
 Due Date: April 4 2018
*/

//includes
#include "functions.h"

//main function
int main() {
    
    //user for random number based on time
    srand( static_cast<unsigned int>(time(NULL)));
    
    //call start game function
    start_game();
    
    return 0;
    
}
