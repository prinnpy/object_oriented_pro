/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: Final Project (Battleship)
 Due Date: April 4 2018
*/

#ifndef Player_h
#define Player_h

//includes
#include "WaterVehicle.h"
#include <iostream>
using namespace std;

//Player Class
class Player {
protected:
    WaterVehicle carrier;
    WaterVehicle battleship;
    WaterVehicle crusier;
    WaterVehicle submarine;
    WaterVehicle destroyer;
public:
    
    //setting ships
    void set_carrier(WaterVehicle carrier){this->carrier = carrier;}
    void set_battleship(WaterVehicle battleship){this->battleship = battleship;}
    void set_crusier(WaterVehicle crusier){this->crusier = crusier;}
    void set_submarine(WaterVehicle submarine){this->submarine = submarine;}
    void set_destroyer(WaterVehicle destroyer){this->destroyer = destroyer;}
    
    //get ships
    WaterVehicle get_carrier(){return this->carrier;}
    WaterVehicle get_battleship(){return this->battleship;}
    WaterVehicle get_crusier(){return this->crusier;}
    WaterVehicle get_submarine(){return this->submarine;}
    WaterVehicle get_destroyer(){return this->destroyer;}
    
    //functions
    void virtual fire_torpedo() {};
    
};


#endif /* Player_h */
