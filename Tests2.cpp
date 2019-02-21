/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Victoria Bowen and Hava Kantrowitz
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>

/**
 * This is the constructor for the testing class.
 */
Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}
/**
 * This is the method that does all the tests.
 * @return true if all the tests pass
 *    	   otherwise it returns false
 */
bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = gridTest();
	if(ok1){
		std::cout<<"Grid test passes\n"<<std::endl;
	}
	//populate it with ants
	bool ok2 = makeAntsTest();
	if(ok2){
		std::cout<<"Make ants passes\n"<<std::endl;
	}
	//see whether they move
	bool ok3 = antsMoveTest();
	if(ok3){
		std::cout<<"Ants move test passes\n"<<std::endl;
	}
	//see whether they breed
	bool ok4 = antsBreedTest();
	if(ok4){
		std::cout<<"Ants breed test passes\n"<<std::endl;
	}
	//populate with doodlebugs
	bool ok5 = makeDoodlesTest();
	if(ok5){
		std::cout<<"Make doodle test passes\n"<<std::endl;
	}
	//see whether they move
	bool ok6 = doodleMoveTest();
	if(ok6){
		std::cout<<"Move doodle test passes\n"<<std::endl;
	}
	//see whether they breed
	bool ok7 = doodleBreedTest();
	if(ok7){
		std::cout<<"Breed doodle test passes\n"<<std::endl;
	}
	//see whether they eat ants
	bool ok8 = doodleEatTest();
	if(ok8){
		std::cout<<"Eat doodle test passes\n"<<std::endl;
	}

	// see whether the get numLivesSurvived method works
	bool ok9 = numStepsSurvivedAnt();
	if(ok9){
		std::cout<<"Get number of steps survived ant test passes\n"<<std::endl;
	}


	results = ok1 && ok2 && ok3 && ok4 && ok6 && ok7 && ok8 && ok9;
	return results;
}

/**
 * This tests the the grid.
 * @return true if all the grid tests pass
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
	Ant* a1 = new Ant(2,3);
	myGrid.setCellOccupant(2, 3, ant, a1);
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
 * This tests making ants.
 * @return true if all the ant making tests pass
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
	Ant* a1 = new Ant(1,2);
	myGrid_p->setCellOccupant(1, 2, ant, a1);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}

	if(myGrid_p->getCellOccupant(3, 4)!= empty)
	{

		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	Doodlebug* d1 = new Doodlebug(3,4);
	myGrid_p->setCellOccupant(3, 4, doodlebug, d1);
	if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty, NULL);
	delete a1;
	delete myGrid_p;
	result = ok1 && ok2;
	return result;
}
/**
 * This tests the ants moving
 * @return true if all the ant moving tests pass
 */
bool Tests2::antsMoveTest()
{
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	std::cout << "Running the move ants test" << std::endl;
	Grid* myGrid_p = new Grid(9);
	Ant* a1 = new Ant(1,1);
	Ant* a2 = new Ant(0,1);
	Ant* a3 = new Ant(1,0);
	Ant* a4 = new Ant(1,2);
	Ant* a5 = new Ant(2,1);
	Ant* a6 = new Ant(0,0);
	myGrid_p->setCellOccupant(1, 1, ant, a1); //setting up the grid and the ants
	myGrid_p->setCellOccupant(0, 1, ant, a2);
	myGrid_p->setCellOccupant(1, 0, ant, a3);
	myGrid_p->setCellOccupant(1, 2, ant, a4);
	myGrid_p->setCellOccupant(2, 1, ant, a5);
	myGrid_p->setCellOccupant(0, 0, ant, a6);
	// this tests the case where the ant should should stay in the same place
	a1->move(myGrid_p);
	if(myGrid_p->getCellOccupant(1, 1) == ant){
		ok1 = true;
	}
	// this tests the case where the ant has one option to move to
	a3->move(myGrid_p);
	if(myGrid_p->getCellOccupant(1,0) == empty && myGrid_p->getCellOccupant(2, 0) == ant){
		ok2 = true;
	}
	// this tests the case where the ant has multiple options to move to
	a5->move(myGrid_p);
	if(myGrid_p->getCellOccupant(2, 1) == empty && (myGrid_p->getCellOccupant(3, 1)== ant || myGrid_p->getCellOccupant(2, 2) == ant)){
		ok3 = true;
	}
	result = ok1 && ok2 && ok3;
	delete myGrid_p;
	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete a5;
	delete a6;

	return result;
}
/**
 * This is the ant breeding test.
 * @param true if all the ant breeding tests pass.
 */
