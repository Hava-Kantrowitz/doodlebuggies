/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Victoria Bowen and Hava Kantrowitz
 */

#include "Cell.h"
#include "Organism.h"
#include <iostream>


/** This is the constructor for a cell
 */
Cell::Cell() {
	guest = empty;
	organism = NULL;
}
/** This is the constructor for a cell
 * @param org pointer to organism in the cell
 */
Cell::Cell(Organism* org) {
	// checking if ant
	if(org->isPrey()){
		guest = ant;
	}
	// checking if NULL
	else if(org == NULL){
		guest = empty;
	}
	// checking if doodlebug
	else{
		guest = doodlebug;
	}
	organism = org;
}


/** This is the method that sets the occupant
 * @param g the occupation status of the guest (empty, ant, doodlebug)
 * @param org the organism that is being set
 */
void Cell::setOccupant(occupationStatus g, Organism* org)
{
		guest = g;
		organism = org;
}
/**
 * This is the method to get the occupation status of the cell
 * @return the occupation status of the cell
 */
occupationStatus Cell::getOccupant()
{
	return guest;
}
/**
 * This is the method to get the organism of the cell
 * @return the pointer to the organism in the cell
 */
Organism* Cell::getOrganism(){
	return organism;
}


/**
 * This is the destructor for the cell
 */
Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

