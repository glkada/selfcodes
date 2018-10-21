
/*-------------------------------------------------------------------------------------------------------------------------------------
triangle = motor 1 ---north 
cross    = motor 3 ---south
circle   = motor 2 ---east
square   = motor 4 ---west

press and hold any shape button and RIGHT_1  to increment pwm (of the motor decided by the shape eg for incrementing pwm of motor1 use triangle)by a user defined factor
press and hold any shape button and LEFT_1  to decrement pwm (of the motor decided by the shape eg for decrementing pwm of motor1 use triangle)by a user defined factor

BUTTON- n - FUNCTION
UP      1   forward    motor 2,4
DOWN    2   reverse 
LEFT    3   left       motor 1,3
RIGHT   4   right
START   5   halt    -stop all the motors

serial monitor display pwm value and value of n (deciding the function in switch case) 

 ------------------------------------------------------------------------------------------------------------------------------------------*/


#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
#include<Cytron_PS2Shield.h>
Cytron_PS2Shield ps2(10,11);

const int rs = 12, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int contra =8;
int brightness = 7;


int m1_dir = A2;  
int m2_dir = A3;
int m3_dir = A4;
int m4_dir = A5;

int m1_pwm = 44;
int m2_pwm = 45;
int m3_pwm = 46;
int m4_pwm = 6;

int pwm1 = 0;
int pwm2 = 0;
int pwm3 = 0;
int pwm4 = 0;

int pwm = 0;
int temp =0;
int n= 0;           //switching var for different fuctions
int factor = 0;    //increment factor
int flag = 0;       //used in debouncing
int prev = 1;       //used in debouncing
int current = 0;    //used in debouncing

void setup(){
  lcd.begin(16, 2);
  analogWrite(contra , 15);
  analogWrite(brightness , 45);
  Serial.begin(9600);
  ps2.begin(9600);

  pinMode(m1_dir, OUTPUT);
  pinMode(m2_dir, OUTPUT);
  pinMode(m3_dir, OUTPUT);
  pinMode(m4_dir, OUTPUT);
  
  pinMode(m1_pwm, OUTPUT);
  pinMode(m2_pwm, OUTPUT);
  pinMode(m3_pwm, OUTPUT);
  pinMode(m4_pwm, OUTPUT);
  
}

void forward(){
  digitalWrite(m1_dir,HIGH);
  analogWrite(m1_pwm, pwm1);
  digitalWrite(m2_dir , HIGH);
  analogWrite(m2_pwm, pwm2);
  digitalWrite(m3_dir,HIGH);
  analogWrite(m3_pwm,pwm3);
  digitalWrite(m4_dir , HIGH);
  analogWrite(m4_pwm, pwm4);
}

void reverse(){
  digitalWrite(m1_dir,LOW);
  analogWrite(m1_pwm, pwm1);
  digitalWrite(m2_dir , LOW);
  analogWrite(m2_pwm, pwm2);
  digitalWrite(m3_dir,LOW);
  analogWrite(m3_pwm,pwm3);
  digitalWrite(m4_dir , LOW);
  analogWrite(m4_pwm, pwm4);
  }

