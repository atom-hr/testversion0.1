int print_sensor()
{
  int sensors[8];
  int pos=qtrrc.readLineBlack(sensors);
  for(int i=0;i<8;i++)
  {
    Serial.println(sensors[i]);
  }
  Serial.println();
  Serial.println(pos);
  Serial.println();
  return 0;
}
