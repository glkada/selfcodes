// TRANSMITTER CODE

//NOTE :- THIS TRANSMITTER CODE IS USED WHEN YOU WANT TO CONTROL THE ROBOT VIA THE BREADBOARD REMOTE
#include <VirtualWire.h>

//Assigning controller buttons to Digital Pins


void setup()
{
    Serial.begin(9600);    // Debugging only
    Serial.println("setup");
    // Initialise the IO and ISR
    vw_setup(200000);  // Bits per sec
    vw_set_tx_pin(3); //Transmitter Data Pin to Digital Pin 3
 }

void loop()
{
    char *msg2 = "1";//send 1 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
    Serial.println(*msg2);
}//close loop
  
 // End Of Code 
  
