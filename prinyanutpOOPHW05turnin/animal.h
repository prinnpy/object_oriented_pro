/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

#ifndef animal_h
#define animal_h

//includes
#include <iostream>
#include <fstream>
#include <string>
#include "stdlib.h"
using namespace std;

//Animal class
class Animal {
    
protected:
    string name;
    string color;
public:
    //default constructor
    Animal(): name(""), color(""){};

    //set
    void setName(string name){this->name = name;}
    void setColor(string color){this->color = color;}
    //get
    string getName(){return this->name;}
    string getColor(){return this->color;}
    
    //virtual functions
    virtual void readAnimal();
    virtual void printAnimal();
    
};


#endif /* animal_h */
