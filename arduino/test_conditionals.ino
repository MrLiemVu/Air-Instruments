
#include <Arduino.h>
#include <TinyMPU6050.h>
#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Wire.h>

MPU6050 mpu (Wire);

long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Keyboard.begin();

  //initialize accelerometer
  mpu.Initialize();
}

void loop() {
  
  mpu.Execute();

  if(millis() - timer > 100){
    
    //Hit snare when orientation is above 0.8 in Y direction
    if (mpu.GetAccY() >= 1.60 && mpu.GetAngAccX() >= 40) {
      Keyboard.write('a');
      delay(20);
      
    } else if (mpu.GetAccY() <= -1.60 && mpu.GetAngAccX() <= -40){
      Keyboard.write('r');
      delay(20);
    /*} else if (mpu6050.getAccX() > 0.8){
      Keyboard.write('x');
      delay(50);
    } else if (mpu6050.getAccX() < -0.99){
      Keyboard.write('y');
      delay(50);
    */}
    timer = millis();
    
  }

}
