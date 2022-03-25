/*
	LSSmooth.h - Class for smoothing analog readings.
	Created by Oscar Martínez Carmona @ RockinTechProjects, February 3, 2016.
*/

#pragma once

#include "Arduino.h"

const int _numReadings = 20;

class LSSmooth{
int _readings[_numReadings]; 
int _readIndex;              
int _total;                
int _average;   
	
	public:
		LSSmooth();
		int smooth(int inputValue);
};