#include <Servo.h>

Servo servo_1; // servo controller (multiple can exist)

int servo_pin = 3; // PWM pin for servo control
int pos = 0;    // servo starting position

void setup() {
  servo_1.attach(servo_pin); // start servo control
  Serial.begin(9600); // start serial monitor
  servo_1.write(pos); // move servo to 0 degrees
}

void loop() {
  if (Serial.available()){
    String in_char = Serial.readStringUntil('\n'); // read until the newline
    Serial.print("Moving to: ");
    Serial.print(in_char);
    Serial.println(" Degrees");
    servo_1.write(in_char.toInt()); // convert angle and write servo
    //delay(in_char.toFloat()*(10.0/6.0)); // delay for maximum speed
  }
  //delay(100);
}
