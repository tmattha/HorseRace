/*
 * RandomNumberGenerator.cpp
 *
 *  Created on: 04.04.2018
 *      Author: Tilmann
 */

#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator() {
	// TODO Auto-generated constructor stub


}

RandomNumberGenerator::~RandomNumberGenerator() {
	// TODO Auto-generated destructor stub
}

float RandomNumberGenerator::getRandomFloat(float lowerBound, float upperBound) {
	std::uniform_real_distribution<float> distribution (lowerBound, upperBound);
	return distribution(generator);
}

int RandomNumberGenerator::getRandomInt(int lowerBound, int upperBound) {
	std::uniform_int_distribution<int> distribution (lowerBound, upperBound);
	return distribution(generator);
}
