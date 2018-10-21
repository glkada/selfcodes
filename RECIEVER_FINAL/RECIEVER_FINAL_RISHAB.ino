// RECIEVER CODE

//NOTE :- THIS CODE IS USED WHEN CONTROLLING THE ROBOT VIA THE BREADBORD REMOTE

#include <VirtualWire.h>
int forwardb = false;
//declaring pin nos to FIRST L293D
int en1 = 11;
 int en2 = 9;
 int in1 = 8;
 int in2 = 7;
 int in3 = 3;
 int in4 = 4;
 int trigPin=5;
 int echoPin=6;
 int distance_thresh=400;
 int a=1;

void setup()
{
    Serial.begin(9600);  // Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
    vw_setup(2000);  // Bits per sec
    vw_set_rx_pin(2);    //Rx Data pin to Digital  Pin 2
    vw_rx_start();       // Start the receiver PLL running
    for (int i = 0; i < 12; i++) 
   {
          pinMode(en1,OUTPUT);
          pinMode(in1,OUTPUT);
          pinMode(in2,OUTPUT);
          pinMode(in3,OUTPUT);
          pinMode(in4,OUTPUT);
          pinMode(en2,OUTPUT);
          
   }
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

}//close setup

void loop()

{
  long duration;
  int distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration) *0.034/2;
  Serial.print(distance);
  delay(100);
  Serial.println("CM");
  if (distance <= distance_thresh)
  {
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
        if(buf[i] == '1')//if button 1 is pressed.... i.e.forward buton
      {
        forward();//go forward
        Serial.println(" = forward");
        forwardb = true;
        //delay(20000);
        break;
      }
       
    
  }
  
   }//close if
   else
   {
    if(!forwardb){
      Serial.println("message not received");
      siren();
      delay(450);
      }
    
   }
  }
  else if(distance > distance_thresh)
   {
    Serial.println("All Clear");
   }
}//close loop


////////////////////////////////////////////////////////////////////////////////////////
//set of functions

void forward()
{
  digitalWrite(en1,50);
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 delay(50);
 digitalWrite(en1,50);
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 }
 void siren()
{
  digitalWrite(en2,255);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(2000);
} 
  

  
 //End Of Code
