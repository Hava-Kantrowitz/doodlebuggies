/*
 * Tests2.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef TESTS2_H_
#define TESTS2_H_

class Tests2 {
public:
	Tests2();
	bool doTests();
	bool gridTest();
	bool makeAntsTest();
	bool antsMoveTest();
	bool testStepsToBirthAnt();
	bool testBreedEligibilityAnt();
	bool antsBreedTest();
	bool antsDieTest();
	bool makeDoodlesTest();
	bool testIsPrey();
	bool testRandomization();
	bool testEnumeration();
	bool testAdjacency();
	bool testUnoccupied();
	bool doodleMoveTest();
	bool testNumSteps();
	bool testAntsEaten();
	bool testRemoval();
	bool testStepsBirthBuggy();
	bool testStarvationState();
	bool testBreedEligibilityBuggy();
	bool doodleBreedTest();
	bool doodleEatTest();
	bool doodleDietest();
	bool testAntAction();
	bool testBuggyAction();


	virtual ~Tests2();
};

#endif /* TESTS2_H_ */
