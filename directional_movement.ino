int forward(int pwd)
{
  digitalWrite(LMF, HIGH);
  digitalWrite(LMB,LOW);
  digitalWrite(RMF,HIGH);
  digitalWrite(RMB,LOW);
  analogWrite(LME,pwd);
  analogWrite(RME,pwd);delay(500);
}
void forward()
{
  digitalWrite(LMF,HIGH);
  digitalWrite(LMB,LOW);
  digitalWrite(RMF,HIGH);
  digitalWrite(RMB,LOW);
}


void backward()
{
  digitalWrite(LMF,LOW);
  digitalWrite(LMB,HIGH);
  digitalWrite(RMF,LOW);
  digitalWrite(RMB,HIGH);
}

void left()
{
  digitalWrite(LMF,LOW);
  digitalWrite(LMB,LOW);
  digitalWrite(RMF,HIGH);
  digitalWrite(RMB,LOW);
}

void right()
{
  digitalWrite(LMF,HIGH);
  digitalWrite(LMB,LOW);
  digitalWrite(RMF,LOW);
  digitalWrite(RMB,LOW);
}

void halt()
{
  digitalWrite(LMF,LOW);
  digitalWrite(LMB,LOW);
  digitalWrite(RMF,LOW);
  digitalWrite(RMB,LOW);
}


