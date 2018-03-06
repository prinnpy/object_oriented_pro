/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW03
 Due Date: Feb 21 2018
 */

#include "WaterVehicle.h"

//set position function for each ship
void WaterVehicle::set_position(string ship_name, int length, int grid[10][10]) {
    
    char x, ori;
    int y;
    bool valid_x = false, valid_y = false, valid_ori = false, valid_space = false, valid_occ = false;
    
    //set ship info
    this->set_name(ship_name);
    this->set_length(length);
    
    //print ship name
    cout << "Setting up: " << ship_name << endl;
    
    //ask for x input also validate input
    while (!valid_x) {
        cout << "what is your x position? (A to J)\n";
        cin >> x;
        x -= 65;
        
        //check for bounds
        if (x >= 0 && x <= 9) {
            this->set_start_position_x(x);
            valid_x = true;
        } else {
            cout << "Invalid input. Enter again.\n";
        }
            
    }//while
    
    //ask for y input also validate input
    while (!valid_y) {
        cout << "what is your y position? (1 to 10)\n";
        cin >> y;
        y -= 1;
            
        //check for bounds
        if (y >= 0 && y <= 9) {
            this->set_start_position_y(y);
            valid_y = true;
        } else {
            cout << "Invalid input. Enter again.\n";
        }
            
    }//while
    
    //ask for orientation input also validate input
    while (!valid_ori) {
        cout << "what is your orientation? (h or v)\n";
        cin >> ori;
            
        //check for bounds
        if (ori == 'h' || ori == 'v') {
            this->set_orientation(ori);
            valid_ori = true;
        } else {
            cout << "Invalid input. Enter again.\n";
        }
            
    }
    
    //check for space and if it was occupy
    valid_space = check_space();
    valid_occ = check_occ(grid);
    
    //if space not avaliable run the whole thing again
    if (!valid_occ || !valid_space) {
        this->set_position(name, length, grid);
    }
    
}//func

//function for check space
bool WaterVehicle::check_space() {
    
    bool valid = true;
    
    //check for h
    if (this->get_orientation() == 'h') {
        //if start x + length ship is > 10
        if (this->get_start_position_x() + this->get_length() > 10) {
            cout << "No horizontal space avaliable\n";
            valid = false;
        }
    }
    
    //check for v
    if (this->get_orientation() == 'v') {
        //if start y + length ship is > 10
        if (this->get_start_position_y() + this->get_length() > 10) {
            cout << "No vertical space avaliable\n";
            valid = false;
        }
    }
    
    return valid;
    
}

//function for checking if it's avalible
bool WaterVehicle::check_occ(int grid[10][10]) {
    
    bool valid = true;
    
    //check for h
    if (this->get_orientation() == 'h') {
        //for loop
        for (int i = 0; i < this->get_length();i++) {
            //check if grid's specific location is occupy by chaning x
            if (grid[this->get_start_position_y()][this->get_start_position_x() + i] == 1) {
                cout << "Space unavaliable\n";
                valid = false;
            }
        }
    }
    
    //check for v
    if (this->get_orientation() == 'v') {
        //for loop
        for (int i = 0; i < this->get_length();i++) {
            //check if grid's specific location is occupy by changing y
            if (grid[this->get_start_position_y() + i][this->get_start_position_x()] == 1) {
                cout << "Space unavaliable\n";
                valid = false;
            }
        }
    }
    
    return valid;
    
}

//function to insert ship
void WaterVehicle::insert_ship(int grid[10][10]) {
    
    //insert for h
    if (this->get_orientation() == 'h') {
        for (int i = 0; i < this->get_length();i++) {
            //put in one by changing x
            grid[this->get_start_position_y()][this->get_start_position_x() + i] = 1;
        }
    }//if
    
    //insert for v
    if (this->get_orientation() == 'v') {
        for (int i = 0; i < this->get_length();i++) {
            //put in one by changing y
            grid[this->get_start_position_y() + i][this->get_start_position_x()] = 1;
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
    out << "Position x: " << ship.get_start_position_x() << endl;
    out << "Position y: " << ship.get_start_position_y() << endl;
    out << "Orientation: " << ship.get_orientation() << endl;
    out << "Sunk: " << ship.get_sunk() << endl;
    out << "--------------\n";
    
    return out;
}


//compare grid functions
void WaterVehicle::compare_grid(int user_grid[10][10], int torpedo_grid[10][10]) {
    
    //if orientation is h
    if (this->get_orientation() == 'h') {
        for (int i = 0; i < this->get_length();i++) {
            //if postion in user grid = 1 and position torpedo grid = 1 ship sunk
            if (user_grid[this->get_start_position_y()][this->get_start_position_x() + i] == 1 && torpedo_grid[this->get_start_position_y()][this->get_start_position_x() + i] == 1) {
                this->set_sunk(true);
                cout << "Your " << this->get_name() << " has sunk!" << endl;
                break;
            }//if
        }//for
    }//if
    
    //if orientation is v
    if (this->get_orientation() == 'v') {
        for (int i = 0; i < this->get_length();i++) {
            //if postion in user grid = 1 and position torpedo grid = 1 ship sunk
            if (user_grid[this->get_start_position_y() + i][this->get_start_position_x()] == 1 && torpedo_grid[this->get_start_position_y() + i][this->get_start_position_x()] == 1) {
                this->set_sunk(true);
                cout << "Your " << this->get_name() << " has sunk!" << endl;
                break;
            }//if
        }//for
    }//if
    
}
