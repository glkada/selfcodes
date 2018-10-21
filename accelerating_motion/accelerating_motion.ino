#define m1p1 22
#define m1p2 23
#define m1pwm 2

#define m2p1 24
#define m2p2 25
#define m2pwm 3


#define m3p1 26
#define m3p2 27
#define m3pwm 4

#define m4p1 38
#define m4p2 39
#define m4pwm 6 

int pwm = 50;
int addn = 10;
int f,n;

char c;
void setup()
{
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(m3p1, OUTPUT);
  pinMode(m3p2, OUTPUT);
  pinMode(m4p1, OUTPUT);
  pinMode(m4p2, OUTPUT);
  pinMode(m1pwm, OUTPUT);
  pinMode(m2pwm, OUTPUT);
  pinMode(m3pwm, OUTPUT);
  pinMode(m4pwm, OUTPUT);
  

  
  Serial.begin(38400);   
  

}
void forward()
{

  
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  analogWrite(m1pwm, pwm);
   pwm = pwm + addn;
   constrain(pwm, 0, 200);
   delay(200);
   
 if (pwm >= 200)
 {
  f = 1;
  
 }
 else
 {
  f = 0;
 }
 while (f ==1)
 {
  analogWrite(9,pwm);
 }
 
  
  
  digitalWrite(m3p1, LOW);
  digitalWrite(m3p2, HIGH);
  analogWrite(m3pwm, pwm);
   pwm = pwm + addn;
 constrain(pwm, 0, 200);
 delay(200);
 
 if (pwm >= 200)
 {
  f = 1;
  
 }
 else
 {
  f = 0;
 }
 while (f ==1)
 {
  analogWrite(9,pwm);
 }
 
  //Serial.println("Forward");
   
  

    
}

void back()
{
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  analogWrite(m1pwm, pwm);
   pwm = pwm + addn;
 constrain(pwm, 0, 200);
 delay(200);

 if (pwm >= 200)
 {
  f = 1;
 
 }
 else
 {
  f = 0;
 }
 while (f ==1)
 {
  analogWrite(9,pwm);
 }
 
  
  digitalWrite(m3p1, HIGH);
  digitalWrite(m3p2, LOW);
  analogWrite(m3pwm, pwm);  
   pwm = pwm + addn;
 constrain(pwm, 0, 200);
 delay(200);
 if (pwm >= 200)
 {
  f = 1;
 }
 else
 {
  f = 0;
 }
 while (f ==1)
 {
  analogWrite(9,pwm);
 }
 
   
}
void right()
{
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  analogWrite(m2pwm, pwm);
  
  digitalWrite(m4p1, LOW);
  digitalWrite(m4p2, HIGH);
  analogWrite(m4pwm, pwm);
   
    
   
}
void left()
{
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  analogWrite(m2pwm, pwm);
  
  digitalWrite(m4p1, HIGH);
  digitalWrite(m4p2, LOW);
  analogWrite(m4pwm, pwm);
   //Serial.println("Left");
}
void halt()
{
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, LOW);
  
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, LOW);
  
  digitalWrite(m3p1, LOW);
  digitalWrite(m3p2, LOW);

  digitalWrite(m4p1, LOW);
  digitalWrite(m4p2, LOW);
}


void loop() 
{
  
  while(Serial.available()){
     c = Serial.read();
    Serial.println(c);
  switch(c){
    case 'F':
    forward();
    break;
    case 'B':
    back();
    break;
    case 'R':
    right();
    break;
    case 'L':
    left();
    break;
    default:
     halt();
     break;
    
  }
    
  }
}
