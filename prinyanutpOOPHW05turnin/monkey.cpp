/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

//includes
#include "monkey.h"

//Override read function
void Monkey::readAnimal() {
    
    //declare vars
    string dummyLine, stringName, stringColor, tempAge, tempIsWild, stringHome, tempIsEndangered;
    int intAge;
    bool boolIsWild, boolisEndangered;
    char charAge;
    
    //exception handling
    try {
        
        //open file
        ifstream inFile("Monkey.csv");
        
        //loop and ignore first line
        while (getline(inFile, dummyLine)){
            getline(inFile, stringName, ',');
            getline(inFile, stringColor, ',');
            getline(inFile, tempAge, ',');
            getline(inFile, tempIsWild, ',');
            getline(inFile, stringHome, ',');
            getline(inFile, tempIsEndangered, ',');
        }
        
        //convert to char
        charAge = tempAge[0];
        
        //check if it's a number, if not print error
        if (!isdigit(charAge)) {
            throw 0;
            //check if isWild, and isEndangered had the right value
        } else if (tempIsWild == "TRUE" || tempIsWild == "FALSE" || tempIsEndangered == "TRUE" || tempIsEndangered == "FALSE") {
            
            //convert to bool and int
            boolIsWild = returnBool(tempIsWild);
            boolisEndangered = returnBool(tempIsEndangered);
            intAge = stoi(tempAge);
            
            //set values
            this->setName(stringName);
            this->setColor(stringColor);
            this->setAge(intAge);
            this->setIsWild(boolIsWild);
            this->setHome(stringHome);
            this->setIsEndangered(boolisEndangered);
        }
        
    } catch (int x) { //catch error
        cout << "Can't read file for Monkey! Error: " << x << endl;
    }
}

//Overriding print functions
void Monkey::printAnimal() {
    
    //convert bool to string
    string printTorFIsWild = printTorF(this->getIsWild());
    string printTorFIsEndangered = printTorF(this->getIsEndangered());
    
    //print out Monkey obj
    cout << "Monkey\n";
    cout << "------\n";
    cout << "Name: " << this->getName() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Is Wild: " + printTorFIsWild << endl;
    cout << "Home: " << this->getHome() << endl;
    cout << "Is Endangered: " + printTorFIsEndangered << endl << endl;
}

//func that toggle monkey isEndangered
void Monkey::monkeyEndangeredToggle() {
    
    //convert from T to F and F to T
    bool newMoneyEndangered = !this->getIsEndangered();
    //set new value
    this->setIsEndangered(newMoneyEndangered);
}

//convert string to bool
bool Monkey::returnBool(string value) {
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
string Monkey::printTorF(bool value) {
    
    string TorF;
    //if for return string
    if (value == 0) {
        TorF = "False";
    } else {
        TorF = "True";
    }
    
    return TorF;
    
}
