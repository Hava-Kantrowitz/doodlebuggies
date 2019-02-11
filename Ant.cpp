/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Hava Kantrowitz
 */

#include "Ant.h"

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
 */
Ant::Ant(int r, int c)
:Organism(true)
{
	row = r;
	col = c;
}

/**
 * Moves the ant
 * @return true if ant moves successfully, false otherwise
 */
bool Ant::move()
{
	bool status = true;
	return status;
}

/**
 * Breeds the ant
 * @return true if ant breeds successfully, false otherwise
 */
bool Ant::breed()
{
	bool status = true;
	return status;
}


/**
 * Destructs the ant class
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

