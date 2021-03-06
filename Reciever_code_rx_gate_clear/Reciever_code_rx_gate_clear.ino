// RECIEVER CODE

#include <VirtualWire.h>

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
 
void setup()
{
    
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
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
   /*
    * pinMode(ALLTHEDECLAREDPINS,OUTPUT) 
    */

}//close setup

void loop()
{
    long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 //Serial.print(distance);
 //Serial.println("CM");
      
      
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
                    Serial.println(buf[i]);//print received command
                      if(buf[i] == '1')//if car is in vicinity
                        {
                          gate_open();
                          Serial.println("Gate is Opened");
                         }
                      /*else 
                        //{
                          //siren();
                          //Serial.println("Gate is not Opened");
                        //}
                    /*switch (buf[i])
                    {
                      /*case 1:
                        gate_open();
                        Serial.println("Gate is opened");
                        break;*/
                      /*case 49:
                        gate_open();
                        Serial.println("Gate is opened");
                       default:
                       siren();
                       //Serial.println("Gate is not Opened"); 
                    }
                   }*/    
  
      }//close if
      else 
      {
         siren();
         Serial.println("Gate is not Opened"); 
      }
      }//if sensor loop closed
      else if (distance > distance_thresh)
      {
        Serial.println("All Clear");
      }
  delay(100);
}//close loop
void gate_open()
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
