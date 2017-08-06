#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"
#include "RollerShutter.h"

#define ENTPRELL_ZEIT 20ul
#define SCHALTER_OFFEN LOW
#define SCHALTER_GESCHLOSSEN HIGH

class PushButton {
  public:
    PushButton(byte,RollerShutter,bool);
    void init(void);
    void next(void);

  private:
    byte _pin;
    bool _up;
    unsigned long _seit;
    RollerShutter _rollerShutter;
    enum Zustand { ungedrueckt, beruehert, gedrueckt, losgelassen } _zustand;
};

#endif

