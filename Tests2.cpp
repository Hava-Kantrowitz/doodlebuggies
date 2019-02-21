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

	//test the get of the buggy's row
	bool ok16 = getBuggyRow();
	if(ok16){
		std::cout<<"Get buggy row test passes\n"<<std::endl;
	}

	//test the get of the buggy's column
	bool ok17 = getBuggyCol();
	if(ok17){
		std::cout<<"Get buggy column test passes\n"<<std::endl;
	}

	//tests set and get of grid occupant
	bool ok18 = gridOccupant();
	if(ok18){
		std::cout<<"Grid occupant test passes\n"<<std::endl;
	}

	//tests get grid organism
	bool ok19 = getGridOrganism();
	if(ok19){
		std::cout<<"Get grid organism test passes\n"<<std::endl;
	}

	//tests get prey
	bool ok20 = getPrey();
	if(ok20){
		std::cout<<"Get prey test passes\n"<<std::endl;
	}

	//tests is prey
	bool ok21 = isPrey();
	if(ok21){
		std::cout<<"Is prey test passes\n"<<std::endl;
	}

	//tests get empty neighbor
	bool ok22 = getEmptyNeighbor();
	if(ok22){
		std::cout<<"Get empty neighbor test passes\n"<<std::endl;
	}

	//tests whether organism is prey
	bool ok23 = isPrey();
	if(ok23){
		std::cout<<"Is prey test passes\n"<<std::endl;
	}

	//tests that an organism can be set to ant
	bool ok24 = testSetAnt();
	if(ok24){
		std::cout<<"Set ant test passes\n"<<std::endl;
	}

	//tests the set and get of a checked organism
	bool ok25 = testChecked();
	if(ok25){
		std::cout<<"Set and get checked organism test passes\n"<<std::endl;
	}


	results = ok1 && ok2 && ok3 && ok4 && ok6 && ok7 && ok8 && ok9 && ok10
			&& ok11 && ok12 && ok13 && ok14 && ok15 && ok16 && ok17 && ok18 && ok19 && ok20
			&& ok21 && ok22 && ok23 && ok24 && ok25;
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

	std::cout<<"\nRunning the cell test"<<std::endl;

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
	delete testCell1;
	delete testCell2;

	return ok;

}

/**
 * Tests the getting of a cell occupant
 * @return true if test passes
 */
bool Tests2::testGetOccupant(){
	std::cout<<"Running get cell occupant test"<<std::endl;
	bool ok = false;

	Ant* a1 = new Ant(2,3);
	Cell* testCell = new Cell(a1);

	if(testCell->getOccupant() == ant){
		ok = true;
	}

	delete a1;
	delete testCell;

	return ok;
}

/**
 * Tests the setting of a cell occupant
 * @return true if test passes
 */
bool Tests2::testSetOccupant(){
	std::cout<<"Running set cell occupant test"<<std::endl;
	bool ok = false;

	Doodlebug* d1 = new Doodlebug();
	Cell* testCell = new Cell();

	testCell->setOccupant(doodlebug, d1);
	if(testCell->getOccupant() == doodlebug){
		ok = true;
	}

	delete d1;
	delete testCell;
	return ok;
}

/**
 * Tests the getting of the organism in the cell
 * @return true if test passes
 */
bool Tests2::testGetOrganism(){
	std::cout<<"Running get cell organism test"<<std::endl;
	bool ok = false;

	Doodlebug* d1 = new Doodlebug();
	Cell* testCell = new Cell(d1);

	if(testCell->getOrganism()->isPrey()==false){
		ok = true;
	}

	delete d1;
	delete testCell;
	return ok;
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
	delete numStepsAnt;
	delete myGrid;

	return result;
}

/**
 * Tests function that tracks number of steps a buggy goes without eating
 * @return true if test passes
 */
bool Tests2::numStepsNoEatingBuggy(){
	bool ok = false;

	std::cout<<"Running the number of steps buggy doesn't eat test."<< std::endl;
	Grid* myGrid = new Grid(9);
	Doodlebug* stepBuggy = new Doodlebug(1, 3);
	stepBuggy->move(myGrid);
	stepBuggy->move(myGrid);
	stepBuggy->move(myGrid);

	if(stepBuggy->getNumStepsNoEat() == 3){
		ok = true;
	}

	delete stepBuggy;
	delete myGrid;

	return ok;
}

