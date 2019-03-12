/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

#ifndef dog_h
#define dog_h

//includes
#include "animal.h"

//Dog class
class Dog: public Animal {
    
private:
    string breed;
    int age;
    int weight;
public:
    //default constructor
    Dog(): breed(""), age(0), weight(0){};
    
    //set
    void setBreed(string breed){this->breed = breed;}
    void setAge(int age){this->age = age;}
    void setWeight(int weight){this->weight = weight;}
    
    //get
    string getBreed(){return this->breed;}
    int getAge(){return this->age;}
    int getWeight(){return this->weight;}
    
    //functions
    void readAnimal();
    void printAnimal();
    void weightSubtractTen();

};


#endif /* dog_h */
