// RECIEVER CODE

//NOTE :- THIS CODE IS USED WHEN CONTROLLING THE ROBOT VIA THE BREADBORD REMOTE


#include<SoftwareSerial.h>
//declaring pin nos cytron
int m1_dir = 7;
 int m2_dir = 8;
 int m1_pwm = 9;
 int m2_pwm = 10;
 int state ;
 const byte interruptPin = 2;
 const byte ledPin = 13;
 volatile byte state = LOW;
 
 SoftwareSerial BT(5,6);//RX,TX
void setup()
{
    pinMode(interruptPin,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin),print10,RISING);  
    Serial.begin(38400);
    BT.begin(38400);// Debugging only
   pinMode(ledPin,OUTPUT);

}//close setup

void loop(){
  digitalWrite(ledPin, state);
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
   
    }
    
    }
  }
void forward()
 {
  Serial.println("Forward");
  digitalWrite(m1_dir,HIGH);
  digitalWrite(m2_dir,HIGH);
  analogWrite(m1_pwm,155);
  analogWrite(m2_pwm,150);
  //delay(10);
  //analogWrite(m1_pwm,0);
  //analogWrite(m2_pwm,0);
 }


void left()
 {
  Serial.println("Left");
  digitalWrite(m1_dir,LOW);
  digitalWrite(m2_dir,HIGH);
  analogWrite(m1_pwm,50);
  analogWrite(m2_pwm,50);
  //delay(10);
  //analogWrite(m1_pwm,0);
  //analogWrite(m2_pwm,0);
 }
void right()
 { 
  Serial.println("Right");
  digitalWrite(m1_dir,HIGH);
  digitalWrite(m2_dir,LOW);
  analogWrite(m2_pwm,50);
  analogWrite(m1_pwm,50);
  //delay(10);
  //analogWrite(m1_pwm,0);
  //analogWrite(m2_pwm,0);
 }
void reverse()
 {
  Serial.println("Reverse");
  digitalWrite(m1_dir,LOW);
  digitalWrite(m2_dir,LOW);
  analogWrite(m1_pwm,150);
  analogWrite(m2_pwm,150);
  //delay(10);
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
 void print10()
 {
  state = !state;
 }


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
