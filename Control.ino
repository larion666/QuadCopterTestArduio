void EngineControl()
{
  int PID_Pitch_value=PIDCompute(Desired_Pitch_Angle-PitchAngle,0.250,0.950,0.011,15,-15);
  int PID_Roll_value=PIDCompute(Desired_Roll_Angle-RollAngle,0.250,0.950,0.011,15,-15);
  //int PID_Yaw_value=PIDCompute();
  //Throttle=PIDCompute(Desired_Throttle-Throttle,0.250,0.950,0.011,100,0);
  //Serial.println(Desired_Throttle+OutputThrottle);
}

