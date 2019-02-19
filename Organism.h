/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

#include "Grid.h"

class Organism {
public:
	Organism();
	Organism(bool b);
	bool isPrey();
	int Randomization();
	virtual bool move()=0;
	virtual bool breed()=0;
	void setAmAnt(bool b);
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */
