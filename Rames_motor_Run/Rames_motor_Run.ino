int m1_F = 3;
int m1_R = 4;
int m2_F = 7;
int m2_R = 8;
int m1_pwm = 5;
int m2_pwm = 6;
int pwm1 = 20; // change this to vary pwm
int pwm2 = 20;

void setup() {
  for(int i = 3;i<9;i++)
  {
    pinMode(i,OUTPUT);
  }
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(m1_F,HIGH);
  digitalWrite(m1_R,LOW);
  analogWrite(m1_pwm,pwm1);
  digitalWrite(m2_F,HIGH);
  digitalWrite(m2_R,LOW);
  analogWrite(m2_pwm,pwm2);
  // put your main code here, to run repeatedly:

}
