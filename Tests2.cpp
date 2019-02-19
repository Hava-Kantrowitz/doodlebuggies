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
			&& ok13 && ok14 && ok15 && ok16 && ok17 && ok18 && ok19
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
	Ant* a1 = new Ant(3,4);
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}

	delete a1;
	delete myGrid_p;
	result = ok1 && ok2;

	if (result){
		std::cout << "Ant creation works." << std::endl;
	}

	return result;
}

/**
 * Tests ant moving function
 * @return true if test passes, false otherwise
 */
bool Tests2::antsMoveTest()
{
	bool result = false;
	std::cout << "Running the move ants test" << std::endl;

	Ant ant = Ant(2, 5);
	int rowBefore = ant.getCurrentRow();
	//std::cout << "Row before is " << rowBefore << std::endl;
	int colBefore = ant.getCurrentCol();
	//std::cout << "Col before is " << colBefore << std::endl;

	ant.move();
	int rowAfter = ant.getCurrentRow();
	//std::cout << "Row after is " << rowAfter << std::endl;
	int colAfter = ant.getCurrentCol();
	//std::cout << "Col after is " << colAfter << std::endl;

	if (((rowAfter - rowBefore) != 0) && ((colAfter - colBefore) != 0)){
		result = true;
	}
	if(result){
		std::cout << "Ant movement works." << std::endl;
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
	//test whether an ant can breed into an empty cell--should allow breeding
	//make sure to check placement of new ant on the grid
	//test that an ant cannot breed when there are no empty cells
	//test that the ant makes a choice when faced with more than 1 empty cell
	//test that an ant cannot breed off the side of the board
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
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make buggies test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	Ant* b1 = new Ant(3,4);
	myGrid_p->setCellOccupant(1, 2, doodlebug);
	if(myGrid_p->getCellOccupant(1, 2)!=doodlebug)
	{
		std::cout << "Cell not set to buggy" << std::endl;
		ok1 = false;
	}

	delete b1;
	delete myGrid_p;
	result = ok1 && ok2;

	if (result){
		std::cout << "Buggy creation works." << std::endl;
	}

	return result;
}

/**
 * Tests whether an organism is prey, meaning it is an ant
 * @return true if test passes, false otherwise
 */
bool Tests2::testIsPrey(){
	//create an ant
	//call isPrey on it
	//If test returns true, set ok1 to true
	//create a buggy
	//call isPrey on it
	//If test returns false, set ok2 to true
	return true;
}

/**
 * Tests randomization of ant movement choice
 * @return true if test passes, false otherwise
 */
bool Tests2::testRandomization(){
	bool ok = false;
	std::cout << "Running randomization test" << std::endl;
	Ant* myAnt = new Ant(2, 3);
	Ant anAnt = *myAnt;
	int randNum = anAnt.Randomization();
	std::cout << "Random number is " << randNum << std::endl;
	if (randNum > 0 || randNum < 5){
		ok = true;
		std::cout << "Randomization works." << std::endl;

	}
	return ok;
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
	//test whether a buggy can breed into an empty cell--should allow breeding
	//make sure to check placement of new buggy on the grid
	//test that a buggy cannot breed when there are no empty cells
	//test that the buggy makes a choice when faced with more than 1 empty cell
	//test that a buggy cannot breed off the side of the board
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

