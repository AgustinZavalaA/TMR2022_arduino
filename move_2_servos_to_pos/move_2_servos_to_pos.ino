#include <Servo.h>

Servo servo_1; // servo controller (multiple can exist)
Servo servo_2;

int servo_pin_1 = 3, servo_pin_2 = 5; // PWM pin for servo control
int pos = 0;    // servo starting position
int sentido_inverso = 1; // cambia para mover los motores en el mismo sentido 
int aux;

void setup() {
  servo_1.attach(servo_pin_1); // start servo control
  servo_2.attach(servo_pin_2);
  Serial.begin(9600); // start serial monitor
  servo_1.write(pos); // move servo to 0 degrees
  servo_2.write(pos);

  Serial.println("Sentido " + sentido_inverso ? "INVERSO" : "NO INVERSO");
  aux = sentido_inverso ? 180 : 0;
}

void loop() {
  if (Serial.available()){
    String in_char = Serial.readStringUntil('\n'); // read until the newline
    Serial.print("-> ");
    Serial.print(in_char);
    Serial.println(" °");
    servo_1.write(in_char.toInt()); // convert angle and write servo
    servo_2.write(abs(180 - in_char.toInt())); // convert angle and write servo
    //delay(in_char.toFloat()*(10.0/6.0)); // delay for maximum speed
  }
  //delay(100);
}
