/*
 Name: Prinn Prinyanut
 Class: CSCI 2412
 Description: HW01
 Due Date: Feb 1 2018
 */

#ifndef guess_hpp
#define guess_hpp

//includes
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//MARK: - Guess class
class Guess {
    
private:
    bool flag;
    int number;public:
    //default constructors
    Guess();
    
    //set
    void setFlag(bool _flag){flag = _flag;}
    void setNumber(int _number){number = _number;}
    
    //get
    bool getFlag(){return flag;}
    int getNumber(){return number;}
    
    //functions
    void playGame();
    void welcomeScreen();
    bool validInputs(int totalInt, int range);
    std::vector<Guess> generateRan(int totalInt, int range);
    std::vector<int> userGuess(int totalInt, int range);
    int compareNumbers(vector<Guess> RandomNumberVec,vector<int> UserGuess, int totalInt);
    
};

#endif /* guess_hpp */

