/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

#ifndef horse_h
#define horse_h

//includes
#include "animal.h"

//Horse class
class Horse: public Animal {
 
private:
    string maneColor;
    int age;
    int height;
public:
    
    //default constructor
    Horse(): maneColor(""), age(0), height(0){};
    
    //set
    void setManeColor(string maneColor){this->maneColor = maneColor;}
    void setAge(int age){this->age = age;}
    void setHeight(int height){this->height = height;}
    
    //get
    string getManeColor(){return this->maneColor;}
    int getAge(){return this->age;}
    int getHeight(){return this->height;}
    
    //functions
    void readAnimal();
    void printAnimal();
    void heightAddOne();
    
};

#endif /* horse_h */
