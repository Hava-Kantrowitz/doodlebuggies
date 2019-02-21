/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Victoria Bowen and Hava Kantrowitz
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include "Grid.h"

// public methods for the organism class
class Organism {
private:
	bool amAnt = false;
	bool isChecked = true;
public:
	Organism();
	Organism(bool b);
	bool isPrey();
	virtual bool move(Grid* playingGrid)=0;
	virtual bool breed(Grid* playingGrid)=0;
	void setAmAnt(bool b);
	bool getIsChecked();
	void setIsChecked(bool check);
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */

