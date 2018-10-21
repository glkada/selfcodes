//please connect as per the connections as per given below
//making changes as pewr connections is almost impossible
//take a copy of this 1st if u wanna edit please bohot mehenat hai
//rpm matching is done using the voltage regulator
//code is for arduino uno
//clock hasn't been used anywhere
//Thank you
//God bless you

/*
 * connections
 * m1_dir1 = 8;
   m1_dir2 = 9;
   m2_dir1 = 10;
   m2_dir2 = 11;
   m3_dir1 = 12;
   m3_dir2 = 13;
   m4_dir1 = A0;
   m4_dir2 = A1;*/
char c;
void setup() 
{
  DDRC = B111111;  //A0-A5
  DDRB = B11111110;  //8-13
  
  Serial.begin(38400);

}

void loop() 
{
   while(Serial.available()) {
    c=Serial.read();
    Serial.println(c);
    switch(c) {
      case 'F':   forward();
                    break;
      case 'R':   right();
                    break;
      case 'L':   left();
                    break;
      case 'B':   back();
                    break;
      default:    halt();
                    break;
    }
  }
}

void forward()
{
  PORTC = B00000001;  
  PORTB = B00010101; 
}
void back()
{
  PORTC = B00000010; 
  PORTB = B00101010;
}
void right()
{
  PORTC = B00000001;
  PORTB = B00010101;
}
void left()
{
  PORTC = B00000010;
  PORTB = B00101010;
}
void halt()
{
  PORTC = B00000000;
  PORTB = B00000000;
}

