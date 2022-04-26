#include "Arduino.h"
#include "ServoController.h"

ServoController::ServoController() {
  clawPos = 0;
  gripPos = 0;
  trayPos = 0;
}

void ServoController::init() {
  servoDriver = Adafruit_PWMServoDriver(0x40);
  servoDriver.begin();
  servoDriver.setOscillatorFrequency(27000000);
  servoDriver.setPWMFreq(SERVO_FREQ);

  moveMotors(0, 0, 1, 1);
  moveMotors(1, 30, 1, 1);
  //moveMotors(2, 0, 1, 1);
}

// Funcion que mueve todos los motores, abstraccion para no repetir ciclos for por todas partes
// pairMotors es la pareja de motores [0,1,2] 0 garra, 1 tapa, 2 pinza
// initialPos es la posicion actual del motor de la izquierda de la pareja de motores[0-180]
// steps es la cantidad de grados que se debe mover el motor[0-180]
// dir es la direccion del motor [1,-1] 1 es hacia arriba, -1 es hacia abajo
int ServoController::moveMotors(int pairMotors, int initialPos, int steps, int dir) {
  int pos = initialPos;
  int realPos1, realPos2;
  for (int i = 0; i < steps; i++) {
    realPos1 = map(pos, 0, 180, SERVOMIN, SERVOMAX);
    realPos2 = SERVOMAX - realPos1;
    servoDriver.setPWM(pairMotors * 2    , 0, realPos1);
    servoDriver.setPWM(pairMotors * 2 + 1, 0, realPos2);
    pos += dir;
  }

  return pos;
}

void ServoController::moveClawUp(int steps) {
  clawPos = moveMotors(0, clawPos, steps, 1);

  clawState = !clawState;
}

void ServoController::moveClawDown(int steps) {
  clawPos = moveMotors(0, clawPos, steps, -1);

  clawState = !clawState;
}

void ServoController::moveClaw(int steps) {
  if (clawState)
    moveClawDown(steps);
  else
    moveClawUp(steps);
}

void ServoController::moveTrayUp(int steps) {
  trayPos = moveMotors(1, trayPos, steps, 1);

  trayState = !trayState;
}

void ServoController::moveTrayDown(int steps) {
  trayPos = moveMotors(1, trayPos, steps, -1);

  trayState = !trayState;
}

void ServoController::moveTray(int steps) {
  if (trayState)
    moveTrayDown(steps);
  else
    moveTrayUp(steps);
}

void ServoController::moveGripUp(int steps) {
  gripPos = moveMotors(2, gripPos, steps, 1);

  gripState = !gripState;
}

void ServoController::moveGripDown(int steps) {
  gripPos = moveMotors(2, gripPos, steps, -1);

  gripState = !gripState;
}

void ServoController::moveGrip(int steps) {
  if (gripState)
    moveGripUp(steps);
  else
    moveGripDown(steps);
}
