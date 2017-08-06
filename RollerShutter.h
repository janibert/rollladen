#ifndef RollerShutter_h
#define RollerShutter_h

#include "Arduino.h"
#include "DirectionControl.h"

class RollerShutter {
  public:
    RollerShutter(byte,unsigned long,DirectionControl);
    void init(void); // setting pinMode and go to initial position
    void next(void);
    void goUp(void);
    void goDown(void);
    void goStop(void);
  private:
    byte _pin;
    unsigned long _duration; // Dauer fÃ¼r komplette Bewegung von Endpunkt zu Endpunkt
    unsigned long _start; 
    DirectionControl _directionControl;
    bool _moving;
};

#endif

