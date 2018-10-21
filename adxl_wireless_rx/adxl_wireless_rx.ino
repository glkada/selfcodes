// RECIEVER CODE

//NOTE :- THIS CODE IS USED WHEN CONTROLLING THE ROBOT VIA THE BREADBORD REMOTE

#include <VirtualWire.h>

//declaring pin nos cytron
int m1_dir = 24;
 int m2_dir = 27;
 int m1_pwm = 7;
 int m2_pwm = 8;
 
void setup()
{
    Serial.begin(9600);  // Debugging only
    Serial.println("setup");
    // try not to overthink
    // Initialise the IO and ISR
    vw_setup(2000);  // Bits per sec
    vw_set_rx_pin(26);    //Rx Data pin to Digital  Pin 25
    vw_rx_start();       // Start the receiver PLL running
    
    pinMode(m1_dir,OUTPUT);
    pinMode(m2_dir,OUTPUT);
    pinMode(m1_pwm,OUTPUT);
    pinMode(m2_pwm,OUTPUT);

}//close setup

void loop()
{
    // try not to overthink
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
  int i;

        digitalWrite(13, true); // Flash a light to show received good message
  // Message with a good checksum received, dump it.
  for (i = 0; i < buflen; i++)
  {
   Serial.print(buf[i]);//print received command
        if(buf[i] == '1')//if front tilt
      {
        forward();//go forward
        Serial.println(" = forward");
      }
        if(buf[i] == '2')//if back tilt
      {
        reverse();//go backward
        Serial.println(" = backward");
      }
        if(buf[i] == '3')//if left tilt
      {
        left();//go left
        Serial.println(" = left");
      }
        if(buf[i] == '4')//if right tilt
      {
        right();//go right
        Serial.println(" = right");
      }
       if(buf[i] == '5')//if no tilt
      {
        stop1();//no tilt
        Serial.println(" = right");
      }
        
      Serial.print(" ");
  }
  Serial.println("");
        digitalWrite(13, false);

   }//close if
}//close loop


////////////////////////////////////////////////////////////////////////////////////////
//set of functions

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
  analogWrite(m1_pwm,0);
  analogWrite(m2_pwm,0);
 }
void right()
 { 
  Serial.println("Right");
  digitalWrite(m2_dir,HIGH);
  analogWrite(m2_pwm,200);
  analogWrite(m1_pwm,0);
  delay(1000);
  analogWrite(m1_pwm,0);
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
  analogWrite(m1_pwm,0);
  analogWrite(m2_pwm,0);  
 }
void stop1()
 {
  Serial.println("Stopped");
  digitalWrite(m1_dir,LOW);
  digitalWrite(m2_dir,LOW);
  analogWrite(m1_pwm,0);
  analogWrite(m2_pwm,0); 
 }

