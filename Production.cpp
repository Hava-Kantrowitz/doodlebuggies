/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Victoria Bowen and Hava Kantrowitz
 */

#include "Production.h"
#include <iostream>
#include <cmath>
#include "Grid.h"
#include "Doodlebug.h"
#include "Ant.h"
#include <stdio.h>
#include <ctime>


/**
 * This is the constructor for the production method
 * @param argc the number of arguments on the command line
 * @param argv the array of arguments
 */
Production::Production(int argc, char* argv[]) {
	// checks if too many arguments (defaults set in header)
	if(argc > 7){
		std::cout<<"Too many arguments have been entered. Expects a max of 7 arguments. The arguments will be set to default."<<std::endl;
	}
	// if good number of arguments
	else {
		// checks if there are at least two arguments
		if (argc >= 2) {
			char* ptr = 0;
			long gS = strtol(argv[1], &ptr, 10);
			gridSize = (int) gS;
			// checking for valid grid size
			if(gridSize <= 0){
				std::cout<<"Invalid grid size entered. Set to default of 20."<<std::endl;
				gridSize = 20;
			}
		}
		// checks if there are at least three arguments
		if(argc >= 3){
			char* ptr2 = 0;
			long sd = strtol(argv[2], &ptr2, 10);
			startDoodle = (int) sd;
			// checking for valid doodle num
			if(startDoodle < 0){
				std::cout<<"Invalid starting doodle amount entered. Set to default of 5."<<std::endl;
				startDoodle = 5;
			}
		}
		// checks if there are at least four arguments
		if(argc >= 4){
			char* ptr3 = 0;
			long sa = strtol(argv[3], &ptr3, 10);
			startAnts = (int) sa;
			// checking for valid ant num
			if(startAnts < 0){
				std::cout<<"Invalid starting ant amount entered. Set to default of 100."<<std::endl;
				startAnts = 100;
			}
		}
		// checks if there are at least five arguments
		if(argc >=5){
			char* ptr4 = 0;
			long ts = strtol(argv[4], &ptr4, 10);
			timeSteps = (int) ts;
			// checking for valid timeSteps
			if(timeSteps < 0){
				std::cout<<"Invalid number of time steps entered. Set to default of 1000."<<std::endl;
				timeSteps = 1000;
			}
		}
		// checks if there are at least six arguments
		if(argc >= 6){
			char* ptr5 = 0;
			long s = strtol(argv[5], &ptr5, 10);
			seed = (int) s;
			// checking for valid seed input
			if(seed < 0){
				std::cout<<"Invalid seed entered. Set to default of 1."<<std::endl;
				seed = 1;
			}
		}
		// checks if there are seven arguments
		if(argc == 7){
			char* ptr6 = 0;
			long p = strtol(argv[6], &ptr6, 10);
			pausePrint = (int) p;
			// checking for valid pausePrint
			if(pausePrint < 0 || pausePrint > timeSteps){
				std::cout<<"Invalid pause and print value entered. Set to default of 0."<<std::endl;
				pausePrint = 0;
			}
		}
	}
	// check if too many organisms
	if(startAnts + startDoodle > gridSize*gridSize){
		std::cout<<"The grid was too small for the given number of organisms. Resizing the grid."<<std::endl;
		gridSize = ((int) (std::sqrt(startAnts + startDoodle))) + 1;

	}

}
/**
 * This is the method to run the actual production of the ants and doodlebugs
 * @return true if the production is successful
 */
