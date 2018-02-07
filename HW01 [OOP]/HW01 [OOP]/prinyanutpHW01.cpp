//MARK: Personal Info
/*
Name: Prinn Prinyanut
Class: CSCI 2312
Description: HW 01
*/

//MARK: includes
//iostream
//using namespace std;

//MARK: Print game menu
    //play
    //rules

//MARK: Rules

    //Print out all of the rules
        //using cout
    //then press 'y' to set up ships position

//MARK: Setting up ships

    //Print grid start at top right
        //first for loop for rows
            //second for loop for columns
                //print out first row all letters
                //print out first column numbers
                //print out the rest '.'

    //Loop for setting up all ships positions [Carrier(5), Battleship(4), Cruiser(3), Submarine(3), Destroyer(2)]
        //Ask player to enter the position of ship
            //where on the grid
            //vertical or horizontal
                //check if you can place ship in this location and orientation
                //if not ask to place ship again
                //else replace '.' on grid with each ship's initials
                //and update grid real time
        //loop through all 5 ships

//MARK: Play Battleship

    //Print 2 grids
        //top one is showing opponent's grid
            //this has to be blank
        //bottom one is showing player's grid
            //this is the finished setup grid

    //Player will be asked to enter a position to attack (loop)
        //player enters the input then compare postition to opponent's grid
            //if input is == '.' on the grid
                //replace '.' with '*' (meaning it's a missed)
                //then it's the opponent's turn
            //else
                //replace '.' with 'H' (meaning it's a hit)
                //keep playing and guess again

        //Have a constant of total units of all ships combined = 17 units
            //search if there are 17 'H' on your grid
                //print "You lost. Play again?"
                    //if yes go back to the setup ship
                    //if no "Goodbye."
            //else if there are 17 'H' on opponent's grid
                //print "You won. Play again?"
                   //if yes go back to the setup ship
                    //if no "Goodbye."
            //else
                //keep asking for the position

//MARK: Test Plan

        //Build a 2x2 2d array grid to test out the outline
        //grid design
            //     A B
            //   1 . .
            //   2 . .
        //Make sure everything prints out correctly
    //Build a input's position variable
        //try to set a specific character in a specific location on the grid by using "a[rowInput#][columnInput#] = character"
        //validate through print statements that everything prints out as expected


