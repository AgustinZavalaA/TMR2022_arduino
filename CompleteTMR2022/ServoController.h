#ifndef ServoController_h
#define ServoController_h

#include "Arduino.h"
#include <Adafruit_PWMServoDriver.h>  // servo Driver library

// Servo Driver
#define SERVOMIN 120   // default = 120, This is the 'minimum' pulse length
#define SERVOMAX 510   // default = 510, This is the 'maximum' pulse length
#define SERVO_FREQ 50  // default = 50,  Analog servos run at ~50 Hz updates

class ServoController
{
  private:
    Adafruit_PWMServoDriver servoDriver;
    int clawPos, gripPos, trayPos;

  public:
    bool clawState, gripState, trayState;

    ServoController();
    void init();
    int moveMotors(int, int, int, int);
    void moveClawUp(int);
    void moveClawDown(int);
    void moveClaw(int);
    void moveTrayUp(int);
    void moveTrayDown(int);
    void moveTray(int);
    void moveGripUp(int);
    void moveGripDown(int);
    void moveGrip(int);
};

#endif
