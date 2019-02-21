/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"
#include "Cell.h"

int n=0; //this initial value will be changed when the program is invoked
Cell** myGridCells_ptr_array = (Cell**)nullptr;
/**
 * This is the empty constructor for the grid
 */
Grid::Grid() {
	// TODO Auto-generated constructor stub
	Grid(10); //calls general constructor with default value
}
/**
 * This is a constructor with parameters for the grid. Makes an array of pointers to
 * each row of the two dimensional array (with given dimensions).
 * @param nSquaresOnASide the number of squares on a side
 */
Grid::Grid(int nSquaresOnASide)
{
	n = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid

	myGridCells_ptr_array = new Cell* [n];  //first allocate array of row pointers

	for(int i=0 ; i < n ; i++)
	{
		myGridCells_ptr_array[i] = new Cell[n]; // allocate memory for columns in each row
	}
	//initializes the cells to empty
	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			myGridCells_ptr_array[row][col].setOccupant(empty, NULL);
		}
	}
}
/** This sets the occupant of a given cell.
 * @param r row of the given cell
 * @param c column of the given cell
 * @param g the occupation status of the given cell (empty, ant, doodlebug)
 *
 */
void Grid::setCellOccupant(int r, int c, occupationStatus g, Organism* org)
{
	myGridCells_ptr_array[r][c].setOccupant(g,org);
}
/**
 * This function gets the occupation status of a given cell
 * @param r the given row
 * @param c the given column
 * @return the occupationStatus of the given cell (empty, ant, doodlebug)
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOccupant();
}
/** This function gets the pointer to the organism of a given cell
 * @param r the given row
 * @param c the given column
 * @return the pointer to the organism at the given location
 */
Organism* Grid::getCellOrganism(int r, int c){
	return myGridCells_ptr_array[r][c].getOrganism();
}

/** This is the method chooses the cell for the prey
 * @param r the row of the organism in question
 * @param c the column of the organism in question
 * @return an integer corresponding to the random prey cell
 *         1 = cell below, 2 = cell above, 3 = cell left, 4 = cell right
 *         returns -1 if the cell does not have any prey
 */
int Grid::getPrey(int r, int c){
	int currRow = r; // row of the organism
	int currCol = c; // cell of the organism
	int preyCount = 0; // count the number of prey
	int possiblePrey[4];
	int randomCell = -1; // to store the decision for the cell
	// checks the cell below
	if(isPrey(currRow + 1, currCol)){
		possiblePrey[preyCount] = 1; // indicate below is prey
		preyCount++;
	}
	// checks the cell above
	if(isPrey(currRow - 1, currCol)){
		possiblePrey[preyCount] = 2; // indicate above is prey
		preyCount++;
	}
	// checks the cell to the left
	if(isPrey(currRow, currCol - 1)){
		possiblePrey[preyCount] = 3; // indicate left is prey
		preyCount++;
	}
	// checks the cell to the right
	if(isPrey(currRow, currCol + 1)){
		possiblePrey[preyCount] = 4; // indicate right is prey
		preyCount++;
	}
	// checks to see if there is any prey
	if(preyCount != 0){
		int randomChoice = rand()%preyCount; // generate a random number of the array
		randomCell = possiblePrey[randomChoice]; // gets the cell element
	}

	return randomCell;

}

/** This method determines if a given cell is prey
 * @param r the row of the given cell
 * @param c the column of the given cell
 * @return true if the given cell is an ant
 * 		   false if the given cell is not an ant or is off the edge of the board
 */
bool Grid::isPrey(int r, int c){
	int currRow = r; // the current row
	int currCol =c; // the current column
	bool result = false; // the result of the function
	// checking if the cell in question is off the board
	if(currRow < 0 || currRow >= n || currCol < 0 || currCol >= n){
		result = false;
	}
	// checking if the cell is an ant
	else if(getCellOccupant(currRow, currCol) == ant){
		result = true;
	}
	// if the cell is not off the edge and is not an ant
	else{
		result = false;
	}
	return result;
}

/**
 * This method determines a random empty cell to move to if there is one
 * @param r the current row
 * @param c the current column
 * @return an integer corresponding to the random empty cell
 *         1 = cell below, 2 = cell above, 3 = cell left, 4 = cell right
 *         returns -1 if the cell does not have any prey
 */
int Grid::getEmptyNeighbor(int r, int c){
	int currRow = r; // row of the organism
	int currCol = c; // cell of the organism
	int emptyCount = 0; // count the number of prey
	int possibleEmpty[4]; // this is to store the possible cells
	int randomCell = -1; // the cell to be chosen


	// checks the cell below
	if(isEmpty(currRow + 1, currCol)){
		possibleEmpty[emptyCount] = 1;
		emptyCount++;
	}
	// checks the cell above
	if(isEmpty(currRow - 1, currCol)){
		possibleEmpty[emptyCount] = 2;
		emptyCount++;
	}
	// checks the cell to the left
	if(isEmpty(currRow, currCol - 1)){
		possibleEmpty[emptyCount] = 3;
		emptyCount++;
	}
	// checks the cell to the right
	if(isEmpty(currRow, currCol + 1)){
		possibleEmpty[emptyCount] = 4;
		emptyCount++;
	}

	// checks to see if there is any prey
	if(emptyCount != 0){
		int randomChoice = rand()%emptyCount; // generate a random number of the array
		randomCell = possibleEmpty[randomChoice]; // gets the cell element
	}

	return randomCell;

}
/** This method determines if the given cell is empty
 * @param r the given row
 * @param c the given column
 * @return true if the cell does not have an organism in it
 *         otherwise returns false (including cell being off the edge)
 */
bool Grid::isEmpty(int r, int c){

	int currRow = r; // current row
	int currCol = c; // current col
	bool result = false; // this stores the result of whether the cell is empty

	// checking if the cell is out of the bounds
	if(currRow < 0 || currRow >= n || currCol < 0 || currCol >= n){
		result = false;
	}
	// checking if the cell is empty
	else if(getCellOccupant(currRow, currCol) == empty){
		result = true;
	}
	// if the cell contains an organism
	else{
		result = false;
	}

	return result;
}
/** This function prints the board based on the occupation status of the cell
 *
 */
void Grid::printBoard(void){

	// loops through the array
	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			// gets occupation status
			occupationStatus currCell =myGridCells_ptr_array[row][col].getOccupant();
			// checks if the cell is empty
			if(currCell == empty){
				std::cout<<" ";
			}
			// checks if the cell is an ant
			else if(currCell == ant){
				std::cout<<"o";
			}
			// checks if the cell is a doodlebug
			else if(currCell == doodlebug){
				std::cout<<"x";
			}
			// checks if the cell is the last on a line
			if(col == n-1){
				std::cout<<"\n";
			}
		}
	}
}

/**
 * This is a destructor for the grid. Free the memory for the columns in each row
 */
Grid::~Grid() {

	for(int r=0; r < n; r++)
	{
		for(int c=0; c < n; c++)
		{
			//cout << "Before freeing" << r << c << endl;
			myGridCells_ptr_array[r][c].~Cell(); // free memory for columns in each row
		}
	}
	//myGridCells_ptr_array = (Cell**)nullptr;
}

