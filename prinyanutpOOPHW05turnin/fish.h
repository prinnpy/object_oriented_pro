/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

#ifndef fish_h
#define fish_h

//includes
#include "animal.h"

//Fish class
class Fish: public Animal {
    
private:
    string habitat;
    bool isFreshWater;
    bool isPredator;
public:
    
    //default constructor
    Fish(): habitat(""), isFreshWater(false), isPredator(false){};
    
    //set
    void setHabitat(string habitat){this->habitat = habitat;}
    void setIsFreshWater(bool isFreshWater){this->isFreshWater = isFreshWater;}
    void setIsPredator(bool isPredator){this->isPredator = isPredator;}
    
    //get
    string getHabitat(){return this->habitat;}
    bool getIsFreshWater(){return this->isFreshWater;}
    bool getIsPredator(){return this->isPredator;}
    
    //functions
    void readAnimal();
    void printAnimal();
    string printTorF(bool value); //return string T or F
    bool returnBool(string value);//return bool T or F
    
};

#endif /* fish_h */
