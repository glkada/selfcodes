int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;
int led10 = 11;
int led11 = 12;
void setup()
{
 DDRB = B11111111;
 DDRD = B11111111;
}

void loop() 
{
 /*PORTB = B11111111;
 PORTD = B11111111;
 delay(500);
 PORTB = B00000000;
 PORTB = B00000000;*/
 for(int i=2;i<13;i++)
  {
    digitalWrite(i, HIGH);
  }
  delay(500);
 for(int i=2;i<13;i++)
  {
    digitalWrite(i, LOW);
  } 
 delay(500);
 digitalWrite(led1,HIGH);
 delay(500);
 digitalWrite(led1,LOW);
 delay(400);
 digitalWrite(led1,HIGH);
 delay(400);
 digitalWrite(led1,LOW);
 delay(300);
 digitalWrite(led1,HIGH);
 delay(300);
 digitalWrite(led1,LOW);
 delay(200);
 digitalWrite(led1,HIGH);
 delay(200);
 digitalWrite(led1,LOW);
 delay(100);
 digitalWrite(led1,HIGH);
 delay(100);
 digitalWrite(led1,LOW);
 delay(100);
  for(int i=2;i<13;i++)
  {
    digitalWrite(i, HIGH);
  }
  delay(500);
 for(int i=2;i<13;i++)
  {
    digitalWrite(i, LOW);
  } 
 delay(500);
 digitalWrite(led1,HIGH);
 delay(100);
 digitalWrite(led2,HIGH);
 delay(100);
 digitalWrite(led3,HIGH);
 delay(100);
 digitalWrite(led4,HIGH);
 delay(100);
 digitalWrite(led5,HIGH);
 delay(100);
 digitalWrite(led6,HIGH);
 delay(100);
 digitalWrite(led7,HIGH);
 delay(100);
 digitalWrite(led8,HIGH);
 delay(100);
 digitalWrite(led9,HIGH);
 delay(100);
 digitalWrite(led10,HIGH);
 delay(100);
 digitalWrite(led11,HIGH);
 delay(500);
 for(int i=2;i<13;i++)
  {
    digitalWrite(i, LOW);
  }
  delay(500);
 for(int i=2;i<13;i++)
  {
    digitalWrite(i, HIGH);
  } 
 delay(500);
 digitalWrite(led11,LOW);
 delay(100);
 digitalWrite(led10,LOW);
 delay(100);
 digitalWrite(led9,LOW);
 delay(100);
 digitalWrite(led8,LOW);
 delay(100);
 digitalWrite(led7,LOW);
 delay(100);
 digitalWrite(led6,LOW);
 delay(100);
 digitalWrite(led5,LOW);
 delay(100);
 digitalWrite(led4,LOW);
 delay(100);
 digitalWrite(led3,LOW);
 delay(100);
 digitalWrite(led2,LOW);
 delay(100);
 digitalWrite(led1,LOW);
 delay(500);
 for(int i=2;i<13;i++)
  {
    digitalWrite(i, LOW);
  } 
 delay(500);
 }
