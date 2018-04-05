/*
 * Race.cpp
 *
 *  Created on: 04.04.2018
 *      Author: Tilmann
 */

#include "Race.h"
#include "Horse.h"
#include <stdexcept>

Race::Race() {
	// TODO Auto-generated constructor stub

}

Race::~Race() {
	// TODO Auto-generated destructor stub
}

void Race::setHorses(std::list<Horse*> horseAssignment) {
	if(horseAssignment.size() > 5)
		throw std::invalid_argument("Only 5 horses are allowed!");
	horses = horseAssignment;
}

void Race::race() {
	horses.sort(Horse::compareHorsesByTime);
}

std::list<Horse*> Race::getPlacement() {
	return horses;
}
