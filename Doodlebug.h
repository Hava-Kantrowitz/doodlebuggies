/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"

class Doodlebug: public Organism {
public:
	Doodlebug();
	bool move();
	bool breed();
	bool eat();
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
