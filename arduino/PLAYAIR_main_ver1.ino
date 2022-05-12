
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
}

void loop() {
  mpu6050.update();

  if(millis() - timer > 50){
    
    Serial.print(mpu6050.getAccX());
    Serial.print("\t ");Serial.print(mpu6050.getAccY());
    Serial.print("\t ");Serial.println(mpu6050.getAccZ());
    timer = millis();
    
  }

}
