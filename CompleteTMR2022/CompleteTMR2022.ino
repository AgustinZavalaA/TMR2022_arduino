// Libraries
#include <Adafruit_GFX.h>             // OLED Screen
#include <Adafruit_SSD1306.h>         // OLED Screen
#include <Ultrasonic.h>  // Ultrasonic interface
#include <Wire.h>
#include "ServoController.h"
#include <Adafruit_VL53L0X.h>
#include  <math.h>

// Constants
const bool ON_PC = false;   // default = false, true for always output to serial
const int DELAY_VALUE = 5;  // default = 5,     forced delay after every read from the sensors
const int TIMEOUT = 10;     // default = 10,    timeout value for serial communications
// OLED
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
// Button variables
const int btnInputPin[4] = {2, 3, 4, 5};  // Pins for the circuit
int btnChange;                            // variable for the first pin (2)
int btnBinary;                            // variable for the sum of the other 3 pins in binary ex. 101 -> 5

// Ultrasonic varaibles
// (Trig, Echo)
Ultrasonic u1(22, 23), u2(24, 25), u3(26, 27), u4(28, 29), u5(30, 31), u6(32, 33), u7(34, 35);
int ultrasonicValues[7];
// OLED display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
//Servos
ServoController servos;

//Mode variables
char modes[9][10] = {"CONTROL R", "BRAZO UP ", "BRAZO DWN", "CHARO UP ", "CHARO DWN", "PENDIENTE", "PENDIENTE", "PENDIENTE"};

// Adagruit VL53L0X
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// Ultrasonic vectors
/*
0: 180°
1: 315°
2: 270°
3: 225°
4: °
5: 0°
6: 315°

Lastest degrees: 90, 225, 180, 135, 45, 0, 315
*/
// int ultrasonic_distances[7] = {5, 5, 5, 5, 5, 5, 5};
const int ultrasonic_angles[] = {180, 315, 270, 225, 135, 90, 45};
double magnitud_vector, angle_vector;
double component_x, component_y;

//void updateDisplay();

void setup() {
    // Initialize built-in led
    pinMode(LED_BUILTIN, OUTPUT);
    // Init Servos
    servos.init();
    //Initiaize Serial
    Serial.begin(115200);
    Serial.setTimeout(TIMEOUT);
    // Initialize OLED screen
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
    }
    //
    if (!lox.begin()) {
    Serial.println(F("Error al iniciar VL53L0X"));
    while(1);
    }
    delay(1000);
    
}

void loop() {
    // Constinuosly read data from the sensors
    // and display it to the OLED screen.
    //
    // if the serial is available and a '1' is
    // sent before the timeout it will output
    // the data to serial.
    //
    // if the constant ON_PC is true it will
    // output to serial everytime.
    //
    // It has a obligatory delay if it generates
    // troubles modify it by changing the constant
    // DELAY_VALUE

    // ---------------------------------------------------
    // | Data obtention                                  |
    // ---------------------------------------------------
    // Ultrasonic
    ultrasonicValues[0] = u1.Ranging(CM);
    ultrasonicValues[1] = u2.Ranging(CM);
    ultrasonicValues[2] = u3.Ranging(CM);
    ultrasonicValues[3] = u4.Ranging(CM);
    ultrasonicValues[4] = u5.Ranging(CM);
    ultrasonicValues[5] = u6.Ranging(CM);
    ultrasonicValues[6] = u7.Ranging(CM);
    // Calculate vector xd
    calculate_vector();
    
    // Buttons
    btnChange = digitalRead(btnInputPin[0]);
    //while(digitalRead(btnInputPin[0])) {}
    btnBinary = digitalRead(btnInputPin[1]) * 4 + digitalRead(btnInputPin[2]) * 2 + digitalRead(btnInputPin[3]);

    // update OLED Screen
    updateDisplay();

    // Power built-in led if the first ultrasonic lecture is less than 10 cm
    if (ultrasonicValues[0] > 10)
        digitalWrite(LED_BUILTIN, LOW);
    else
        digitalWrite(LED_BUILTIN, HIGH);

    // Conditional for sending and receiving data from serial
    // 1 -> Send information from sensors
    // 2 -> Move claw up and down
    // 3 -> Move tray in and out
    if (Serial.available() > 0) {
        String recv = Serial.readStringUntil('\n');
        if ((recv == "1") || ON_PC)
            sendData();
        else if (recv == "2")
            servos.moveClaw(95);
        else if (recv == "3")
            servos.moveTray(30);
    }
    
    if(digitalRead(btnInputPin[2])){
      servos.moveClaw(95);
      while(digitalRead(btnInputPin[2])){}
    }
    if(digitalRead(btnInputPin[1])){
      servos.moveTray(30);
      while(digitalRead(btnInputPin[1])){}
    }

    

    // Forced delay
    delay(DELAY_VALUE);
}


void sendData() {
    // When called this function prints all
    // latest sensor values to serial port
    //
    // It follows the next format:
    // [change, buttons_value, u1, u2, u3, u4, u5, u6, u7]

    Serial.print(btnChange);
    Serial.print(',');
    Serial.print(btnBinary);
    Serial.print(',');
    Serial.print(ultrasonicValues[0]);
    Serial.print(',');
    Serial.print(ultrasonicValues[1]);
    Serial.print(',');
    Serial.print(ultrasonicValues[2]);
    Serial.print(',');
    Serial.print(ultrasonicValues[3]);
    Serial.print(',');
    Serial.print(ultrasonicValues[4]);
    Serial.print(',');
    Serial.print(ultrasonicValues[5]);
    Serial.print(',');
    Serial.print(ultrasonicValues[6]);
    Serial.println();
}

void calculate_vector() {
  double vx = 0, vy = 0;
  double sum_vx = 0, sum_vy = 0;

  for (int i = 0; i < 7; i++) {
    vx = ultrasonicValues[i] * cos(radians(ultrasonic_angles[i]));
    vy = ultrasonicValues[i] * sin(radians(ultrasonic_angles[i]));
    sum_vx += vx;
    sum_vy += vy;
  }

  component_x = sum_vx;
  component_y = sum_vy;
  
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

void updateDisplay() {
    // Prepare the display
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);

    // Similar to serial, this part print
    // the variables in the next format:
    //
    // btn = change, btnBinary
    //        mode
    //  u1, u2, u3, u4, u5, u6, u7

    // Format ultrasonic string
    char buff[21];
    sprintf(buff, "%2d %2d %2d %2d %2d %2d %2d",
            ultrasonicValues[0],
            ultrasonicValues[1],
            ultrasonicValues[2],
            ultrasonicValues[3],
            ultrasonicValues[4],
            ultrasonicValues[5],
            ultrasonicValues[6]);

    display.print("BTN = ");
    display.print(btnChange);
    display.print(", ");
    display.println(btnBinary);
    display.println((btnChange == 1) ? "PAUSA" : modes[btnBinary]);
    display.println(buff);

    // Print the information in the display
    display.display();
}
