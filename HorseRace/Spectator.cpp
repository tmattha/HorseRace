/*
 * Spectator.cpp
 *
 *  Created on: 04.04.2018
 *      Author: Tilmann
 */

#include "Spectator.h"
#include <stdexcept>
#include <iostream>

Spectator::Spectator() {
	// TODO Auto-generated constructor stub

}

Spectator::~Spectator() {
	// TODO Auto-generated destructor stub

}

void Spectator::identify(HorseList horses) {
	Race arena;
	//Ensure 25 horses were provided.
	if (horses.size() != 25)
		throw std::invalid_argument("It has to be 25 horses.");

	//Pool of horses competing
	std::list<HorseList*> horseGroups;

	/*
	 * Identification Strategy
	 */
	//Make groups of 5 horses

	for(HorseList::iterator it = horses.begin(); it != horses.end(); ){
		horseGroups.push_back(new HorseList());
		for(int i = 0; i < 5; i++){
			horseGroups.back()->push_back((*it));
			++it;
		}
	};
	HorseList winners;
	//Race all groups and collect the winners.
	for(std::list<HorseList*>::iterator it = horseGroups.begin(); it != horseGroups.end(); it++){
		arena.setHorses((**it));
		arena.race();
		(**it)=arena.getPlacement();
		winners.push_back((**it).front());

	}
	arena.setHorses(winners);
	arena.race();
	winners=arena.getPlacement();
	fastestHorses.clear();
	fastestHorses.push_back(winners.front());
	//Order groups by winners race results.

	for(HorseList::iterator itWinners = winners.begin(); itWinners != winners.end(); itWinners++){
		for(std::list<HorseList*>::iterator itGroups = horseGroups.begin(); itGroups != horseGroups.end(); ++itGroups){
			if((**itGroups).front() == (*itWinners)){
				horseGroups.push_back(*itGroups);
				itGroups = horseGroups.erase(itGroups);
				break;
			}
		}
	}

	//Collect all the horses that could still be 2nd or 3rd.
	HorseList consolidation;
	std::list<HorseList*>::iterator itGroups = horseGroups.begin();
	HorseList::iterator itHorses = (*itGroups)->begin();
	itHorses++;
	consolidation.push_back((*itHorses));
	itHorses++;
	consolidation.push_back((*itHorses));
	itGroups++;
	itHorses = (*itGroups)->begin();
	consolidation.push_back((*itHorses));
	itHorses++;
	consolidation.push_back((*itHorses));
	itGroups++;
	consolidation.push_back((*itGroups)->front());

	//Race these horses to identify the 2nd and 3rd place.
	arena.setHorses(consolidation);
	arena.race();
	consolidation = arena.getPlacement();
	itHorses = consolidation.begin();
	for(int i = 0; i < 2; i++){
		fastestHorses.push_back((*itHorses));
		itHorses++;
	}

	//Clean up dynamic references to the grouped horses.
	while(!horseGroups.empty()){
		delete(horseGroups.front());
		horseGroups.pop_front();
	}

}

HorseList Spectator::getFastestHorses() {
	return fastestHorses;
}