bool Tests2::antsBreedTest()
{
	std::cout << "Running the breed ants test" << std::endl;

	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	Grid* myGrid_p = new Grid(9);
	Ant* a1 = new Ant(1, 1);
	Ant* a2 = new Ant(0, 1);
	Ant* a3 = new Ant(1, 0);
	Ant* a4 = new Ant(1, 2);
	Ant* a5 = new Ant(2, 1);
	Doodlebug* a6 = new Doodlebug(0, 0);
	myGrid_p->setCellOccupant(1, 1, ant, a1); //setting up the grid and the ants
	myGrid_p->setCellOccupant(0, 1, ant, a2);
	myGrid_p->setCellOccupant(1, 0, ant, a3);
	myGrid_p->setCellOccupant(1, 2, ant, a4);
	myGrid_p->setCellOccupant(2, 1, ant, a5);
	myGrid_p->setCellOccupant(0, 0, doodlebug, a6);


	// this checks the case in which the ant cannot breed
	a1->breed(myGrid_p);
	if(myGrid_p->getCellOccupant(1, 1) == ant){
		ok1 = true;
	}

	// when there is only one open cell
	a3->breed(myGrid_p);
	if(myGrid_p->getCellOccupant(1,0) == ant && myGrid_p->getCellOccupant(2, 0) == ant){
		ok2 = true;
	}
	// when there are multiple options
	a5->breed(myGrid_p);
	if(myGrid_p->getCellOccupant(2, 1) == ant && (myGrid_p->getCellOccupant(3, 1)== ant || myGrid_p->getCellOccupant(2, 2)== ant)){
		ok3 = true;
	}
	result = ok1 && ok2 && ok3;
	delete myGrid_p;
	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete a5;
	delete a6;

	return result;
}

/**
 * This is the test to check making a doodlebug
 * @return true if the make doodlebug tests pass
 */
