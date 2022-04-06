#include <Arduino.h>
#include "LSDigitalTrigger.h"

#define N_TRIGGERS 5

#define ID_0 0
#define ID_1 1
#define ID_2 2
#define ID_3 3
#define ID_4 4

#define DIGITAL_PIN_0 0
#define DIGITAL_PIN_1 1 
#define DIGITAL_PIN_2 2
#define DIGITAL_PIN_3 3
#define DIGITAL_PIN_4 4

LSDigitalTrigger digitalTriggers[N_TRIGGERS] = {
  LSDigitalTrigger(ID_0, DIGITAL_PIN_0),
  LSDigitalTrigger(ID_1, DIGITAL_PIN_1),
  LSDigitalTrigger(ID_2, DIGITAL_PIN_2),
  LSDigitalTrigger(ID_3, DIGITAL_PIN_3),
  LSDigitalTrigger(ID_4, DIGITAL_PIN_4)
};

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
  for(LSDigitalTrigger trigger:digitalTriggers)
    trigger.readnShoot(actOnTrigger);
}