byte incomingByte = 0;
unsigned short Throttle = 0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  ChangeThrottle();
  Serial.println(Throttle);
  delay(100);
}
