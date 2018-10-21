
// TRANSMITTER CODE
#include <VirtualWire.h>

int forward = 8;
int backward = 9;
int rightTurn = 10;
int leftTurn = 11;
int stopMotor = 12;
int x, y, z, n;
const int groundPin = 18;
const int powerPin = 19;
const int xpin = A0;
const int ypin = A1;
const int zpin = A2;

void setup()
{
    Serial.begin(9600);    // Debugging only
    Serial.println("setup");
    // Initialise the IO and ISR
    vw_setup(2000);  // Bits per sec
    vw_set_tx_pin(3); //Transmitter Data Pin to Digital Pin 3
    pinMode(groundPin,OUTPUT);
    pinMode(powerPin,OUTPUT);
    digitalWrite(groundPin,LOW);
    digitalWrite(powerPin,HIGH);
      
}//close setup

void loop()
{
  //scan adxl335 for values
  x = analogRead(xpin); 
  y = analogRead(ypin);
  z = analogRead(zpin);
  // print the sensor values:
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  Serial.println();
  // delay before next reading:
  
  if(x < 340 && x > 80 && x != 0)
  {
   n = 1;//read ahead
  }
  else if(x > 435 && x > 80 && x != 0)
  {
    n = 2;//read ahead
  }
  else if(y < 350 && y > 80 && y != 0)
  {
   n = 3;//read ahead
  }
  else if(z < 410 && z > 80 && z != 0)
  {
   n = 4;//read ahead
  }
  else
   {
    n = 5;//read ahead
   }
  delay(1000);

  char *msg2;
  
  if(n == 1)//if front tilt
  {
    Serial.println("Forward");
    char *msg2 = "1";//send 1 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
  else if(n == 2)
  {
    Serial.println("Reverse");
    char *msg2 = "2";///send 2 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
  else if(n == 3)//if the left button is pressed
  {
    Serial.println("Left");
    char *msg2 = "3";//send 3 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
  else if(n == 4)//if the right button is pressed
  {
    Serial.println("Right");
    char *msg2 = "4";//send 4 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the message to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  else if(n == 5)
   {
    Serial.println("No Tilt");
    char *msg2 = "5";//send 5 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the message to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
   }
  
  
  
}//close loop
  
 // End Of Code 
