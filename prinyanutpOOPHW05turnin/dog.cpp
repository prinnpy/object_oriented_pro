/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

//includes
#include "dog.h"

//Override read function
void Dog::readAnimal() {
    
    //declare vars
    string dummyLine, stringName, stringColor, stringBreed, tempAge, tempWeight;
    int intAge, intWeight;
    char charAge, charWeight;
    
    //exception handling
    try {
        //open file
        ifstream inFile("Dog.csv");
        
        //loop and ignore first line
        while(getline(inFile, dummyLine)) {
            
            getline(inFile, stringName, ',');
            getline(inFile, stringBreed, ',');
            getline(inFile, tempAge, ',');
            getline(inFile, stringColor, ',');
            getline(inFile, tempWeight);
    
        }
    
        //convert to char
        charAge = tempAge[0];
        charWeight = tempWeight[0];
        
        //check if it's a number, if not print error
        if (!isdigit(charAge) || !isdigit(charWeight)) {
            throw 0;
        }
        
        //convert string to int
        intAge = stoi(tempAge);
        intWeight = stoi(tempWeight);

        //set values
        this->setName(stringName);
        this->setColor(stringColor);
        this->setBreed(stringBreed);
        this->setAge(intAge);
        this->setWeight(intWeight);
        
    } catch (int x) { //catch error
        cout << "Can't read file for Dog! Error: " << x << endl;
    }
    
}

//Overriding print functions
void Dog::printAnimal() {
    //print out Dog objs
    cout << "Dog\n";
    cout << "---\n";
    cout << "Name: " << this->getName() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Breed: " << this->getBreed() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Weight: " << this->getWeight() << endl << endl;
}

//func that subtract 10 functions
void Dog::weightSubtractTen() {
    
    //subtract 10 from dog weight
    int newDogWeight = this->getWeight() - 10;
    //set new weight
    this->setWeight(newDogWeight);
    
}

