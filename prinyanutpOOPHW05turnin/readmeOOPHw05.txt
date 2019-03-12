*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2312
*  Due Date  :  Mar. 28, 2018
*******************************************************


                      Read Me


*******************************************************
*  Description of the program
*******************************************************

Homework 05:

A program that read information in from various files, perform 
exception handling when reading those files, and create a base 
class and derived classes with virtual functions to read the 
various files, perform some computations on the inputs, 
and print the file details.  

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program.
    - create objects for each animal
    - dog computations
        - read from file
        - subtract 10 from weight
        - print obj info
    - fish computations
        - read from file
        - print obj info
    - horse computations
        - read from file
        - add 1 to height
        - print obj info
    - lizard computations
        - read from file
        - print obj info
    - monkey computations
        - read from file
        - change isEndangered
        - print obj info

Name: animal.h
    Contains the definition for the class Animal and all of it's member functions.

Name: animal.cpp
   Defines and implements the Animal class. 
    readAnimal:
        - no implementations
    printAnimal:
        - no implementations

Name: dog.h
   Contains the definition for the class Dog and all of it's member functions.

Name: dog.cpp
   Defines and implements the Dog class.   
    readAnimal:
        - open file
        - loop to read in values and ignore first line
        - check for invalid values
        - set values
    printAnimal:
        - print out info for that objects
    weightSubtractTen:
        - subtract 10 from dog weight

Name: fish.h
   Contains the definition for the class Fish and all of it's member functions.

Name: fish.cpp
   Defines and implements the Fish class.   
    readAnimal:
        - open file
        - loop to read in values and ignore first line
        - check for invalid values
        - set values
    printAnimal:
        - print out info for that objects
    returnBool:
        - convert string to bool
    printTorF:
        - convert bool to string

Name: horse.h
   Contains the definition for the class Horse and all of it's member functions.

Name: horse.cpp
   Defines and implements the Horse class.   
    readAnimal:
        - open file
        - loop to read in values and ignore first line
        - check for invalid values
        - set values
    printAnimal:
        - print out info for that objects
    heightAddOne:
        - add 1 to height

Name: lizard.h
   Contains the definition for the class Lizard and all of it's member functions.

Name: lizard.cpp
   Defines and implements the Lizard class.   
    readAnimal:
        - open file
        - loop to read in values and ignore first line
        - check for invalid values
        - set values
    printAnimal:
        - print out info for that objects
    returnBool:
        - convert string to bool
    printTorF:
        - convert bool to string

Name: monkey.h
   Contains the definition for the class Monkey and all of it's member functions.

Name: Monkey.cpp
   Defines and implements the Monkey class.   
    readAnimal:
        - open file
        - loop to read in values and ignore first line
        - check for invalid values
        - set values
    printAnimal:
        - print out info for that objects
    monkeyEndangeredToggle:
        - toggle monkey isEndangered
    returnBool:
        - convert string to bool
    printTorF:
        - convert bool to string


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