/**
 * Tests function that tracks number of steps buggy survives
 * @return true if test passes
 */
bool Tests2::numStepsSurvivedBuggy(){
	bool ok = false;

	std::cout<<"Running the number of steps buggy survived test."<< std::endl;
	Grid* myGrid = new Grid(9);
	Doodlebug* stepBuggy = new Doodlebug(1, 3);
	stepBuggy->move(myGrid);
	stepBuggy->move(myGrid);
	stepBuggy->move(myGrid);

	if(stepBuggy->getNumStepsSurvive() == 3){
		ok = true;
	}

	delete stepBuggy;
	delete myGrid;

	return ok;
}

/**
 * Tests the get of the row buggy is in
 * @return true if test passes
 */
bool Tests2::getBuggyRow(){
	bool ok = false;
	std::cout<<"Running the get buggy row test."<<std::endl;

	Doodlebug* myBug = new Doodlebug(2, 4);

	if(myBug->getRow() == 2){
		ok = true;
	}

	delete myBug;
	return ok;
}

/**
 * Tests the get of the column the buggy is in
 * @return true if test passes
 */
bool Tests2::getBuggyCol(){
	bool ok = false;
	std::cout<<"Running the get buggy column test."<<std::endl;

	Doodlebug* myBug = new Doodlebug(2, 4);

	if(myBug->getCol() == 4){
		ok = true;
	}

	delete myBug;
	return ok;
}

/**
 * Tests the get and set of the occupant of specific cell in grid
 * @return true if test passes
 */
bool Tests2::gridOccupant(){
	bool ok = false;
	std::cout<<"Running grid occupant test"<<std::endl;

	Grid* myGrid = new Grid(9);
	Doodlebug* gridBuggy = new Doodlebug();
	myGrid->setCellOccupant(2, 4, doodlebug, gridBuggy);
	if(myGrid->getCellOccupant(2, 4) == doodlebug){
		ok = true;
	}

	delete myGrid;
	delete gridBuggy;
	return ok;
}

/**
 * Tests the get of the organism of specific cell in grid
 * @return true if test passes
 */
bool Tests2::getGridOrganism(){
	bool ok = false;
	std::cout<<"Running get grid organism test"<<std::endl;

	Grid* myGrid = new Grid(9);
	Doodlebug* gridBuggy = new Doodlebug();
	myGrid->setCellOccupant(2, 4, doodlebug, gridBuggy);
	if(myGrid->getCellOrganism(2, 4)->isPrey()==false){
		ok = true;
	}

	delete myGrid;
	delete gridBuggy;
	return ok;
}

/**
 * Tests the get of prey in a neighboring cell
 * @return true if test passes
 */
bool Tests2::getPrey(){
	bool ok = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	std::cout<<"Running get neighboring prey cells test"<<std::endl;

	Grid* myGrid1 = new Grid(9);
	Doodlebug* buggy1 = new Doodlebug(4, 4);
	Ant* ant1 = new Ant(4, 5);
	Ant* ant2 = new Ant(3, 4);
	myGrid1->setCellOccupant(4, 4, doodlebug, buggy1);
	myGrid1->setCellOccupant(4, 5, ant, ant1);
	myGrid1->setCellOccupant(3, 4, ant, ant2);

	Grid* myGrid2 = new Grid(9);
	Doodlebug* buggy2 = new Doodlebug(4, 5);
	myGrid2->setCellOccupant(4, 4, doodlebug, buggy1);
	myGrid2->setCellOccupant(5, 4, doodlebug, buggy2);

	Grid* myGrid3 = new Grid(9);
	myGrid3->setCellOccupant(4, 4, doodlebug, buggy1);
	myGrid3->setCellOccupant(4, 5, ant, ant1);

	//test with multiple neighboring cells prey
	if(myGrid1->getPrey(4,4)==4 || myGrid1->getPrey(4,4)==2){
		ok1 = true;
	}

	//test with no neighboring cells prey
	if(myGrid2->getPrey(4, 4)==-1){
		ok2 = true;
	}

	//test with one neighboring cell prey
	if(myGrid3->getPrey(4, 4)==4){
		ok3 = true;
	}

	ok = ok1 && ok2 && ok3;
	myGrid1->~Grid();
	myGrid2->~Grid();
	myGrid3->~Grid();
	return ok;
}

/**
 * Tests whether the organism in a cell is prey
 * @return true if test passes
 */
