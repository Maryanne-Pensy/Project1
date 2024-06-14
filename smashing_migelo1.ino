// C++ code
//
#include <Servo.h>
Servo myServo;
int previousPosition = 0; 
int temperature_sensor = A0;
int photo_transistor = A1;
int led1=9;
int led2=8;
int led3=2;
int switch=10;
void setup()
{
  Serial.begin(9600);
  myServo.attach(3); 
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(temperature_sensor,INPUT);
  pinMode(photo_transistor,INPUT);
  
}

void loop()
{
  int reading = analogRead(temperature_sensor);
  float voltage = (reading/1024.0)*5.0;
  Serial.print("Volts : ");
  Serial.print(voltage);

  float tempC = (voltage -.5)*100; 
  Serial.println(tempC);

  int position = map(tempC, 0, 50, 0, 180); 
  Serial.print("Servo Position: ");
  Serial.println(position);

  if (previousPosition != position) {
    myServo.write(position);
    previousPosition = position;
  }
  
  delay(1000);
  
  int lightReading = analogRead(photo_transistor);
  float reading2 = (lightReading/1024.0)*5.0;
  Serial.print("Photo Transistor Voltage: ");
  Serial.println(reading2);  
  delay(100);
  
  if(lightReading < 5){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }else if (lightReading < 2){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
}


    
    
