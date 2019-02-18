/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Hava Kantrowitz
 */

#include "Production.h"

int timestepsLeft=100;


/**
 * Constructs the production class
 */
Production::Production(int argc, char* argv[]) {
	// TODO Auto-generated constructor stub
	int timestepsLeft = 100; //initialize available timesteps
}

/**
 * Runs production
 * @return true if production is still running, false otherwise
 */
bool Production::runProduction()
{
	bool result = true;
	while(timestepsLeft-- > 0)
	{
		//dbs.step;
		//ants.step;

		//call the doodlebug move
		//if steps are 8 or more, call the buggy breed

		//call the ant move
		//if steps are 3 or more, call ant breed
	}
	return result;
}

/**
 * Destructs production class
 */
Production::~Production() {
	// TODO Auto-generated destructor stub
}

