/*
 *  Mandatory includes
 */
#include <Arduino.h>
#include <TinyMPU6050.h>

/*
 *  Constructing MPU-6050
 */
MPU6050 mpu (Wire);

/*
 *  Method that prints everything
 */
void PrintGets () {
  // Show readable data
//  Serial.println("--- Readable data:");
//  Serial.print("AccX = ");
//  Serial.print(mpu.GetAccX()); // just above 0
//  Serial.println(" m/s²");
//  Serial.print("AccY = ");
//  Serial.print(mpu.GetAccY()); // at 2
//  Serial.println(" m/s²");
//  Serial.print("AccZ = ");
//  Serial.print(mpu.GetAccZ()); // skip z
//  Serial.println(" m/s²");
//  Serial.print("GyroX = ");
//  Serial.print(mpu.GetGyroX()); //135
//  Serial.println(" degrees/second");
//  Serial.print("GyroY = ");
//  Serial.print(mpu.GetGyroY()); // above 50
//  Serial.println(" degrees/second");
//  Serial.print("GyroZ = ");
//  Serial.print(mpu.GetGyroZ()); // below -250
//  Serial.println(" degrees/second");
  // Show angles based on accelerometer only
//  Serial.println("--- Accel angles:");
//  Serial.print("AccelAngX = ");
//  Serial.println(mpu.GetAngAccX());
  Serial.print("AccelAngY = ");
  Serial.println(mpu.GetAngAccY());


/* snare
mpu.GetAccX()); // just above 0
mpu.GetAccY()); // at 2
mpu.GetGyroX()); //qbove 135
mpu.GetGyroY()); // above 50
mpu.GetGyroZ()); // below -250


*/
}

/*
 *  Setup
 */
void setup() {

  // Initialization
  mpu.Initialize();
  
  Serial.begin(9600);

}

/*
 *  Loop
 */
void loop() {
  
  mpu.Execute();
  PrintGets();
  delay(300); // 30 sec delay

}
