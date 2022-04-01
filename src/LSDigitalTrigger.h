/*
	LSDigitalTrigger.h - Class to generate triggers from DigitalReadings
	Created by Oscar Martínez Carmona @ RockinTechProjects, March 1st, 2022
*/

#pragma once

#include "Arduino.h"
#include "LSTrigger.h"

class LSDigitalTrigger : public LSTrigger{
public:
    LSDigitalTrigger(int ID, int inputPin):LSTrigger(ID, inputPin){
        pinMode(_inputPin, INPUT_PULLUP);
    };
    void readnShoot(void (*f)(int,String));
    void printReading();
};