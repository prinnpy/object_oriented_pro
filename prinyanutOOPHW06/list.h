/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW06
 Due Date: Apr 26 2018
 */

#ifndef list_h
#define list_h

//includes
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

//Node struct
template <typename DATA>
struct Node {
    DATA data;
    Node<DATA> *nextPtr = nullptr;
};

//List class
template <typename DATA>
class List {
private:
    Node<DATA> *headPtr;
public:
    
    //constructors
    List(): headPtr(nullptr){}; //default constructor
    List(const List<DATA> &list); //copy constructor
    List<DATA>& operator = (List<DATA> &v); //overloading = operator
    
    //get headptr
    Node<DATA> *getHeadPtr(){return this->headPtr;}
    
    //functions
    void insert_back(DATA value);
    void push_front(DATA value);
    void push_back(DATA value);
    void pop_front() throw(int);
    void pop_back() throw(int);
    void print(ostream &out);
    void clear();
    
    //destructor
    ~List(){clear();};
    
};





#endif /* list_h */
