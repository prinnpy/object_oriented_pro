/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: Final Project (Battleship)
 Due Date: April 4 2018
*/

//includes
#include "User.h"
#include "Computer.h"

//read in file function
void User::read_user_ship() {
    
    try {
    
        //open up file
        ifstream inFile("battleship.csv");
        
        //create temp vars
        string temp_name;
        string temp_position;
        string next_temp_position;
        string temp_orientation;
        int count = 0;
        char char_col, char_row, char_ori;
        
    
        //while loop for reading in the csv file
        while (getline(inFile, temp_name, ',')) {
            
            //reading in values
            getline(inFile, temp_position, ',');
            getline(inFile, temp_orientation);
            
            //check for duplicate position
            if (temp_position == next_temp_position) {
                throw 0;
            }
            
            //set equal to next position
            next_temp_position = temp_position;
            
            //convert to char to check for valid input
            char_row = temp_position[0];
            char_row = toupper(char_row);
            char_col = temp_position[1];
            char_ori = toupper(temp_orientation[0]);
            
            //if file is not correct exit
            if (!isdigit(char_col) || char_row > 'J' || char_row < 'A') {
                throw 0;
            }
            
            if (char_ori == 'H' || char_ori == 'V') {
                //convert and calculate the actual values of row, col, and ori
                int row = temp_position[1] - 48;
                int col = temp_position[0] - 64;
                char orientation = temp_orientation[0];
            
                //setting up all the ships info
                if (count == 0) { //set user carrier
                    bool valid_occ = false, valid_space = false;
                    WaterVehicle user_carrier(temp_name, 5, col, row, orientation,'C', false);
                    //check if space is avaliable
                    valid_space = user_carrier.check_space();
                    valid_occ = user_carrier.check_occ(user_grid);
                    //if not try again, else insert ship on the grid
                    if (!valid_occ || !valid_space) {
                        count = 0;
                    } else {
                        set_carrier(user_carrier);
                        user_carrier.insert_ship(user_grid);
                        count++;
                    }
                } else if (count == 1) { //set user battleship
                    bool valid_occ = false, valid_space = false;
                    WaterVehicle user_battleship(temp_name, 4, col, row, orientation,'B', false);
                    //check if space is avaliable
                    valid_space = user_battleship.check_space();
                    valid_occ = user_battleship.check_occ(user_grid);
                    //if not try again, else insert ship on the grid
                    if (!valid_occ || !valid_space) {
                        count = 0;
                    } else {
                        set_battleship(user_battleship);
                        user_battleship.insert_ship(user_grid);
                        count++;
                    }
                } else if (count == 2) { //set user crusier
                    bool valid_occ = false, valid_space = false;
                    WaterVehicle user_crusier(temp_name, 3, col, row, orientation,'K', false);
                    //check if space is avaliable
                    valid_space = user_crusier.check_space();
                    valid_occ = user_crusier.check_occ(user_grid);
                    //if not try again, else insert ship on the grid
                    if (!valid_occ || !valid_space) {
                        count = 0;
                    } else {
                        set_crusier(user_crusier);
                        user_crusier.insert_ship(user_grid);
                        count++;
                    }
                } else if (count == 3) { //set user submarine
                    bool valid_occ = false, valid_space = false;
                    WaterVehicle user_submarine(temp_name, 3, col, row, orientation,'S', false);
                    //check if space is avaliable
                    valid_space = user_submarine.check_space();
                    valid_occ = user_submarine.check_occ(user_grid);
                    //if not try again, else insert ship on the grid
                    if (!valid_occ || !valid_space) {
                        count = 0;
                    } else {
                        set_submarine(user_submarine);
                        user_submarine.insert_ship(user_grid);
                        count++;
                    }
                } else if (count == 4) { //set user destroyer
                    bool valid_occ = false, valid_space = false;
                    WaterVehicle user_destroyer(temp_name, 2, col, row, orientation,'D', false);
                    //check if space is avaliable
                    valid_space = user_destroyer.check_space();
                    valid_occ = user_destroyer.check_occ(user_grid);
                    //if not try again, else insert ship on the grid
                    if (!valid_occ || !valid_space) {
                        count = 0;
                    } else {
                        set_destroyer(user_destroyer);
                        user_destroyer.insert_ship(user_grid);
                        count++;
                    }
                }
            } else {
                throw 0;
            }
        }//while
    } catch (int e) { //catch error and print out error message
        cout << "\n---------------------------------------------------------------------------\n";
        cout << "Cannot read the ship placement file. Please fix file and rerun the program!\n";
        cout << "---------------------------------------------------------------------------\n";
        cout << "\nFile line examples:\nship_name,C5,H\nship_name,H2,V\n";
        cout << "\n---------------------------------------------------------------------------\n\n";
        exit(0);
    }
}

//function for firing torpedo for user.
void User::fire_torpedo(int row, int col, char computer_grid[10][10]) {

    int count = 0;
    
    //check for duplicates
    if (computer_grid[row][col] == 'X' || computer_grid[row][col] == 'O') {
        
        cout << "\n=========================\n";
        cout << "Duplicate Input for user!\n";
        cout << "=========================\n";
        
    } else if (computer_grid[row][col] != '.') { //compare user input to the computer's grid
        user_attack_grid[row][col] = 'O'; //set attack grid
        computer_grid[row][col] = 'O'; //set computer grid
        count = get_count() + 1; //count for if all ship sink
        this->set_count(count); // set count
        // if hit all ships set to sunk
        if (this->get_count() == 17) {
            get_carrier().set_sunk(true);
            get_battleship().set_sunk(true);
            get_crusier().set_sunk(true);
            get_submarine().set_sunk(true);
            get_destroyer().set_sunk(true);
        }
        
    } else { //if miss place x on the grid
        user_attack_grid[row][col] = 'X';
        computer_grid[row][col] = 'X';
    }
    
}


