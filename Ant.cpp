/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Ant.h"

Ant::Ant()
//:Organism(true)
{

}
Ant::Ant(int r, int c)
:Organism(true)
{
	row = r;
	col = c;
}

bool Ant::move()
{
	bool status = true;
	return status;
}

bool Ant::breed()
{
	bool status = true;
	return status;
}

Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

