//**********TestVersion 0.1********
//*********************************

#include<QTRSensors.h>

//********defines********
#define indicator_on digitalWrite(13,HIGH)
#define indicator_off digitalWrite(13,LOW)

#define Kp 0.1
#define Kd 0
#define Ki 0

#define RMF 24
#define RMB 25
#define LMF 22
#define LMB 23
#define RME 11
#define LME 12
#define max_motor 150

#define trigPin1 43
#define echoPin1 42
#define trigPin2 39
#define echoPin2 38
#define trigPin3 41
#define echoPin3 40

#define NUM_SENSORS   8
#define TIMEOUT       2500 
#define EMITTER_PIN   2 
QTRSensors qtrrc;//((unsigned char[]) { 30,31,32,33,34,35,36,37 } ,NUM_SENSORS, TIMEOUT, EMITTER_PIN);
unsigned char sensor_pins[] = {30,31,32,33,34,35,36,37};
unsigned int sensorValues[NUM_SENSORS];


void setup() {
  //****setting up pinMode*****
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  
  pinMode(LMF,OUTPUT);
  pinMode(LMB,OUTPUT);
  pinMode(RMF,OUTPUT);
  pinMode(RMB,OUTPUT);
  pinMode(LME,OUTPUT);
  pinMode(RME,OUTPUT);

  //setting qtrrc
  qtrrc.setSensorPins(sensor_pins,NUM_SENSORS);
  qtrrc.setTimeout(TIMEOUT);
  qtrrc.setEmitterPin(EMITTER_PIN);

  calibration();
}

int last_error=0;
bool line_follow=true;
void loop() {
  
  if(Serial.available())
  {
    line_follow=false;
    int input=Serial.read();
    switch (input)
    {
      case 'c':calibration();break;
      case 'h':halt();break;
      case 'f':forward(50);break;
      case 'p':print_sensor();break;
      case 'z':line_follow=true;break;
      default :break;
    }
  }
  else if(line_follow==true)
  {
    int sensors[NUM_SENSORS];
    int line_position=qtrrc.readLineBlack(sensors);
    int error=line_position-3500;

    int motor_speed = Kp * error + Kd * (error - last_error);
    last_error = error;

    int left_motor=max_motor+motor_speed;
    int right_motor=max_motor-motor_speed;

    if(left_motor>255)left_motor=255;
    else if(left_motor<0)left_motor=0;
    if(right_motor>255)right_motor=255;
    else if(right_motor<0)right_motor=0;

    //the turns

    if(sensors[0]>200)
    {
      left_motor=100;
      right_motor=255;
    }
    else if(sensors[7]>200)
    {
      left_motor=255;
      right_motor=100;
    }

    digitalWrite(LMF, HIGH); 
    digitalWrite(LMB, LOW);
    digitalWrite(RMF, HIGH);
    digitalWrite(RMB, LOW);
    analogWrite(LME, left_motor);
    analogWrite(RME, right_motor);

    Serial.println(line_position);
  }
}
