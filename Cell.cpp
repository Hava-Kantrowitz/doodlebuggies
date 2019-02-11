/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include "Cell.h"

occupationStatus guest  = empty;

Cell::Cell() {

	guest = empty;
}

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
occupationStatus Cell::getOccupant()
{
	return guest;
}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

