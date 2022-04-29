#include  <math.h>

// the setup function runs once when you press reset or power the board

int ultrasonic_distances[7] = {5, 5, 5, 5, 5, 5, 5};
const int ultrasonic_angles[] = {90, 225, 180, 135, 45, 0, 315};
double magnitud_vector, angle_vector;

void calculate_vector() {
  double vx = 0, vy = 0;
  double sum_vx = 0, sum_vy = 0;

  for (int i = 0; i < 7; i++) {
    vx = ultrasonic_distances[i] * cos(radians(ultrasonic_angles[i]));
    vy = ultrasonic_distances[i] * sin(radians(ultrasonic_angles[i]));
    sum_vx += vx;
    sum_vy += vy;
  }
  
  magnitud_vector = pow(pow(sum_vx, 2) + pow(sum_vy, 2), 0.5);
  double division = sum_vy / sum_vx;
  angle_vector = degrees(atan(division));

  if (angle_vector < 0) {
    angle_vector = angle_vector + 180; 
  }
  if (sum_vy < -0.01) {
    angle_vector = angle_vector + 180;
  }
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  calculate_vector();
  Serial.println(magnitud_vector);
  Serial.println(angle_vector );
}

// the loop function runs over and over again forever
void loop() {

}
