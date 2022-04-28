#include  <math.h>

// the setup function runs once when you press reset or power the board

int ultrasonic_distances[7] = {5, 5, 5, 5, 5, 5, 5};
const int ultasonic_angles[] = {90, 225, 180, 135, 45, 0, 315};
double magnitud_vector, angle_vector;

void calculate_vector() {
  magnitud_vector = 5;
  
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  Serial.println(magnitud_vector);
  calculate_vector();
  Serial.println(magnitud_vector);
}

// the loop function runs over and over again forever
void loop() {

}