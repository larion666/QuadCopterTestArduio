void GetThrottle()
{  
    if (Serial.available() > 0) 
    {
      incomingByte = Serial.read();
      switch (incomingByte)
      {
        case 108:
          throttle_checking(-1);
        break;
        case 107:
          throttle_checking(1);
        break;
        /*case 37:
          throttle_checking(-10);
        break;
        case 39:
          throttle_checking(10);
        break;*/
      }
    }
}
void throttle_checking(short number)
{
  if (Throttle+number<=100)
  {
    Throttle+=number;
  }
}