bool Production::runProduction()
{
	// setting the random with the seed
	// checks if seed is zero
	if(seed == 0){
		srand(time(0));
	}
	// checks if the seed is another integer
	else{
		srand(seed);
	}


	std::cout<<"in the run production method"<<std::endl;
	bool result = true;
	// setting up the initial grid
	Grid* gridOfPlay = new Grid(gridSize);
	// this loops through all the ants
	for(int numA = 0; numA < startAnts; numA = numA+1){
		int randomRow = rand()%gridSize; // get a random row
		int randomCol = rand()%gridSize; // get a column column
		// keeps generating random cells until it reaches an empty one
		while(gridOfPlay->getCellOccupant(randomRow, randomCol) != empty){
			randomRow = rand()%gridSize;
			randomCol = rand()%gridSize;
		}
		// sets up the new cell occupant
		Organism* newAnt = new Ant(randomRow, randomCol);
		newAnt->setIsChecked(false);
		gridOfPlay->setCellOccupant(randomRow, randomCol, ant, newAnt);
	}

	// this loops through for all the doodlebugs
	for (int numD = 0; numD < startDoodle; numD = numD+1) {
		int randomRowD = rand() % gridSize; // get a random row
		int randomColD = rand() % gridSize; // get a column column
		// keeps generating random cells until it reaches an empty one
		while (gridOfPlay->getCellOccupant(randomRowD, randomColD) != empty) {
			randomRowD = rand() % gridSize;
			randomColD = rand() % gridSize;
		}
		// sets up the new cell occupant
		Organism* newDoodle = new Doodlebug(randomRowD, randomColD);
		newDoodle->setIsChecked(false);
		gridOfPlay->setCellOccupant(randomRowD, randomColD, doodlebug, newDoodle);

	}

	// this is to keep track of if it should terminate or not
	bool done = false;
	int additionalAnts = 0;   // keeping track of ants born
	int additionalDoodles = 0; // keeping track of doodles born
	int endAnts = 0;
	int endDoodles = 0;


	// this is the main loop for the game
	int i;
	for(i = 0; i <= timeSteps && !done; i++)
	{
		// prints out grids if the number of time steps is divisible by the printPause num
		// i is the current time step
		if(pausePrint > 0 && i%pausePrint == 0){
			std::cout<<"Time step: "<<i<<std::endl;
			gridOfPlay->printBoard();
			std::cout<<"Type enter to continue."<<std::endl;
			getc(stdin);
		}

		// setting them all false before starting
		for(int row = 0; row < gridSize; row++){
			for(int col = 0; col < gridSize; col++){
				// checks to make sure that the element is either an ant or a doodle
				if(!(gridOfPlay->getCellOccupant(row, col) == empty)){
					gridOfPlay->getCellOrganism(row, col)->setIsChecked(false);
				}
			}
		}

		//this is the for loop for all the doodle bugs
		//looping through the rows and the columns
		for(int currRow = 0; currRow < gridSize; currRow++){
			for(int currCol = 0; currCol < gridSize; currCol++){
				// checking that it is a doodlebug and that it has not already been checked
				Organism* currDoodle = (gridOfPlay->getCellOrganism(currRow, currCol)); // gets current doodle bug

				if(gridOfPlay->getCellOccupant(currRow, currCol) == doodlebug && !(currDoodle->getIsChecked())){
					currDoodle->setIsChecked(true);

					bool canMove = currDoodle->move(gridOfPlay); // moves the organism
					// sets the new row and column for the next function (if it moved successfully)
					int movedRow = currRow;
					int movedCol = currCol;
					if(canMove){
						movedRow = ((Doodlebug*)currDoodle)->getRow();
						movedCol = ((Doodlebug*)currDoodle)->getCol();
					}

					// checks if the doodle has starved
					if(((Doodlebug*)currDoodle)->getNumStepsNoEat() == 3){
						delete currDoodle;
						gridOfPlay->setCellOccupant(movedRow, movedCol, empty, NULL);
					}

					// checks if the doodle bug has been alive long enough to give birth
					else if(((Doodlebug*)currDoodle)->getNumStepsSurvive()>=8){
						bool canBreedDoodle = currDoodle->breed(gridOfPlay);
						// checks if the the breed was successful
						if(canBreedDoodle){
							additionalDoodles++;
						}
					}
				}
			}
		}

		// this is the loop for the ants
		// loops through the columns and the rows
		for(int currRow2 = 0; currRow2 < gridSize; currRow2++){
			for(int currCol2 = 0; currCol2 < gridSize; currCol2++){
				// getting the current
				Organism* currAnt = gridOfPlay->getCellOrganism(currRow2, currCol2);
				// checking if it is an ant and has not been checked yet
				if(gridOfPlay->getCellOccupant(currRow2, currCol2) == ant && !(currAnt->getIsChecked())){
					currAnt->setIsChecked(true);
					currAnt->move(gridOfPlay); // moves the ant
					// checks if the ant has survived enough to breed
					if(((Ant*)currAnt)->getNumStepsSurvive() >= 3){
						bool canBreed = currAnt->breed(gridOfPlay);
						// checks if it was able to breed
						if(canBreed){
							additionalAnts++;
						}
					}
				}
			}
		}
		// sets this back to zero so it can see how many ants and doodles are left
		endAnts = 0;
		endDoodles = 0;

		// check the termination conditions
		for(int lastRow = 0; lastRow < gridSize; lastRow++){
			for(int lastCol = 0; lastCol < gridSize; lastCol++){
				// this checks if it is a doodlebug
				if(gridOfPlay->getCellOccupant(lastRow, lastCol)== doodlebug ){
					endDoodles++;
				}
				else if(gridOfPlay->getCellOccupant(lastRow, lastCol)== ant){
					endAnts++;
				}
			}
		}

		// checking if either the ants or the doodlebugs are all gone
		if(endAnts == 0 || endDoodles == 0){
			done = true;
		}
	}

	// this is what is printed after termination
	std::cout<<"Command Line: \n";
	std::cout<<"Grid size: "<<gridSize<<std::endl;
	std::cout<<"Number of doodlebugs: "<<startDoodle<<std::endl;
	std::cout<<"Number of ants: "<<startAnts<<std::endl;
	std::cout<<"Number of time steps: "<<timeSteps<<std::endl;
	std::cout<<"Seed number: "<<seed<<std::endl;
	std::cout<<"Pause and print: "<<pausePrint<<std::endl;

	std::cout<<"\nFinal numbers"<<std::endl;
	std::cout<<"Number of steps simulated: "<<i-1<<std::endl;
	std::cout<<"Total number of ants: "<<startAnts + additionalAnts<<std::endl;
	std::cout<<"Ants remaining: "<<endAnts<<std::endl;
	std::cout<<"Total number of doodlebugs: "<<startDoodle + additionalDoodles<<std::endl;
	std::cout<<"Doodlebugs remaining: "<<endDoodles<<std::endl;
	std::cout<<"Final Configuration"<<std::endl;
	gridOfPlay->printBoard();


	return result;
}
/**
 * This is the destructor for the production method
 */
Production::~Production() {
	// TODO Auto-generated destructor stub
}

