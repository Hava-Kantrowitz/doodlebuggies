/*
 * Cell.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef CELL_H_
#define CELL_H_

class Organism;

// occupation status for the cell class
enum occupationStatus {empty, ant, doodlebug};

//public methods for the cell class
class Cell {
private:
	Organism* organism;
	occupationStatus guest  = empty;
public:
	Cell();
	Cell(Organism* org);
	void setOccupant(occupationStatus g, Organism* org);
	occupationStatus getOccupant();
	Organism* getOrganism();
	virtual ~Cell();
};

#endif /* CELL_H_ */
