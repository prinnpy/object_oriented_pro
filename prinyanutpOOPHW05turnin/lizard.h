/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

#ifndef lizard_h
#define lizard_h

//includes
#include "animal.h"

//Lizard class
class Lizard: public Animal {
   
private:
    string habitat;
    int weight;
    bool isProtected;
public:
    
    //default constructor
    Lizard(): habitat(""), weight(0), isProtected(false){};
    
    //set
    void setHabitat(string habitat){this->habitat = habitat;}
    void setWeight(int weight){this->weight = weight;}
    void setIsProtected(bool isProtected){this->isProtected = isProtected;}
    
    //get
    string getHabitat(){return this->habitat;}
    int getWeight(){return this->weight;}
    bool getIsProtected(){return this->isProtected;}
    
    //functions
    void readAnimal();
    void printAnimal();
    string printTorF(bool value); //return string T or F
    bool returnBool(string value);//return bool T or F
    
};

#endif /* lizard_h */
