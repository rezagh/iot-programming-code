// #include "defines.h"
// #include "arduino_secrets.h"

// To eliminate FW warning when using not latest nina-fw version
// To use whenever WiFi101-FirmwareUpdater-Plugin is not sync'ed with nina-fw
// version
#define WIFI_FIRMWARE_LATEST_VERSION "1.4.8"

#include <SPI.h>

#if USING_WIFI101
#include <WiFi101_Generic.h>
#else
#include <WiFiNINA_Generic.h>
#endif

// SSID of your network
char ssid[] = "your wifi name";
// password of your WPA Network
char pass[] = "your wifi password";

void setup() {

  Serial.begin(115200);

  int status = WiFi.begin(ssid, pass);
  delay(10000);

  Serial.println("You're connected to the network");
}

void loop() { Serial.println("You're connected to the network"); }