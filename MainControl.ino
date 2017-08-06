#include <Controllino.h>
#include "Arduino.h"

#include "DirectionControl.h"
#include "RollerShutter.h"
#include "PushButton.h"


DirectionControl directionControl(CONTROLLINO_D9);
RollerShutter rollerShutter(CONTROLLINO_D0,30000,directionControl);
PushButton pbUp(CONTROLLINO_A0,rollerShutter,false);
PushButton pbDown(CONTROLLINO_A1,rollerShutter,true);

void setup() {
  directionControl.init();
  rollerShutter.init();
  pbUp.init();
  pbDown.init();
}

void loop() {
  rollerShutter.next();
  pbUp.next();
  pbDown.next();
}

