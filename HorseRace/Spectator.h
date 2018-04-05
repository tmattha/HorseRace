/*
 * Spectator.h
 *
 *  Created on: 04.04.2018
 *      Author: Tilmann
 */

#include <list>
#include "Horse.h"
#include "Race.h"

#ifndef SPECTATOR_H_
#define SPECTATOR_H_

class Spectator {
public:
	Spectator();
	virtual ~Spectator();
	void identify(std::list<Horse*> horses);
	std::list<Horse*> getFastestHorses();
private:

	//Top 3 fastest horses.
	std::list<Horse*> fastestHorses;
};

#endif /* SPECTATOR_H_ */
