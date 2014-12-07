#include <Wire.h>
#include <I2Cdev.h>
#include <helper_3dmath.h>
#include <MPU6050_6Axis_MotionApps20.h>
//#include <I2Cdev.h>
//#include <MPU6050_6Axis_MotionApps20.h>

MPU6050 mpu;
byte incomingByte = 0;
double Throttle = 0.000;
double OutputThrottle = 0.000;
double PitchAngle=0;
double RollAngle=0;
double Zangle=0;
double Desired_Pitch_Angle=0.000;
double Desired_Roll_Angle=0.000;
double Desired_Yaw_Angle=0.000;
double Desired_Throttle=0.000;
bool dmpReady = false; 
uint8_t devStatus;
uint16_t packetSize; // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount; // count of all bytes currently in FIFO
uint8_t fifoBuffer[64];
uint8_t mpuIntStatus;
float ypr[3];
Quaternion q; // [w, x, y, z] quaternion container
VectorFloat gravity;
volatile bool mpuInterrupt = false;
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
  GetThrottle();
  GetDesiredAngles();
  EngineControl();
  Get_angles_from_sensor();
  PitchAngle=ypr[1] * 180/M_PI;
  RollAngle=ypr[2] * 180/M_PI;
  //Serial.print(PitchAngle);
  //Serial.print(",");
  //Serial.println(RollAngle);
  //Serial.println(Throttle);
  //delay(50);
}
