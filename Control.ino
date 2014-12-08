void EngineControl()
{
  PID_Pitch_value=PIDCompute(Desired_Pitch_Angle-PitchAngle,PID_Pitch_Kp,PID_Pitch_Ki,PID_Pitch_Kd,PID_Pitch_MaxValue,PID_Pitch_MinValue);
  PID_Roll_value=PIDCompute(Desired_Roll_Angle-RollAngle,PID_Roll_Kp,PID_Roll_Ki,PID_Roll_Kd,PID_Roll_MaxValue,PID_Roll_MinValue);
  //int PID_Yaw_value=PIDCompute();
  //Throttle=PIDCompute(Desired_Throttle-Throttle,0.250,0.950,0.011,100,0);
  //Serial.println(Desired_Throttle+OutputThrottle);

}

