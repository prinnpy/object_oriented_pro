/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

//includes
#include "horse.h"

//Override read function
void Horse::readAnimal() {
    
    //declare vars
    string dummyLine, stringName, stringColor, stringManeColor, tempAge, tempHeight;
    int intAge, intHeight;
    char charAge, charHeight;
    
    //exception handling
    try {
        //open file
        ifstream inFile("Horse.csv");
        
        //loop and ignore first line
        while (getline(inFile, dummyLine)){
            getline(inFile, stringName, ',');
            getline(inFile, stringColor, ',');
            getline(inFile, stringManeColor, ',');
            getline(inFile, tempAge, ',');
            getline(inFile, tempHeight, ',');
        }
        
        //convert to char
        charAge = tempAge[0];
        charHeight = tempHeight[0];
        
        //check if it's a number, if not print error
        if (!isdigit(charAge) || !isdigit(charHeight)) {
            throw 0;
        }
        
        //convert string to int
        intAge = stoi(tempAge);
        intHeight = stoi(tempHeight);
        
        //set values
        this->setName(stringName);
        this->setColor(stringColor);
        this->setManeColor(stringManeColor);
        this->setAge(intAge);
        this->setHeight(intHeight);
        
    } catch (int x){ //catch error
        cout << "Can't read file for Horse! Error: " << x << endl;
    }
    
}

//Overriding print functions
void Horse::printAnimal() {
    
    //print out all Horse obj
    cout << "Horse\n";
    cout << "-----\n";
    cout << "Name: " << this->getName() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "ManeColor: " << this->getManeColor() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Height: " << this->getHeight() << endl << endl;
}

//func that add 1 to height
void Horse::heightAddOne() {
    
    //add 1 to height
    int newHorseHeight = this->getHeight() + 1;
     //set new height
    this->setHeight(newHorseHeight);
}
