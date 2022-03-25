/*
	RTPPhotoDiodeTrigger.cpp - Class to generate triggers from PhotoDiodes
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 15th, 2018
*/

#include "Arduino.h"
#include "LSAnalogTrigger.h"


LSAnalogTrigger::LSAnalogTrigger(int ID, int photoInput){
	_ID = ID;
	_photoInput = photoInput;
  	_countGuard=0;
  	_shootGuard=false;
  	_coundGuardCycles=2000;
}

void LSAnalogTrigger::callibrate(int threshold){
  digitalWrite(12,HIGH);
 _envMax=0;
  _envMin=1023;
 while (millis() < 4000) {
    int sensorValue = analogRead(_photoInput);
    if (sensorValue > _envMax) {
      _envMax = sensorValue;
    }

    if (sensorValue < _envMin) {
      _envMin = sensorValue;
    }
 }
  _threshold = threshold;
}

void LSAnalogTrigger::setThreshold(int threshold){
	_threshold = threshold;
}

void LSAnalogTrigger::setCountGuard(int countGuardCycles){
	_coundGuardCycles = countGuardCycles;
}

void LSAnalogTrigger::readnShoot(void (*f)(int, String)){
  _photoRead = smoother.smooth(analogRead(_photoInput));
  if(_shootGuard) _countGuard++;

  if(_countGuard >= _coundGuardCycles){
      _shootGuard=false;
      _countGuard=0;
  }
 
  if(_photoRead > _threshold){
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
	Serial.print(_photoRead);
	Serial.print("\t");
}

bool LSAnalogTrigger::overThreshold(){
	return _state;
}