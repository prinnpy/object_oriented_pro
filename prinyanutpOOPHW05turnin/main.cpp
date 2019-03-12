/*
 Name: Prinn Prinyanut
 Class: CSCI 2312
 Description: HW05
 Due Date: Mar 28 2018
*/

//includes
#include "dog.h"
#include "fish.h"
#include "horse.h"
#include "lizard.h"
#include "monkey.h"

//main
int main(){
    
    //obj for each animal classes
    Dog dog;
    Fish fish;
    Horse horse;
    Lizard lizard;
    Monkey monkey;
    
    //dog computations
    dog.readAnimal(); //read from dog file
    dog.weightSubtractTen(); //subtract 10 from weight
    dog.printAnimal(); //print dog info
    
    //fish computations
    fish.readAnimal(); //read from fish file
    fish.printAnimal(); //print fish info
    
    //horse computations
    horse.readAnimal(); //read from horse file
    horse.heightAddOne(); //add 1 to height
    horse.printAnimal(); //print horse info
    
    //lizard computations
    lizard.readAnimal(); //read from lizard file
    lizard.printAnimal(); //print lizard info
    
    //monkey computations
    monkey.readAnimal(); //read from monkey file
    monkey.monkeyEndangeredToggle(); //toggle isEndangered
    monkey.printAnimal(); //print monkey info
    
    return 0;
}
