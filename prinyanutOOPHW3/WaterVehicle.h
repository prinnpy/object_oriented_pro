/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW03
 Due Date: Feb 21 2018
 */

#ifndef WaterVehicle_h
#define WaterVehicle_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//watervehicle class
class WaterVehicle {
//private vars
private:
    string name;
    int length;
    int start_position_x;
    int start_position_y;
    char orientation;
    bool sunk;
    
//public vars
public:
    //constructors
    WaterVehicle(): length(0), start_position_x(0), start_position_y(0), orientation(' '), sunk(false){};
    WaterVehicle(string name, int length, int start_position_x, int start_position_y, char orientation, bool sunk){
        this->name = name;
        this->length = length;
        this->start_position_x = start_position_x;
        this->start_position_y = start_position_y;
        this->orientation = orientation;
        this->sunk = sunk;
    };
    
    //set
    void set_name(string name){this->name = name;}
    void set_length(int length){this->length = length;}
    void set_start_position_x(int start_position_x){this->start_position_x = start_position_x;}
    void set_start_position_y(int start_position_y){this->start_position_y = start_position_y;}
    void set_orientation(char orientation){this->orientation = orientation;}
    void set_sunk(bool sunk){this->sunk = sunk;}
    
    //get
    string get_name(){return name;}
    int get_length(){return length;}
    int get_start_position_x(){return start_position_x;}
    int get_start_position_y(){return start_position_y;}
    char get_orientation(){return orientation;}
    bool get_sunk(){return sunk;}
    
    //functions
    void set_position(string ship_name, int length, int user_grid[10][10]);
    bool check_space();
    bool check_occ(int grid[10][10]);
    void insert_ship(int user_grid[10][10]);
    void compare_grid(int user_grid[10][10],int torpedo_grid[10][10]);
    
    //overloading
    friend ostream& operator << (ostream &os, WaterVehicle ship);
    
    
    
    
    
    
    
};


#endif /* WaterVehicle_h */
