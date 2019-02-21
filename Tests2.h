/*
 * Tests2.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Victoria Bowen and Hava Kantrowitz
 */

#ifndef TESTS2_H_
#define TESTS2_H_
// these are the public methods for the testing class
class Tests2 {
public:
	Tests2();
	bool doTests();
	bool gridTest();
	bool makeAntsTest();
	bool antsMoveTest();
	bool antsBreedTest();
	bool makeDoodlesTest();
	bool doodleMoveTest();
	bool doodleBreedTest();
	bool doodleEatTest();
	bool numStepsSurvivedAnt();
	bool cellTest();
	bool testGetOccupant();
	bool testSetOccupant();
	bool testGetOrganism();
	bool numStepsNoEatingBuggy();
	bool numStepsSurvivedBuggy();
	bool getBuggyRow();
	bool getBuggyCol();
	bool gridOccupant();
	bool getGridOrganism();
	bool getPrey();
	bool isPrey();
	bool getEmptyNeighbor();
	bool isEmpty();
	bool testSetAnt();
	bool testChecked();


	virtual ~Tests2();
};

#endif /* TESTS2_H_ */
