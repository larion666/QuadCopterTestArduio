void GetThrottleAndDesiredAngles()
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
        case 104: //numpad8
          Desired_Pitch_Angle=angle_checking(Desired_Pitch_Angle,1,Max_Pitch_Angle,Min_Pitch_Angle);
        break;
        case 98: //numpad2
          Desired_Pitch_Angle=angle_checking(Desired_Pitch_Angle,-1,Max_Pitch_Angle,Min_Pitch_Angle);
        break;
        case 100: //numpad4
          Desired_Roll_Angle=angle_checking(Desired_Roll_Angle,-1,Max_Roll_Angle,Min_Roll_Angle);
        break;
        case 102: //numpad6
          Desired_Roll_Angle=angle_checking(Desired_Roll_Angle,1,Max_Roll_Angle,Min_Roll_Angle);
        break;
      }
    }
}
void throttle_checking(short number)
{
  if (Desired_Throttle+number<=100)
  {
    Desired_Throttle+=number;
  }
}

double angle_checking(double angle, short number, double maxval, double minval)
{
  if (angle+number<=maxval && angle+number>=minval)// || angle+number>=minval)
  {
    angle+=number;
  }
  return angle;
}
