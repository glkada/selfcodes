int m1_dir = 8;
int m2_dir = 7;
int m1_pwm = 6;
int m2_pwm = 5;
int x,y,z;
const int groundPin = 18;
const int powerPin = 19;
const int xpin = A0;
const int ypin = A1;
const int zpin = A2;

void setup() 
{
  Serial.begin(9600);
 for(int i=5;i<9;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(groundPin,OUTPUT);
  pinMode(powerPin,OUTPUT);
  digitalWrite(groundPin,LOW);
  digitalWrite(powerPin,HIGH);
  analogWrite(m1_pwm,0);
  analogWrite(m2_pwm,0);}

void loop() 
{
  x = analogRead(xpin);
  y = analogRead(ypin);
  z = analogRead(zpin);
  // print the sensor values:
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  Serial.println();
  // delay before next reading:
  
  if(x < 400 && x > 80 && x != 0)
  {
   forward();
  }
  else if(x > 450 && x > 80 && x != 0)
  {
    reverse();
  }
  else if(y < 400 && y > 80 && y != 0)
  {
   left();
  }
  else if(z < 490 && z > 80 && z != 0)
  {
   right();
  }
  delay(1000);
}

void forward()
 {
  Serial.println("Forward");
  digitalWrite(m1_dir,HIGH);
  digitalWrite(m2_dir,HIGH);
  analogWrite(m1_pwm,225);
  analogWrite(m2_pwm,225);
  delay(1000);
  analogWrite(m1_pwm,0);
  analogWrite(m2_pwm,0);
 }
void left()
 {
  Serial.println("Left");
  digitalWrite(m1_dir,HIGH);
  analogWrite(m1_pwm,200);
  analogWrite(m2_pwm,0);
  delay(1000);
  //digitalWrite(m1_dir,HIGH);
  analogWrite(m1_pwm,0);
  //digitalWrite(m2_dir,HIGH);
  analogWrite(m2_pwm,0);
 }
void right()
 { 
  Serial.println("Right");
  digitalWrite(m2_dir,HIGH);
  analogWrite(m2_pwm,200);
  analogWrite(m1_pwm,0);
  delay(1000);
  //digitalWrite(m1_dir,HIGH);
  analogWrite(m1_pwm,0);
  //digitalWrite(m2_dir,HIGH);
  analogWrite(m2_pwm,0);
 }
void reverse()
 {
  Serial.println("Reverse");
  digitalWrite(m1_dir,LOW);
  digitalWrite(m2_dir,LOW);
  analogWrite(m1_pwm,225);
  analogWrite(m2_pwm,225);
  delay(1000);
  //digitalWrite(m1_dir,HIGH);
  analogWrite(m1_pwm,0);
  //digitalWrite(m2_dir,HIGH);
  analogWrite(m2_pwm,0);  
 }

