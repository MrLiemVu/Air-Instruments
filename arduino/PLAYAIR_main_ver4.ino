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

// Drum counter
int drum_counter = 1;

// Grip
int grip_pin=A1;
float grip_analog;
float grip_threshold = 1;

// Vibration motor pins
int vibe1=4;
int vibe2=5;
int vibe3=6;
int vibe4=7;
int vibe5=8;

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

  // Acceleration values
  float z = mpu.GetAccZ();
  float y = mpu.GetAccY();

  // Swiitch drums by moving hand left or right
  if (y <= -1.90) {
    drum_counter += 1;
    Serial.println(drum_counter);
    delay(100);
  } else if (y >= 1.9) {
    drum_counter -= 1;
    Serial.println(drum_counter);
    delay(100);
  }

  
  // Read grip
  grip_analog = analogRead(grip_pin);

  // Run while grip is above threshold
  while (grip_analog >= grip_threshold) { 
    
    // Current time
    unsigned long currentTime = millis();
  
    // Accelerometer X,Y, and Z values
    if(currentTime - prevTime_acc > interval_acc){
      
      // Play selected drum
      if (z >= 1.90){
        switch (drum_counter) {
          case 0: // HiHat cymbal
            Serial.println("HiHat");
            Keyboard.write('r');
            // Vibrate motors to sound
            digitalWrite(vibe1,HIGH); // vary vibration -> analogWrite(vibe1,mpu.GetAccyY());
            digitalWrite(vibe2,HIGH);
            digitalWrite(vibe3,HIGH);
            digitalWrite(vibe4,HIGH);
            digitalWrite(vibe5,HIGH);
    
            // Delay in ms
            delay(200);
            break;
          case 1: // Snare drum
            Serial.println("Snare");
            Keyboard.write('a');
            // Vibrate motors to sound
            digitalWrite(vibe1,HIGH); // vary vibration -> analogWrite(vibe1,mpu.GetAccyY());
            digitalWrite(vibe2,HIGH);
            digitalWrite(vibe3,HIGH);
            digitalWrite(vibe4,HIGH);
            digitalWrite(vibe5,HIGH);
    
            // Delay in ms
            delay(200);
            break;
          case 2: // Floor Tom
            Serial.println("Floor Tom");
            Keyboard.write('j');
            // Vibrate motors to sound
            digitalWrite(vibe1,HIGH); // vary vibration -> analogWrite(vibe1,mpu.GetAccyY());
            digitalWrite(vibe2,HIGH);
            digitalWrite(vibe3,HIGH);
            digitalWrite(vibe4,HIGH);
            digitalWrite(vibe5,HIGH);
    
            // Delay in ms
            delay(200);
            break;
          case 3: // Ride Cymbal
            Serial.println("Ride Cymbal");
            Keyboard.write('u');
            // Vibrate motors to sound
            digitalWrite(vibe1,HIGH); // vary vibration -> analogWrite(vibe1,mpu.GetAccyY());
            digitalWrite(vibe2,HIGH);
            digitalWrite(vibe3,HIGH);
            digitalWrite(vibe4,HIGH);
            digitalWrite(vibe5,HIGH);
    
            // Delay in ms
            delay(200);
            break;
          default:
            Serial.println("Out of range");
            delay(40);
            break;
        }
      
      // Previous time
      prevTime_acc = millis();
      }
    }
    // Print Acc X, Y, & Z to Serial
      Serial.print(mpu.GetAccX());
      Serial.print("\t ");Serial.print(mpu.GetAccY());
      Serial.print("\t ");Serial.println(mpu.GetAccZ());

  }
}
