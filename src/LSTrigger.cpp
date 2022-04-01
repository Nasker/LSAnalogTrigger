/*
	LSgTrigger.h - Baseclass to generate triggers
	Created by Oscar Martínez Carmona @ RockinTechProjects, March 1, 2022
*/

#include "Arduino.h"
#include "LSTrigger.h"


LSTrigger::LSTrigger(int ID, int inputPin){
	_ID = ID;
	_inputPin = inputPin;
  	_countGuard=0;
  	_shootGuard=false;
  	_coundGuardCycles=2000;
}


void LSTrigger::setCountGuard(int countGuardCycles){
	_coundGuardCycles = countGuardCycles;
}

bool LSTrigger::overThreshold(){
	return _state;
}