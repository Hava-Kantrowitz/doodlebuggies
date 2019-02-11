/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Hava Kantrowitz
 */

#include "Cell.h"

occupationStatus guest  = empty;

/**
 * Constructs an instance of cell class
 */
Cell::Cell() {

	guest = empty;
}

/**
 * Sets the occupants of a cell
 * @param g : the occupation status of the cell, whether occupied or not
 * @return true if cell is successfully set occupied, false otherwise
 */
bool Cell::setOccupant(occupationStatus g)
{
	bool result = true;
	if(guest==empty)
	{
		guest = g;
	}
	else
	{
		result = false;
	}
	return result;
}

/**
 * Gets the occupant of the cell
 * @return whether or not the cell is occupied
 */
occupationStatus Cell::getOccupant()
{
	return guest;
}

/**
 * Destructs the cell class
 */
Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

