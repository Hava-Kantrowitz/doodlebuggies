/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Hava Kantrowitz
 */

#include "Ant.h"
#include <iostream>

/**
 * Constructs instance of Ant class
 */
Ant::Ant()
//:Organism(true)
{

}

/**
 * Initializes the ants location on the grid
 * @param r : the row the ant's cell is located in
 * @param c : the column the ant's cell is located in
 * @param numSteps : the number of time steps of the ant
 */
Ant::Ant(int r, int c)
:Organism(true)
{
	row = r;
	col = c;
}

/**
 * Determines whether a given square is occupied
 * @param direction: the cell to determine occupancy
 * 			One of five values: right, left, up, down, or center
 * @return true if the cell has something in it, false otherwise
 * 			Cells off the edge of the grid are considered occupied
 */
bool Ant::isOccupied(int direction){
	int row = getCurrentRow();
	int col = getCurrentCol();
	int newCellR = 0;
	int newCellC = 0;
	if (direction == 1){
		newCellR = row + 1;
		newCellC = col;
	}
	if(direction == 2){
		newCellR = row - 1;
		newCellC = col;
	}
	if(direction == 3){
		newCellR = row;
		newCellC = col + 1;
	}
	if(direction == 4){
		newCellR = row;
		newCellC = col -1;
	}


	//Determine if off the grid
	//If it is off the grid, return false
	//if getOccupant returns an ant or buggy, return yes
	//otherwise return false
	return true;
}

/**
 * Moves the ant
 * @return true when ant finishes moving
 */
bool Ant::move()
{
	int nowRow = getCurrentRow();
	int nowCol = getCurrentCol();
	int numOccupied = 0;
	for (int i = 1; i < 5; i++){
		if (isOccupied(i)){
			numOccupied++;
		}
	}
	if (numOccupied == 4){
		return true;
	}
	else {
	int direction = Randomization();
	if (isOccupied(direction) == false){
		if (direction == 1){
			row = nowRow + 1;
		}
		if(direction == 2){
			row = nowRow - 1;
		}
		if(direction == 3){
			col = nowCol + 1;
		}
		if(direction == 4){
			col = nowCol -1;
		}
		else{
			std::cout << "Direction is an out of bounds value." << std::endl;
		}
	}
	else{
		move();
	}
	}

	return true;
}

/**
 * Breeds the ant
 * @return true if ant breeds successfully, false otherwise
 */
bool Ant::breed()
{

	int nowRow = getCurrentRow();
	int nowCol = getCurrentCol();
	int numOccupied = 0;
	for (int i = 1; i < 5; i++){
		if (isOccupied(i)){
			numOccupied++;
		}
	}
	if (numOccupied == 4){
		return true;
	}
	else {
	int direction = Randomization();
	if (isOccupied(direction) == false){
		if (direction == 1){
			row = nowRow + 1;
			col = nowCol;
		}
		if(direction == 2){
			row = nowRow - 1;
			col = nowCol;
		}
		if(direction == 3){
			row = nowRow;
			col = nowCol + 1;
		}
		if(direction == 4){
			row = nowRow;
			col = nowCol -1;
		}
		else{
			std::cout << "Direction is an out of bounds value." << std::endl;
		}
	}
	else{
		breed();
	}

	//create ant at row and col

	}

	bool status = true;
	return status;
}

/**
 * Gets current row of ant
 * @return the row the ant is currently in
 */
int Ant::getCurrentRow(){

	return row;
}

/**
 * Gets current column of ant
 * @return the column the ant is currently in
 */
int Ant::getCurrentCol(){

	return col;
}


/**
 * Destructs the ant class
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

