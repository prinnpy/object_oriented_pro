/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: Final Project (Battleship)
 Due Date: April 4 2018
*/

#ifndef User_h
#define User_h

//includes
#include "Player.h"
#include "WaterVehicle.h"
#include <fstream>
#include <string>
#include "stdio.h"

//Player class
class User: Player {
private:
    int row;
    int col;
    int count = 0;
public:
    //user grids
    char user_grid[10][10] = {
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'}
    };
    char user_attack_grid[10][10] = {
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'}
    };
    
    //set and get for counts
    void set_count(int count){this->count = count;}
    int get_count(){return this->count;}
    
    //functions
    void read_user_ship();
    void fire_torpedo(int row, int col, char computer_grid[10][10]);
    
};

#endif /* User_h */
