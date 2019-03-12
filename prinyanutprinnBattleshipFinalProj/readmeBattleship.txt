*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2312
*  Due Date  :  Apr 4, 2018
*******************************************************


                      Read Me


*******************************************************
*  Description of the program
*******************************************************

Design and implement algorithms for Battleship strategy game.
This is a single player mode. The user will be plaing against 
cpu. 

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program. This is the driver program that call start_game function
   to start the game.

Name: Player.h
   Contains the definition for the class Player.
    - this class has all of the five ships
    - get/set functions
    - fire_torpedo virtual function

Name: User.h
   Contains the definition for the class User that inherent from Player class.
    - contain user's grid and user's attack grid
    - contain count for keeping the score
    - read_user_ship function
    - override fire_torpedo function

Name: User.cpp
   Function 1: read_user_ship
    - function that read in user's ship from a csv file
        - open file
        - read in from file
        - check if file contains valid data
        - while in that loop
            - set Carrier info
                - grab data from file
                - check if space is occupy on the user's grid
                - insert ship on to the user's grid
            - set Battleship info
                - grab data from file
                - check if space is occupy on the user's grid
                - insert ship on to the user's grid
            - set Crusier info
                - grab data from file
                - check if space is occupy on the user's grid
                - insert ship on to the user's grid
            - set Submarine info
                - grab data from file
                - check if space is occupy on the user's grid
                - insert ship on to the user's grid
            - set Destroyer info
                - grab data from file
                - check if space is occupy on the user's grid
                - insert ship on to the user's grid
        - if can't read file, print error message

    Function 2: fire_torpedo
        - function that compare user's attack grid to cpu main grid
            - check if the torpedo shot is a deplicate
            - if not, set that spot to 'O'
            - else, set it to 'X'

Name: Computer.h
   Contains the definition for the class Computer that inherent from Player class.
    - contain cpu's grid and cpu's attack grid
    - contain count for keeping the score
    - generate_cpu_ship function
    - override fire_torpedo function

Name: Computer.cpp
   Function 1: generate_cpu_ship
    - function that generate random cpu ships placement
        - generate random row, column, and orientation
        - while in that loop
            - set Carrier info
                - grab data from file
                - check if space is occupy on the cpu's grid
                - insert ship on to the cpu's grid
            - set Battleship info
                - grab data from file
                - check if space is occupy on the cpu's grid
                - insert ship on to the cpu's grid
            - set Crusier info
                - grab data from file
                - check if space is occupy on the cpu's grid
                - insert ship on to the cpu's grid
            - set Submarine info
                - grab data from file
                - check if space is occupy on the cpu's grid
                - insert ship on to the cpu's grid
            - set Destroyer info
                - grab data from file
                - check if space is occupy on the cpu's grid
                - insert ship on to the cpu's grid

   Function 2: fire_torpedo
        - function that compare cpu's attack grid to user's main grid
            - check if the torpedo shot is a deplicate
            - if not, set that spot to 'O'
            - else, set it to 'X'

Name: WaterVehicle.h
   Contains the definition for the class WaterVehicle and all of it's member functions.
    - constructors
    - set/get
    - member functions
        - check_space
        - check_occ
        - insert_ship

Name: WaterVehicle.cpp
   Defines and implements the WaterVehicle class.
   Function 1: check_space
    - function that checks if there are spaces available based on each ship's length.
   Function 2: check_occ
    - function that checks if any slot was already taken.
   Function 3: insert_ship
    - function that insert ship's char on to the grid
   overloading class:
    - function that overload << operator and print out all info of each ship.

Name: functions.h
   Contains all of the functions prototypes.
    - start_game func
    - print_grid func
    - get_user_input
    - get_random_cpu_input 
    - restart_game

Name: functions.cpp
   All of the function implementations
   Function 1: start_game
    - main functiont that runs the entire game
        - ask if user wants to play
        - read in user's ship from file
        - generate cpu ships
        - print user's grid and user's attack grid
        - while play loop
            - call function to get user row and col inputs
            - fire torpedo shots to computer's grid
            - call function to generate computer's row and col
            - fore torpedo shots to user's grid
            - print out the update user's grid and user's attack grid
            - check for winner
            - ask if user want to continue playing the game
        - ask if user wants to restart the game
        - print out computer's grid and computer's attack grid and goodbye message
   Function 2: restart_game
    - function that allows user to restart the whole game
        - ask for user input
        - restart game
   Function 3: print_grid
    - function that print grids.
   Function 4: get_random_cpu_input
    - function that generate random cpu row and col
        - condition for getting random row
        - condition for getting random col
   Function 5: get_user_input
    - function that asks user input for row and col
        - condition for getting random row
        - condition for getting random col

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
