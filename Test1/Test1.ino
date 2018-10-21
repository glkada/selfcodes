
// TRANSMITTER CODE

//NOTE :- THIS TRANSMITTER CODE IS USED WHEN YOU WANT TO CONTROL THE ROBOT VIA THE BREADBOARD REMOTE
#include <VirtualWire.h>

//Assigning controller buttons to Digital Pins
int forward = 8;
int backward = 9;
int rightTurn = 10;
int leftTurn = 11;
int stopMotor = 12;
int remotePins[]= {8,9,10,11,12};//array to store pin nos

void setup()
{
    Serial.begin(9600);    // Debugging only
    Serial.println("setup");
    // Initialise the IO and ISR
    vw_setup(2000);  // Bits per sec
    vw_set_tx_pin(3); //Transmitter Data Pin to Digital Pin 3
        
 
    for(int i = 0; i<6 ; i++)
    {
      pinMode(remotePins[i], INPUT);
      digitalWrite(remotePins[i],HIGH);
    }
      /*
      This is what the loop above does :-
        pinMode(8, INPUT);
        pinMode(9, INPUT);
        pinMode(10, INPUT);
        pinMode(11, INPUT);
        pinMode(12, INPUT);

        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);*/
}//close setup

void loop()
{
  char *msg2;
  
  if(digitalRead(forward) == LOW)//if the forward button is pressed
  {
    char *msg2 = "1";//send 1 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
  if(digitalRead(backward) == LOW)//if the back button is pressed
  {
    char *msg2 = "2";///send 2 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
  if(digitalRead(leftTurn) == LOW)//if the left button is pressed
  {
    char *msg2 = "3";//send 3 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
  if(digitalRead(rightTurn) == LOW)//if the right button is pressed
  {
    char *msg2 = "4";//send 4 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the message to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
  if(digitalRead(stopMotor)==LOW)//if the stop button is pressed
  {
   char *msg2 = "5";//send 5 to the receiver
   digitalWrite(13, true); // Flash a light to show transmitting
   vw_send((uint8_t *)msg2, strlen(msg2));//send the message to the receiver
   vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  } 
}//close loop
  
 // End Of Code 
