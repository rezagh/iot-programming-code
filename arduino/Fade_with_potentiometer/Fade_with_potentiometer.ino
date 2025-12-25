/**
potentiometer is a variable resistor

The middle pin returns the current with the resistance of the potentiometer applied. 
Suppose you connect the + to 5 Volt, and connect the - to the GND. When we turn the potentiometer for 50% open the middle pin will be 2.5 Volts.
v= ir

baud is the unit of measure for symbol per second that can be send to a channel
*/

#define LED_PIN 11
#define POTENTIOMETER_PIN A2
void setup(){
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600); 
}

void loop(){
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  Serial.println(potentiometerValue); // see serial monitor
  int brightness = potentiometerValue / 4; // the high potentiometer value the brighter LED will be
  analogWrite(LED_PIN, brightness); // write an analog value (between 0-255) to the pin - unlike digitalWrite we have seen so far
  delay(1000);
}

