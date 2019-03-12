/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: Final Project (Battleship)
 Due Date: April 4 2018
*/

//includes
#ifndef functions_h
#define functions_h
#include <iostream>
#include "Player.h"
#include "User.h"
#include "Computer.h"
#include "WaterVehicle.h"
#include <ctime>
#include "stdlib.h"
using namespace std;

//functions prototypes
void start_game();
void print_grid(char grid[10][10]);
int get_user_input(int value);
int get_random_cpu_input(int value);
void restart_game();


#endif /* functions_h */
