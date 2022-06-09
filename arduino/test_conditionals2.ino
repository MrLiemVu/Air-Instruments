
#include <Arduino.h>
#include <TinyMPU6050.h>
#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Wire.h>

MPU6050 mpu (Wire);

long timer = 0;
float myarray[2] = {0,0}; 
//float yarray[2] = []
boolean up = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Keyboard.begin();

  //initialize accelerometer
  mpu.Initialize();
  mpu.Calibrate();
}

void loop() {
  
  mpu.Execute();
  
  Serial.print(mpu.GetAngY());
  Serial.print(",");
  Serial.println(mpu.GetAngZ());
  
  
  float first = mpu.GetAngY(); 
  if ((first - myarray[1]) < -20){
    up = true;
  }
  while (up) {
    mpu.Execute();
    Serial.print(mpu.GetAngY());
    Serial.print(",");
    Serial.println(mpu.GetAngZ());
    
//    if(millis() - timer > 100){
    float z = mpu.GetAngZ();
    float y = mpu.GetAngY();
      //Hit snare when orientation is above 0.8 in Y direction
   // if (z >= -80 && z <= -30){
      if(y >= -40 && y <= -20){
        Keyboard.write('r');
        delay(20);
        up = false; 
      } else if(y <= 22 && y >= -2){
        Keyboard.write('a');
        delay(20);
        up = false;          
      }
//    } 
//    else if (z >= 30 && z <= 60){
//      if(y >= -40 && y <= -20){
//        Keyboard.write('u');
//        up = false; 
//      } else if(y <= 22 && y >= -2){
//        Keyboard.write('j');
//        up = false;          
//      }
//    }

//    timer = millis();
  delay(20);
  }
  myarray[1] = myarray[0];
  myarray[0] = mpu.GetAngY();
  delay(20);

}
