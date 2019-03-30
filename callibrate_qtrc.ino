int calibration()
{
  indicator_off;
  for(int i=0;i<100;i++)
  {
    qtrrc.calibrate();
    blink(20);
  }
  delay(2000);

  if(true)
  {
    for (int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(qtrrc.calibrationOn.minimum[i]);
      Serial.print(' ');
    }
    Serial.println();

    for (int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(qtrrc.calibrationOn.maximum[i]);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
  }
  indicator_on;
}
