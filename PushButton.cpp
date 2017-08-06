#include "PushButton.h"
#include "RollerShutter.h"

PushButton::PushButton(byte pin,RollerShutter rollerShutter,bool up) : _rollerShutter(rollerShutter) {
  _pin = pin;
  _up = up;
};

void PushButton::init(void) {
    pinMode(_pin, INPUT);
    _zustand = ungedrueckt;
}

void PushButton::next(void) {
  byte schalterPosition = digitalRead(_pin);
  unsigned long jetzt = millis();
  switch(_zustand) {
    case ungedrueckt:
      if(schalterPosition == SCHALTER_GESCHLOSSEN) {
        _zustand = beruehert;
        _seit = jetzt;
      }
      break;
    case beruehert:
      if(schalterPosition == SCHALTER_OFFEN) {
        _zustand = ungedrueckt;
      } else if((jetzt - _seit) > ENTPRELL_ZEIT) {
        _zustand = gedrueckt;
        if(_up) {
          _rollerShutter.goUp();
        } else {
          _rollerShutter.goDown();
        }
      }
      break;      
    case gedrueckt:
      if(schalterPosition == SCHALTER_OFFEN) {
        _zustand = losgelassen;
        _seit = jetzt;
      }
      break;
    case losgelassen:
      if(schalterPosition == SCHALTER_GESCHLOSSEN) {
        if((jetzt - _seit) < ENTPRELL_ZEIT) {
          _zustand = gedrueckt;
        }
      } else if((jetzt - _seit) > ENTPRELL_ZEIT) {
        _zustand = ungedrueckt;
      }
      break;
  }
}


