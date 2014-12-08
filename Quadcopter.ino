#include <Wire.h>
#include <I2Cdev.h>
#include <helper_3dmath.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include "Config.h"
//#include <I2Cdev.h>
//#include <MPU6050_6Axis_MotionApps20.h>

MPU6050 mpu;
byte incomingByte = 0;
double Throttle = 0.000;
double OutputThrottle = 0.000;
double PitchAngle=0;
double RollAngle=0;
double YawAngle=0;
double Desired_Pitch_Angle=0.000;
double Desired_Roll_Angle=0.000;
double Desired_Yaw_Angle=0.000;
double Desired_Throttle=0.000;
bool dmpReady = false; 
double PID_Pitch_value=0.000;
double PID_Roll_value=0.000;
uint8_t mpuIntStatus;
uint16_t packetSize; // expected DMP packet size (default is 42 bytes)
void setup()
{
  Serial.begin(115200);
  Wire.begin();
  TWBR = 24;
  mpu.initialize();
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
  mpu.dmpInitialize();
  mpu.setXAccelOffset(-1683);
  mpu.setYAccelOffset(2103);
  mpu.setZAccelOffset(1278);
  mpu.setXGyroOffset(-13);
  mpu.setYGyroOffset(-31);
  mpu.setZGyroOffset(112);
  mpu.setDMPEnabled(true);
  attachInterrupt(0, dmpDataReady, RISING);
  mpuIntStatus = mpu.getIntStatus();
  dmpReady = true;
  packetSize = mpu.dmpGetFIFOPacketSize();
}
void loop()
{
  GetThrottleAndDesiredAngles();
  //GetDesiredAngles();
  Get_angles_from_sensor();
  EngineControl();
  Serial.print(Desired_Pitch_Angle);
  Serial.print(",");
  Serial.print(PitchAngle);
  Serial.print(",");
  Serial.print(PID_Pitch_value);
  Serial.print(",");
  //Serial.println(Desired_Throttle);
  //Serial.print(",");
  Serial.print(Desired_Roll_Angle);
  Serial.print(",");
  Serial.print(RollAngle);
  Serial.print(",");
  Serial.println(PID_Roll_value);
  //Serial.println(Throttle);
}
