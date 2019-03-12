/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

//includes
#include "lizard.h"

//Override read function
void Lizard::readAnimal() {
    
    //declare vars
    string dummyLine, stringName, stringColor, stringHabitat, tempIsProtected, tempWeight;
    int intWeight;
    bool boolIsProtected;
    char charWeight;
    
    //exception handling
    try {
        //open file
        ifstream inFile("Lizard.csv");
        
        //loop and ignore first line
        while (getline(inFile, dummyLine)) {
            
            getline(inFile, stringName, ',');
            getline(inFile, stringColor, ',');
            getline(inFile, stringHabitat, ',');
            getline(inFile, tempIsProtected, ',');
            getline(inFile, tempWeight, ',');
            
        }
        
        //convert to char
        charWeight = tempWeight[0];
        
        //check if it's a number, if not print error
        if (!isdigit(charWeight)) {
            throw 0;
            //check if isProtected had the right value
        } else if (tempIsProtected == "TRUE" || tempIsProtected == "FALSE") {
            
            //convert to bool and int
            boolIsProtected = returnBool(tempIsProtected);
            intWeight = stoi(tempWeight);
            
            //set values
            this->setName(stringName);
            this->setColor(stringColor);
            this->setHabitat(stringHabitat);
            this->setIsProtected(boolIsProtected);
            this->setWeight(intWeight);
        }
        
    } catch (int x) { //catch error
        cout << "Can't read file for Lizard! Error: " << x << endl;
    }
}

//Overriding print functions
void Lizard::printAnimal() {
    
    //convert bool to string
    string printTorFIsProtected = printTorF(this->getIsProtected());
    
    //print out Lizard objs
    cout << "Lizard\n";
    cout << "------\n";
    cout << "Name: " << this->getName() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Habitat: " << this->getHabitat() << endl;
    cout << "Is Protected: " + printTorFIsProtected << endl;
    cout << "Weight: " << this->getWeight() << endl << endl;
}

//convert string to bool
bool Lizard::returnBool(string value) {
    bool TorF;
    //if for return bool
    if (value == "TRUE") {
        TorF = true;
    } else {
        TorF = false;
    }
    
    return TorF;
}

//convert bool to string
string Lizard::printTorF(bool value) {
    
    string TorF;
    //if for return string
    if (value == 0) {
        TorF = "False";
    } else {
        TorF = "True";
    }
    
    return TorF;
    
}
