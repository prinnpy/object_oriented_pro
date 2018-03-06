/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW03
 Due Date: Feb 21 2018
 */

//includes
#include "functions.h"
#include "WaterVehicle.h"

//start game function
void start_game() {
    
    //welcome message
    cout << "\n----------------------\n";
    cout << "Welcome to Battleship!\n";
    cout << "----------------------\n";
    
    //ask if want to play
    cout << "\nStart Game (y or n)\n";
    char play;
    cin >> play;
    
    //if play
    if (play == 'y') {
        
        //array size
        const int GRIDSIZE = 10;
        
        //create 2 grids, one for user input and random torpedo
        int user_grid[GRIDSIZE][GRIDSIZE] = {{0},{0}};
        int torpedo_grid[GRIDSIZE][GRIDSIZE] = {{0},{0}};
        
        //print out empty grid
        cout << "\nYour grid\n";
        cout << "---------\n";
        print_grid(user_grid);
        
        //create carrier ship then ask for inputs
        WaterVehicle carrier;
        carrier.set_position("carrier", 5, user_grid);
        carrier.insert_ship(user_grid);
        
        //print update grid
        cout << "\nYour grid\n";
        cout << "---------\n";
        print_grid(user_grid);
        
        //create battleship ship then ask for inputs
        WaterVehicle battleship;
        battleship.set_position("battleship", 4, user_grid);
        battleship.insert_ship(user_grid);
        
        //print update grid
        cout << "\nYour grid\n";
        cout << "---------\n";
        print_grid(user_grid);
        
        //create crusier ship then ask for inputs
        WaterVehicle crusier;
        crusier.set_position("crusier", 3, user_grid);
        crusier.insert_ship(user_grid);
        
        //print update grid
        cout << "\nYour grid\n";
        cout << "---------\n";
        print_grid(user_grid);
        
        //create submarine ship then ask for inputs
        WaterVehicle submarine;
        submarine.set_position("submarine", 3, user_grid);
        submarine.insert_ship(user_grid);
        
        //print nupdate grid
        cout << "\nYour grid\n";
        cout << "---------\n";
        print_grid(user_grid);
        
        //create destroyer ship then ask for inputs
        WaterVehicle destroyer;
        destroyer.set_position("destroyer", 2, user_grid);
        destroyer.insert_ship(user_grid);
        
        //print update grid
        cout << "\nYour grid\n";
        cout << "---------\n";
        print_grid(user_grid);
        
        //generate random hits for torpedo grid
        generate_rand(torpedo_grid);
        cout << "Torpedo grid\n";
        cout << "------------\n";
        print_grid(torpedo_grid);
        
        //compare user grid and torpedo grid and print which ship has been hit
        carrier.compare_grid(user_grid,torpedo_grid);
        battleship.compare_grid(user_grid, torpedo_grid);
        crusier.compare_grid(user_grid, torpedo_grid);
        submarine.compare_grid(user_grid, torpedo_grid);
        destroyer.compare_grid(user_grid, torpedo_grid);
        
        //print all info for each ship
        cout << carrier;
        cout << battleship;
        cout << crusier;
        cout << submarine;
        cout << destroyer;
        
    } else {
        cout << "\nGoodbye\n\n";
    }
    
    
    
}

//function to generate random number and place it in random position in torpedo grid
void generate_rand(int grid[10][10]) {
    
    int rand_hits = 15;
    int count = 0, ranR, ranC;
    
    //loop for putting in random torpedo position in 2d array
    while (count < rand_hits) {
        //random
        ranR = rand() % 9 + 1;
        ranC = rand() % 9 + 1;
        
        //put it in random vector position
        if (grid[ranR][ranC] == 0) {
            grid[ranR][ranC] = 1;
            count++;
        }
    }//while
    
}

//print function for grids
void print_grid(int grid[10][10]) {
    
    //strings for row and column
    string columnHeader = "    A B C D E F G H I J ";
    string rowheader[] = {" 1 "," 2 "," 3 "," 4 "," 5 "," 6 "," 7 "," 8 "," 9 ","10 "};
    const int GRIDSIZE = 10;
    
    //printing grid
    cout << columnHeader << endl;
    cout << "    -------------------\n";
    for (int i = 0; i < GRIDSIZE; i++) {
        cout << rowheader[i] << " ";
        for (int j = 0; j < GRIDSIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    
}
