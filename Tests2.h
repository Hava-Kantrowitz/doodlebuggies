/*
 * Tests2.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
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
	bool isAntTest();
	bool numStepNoFoodTest();
	bool numAntNeighborsTest();
	bool numSurvivedDoodlebugTest();
	bool numNeighborsAntTest();
	bool numStepsSurvivedAnt();
	bool stepAntTest();
	bool stepDoodlebugTest();


	virtual ~Tests2();
};

#endif /* TESTS2_H_ */
