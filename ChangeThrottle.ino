void ChangeThrottle()
{  
    if (Serial.available() > 0) 
    {
      incomingByte = Serial.read();
      switch (incomingByte)
      {
        case 40:
          number_checking(-1);
        break;
        case 38:
          number_checking(1);
        break;
        case 37:
          number_checking(-10);
        break;
        case 39:
          number_checking(10);
        break;
      }
    }
}
void number_checking(short number)
{
  if (Throttle+number<=100)
  {
    Throttle+=number;
  }
}
