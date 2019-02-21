/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Victoria Bowen and Hava Kantrowitz
 */

#include "Doodlebug.h"
#include "Ant.h"
#include <iostream>

/**
 * This is the constructor for a doodlebug
 */
Doodlebug::Doodlebug() {
	// TODO Auto-generated constructor stub

}
/** This is a constuctor for doodlebug
 * @param r the row of the doodlebug
 * @param c the column of the doodlebug
 *
 */
Doodlebug::Doodlebug(int r, int c)
:Organism(false)
{
	row = r;
	col = c;
	numStepsNoEat = 0;
	numStepsSurvive = 0;
}


/** This is the move function for a doodlebug. The doodlebug eats an ant in an adjacent cell and moves to that cell.
 * @param playingGrid the setup of the game
 * @return true if the doodlebug moves
 */
bool Doodlebug::move(Grid* playingGrid)
{
	bool status = true;
	// if the doodle bug was able to eat successfully
	bool ableToEat = eat(playingGrid);
	if(ableToEat){
		status = true;
	}
	// if the doodle was not able to eat
	else{
		numStepsNoEat++;
		int cell = playingGrid->getEmptyNeighbor(row, col);
		// if the doodle cannot move either
		if(cell == -1){
			status = false;
		}
		// checks if it is the bottom cell
		else if (cell == 1) {
			row++;
			playingGrid->setCellOccupant(row, col, doodlebug, this); //setting up the new cell
			playingGrid->setCellOccupant(row - 1, col, empty, NULL);
		}
		// checks if it is the top cell
		else if (cell == 2) {
			row--;
			playingGrid->setCellOccupant(row, col, doodlebug, this); //setting up the new cell
			playingGrid->setCellOccupant(row + 1, col, empty, NULL);
		}
		// checks if it is the left cell
		else if (cell == 3) {
			col--;
			playingGrid->setCellOccupant(row, col, doodlebug, this); //setting up the new cell
			playingGrid->setCellOccupant(row, col + 1, empty, NULL);
		}
		// checks if it is the cell to the right
		else {
			col++;
			playingGrid->setCellOccupant(row, col, doodlebug, this); //setting up the new cell
			playingGrid->setCellOccupant(row, col - 1, empty, NULL);
		}
	}
	numStepsSurvive++;

	return status;
 }
/** This is the breed function for doodlebug. If the doodlebug survives 8
 *  time steps a new doodlebug is born in an adjacent cell.
 * @return true if the doodlebug is able to breed false otherwise
 */
bool Doodlebug::breed(Grid* playingGrid)
{
	bool status = true;
	// gets the desired cell to move to
	int cell = playingGrid->getEmptyNeighbor(row, col);
	// checks if the ant is unable to breed
	if (cell == -1) {
		status = false;
	}
	// if the ant can breed
	else {
		Organism* newDoodle;
		numStepsSurvive = 0;
		if (cell == 1) {
			newDoodle = new Doodlebug(row + 1, col);
			playingGrid->setCellOccupant(row + 1, col, doodlebug, newDoodle);
		}
		// checks if it is the top cell
		else if (cell == 2) {
			newDoodle = new Doodlebug(row - 1, col);
			playingGrid->setCellOccupant(row - 1, col, doodlebug, newDoodle);
		}
		// checks if it is the left cell
		else if (cell == 3) {
			newDoodle = new Doodlebug(row, col - 1);
			playingGrid->setCellOccupant(row, col - 1, doodlebug, newDoodle);
		}
		// checks if it is the cell to the right
		else {
			newDoodle = new Doodlebug(row, col + 1);
			playingGrid->setCellOccupant(row, col + 1, doodlebug, newDoodle);
		}
	}

	return status;

}
/** This is the function for the doodlebug to eat an ant. Each time step
 * the doodlebug eats an ant in an adjacent cell.
 * @param playingGrid the grid with the setup
 * @return true if the doodlebug eats the ant
 *         otherwise it returns false
 */
bool Doodlebug::eat(Grid* playingGrid)
{	// gets the integer corresponding to the cell with prey
	int cell = playingGrid->getPrey(row, col);
	bool status = true;
	// if the doodlebug has nothing to eat
	if(cell == -1){
		status = false;
	}
	// when the doodlebug has something to eat
	else {
		// checks if it is the bottom cell
		int origRow = row; // keep original for setting NULL
		int origCol = col;
		numStepsNoEat = 0;
		if (cell == 1) {
			row++;
		}
		// checks if it is the top cell
		else if (cell == 2) {
			row--;
		}
		// checks if it is the left cell
		else if (cell == 3) {
			col--;
		}
		// checks if it is the cell to the right
		else {
			col++;
		}
		delete ((Ant*)(playingGrid->getCellOrganism(row, col))); // destruct the ant
		playingGrid->setCellOccupant(row, col, doodlebug, this); //setting up the new cell
		playingGrid->setCellOccupant(origRow, origCol, empty, NULL);
	}


	return status;
}
/** This method gets the number of steps without food
 * @return the time steps without the food
 */
int Doodlebug::getNumStepsNoEat(){
	return numStepsNoEat;
}
/** This method gets the number of steps the doodlebug survived
 * @return the time steps the doodlebug has survived
 */
int Doodlebug::getNumStepsSurvive(){
	return numStepsSurvive;
}

/** This is the method that gets the row number
 * @return the row of the doodlebug
 *
 */
int Doodlebug::getRow(){
	return row;
}
/** This is the method that gets the column number
 * @return the column of the doodle bug
 */
int Doodlebug::getCol(){
	return col;
}

/**
 * This is the destructor for the doodlebug. Used when the doodlebug starves
 * (does not eat an ant within 3 time steps).
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

