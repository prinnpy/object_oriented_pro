/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW02
 Due Date: Feb 7 2018
 */
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "matrix.h"
using namespace std;


//MARK: - Pass inputs
Matrix Matrix::enterInputs() {
    //vars
    int row,column;
    Matrix tempClass;
    char validInput = 'n';
    
    //loop to check for valid inputs
    while (validInput == 'n') {
    //ask for grid row and column
        cout << "How many grid row?\n";
        cin >> row;
        cout << "How many grid column?\n";
        cin >> column;
        
        if (row > 0 && column > 0) {
        //initialize all elements in vector with 0
            vector<vector<int> > matrix(row, vector<int> (column,0));
            //put everything in tempClass
            tempClass.setRow(row);
            tempClass.setColumn(column);
            tempClass.setMatrix(matrix);
            break;
        } else {
            cout << "Invalid Input. Please enter again.\n";
        }
        
    }
    
    //return
    return tempClass;

}

//MARK: - Calculate 1/3 of the total cell
int Matrix::calculateOneThird(int tempRow,int tempColumn) {
    
    int totalCell, tempThird;
    
    //get total cell
    totalCell = tempRow * tempColumn;
    
    //make sure that you fill 1 at 1/3 of the total grid
    if (totalCell % 3 > 0) {
        tempThird = (totalCell / 3) + 1;
    } else {
        tempThird = totalCell / 3;
    }
    
    return tempThird;
}

//MARK: - Print function
void Matrix::printMatrix(int tempRow, int tempColumn, vector<vector<int>> temp2DVec) {
    
    //print out grid
    for (int i = 0; i < tempRow; i++){
        for (int k = 0; k < tempColumn; k++){
            cout << temp2DVec[i][k];
        }
        cout << endl;
    }
}

//MARK: - Randomize function
vector<vector<int> > Matrix::random(Matrix tempClass){
    
    //variables
    int ranR, ranC, oneThird, count = 0;
    vector<vector<int> > rand2DVec;
    
    //initialize temp2DVec with 0
    rand2DVec = tempClass.getMatrix();
    
    //calculate one third of total grid cell
    oneThird = calculateOneThird(tempClass.getRow(), tempClass.getColumn());
    
    while (count < oneThird) {
        //random
        ranR = rand() % tempClass.getRow();
        ranC = rand() % tempClass.getColumn();
        
        //put it in random vector position
        if (rand2DVec.at(ranR).at(ranC) == 0) {
            rand2DVec.at(ranR).at(ranC) = 1;
            count++;
        }
    }//while
    
    //print out grid
    printMatrix(tempClass.getRow(), tempClass.getColumn(), rand2DVec);
    
    return rand2DVec;
    
}

//MARK: - Compare function
void Matrix::compareGrid(vector<vector<int> > tempGrid1, vector<vector<int> > tempGrid2, int tempRow, int tempColumn) {
    
    //initialize third vec to be 0
    vector<vector<int> > grid3(tempRow, vector<int> (tempColumn,0));
    
    //loop to check if grid 1 is = to grid 2
    for (int i = 0; i < tempRow; i++){
        for (int k = 0; k < tempColumn; k++){
            //compare and set 1 for grid 3
            if (tempGrid1.at(i).at(k) == 1 && tempGrid2.at(i).at(k) == 1) {
                grid3.at(i).at(k) = 1;
            }//if
        }//for
        
    }//for
    
    //print out grid 3
    printMatrix(tempRow, tempColumn, grid3);
    
}

//MARK: - Function that runs program
void Matrix::run() {
    //srand
    srand(time(NULL));
    
    //create objects
    Matrix grid1 = enterInputs();
    Matrix grid2 = grid1;

    //call grid and print fuctions
    cout << "\nGrid: 1\n";
    //puting random generated grid into grid 1
    grid1.setMatrix(random(grid1));
    cout << "\nGrid: 2\n";
    //puting random generated grid into grid 1
    grid2.setMatrix(random(grid2));
    cout << "\nGrid: 3\n";
    //compare function
    compareGrid(grid1.getMatrix(), grid2.getMatrix(), grid1.getRow(), grid1.getColumn());
    cout << endl;
    
    
}
