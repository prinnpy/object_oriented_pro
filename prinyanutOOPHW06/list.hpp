/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW06
 Due Date: Apr 26 2018
 */

#include "list.h"

//copy constructor
template <typename DATA>
List<DATA>::List(const List<DATA> &list):headPtr(nullptr) {
    
    //got this code from stackoverflow Link: https://stackoverflow.com/questions/43462982/implementing-copy-constructor-in-a-single-linked-list-c
    //cout << "\ncopy constructor called:";
    Node<DATA> *node = list.headPtr;
    while (node != nullptr)
    {
        insert_back(node->data);
        node = node->nextPtr;
    }
    
}

//overloading = operator
template <typename DATA>
List<DATA> &List<DATA>::operator = (List<DATA> &list) {
    
    //got this code from stackoverflow Link: https://stackoverflow.com/questions/43462982/implementing-copy-constructor-in-a-single-linked-list-c
    //cout << "\nassignment = called";
    swap(headPtr, list.headPtr);
    return *this;
    
}

//insert item into list
template <typename DATA>
void List<DATA>::insert_back(DATA value){
    
    //get currptr and create new node and set value to new node
    Node<DATA> *currentPtr = headPtr;
    Node<DATA> *tempPtr = new Node<DATA>;
    tempPtr->data = value;
    
    //check if the list was empty, set headptr to point to new node
    if (currentPtr == nullptr) {
        headPtr = tempPtr;
        delete currentPtr;
    } else {//else get the last node in list
        while (currentPtr->nextPtr != nullptr) {
            currentPtr = currentPtr->nextPtr;
        }
        //point last node to new node then point new node to null
        currentPtr->nextPtr = tempPtr;
        tempPtr->nextPtr = nullptr;
        
    }
    
}


//push_front function
template <typename DATA>
void List<DATA>::push_front(DATA value){
    
    if (headPtr == nullptr) {
        cout << "List is empty nothing to add!\n";
    } else {
        //change the data of the first node
        headPtr->data = value;

    }
    

}

//push_back function
template <typename DATA>
void List<DATA>::push_back(DATA value){
    
    if (headPtr == nullptr) {
        cout << "List is empty nothing to add!\n";
    } else {
        //create a currentptr
        Node<DATA> *currentPtr = headPtr;
        //loop through to get the last node
        while (currentPtr->nextPtr != nullptr) {
            currentPtr = currentPtr->nextPtr;
        }
        //set last node to the new value
        currentPtr->data = value;
    }
}

//pop_front function
template <typename DATA>
void List<DATA>::pop_front() throw(int){
    
    Node<DATA> *tempPtr = headPtr;
    
    //check if list is empty
    if (tempPtr == nullptr) {
        throw 0;
    }
    
    //change data of first node to null
    headPtr->data = 0;
    
}

//pop_back function
template <typename DATA>
void List<DATA>::pop_back() throw(int){
    
    //create a currentptr
    Node<DATA> *currentPtr = headPtr;
    
    //check if list is empty
    if (currentPtr == nullptr) {
        throw 0;
    }
    //loop through to get the last node
    while (currentPtr->nextPtr != nullptr) {
        currentPtr = currentPtr->nextPtr;
    }
    //set last node to null
    currentPtr->data = 0;
    
    
}

//clear all data in list
template <typename DATA>
void List<DATA>::clear() {
    
    Node<DATA> *wantToRemovePtr = headPtr;
    Node<DATA> *temp = headPtr;
    
    //loop for deleting every item in the list
    while (wantToRemovePtr != nullptr) {
        temp = wantToRemovePtr;
        delete wantToRemovePtr;
        wantToRemovePtr = temp->nextPtr;
    }
    
    //set headptr to point to null
    headPtr = nullptr;
}


//print out list data
template <typename DATA>
void List<DATA>::print(ostream & out)
{
    //create temp
    Node<DATA> *temp = getHeadPtr();
    
    //loop that keep print out items in list
    while (temp != nullptr) {
        out << temp->data << endl;
        temp = temp->nextPtr;
    }
    
}
