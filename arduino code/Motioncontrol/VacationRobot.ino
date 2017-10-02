#include <Servo.h>

//#include <Servo.h>
//Servo servohead; // create servo object to control a servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
//int poshead = 89; // variable to store the servo position
int pos1 = 10;//10~170
int pos2 = 80;//89~10
int pos3 = 89;//89~160
int pos4 = 171;//170~10
int pos5 = 98;//89~170
int pos6 = 89;//20~89
int a = 0;
int b = 0;
void setup()
{
  //servohead.attach(); // attaches the servo on pin 9 to the servo object
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}
void stand()
{
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
  servo5.write(pos5);
  servo6.write(pos6);
}
void hello()
{
  servo1.write(120);
  delay(800);
  servo3.write(160);
  delay(500);
  servo3.write(pos3);
  delay(500);
  servo3.write(160);
  delay(500);
  servo3.write(pos3);
  delay(500);
  servo1.write(pos1);
  delay(800);
}
void loop()
{
  readcommand();
  //servo6.write(pos6);
  //stand();
  //delay(500);
//  hello();
//  delay(3000);
}

void readcommand()
{
  a = digitalRead(12);
  b = digitalRead(13);
  if (a == 1)
  {
    if(b == 1)
    {
      stand();
    }
    else
    { 
      stand();
    }
  }
  else
  {
    if(b == 1)
    {
      stand();
      delay(1000);
      hello();
      delay(2000);
    }
    else
    {
      stand();
    }
  }
}
//void loop()
//{
//  //for(pos = 0; pos < 180; pos += 1) // goes from 0 degrees to 180 degrees
//  //{ // in steps of 1 degree
//  servo1.write(pos1); // tell servo to go to position in variable 'pos'
//  delay(15); // waits 15ms for the servo to reach the position
//  //}
//  //for(pos = 180; pos>=1; pos-=1) // goes from 180 degrees to 0 degrees
//  //{
//  //myservo.write(pos); // tell servo to go to position in variable 'pos'
//  //delay(15); // waits 15ms for the servo to reach the position
//  //}
//}
