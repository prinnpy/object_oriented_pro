*******************************************************
*  Name      :  Prinn Prinyanut
*  Student ID:  103379393
*  Class     :  CSCI 2312
*  Due Date  :  Apr 26, 2018
*******************************************************


                      Read Me


*******************************************************
*  Description of the program
*******************************************************

Homework 06:

Program that use pointers with dynamic memory, templates, 
binary files and exception handling to build a multi-purpose, 
generic, Single Linked List. Need to include Copy Constructor, 
overloaded Assignment Operator, and a Destructor. This will be 
similar in functionality to the C++ Standard Template Library (STL) 
forward_list, you will create your own using pointers (instead of 
forward_list, list or vector).

*******************************************************
*  Source files
*******************************************************

Name: main.cpp
   Main program.
    - Create list 1
        - insert new node to list 1
        - print list 1
        - pop_front
        - pop_back
        - add 1 to front
        - add 4 to back
        - print out updated list 1
    - Create list 2
        - use copy Constructor
        - print list 2
    - Create list 3
        - use overloading = Operator
        - print list 3
    - Create list 4
        - test empty list with pop_front and pop_back
        - print out error
    - Delete
        - list 2
        - list 3
        - list 4
    
    - Read in from binary file
        - open file
        - create new list of type student
        - read students into that list
        - print out all students in list

Name: student.h
    Contains the definition for the struct Student and an overloading << function
    to print out each Student object.

Name: list.h
    Contains the definition for the struct Node, and List class.

Name: list.hpp
    Defines and implements the List class. 
    function 1: copy Constructor
        - got this from stackoverflow
    function 2: overloading = Operator
        - got this from stackoverflow
    function 3: insert_back
        - function for inserting new node to the list
    function 4: push_front
        - function that modify data of the first node to new value
    function 5: push_back
        - function that modify data of the last node to new value
    function 6: pop_front
        - function that modify data of the first node to NULL
    function 7: pop_back
        - function that modify data of the last node to NULL
    function 8: clear
        - function that delete all node in list
    function 9: print
        - function that print nodes in list


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on Xcode g++.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.
