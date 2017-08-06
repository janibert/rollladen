#ifndef DirectionControl_h
#define DirectionControl_h

#include "Arduino.h"

class DirectionControl {
  public:
    DirectionControl(byte);
    void init(void);
    void goUp(void);
    void goDown(void);
  private:
    byte _pin;
};

#endif

