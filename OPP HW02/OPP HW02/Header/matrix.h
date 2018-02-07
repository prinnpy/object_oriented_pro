/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW02
 Due Date: Feb 7 2018
 */

#ifndef functions1_h
#define functions1_h
#include <vector>
#include <iostream>
using namespace std;

//MARK: - Matrix class

class Matrix {
    
private:
    //members
    vector<vector<int> > matrix;
    int row;
    int column;
    
public:
    //default constructors
    Matrix():row(0),column(0){};
    
    //set
    void setRow(int _row){row = _row;}
    void setColumn(int _column){column = _column;}
    void setMatrix(vector<vector<int> > _matrix){matrix = _matrix;}
    
    //get
    int getRow(){return row;}
    int getColumn(){return column;}
    vector<vector<int> > getMatrix(){return matrix;}
    
    //functions
    void run();
    vector<vector<int> > random(Matrix _tempClass);
    void printMatrix(int tempRow, int tempColumn, vector<vector<int> > temp2DVec);
    void compareGrid(vector<vector<int> > tempGrid1, vector<vector<int> > tempGrid2, int _tempRow, int _tempColumn);
    int calculateOneThird(int tempRow, int tempColumn);
    Matrix enterInputs();
    
};



#endif /* functions1_h */
