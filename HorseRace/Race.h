/*
 * Race.h
 *
 *  Created on: 04.04.2018
 *      Author: Tilmann
 */



#ifndef RACE_H_
#define RACE_H_

#include <list>
#include "Horse.h"

class Race {
public:
	Race();
	virtual ~Race();
	void setHorses(std::list<Horse*> horseAssignment);
	void race();
	std::list<Horse*> getPlacement();
private:
	std::list<Horse*> horses;
};

#endif /* RACE_H_ */
