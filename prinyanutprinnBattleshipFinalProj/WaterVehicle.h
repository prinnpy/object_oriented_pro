/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: Final Project (Battleship)
 Due Date: April 4 2018
*/

#ifndef WaterVehicle_h
#define WaterVehicle_h

//includes
#include <iostream>
using namespace std;

//WaterVehicle class
class WaterVehicle {
private:
    string name;
    int length;
    int col;
    int row;
    char orientation;
    char ship_char;
    bool sunk;
public:
    //constructors
    WaterVehicle(): length(0), col(0), row(0), orientation(' '), ship_char('P'),sunk(false){};
    WaterVehicle(string name, int length, int col, int row, char orientation, char ship_char, bool sunk){
        this->name = name;
        this->length = length;
        this->col = col;
        this->row = row;
        this->orientation = orientation;
        this->ship_char = ship_char;
        this->sunk = sunk;
    };
    
    //set
    void set_name(string name){this->name = name;}
    void set_length(int length){this->length = length;}
    void set_col(int col){this->col = col;}
    void set_row(int row){this->row = row;}
    void set_orientation(char orientation){this->orientation = orientation;}
    void set_ship_char(char ship_char){this->ship_char = ship_char;}
    void set_sunk(bool sunk){this->sunk = sunk;}
    
    //get
    string get_name(){return name;}
    int get_length(){return length;}
    int get_col(){return col;}
    int get_row(){return row;}
    char get_orientation(){return orientation;}
    char get_ship_char(){return ship_char;}
    bool get_sunk(){return sunk;}
    
    //functions
    bool check_space();
    bool check_occ(char grid[10][10]);
    void insert_ship(char user_grid[10][10]);
    
    //overloading
    friend ostream& operator << (ostream &os, WaterVehicle ship);
    
    
};

#endif /* WaterVehicle_h */
