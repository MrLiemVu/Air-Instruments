#include <Arduino.h>
//#include <TinyMPU6050.h>
#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MPU6050_tockn.h>

// Accelerometer
MPU6050 mpu (Wire);

// Accelerometer timing
unsigned long prevTime_acc = millis();
long interval_acc = 200;

// Grip
int grip_pin;
float grip_analog;
float grip_threshold;

// Vibration motor pins
int vibe1 = 4;
int vibe2 = 5;
int vibe3 = 6;
int vibe4 = 7;
int vibe5 = 8;

const int TX = 1;
const int RX = 0;
int BAUD_RATE = 9600;
int state;
MPU6050 mpu6050(Wire);
SoftwareSerial Blue(RX, TX);
int count = 0;

void setup() {

  // Begin Serial and Bluetooth Serial
  Blue.begin(BAUD_RATE);
  Serial.begin(BAUD_RATE);
  
  // Initialize accelerometer
  mpu6050.begin();
  
  // I2C
  Wire.begin();

  // Keyboard
  Keyboard.begin();
  
  // Setup vibration pins
  pinMode(vibe1,OUTPUT);
  pinMode(vibe2,OUTPUT);
  pinMode(vibe3,OUTPUT);
  pinMode(vibe4,OUTPUT);
  pinMode(vibe5,OUTPUT);

  digitalWrite(vibe1, HIGH);
  delay(200);
  digitalWrite(vibe1, LOW);
  delay(200);
  digitalWrite(vibe1, HIGH);
  delay(200);
  digitalWrite(vibe1, LOW);
    
  Serial.println("Ready!");

}

void loop() {

  // Check if data coming from serial port
  if (Serial.available() > 0) {
    state = Serial.read();
    Serial.println(state + "serialtest");
  }
  if (Blue.available() > 0) {
    state = Blue.read();
    Serial.println("blbluetest" + state);
    Serial.println(Blue.read());
    Blue.println(Blue.read());
  }
  if (state == '1') {
    digitalWrite(vibe1, HIGH);
    Serial.println("Vibrate: On");
  }
  else if (state == '0') {
    digitalWrite(vibe1, LOW);
    Serial.println("Vibrate: Off");
  }
  // Update accelerometer values
  mpu6050.update();

  // Current time
  unsigned long currentTime = millis();

  // Accelerometer X,Y, and Z values
  if(currentTime - prevTime_acc > interval_acc){
    prevTime_acc = millis();
    float accX = mpu6050.getAccX();
    float accY = mpu6050.getAccY();
    float accZ = mpu6050.getAccZ();
//    Blue.println(String(accX) + " " + String(accY) + " " + String(accZ));
//    Serial.println("X: " + String(accX) + " Y: " + String(accY) + " Z: " + String(accZ));
    
  }
  

}
