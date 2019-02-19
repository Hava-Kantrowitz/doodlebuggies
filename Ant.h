/*
 * Ant.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

class Ant: public Organism {
private:
	int row = 0;
	int col = 0;
	Grid* grid = new Grid(10);

public:
	Ant();
	Ant(int r=0, int c = 0, Grid* g = new Grid(10));
	bool isOccupied(int direction);
	bool move();
	bool breed();
	int getCurrentRow();
	int getCurrentCol();
	Grid** getGrid();
	 ~Ant();
};

#endif /* ANT_H_ */
