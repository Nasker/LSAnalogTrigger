#include <Arduino.h>
#include "LSDigitalTrigger.h"

#define DIGITAL_PIN 0
#define TRIGGER_ID 0

LSAnalogTrigger digitalTrigger(TRIGGER_ID, DIGITAL_PIN);

void actOnTrigger(int ID, String callbackString){
  Serial.printf("ID: %d, %s\n", ID, callbackString.c_str());
  /*
  Whatever you want to do when the trigger is fired
  */
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  digitalTrigger.readnShoot(actOnTrigger);
}