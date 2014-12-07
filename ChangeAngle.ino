void GetDesiredAngles()
{
    if (Serial.available() > 0) 
    {
      incomingByte = Serial.read();
      switch (incomingByte)
      {
        case 104:
          angle_checking(Desired_Pitch_Angle,1,15,-15);
        break;
        case 98:
          angle_checking(Desired_Pitch_Angle,-1,15,-15);
        break;
        case 100:
          angle_checking(Desired_Roll_Angle,-1,15,-15);
        break;
        case 102:
          angle_checking(Desired_Roll_Angle,1,15,-15);
        break;
      }
    }
}
void angle_checking(double angle, short number, double maxval, double minval)
{
  if (angle+number<=maxval || angle+number>=minval)
  {
    angle+=number;
  }
}
