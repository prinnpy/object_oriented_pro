/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

#ifndef monkey_h
#define monkey_h

//includes
#include "animal.h"

//Monkey class
class Monkey: public Animal {
    
private:
    string home;
    int age;
    bool isWild;
    bool isEndangered;
public:
    
    //default constructor
    Monkey(): home(""), age(0), isWild(false), isEndangered(false){};
    
    //set
    void setHome(string home){this->home = home;}
    void setAge(int age){this->age = age;}
    void setIsWild(bool isWild){this->isWild = isWild;}
    void setIsEndangered(bool isEndangered){this->isEndangered = isEndangered;}
    
    //get
    string getHome(){return this->home;}
    int getAge(){return this->age;}
    bool getIsWild(){return this->isWild;}
    bool getIsEndangered(){return this->isEndangered;}
    
    //functions
    void readAnimal();
    void printAnimal();
    void monkeyEndangeredToggle();
    string printTorF(bool value); //return string T or F
    bool returnBool(string value); //return bool T or F
    
};

#endif /* monkey_h */
