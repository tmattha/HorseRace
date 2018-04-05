/*
 * main.cpp
 *
 *  Created on: 04.04.2018
 *      Author: Tilmann
 */


#include "Horse.h"
#include "Race.h"
#include <list>
#include <iostream>
#include "Spectator.h"


int main(){

	Spectator singleSpectator;
	std::list<Horse*> participants;
	std::cout << "The participants\n----------------\n";
	for(int i=0; i<25; ++i){
		participants.push_back(new Horse());
		std::cout << participants.back()->getTime() << "\n";
	}

	singleSpectator.identify(participants);
	std::list<Horse*> proposal = singleSpectator.getFastestHorses();
	std::cout << "\nThe winners are:\n----------------\n";
	for(std::list<Horse*>::iterator it = proposal.begin(); it != proposal.end(); it++){
		std::cout << (*it)->getTime() << "\n";
	}


	while(!participants.empty()){
		delete(participants.front());
		participants.pop_front();
	}

	return 0;
}

