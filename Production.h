/*
 * Production.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
// the public method for the production class
class Production {
private:
	int gridSize = 20;
	int startDoodle = 5;
	int startAnts = 100;
	int timeSteps = 1000;
	int seed = 1;
	int pausePrint = 0;

public:
	Production(int argc, char* argv[]);
	bool runProduction();
	virtual ~Production();
};

#endif /* PRODUCTION_H_ */
