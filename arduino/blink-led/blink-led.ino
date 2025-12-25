/*
  Blink a real LED.
  Also learn about about declaring a variable

  int LED = 11;
*/

void setup() {
  // initialize digital pin 11 as an output.
  pinMode(11, OUTPUT);
}

void loop() {
  digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level). will send 5v to the led which is too much for most 3-5mm LEDs hence you need a resistor.
  delay(1000);              // wait for a second
  digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW. will send 0v to the led.
  delay(1000);              // wait for a second
}