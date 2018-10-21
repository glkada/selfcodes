void setup() {
  DDRB = B11111111;
  DDRD = B11111110;
  // put your setup code here, to run once:

}

void loop() {
  PORTB = B00010000;//digitalPin 12
  PORTD = B0001000,00;//digitalPin 3
  delay(1000);
  PORTB = B00000000;
  PORTD = B00000000;
  // put your main code here, to run repeatedly:

}
