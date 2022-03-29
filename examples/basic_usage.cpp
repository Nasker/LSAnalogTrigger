#include <Arduino.h>
#include "LSAnalogTrigger.h"

#define ANALOG_PIN 13
#define TRIGGER_ID 0

LSAnalogTrigger analogTrigger(TRIGGER_ID, ANALOG_PIN);

const int thresholdValue = 1000;

void actOnTrigger(int ID, String callbackString){
  Serial.printf("ID: %d, %s\n", ID, callbackString.c_str());
  /*
  Whatever you want to do when the trigger is fired
  */
}

void setup() {
  Serial.begin(115200);
  analogTrigger.setThreshold(thresholdValue);
}

void loop() {
  analogTrigger.readnShoot(actOnTrigger);
}