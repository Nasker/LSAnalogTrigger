/*
	RTPPhotoDiodeTrigger.cpp - Class to generate triggers from PhotoDiodes
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 15th, 2018
*/

#include "Arduino.h"
#include "LSAnalogTrigger.h"


void LSAnalogTrigger::callibrate(int threshold){
  _envMax = 0;
  _envMin = 1023;
 while (millis() < 4000) {
    int sensorValue = analogRead(_inputPin);
    if (sensorValue > _envMax) {
      _envMax = sensorValue;
    }

    if (sensorValue < _envMin) {
      _envMin = sensorValue;
    }
 }
  _threshold = threshold;
}

void LSAnalogTrigger::readnShoot(void (*f)(int, String)){
  _reading = smoother.smooth(analogRead(_inputPin));
  if(_shootGuard) _countGuard++;

  if(_countGuard >= _coundGuardCycles){
      _shootGuard=false;
      _countGuard=0;
  }
 
  if(_reading > _threshold){
      _state = true;  
    }
    else{
      _state = false;
   }
  
  if(_state != _prevState){
    if((_state)&&(!_shootGuard)){
      (*f)(_ID,"ON");
      _shootGuard=true;
      _countGuard=0; 
    }
    if(!_state){
      (*f)(_ID,"OFF");
    }
    _prevState = _state;
  }
}

void LSAnalogTrigger::printReading(){
	Serial.print(_reading);
	Serial.print("\t");
}

bool LSAnalogTrigger::overThreshold(){
	return _state;
}