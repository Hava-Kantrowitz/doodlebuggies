/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Victoria Bowen and Hava Kantrowitz
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_
// the includes
#include "Organism.h"


//the public methods for Doodlebug
class Doodlebug: public Organism {
private:
	int row = 0; // row of ant
	int col = 0; // column of ant
	int numStepsNoEat = 0;
	int numStepsSurvive = 0;
public:
	Doodlebug();
	Doodlebug(int r, int c);
	bool move(Grid* playingGrid);
	bool breed(Grid* playingGrid);
	bool eat(Grid* playingGrid);
	int getNumStepsNoEat();
	int getNumStepsSurvive();
	int getRow();
	int getCol();
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
