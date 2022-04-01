/*
	LSAnalogTrigger.h - Class to generate triggers from AnalogReadings
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 15th, 2018
*/

#pragma once

#include "Arduino.h"
#include "LSTrigger.h"
#include <LSSmooth.h>

class LSAnalogTrigger : public LSTrigger{
	LSSmooth smoother;
	int _threshold;
	int _envMax;
	int _envMin;

	public:
		LSAnalogTrigger(int ID, int inputPin):LSTrigger(ID, inputPin){};
		void callibrate(int threshold);
		void setThreshold(int threshold);
		void readnShoot(void (*f)(int,String));
		void printReading();
};