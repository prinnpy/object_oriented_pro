/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW06
 Due Date: Apr 26 2018
 */

#ifndef student_h
#define student_h

//includes
#include <iostream>
#include <string>
using namespace std;

//student struct
struct Student {
    char name[20];
    int id;
};

//overloading << for printing
ostream& operator << (ostream &out, Student s)
{
    out << "Name: " << s.name << endl;
    out << "Id: " <<  s.id << endl;
    return out;
}


#endif /* student_h */
