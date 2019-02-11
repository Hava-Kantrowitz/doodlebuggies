/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Hava Kantrowitz
 */

#include "Organism.h"
bool amAnt = false;

/**
 * Constructs the organism class
 */
Organism::Organism() {
	// TODO Auto-generated constructor stub

}

/**
 * Initializes the organism class
 * Determining whether or not the organism is an ant
 * @param b : true if the organism is an ant, false otherwise
 */
Organism::Organism(bool b) {
	amAnt = b;

}

/**
 * Determines if the organism is prey
 * @return whether or not the organism is an ant
 */
bool Organism::isPrey()
{
	return amAnt;
}

/**
 * Sets whether or not the organism is an ant
 * @return b : true if organism is an ant, false otherwise
 * @return void, sets the amAnt field in the Organism class
 */
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}

/**
 * Destructs the organism class
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

