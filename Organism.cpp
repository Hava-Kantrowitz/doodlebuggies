/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Victoria Bowen and Hava Kantrowitz
 */

#include "Organism.h"
#include <iostream>

/**
 * This is the empty constructor for the organism.
 */
Organism::Organism() {
	// TODO Auto-generated constructor stub

}

/**
 * This is the constructor for the organism
 * @param b a boolean that is true if the organism is an ant
 */
Organism::Organism(bool b) {
	amAnt = b;
	isChecked = true;

}

/** This is the move function for the organism.
 * 		This is a virtual function, and is overriden by the ant and doodlebug classes
 * 		An organism that is not an ant or doodlebug cannot move
 * 	@param playingGrid the grid of play for the game
 *	@return false, should never be called for an unset organism
*/
bool Organism::move(Grid* playingGrid)
{
	return false;
}

/** This is the breed function for the organism.
 * 		This is a virtual function, and is overriden by the ant and doodlebug classes
 * 		An organism that is not an ant or doodlebug cannot breed
 * 	@param playingGrid the grid of play for the game
 *	@return false, should never be called for an unset organism
*/
bool Organism::breed(Grid* playingGrid)
{
	return false;
}

/**
 * This is a method to determine if the given organism is prey.
 * @return true if the organism is an ant
 *         otherwise returns false
 */
bool Organism::isPrey()
{
	return amAnt;
}

/** This is a method to set an organism to an organism
 * @param b boolean which is true for an ant and false otherwise
 */
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}

/**
 * This method sets the isChecked variable
 * @param check the boolean representing the value to set isChecked to
 */
void Organism::setIsChecked(bool check){
	isChecked = check;
}

/**
 * This method gets the isChecked variable
 */
bool Organism::getIsChecked(){
	return isChecked;
}

/**
 * This is the destructor for an organism
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

