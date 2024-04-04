#include <Servo.h>
Servo servo; 
void setup()
{
  //trig=10 and echo=11
  pinMode(A3,INPUT_PULLUP);
  pinMode(10,OUTPUT);
  pinMode(11,INPUT); 
  Serial.begin(9600);
  servo.attach(12); 
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT); 
  pinMode(A4,OUTPUT);
}
void loop()
{
  if (digitalRead(A3)==HIGH)
  {
  int distance; 
  for(int i=0;i<=270;i++)
  {
    servo.write(i);
    delay(30);
    distance=calcdist();
    Serial.print("At position ");
    Serial.print(i);
  	Serial.print(", the distance is ");
  	Serial.println(distance);  
    if(distance>=10&&distance<=200)
    {
      if(i==0)
      {
        digitalWrite(8,HIGH);
        delay(1000);
        digitalWrite(8,LOW);
      }
      else if(i==23)
      {
        digitalWrite(9,HIGH);
        delay(1000);
        digitalWrite(9,LOW);
      }
      else if(i==45)
      {
        digitalWrite(13,HIGH);
        delay(1000); 
        digitalWrite(13,LOW);
      }
      else if(i==68)
      {
        digitalWrite(7,HIGH);
        delay(1000);
        digitalWrite(7,LOW);
      }
      else if(i==90)
      {
        digitalWrite(A5,HIGH);
        delay(1000);
        digitalWrite(A5,LOW);
      }
      else if(i==113)
      {
        digitalWrite(A2,HIGH);
        delay(1000);
        digitalWrite(A2,LOW);
      }
      else if(i==135)
      {
        digitalWrite(A1,HIGH);
        delay(1000);
        digitalWrite(A1,LOW);
      }
      else if(i==158)
      {
        digitalWrite(A0,HIGH);
        delay(1000);
        digitalWrite(A0,LOW);
      }
      else if(i==180)
      {
        digitalWrite(5,HIGH);
        delay(1000);
        digitalWrite(5,LOW);
      }
      else if(i==203)
      {
        digitalWrite(6,HIGH);
        delay(1000);
        digitalWrite(6,LOW);
      }
      else if(i==225)
      {
        digitalWrite(2,HIGH);
        delay(1000);
        digitalWrite(2,LOW);
      }
      else if(i==248)
      {
        digitalWrite(3,HIGH);
        delay(1000);
        digitalWrite(3,LOW);
      }
      else if(i==270)
      {
        digitalWrite(4,HIGH);
        delay(1000);
        digitalWrite(4,LOW);
      }
            

      
  }
  }
  for(int i=270;i>=0;i--)
  {
    servo.write(i);
    delay(30);
    distance=calcdist();
    Serial.print("At position ");
    Serial.print(i);
  	Serial.print(", the distance is ");
  	Serial.println(distance);
    if(distance>=10&&distance<=200)
    {
      if(i==0)
      {
        digitalWrite(8,HIGH);
        delay(1000);
        digitalWrite(8,LOW);
      }
      else if(i==23)
      {
        digitalWrite(9,HIGH);
        delay(1000);
        digitalWrite(9,LOW);
      }
      else if(i==45)
      {
        digitalWrite(13,HIGH);
        delay(1000); 
        digitalWrite(13,LOW);
      }
      else if(i==68)
      {
        digitalWrite(7,HIGH);
        delay(1000);
        digitalWrite(7,LOW);
      }
      else if(i==90)
      {
        digitalWrite(A5,HIGH);
        delay(1000);
        digitalWrite(A5,LOW);
      }
      else if(i==113)
      {
        digitalWrite(A2,HIGH);
        delay(1000);
        digitalWrite(A2,LOW);
      }
      else if(i==135)
      {
        digitalWrite(A1,HIGH);
        delay(1000);
        digitalWrite(A1,LOW);
      }
      else if(i==158)
      {
        digitalWrite(A0,HIGH);
        delay(1000);
        digitalWrite(A0,LOW);
      }
      else if(i==180)
      {
        digitalWrite(5,HIGH);
        delay(1000);
        digitalWrite(5,LOW);
      }
      else if(i==203)
      {
        digitalWrite(6,HIGH);
        delay(1000);
        digitalWrite(6,LOW);
      }
      else if(i==225)
      {
        digitalWrite(2,HIGH);
        delay(1000);
        digitalWrite(2,LOW);
      }
      else if(i==248)
      {
        digitalWrite(3,HIGH);
        delay(1000);
        digitalWrite(3,LOW);
      }
      else if(i==270)
      {
        digitalWrite(4,HIGH);
        delay(1000);
        digitalWrite(4,LOW);
      }
    }
    }
  }
}
  int calcdist()
  {
    digitalWrite(10,LOW); delay(2);
    digitalWrite(10,HIGH); delay(10);
    digitalWrite(10,LOW);
    int dur=pulseIn(11,HIGH);
    int distance=dur*0.034/2;
    return distance; 
  }