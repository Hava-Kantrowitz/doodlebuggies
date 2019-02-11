/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"
bool amAnt = false;

Organism::Organism() {
	// TODO Auto-generated constructor stub

}
Organism::Organism(bool b) {
	amAnt = b;

}
bool Organism::isPrey()
{
	return amAnt;
}
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}

Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

