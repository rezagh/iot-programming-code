/* 
when reading the computer serial port make sure to close Arduino IDE's Serial Monitor
In Mac: screen /dev/cu.usbmodem11101 9600
*/

void setup() {
  Serial.begin(9600); // start the serial comms channel. speed in baud bits per second
}

void loop() {
  Serial.println("I am writing to serial port");
  delay(1000); 
}