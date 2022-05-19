#include <Arduino.h>
#include <TinyMPU6050.h>
#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Wire.h>

// Accelerometer
MPU6050 mpu (Wire);

// Accelerometer timing
unsigned long prevTime_acc = millis();
long interval_acc = 40;

// Grip
int grip_pin;
float grip_analog;
float grip_threshold;

// Vibration motor pins
int vibe1;
int vibe2;
int vibe3;
int vibe4;
int vibe5;

void setup() {
  // Serial
  Serial.begin(9600);

  // I2C
  Wire.begin();

  // Keyboard
  Keyboard.begin();

  // Initialize accelerometer
  mpu.Initialize();
  
  // Calibrate accelerometer
  //mpu.Calibrate();

  // Setup grip pin
  pinMode(grip_pin, INPUT);

  // Setup vibration pins
  pinMode(vibe1,OUTPUT);
  pinMode(vibe2,OUTPUT);
  pinMode(vibe3,OUTPUT);
  pinMode(vibe4,OUTPUT);
  pinMode(vibe5,OUTPUT);
}

void loop() {
  // Update accelerometer values
  mpu.Execute();

  // Read grip
  grip_analog = analogRead(grip_pin);

  // Run while grip is above threshold
  while (grip_analog >= grip_threshold) { 
    
    // Current time
    unsigned long currentTime = millis();
  
    // Accelerometer X,Y, and Z values
    if(currentTime - prevTime_acc > interval_acc){
     
      // Acceleration in downward motion in this direction, play snare drum.
      // To Do: Add conditionals for acceleration in each drum direction
      if (mpu.GetAccY() >= 1.60 && mpu.GetAngAccX() >= 40) {
        
        // Press key assigned to sound
        Keyboard.write('a');

        // Vibrate motors to sound
        digitalWrite(vibe1,HIGH); // vary vibration -> analogWrite(vibe1,mpu.GetAccyY());
        digitalWrite(vibe2,HIGH);
        digitalWrite(vibe3,HIGH);
        digitalWrite(vibe4,HIGH);
        digitalWrite(vibe5,HIGH);

        // Delay in ms
        delay(20);
        
      } /* elseif ( HiHat direction ) {
        // Press key assigned to sound
        Keyboard.write('r');

        // Vibrate motors to sound
        digitalWrite(vibe1,HIGH);
        digitalWrite(vibe2,HIGH);
        digitalWrite(vibe3,HIGH);
        digitalWrite(vibe4,HIGH);
        digitalWrite(vibe5,HIGH);

        // Delay in ms
        delay(20);
        
      } elseif ( high tom direction ) {
      
        // Press key assigned to sound
        Keyboard.write('g');

        // Vibrate motors to sound
        digitalWrite(vibe1,HIGH);
        digitalWrite(vibe2,HIGH);
        digitalWrite(vibe3,HIGH);
        digitalWrite(vibe4,HIGH);
        digitalWrite(vibe5,HIGH);

        // Delay in ms
        delay(20);
        
      } elseif ( Low tom direction) {
      
        // Press key assigned to sound
        Keyboard.write('h');

        // Vibrate motors to sound
        digitalWrite(vibe1,HIGH);
        digitalWrite(vibe2,HIGH);
        digitalWrite(vibe3,HIGH);
        digitalWrite(vibe4,HIGH);
        digitalWrite(vibe5,HIGH);

        // Delay in ms
        delay(20);
        
      } elseif ( Floor tom direction ) {
      
        // Press key assigned to sound
        Keyboard.write('j');

        // Vibrate motors to sound
        digitalWrite(vibe1,HIGH);
        digitalWrite(vibe2,HIGH);
        digitalWrite(vibe3,HIGH);
        digitalWrite(vibe4,HIGH);
        digitalWrite(vibe5,HIGH);

        // Delay in ms
        delay(20);
        
      } elseif ( Crash cymbal direction ) {

        // Press key assigned to sound
        Keyboard.write('y');

        // Vibrate motors to sound
        digitalWrite(vibe1,HIGH);
        digitalWrite(vibe2,HIGH);
        digitalWrite(vibe3,HIGH);
        digitalWrite(vibe4,HIGH);
        digitalWrite(vibe5,HIGH);

        // Delay in ms
        delay(20);

      }*/
      
      // Previous time
      prevTime_acc = millis();
    }

    // Print Acc X, Y, & Z to Serial
      Serial.print(mpu.GetAccX());
      Serial.print("\t ");Serial.print(mpu.GetAccY());
      Serial.print("\t ");Serial.println(mpu.GetAccZ());

  }
}
