/*
 Name: Prinn Prinyanut
 Class: CSCI 2412
 Description: HW01
 Due Date: Feb 1 2018
 */

#include "guess.h"
#include <iostream>
#include <vector>
using namespace std;

//MARK: - Default constructor
Guess::Guess() {
    flag = false;
    number = 0;
}

//MARK: - Generate random numbers
std::vector<Guess> Guess::generateRan(int tempTotalInt, int tempRange) {
    //create a vector that hold randomnumber struct data types
    vector<Guess> tempVec;
    
    //srand
    srand(time(NULL));
    
    //loop to generate random numbers and push back to vector
    for (int i = 0; i < tempTotalInt; i++) {
        
        //temp values
        int tempNumber = (int)rand() % tempRange + 1;
        bool tempFlag = false;
        
        //setting numbers and flags
        Guess tempClass;
        tempClass.setNumber(tempNumber);
        tempClass.setFlag(tempFlag);
        
        //put everything back into vector
        tempVec.push_back(tempClass);
        
    }
    //return temp vector
    return tempVec;
}

//MARK: - Ask for user inputs
std::vector<int> Guess::userGuess(int tempTotalInt, int tempRange) {
    //vector for users inputs
    vector<int> tempVec;
    
    //print inputs
    cout << "\nEnter your guesses for the " << tempTotalInt << " integers in the range from 1 to " << tempRange << " that have been selected:\n\n";
    
    //loop for push back user inputs
    for (int i = 0; i < tempTotalInt; i++) {
        int tempInt;
        cout << "Integer " << i + 1 << endl;
        cin >> tempInt;
        tempVec.push_back(tempInt);
    }
    //return temp vector
    return tempVec;
}

//MARK: - Comparing numbers function
int Guess::compareNumbers(vector<Guess> tempRandomNumberVec,vector<int> tempUserGuess, int tempTotalInt) {
    int count = 0;
    //for loop that grab user guess
    for (int i = 0; i < tempTotalInt; i++){
        //for loop that grab random generated number and compare
        for (int k = 0; k < tempTotalInt; k++) {
            //compare user guess and random number
            if ((tempUserGuess[i] == tempRandomNumberVec[k].number) && (tempRandomNumberVec[k].flag == false)) {
                //set flag
                tempRandomNumberVec[k].flag = true;
                //add count
                count += 1;
                break;
            }
        }
    }
    //reset all values to false
    return count;
}

//MARK: - Function for printing out welcome screen
void Guess::welcomeScreen() {
    
    cout << "\n        ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄";
    cout << "\n       █░░░█░░░░░░░░░░▄▄░██░█";
    cout << "\n       █░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█";
    cout << "\n       █░░░▀░░░▄▄▄▄▄░░██░▀▀░█";
    cout << "\n        ▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀\n\n";
    
    cout << "------------------------------------\n";
    cout << "Welcome to our number guessing game!\n";
    cout << "------------------------------------\n\n";
    
    cout << "            LET'S PLAY!\n";
    
    
}

//MARK: - Validation inputs function
bool Guess::validInputs(int tempTotalInt, int tempRange) {
    if (tempTotalInt <= 0 || tempRange <= 0) {
        cout << "\nInvalid input. Please enter your numbers again\n";
        return false;
    } else {
        return true;
    }
}

//MARK: - Play game function
void Guess::playGame() {
    
    int totalInt = 0, range = 0, tries, maxTries = 3, count = 0;
    char playAgain = 'y';
    bool validInput;
    
    //while loop for asking if user wants to play game again
    while (playAgain == 'y') {
        
        validInput = false;
        //asks for user inputs
        while (!validInput) {
            cout << "\n------------------------------------";
            cout << "\nHow many integers do you want?\n";
            cin >> totalInt;
            cout << "What is your max number range?\n";
            cin >> range;
        
            validInput = validInputs(totalInt, range);
        }
        //generate random numbers
        vector<Guess> randomNumberVec = generateRan(totalInt, range);

        //start tries at 0
        tries = 0;
        
        cout << "\n*********************************\n";
        cout << "WARNING: You only have 3 guesses!\n";
        cout << "*********************************\n\n";

        //loop for asking to guess
        while (tries < maxTries) {
            
            cout << "---------\n";
            cout << "Guess: " << tries + 1 << endl;
            cout << "---------\n";
            //asks for inputs
            vector<int> userGuessVec = userGuess(totalInt, range);

            //compare numbers
            count = compareNumbers(randomNumberVec, userGuessVec, totalInt);

            //print out results
            cout << "\nyou guessed " << count << " numbers correct!\n\n";

            //print for when player guess all numbers correctly
            if (count == totalInt) {
                cout << "------------------\n";
                cout << "CONGRATS! You won.\n";
                cout << "------------------\n\n";
                tries = maxTries;
            }
            tries++;
        }//while

        //print if player didn't guess correctly in 3 tries
        if (tries == maxTries && count != totalInt) {
            cout << "----------------\n";
            cout << "Sorry, You lose.\n";
            cout << "----------------\n\n";
        }

        //loop asking if players wants to play again
        cout << "Play again? y or n" << endl;
        cin >> playAgain;
    }

    cout << "\nGoodbye.\n\n";
    
}

