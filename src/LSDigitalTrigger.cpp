/*
	RTPPhotoDiodeTrigger.cpp - Class to generate triggers from PhotoDiodes
	Created by Oscar Martínez Carmona @ RockinTechProjects, October 15th, 2018
*/

#include "Arduino.h"
#include "LSDigitalTrigger.h"

void LSDigitalTrigger::readnShoot(void (*f)(int, String)){
  _reading = digitalRead(_inputPin);
  if(_shootGuard) _countGuard++;

  if(_countGuard >= _coundGuardCycles){
      _shootGuard=false;
      _countGuard=0;
  }
  _state = _reading;
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

void LSDigitalTrigger::printReading(){
	Serial.print(_reading);
	Serial.print("\t");
}