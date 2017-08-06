#include "DirectionControl.h"

DirectionControl::DirectionControl(byte pin) {
  _pin = pin;
}

void DirectionControl::init(void) {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void DirectionControl::goUp(void) {
    digitalWrite(_pin, HIGH);
}

void DirectionControl::goDown(void) {
    digitalWrite(_pin, LOW);  
}


