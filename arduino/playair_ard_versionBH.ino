
/**************************************************************************************************************
  Example for connecting four BME280 sensors to an I2C multiplexer (TCA9548A)
  written by Thiago Barros for BlueDot UG (haftungsbeschränkt)
  BSD License

  This sketch was written for the Bosch Sensor BME280 and the Chip TCA9548A from Texas Instrument.
  The BME280 is a MEMS device for measuring temperature, humidity and atmospheric pressure.
  The TCA9548A is an 8-Channel I2C Switch with reset function.
  For more technical information on the BME280 and TCA9548A, please go to ------> http://www.bluedot.space

 **************************************************************************************************************/

#include <<MPU6050_tockn.h>>
#include <Wire.h>
//#include <avr/wdt.h>

MPU6050_01 mpu6050(Wire);
MPU6050_02 mpu6050(Wire);


#define TCAADDR 0x70
void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println(F("##############################"));            
  Serial.println(F("Starting Initialization"));
  Serial.println(F("##############################"));       
 

  //*************INITIALIZING FIRST SENSOR*******************************   
  tcaselect(0);
  MPU6050_01.begin();

  //**********************************************************************

  //*************INITIALIZING FIRST SENSOR*******************************   
  tcaselect(1);
  MPU6050_02.begin();

  //**********************************************************************    

  //*********************************************************************
  //*************NOW LET'S START MEASURING*******************************
void loop() {
   mpu6050.update();
   tcaselect(0);
   Serial.print(MPU6050_01.getAccX());
   Serial.print("\t ");Serial.print(MPU6050_01.getAccY());
   Serial.print("\t ");Serial.println(MPU6050_01.getAccZ()); 
 
   tcaselect(1);
   Serial.print(MPU6050_02.getAccX());
   Serial.print("\t ");Serial.print(MPU6050_02.getAccY());
   Serial.print("\t ");Serial.println(MPU6050_02.getAccZ());

   Serial.println();
   Serial.println();

   delay(1000);   
 
}
