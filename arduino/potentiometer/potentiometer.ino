/**
potentiometer is a variable resistor

The middle pin returns the current with the resistance of the potentiometer applied. 
Suppose you connect the + to 5 Volt, and connect the - to the GND. When we turn the potentiometer for 50% open the middle pin will be 2.5 Volts.
baud is the unit of measure for symbol per second that can be send to a channel
*/

int potPin = A2;              // Potmeter pin
int potVal = 0;               // Potmeter's value (0 by default)

void setup() {
  Serial.begin(9600);         // Start the serial monitor at 9600 baud, This indicates that the Arduino is allowed to send back symbols to the computer at a rate of 9600 symbols per second. This number is called the Baud rate.
}

// The loop() function runs infinitely
void loop() {
  
  potVal = analogRead(potPin);       // Read the analog value of the potmeter (0-1023)
  Serial.println(potVal);            // Write the value to the serial monitor (tools menu -> serial monitor)
  delay(1000);                     // Pause
}
