/*
 * Ant.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */
// include statements
#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
// variables for the class
class Ant: public Organism {
private:
	int row = 0; // row of ant
	int col = 0; // column of ant
	int numStepsSurvive = 0;
// public methods for the class
public:
	Ant();
	Ant(int r=0, int c = 0);
	bool move(Grid* playingGrid);
	bool breed(Grid* playingGrid);
	int getNumStepsSurvive();
	 ~Ant();
};

#endif /* ANT_H_ */
