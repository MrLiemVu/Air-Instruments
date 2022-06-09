
#include <Arduino.h>
#include <TinyMPU6050.h>
#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Wire.h>

MPU6050 mpu (Wire);

int drum_counter = 1;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Keyboard.begin();

  //initialize accelerometer
  mpu.Initialize();
//  mpu.Calibrate();
}

void loop() {

  mpu.Execute();
//  Serial.print(mpu.GetAccY());
//  Serial.print(",");
//  Serial.println(mpu.GetAccZ());
  
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

  // Play selected drum
  if (z >= 1.90){
    switch (drum_counter) {
      case 0:
        Serial.println("Hi Hat");
        Keyboard.write('r');
        delay(40);
        break;
      case 1:
        Serial.println("Snare");
        Keyboard.write('a');
        delay(40);
        break;
      case 2:
        Serial.println("Floor Tom");
        Keyboard.write('j');
        delay(40);
        break;
      case 3:
        Serial.println("Ride Cymbal");
        Keyboard.write('u');
        delay(40);
        break;
      default:
        Serial.println("Out of range");
        delay(40);
        break;
    }
  }
delay(40);
}
