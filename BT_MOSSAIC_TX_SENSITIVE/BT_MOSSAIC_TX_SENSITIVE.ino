int x, y, z, n;
const int groundPin = 18;
const int powerPin = 19;
const int xpin = A0;
const int ypin = A1;
const int zpin = A2;
#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);

void setup()
{
  Serial.begin(38400);    // Debugging only
  BT.begin(38400);
  Serial.println("setup");
  // Initialise the IO and ISR
  //vw_setup(2000);  // Bits per sec
  //vw_set_tx_pin(3); //Transmitter Data Pin to Digital Pin 3
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
  else if(x < 370 && x > 80 && x != 0)
  {
    n = 6;
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
  //delay(1000);

  //switch(n)
  
  if(n == 1)
    {BT.write('1');
    Serial.println("Front");}
  else if(n == 2)
    {BT.write('2');
    Serial.println("back");}
  else if(n == 3)
    {BT.write('3');
    Serial.println("left");}
  else if(n == 4)
    {BT.write('4');
    Serial.println("right");}
  else if( n== 5){
    BT.write("5");
    Serial.println("stop");}



}//close loop

// End Of Code 