bool Tests2::makeDoodlesTest()
{
	bool result = true;
	std::cout << "Running the make doodlebugs test" << std::endl;
	bool ok1 = true;
	bool ok2 = true;
	Grid* myGrid_p = new Grid(9);
	if (myGrid_p->getCellOccupant(1, 2) != empty) {
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	Doodlebug* d1 = new Doodlebug(1, 2);
	myGrid_p->setCellOccupant(1, 2, doodlebug, d1);
	if (myGrid_p->getCellOccupant(1, 2) != doodlebug) {
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok1 = false;
	}

	if (myGrid_p->getCellOccupant(3, 4) != empty) {

		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	Doodlebug* d2 = new Doodlebug(3, 4);
	myGrid_p->setCellOccupant(3, 4, doodlebug, d1);
	if (myGrid_p->getCellOccupant(3, 4) != doodlebug) {
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty, NULL);
	delete d1;
	delete d2;
	delete myGrid_p;
	result = ok1 && ok2;

	return result;
}
/**
 * This is to test the doodlebug moving function.
 * @return true if the moving tests all pass
 */
bool Tests2::doodleMoveTest()
{
	// this also tests some of the breed test because the doodle bug has to move to those place
	std::cout << "Running the move doodlebugs test" << std::endl;
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	Grid* myGrid_p = new Grid(9);   // setting up the grid and the ant
	Doodlebug* d1 = new Doodlebug(1,1);
	Ant* a1 = new Ant(0,1);
	Doodlebug* d2 = new Doodlebug(1,0);
	Doodlebug* d3 = new Doodlebug(1,2);
	Ant* a2 = new Ant(2,1);
	Ant* a3 = new Ant(1,3);

	myGrid_p->setCellOccupant(1, 1, doodlebug, d1); //setting up the grid and the organisms
	myGrid_p->setCellOccupant(0, 1, ant, a1);
	myGrid_p->setCellOccupant(1, 0, doodlebug, d2);
	myGrid_p->setCellOccupant(1, 2, doodlebug, d3);
	myGrid_p->setCellOccupant(2, 1, ant, a2);
	myGrid_p->setCellOccupant(1, 3, ant, a3);
	// this is some of the set up for the test doodlebug function

	// this is the test when the doodlebug only has one place to move to (that has an ant)
	d3->move(myGrid_p);
	if(myGrid_p->getCellOccupant(1, 2)== empty && myGrid_p->getCellOccupant(1, 3) == doodlebug){
		ok1 = true;
	}
	// this is the test when the doodlebug has two places to move that have ants in them
	d1->move(myGrid_p);
	if(myGrid_p->getCellOccupant(1, 1) == empty && (myGrid_p->getCellOccupant(0,1)== doodlebug ||
			myGrid_p->getCellOccupant(2, 1)==doodlebug)){
		ok2 = true;
	}
	// this is the test when the doodlebug does not have any ants to move to and it just moves
	d2->move(myGrid_p);
	if(myGrid_p->getCellOccupant(1,0)== empty && (myGrid_p->getCellOccupant(0,0) == doodlebug
			|| myGrid_p->getCellOccupant(2,0)==doodlebug)){
		ok3 = true;
	}

	result = ok1 && ok2 && ok3;
	delete d1;
	delete d2;
	delete d3;
	delete a2;
	delete myGrid_p;
	return result;
}
/**
 * This tests the doodlebug breeding functions
 * @return true if all the breeding tests pass
 */
bool Tests2::doodleBreedTest()
{
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	std::cout << "Running the breed doodlebugs test" << std::endl;
	Grid* myGrid_p = new Grid(9);   // setting up the grid and the ant
	Doodlebug* d1 = new Doodlebug(1,1);
	Ant* a1 = new Ant(0,1);
	Doodlebug* d2 = new Doodlebug(1,0);
	Doodlebug* d3 = new Doodlebug(1,2);
	Ant* a2 = new Ant(2,1);

	myGrid_p->setCellOccupant(1, 1, doodlebug, d1); //setting up the grid and the organisms
	myGrid_p->setCellOccupant(0, 1, ant, a1);
	myGrid_p->setCellOccupant(1, 0, doodlebug, d2);
	myGrid_p->setCellOccupant(1, 2, doodlebug, d3);
	myGrid_p->setCellOccupant(2, 1, ant, a2);

	// This tests the case in which the doodle is not able to breed
	d1->breed(myGrid_p);
	if(myGrid_p->getCellOccupant(1, 1) == doodlebug){
		ok1 = true;
	}
	// This tests the case in which the doodle has more than one place to move to
	d2->breed(myGrid_p);
	if(myGrid_p->getCellOccupant(1, 0) == doodlebug && (myGrid_p->getCellOccupant(0, 0) == doodlebug ||
			myGrid_p->getCellOccupant(2, 0) == doodlebug)){
		ok2 = true;
	}
	// This tests the case in which the doodlebug has three places to move to
	d3->breed(myGrid_p);
	if(myGrid_p->getCellOccupant(1, 2) == doodlebug && (myGrid_p->getCellOccupant(1, 3) == doodlebug ||
			myGrid_p->getCellOccupant(0, 2) == doodlebug || myGrid_p->getCellOccupant(2, 2) == doodlebug)){
		ok3 = true;
	}

	result = ok1 && ok2 && ok3;
	delete d1;
	delete d2;
	delete d3;
	delete a1;
	delete a2;
	delete myGrid_p;
	return result;
}
/**
 * This tests the doodlebug eating functions
 * @return true if all the eating tests pass
 */
bool Tests2::doodleEatTest()
{
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	std::cout << "Running the eat ant test" << std::endl;
	Grid* myGrid_p = new Grid(9);   // setting up the grid and the ant
	Doodlebug* d1 = new Doodlebug(1, 1);
	Ant* a1 = new Ant(0, 1);
	Doodlebug* d2 = new Doodlebug(1, 0);
	Doodlebug* d3 = new Doodlebug(1, 2);
	Ant* a2 = new Ant(2, 1);
	Ant* a3 = new Ant(1, 3);

	myGrid_p->setCellOccupant(1, 1, doodlebug, d1); //setting up the grid and the organisms
	myGrid_p->setCellOccupant(0, 1, ant, a1);
	myGrid_p->setCellOccupant(1, 0, doodlebug, d2);
	myGrid_p->setCellOccupant(1, 2, doodlebug, d3);
	myGrid_p->setCellOccupant(2, 1, ant, a2);
	myGrid_p->setCellOccupant(1, 3, ant, a3);


	// This is to test the case when the doodlebug has nothing to eat
	int cell = d2->eat(myGrid_p); // function return
	if(myGrid_p->getCellOccupant(1, 0) == doodlebug && cell == false){
		ok1 = true;
	}

	// This is to test the case where the doodle bug has multiple options to eat
	d1->eat(myGrid_p);
	if(myGrid_p->getCellOccupant(1, 1) == empty && (myGrid_p->getCellOccupant(0,1 ) == doodlebug
			|| myGrid_p->getCellOccupant(2, 1) == doodlebug)){
		ok2 = true;
	}

	// This is to test the case in which the doodlebug only has one option to eat
	d3->eat(myGrid_p);
	if(myGrid_p->getCellOccupant(1, 2) == empty && (myGrid_p->getCellOccupant(1, 3) == doodlebug)){
		ok3 = true;
	}

	result = ok1 && ok2 && ok3;
	return result;
}

/**
 * This is the test to check the isAnt function.
 * @return true if all the test cases pass
 */
bool Tests2::isAntTest(){
	bool result = false;
	std::cout<<"Running the is ant test" << std::endl;
	return result;
}
/**
 * This is the test to check the number of steps the doodlebug has gone without food
 * @return true if all the cases pass
 */
bool Tests2::numStepNoFoodTest(){
	bool result = false;
	std::cout<<"Running the number of steps without food test." << std::endl;
	return result;
}

/**
 * This is the test for the doodlebug number of survived lives
 * @return true is all the test cases pass
 */
bool Tests2::numSurvivedDoodlebugTest(){
	bool result = false;
	std::cout<<"Running the survived test for doodlebug."<< std::endl;
	return result;
}


/** This is the test to see if the ant number of steps survived works
 * @return true if all the test cases pass
 *
 */
bool Tests2::numStepsSurvivedAnt(){
	bool result = false;
	bool ok1 = false;

	std::cout<<"Running the number of steps ant survived test."<< std::endl;
	Grid* myGrid = new Grid(9);
	Ant* numStepsAnt = new Ant(1, 3);
	numStepsAnt->move(myGrid);
	numStepsAnt->move(myGrid);
	numStepsAnt->move(myGrid);

	if(numStepsAnt->getNumStepsSurvive() == 3){
		ok1 = true;
	}

	result = ok1;
	return result;
}


/**
 * This is the destructor for the testing class
 */
Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

