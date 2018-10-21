#include <Servo.h>
Servo myservo;
Servo myservo1;
int x_key = A0;
int y_key = A1;
int xpos;
int ypos;
int pos = 0;
int pos1 = 180;
void setup() {
  Serial.begin(9600);
  pinMode(x_key,INPUT);
  pinMode(y_key,INPUT);
  myservo.attach(9);
  myservo1.attach(10);
  myservo.write(0);
  myservo1.write(0);
  
}

void loop() 
{
 
 digitalWrite(13,HIGH); 
 xpos = analogRead(x_key);
 ypos = analogRead(y_key);
  Serial.print(xpos);
  Serial.print("\t");
  Serial.println(ypos);
 
 if(xpos > 1000 && xpos != 0){
    turn1();
  
 }
  if(xpos < 20)
  {
    turn2();
  } 
  if(ypos > 1000)
  {
   turn3();
  }
  if(ypos < 20 )
  {
    turn4();
  }
  //delay(1000);  
 }
 void turn1()
 {
   //int pos = 0;
   
   int i=0;
      // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    //constrain(pos, 0,180);
    myservo.write(i++);
   
    Serial.println("turn 1");
  }
 void turn2()
 {
   //int pos1 = 0;
   pos1--;
    myservo.write(pos1);
    //constrain(pos1, 0,180);
    Serial.println("turn 2");
 }
 void turn3()
 {
   //int pos = 0;
   pos++;
   //constrain(pos, 0,180);
    myservo1.write(pos);
    //constrain(pos, 0,180);
    Serial.println("turn 3");
 }
 void turn4()
 {
   //int pos1 = 0;
    pos1--;
    //constrain(pos1, 0,180);
    myservo1.write(pos1);
    //constrain(pos1, 0,180);
    Serial.println("turn 4");
 }  




