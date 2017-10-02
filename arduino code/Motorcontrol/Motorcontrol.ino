#include <Servo.h>

const int Motor_E1 = 5; // digital pin 5 of Arduino (PWM)    
const int Motor_E2 = 6;  // digital pin 6 of Arduino (PWM)  
const int Motor_M1 = 7;     // digital pin 7 of Arduino
const int Motor_M2 = 8;    // digital pin 8 of Arduino
const int D1 = 2;
const int D2 = 3;
const int D3 = 4;
int a = 0;
int b = 0;
int c = 0;
Servo servohead;
int poshead = 89;

void setup() 
{ 
 pinMode(Motor_M1, OUTPUT); 
 pinMode(Motor_M2, OUTPUT);
 pinMode(D1, INPUT);
 pinMode(D2, INPUT);
 pinMode(D3, INPUT);
 pinMode(9, OUTPUT);
 servohead.attach(11);
}

void loop()
{
  digitalWrite( 9, HIGH);
//  servohead.write(poshead);
//  delay(2000);
//  forward(0,255);
//  delay(1000);
//  motorstop(0,0);
//  delay(500);
//  servohead.write(60);
//  delay(7000);
  readcommand();
  delay(500);
}

void readcommand()
{
  a = digitalRead(D1);
  b = digitalRead(D2);
  c = digitalRead(D3);
  if (a == 1)
  {
    if(b == 1)
    {
      if(c == 1)
      {
        backward(0,255);
      }
      else
      {
      }
    }
    else
    { 
    }
  }
  else
  {
    if(b == 1)
    {
      if(c == 1)
      {
        forward(0,255);
      }
      else
      {
        left(0,255);
      }
    }
    else
    { 
      if(c == 1)
      {
        right(0,255);
      }
      else
      {
        motorstop(0,0);
      }
    }
  }
}

void motorstop(byte flag, byte motorspeed)
{
  digitalWrite( Motor_E1, motorspeed);
  digitalWrite( Motor_E2, motorspeed);
}

void forward(byte flag, byte motorspeed)
{
  digitalWrite( Motor_M1, HIGH);
  digitalWrite( Motor_M2, HIGH);
  analogWrite( Motor_E1, motorspeed);
  analogWrite( Motor_E2, motorspeed);
}
void backward(byte flag, byte motorspeed) 
{
  digitalWrite( Motor_M1, LOW); 
  digitalWrite( Motor_M2, LOW); 
  analogWrite( Motor_E1, motorspeed); 
  analogWrite( Motor_E2, motorspeed);
} 
void left(byte flag, byte motorspeed) 
{
  digitalWrite( Motor_M1, HIGH); 
  digitalWrite( Motor_M2, LOW); 
  analogWrite( Motor_E1, motorspeed); 
  analogWrite( Motor_E2, motorspeed);
} 
void right(byte flag, byte motorspeed) 
{
  digitalWrite( Motor_M1, LOW); 
  digitalWrite( Motor_M2, HIGH);
  analogWrite( Motor_E1, motorspeed); 
  analogWrite( Motor_E2, motorspeed);
}
