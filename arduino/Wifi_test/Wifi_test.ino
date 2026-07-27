// WiFi Test — connects to a WiFi network and reports signal strength.
//
// Requires a board with built-in WiFi, such as the Arduino Nano 33 IoT,
// MKR WiFi 1010, or Arduino Uno R4 WiFi. The classic Uno (R3) has no WiFi.
//
// Library: install "WiFiNINA" via the Library Manager.
// For the Uno R4 WiFi, use <WiFiS3.h> instead (installed with the board package).

#include <WiFiNINA.h>  // For the Uno R4 WiFi, use <WiFiS3.h> instead

char ssid[] = "YOUR_SSID";      // Name of your WiFi network
char pass[] = "YOUR_PASSWORD";  // Password of your WPA network

void setup() {
  Serial.begin(9600);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Keep trying until we are connected
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(5000);
  }

  Serial.println();
  Serial.println("You're connected to the network!");
}

void loop() {
  // Report the WiFi signal strength every 5 seconds
  Serial.print("Signal strength (RSSI): ");
  Serial.println(WiFi.RSSI());
  delay(5000);
}
