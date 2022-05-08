
#include <MPU6050_tockn.h>
#include <Wire.h>

byte code = 1;
float vel = 0;

MPU6050 mpu6050(Wire);

long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  //initialize accelerometer
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  
  mpu6050.update();

  if(millis() - timer > 100){
    
    //Hit snare when orientation is above 0.8 in Y direction
    if (mpu6050.getAccY() > 0.8) {
      code = 127;
      // Send byte to processing to play snare sound
      Serial.write(code);
      delay(10);
    }
    timer = millis();
    
  }

}
