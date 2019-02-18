/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Hava Kantrowitz
 */

#include "Doodlebug.h"
#include <iostream>

/**
 * Initializes the doodlebug class
 */
Doodlebug::Doodlebug() {
	// TODO Auto-generated constructor stub

}

Doodlebug::Doodlebug(int r, int c)
:Organism(true){
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
bool Doodlebug::isOccupied(int direction){
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
	//perform directional computation
	//Determine if off the grid
	//If it is off the grid, return false
	//if getOccupant returns an ant or buggy, return yes
	//otherwise return false
	return true;
}

/**
 * Determines whether a given square has an ant
 * @param direction: the cell to determine ant occupancy
 * 			One of five values: right, left, up, down, or center
 * @return true if the cell has something in it, false otherwise
 * 			Cells off the edge of the grid are considered occupied
 */
bool Doodlebug::hasAnt(int direction){
	bool hasAnt = false;
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
	//Perform isPrey on getOccupant
	//If isPrey is true, return true
	//otherwise return false
	return hasAnt;
}

/**
 * Moves the doodlebug
 * @return true if doodlebug moves
 */
bool Doodlebug::move()
{


	int nowRow = getCurrentRow();
	int nowCol = getCurrentCol();
	int numWithAnt = 0;
	int numOccupied = 0;
	for (int i = 1; i < 5; i++){
		if(hasAnt(i)){
			numWithAnt++;
		}
		if(isOccupied(i)){
			numOccupied++;
		}
	}
	if(numWithAnt == 0 && numOccupied == 4){
		return true;
	}
	else if (numWithAnt > 0){
		int antDirection = Randomization();
		if (hasAnt(antDirection)){
			//kill the ant
			if (antDirection == 1){
				row = nowRow + 1;
			}
			if(antDirection == 2){
				row = nowRow - 1;
			}
			if(antDirection == 3){
				col = nowCol + 1;
			}
			if(antDirection == 4){
				col = nowCol -1;
			}
			else{
				std::cout << "Direction is an out of bounds value." << std::endl;
			}
		}
	}
	else{
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
 * Has the doodlebug breed
 * @return true if doodlebug breeds
 */
bool Doodlebug::breed()
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

	//create buggy at row and col

	}

	bool status = true;
	return status;
}

/**
 * Has the doodlebug eat
 * @return true if doodlebug eats
 */
bool Doodlebug::eat()
{
	bool status = true;
	return status;
}

/**
 * Gets the current row of the doodlebug
 * @return the row the doodle is currently in
 */
int Doodlebug::getCurrentRow(){
	return row;
}

/**
 * Gets the current column of the doodlebug
 * @return the column the doodle is currently in
 */
int Doodlebug::getCurrentCol(){
	return col;
}

/**
 * Destructs doodlebug class
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

