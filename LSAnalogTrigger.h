/*
	LSAnalogTrigger.h - Class to generate triggers from AnalogReadings
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 15th, 2018
*/

#pragma once

#include "Arduino.h"
#include <LSSmooth.h>

class LSAnalogTrigger{
	LSSmooth smoother;
	int _ID;
	int _photoInput;
	int _photoRead;
	bool _state;
	bool _prevState;
	int _threshold;
	int _envMax;
	int _envMin;
	bool _shootGuard;
    int _coundGuardCycles;  
    int _countGuard;  
	
	
	public:
		LSAnalogTrigger(int ID, int photoInput);
		void callibrate(int threshold);
		void setThreshold(int threshold);
		void setCountGuard(int countGuardCycles);
		void readnShoot(void (*f)(int,String));
		void printReading();
		bool overThreshold();
};