/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"

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

