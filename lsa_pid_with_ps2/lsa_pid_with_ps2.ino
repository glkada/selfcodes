#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
#include<Cytron_PS2Shield.h>
Cytron_PS2Shield ps2(10,11);

const int rs = 12, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int contra =8;
int brightness = 7;

int Kp = 0;   // Kp value that you have to change
int Kd = 0;   // Kd value that you have to change
const int setPoint = 35;    // Middle point of sensor array
const int baseSpeed = 100;    // Base speed for your motors
const int maxSpeed = 200;   // Maximum speed for your motors

const byte rx = 0;    // Defining pin 0 as Rx
const byte tx = 1;    // Defining pin 1 as Tx
const byte serialEn = 2;    // Connect UART output enable of LSA08 to pin 2
const byte junctionPulse = 4;   // Connect JPULSE of LSA08 to pin 4
const byte dir1 = 13;   // Connect DIR1 of motor driver to pin 13
const byte dir2 = 12;   // Connect DIR2 of motor driver to pin 12
const byte pwm1 = 11;   // Connect PWM1 of motor driver to pin 11
const byte pwm2 = 10;   // Connect PWM2 of motor driver to pin 10

int factor = 0;    //increment factor
int flag = 0;       //used in debouncing
int prev = 1;       //used in debouncing
int current = 0;    //used in debouncing

void setup() 
{
  lcd.begin(16, 2);
  analogWrite(contra , 15);
  analogWrite(brightness , 45);
  Serial.begin(9600);
  ps2.begin(9600);
  pinMode(serialEn,OUTPUT);   // Setting serialEn as digital output pin
  pinMode(junctionPulse,INPUT);   // Setting junctionPulse as digital input pin

  // Setting pin 10 - 13 as digital output pin
  for(byte i=10;i<=13;i++) {
    pinMode(i,OUTPUT);
  }

  // Setting initial condition of serialEn pin to HIGH
  digitalWrite(serialEn,HIGH);

  // Setting the initial condition of motors
  // make sure both PWM pins are LOW
  digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);

  // State of DIR pins are depending on your physical connection
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);

  Serial.begin(9600);

}

int lastError = 0;    // Declare a variable to store previous error

void loop() {
  digitalWrite(serialEn,LOW);   // Set serialEN to LOW to request UART data
  while(Serial.available() <= 0);   // Wait for data to be available
  int positionVal = Serial.read();    // Read incoming data and store in variable positionVal
  digitalWrite(serialEn,HIGH);    // Stop requesting for UART data

  // If no line is detected, stay at the position
  if(positionVal == 255) {
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
  }

  // Else if line detected, calculate the motor speed and apply
  else {
    int error = positionVal - setPoint;   // Calculate the deviation from position to the set point
    int motorSpeed = Kp * error + Kd * (error - lastError);   // Applying formula of PID
    lastError = error;    // Store current error as previous error for next iteration use

    // Adjust the motor speed based on calculated value
    // You might need to interchange the + and - sign if your robot move in opposite direction
    int rightMotorSpeed = baseSpeed - motorSpeed;
    int leftMotorSpeed = baseSpeed + motorSpeed;
    
    
    // If the speed of motor exceed max speed, set the speed to max speed
    if(rightMotorSpeed > maxSpeed) rightMotorSpeed = maxSpeed;
    if(leftMotorSpeed > maxSpeed) leftMotorSpeed = maxSpeed;

    // If the speed of motor is negative, set it to 0
    if(rightMotorSpeed < 0) rightMotorSpeed = 0;
    if(leftMotorSpeed < 0) leftMotorSpeed = 0;
    
    //printing pwm assigned to motors
    Serial.print("Right Motor Speed =");
    Serial.println(rightMotorSpeed);
    Serial.print("Left Motor Speed =");
    Serial.println(leftMotorSpeed);

    // Writing the motor speed value as output to hardware motor
    analogWrite(pwm1,rightMotorSpeed);
    analogWrite(pwm2,leftMotorSpeed);
  }

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
    Kp =  constrain(Kp +factor,0, 225);
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
      Kp =  constrain(Kp -factor,0, 225);
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

