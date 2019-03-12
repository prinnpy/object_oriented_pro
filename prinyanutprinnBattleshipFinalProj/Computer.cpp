/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: Final Project (Battleship)
 Due Date: April 4 2018
*/

#include "Computer.h"
#include "User.h"

//function that generate random row, col, orientaion then put in ship infos
void Computer::generate_cpu_ship() {
    
    //count for placing info in ships
    int count = 0;
    int total_ship = 5;
    int rand_row, rand_col, temp_ori;
    char rand_ori;

    //loop for putting in ships for computer
    while (count < total_ship) {
        rand_row = rand() % 9 + 1;
        rand_col = rand() % 9 + 1;
        temp_ori = rand() % 2;
        
        //convert orientation to chars
        if (temp_ori == 0) {
            rand_ori = 'H';
        } else {
            rand_ori = 'V';
        }
        
        //putting in info for ships
        if (count == 0) { //set cpu carrier
            bool valid_occ = false, valid_space = false;
            WaterVehicle cpu_carrier("carrier", 5, rand_col, rand_row, rand_ori,'C', false);
            //check if space is avaliable
            valid_space = cpu_carrier.check_space();
            valid_occ = cpu_carrier.check_occ(computer_grid);
            //if not try again, else insert ship on the grid
            if (!valid_occ || !valid_space) {
                count = 0;
            } else {
                set_carrier(cpu_carrier);
                cpu_carrier.insert_ship(computer_grid);
                count++;
            }
        } else if (count == 1) { //set cpu battleship
            bool valid_occ = false, valid_space = false;
            WaterVehicle cpu_battleship("battleship", 4, rand_col, rand_row, rand_ori,'B', false);
            //check if space is avaliable
            valid_space = cpu_battleship.check_space();
            valid_occ = cpu_battleship.check_occ(computer_grid);
            //if not try again, else insert ship on the grid
            if (!valid_occ || !valid_space) {
                count = 1;
            } else {
                set_battleship(cpu_battleship);
                cpu_battleship.insert_ship(computer_grid);
                count++;
            }
        } else if (count == 2) { //set cpu crusier
            bool valid_occ = false, valid_space = false;
            WaterVehicle cpu_crusier("crusier", 3, rand_col, rand_row, rand_ori,'K', false);
            //check if space is avaliable
            valid_space = cpu_crusier.check_space();
            valid_occ = cpu_crusier.check_occ(computer_grid);
            //if not try again, else insert ship on the grid
            if (!valid_occ || !valid_space) {
                count = 2;
            } else {
                set_crusier(cpu_crusier);
                cpu_crusier.insert_ship(computer_grid);
                count++;
            }
        } else if (count == 3) { //set cpu submarine
            bool valid_occ = false, valid_space = false;
            WaterVehicle cpu_submarine("submarine", 3, rand_col, rand_row, rand_ori,'S', false);
            //check if space is avaliable
            valid_space = cpu_submarine.check_space();
            valid_occ = cpu_submarine.check_occ(computer_grid);
            //if not try again, else insert ship on the grid
            if (!valid_occ || !valid_space) {
                count = 3;
            } else {
                set_submarine(cpu_submarine);
                cpu_submarine.insert_ship(computer_grid);
                count++;
            }
        } else if (count == 4) { //set cpu destroyer
            bool valid_occ = false, valid_space = false;
            WaterVehicle cpu_destroyer("destroyer", 2, rand_col, rand_row,  rand_ori,'D', false);
            //check if space is avaliable
            valid_space = cpu_destroyer.check_space();
            valid_occ = cpu_destroyer.check_occ(computer_grid);
            //if not try again, else insert ship on the grid
            if (!valid_occ || !valid_space) {
                count = 4;
            } else {
                set_destroyer(cpu_destroyer);
                cpu_destroyer.insert_ship(computer_grid);
                count++;
            }
        }
        
    }//while
    
}//func


//function for firing torpefo for computer
void Computer::fire_torpedo(int row, int col, char user_grid[10][10]) {
    
    //convert to base 0
    int new_row = row - 1;
    int new_col = col - 1;
    int count = 0;
    
    //check for duplicates
    if (user_grid[new_row][new_col] == 'X' || user_grid[new_row][new_col] == 'O') {
        
        cout << "\n=============================\n";
        cout << "Duplicate Input for computer!\n";
        cout << "=============================\n";
        
    } else if (user_grid[new_row][new_col] != '.') { //compare computer input to the user's grid
        user_grid[new_row][new_col] = 'O'; //set user grid
        computer_attack_grid[new_row][new_col] = 'O'; //set attack grid
        count = get_count() + 1; // add count
        this->set_count(count); // set count
        if (this->get_count() == 17) { //check if all ship sunk
            get_carrier().set_sunk(true);
            get_battleship().set_sunk(true);
            get_crusier().set_sunk(true);
            get_submarine().set_sunk(true);
            get_destroyer().set_sunk(true);
        }
    } else { //if miss place x
        user_grid[new_row][new_col] = 'X';
        computer_attack_grid[new_row][new_col] = 'X';
    }
    
    
}

