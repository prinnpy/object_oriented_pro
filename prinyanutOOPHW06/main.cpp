/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW06
 Due Date: Apr 26 2018
 */

//includes
#include "list.h"
#include "list.hpp"
#include "student.h"

//main
int main() {
    
    //create new point for the first list
    List<int> *List1 = new List<int>;
    
    //insert items into list1
    List1->insert_back(5);
    List1->insert_back(2);
    List1->insert_back(3);
    List1->insert_back(8);
    
    //print out list 1
    cout << "List 1:\n";
    List1->print(cout);
    cout << endl;
    
    //print out list 1 after pop_front and pop_back
    cout << "List 1 after (pop 5 in front) and (pop 8 in back)\n";
    List1->pop_front();
    List1->pop_back();
    List1->print(cout);
    cout << endl;
    
    //print out list 1 after push_front and push_back
    cout << "List 1 after (push 1 in front) and (push 4 in back)\n";
    List1->push_front(1);
    List1->push_back(4);
    List1->print(cout);
    cout << endl;
    
    //create new pointer for the second list with copy constructor
    List<int> *List2(List1);
    
    //print list 2
    cout << "List 2 after copy constructor:\n";
    List2->print(cout);
    cout << endl;
    
    //create new pointer for the third list
    List<int> *List3 = new List<int>;
    
    //print list 3
    cout << "List 3 after overloading = assignment:\n";
    List3 = List1;
    List3->print(cout);
    cout << endl;
    
    //create new point for the forth list to demonstrate exception handling
    List<int> *List4 = new List<int>;
    
    //error handling for list 4
    cout << "List 4: Trying to remove empty list\n";
    try {
        List4->pop_front();
        List4->pop_back();
        List4->print(cout);
    } catch (int e) {
        if (e == 0)
            cout << "List is empty nothing to remove!\n\n";
    }
    
    //set pointers to nullptr
    List2 = nullptr;
    List3 = nullptr;
    List4 = nullptr;
    
    //deleting pointers
    delete List2;
    delete List3;
    delete List4;
    
    //reading from binary file
    cout << "\n----------------------------------------------------\n";
    cout << "Reading from binary file, and adding to student list\n";
    cout << "----------------------------------------------------\n\n";
    
    //open up student
    fstream inFile("students.dat", ios::out | ios::in | ios::binary);
    
    //create list of students and student
    List<Student> studentList;
    Student s;
    
    //got this code from MyVector example
    inFile.seekg(ios::beg);
    while (inFile.read((char*) &s, sizeof(Student)))
    {
        studentList.insert_back(s);
    }
    
    //close file
    inFile.close();
    
    //printing out from file
    cout << "Print out student list from file...\n\n";
    studentList.print(cout);
    
    return 0;
    
}
