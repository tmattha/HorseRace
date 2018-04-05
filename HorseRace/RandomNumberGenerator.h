/*
 * RandomNumberGenerator.h
 *
 *  Created on: 04.04.2018
 *      Author: Tilmann
 */
#include <random>

#ifndef RANDOMNUMBERGENERATOR_H_
#define RANDOMNUMBERGENERATOR_H_


class RandomNumberGenerator {
public:
	RandomNumberGenerator();
	virtual ~RandomNumberGenerator();
	float getRandomFloat(float lowerBound, float upperBound);
	int getRandomInt(int lowerBound, int upperBound);
private:
	std::default_random_engine generator;
};

#endif /* RANDOMNUMBERGENERATOR_H_ */
