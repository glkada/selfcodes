#include <Servo.h>
Servo myservo;
const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 11;
const int echoPin2 = 12;
// defines variables
long duration1;
int distance1;
long duration2;
int distance2;
int pos = 90;
int pos_anti = 180;
int pos_clock = 0;

void setup() {
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT); 
pinMode(trigPin2, OUTPUT); 
pinMode(echoPin2, INPUT);
myservo.attach(3); 
Serial.begin(9600); 
}
void loop() {
 myservo.write(pos); 
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1= duration1*0.034/2;
digitalWrite(trigPin2, LOW);//ultra2
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distance2= duration2*0.034/2;
if(distance1 < 8 || distance2 < 8)
{
  myservo.write(pos_anti);
}
else
{
 myservo.write(pos_clock); 
}

}
