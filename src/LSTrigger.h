/*
	LSgTrigger.h - Baseclass to generate triggers
	Created by Oscar Martínez Carmona @ RockinTechProjects, March 1, 2022
*/

#pragma once

#include "Arduino.h"

class LSTrigger{
protected:
	int _ID;
	int _inputPin;
	int _reading;
	bool _state;
	bool _prevState;
	int _threshold;
	bool _shootGuard;
    int _coundGuardCycles;  
    int _countGuard;  
	
public:
    LSTrigger(int ID, int inputPin);
    void setCountGuard(int countGuardCycles);
    virtual void readnShoot(void (*f)(int,String))=0;
    virtual void printReading()=0;
    bool overThreshold();
};