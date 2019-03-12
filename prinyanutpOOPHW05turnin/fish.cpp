/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

//includes
#include "fish.h"

//Override read function
void Fish::readAnimal() {
    
    //declare vars
    string dummyLine, stringName, stringColor, stringHabitat, tempIsFreshWater, tempIsPredator;
    bool boolIsFreshWater, boolIsPredator;
    
    //exception handling
    try {
    
        //open file
        ifstream inFile("Fish.csv");
        
        //loop and ignore first line
        while(getline(inFile, dummyLine)) {
            getline(inFile, stringName, ',');
            getline(inFile, stringColor, ',');
            getline(inFile, tempIsFreshWater, ',');
            getline(inFile, stringHabitat, ',');
            getline(inFile, tempIsPredator, ',');
        }
        
        //check if values is "TRUE" or "FALSE", else throw error
        if (tempIsFreshWater == "TRUE" || tempIsFreshWater == "FALSE" || tempIsPredator == "TRUE" || tempIsPredator == "FALSE") {
            
            //convert string to bool
            boolIsFreshWater = returnBool(tempIsFreshWater);
            boolIsPredator = returnBool(tempIsPredator);
            
            //set values
            this->setName(stringName);
            this->setColor(stringColor);
            this->setHabitat(stringHabitat);
            this->setIsFreshWater(boolIsFreshWater);
            this->setIsPredator(boolIsPredator);
            
        } else {
            throw 0;
        }
        
    } catch (int x){ //print out error message
        cout << "Can't read file for Fish! Error: " << x << endl;
    }
    
}

//Overriding print functions
void Fish::printAnimal() {
    
    //set bool to string
    string printTorFIsFreshWater = printTorF(this->getIsFreshWater());
    string printTorFIsPredator = printTorF(this->getIsPredator());
    
    //print out fish obj
    cout << "Fish\n";
    cout << "----\n";
    cout << "Name: " << this->getName() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Habitat: " << this->getHabitat() << endl;
    cout << "Is FreshWater: " + printTorFIsFreshWater << endl;
    cout << "Is Predator: " + printTorFIsPredator << endl << endl;
}

//convert string to bool
bool Fish::returnBool(string value) {
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
string Fish::printTorF(bool value) {
    
    string TorF;
    
    //if for return string
    if (value == 0) {
        TorF = "False";
    } else {
        TorF = "True";
    }
    
    return TorF;
    
}
