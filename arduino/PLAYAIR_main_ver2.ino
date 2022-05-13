
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

unsigned long prevTime_acc = millis();
long interval_acc = 50;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize accelerometer
  mpu6050.begin();
}

void loop() {
  // Update accelerometer values
  mpu6050.update();

  // Current time
  unsigned long currentTime = millis();

  // Accelerometer X,Y, and Z values
  if(currentTime - prevTime_acc > interval_acc){
    prevTime_acc = millis();
    Serial.print(mpu6050.getAccX());
    Serial.print("\t ");Serial.print(mpu6050.getAccY());
    Serial.print("\t ");Serial.println(mpu6050.getAccZ());
    
  }
  

}
