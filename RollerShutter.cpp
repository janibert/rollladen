#include "RollerShutter.h"

RollerShutter::RollerShutter(byte pin, unsigned long duration, DirectionControl directionControl) : _directionControl(directionControl) {
  _pin = pin;
  _duration = duration;
}

void RollerShutter::init(void) {
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  _moving = false;
}


void RollerShutter::goUp(void) {
  _directionControl.goUp();
  digitalWrite(_pin, HIGH);
  _start = millis();
  _moving = true;
}

void RollerShutter::goDown(void) {
  _directionControl.goDown();
  digitalWrite(_pin, HIGH);
  _start = millis();
  _moving = true;
}

void RollerShutter::goStop(void) {
  digitalWrite(_pin, LOW);
  _moving = false;
}

void RollerShutter::next(void) {
  unsigned long jetzt = millis();
  if (_moving && ((jetzt - _start) > _duration)) {
    goStop();
  }
}