void right(){
  digitalWrite(m1_dir,HIGH);
  analogWrite(m1_pwm, pwm1);
  digitalWrite(m2_dir , LOW);
  analogWrite(m2_pwm, pwm2);
  digitalWrite(m3_dir,LOW);
  analogWrite(m3_pwm,pwm3);
  digitalWrite(m4_dir , HIGH);
  analogWrite(m4_pwm, pwm4);

void left(){
  digitalWrite(m1_dir,LOW);
  analogWrite(m1_pwm, pwm1);
  digitalWrite(m2_dir, HIGH);
  analogWrite(m2_pwm, pwm2);
  digitalWrite(m3_dir,HIGH);
  analogWrite(m3_pwm,pwm3);
  digitalWrite(m4_dir , LOW);
  analogWrite(m4_pwm, pwm4);
}

void halt(){
  digitalWrite(m1_dir,LOW);
  analogWrite(m1_pwm, 0);
  digitalWrite(m2_dir, LOW);
  analogWrite(m2_pwm, 0);
  digitalWrite(m3_dir,LOW);
  analogWrite(m3_pwm,0);
  digitalWrite(m4_dir , LOW);
  analogWrite(m4_pwm, 0);
}

void reset(){
  factor = 0;
  pwm = 0;
}

void debounce(){                           //incrementing pwm
  
  current = ps2.readButton(PS2_RIGHT_1);
    if(current != prev){
      prev = current;
      delay(100);
      if(ps2.readButton(PS2_RIGHT_1)==0){
        flag= 1;
      }
      else flag = 0;
    }
    if(flag){
    pwm =  constrain(pwm +factor,0, 225);
      flag = 0;
    }
  
}
 void debounce2(){                           //decrementing pwm
    current = ps2.readButton(PS2_LEFT_1);
    if(current != prev){
      prev = current;
      delay(100);
      if(ps2.readButton(PS2_LEFT_1)==0){
        flag= 1;
      }
      else flag = 0;
    }
    if(flag){
      pwm =  constrain(pwm -factor,0, 225);
      flag = 0;
    }
  
}

 void debounce3(){                           //incrementing factor
    current = ps2.readButton(PS2_RIGHT_2);
    if(current != prev){
      prev = current;
      delay(50);
      if(ps2.readButton(PS2_RIGHT_2)==0){
        flag= 1;
      }
      else flag = 0;
    }
    if(flag){
      factor= constrain(factor + 5,0,100);
      flag = 0;
    }
  
}

 void debounce4(){                           //decrementing factor
    current = ps2.readButton(PS2_LEFT_2);
    if(current != prev){
      prev = current;
      delay(50);
      if(ps2.readButton(PS2_LEFT_2)==0){
        flag= 1;
      }
      else flag = 0;
    }
    if(flag){
      factor= constrain(factor - 5,0,100);
      flag = 0;
    }
  
}


void loop(){
  
  if(ps2.readButton(PS2_TRIANGLE)==0){
   debounce();
   debounce2();
   pwm1 = pwm;
   }  

  if(ps2.readButton(PS2_CIRCLE)==0){
   debounce();
   debounce2();
   pwm2 = pwm;
   }


    if(ps2.readButton(PS2_CROSS)==0){
   
   debounce();
   debounce2();
   pwm3 = pwm;
   }

   if(ps2.readButton(PS2_SQUARE)==0){
 
   debounce();
   debounce2();
   pwm4 = pwm;
   }

   if(ps2.readButton(PS2_RIGHT_2)==0){
 
   debounce3();
   }

    if(ps2.readButton(PS2_LEFT_2)==0){
 
   debounce4();
   }


  
  Serial.println(pwm);
  lcd.print(pwm1);
  lcd.print(' ');
  lcd.print(pwm2);
  lcd.print(' ');
  lcd.print(pwm3);
  lcd.print(' ');
  lcd.print(pwm4);
  lcd.print(' ');
  lcd.print(factor);
  lcd.print(' ');
  lcd.print(n);
  delay(10);
  lcd.clear();
  Serial.println(factor);
    Serial.println(n);
  delay(10);
  if(ps2.readButton(PS2_UP)==0)
 {
  n=1;
 }
 else  if(ps2.readButton(PS2_DOWN)==0)
 {
  n=2;
 }
 else  if(ps2.readButton(PS2_LEFT)==0)
 {
  n=3;
 }
 else  if(ps2.readButton(PS2_RIGHT)==0)
 {
  n=4;
 }
 else  if(ps2.readButton(PS2_START)==0)
 {
  n=5;
 }
 else  if(ps2.readButton(PS2_SELECT)==0)
 {
  n=6;
 }
 switch(n){
  case 1: forward();
  break;
  case 2: reverse();
  break;
  case 3: left();
  break;
  case 4: right();
  break;
  case 5: halt();
  break;
  case 6: reset();
  break;
 }
}
