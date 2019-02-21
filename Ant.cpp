/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Victoria Bowen and Hava Kantrowitz
 */

#include "Ant.h"
#include "Grid.h"
#include <iostream>
/** This is the empty constructor for an ant
 *
 */
Ant::Ant()
//:Organism(true)
{

}
/**
 * This is a constructor for an ant
 * @param r the row the ant should be in
 * @param c the column the ant should be in
 */
Ant::Ant(int r, int c)
:Organism(true)
{
	row = r;
	col = c;
	numStepsSurvive = 0;
}

/** This is the move function for the ant. Every time step the ant
 *  tries to move to an adjacent cell.
 * 	@param playingGrid the grid of play for the game
 *	@return true if the ant was able to move
 */
bool Ant::move(Grid* playingGrid)
{
	int cell = playingGrid->getEmptyNeighbor(row, col);
	bool status = true;
	// this checks if the given ant has no empty neighbors
	if(cell == -1){
		status = false;
	}
	// if there is a neighbor to move to
	else{
		// checks if it is the bottom cell
		if(cell == 1){
			row++;
			// sets up place moved to
			playingGrid->setCellOccupant(row, col, ant, this);
			// sets other cell to empty
			playingGrid->setCellOccupant(row-1, col, empty, NULL);
		}
		// checks if it is the top cell
		else if (cell == 2) {
			row--;
			// sets up place moved to
			playingGrid->setCellOccupant(row, col, ant, this);
			// sets old cell to empty
			playingGrid->setCellOccupant(row+1, col, empty, NULL);

		}
		// checks if it is the left cell
		else if (cell == 3) {
			col--;
			// sets up place moved to
			playingGrid->setCellOccupant(row, col, ant, this);
			// sets old to empty
			playingGrid->setCellOccupant(row, col+1, empty, NULL);
		}
		// checks if it is the cell to the right
		else {
			col++;
			// sets up place moved to
			playingGrid->setCellOccupant(row, col, ant, this);
			// sets old to empty
			playingGrid->setCellOccupant(row, col-1, empty, NULL);
		}
	}
	numStepsSurvive++;
	return status;
}
/** This is the breed function for an ant. If an ant survives 3 time steps,
 * a new ant is born in an adjacent cell.
 * @param playingGrid the game setup
 * @return true if the ant has given birth
 */
bool Ant::breed(Grid* playingGrid)
{
	// gets the desired cell to move to
	int cell = playingGrid->getEmptyNeighbor(row, col);
	bool status = true;
	// checks if the ant is unable to breed
	if (cell == -1) {
		status = false;
	}
	// if the ant can breed
	else {
		Organism* newAnt;
		numStepsSurvive = 0;
		if (cell == 1) {
			newAnt = new Ant(row + 1, col);
			playingGrid->setCellOccupant(row+1, col, ant, newAnt);
		}
		// checks if it is the top cell
		else if (cell == 2) {
			newAnt = new Ant(row-1, col);
			playingGrid->setCellOccupant(row-1, col, ant, newAnt);
		}
		// checks if it is the left cell
		else if (cell == 3) {
			newAnt = new Ant(row, col-1);
			playingGrid->setCellOccupant(row, col- 1, ant, newAnt);
		}
		// checks if it is the cell to the right
		else {
			newAnt = new Ant(row, col+1);
			playingGrid->setCellOccupant(row, col+1, ant, newAnt);
		}
	}

	return status;
}
/** This method gets the number of steps that the ant has survived
 * @return the number of steps since the last birth
 */
int Ant::getNumStepsSurvive(){
	return numStepsSurvive;
}

/**
 * This is the destructor for the ant. Used when the ant is eaten by the doodlebug.
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

