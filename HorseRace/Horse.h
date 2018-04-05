/*
 * Horse.h
 *
 *  Created on: 04.04.2018
 *      Author: Tilmann
 */

#include <list>

#ifndef HORSE_H_
#define HORSE_H_
#define HorseList std::list<Horse*>

class Horse {
public:
	Horse();
	virtual ~Horse();
	float getTime() const;
	//Comparison of two horses by time.
	static bool compareHorsesByTime(const Horse* first, const Horse* second);
private:
	float time;
};

#endif /* HORSE_H_ */
