int pwm = 50;
int addn = 10;
int f=0;
void setup() 
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() 
{
 digitalWrite(8,HIGH);
 analogWrite(9, pwm);// put your main code here, to run repeatedly:
 pwm = pwm + addn;
 constrain(pwm, 0, 200);
 delay(200);
 Serial.println(pwm);
 if (pwm >= 200)
 {
  f = 1;
  Serial.println(f);
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
