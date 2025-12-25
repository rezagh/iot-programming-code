int ledPin = 11;    // LED connected to digital pin ~11

void setup(){}

void loop() {

    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) { // fade in
    analogWrite(ledPin, fadeValue);
    delay(30); // wait for 30 milliseconds to see the dimming effect

  }

  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) { // fade out
    analogWrite(ledPin, fadeValue);
    delay(30);
  }
}