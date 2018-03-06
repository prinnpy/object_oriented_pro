*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2312
*  Due Date  :  Feb. 21, 2018
*******************************************************


                      Read Me


*******************************************************
*  Description of the program
*******************************************************

A program that allows input of the ship length, grid location, and orientation. 
Assume the grid where the submarine is to be placed is a 10 by 10 grid and is 
indexed as described in Assignment 1. Randomly generate 15 torpedo shots in 
the main of the program, output the shot grid locations to the screen, and then 
output whether the torpedo hit any ship and if it did, whether that ship was sunk. 

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program. This is the driver program that create generate a random time.
   Then it starts the game.

Name: WaterVehicle.h
   Contains the definition for the class WaterVehicle and all of it's member functions.

Name: WaterVehicle.cpp
   Defines and implements the WaterVehicle class. 
   set_position:
    - function that allows each object to enter x and y coordinates and also orientation of the ship.
   check_space:
    - function that checks if there are spaces available based on each ship's length.
   check_occ:
    - function that checks if there are any slot taken.
   insert_ship:
    - function that changes 0 to 1 and place ship on the grid.
   overloading class:
    - function that overload << operator and print out all info of each ship.
   compare_grid:
    - compare user grid and random torpedo grid and see if it sunk any ship.


Name: functions.h
   Contains function prototypes for all functions.


Name: functions.cpp
   Contains functions.
   start_game:
    - print welcome messages
    - create user grid and torpedo grid
    - create 5 ships
    - get inputs for each ship
    - compare each ship to the torpedo grid
    - print each ship info
   generate_rand:
    - function that generate 15 torpedo shots and place it randomly on the grid.
   print_grid:
    - function that prints grids.

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
