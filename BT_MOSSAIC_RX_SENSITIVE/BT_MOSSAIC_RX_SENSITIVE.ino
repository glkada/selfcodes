#include<SoftwareSerial.h>
//declaring pin nos cytron
int m1_dir = 7;
 int m2_dir = 8;
 int m1_pwm = 9;
 int m2_pwm = 10;
 int led = 13;
 

 
SoftwareSerial BT(5,6);
void setup()
{
    Serial.begin(38400);
    BT.begin(38400);// Debugging only
    //Serial.println("setup");
    pinMode(led,OUTPUT);
    pinMode(2,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2),led_on,LOW);
}//close setup

void loop(){
  
  while(BT.available()){
    int c = BT.read();
    Serial.println(c);
    
    switch(c){
    case 49:
    forward();
    break;
    case 50:
    reverse();
    break;
    case 51:
    left();
    break;
    case 52:
    right();
    break;
    case 53:
    stop1();
    break;
    case 54:
    forward_slow();
    break;
    }
    
    }
  }
void forward()
 {
  Serial.println("Forward");
  digitalWrite(m1_dir,HIGH);
  digitalWrite(m2_dir,HIGH);
  for(int i=1;i<106;i++)
  {
    analogWrite(m1_pwm,150+i);
    analogWrite(m2_pwm,150+i);
    delay(5);
  } 
  delay(10);
  //analogWrite(m1_pwm,0);
  //analogWrite(m2_pwm,0);
 }
 void forward_slow()
 {
  Serial.println("Forward");
  digitalWrite(m1_dir,HIGH);
  digitalWrite(m2_dir,HIGH);
  analogWrite(m1_pwm,150);
  analogWrite(m2_pwm,150);
  delay(10);
  //analogWrite(m1_pwm,0);
  //analogWrite(m2_pwm,0);
 }
void left()
 {
  Serial.println("Left");
  digitalWrite(m1_dir,HIGH);
  digitalWrite(m2_dir,LOW);
  analogWrite(m1_pwm,180);
  analogWrite(m2_pwm,180);
  delay(10);
  //analogWrite(m1_pwm,0);
  //analogWrite(m2_pwm,0);
 }
void right()
 { 
  Serial.println("Right");
  digitalWrite(m1_dir,LOW);
  digitalWrite(m2_dir,HIGH);
  analogWrite(m2_pwm,180);
  analogWrite(m1_pwm,180);
  delay(10);
  //analogWrite(m1_pwm,0);
  //analogWrite(m2_pwm,0);
 }
void reverse()
 {
  Serial.println("Reverse");
  digitalWrite(m1_dir,LOW);
  digitalWrite(m2_dir,LOW);
  analogWrite(m1_pwm,180);
  analogWrite(m2_pwm,180);
  delay(10);
  //analogWrite(m1_pwm,0);
  //analogWrite(m2_pwm,0);  
 }
void stop1()
 {
  Serial.println("Stopped");
  //digitalWrite(m1_dir,LOW);
  //digitalWrite(m2_dir,LOW);
  analogWrite(m1_pwm,0);
  analogWrite(m2_pwm,0); 
 }
void led_on()
  {
    PORTB = B00100000;
    delay(100);
    PORTB = B00000000; 
  }

