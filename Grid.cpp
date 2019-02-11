/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Hava Kantrowitz
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"
#include "Cell.h"

int n=0; //this initial value will be changed when the program is invoked
Cell** myGridCells_ptr_array = (Cell**)nullptr;

/**
 * Constructs the grid class
 */
Grid::Grid() {
	// TODO Auto-generated constructor stub
	Grid(10); //calls general constructor with default value
}

/**
 * Initializes grid with given size
 * @param nSquaresOnASide : number of squares per side on grid
 *
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
}

/**
 * Sets occupant of a grid cell
 * @param r : row of cell to be set
 * @param c : column of cell to be set
 * @param g : whether or nnot cell is occupied
 * @return true if cell is occupied, false otherwise
 */
bool Grid::setCellOccupant(int r, int c, occupationStatus g)
{
	return myGridCells_ptr_array[r][c].setOccupant(g);
}

/**
 * Gets occupant of a grid cell
 * @param r : row of cell to get
 * @param c : column of cell to get
 * @return whether or not the given cell is occupied
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOccupant();
}

/**
 * Destructs grid class
 * Prints out the grid state
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

