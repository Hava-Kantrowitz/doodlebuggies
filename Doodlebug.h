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
private:
	int row = 0;
	int col = 0;
	Grid* grid = new Grid(10);

public:
	Doodlebug();
	Doodlebug(int r = 0, int c = 0, Grid* g = new Grid(10));
	bool isOccupied(int direction);
	bool hasAnt(int direction);
	bool move();
	bool breed();
	bool eat();
	int getCurrentRow();
	int getCurrentCol();
	Grid** getGrid();
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
