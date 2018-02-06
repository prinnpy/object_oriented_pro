# DataHW01

*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2421
*  Due Date  :  Feb. 1, 2018
*******************************************************


* Read Me


*******************************************************
*  Description of the program
*******************************************************

A simple number guessing game that asks user for numbers of random integers
and max range. Then generate random numbers based on user inputs. Asks users
to guess numbers. Compare guess numbers to random generate numbers.
If all guess numbers match random generate numbers, user wins. User only have 3 tries.

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program. This is the driver program that create a Guess class object
   calls play. Then it calls one of its method called welcomeScreen that will print
   welcome messages. Then it calls playGame function, which runs the entire program.

Name: guess.h
   Contains the definition for the class guess.

Name: guess.cpp
   Defines and implements the guess class for implementing a guessing logic.
   This class provides functions for generating random numbers, push back user
   guesses into vector, comparing user guesses to generated numbers, welcome screen
   print, inputs validation, and play game function which is a main function that controls everything.


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
