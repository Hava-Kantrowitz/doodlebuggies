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
	//create a cell
	bool ok1 = cellTest();
	if(ok1){
		std::cout<<"Cell test passes\n"<<std::endl;
	}

	bool ok2 = testSetOccupant();
	if(ok2){
		std::cout<<"Set occupant passes\n"<<std::endl;
	}

	bool ok3 = testGetOccupant();
	if(ok3){
		std::cout<<"Get occupant passes\n"<<std::endl;
	}

	bool ok4 = testGetOrganism();
	if(ok4){
		std::cout<<"Get organism passes\n"<<std::endl;
	}

	//establish a grid
	bool ok5 = gridTest();
	if(ok5){
		std::cout<<"Grid test passes\n"<<std::endl;
	}
	//populate it with ants
	bool ok6 = makeAntsTest();
	if(ok6){
		std::cout<<"Make ants passes\n"<<std::endl;
	}
	//see whether they move
	bool ok7 = antsMoveTest();
	if(ok7){
		std::cout<<"Ants move test passes\n"<<std::endl;
	}
	//see whether they breed
	bool ok8 = antsBreedTest();
	if(ok8){
		std::cout<<"Ants breed test passes\n"<<std::endl;
	}
	//populate with doodlebugs
	bool ok9 = makeDoodlesTest();
	if(ok9){
		std::cout<<"Make doodle test passes\n"<<std::endl;
	}
	//see whether they move
	bool ok10 = doodleMoveTest();
	if(ok10){
		std::cout<<"Move doodle test passes\n"<<std::endl;
	}
	//see whether they breed
	bool ok11 = doodleBreedTest();
	if(ok11){
		std::cout<<"Breed doodle test passes\n"<<std::endl;
	}
	//see whether they eat ants
	bool ok12 = doodleEatTest();
	if(ok12){
		std::cout<<"Eat doodle test passes\n"<<std::endl;
	}

	// see whether the get numLivesSurvived method works
	bool ok13 = numStepsSurvivedAnt();
	if(ok13){
		std::cout<<"Get number of steps survived ant test passes\n"<<std::endl;
	}

	//see whether num steps no eating for buggy works
	bool ok14 = numStepsNoEatingBuggy();
	if(ok14){
		std::cout<<"Get number of steps buggy not eating test passes\n"<<std::endl;
	}

	//tests num steps total for buggy
	bool ok15 = numStepsSurvivedBuggy();
	if(ok15){
		std::cout<<"Get number of steps buggy survived test passes\n"<<std::endl;
	}

	//tests set grid occupant
	bool ok16 = setGridOccupant();
	if(ok16){
		std::cout<<"Set grid occupant test passes\n"<<std::endl;
	}

	//tests get grid occupant
	bool ok17 = getGridOccupant();
	if(ok17){
		std::cout<<"Get grid occupant test passes\n"<<std::endl;
	}

	//tests get grid organism
	bool ok18 = getGridOrganism();
	if(ok18){
		std::cout<<"Get grid organism test passes\n"<<std::endl;
	}

	//tests get prey
	bool ok19 = getPrey();
	if(ok19){
		std::cout<<"Get prey test passes\n"<<std::endl;
	}

	//tests is prey
	bool ok20 = isPrey();
	if(ok20){
		std::cout<<"Is prey test passes\n"<<std::endl;
	}

	//tests get empty neighbor
	bool ok21 = getEmptyNeighbor();
	if(ok21){
		std::cout<<"Get empty neighbor test passes\n"<<std::endl;
	}

	//tests whether organism is prey
	bool ok22 = isPrey();
	if(ok22){
		std::cout<<"Is prey test passes\n"<<std::endl;
	}


	results = ok1 && ok2 && ok3 && ok4 && ok6 && ok7 && ok8 && ok9 && ok10
			&& ok11 && ok12 && ok13 && ok14 && ok15 && ok16 && ok17 && ok18 && ok19 && ok20
			&& ok21 && ok22;
	return results;
}

/**
 * This tests the cell.
 * @return true if all cell tests pass
 */
bool Tests2::cellTest(){
	bool ok = false;
	bool ok1 = false;
	bool ok2 = false;

	Ant* a1 = new Ant(2,3);
	Doodlebug* d1 = new Doodlebug(3,4);

	Cell* testCell1 = new Cell(a1);
	Cell* testCell2 = new Cell(d1);

	if(testCell1->getOccupant()==ant){
		ok1 = true;
	}

	if(testCell2->getOccupant()==doodlebug){
		ok2 = true;
	}

	ok = ok1 && ok2;
	delete a1;
	delete d1;

	return ok;

}

/**
 * Tests the getting of a cell occupant
 * @return true if test passes
 */
bool Tests2::testGetOccupant(){
	return true;
}

/**
 * Tests the setting of a cell occupant
 * @return true if test passes
 */
bool Tests2::testSetOccupant(){
	return true;
}

/**
 * Tests the getting of the organism in the cell
 * @return true if test passes
 */
bool Tests2::testGetOrganism(){
	return true;
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
 * Tests function that tracks number of steps a buggy goes without eating
 * @return true if test passes
 */
bool Tests2::numStepsNoEatingBuggy(){
	return true;
}

/**
 * Tests function that tracks number of steps buggy survives
 * @return true if test passes
 */
bool Tests2::numStepsSurvivedBuggy(){
	return true;
}

/**
 * Tests the get of the row buggy is in
 * @return true if test passes
 */
bool Tests2::getBuggyRow(){
	return true;
}

/**
 * Tests the get of the column the buggy is in
 * @return true if test passes
 */
bool Tests2::getBuggyCol(){
	return true;
}

/**
 * Tests the get of the occupant of specific cell in grid
 * @return true if test passes
 */
bool Tests2::getGridOccupant(){
	return true;
}

/**
 * Tests the set of the occupant of specific cell in grid
 * @return true if test passes
 */
bool Tests2::setGridOccupant(){
	return true;
}

/**
 * Tests the get of the organism of specific cell in grid
 * @return true if test passes
 */
bool Tests2::getGridOrganism(){
	return true;
}

/**
 * Tests the get of prey in a neighboring cell
 * @return true if test passes
 */
bool Tests2::getPrey(){
	//test with some neighboring cell having prey
	//test with no neighboring cells prey
	return true;
}

/**
 * Tests whether the organism in a cell is prey
 * @return true if test passes
 */
bool Tests2::isPrey(){
	return true;
}

/**
 * Tests the get of a neighboring empty cell
 * @return true if test passes
 */
bool Tests2::getEmptyNeighbor(){
	return true;
}

/**
 * Tests whether a cell is empty
 * @return true if test passes
 */
bool Tests2::isEmpty(){
	return true;
}

/**
 * This is the destructor for the testing class
 */
Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

