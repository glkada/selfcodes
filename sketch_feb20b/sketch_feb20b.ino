const int pwm = 10 ;  //initializing pin 2 as pwm
const int in_1 = 13 ;
const int in_2 = 12 ;

void setup() 
{
  pinMode(pwm,OUTPUT) ;   //we have to set PWM pin as output
pinMode(in_1,OUTPUT) ;  //Logic pins are also set as output
pinMode(in_2,OUTPUT) ;

}

void loop() 
{
  digitalWrite(in_1,HIGH);
  digitalWrite(in_2,LOW);
  analogWrite(pwm,100);
  delay(40);
  digitalWrite(in_1,LOW);
  digitalWrite(in_2,LOW);
  analogWrite(pwm,0);
  delay(1000);

}
