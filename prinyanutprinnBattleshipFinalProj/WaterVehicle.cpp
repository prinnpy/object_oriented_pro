/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: Final Project (Battleship)
 Due Date: April 4 2018
*/

#include "WaterVehicle.h"

//function for check space
bool WaterVehicle::check_space() {
    
    bool valid = true;
    
    //check for h
    if (this->get_orientation() == 'H') {
        //if start x + length ship is > 10
        if (this->get_col() + this->get_length() > 10) {
            valid = false;
        }
    }
    
    //check for v
    if (this->get_orientation() == 'V') {
        //if start y + length ship is > 10
        if (this->get_row() + this->get_length() > 10) {
            valid = false;
        }
    }
    
    return valid;
    
}

//function for checking if it's avalible
bool WaterVehicle::check_occ(char grid[10][10]) {
    
    bool valid = true;
    
    //check for h
    if (this->get_orientation() == 'H') {
        //for loop
        for (int i = 0; i < this->get_length();i++) {
            //check if grid's specific location is occupy by chaning x
            int temp_row = this->get_row() - 1;
            int temp_col = this->get_col() - 1;
            if (grid[temp_row][temp_col + i] != '.') {
                valid = false;
            }
        }
    }
    
    //check for v
    if (this->get_orientation() == 'V') {
        //for loop
        for (int i = 0; i < this->get_length();i++) {
            //check if grid's specific location is occupy by changing y
            int temp_row = this->get_row() - 1;
            int temp_col = this->get_col() - 1;
            if (grid[temp_row + i][temp_col] != '.') {
                valid = false;
            }
        }
    }
    
    return valid;
    
}

//function to insert ship
void WaterVehicle::insert_ship(char grid[10][10]) {
    
    //insert for h
    if (this->get_orientation() == 'H') {
        for (int i = 0; i < this->get_length();i++) {
            //put in one by changing x
            int temp_row = this->get_row() - 1;
            int temp_col = this->get_col() - 1;
            grid[temp_row][temp_col + i] = this->ship_char;
        }
    }//if
    
    //insert for v
    if (this->get_orientation() == 'V') {
        for (int i = 0; i < this->get_length();i++) {
            //put in one by changing y
            int temp_row = this->get_row() - 1;
            int temp_col = this->get_col() - 1;
            grid[temp_row + i][temp_col] = this->ship_char;
        }
    }//if
    
}

//overloading ship
ostream& operator << (ostream& out, WaterVehicle ship) {
    //normal overloading cout
    out << endl;
    out << ship.get_name() << endl;
    out << "--------------\n";
    out << "Length: " << ship.get_length() << endl;
    out << "Column: " << ship.get_col() << endl;
    out << "Row: " << ship.get_row() << endl;
    out << "Orientation: " << ship.get_orientation() << endl;
    out << "Sunk: " << ship.get_sunk() << endl;
    out << "--------------\n";
    
    return out;
}