bool Tests2::isPrey(){
	bool ok = false;
	bool ok1 = false;
	bool ok2 = false;
	std::cout<<"Running the is prey test"<<std::endl;

	Grid* aGrid = new Grid(9);
	Doodlebug* buggy = new Doodlebug();
	Ant* anty = new Ant(2, 4);
	aGrid->setCellOccupant(3, 5, doodlebug, buggy);
	aGrid->setCellOccupant(2, 4, ant, anty);

	if(aGrid->isPrey(3, 5)==false){
		ok1 = true;
	}

	if(aGrid->isPrey(2, 4)==true){
		ok2 = true;
	}

	ok = ok1 && ok2;
	aGrid->~Grid();
	return ok;
}

/**
 * Tests the get of a neighboring empty cell
 * @return true if test passes
 */
bool Tests2::getEmptyNeighbor(){
	bool ok = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	std::cout<<"Running get neighboring empty cells test"<<std::endl;

	Grid* myGrid1 = new Grid(9);
	Doodlebug* buggy1 = new Doodlebug(4, 4);
	Ant* ant1 = new Ant(4, 5);
	Ant* ant2 = new Ant(3, 4);
	myGrid1->setCellOccupant(4, 4, doodlebug, buggy1);
	myGrid1->setCellOccupant(4, 5, ant, ant1);
	myGrid1->setCellOccupant(3, 4, ant, ant2);

	Grid* myGrid2 = new Grid(9);
	Doodlebug* buggy2 = new Doodlebug(4, 5);
	Doodlebug* buggy3 = new Doodlebug(4, 3);
	Doodlebug* buggy4 = new Doodlebug(5, 4);
	Doodlebug* buggy5 = new Doodlebug(3, 4);
	myGrid2->setCellOccupant(4, 4, doodlebug, buggy1);
	myGrid2->setCellOccupant(4, 5, doodlebug, buggy2);
	myGrid2->setCellOccupant(4, 3, doodlebug, buggy3);
	myGrid2->setCellOccupant(5, 4, doodlebug, buggy4);
	myGrid2->setCellOccupant(3, 4, doodlebug, buggy5);

	Grid* myGrid3 = new Grid(9);
	myGrid3->setCellOccupant(4, 4, doodlebug, buggy1);
	myGrid3->setCellOccupant(4, 5, ant, ant1);
	myGrid3->setCellOccupant(4, 3, doodlebug, buggy3);
	myGrid3->setCellOccupant(5, 4, doodlebug, buggy4);


	//test with multiple neighboring cells empty
	if(myGrid1->getEmptyNeighbor(4, 4)==3 || myGrid1->getEmptyNeighbor(4,4)==1){
		ok1 = true;
	}

	//test with no neighboring cells empty
	if(myGrid2->getEmptyNeighbor(4, 4)==-1){
		ok2 = true;
	}

	//test with one neighboring cell empty
	if(myGrid3->getEmptyNeighbor(4, 4)==2){
		ok3 = true;
	}

	ok = ok1 && ok2 && ok3;
	myGrid1->~Grid();
	myGrid2->~Grid();
	myGrid3->~Grid();
	return ok;
}

/**
 * Tests whether a cell is empty
 * @return true if test passes
 */
bool Tests2::isEmpty(){
	bool ok = false;
	std::cout<<"Running the is cell empty test"<<std::endl;

	Grid* emptyGrid = new Grid(9);
	if(emptyGrid->isEmpty(2, 4)==true){
		ok = true;
	}
	emptyGrid->~Grid();
	return ok;
}

/**
 * Tests that an organism can be set to ant
 * @return true if test passes
 */
bool Tests2::testSetAnt(){
	bool ok = false;
	std::cout<<"Running set ant test"<<std::endl;
	Organism* anAnt = new Doodlebug();
	anAnt->setAmAnt(true);

	if(anAnt->isPrey()==true){
		ok = true;
	}

	anAnt->~Organism();
	return ok;
}

/**
 * Tests that an organism can be set and get checked
 * @return true if test passes
 */
bool Tests2::testChecked(){
	bool ok = false;
	std::cout<<"Running set and get checked test"<<std::endl;

	Organism* buggy = new Doodlebug();
	buggy->setIsChecked(true);

	if(buggy->getIsChecked()==true){
		ok = true;
	}

	return ok;
}

/**
 * This is the destructor for the testing class
 */
Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

