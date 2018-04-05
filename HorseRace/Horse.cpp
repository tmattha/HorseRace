/*
 * Horse.cpp
 *
 *  Created on: 04.04.2018
 *      Author: Tilmann
 */

#include "Horse.h"
#include "main.h"
#include <random>
#include "RandomNumberGenerator.h"

Horse::Horse() {

	time = random.getRandomFloat(10.0f, 30.0f);
}

Horse::~Horse() {
	// TODO Auto-generated destructor stub
}

float Horse::getTime() const{
	return time;
}

bool Horse::compareHorsesByTime(const Horse* first, const Horse* second) {
	return (first->getTime()<second->getTime());
}
