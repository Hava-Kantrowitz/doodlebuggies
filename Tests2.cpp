/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Hava Kantrowitz
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include <iostream>

//In order to test for multiple possible options, I would use the logical or operator (||)


/**
 * Constructs tests2 class
 */
Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}

/**
 * Performs the overall tests
 * @return true if all tests pass, false otherwise
 */
bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = gridTest();
	//populate it with ants
	bool ok2 = makeAntsTest();
	//see whether they move
	bool ok3 = antsMoveTest();
	//tests steps to birth of ant
	bool ok4 = testStepsToBirthAnt();
	//test breed eligibility for ant
	bool ok5 = testBreedEligibilityAnt();
	//see whether they breed
	bool ok6 = antsBreedTest();
	//see whether they die?
	bool ok7 = antsDieTest();//maybe if they wander off?
	//populate with doodlebugs
	bool ok8 = makeDoodlesTest();
	//see whether occupied square has prey
	bool ok9 = testIsPrey();
	//tests randomization
	bool ok10 = testRandomization();
	//test enumeration
	bool ok11 = testEnumeration();
	//test adjacency
	bool ok12 = testAdjacency();
	//test unoccupied
	bool ok13 = testUnoccupied();
	//see whether they move
	bool ok14 = doodleMoveTest();
	//test number of steps calculator
	bool ok15 = testNumSteps();
	//test buggies eating ants
	bool ok16 = testAntsEaten();
	//tests creature removal
	bool ok17 = testRemoval();
	//test steps to birth for buggy
	bool ok18 = testStepsBirthBuggy();
	//test starvation state
	bool ok19 = testStarvationState();
	//test breed eligibility
	bool ok20 = testBreedEligibilityBuggy();
	//see whether they breed
	bool ok21 = doodleBreedTest();
	//see whether they eat ants
	bool ok22 = doodleEatTest();
	//see whether they die
	bool ok23 = doodleDietest();
	//test overall ant action works
	bool ok24 = testAntAction();
	//test overall buggy action works
	bool ok25 = testBuggyAction();
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10
			&& ok11 && ok12 && ok13 && ok14 && ok15 && ok16 && ok17 && ok18 && ok19
			&& ok20 && ok21 && ok22 && ok23 && ok24 && ok25;
	return results;
}

/**
 * Tests the grid function
 * @return true if test passes, false otherwise
 */
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the grid test" << std::endl;
	Grid myGrid = Grid(8);
	if(myGrid.getCellOccupant(2, 3)!=empty)
	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	//std::cout << "second grid test" << std::endl;
	myGrid.setCellOccupant(2, 3, ant);
	if(myGrid.getCellOccupant(2, 3)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	//std::cout << "third grid test" << std::endl;
	myGrid.~Grid();
	result = ok1 && ok2;
	return result;
}

/**
 * Tests ant construction
 * @return true if test passes, false otherwise
 */
bool Tests2::makeAntsTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make ants test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	Ant* a1 = new Ant(3,4);
	if(myGrid_p->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(3, 4, doodlebug);
	if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty);
	delete a1;
	delete myGrid_p;
	result = ok1 && ok2;
	return result;
}

/**
 * Tests ant moving function
 * @return true if test passes, false otherwise
 */
bool Tests2::antsMoveTest()
{
	bool result = true;
	std::cout << "Running the move ants test" << std::endl;

	Ant ant = Ant(2, 5);
	int rowBefore = ant.getCurrentRow();
	int colBefore = ant.getCurrentCol();

	ant.move();
	int rowAfter = ant.getCurrentRow();
	int colAfter = ant.getCurrentCol();

	if (((rowAfter - rowBefore) == 0) && ((colAfter - colBefore) == 0)){
		result = false;
	}


	return result;
}

/**
 * Tests how many steps a given ant has until it can give birth
 * @return true if test passes, false otherwise
 */
bool Tests2::testStepsToBirthAnt(){
	return true;
}

/**
 * Tests how whether an ant can breed
 * @return true if test passes, false otherwise
 */
bool Tests2::testBreedEligibilityAnt(){
	return true;
}

/**
 * Tests ant breeding function
 * @return true if test passes, false otherwise
 */
bool Tests2::antsBreedTest()
{
	bool result = true;
	std::cout << "Running the breed ants test" << std::endl;
	return result;
}

/**
 * Tests ant dying function
 * @return true if test passes, false otherwise
 */
bool Tests2::antsDieTest()
{
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	return result;
}

/**
 * Tests make doodle function
 * @return true if test passes, false otherwise
 */
bool Tests2::makeDoodlesTest()
{
	bool result = true;
	std::cout << "Running the make doodlebugs test" << std::endl;
	return result;
}

/**
 * Tests whether an organism is prey, meaning it is an ant
 * @return true if test passes, false otherwise
 */
bool Tests2::testIsPrey(){
	return true;
}

/**
 * Tests randomization of ant movement choice
 * @return true if test passes, false otherwise
 */
bool Tests2::testRandomization(){
	return true;
}

/**
 * Tests enumeration of ant movement choice
 * @return true if test passes, false otherwise
 */
bool Tests2::testEnumeration(){
	return true;
}

/**
 * Tests whether a cell is adjacent to another cell
 * @return true if test passes, false otherwise
 */
bool Tests2::testAdjacency(){
	return true;
}

/**
 * Tests whether a cell is unoccupied
 * @return true if test passes, false otherwise
 */
bool Tests2::testUnoccupied(){
	return true;
}

/**
 * Tests doodle moving function
 * @return true if test passes, false otherwise
 */
bool Tests2::doodleMoveTest()
{
	bool result = true;
	std::cout << "Running the move doodlebugs test" << std::endl;


	return result;
}

/**
 * Tests current number of steps of organism
 * @return true if test passes, false otherwise
 */
bool Tests2::testNumSteps(){
	return true;
}

/**
 * Tests if a buggy ate an ant
 * @return true if test passes, false otherwise
 */
bool Tests2::testAntsEaten(){
	return true;
}

/**
 * Tests removal from grid of an organism
 * @return true if test passes, false otherwise
 */
bool Tests2::testRemoval(){
	return true;
}

/**
 * Tests how many steps a given buggy has until it can give birth
 * @return true if test passes, false otherwise
 */
bool Tests2::testStepsBirthBuggy(){
	return true;
}

/**
 * Tests if a buggy is starving
 * @return true if test passes, false otherwise
 */
bool Tests2::testStarvationState(){
	return true;
}

/**
 * Tests if a buggy is eligible to give birth
 * @return true if test passes, false otherwise
 */
bool Tests2::testBreedEligibilityBuggy(){
	return true;
}

/**
 * Tests doodle breeding function
 * @return true if test passes, false otherwise
 */
bool Tests2::doodleBreedTest()
{
	bool result = true;
	std::cout << "Running the breed doodlebugs test" << std::endl;
	return result;
}

/**
 * Tests doodle eating function
 * @return true if test passes, false otherwise
 */
bool Tests2::doodleEatTest()
{
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;
	return result;
}

/**
 * Tests doodle dying function
 * @return true if test passes, false otherwise
 */
bool Tests2::doodleDietest()
{
	bool result = true;
	std::cout << "Running the doodlebug dies test" << std::endl;
	return result;
}

/**
 * Tests that ants are able to take an action
 * @return true if test passes, false otherwise
 */
bool Tests2::testAntAction(){
	return true;
}

/**
 * Tests that buggies are able to take an action
 * @return true if test passes, false otherwise
 */
bool Tests2::testBuggyAction(){
	return true;
}

/**
 * Destructs tests2
 */
Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

