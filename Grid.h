/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_
// the include statements
#include "Cell.h"


// these are the public methods for the grid class
class Grid {
private:
	int n=0; //this initial value will be changed when the program is invoked
	Cell** myGridCells_ptr_array = (Cell**)nullptr;
public:
	Grid();
	Grid(int nSquaresOnASide);
	void setCellOccupant(int r, int c, occupationStatus g, Organism* org);
	occupationStatus getCellOccupant(int r, int c);
	int getPrey(int r, int c);
	bool isPrey(int r, int c);
	int getEmptyNeighbor(int r, int c);
	bool isEmpty(int r, int c);
	void printBoard(void);
	Organism* getCellOrganism(int r, int c);
	virtual ~Grid();
};

#endif /* GRID_H_ */
