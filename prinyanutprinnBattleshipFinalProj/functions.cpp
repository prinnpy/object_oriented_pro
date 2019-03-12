/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: Final Project (Battleship)
 Due Date: April 4 2018
*/

//includes
#include "functions.h"

//start game function
void start_game() {
    
    cout << "\n                __/___\n";
    cout << "          _____/______|__\n";
    cout << "  _______/_____/_________|____\n";
    cout << " /             < < <          |\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "      WELCOME TO BATTLESHIP! \n\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    
    bool valid_start_game_input = false;
    char play = ' ';
    
    //ask if want to play
    while (!valid_start_game_input) {
        cout << "\nStart Game (y or n)\n";
        cin >> play;
        play = toupper(play);
        if (play == 'Y' || play == 'N') {
            valid_start_game_input = true;
        } else {
            cout << "Invalid input! Enter 'y' or 'n'";
        }
        
    }
    //create user and computer object
    User user_player;
    Computer computer_player;
    
    //read in file for user
    user_player.read_user_ship();
    
    //generate random ship position for computer
    computer_player.generate_cpu_ship();
    
    cout << "\nLet's Play!\n";
    cout << "-----------\n";
    cout << "C is for carrier\n";
    cout << "B is for battleship\n";
    cout << "K is for Crusier\n";
    cout << "S is for submarine\n";
    cout << "D is for destroyer\n";
    
    //print initial user grids
    cout << "\nUser Grid: (X is miss, O is hit)\n";
    cout << "================================\n\n";
    print_grid(user_player.user_grid);
    
    cout << "\nAttack Grid: (X is miss, O is hit)\n";
    cout << "==================================\n\n";
    print_grid(user_player.user_attack_grid);
    
    //while loop for play game
    while(play == 'Y') {
        
        bool valid_continue_play = false;
        
        //get user input func
        int input_col = get_user_input(0);
        int input_row = get_user_input(1);
        
        //check with the computer grid
        user_player.fire_torpedo(input_row, input_col, computer_player.computer_grid);
        
        //get computer input func
        int rand_col = get_random_cpu_input(0);
        int rand_row = get_random_cpu_input(1);
       
        //check with user grid
        computer_player.fire_torpedo(rand_row, rand_col, user_player.user_grid);
        
        //print update user grids
        cout << "\nYour Grid: (X is miss, O is hit)\n";
        cout << "===============================\n\n";
        print_grid(user_player.user_grid);
        
        cout << "\nAttack Grid: (X is miss, O is hit)\n";
        cout << "==================================\n\n";
        print_grid(user_player.user_attack_grid);
        
        //check for winner
        if (user_player.get_count() == 17) {
            cout << "\n----------------------------------------";
            cout << "\nYou've sunk all ships: You're a winner!.\n";
            cout << "----------------------------------------\n";
            break;
        } else if (computer_player.get_count() == 17) {
            cout << "\n-----------------------------------";
            cout << "\nComputer sunk all ships: You lose!.\n";
            cout << "-----------------------------------\n";
            break;
        }
        
        //ask if want to continue the game or not
        while (!valid_continue_play) {
            cout << "\nDo you want to continue the game? (y or n)\n";
            cin >> play;
            play = toupper(play);
            if (play == 'Y' || play == 'N') {
                valid_continue_play = true;
            } else {
                cout << "Invalid input! Enter 'y' or 'n'";
            }
        }
        
        
    }
    
    //option to restart game
    restart_game();
    
    //print out computers' grids
    cout << "\n-----------------------------------------------\n";
    cout << "Thank you for playing! Here's computers' grids.\n";
    cout << "-----------------------------------------------\n\n";
    cout << "Computer's ship grid: (X is miss, O is hit)\n";
    cout << "===========================================\n\n";
    print_grid(computer_player.computer_grid);
    cout << "\nComputer's attack grid: (X is miss, O is hit)\n";
    cout << "=============================================\n\n";
    print_grid(computer_player.computer_attack_grid);
    cout << "---------------------------\n";
    cout << "See you next time. Goodbye.\n";
    cout << "---------------------------\n\n";
}

//func to restart game
void restart_game() {
    
    bool valid_restart_input = false;
    char restart_game = ' ';
    
    while (!valid_restart_input) {
        //ask is they want to restart the game
        cout << "\nRestart game? (y or n)\n";
        cin >> restart_game;
        restart_game = toupper(restart_game);
        if (restart_game == 'Y' || restart_game == 'N') {
            valid_restart_input = true;
        } else {
            cout << "Invalid input! Enter 'y' or 'n'";
        }
    }

    if (restart_game == 'Y') {
        start_game();
    }
}

//func to print grid
void print_grid(char grid[10][10]) {
    
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

//get random rows and col for computer torpedo
int get_random_cpu_input(int value) {
    int final_value = 0;
    
    //vars
    int rand_col = 0, rand_row = 0;
    bool valid_col = false, valid_row = false;
    
    //generate random torpedo shots col for computer
    if (value == 0) {
        while (!valid_col) {
            //generate random col
            rand_col = rand() % 9 + 1;
            //check for bounds
            if (rand_col >= 0 && rand_col <= 9) {
                valid_col = true;
                final_value = rand_col;
            }
        }
    }
    
    //generate random torpedo shots row for computer
    if (value == 1) {
        while (!valid_row) {
            //generate random row
            rand_row = rand() % 9 + 1;
            //check for bounds
            if (rand_row >= 0 && rand_row <= 9) {
                valid_row = true;
                final_value = rand_row;
            }
        }
    }
    
    return final_value;
    
}

//ask user for torpedos inputs
int get_user_input(int value) {
    
    int final_value = 0;
    
    //vars
    int input_col = 0, input_row_int = 0;
    string input_row_string;
    bool valid_col = false, valid_row = false;
    
    //ask input torpedo shots col for user
    if (value == 0) {
        while (!valid_col) {
            //ask for input
            cout << "What column you want to shot a torpedo? (A to J)\n";
            char input_col_char;
            cin >> input_col_char;
            //convert to int
            input_col_char = toupper(input_col_char);
            input_col = input_col_char - 65;
            //check for bounds
            if (input_col >= 0 && input_col <= 9) {
                valid_col = true;
                final_value = input_col;
            } else {
                cout << "Invalid column input. Enter again!\n";
            }
        }
    //ask input torpedo shots row for user
    } else if (value == 1) {
        while (!valid_row) {
            //ask for input
            cout << "What row do you want to shot a torpedo? (1 to 10)\n";
            cin >> input_row_string;
            //convert to int
            input_row_int = stoi(input_row_string);
            input_row_int -= 1;
            //check for bounds
            if (input_row_int >= 0 && input_row_int <= 9) {
                valid_row = true;
                final_value = input_row_int;
            } else {
                cout << "Invalid row input. Enter again!\n";
            }
        }
    }
    
    return final_value;
    
}
