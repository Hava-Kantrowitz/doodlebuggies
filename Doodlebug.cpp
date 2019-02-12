/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Hava Kantrowitz
 */

#include "Doodlebug.h"

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
 * Moves the doodlebug
 * @return true if doodlebug moves
 */
bool Doodlebug::move()
{
	bool status = true;
	return status;
}

/**
 * Has the doodlebug breed
 * @return true if doodlebug breeds
 */
bool Doodlebug::breed()
{
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

